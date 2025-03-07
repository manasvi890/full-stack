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

// Fetch total number of users
$sqlUsers = "SELECT COUNT(*) AS total_users FROM users";
$resultUsers = $conn->query($sqlUsers);
$totalUsers = $resultUsers->fetch_assoc()['total_users'];

// Fetch total number of orders
$sqlOrders = "SELECT COUNT(*) AS total_orders FROM orders";
$resultOrders = $conn->query($sqlOrders);
$totalOrders = $resultOrders->fetch_assoc()['total_orders'];

// Fetch total revenue
$sqlRevenue = "SELECT SUM(total) AS total_revenue FROM orders";
$resultRevenue = $conn->query($sqlRevenue);
$totalRevenue = $resultRevenue->fetch_assoc()['total_revenue'];

?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Admin Dashboard</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css">
</head>
<body class="bg-gray-100">

  <!-- Header -->
  <?php include 'admin_header.php'; ?>

  <div class="container mx-auto p-8">
    <h1 class="text-3xl font-bold mb-8">Admin Dashboard</h1>

    <div class="grid grid-cols-1 md:grid-cols-3 gap-8">
      <!-- Total Users -->
      <div class="bg-white shadow-md rounded-lg p-6">
        <h2 class="text-xl font-semibold mb-4">Total Users</h2>
        <p class="text-3xl font-bold"><?php echo number_format($totalUsers); ?></p>
      </div>

      <!-- Total Orders -->
      <div class="bg-white shadow-md rounded-lg p-6">
        <h2 class="text-xl font-semibold mb-4">Total Orders</h2>
        <p class="text-3xl font-bold"><?php echo number_format($totalOrders); ?></p>
      </div>

      <!-- Total Revenue -->
      <div class="bg-white shadow-md rounded-lg p-6">
        <h2 class="text-xl font-semibold mb-4">Total Revenue</h2>
        <p class="text-3xl font-bold">₹<?php echo number_format($totalRevenue, 2, '.', ','); ?></p>
      </div>
    </div>
  </div>

</body>
</html>

<?php
$conn->close();
?>
