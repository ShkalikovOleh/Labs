<?php 

class User
{
    protected $firstName;
    protected $lastName;
    protected $middleName;
    protected $birthday;

    public function __construct($firstName, $lastName, $middleName, $birthday) 
    {        
        echo $this->$firstName;
        $this->SetFirstName($firstName);
        $this->SetMiddleName($middleName);        
        $this->SetLastName($lastName);        
        $this->SetBirthday($birthday);
    }

    public function GetName()
    {                
        return $this->lastName." ".$this->firstName[0].".".$this->middleName[0];
    }

    public function GetBirthday()
    {
        return $this->birthday;
    }

    public function GetAge()
    {        
        $today = date("Y-m-d");
        $diff = date_diff(date_create($this->birthday), date_create($today));
        return $diff->format('%y');
    }

    public function SetFirstName($value)
    {
        if($this->CheckName($value))
        {            
            $this->firstName = $value;            
        }
        else
        {
            throw new Exception("Incorrect value", 1);            
        }
    }
    
    public function SetMiddleName($value)
    {
        if($this->CheckName($value))
        {
            $this->middleName = $value;
        }
        else
        {
            throw new Exception("Incorrect value", 1);            
        }
    }
    
    public function SetLastName($value)
    {
        if($this->CheckName($value))
        {
            $this->lastName = $value;
        }
        else
        {
            throw new Exception("Incorrect value", 1);            
        }
    }

    protected function SetBirthday($value)
    {
        if(strtotime($value))
        {
            $this->birthday = date('d.m.Y', strtotime($value));            
        }
        else
        {
            throw new Exception("Incorrect value", 1);            
        }        
    }

    protected function CheckName($value)
    {
        if(filter_var(
            $value,
            FILTER_VALIDATE_REGEXP,
            array(
                 "options" => array("regexp"=>"/^[A-Za-z]+$/")
            )))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


class Student extends User
{
    public function __construct($firstName, $lastName, $middleName, $birthday, $faculty, $cafedra, $cipher, $number)
    {
        parent::__construct($firstName, $lastName, $middleName, $birthday);
        $this->faculty = $faculty;
        $this->cafedra = $cafedra;
        $this->group = $group;
        $this->SetCipher($cipher);
        $this->SetNumber($number);
    }

    protected $faculty;
    protected $cafedra;
    protected $cipher;
    protected $number;


    public function GetFaculty()
    {
        return $this->faculty;
    }

    public function GetCafedra()
    {
        return $this->cafedra;
    }

    public function GetGroupName()
    {
        return $this->cipher."-".$this->number;
    }

    public function GetEnterYear()
    {        
        return "201".strval($this->number)[0];
    }

    public function GetSubGroup()
    {        
        return strval($this->number)[1];
    }

    public function SetCipher($value)
    {
        if(!filter_var(
            $value,
            FILTER_VALIDATE_REGEXP,
            array(
                 "options" => array("regexp"=>"/A-ZA-Z/")
            )))
        {
            $this->cipher = $value;
        }
        else
        {
            throw new Exception("Incorrect value", 1);            
        }
    }

    public function SetNumber($value)
    {
        if(!filter_var(
            $value,
            FILTER_VALIDATE_REGEXP,
            array(
                 "options" => array("regexp"=>"/0-90-9/")
            )))
        {
            $this->number = $value;
        }
        else
        {
            throw new Exception("Incorrect value", 1);            
        }
    }
}


$user = new User("Oleh", "Shkalikov", "Vladimirovich", "28.02.2001");
echo '<p>'.$user->GetName().'</p>';
echo '<p>'.$user->GetBirthday().'</p>';
echo '<p>'.$user->GetAge().'</p>';
$user->SetFirstName("Helo");
$user->SetLastName("Vokilakhs");
echo '<p>'. $user->GetName().'</p>';

$student = new Student("Oleh", "Shkalikov", "Vladimirovich", "28.02.2001", "IPT", "IS", "FI", 81);
echo '<p>'.$student->GetGroupName().'</p>';
echo '<p>'.$student->GetEnterYear().'</p>';
echo '<p>'.$student->GetFaculty().'</p>';
echo '<p>'.$student->GetCafedra().'</p>';

?>