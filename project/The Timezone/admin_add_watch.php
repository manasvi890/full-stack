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

$successMessage = '';
$errorMessage = '';

// Handle form submission to add a new watch
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['add_watch'])) {
    $brand = $_POST['brand'];
    $description = $_POST['description'];
    $type = $_POST['type'];
    $price = $_POST['price'];
    $imageUrl = $_POST['image_url'];

    if (!empty($brand) && !empty($description) && !empty($type) && !empty($price) && !empty($imageUrl)) {
        $sqlInsert = "INSERT INTO watches (brand, description, type, price, image_url) VALUES (?, ?, ?, ?, ?)";
        $stmtInsert = $conn->prepare($sqlInsert);
        $stmtInsert->bind_param("sssds", $brand, $description, $type, $price, $imageUrl);

        if ($stmtInsert->execute()) {
            $successMessage = "Watch added successfully!";
        } else {
            $errorMessage = "Error adding watch.";
        }
    } else {
        $errorMessage = "Please fill in all fields.";
    }
}

// Handle watch deletion
if (isset($_GET['delete'])) {
    $watchId = intval($_GET['delete']);
    $sqlDelete = "DELETE FROM watches WHERE id = ?";
    $stmtDelete = $conn->prepare($sqlDelete);
    $stmtDelete->bind_param('i', $watchId);
    
    if ($stmtDelete->execute()) {
        $successMessage = "Watch deleted successfully!";
    } else {
        $errorMessage = "Error deleting watch.";
    }
}

// Handle watch editing
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['edit_watch'])) {
    $watchId = $_POST['watch_id'];
    $brand = $_POST['edit_brand'];
    $description = $_POST['edit_description'];
    $type = $_POST['edit_type'];
    $price = $_POST['edit_price'];
    $imageUrl = $_POST['edit_image_url'];

    if (!empty($brand) && !empty($description) && !empty($type) && !empty($price) && !empty($imageUrl)) {
        $sqlUpdate = "UPDATE watches SET brand = ?, description = ?, type = ?, price = ?, image_url = ? WHERE id = ?";
        $stmtUpdate = $conn->prepare($sqlUpdate);
        $stmtUpdate->bind_param("sssdsi", $brand, $description, $type, $price, $imageUrl, $watchId);

        if ($stmtUpdate->execute()) {
            $successMessage = "Watch updated successfully!";
        } else {
            $errorMessage = "Error updating watch.";
        }
    } else {
        $errorMessage = "Please fill in all fields.";
    }
}

// Fetch all available watches
$sqlWatches = "SELECT id, brand, description, type, price, image_url FROM watches";
$resultWatches = $conn->query($sqlWatches);
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Add and Manage Watches</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css">
  <script>
    function openEditModal(id, brand, description, type, price, imageUrl) {
      document.getElementById('editModal').style.display = 'block';
      document.getElementById('watch_id').value = id;
      document.getElementById('edit_brand').value = brand;
      document.getElementById('edit_description').value = description;
      document.getElementById('edit_type').value = type;
      document.getElementById('edit_price').value = price;
      document.getElementById('edit_image_url').value = imageUrl;
    }

    function closeEditModal() {
      document.getElementById('editModal').style.display = 'none';
    }
  </script>
