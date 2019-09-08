var modal;
var lastInput;

document.addEventListener("DOMContentLoaded", function() {
    
    modal = document.getElementsByClassName('modal')[0];
    modal.style.visibility = 'hidden';
    lastInput = Date.now();
    setInterval(ShowPopup, 60000)

    $("form").validate();
    $.validator.addMethod(
        "regex",
        function(value, element, regexp) {
            var re = new RegExp(regexp);
            return re.test(value);
        },
        alert("Name can not contains non latin letter.")
    );
    $("#Name").rules("add", { regex: "^[A-Za-z]+$" })
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
        modal.style.visibility = 'visible';
}

function ClosePopup()
{
    modal.style.visibility = 'hidden';
    lastInput = Date.now();
}

function ValidateForm()
{
    var name = document.forms[0]['Name'].value;
    var re = new RegExp(/^[A-Za-z]+$/);
    if(re.test(name))
    {
        return true;
    }
    else
    {
        alert("Name can not contains non latin letter");
        return false;
    }
}