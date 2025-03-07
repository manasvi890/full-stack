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

// Handle user deletion
if (isset($_GET['delete'])) {
    $userId = intval($_GET['delete']);
    $sqlDelete = "DELETE FROM users WHERE id = ?";
    $stmtDelete = $conn->prepare($sqlDelete);
    $stmtDelete->bind_param('i', $userId);
    if ($stmtDelete->execute()) {
        header("Location: admin_manager_users.php"); // Refresh the page after deletion
        exit();
    } else {
        echo '<p class="text-center text-red-600">Error deleting user.</p>';
    }
}

// Fetch all users
$sqlUsers = "SELECT id, name, email FROM users";
$resultUsers = $conn->query($sqlUsers);
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Manage Users</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css">
</head>
<body class="bg-gray-100">

  <!-- Header -->
  <?php include 'admin_header.php'; ?>

  <div class="container mx-auto p-8">
    <h1 class="text-3xl font-bold mb-8">Manage Users</h1>

    <div class="bg-white shadow-md rounded-lg p-6">
      <table class="min-w-full divide-y divide-gray-200">
        <thead class="bg-gray-50">
          <tr>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">ID</th>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">Name</th>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">Email</th>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">Actions</th>
          </tr>
        </thead>
        <tbody class="bg-white divide-y divide-gray-200">
          <?php
          if ($resultUsers->num_rows > 0) {
              while ($row = $resultUsers->fetch_assoc()) {
                  echo '<tr>';
                  echo '<td class="px-6 py-4 whitespace-nowrap">' . htmlspecialchars($row['id']) . '</td>';
                  echo '<td class="px-6 py-4 whitespace-nowrap">' . htmlspecialchars($row['name']) . '</td>';
                  echo '<td class="px-6 py-4 whitespace-nowrap">' . htmlspecialchars($row['email']) . '</td>';
                  echo '<td class="px-6 py-4 whitespace-nowrap text-right">';
                  echo '<a href="admin_manager_users.php?delete=' . $row['id'] . '" class="text-red-600 hover:text-red-800">Delete</a>';
                  echo '</td>';
                  echo '</tr>';
              }
          } else {
              echo '<tr><td colspan="4" class="px-6 py-4 text-center text-gray-500">No users found.</td></tr>';
          }
          ?>
        </tbody>
      </table>
    </div>
  </div>

</body>
</html>

<?php
$conn->close();
?>
