<?php
session_start();

if (!isset($_SESSION['user']) || !is_array($_SESSION['user'])) {
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

if (isset($_SESSION['user']['id'])) {
    $user_id = $_SESSION['user']['id'];
} else {
    die("User ID not found in session.");
}

$cart = isset($_SESSION['cart']) ? $_SESSION['cart'] : [];

if (!is_array($cart)) {
    die("Cart is not in the correct format.");
}

if (!empty($cart)) {
    foreach ($cart as $watch_id => $quantity) {
        if (!is_numeric($watch_id) || !is_numeric($quantity) || $quantity <= 0) {
            continue;
        }

        $sql = "SELECT price FROM watches WHERE id = ?";
        $stmt = $conn->prepare($sql);
        $stmt->bind_param('i', $watch_id);
        $stmt->execute();
        $result = $stmt->get_result();
        $watch = $result->fetch_assoc();

        if ($watch) {
            $total = $watch['price'] * $quantity;

            $sql = "INSERT INTO orders (user_id, watch_id, quantity, total) VALUES (?, ?, ?, ?)";
            $stmt = $conn->prepare($sql);
            $stmt->bind_param('iiid', $user_id, $watch_id, $quantity, $total);
            $stmt->execute();
        }
    }

    unset($_SESSION['cart']);
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Processing Payment</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <style>
        .loading {
            border: 5px solid rgba(0,0,0,0.1);
            border-radius: 50%;
            border-top: 5px solid #3498db;
            width: 50px;
            height: 50px;
            animation: spin 1s linear infinite;
        }
        @keyframes spin {
            0% { transform: rotate(0deg); }
            100% { transform: rotate(360deg); }
        }
    </style>
</head>
<body class="flex items-center justify-center h-screen bg-gray-100">
    <div class="text-center">
        <div class="loading mx-auto mb-4"></div>
        <h2 class="text-xl font-semibold mb-2">Processing Payment...</h2>
        <p class="text-gray-600">Please wait while we process your payment. You will be redirected shortly.</p>
    </div>

    <script>
        setTimeout(function() {
            window.location.href = 'my_orders.php';
        }, 2000);
    </script>
</body>
</html>
