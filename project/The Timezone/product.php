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

if (!isset($_GET['id'])) {
    header("Location: home.php");
    exit();
}

$id = intval($_GET['id']);
$sql = "SELECT * FROM watches WHERE id = ?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("i", $id);
$stmt->execute();
$result = $stmt->get_result();

if ($result->num_rows === 0) {
    echo "Watch not found.";
    exit();
}

$watch = $result->fetch_assoc();

if (isset($_POST['add_to_cart'])) {
    $quantity = intval($_POST['quantity']);
    $cart = $_SESSION['cart'] ?? [];
    if (isset($cart[$id])) {
        $cart[$id] += $quantity;
    } else {
        $cart[$id] = $quantity;
    }
    $_SESSION['cart'] = $cart;
    header("Location: cart.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Product - The Timezone</title>
  <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-gray-100">

  <!-- Header -->
  <?php include 'Header.php'; ?>

  <!-- Product Details -->
  <div class="container mx-auto my-8 p-4 bg-white shadow-lg rounded-lg">
    <div class="flex">
      <img src="<?php echo htmlspecialchars($watch['image_url']); ?>" alt="<?php echo htmlspecialchars($watch['brand']); ?>" class="w-1/2 h-96 object-cover rounded-lg">
      <div class="w-1/2 pl-8">
        <h1 class="text-3xl font-bold"><?php echo htmlspecialchars($watch['brand']); ?></h1>
        <p class="text-gray-600 mt-2"><?php echo htmlspecialchars($watch['description']); ?></p>
        <p class="text-gray-800 mt-2">Type: <?php echo htmlspecialchars($watch['type']); ?></p>
        <p class="text-green-600 font-bold text-2xl mt-4">₹<?php echo number_format($watch['price'], 0, '.', ','); ?></p>
        <form action="product.php?id=<?php echo $watch['id']; ?>" method="POST" class="mt-4">
          <label for="quantity" class="block text-lg font-semibold">Quantity</label>
          <input type="number" id="quantity" name="quantity" value="1" min="1" class="mt-2 p-2 border border-gray-300 rounded-md">
          <button type="submit" name="add_to_cart" class="mt-4 px-4 py-2 bg-blue-600 text-white rounded-md hover:bg-blue-700">Add to Cart</button>
        </form>
      </div>
    </div>
  </div>

</body>
</html>

<?php
$conn->close();
?>
