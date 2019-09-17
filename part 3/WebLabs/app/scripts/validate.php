<?php 

$name = $_POST['name'];
$birthday = $_POST['birthday'];
$email = $_EMAIL['email'];
$desk = $_POST['desk'];
$errorList = [];

CheckRequired($name, 'Name', $errorList)

class ErrorMessage
{
    protected $elementID;
    protected $errorMessage;

    function __construct($elementID)
    {
        $this->$elementID = $elementID;
        $this->$errorMessage = "{$elementID} is incorrect"
    }

    function __construct($elementID, $errorMessage)
    {
        $this->$elementID = $elementID;
        $this->$errorMessage = $errorMessage;
    }
}


public function CheckRequired($value,  $id, array $errorList)
{
    if(empty($value))
    {
        $errorMessage = new ErrorMessage($id, "{$id} is required");
        array_push($errorList, $errorMessage);
    }
}

public function CheckEmail($email, $id, array $errorList)
{
    if(filter_var($email))
    {
        
    }
}

?>