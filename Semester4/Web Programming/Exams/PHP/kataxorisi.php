<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Καταχώρηση</title>
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

        h1,
        .error {
            color: red;
        }
    </style>
</head>

<body>
    <h2>Καταχώρηση</h2>
    <?php
    $nameErr = "";
    $name = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if (empty($_POST["name"])) {
            $nameErr = "Υποχρεωτικό πεδίο";
        } else {
            $name = test_input($_POST["name"]);
            $nameErr = "";

            if (!preg_match("/^[\p{L}\s]*$/u", $name)) {
                $nameErr = "Επιτρέπονται μόνο γράμματα και ο κενός χαρακτήρας";
            }
        }
    }

    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "test";
    $tabname = "iis23000";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn -> connect_errno) {
        die("Σφάλμα κατά τη σύνδεση με τη βάση δεδομένων");
    }

    if (!empty($name) && empty($nameErr)) {

        $sql = "INSERT INTO $tabname (name) VALUES ('$name')";
        $sql2 = "SELECT COUNT(*) as total FROM $tabname";

        if (mysqli_query($conn, $sql)) {
            $result = mysqli_query($conn, $sql2);

            $row = $result->fetch_assoc();

            $totalInsertions = $row["total"];

            echo "Συνολικές εγγραφές: " . $totalInsertions;
        } else {
            echo "Απέτυχε η εισαγωγή δεδομένων";
        }
    }

    mysqli_close($conn);

    function test_input($data)
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }
    ?>

    <form method="post" action="<?php $_SERVER["PHP_SELF"]; ?>">
        Name: <input type="text" name="name">
        <span class="error">*
            <?php echo $nameErr; ?>
        </span>
        <br><br>
        <input type="submit" name="submit" value="Υποβολή">
    </form>

    <a href="index.php">Αρχική</a>
    <a href="diorthosi.php">Διόρθωση</a>
    <footer>
        <h1>ΟΝΟΜΑΤΕΠΩΝΥΜΟ - ΑΡΙΘΜΟΣ ΜΗΤΡΩΟΥ</h1>
    </footer>
</body>

</html>