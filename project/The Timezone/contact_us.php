<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Contact Us - The Timezone</title>
  <script src="https://cdn.tailwindcss.com"></script>
</head>
<body class="bg-gray-100">

  <!-- Header -->
  <?php include 'header.php'; ?>

  <!-- Contact Us Section -->
  <section class="max-w-4xl mx-auto p-8 bg-white shadow-lg rounded-lg my-8">
    <h1 class="text-3xl font-bold mb-4">Contact Us</h1>
    <form method="POST" action="send_contact.php">
      <div class="mb-4">
        <label for="name" class="block text-sm font-medium text-gray-700">Name</label>
        <input type="text" name="name" class="w-full p-2 border border-gray-300 rounded" required>
      </div>
      <div class="mb-4">
        <label for="email" class="block text-sm font-medium text-gray-700">Email</label>
        <input type="email" name="email" class="w-full p-2 border border-gray-300 rounded" required>
      </div>
      <div class="mb-4">
        <label for="message" class="block text-sm font-medium text-gray-700">Message</label>
        <textarea name="message" rows="5" class="w-full p-2 border border-gray-300 rounded" required></textarea>
      </div>
      <button type="submit" class="w-full bg-blue-600 text-white p-2 rounded">Send Message</button>
    </form>
  </section>

</body>
</html>
