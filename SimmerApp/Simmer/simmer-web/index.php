<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" >
  <meta name="viewport" content="width=device-width, initial-scale=1.0" >
  <title>Login PHP</title>
  <link rel="stylesheet" href="styles.css">
  <link href="https://fonts.googleapis.com/css2?family=Inter&display=swap" rel="stylesheet" >
</head>
<body>
  <div class="flex-container">
  <img src="images/Simmer (1).png" alt="Simmer Logo">
  <form class="login-box" action="login.php" method="POST">
    <?php if(isset($_GET['error'])) { ?>
        <p class="error"> <?php echo $_GET['error']; ?></p>
    <?php } ?>
    <div>
      <label for="username">Username</label>
      <input type="text" name="username" id="username" required >
    </div>

    <div>
      <label for="password">Password</label>
      <input type="password" name="password" id="password" required>
    </div>

    <button type="submit">Sign In</button>

    <div class="forgot">
      <a href="#">Forgot password?</a>
    </div>
  </form>
</div>
</body>
</html>