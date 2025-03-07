<?php
session_start();

if (!isset($_SESSION['user'])) {
    header("Location: login.php");
    exit();
}

if (isset($_GET['logout'])) {
    session_destroy();
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

$searchQuery = '';
if (isset($_GET['search'])) {
    $searchQuery = $_GET['search'];
    $sql = "SELECT * FROM watches WHERE brand LIKE ? OR description LIKE ? OR type LIKE ?";
    $stmt = $conn->prepare($sql);
    $searchTerm = "%$searchQuery%";
    $stmt->bind_param('sss', $searchTerm, $searchTerm, $searchTerm);
    $stmt->execute();
    $result = $stmt->get_result();
} else {
    $sql = "SELECT * FROM watches";
    $result = $conn->query($sql);
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Home - The Timezone</title>
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/owl.carousel@2/dist/assets/owl.carousel.min.css">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/owl.carousel@2/dist/assets/owl.theme.default.min.css">
  <script src="https://cdn.jsdelivr.net/npm/jquery@3.6.0/dist/jquery.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/owl.carousel@2/dist/owl.carousel.min.js"></script>
  <script src="https://cdn.tailwindcss.com"></script>
  <script>
    $(document).ready(function(){
      $(".owl-carousel").owlCarousel({
        items: 3,
        loop: true,
        autoplay: true,
        autoplayTimeout: 3000,
        autoplayHoverPause: true,
        nav: true,
        dots: true
      });
    });
  </script>

</head>
<body class="bg-gray-100">

  <!-- Header -->
  <?php include 'header.php'; ?>

  <!-- Hero Section with Owl Carousel -->
  <!-- collection section start -->
  <div class="w-full h-20">  </div>
     <div class="max-w-6xl m-auto">   
      <h4 class="text-center text-[#7a6256] font-serif lg:text-2xl md:text-xl">GLAMOR EDITION</h4>
      <h1 class="text-center text-[#090301] font-serif lg:text-6xl  pt-5">SPECIAL COLLECTIONS</h1>
      <div class="owl-carousel flex mx-auto justify-evenly  p-10">
          <div class="item mx-2 border border-gray-300 pb-5 hover:shadow-2xl hover:border-hidden duration-700 transition delay-150 ease-in-out hover:-translate-y-1 hover:scale-95">
             <div class="flex"> <img src="../assets/images/asset 4.jpeg" ></div>
              <h4 class="text-center text-xl font-serif">Stainless Steel Dail</h4>
              <p class="text-center text-lg text-[#7a6256]">Rs.3,000.00</p>
          </div>
          <div class="item mx-2 border border-gray-300 pb-5 hover:shadow-2xl hover:border-hidden duration-700 transition delay-150 ease-in-out hover:-translate-y-1 hover:scale-95">
              <img src="../assets/images/asset 5.jpeg">
              <h4 class="text-center text-xl font-serif">Golden Dail Watch</h4>
              <p class="text-center text-lg text-[#7a6256]">Rs.3,000.00</p>
          </div>
          <div class="item mx-2 border border-gray-300 pb-5 hover:shadow-2xl hover:border-hidden duration-700 transition delay-150 ease-in-out hover:-translate-y-1 hover:scale-95">
              <img src="../assets/images/asset 6.jpeg">
              <h4 class="text-center text-xl font-serif">Analog Strap Watch</h4>
              <p class="text-center text-lg text-[#7a6256]">Rs.3,000.00</p>
          </div>
          <div class="item mx-2 border border-gray-300 pb-5 hover:shadow-2xl hover:border-hidden duration-700 transition delay-150 ease-in-out hover:-translate-y-1 hover:scale-95">
              <img src="../assets/images/asset 7.jpeg">
              <h4 class="text-center text-xl font-serif">Analog Strap Watch</h4>
              <p class="text-center text-lg text-[#7a6256]">Rs.3,000.00</p>
          </div>
      </div>
     </div>
      <!-- collection section end -->
       
 <!-- categories section start -->
       <div class="min-h-50 w-full"></div>
       <div class="max-w-6xl m-auto">
         <div class="flex gap-10">
            
             <div class="categories flex gap-10">
                 <!-- Men's Watch -->
                 <div class="relative p-2 border-r-1 border-b-1 border-[#7a6256] p-5">
                     <img src="../assets/images/asset 8.jpeg" alt="Men's Watch" class="w-full h-auto">
                     <p class="absolute inset-0 flex items-center justify-center text-white text-4xl font-light tracking-widest">
                         MENS WATCH
                     </p>
                 </div>
             
         
                 <!-- Women's Watch -->
                 <div class="relative p-2 border-r-1 border-b-1 border-[#7a6256] p-5">
                     <img src="../assets/images/asset 9.jpeg" alt="Women's Watch" class="w-full h-auto ">
                   <p class=" absolute inset-0 flex items-center justify-center text-white text-4xl font-light tracking-widest">
                     WOMENS WATCH
                 </p>
             </div>
         </div>
       </div>
       </div>
        <!-- categories section end -->
        <div class="container mx-auto px-6 py-12">
                <div class="flex flex-col lg:flex-row items-center justify-center">
                  
                    <div class="signature lg:w-1/2 p-6 border-r-1 border-b-1 border-t-1 border-[#7a6256] ">
                        <h2 class="text-3xl font-light tracking-widest mb-4">
                            Perfect combination of style and design in wrist watches
                        </h2>
                        <p class="text-gray-500 mb-6 tracking-widest">
                            Dignissim diam quis enim lobortis. Egestas sed tempus urna et pharetra pharetra massa. 
                            Platea dictumst quisque sagittis purus sit amet. Nunc mi ipsum faucibus vitae aliquet nec.
                        </p>
                        <div class="flex items-center space-x-2">
                            <img src="../assets/images/asset 15.png" alt="Signature" class="h-8">
                            <span class="text-gray-600 tracking-widest">- Nicolas</span>
                        </div>
                    </div>
                </div>
  </div>
          <!-- section4 start -->
          <div class="min-h-30 w-full"></div>
        <div class="max-w-6xl m-auto">
            <div class="img-1">
                <img src="../assets/images/asset 10.jpeg">
             </div>
        </div>
         <div class="bg-[#2c2323] w-full h-auto">
            <div class="max-w-6xl m-auto">
                <div class="min-h-30 w-full"></div>
                <div class="heading flex justify-center">
                    <p class="font text-xl text-center text-wrap text-[#ecc696] font-mono font-thin leading-8 tracking-widest uppercase">Sed faucibus in eu mi bibendum neque. Pulvinar pellentesque habitant morbi tristique senectus et netus et.</p>
                </div>
                <div class="content flex justify-evenly py-10 gap-10 text-[#7a6256]">
                    <div><p class="text-[15px] leading-6 tracking-normal">Morbi tincidunt augue interdum velit euismod. Nulla pharetra<br> diam sit amet nisl. Et netus et malesuada fames ac turpis<br>     egestas maecenas. Penatibus et magnis dis parturient.</p></div>
                    <div ><p class="text-[15px] leading-6 tracking-normal">Lobortis mattis aliquam faucibus purus in massa <br>tempor nec feugiat. Ac feugiat sed lectus vestibulum <br>mattis ullamcorper. Purus faucibus ornare.</p></div>
                </div>
                <div class="section4-image flex gap-10 m-auto">
                    <div><img src="../assets/images/asset 11.jpeg" class="max-w-auto"></div>
                    <div class="section4-image block">
                        <img src="../assets/images/asset 12.png" class="block_image max-w-auto">
                        <img src="../assets/images/asset 14.png" class="block_image max-w-auto">
                    </div>
                    <div><img src="../assets/images/asset 13.jpeg" class="max-w-auto"></div>
                </div>
            </div>
         </div>
        
           <!-- section4 end -->
  <!-- section5 start -->
  <div class="container mx-auto px-6 py-12">
                <div class="min-h-20 w-full"></div>
                <div class="mt-12 text-left">
                    <span class="text-gray-500 uppercase text-lg tracking-widest">Certified Watches</span>
                    <h3 class="text-6xl font-thin tracking-widest mt-2 uppercase">Durable & Style</h3>
                </div>
                <div class="container mx-auto py-10">
                    <div class="grid grid-cols-1 md:grid-cols-3 lg:gap-20 sm:gap-0">
                        <!-- Watch 1 -->
                        <div class="text-center">
                            <img src="../assets/images/asset 17.jpeg" alt="Mineral Glass Watch" class="w-full object-cover  mt-20">
                            <p class="mt-3 text-gray-600 tracking-widest">MINERAL GLASS</p>
                        </div>
                        <!-- Watch 2 -->
                        <div class="text-center">
                            <img src="../assets/images/asset 18.jpeg" alt="Quartz Analog Watch" class="w-full object-cover  lg:mt-40 sm:mt-10">
                            <p class="mt-3 text-gray-600 tracking-widest">QUARTZ ANALOG</p>
                        </div>
                        <!-- Watch 3 -->
                        <div class="text-center">
                            <img src="../assets/images/asset 19.jpeg" alt="Two-Tone Rose Gold Watch" class="w-full object-cover sm:mt-10">
                            <p class="mt-3 text-gray-600 tracking-widest">TWO-TONE ROSE GOLD</p>
                        </div>
                    </div>
                </div>
                <div class="fixed bottom-6 right-6 bg-orange-300 p-3 rounded-lg shadow-lg">
                    <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" class="w-6 h-6 text-white">
                        <path stroke-linecap="round" stroke-linejoin="round" d="M12 6v6l4 2"></path>
                        <circle cx="12" cy="12" r="9" stroke="currentColor" stroke-width="1.5"></circle>
                    </svg>
                </div>
            </div>
            <!-- section5 end -->

  <!-- Search Bar -->
  <div class="container mx-auto my-8 pt-10">
    <form action="home.php" method="GET" class="flex justify-center">
      <input type="text" name="search" value="<?php echo htmlspecialchars($searchQuery); ?>" class="w-full max-w-lg p-3 border border-gray-300 rounded-l-md focus:outline-none focus:ring-2 focus:ring-blue-500" placeholder="Search for a watch...">
      <button type="submit" class="p-3 bg-[#7a6256] text-white rounded-r-md hover:bg-[#3c2f2f]">Search</button>
    </form>
  </div>

  <!-- Watches Display -->
<div class="max-w-7xl m-auto">
<div class="container mx-auto grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-8 mt-8 p-8">
    <?php
    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo '<div class="bg-white shadow-lg  overflow-hidden">';
            echo '<img src="' . $row['image_url'] . '" alt="' . htmlspecialchars($row['brand']) . '" class="w-full h-64 object-contain">';
            echo '<div class="p-4">';
            echo '<h3 class="text-xl font-semibold mb-2 text-[#7a6256]">' . htmlspecialchars($row['brand']) . '</h3>';
            echo '<p class="text-[#7a6256] mb-2">' . htmlspecialchars($row['description']) . '</p>';
            echo '<p class="text-gray-800 mb-2">Type: ' . htmlspecialchars($row['type']) . '</p>';
            echo '<p class="text-green-600 font-bold text-lg">₹' . number_format($row['price'], 0, '.', ',') . '</p>';
            echo '<a href="product.php?id=' . $row['id'] . '" class="mt-4 block text-center bg-[#7a6256] text-white py-2 rounded hover:bg-[#3c2f2f]">Buy Now</a>';
            echo '</div>';
            echo '</div>';
        }
    } else {
        echo '<p class="text-center text-gray-600">No watches found.</p>';
    }
    ?>
  </div>
