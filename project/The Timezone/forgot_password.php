<?php
session_start();

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Normally, you would send a reset link to the user's email and handle token generation here.
    // For simplicity, we'll just display a message.

    $email = $_POST['email'];
    
    // For demo purposes, we'll just show a success message.
    echo "<p class='text-center text-green-600'>If an account with that email exists, a password reset link has been sent to $email.</p>";
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Forgot Password - The Timezone</title>
  <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-gray-100 h-screen flex justify-center items-center">
  <div class="w-full max-w-md p-8 bg-white shadow-lg rounded-lg">
    <h2 class="text-2xl font-bold text-center mb-6">Forgot Password</h2>
    <form method="POST">
      <div class="mb-4">
        <label for="email" class="block text-sm font-medium text-gray-700">Email</label>
        <input type="email" name="email" class="w-full p-2 border border-gray-300 rounded" required>
      </div>
      <button type="submit" class="w-full bg-blue-600 text-white p-2 rounded">Submit</button>
    </form>
    <p class="text-sm text-center mt-4">Remember your password? <a href="login.php" class="text-blue-500 underline">Login</a></p>
  </div>
</body>
</html>
