<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $message = $_POST['message'];

    // For demo purposes, just show a success message
    echo "<p class='text-center text-green-600'>Thank you, $name. Your message has been sent.</p>";
}
?>