</div>

  <!-- section7 start -->
  <div class="min-h-20 w-full"></div>
<div class="max-w-7xl m-auto">
    <p class="text-[#7a6256] tracking-widest">OUR STORIES</p>
    <H2 class="text-6xl font-thin tracking-widest text-gray-900 mt-4">OUR BLOG</H2>
    <button class="border px-5 py-2 mt-5 tracking-widest hover:bg-[#2c2323] text-[#7a6256] duration-700 font-semibold">VIEW ALL -></button>
    <div class="owl-carousel flex mt-20 gap-10">
        <div class="item mx-5">
            <img src="../assets/images/asset 26.jpeg">
            <p class="pt-10 text-[#7a6256] text-lg tracking-widest">MAY 30 , 2022</p>
            <P class="pt-10 text-2xl font-light tracking-widest text-[#7a6256]">HOW TO BUILD WATCHES BY MACHINE</P>
            <P class="pt-5 text-[#7a6256] text-lg font-normal tracking-widest">Lorem ipsum dolor sit amet consectetur adipisicing elit.... </P>
        </div>
        <div  class="item mx-5">
            <img src="../assets/images/asset 27.jpeg">
            <p class="pt-10 text-[#7a6256] text-lg tracking-widest">MAY 30 , 2022</p>
            <P class="pt-10 text-2xl font-light tracking-widest text-[#7a6256]">HOW TO BUILD WATCHES BY MACHINE</P>
            <P class="pt-5 text-[#7a6256] text-lg font-normal tracking-widest">Lorem ipsum dolor sit amet consectetur adipisicing elit.... </P>
        </div>
        <div>
        <div class="item mx-5">   
            <img src="../assets/images/asset 28.jpeg" ></div>
            <p class="pt-10 text-[#7a6256] text-lg tracking-widest">MAY 30 , 2022</p>
            <P class="pt-10 text-2xl font-light tracking-widest text-[#7a6256]">HOW TO BUILD WATCHES BY MACHINE</P>
            <P class="pt-5 text-[#7a6256] text-lg font-normal tracking-widest">Lorem ipsum dolor sit amet consectetur adipisicing elit.... </P>
        </div>
    </div>
    <hr class=" text-[#7a6256] mt-20">
