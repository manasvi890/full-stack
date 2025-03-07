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

$user_id = $_SESSION['user']['id'];

$sql = "SELECT orders.*, watches.brand, watches.image_url, watches.description FROM orders 
        JOIN watches ON orders.watch_id = watches.id
        WHERE orders.user_id = ? ORDER BY orders.created_at DESC";
$stmt = $conn->prepare($sql);
$stmt->bind_param('i', $user_id);
$stmt->execute();
$result = $stmt->get_result();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Orders</title>
    <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-gray-100">
    <!-- Header -->
    <?php include 'header.php'; ?>

    <!-- Orders Section -->
    <section class="py-8">
        <div class="container mx-auto px-4">
            <h2 class="text-2xl font-bold mb-4">My Orders</h2>
            <div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-4">
                <?php if ($result->num_rows > 0): ?>
                    <?php while ($order = $result->fetch_assoc()): ?>
                        <div class="bg-white rounded-lg shadow-lg p-4">
                            <img src="<?php echo htmlspecialchars($order['image_url']); ?>" alt="<?php echo htmlspecialchars($order['brand']); ?>" class="w-full h-48 object-cover mb-4">
                            <h3 class="text-xl font-semibold"><?php echo htmlspecialchars($order['brand']); ?></h3>
                            <p class="text-gray-600"><?php echo htmlspecialchars($order['description']); ?></p>
                            <p class="mt-2 font-bold">Quantity: <?php echo htmlspecialchars($order['quantity']); ?></p>
                            <p class="mt-2 font-bold">Total: ₹<?php echo htmlspecialchars($order['total']); ?></p>
                            <p class="text-gray-500 text-sm">Ordered on: <?php echo htmlspecialchars($order['created_at']); ?></p>
                        </div>
                    <?php endwhile; ?>
                <?php else: ?>
                    <p class="text-gray-600">You have no orders yet.</p>
                <?php endif; ?>
            </div>
        </div>
    </section>
</body>
</html>
