<?php 

$name = $_POST['name'];
$birthday = $_POST['birthday'];
$email = $_POST['email'];
$desk = $_POST['desk'];
$errorList = array();

function CheckRequired($value, $name)
{
    global $errorList;
    if(empty($value))
    {        
        array_push($errorList, "{$name} is required");
    }
}

function CheckEmail($email)
{
    global $errorList;
    if(!filter_var($email, FILTER_VALIDATE_EMAIL))
    {
        array_push($errorList, "E-mail is incorrect");
    }
}

function CheckRegexp($value, $name, $regexp)
{
    global $errorList;
    if(!filter_var(
        $value, 
        FILTER_VALIDATE_REGEXP,
        array(
             "options" => array("regexp"=>$regexp)
        )))
    {
        array_push($errorList, "{$name} is incorrect");
    }
}

CheckRequired($name, "Name");
CheckRegexp($name, "Name", "/^[A-Za-z ]+$/");
CheckRequired($email, "E-mail");
CheckEmail($email);
CheckRequired($birthday, "Birthday");

echo json_encode(
    array
    (        
        'errors' => $errorList
    )
)

?>