</div>
<!-- section7 end -->
 <!-- section8 start -->
 <div class=" h-screen bg-no-repeat bg-center w-full sm:bg-contain md:bg-cover mt-50" style="background-image: url('../assets/images/asset\ 42.jpeg');">
    <div class="max-w-6xl m-auto pt-50">
        <p class="text-xl leading-[27.5px] text-[#7a6256] tracking-widest text-left uppercase">clients reactions</p>
        <h1 class="text-6xl text-left leading-[70.5px] tracking-widest text-[#090301] font-light ">OUT TESTIMONIALS</h1>
        <div class=" border-t-2 border-b-2 border-r-2 border-[#7a6256] py-10  my-10 w-xl">
      <p class="text-sm leading-[27.5px] text-[#7a6256] tracking-widest text-justify  uppercase">Lorem ipsum dolor sit, amet consectetur adipisicing elit. <br>Temporibus maiores molestiae nulla quos quaerat! Architecto<br> </p>
      <div class="flex pt-5">
        <img  src="../assets/images/test01_200x200.jpg" class="rounded-full">
        <div class="block p-5">
          <p class="text-lg text-[#7a6256] font-semibold">Matthew Marc</p>
          <p class="text-lg text-[#7a6256] font-light">Professor</p>
        </div>
      </div>
    </div>
    </div>
   
  </div>
 <!-- section8 end -->

 <footer class="bg-black text-gray-400 py-10">
        <div class="max-w-7xl mx-auto px-6 lg:px-8">
            <div class="grid grid-cols-1 md:grid-cols-3 gap-10 border-b border-gray-700 pb-10">
                <!-- Follow Us -->
                <div>
                    <h3 class="text-lg text-yellow-500 uppercase">Follow Us</h3>
                    <div class="flex space-x-4 mt-4">
                        <a href="#" class="w-10 h-10 flex items-center justify-center bg-gray-700 rounded-full">
                            <i class="fab fa-facebook-f text-white"></i>
                        </a>
                        <a href="#" class="w-10 h-10 flex items-center justify-center bg-gray-700 rounded-full">
                            <i class="fab fa-twitter text-white"></i>
                        </a>
                        <a href="#" class="w-10 h-10 flex items-center justify-center bg-gray-700 rounded-full">
                            <i class="fab fa-linkedin-in text-white"></i>
                        </a>
                        <a href="#" class="w-10 h-10 flex items-center justify-center bg-gray-700 rounded-full">
                            <i class="fab fa-instagram text-white"></i>
                        </a>
                    </div>
                </div>

                <!-- Brand Description -->
                <div class="text-center">
                    <h3 class="text-lg text-yellow-500 uppercase">Lance <span class="block text-sm text-gray-500">Watches</span></h3>
                    <p class="mt-4 text-sm">Mattis rhoncus urna neque viverra justo nec. Enim facilisis gravida neque convallis a cras semper. Sed sed risus pretium quam vulputate. Iaculis nunc sed augue lacus viverra vitae.</p>
                </div>

                <!-- Newsletter -->
                <div>
                    <h3 class="text-lg text-yellow-500 uppercase">Newsletter</h3>
                    <div class="mt-4 flex items-center border-b border-gray-600 pb-2">
                        <input type="email" placeholder="Enter email" class="bg-transparent flex-1 p-2 outline-none text-white placeholder-gray-500">
                        <button class="text-gray-400 text-sm">Subscribe</button>
                    </div>
                    <p class="mt-2 text-sm">We do not spam. We send offers instead.</p>
                </div>
            </div>

            <!-- Bottom Section -->
            <div class="mt-6 flex flex-col md:flex-row justify-between items-center text-sm">
                <div class="flex items-center space-x-2">
                    <span class="text-gray-500">&#9742;</span>
                    <span>(000) 123 456789</span>
                </div>
                <div class="flex items-center space-x-2 mt-2 md:mt-0">
                    <span class="text-gray-500">&#9993;</span>
                    <span>info@example.com</span>
                </div>
                <div class="text-center mt-2 md:mt-0">
                    No: 58 A, East Madison Street, Baltimore, MD, USA 4508
                </div>
            </div>
        </div>

        <!-- Scroll to Top -->
      
    </footer>

    <!-- Font Awesome for Icons -->
    <script src="https://kit.fontawesome.com/a076d05399.js" crossorigin="anonymous"></script>
</body>
</html>

<?php
$conn->close();
?>
