document.addEventListener("DOMContentLoaded", function() {
    document.getElementById("submit").addEventListener("click", ValidateAJAX);

    function ValidateAJAX() 
    {   
        ajax = new XMLHttpRequest();

        var errors = document.getElementById("errors");    
        while(errors.firstChild)
        {
           errors.removeChild(errors.firstChild);
        }

        name = document.getElementById("Name").value;        
        email = document.getElementById("Email").value;
        birthday = document.getElementById("Birthday").value;
        desk = document.getElementById("Desk").value;

        requestData = "name=" + name + "&email=" + email + "&birthday=" + birthday + "&desk=" + desk;

        ajax.open("post", "../scripts/validate.php");
        ajax.setRequestHeader("Content-type", "application/x-www-form-urlencoded");    

        ajax.onload = () =>
        {
            console.log(ajax.responseText);        
            response = JSON.parse(ajax.responseText);
            response.errors.forEach(element => {
                var li = document.createElement("li");
                li.textContent = element;
                errors.appendChild(li);
            });
            /*if(response.errors.lenght = 0)
            {
                send
            }
            */
        }
        console.log(requestData);
        ajax.send(requestData);
    }
});