<?php
session_start();

$host = "localhost:3307";
$username = "root";
$password = "chamoli";
$dbname = "timezone";
$conn = new mysqli($host, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $email = $_POST['email'];
    $password = $_POST['password'];

    $sql = "SELECT * FROM users WHERE email = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param('s', $email);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        $user = $result->fetch_assoc();
        if (password_verify($password, $user['password'])) {
            $_SESSION['user'] = [
                'id' => $user['id'],
                'name' => $user['name'],
                'email' => $user['email']
            ];
            header("Location: home.php");
            exit();
        } else {
            echo "Invalid password!";
        }
    } else {
        echo "No user found with this email!";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Login - The Timezone</title>
  <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-gray-100 h-screen flex justify-center items-center">
  <div class="w-full max-w-md p-8 bg-white shadow-lg rounded-lg">
    <h2 class="text-2xl font-bold text-center mb-6">Login to The Timezone</h2>
    <form method="POST">
      <div class="mb-4">
        <label for="email" class="block text-sm font-medium text-gray-700">Email</label>
        <input type="email" name="email" id="email" class="w-full p-2 border border-gray-300 rounded" required>
      </div>
      <div class="mb-4">
        <label for="password" class="block text-sm font-medium text-gray-700">Password</label>
        <input type="password" name="password" id="password" class="w-full p-2 border border-gray-300 rounded" required>
      </div>
      <button type="submit" class="w-full bg-blue-600 text-white p-2 rounded">Login</button>
    </form>
    <p class="text-sm text-center mt-4">Don't have an account? 
      <a href="register.php" class="text-blue-500 underline">Register</a>
    </p>
     <p class="text-sm text-center mt-4">Forgot Password? 
      <a href="forgot_password.php" class="text-blue-500 underline">Click Here</a>
    </p>
  </div>

   


</body>
</html>
