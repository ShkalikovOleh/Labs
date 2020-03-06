$(document).ready(function() {
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
            },
            Email:
            {
                required: true,
                email: true
            },
            Birthday:
            {
                required: true
            }
        },
        messages:
        {
            Name:
            {
                regex: "Name may contains only latin letter and spaces"
            }
        }
    });
});