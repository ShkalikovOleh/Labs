$(document).ready(function () 
{
    $("#submit").click(function ()
    {           
        var name = $("#Name").val();
        var email = $("#Email").val();
        var birthday = $("#Birthday").val();
        var desk = $("#Desk").val();
        var data = "name=" + name + "&email=" + email + "&birthday=" + birthday + "&desk=" + desk;
        
        console.log(data);
        
        $("#errors").empty();
        
        $.ajax({
            type: "POST",
            url: "http://localhost/scripts/validate.php",
            data: data,
            success: function (data, textStatus) 
            {
                console.log(data);        
                response = JSON.parse(data);
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
        }});
    });
})