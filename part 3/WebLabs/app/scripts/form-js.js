function ValidateForm()
{
    var name = document.getElementById('Name').value;
    var email = document.getElementById('Email').value;
    var birthday = document.getElementById('Birthday').value;
    var nameRe = new RegExp(/^[A-Za-z ]+$/);
    if(name && email && birthday && nameRe.test(name))
    {
        //send
        return true;
    }
    else
    {        
        alert("Form is incorrect");
        return false;   
    }
}