</head>
<body class="bg-gray-100">

  <!-- Admin Header -->
  <?php include 'admin_header.php'; ?>

  <div class="container mx-auto p-8">
    <h1 class="text-3xl font-bold mb-8">Add New Watch</h1>

    <?php if (!empty($successMessage)) : ?>
      <p class="text-green-600 mb-4"><?php echo $successMessage; ?></p>
    <?php endif; ?>
    
    <?php if (!empty($errorMessage)) : ?>
      <p class="text-red-600 mb-4"><?php echo $errorMessage; ?></p>
    <?php endif; ?>

    <!-- Add Watch Form -->
    <div class="bg-white shadow-md rounded-lg p-6 mb-8">
      <form action="admin_add_watch.php" method="POST" class="space-y-6">
        <input type="hidden" name="add_watch" value="1">
        <div>
          <label for="brand" class="block text-sm font-medium text-gray-700">Brand</label>
          <input type="text" name="brand" id="brand" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required>
        </div>

        <div>
          <label for="description" class="block text-sm font-medium text-gray-700">Description</label>
          <textarea name="description" id="description" rows="4" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required></textarea>
        </div>

        <div>
          <label for="type" class="block text-sm font-medium text-gray-700">Type</label>
          <input type="text" name="type" id="type" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required>
        </div>

        <div>
          <label for="price" class="block text-sm font-medium text-gray-700">Price (₹)</label>
          <input type="number" step="0.01" name="price" id="price" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required>
        </div>

        <div>
          <label for="image_url" class="block text-sm font-medium text-gray-700">Image URL</label>
          <input type="url" name="image_url" id="image_url" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required>
        </div>

        <div>
          <button type="submit" class="w-full bg-blue-600 text-white py-3 rounded-md hover:bg-blue-700">Add Watch</button>
        </div>
      </form>
    </div>

    <!-- Display Available Watches -->
    <h1 class="text-3xl font-bold mb-8">Available Watches</h1>

    <div class="bg-white shadow-md rounded-lg p-6">
      <table class="min-w-full divide-y divide-gray-200">
        <thead class="bg-gray-50">
          <tr>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">ID</th>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">Brand</th>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">Description</th>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">Type</th>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">Price</th>
            <th class="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">Actions</th>
          </tr>
        </thead>
        <tbody class="bg-white divide-y divide-gray-200">
          <?php
          if ($resultWatches->num_rows > 0) {
              while ($row = $resultWatches->fetch_assoc()) {
                  echo '<tr>';
                  echo '<td class="px-6 py-4 whitespace-nowrap">' . htmlspecialchars($row['id']) . '</td>';
                  echo '<td class="px-6 py-4 whitespace-nowrap">' . htmlspecialchars($row['brand']) . '</td>';
                  echo '<td class="px-6 py-4 whitespace-nowrap">' . htmlspecialchars($row['description']) . '</td>';
                  echo '<td class="px-6 py-4 whitespace-nowrap">' . htmlspecialchars($row['type']) . '</td>';
                  echo '<td class="px-6 py-4 whitespace-nowrap">₹' . number_format($row['price'], 2) . '</td>';
                  echo '<td class="px-6 py-4 whitespace-nowrap text-right">';
                  echo '<a href="javascript:void(0);" class="text-blue-600 hover:text-blue-800" onclick="openEditModal(' . $row['id'] . ', \'' . htmlspecialchars($row['brand']) . '\', \'' . htmlspecialchars($row['description']) . '\', \'' . htmlspecialchars($row['type']) . '\', ' . $row['price'] . ', \'' . htmlspecialchars($row['image_url']) . '\')">Edit</a> | ';
                  echo '<a href="admin_add_watch.php?delete=' . $row['id'] . '" class="text-red-600 hover:text-red-800">Delete</a>';
                  echo '</td>';
                  echo '</tr>';
              }
          } else {
              echo '<tr><td colspan="6" class="px-6 py-4 text-center text-gray-500">No watches found.</td></tr>';
          }
          ?>
        </tbody>
      </table>
    </div>
  </div>

  <!-- Edit Modal -->
  <div id="editModal" class="fixed z-10 inset-0 overflow-y-auto" style="display:none;">
    <div class="flex items-center justify-center min-h-screen px-4">
      <div class="bg-white rounded-lg overflow-hidden shadow-xl transform transition-all max-w-lg w-full">
        <div class="bg-gray-50 px-4 py-5 sm:px-6">
          <h3 class="text-lg leading-6 font-medium text-gray-900">Edit Watch</h3>
        </div>
        <div class="px-4 py-5 sm:p-6">
          <form action="admin_add_watch.php" method="POST">
            <input type="hidden" name="edit_watch" value="1">
            <input type="hidden" id="watch_id" name="watch_id">
            <div>
              <label for="edit_brand" class="block text-sm font-medium text-gray-700">Brand</label>
              <input type="text" name="edit_brand" id="edit_brand" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required>
            </div>
            <div>
              <label for="edit_description" class="block text-sm font-medium text-gray-700">Description</label>
              <textarea name="edit_description" id="edit_description" rows="4" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required></textarea>
            </div>
            <div>
              <label for="edit_type" class="block text-sm font-medium text-gray-700">Type</label>
              <input type="text" name="edit_type" id="edit_type" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required>
            </div>
            <div>
              <label for="edit_price" class="block text-sm font-medium text-gray-700">Price (₹)</label>
              <input type="number" step="0.01" name="edit_price" id="edit_price" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required>
            </div>
            <div>
              <label for="edit_image_url" class="block text-sm font-medium text-gray-700">Image URL</label>
              <input type="url" name="edit_image_url" id="edit_image_url" class="mt-1 block w-full p-3 border border-gray-300 rounded-md shadow-sm" required>
            </div>
            <div class="mt-5 sm:mt-6">
              <button type="submit" class="w-full bg-blue-600 text-white py-3 rounded-md hover:bg-blue-700">Update Watch</button>
              <button type="button" class="w-full mt-2 bg-gray-600 text-white py-3 rounded-md hover:bg-gray-700" onclick="closeEditModal()">Cancel</button>
            </div>
          </form>
        </div>
      </div>
    </div>
  </div>

</body>
</html>

<?php
$conn->close();
?>
