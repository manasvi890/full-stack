<?php
session_start();

if (!isset($_SESSION['user'])) {
    header("Location: login.php");
    exit();
}

$host = "localhost:3307";
$username = "root";
$password = "chamoli";
$dbname = "timezone";
$conn = new mysqli($host, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Handle remove item from cart
if (isset($_GET['remove_id'])) {
    $remove_id = intval($_GET['remove_id']);
    if (isset($_SESSION['cart'][$remove_id])) {
        unset($_SESSION['cart'][$remove_id]);
    }
    header("Location: cart.php");
    exit();
}

// Handle quantity update
if (isset($_POST['update_cart'])) {
    foreach ($_POST['quantities'] as $id => $quantity) {
        $_SESSION['cart'][$id] = intval($quantity);
    }
    header("Location: cart.php");
    exit();
}

$cart = $_SESSION['cart'] ?? [];
$cart_items = [];
$total_price = 0;

if (!empty($cart)) {
    $ids = implode(',', array_keys($cart));
    $sql = "SELECT * FROM watches WHERE id IN ($ids)";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $row['quantity'] = $cart[$row['id']];
            $row['total'] = $row['price'] * $row['quantity'];
            $total_price += $row['total'];
            $cart_items[] = $row;
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Cart - The Timezone</title>
  <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-gray-100">

  <!-- Header -->
  <?php include 'Header.php'; ?>

  <!-- Cart Section -->
  <div class="container mx-auto my-8 p-4 bg-white shadow-lg rounded-lg">
    <h2 class="text-3xl font-bold mb-6">Your Cart</h2>
    <?php if (!empty($cart_items)): ?>
      <form action="cart.php" method="POST">
        <table class="w-full border-collapse">
          <thead>
            <tr class="border-b">
              <th class="py-2 px-4 text-left">Image</th>
              <th class="py-2 px-4 text-left">Brand</th>
              <th class="py-2 px-4 text-left">Description</th>
              <th class="py-2 px-4 text-left">Quantity</th>
              <th class="py-2 px-4 text-left">Price</th>
              <th class="py-2 px-4 text-left">Total</th>
              <th class="py-2 px-4 text-left">Action</th>
            </tr>
          </thead>
          <tbody>
            <?php foreach ($cart_items as $item): ?>
              <tr class="border-b">
                <td class="py-2 px-4"><img src="<?php echo htmlspecialchars($item['image_url']); ?>" alt="<?php echo htmlspecialchars($item['brand']); ?>" class="w-24 h-24 object-cover"></td>
                <td class="py-2 px-4"><?php echo htmlspecialchars($item['brand']); ?></td>
                <td class="py-2 px-4"><?php echo htmlspecialchars($item['description']); ?></td>
                <td class="py-2 px-4">
                  <input type="number" name="quantities[<?php echo $item['id']; ?>]" value="<?php echo $item['quantity']; ?>" min="1" class="p-2 border border-gray-300 rounded-md">
                </td>
                <td class="py-2 px-4">₹<?php echo number_format($item['price'], 0, '.', ','); ?></td>
                <td class="py-2 px-4">₹<?php echo number_format($item['total'], 0, '.', ','); ?></td>
                <td class="py-2 px-4">
                  <a href="cart.php?remove_id=<?php echo $item['id']; ?>" class="text-red-600 hover:text-red-800">Remove</a>
                </td>
              </tr>
            <?php endforeach; ?>
          </tbody>
        </table>

        <!-- Cart Total -->
        <div class="mt-4 text-right">
          <p class="text-xl font-bold">Total Price: ₹<?php echo number_format($total_price, 0, '.', ','); ?></p>
          <button type="submit" name="update_cart" class="mt-4 px-4 py-2 bg-blue-600 text-white rounded-md hover:bg-blue-700">Update Cart</button>
        </div>
      </form>

      <!-- Checkout Button -->
      <div class="mt-8 text-center">
        <a href="checkout.php" class="px-6 py-3 bg-green-600 text-white rounded-md hover:bg-green-700">Proceed to Checkout</a>
      </div>

    <?php else: ?>
      <p class="text-center text-gray-600">Your cart is empty.</p>
    <?php endif; ?>
  </div>

</body>
</html>

<?php
$conn->close();
?>
