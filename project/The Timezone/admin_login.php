<?php
session_start();

if (isset($_SESSION['admin'])) {
    header("Location: admin_dashboard.php");
    exit();
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Hardcoded credentials
    $adminUsername = 'admin';
    $adminPassword = 'admin';

    if ($username === $adminUsername && $password === $adminPassword) {
        $_SESSION['admin'] = true;
        header("Location: admin_dashboard.php");
        exit();
    } else {
        $error = "Invalid username or password.";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Admin Login</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/tailwindcss@2.2.19/dist/tailwind.min.css">
</head>
<body class="bg-gray-100 flex items-center justify-center min-h-screen">

  <div class="bg-white p-8 rounded-lg shadow-md w-full max-w-sm">
    <h2 class="text-2xl font-bold mb-6 text-center">Admin Login</h2>
    <?php if (isset($error)): ?>
      <div class="bg-red-100 text-red-700 p-3 rounded mb-4"><?php echo htmlspecialchars($error); ?></div>
    <?php endif; ?>
    <form method="POST">
      <label for="username" class="block text-gray-700">Username</label>
      <input type="text" name="username" id="username" class="w-full p-2 border border-gray-300 rounded mb-4" required>
      
      <label for="password" class="block text-gray-700">Password</label>
      <input type="password" name="password" id="password" class="w-full p-2 border border-gray-300 rounded mb-6" required>
      
      <button type="submit" class="w-full bg-blue-600 text-white py-2 rounded hover:bg-blue-700">Login</button>
    </form>
  </div>

</body>
</html>
