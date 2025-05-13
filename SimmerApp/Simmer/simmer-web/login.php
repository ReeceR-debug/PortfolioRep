<?php
session_start();
include "db_connect.php";

if (isset($_POST['username']) && isset($_POST['password'])) {

    function validate($data) {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }

    $username = validate($_POST['username']);
    $password = validate($_POST['password']);

    if (empty($username)) {
        header("Location: index.php?error=User Name is required");
        exit();
    } else if (empty($password)) {
        header("Location: index.php?error=Password is required");
        exit();
    }

    // Use prepared statements to prevent SQL injection
    $stmt = $conn->prepare("SELECT * FROM users WHERE user_name = ?");
    $stmt->bind_param("s", $username);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result && $result->num_rows === 1) {
        $row = $result->fetch_assoc();

        // If using hashed passwords:
        // if (password_verify($password, $row['password'])) {
        if ($row['password'] === $password) {
            $_SESSION['user_name'] = $row['user_name'];
            $_SESSION['name'] = $row['name'];
            $_SESSION['id'] = $row['id'];
            header("Location: home.php");
            exit();
        } else {
            header("Location: index.php?error=Incorrect Username or Password");
            exit();
        }
    } else {
        header("Location: index.php?error=Incorrect Username or Password");
        exit();
    }

} else {
    header("Location: index.php");
    exit();
}
?>
