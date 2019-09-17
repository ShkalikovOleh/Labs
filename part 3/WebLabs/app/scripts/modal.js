var modal;
var lastInput;

document.addEventListener("DOMContentLoaded", function() 
{    
    $(".modal").hide();    
    lastInput = Date.now();
    SubscribeOnInputs();
    setInterval(ShowPopup, 60000);
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