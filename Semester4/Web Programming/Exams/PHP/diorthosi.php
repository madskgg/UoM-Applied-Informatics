<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Διόρθωση</title>
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
    <?php
    $nameErr = "";
    $name = "";

    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "test";
    $tabname = "iis23000";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if ($conn -> connect_errno) {
        die("Σφάλμα κατά τη σύνδεση με τη βάση δεδομένων");
    }

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $id = $_POST["id"];
        $name = $_POST["name"];
        if (!empty($_POST["name"])) {
            $name = test_input($_POST["name"]);
            $nameErr = "";
            
            if (!preg_match("/^[\p{L}\s]*$/u", $name)) {
                $nameErr = "Επιτρέπονται μόνο γράμματα και ο κενός χαρακτήρας";
            } else {
                
                $sql = "UPDATE $tabname SET name='$name' WHERE id='$id' AND EXISTS (SELECT * FROM $tabname WHERE id='$id')";

                if ($conn->query($sql)) {
                    $updatedRows = $conn->affected_rows;
                    if ($updatedRows > 0) {
                        echo "<p>Επιτυχής τροποποίηση δεδομένων! Έχει γίνει τροποποίηση σε συνολικά $updatedRows εγγραφές.</p>";
                    } else {
                        echo "<p>Εισάγατε ίδιο όνομα για την διόρθωση της εγγραφής</p>";
                    }
                } else {
                    echo "<p>Απέτυχε η τροποποίηση δεδομένων.</p>";
                }
            }
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

    <h2>Φόρμα Διόρθωσης</h2>

    <form method="post" action="<?php $_SERVER["PHP_SELF"]?>">
        ID: <input type="text" name="id"> <span class="error">*</span>
        <br><br>
        Name:
        <input type="text" name="name">
        <span class="error">*
            <?php echo $nameErr; ?>
        </span>
        <br><br>
        <span class="error">Υποχρεωτικό πεδίο</span>
        <br><br>
        <input type="submit" value="Υποβολή">
    </form>

    <a href="index.php">Αρχική</a>
    <a href="kataxorisi.php">Καταχώρηση</a>
    <footer>
        <h1>ΟΝΟΜΑΤΕΠΩΝΥΜΟ - ΑΡΙΘΜΟΣ ΜΗΤΡΩΟΥ</h1>
    </footer>
</body>

</html>