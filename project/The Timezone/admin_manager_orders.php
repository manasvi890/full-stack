<?php
session_start();

if (!isset($_SESSION['admin'])) {
    header("Location: admin_login.php");
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

// Fetch orders
$sql = "SELECT orders.id, orders.user_id, orders.watch_id, orders.quantity, orders.total, orders.created_at, 
               users.name AS user_name, watches.brand AS watch_brand 
        FROM orders 
        JOIN users ON orders.user_id = users.id 
        JOIN watches ON orders.watch_id = watches.id";

$result = $conn->query($sql);

// Handle delete request
if (isset($_GET['delete'])) {
    $orderId = intval($_GET['delete']);
    $deleteSql = "DELETE FROM orders WHERE id = ?";
    $stmt = $conn->prepare($deleteSql);
    $stmt->bind_param("i", $orderId);
    if ($stmt->execute()) {
        echo "<p class='text-green-500 text-center'>Order deleted successfully!</p>";
    } else {
        echo "<p class='text-red-500 text-center'>Error deleting order: " . $conn->error . "</p>";
    }
    $stmt->close();
    // Refresh page to reflect changes
    header("Refresh: 0");
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Manage Orders - The Timezone</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css">
</head>
<body class="bg-gray-100">

  <!-- Header -->
  <?php include 'admin_header.php'; ?>

  <div class="container mx-auto p-6">
    <h1 class="text-3xl font-bold mb-6">Manage Orders</h1>

    <?php if ($result->num_rows > 0): ?>
      <table class="min-w-full bg-white border border-gray-200 rounded-lg shadow-lg">
        <thead>
          <tr>
            <th class="py-2 px-4 border-b text-left">Order ID</th>
            <th class="py-2 px-4 border-b text-left">User</th>
            <th class="py-2 px-4 border-b text-left">Watch</th>
            <th class="py-2 px-4 border-b text-left">Quantity</th>
            <th class="py-2 px-4 border-b text-left">Total</th>
            <th class="py-2 px-4 border-b text-left">Date</th>
            <th class="py-2 px-4 border-b text-left">Action</th>
          </tr>
        </thead>
        <tbody>
          <?php while ($row = $result->fetch_assoc()): ?>
            <tr>
              <td class="py-2 px-4 border-b"><?php echo htmlspecialchars($row['id']); ?></td>
              <td class="py-2 px-4 border-b"><?php echo htmlspecialchars($row['user_name']); ?></td>
              <td class="py-2 px-4 border-b"><?php echo htmlspecialchars($row['watch_brand']); ?></td>
              <td class="py-2 px-4 border-b"><?php echo htmlspecialchars($row['quantity']); ?></td>
              <td class="py-2 px-4 border-b">₹<?php echo number_format($row['total'], 2); ?></td>
              <td class="py-2 px-4 border-b"><?php echo htmlspecialchars($row['created_at']); ?></td>
              <td class="py-2 px-4 border-b">
                <a href="admin_manager_orders.php?delete=<?php echo $row['id']; ?>" class="text-red-600 hover:text-red-800">Delete</a>
              </td>
            </tr>
          <?php endwhile; ?>
        </tbody>
      </table>
    <?php else: ?>
      <p class="text-center text-gray-600">No orders found.</p>
    <?php endif; ?>
  </div>

</body>
</html>
