var modal;
var lastInput;

document.addEventListener("DOMContentLoaded", function() {
    
    $(".modal").hide();    
    lastInput = Date.now();
    setInterval(ShowPopup, 60000);
    
    $.validator.addMethod(
        "regex",
        function(value, element, regexp) {
            return this.optional(element) || regexp.test(value);
        },
        "Incorrect pattern"
    );    
    $("form").validate(
    {
        rules:
        {
            Name:
            {
                required: true,
                regex: /^[A-Za-z\s]+$/
            }
        }            
    });
});

function SubscribeOnInputs()
{
    var inputs, index;
    
    inputs = document.getElementsByTagName('input');
    for (index = 0; index < inputs.length; ++index) {
        inputs[index].oninput = function()
        {
            lastInput = Date.now();
        }
    }
}

function ShowPopup()
{
    var delta = (Date.now() - lastInput) * 1000 * 60;
    if(delta > 1)
        $('.modal').show();
}

function ClosePopup()
{
    $(".modal").hide();
    lastInput = Date.now();
}

function ValidateForm()
{
    var name = document.getElementById('Name').value;
    var re = new RegExp(/^[A-Za-z]+$/);
    if(re.test(name))
    {
        return true;
    }
    else
    {        
        return false;
    }
}