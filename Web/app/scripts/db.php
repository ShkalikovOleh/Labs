<?php

$firstName = $_REQUEST['FirstName'];
$lastName = $_REQUEST['LastName'];
$middleName = $_REQUEST['MiddleName'];
$birthday = $_REQUEST['Birthday'];
$groupChipher = $_REQUEST['GroupCipher'];
$groupNumber = $_REQUEST['GroupNumber'];
$facultyName = $_REQUEST['Faculty'];
#$firstName = "Oleh";
#$lastName = "Shkalikov";
#$middleName = "Volodymyrovich";
#$birthday = "2001-02-28";
#$groupChipher = "FI";
#$groupNumber = 81;
#$facultyName = "IPT";

$connection = new mysqli('db', 'user', 'password', 'LabsDB');

if ($connection->connect_errno > 0) 
{
    die($connection->connect_errno);
}

$getAllStudents = <<<SQL
    SELECT Students.FirstName, Students.MiddleName, Students.LastName, Students.Birthday, Classes.Cipher, Classes.Code, Faculties.Name
    FROM Students
    JOIN Classes ON Classes.Id = Students.ClassId
    JOIN Faculties ON Faculties.Id = Classes.FacultyId;
SQL;

$preGetFacultyId = $connection->prepare("SELECT Id FROM Faculties WHERE Name = ?");
$preCreateFaculty = $connection->prepare("INSERT Faculties(Name) VALUES (?)");
$preGetFacultyId->bind_param('s',$facultyName);
$preCreateFaculty->bind_param('s',$facultyName);
$preGetFacultyId->bind_result($facultyId);

$preGetClassId = $connection->prepare("SELECT Id FROM Classes WHERE Cipher = ? AND Code = ?");
$preCreateClass = $connection->prepare("INSERT Classes(Cipher, Code, FacultyId) VALUES(?,?,?)");
$preGetClassId->bind_param('si', $groupChipher, $groupNumber);
$preCreateClass->bind_param('sii', $groupChipher, $groupNumber, $facultyId);
$preGetClassId->bind_result($classId);

$preCreateStudent = $connection->prepare("INSERT Students(FirstName, LastName, MiddleName, Birthday, ClassId) VALUES (?,?,?,?,?)");
$preCreateStudent->bind_param('ssssi', $firstName, $lastName, $middleName, $birthday, $classId);

$facultyId = null;
$classId = null;

$preGetFacultyId->execute();
$preGetFacultyId->fetch();

if(!$facultyId)
{
    $preCreateFaculty->execute();
    $preGetFacultyId->execute();
    $preGetFacultyId->fetch();

    $preCreateFaculty->close();
}
$preGetFacultyId->close();

$preGetClassId->execute();
$preGetClassId->fetch();

if(!$classId)
{
    $preCreateClass->execute();
    $preGetClassId->execute();
    $preGetClassId->fetch();

    $preCreateClass->close();
}
$preGetClassId->close();

$preCreateStudent->execute();
$preCreateStudent->close();

$result = $connection->query($getAllStudents) or die('505 :)');

if($connection->affected_rows > 0)
{
    echo "<H1>All Students</H1>";
    while($row = $result->fetch_assoc())
    {
        echo "Name: " . $row['LastName'] . ' ' . $row['FirstName'] .'</br>';
    }
}

$connection->close();

?>