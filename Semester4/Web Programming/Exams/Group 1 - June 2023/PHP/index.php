<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Αρχική</title>
    <style>
        html {
            height: 100%;
        }

        footer {
            position: fixed;
            bottom: 0;
            left: 10;
            width: 100%;
        }

        h1 {
            color: red;
        }
    </style>
</head>

<body>

    <?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "test";
    $tabname = "iis23000";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn -> connect_errno) {
        die("Σφάλμα κατά τη σύνδεση με τη βάση δεδομένων");
    }

    $sql = "CREATE TABLE IF NOT EXISTS $tabname (
            id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
            name VARCHAR(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci
        )";

    if (mysqli_query($conn, $sql)) {
        echo "Ο πίνακας $tabname δημιουργήθηκε επιτυχώς";
    } else {
        echo "ΔΕΝ έγινε δημιουργία του πίνακα.";
    }

    mysqli_close($conn);

    ?>
    <br>
    <a href="kataxorisi.php">Καταχώρηση</a>
    <a href="diorthosi.php">Διόρθωση</a>
    <footer>
        <h1>ΟΝΟΜΑΤΕΠΩΝΥΜΟ - ΑΡΙΘΜΟΣ ΜΗΤΡΩΟΥ</h1>
    </footer>
</body>

</html>