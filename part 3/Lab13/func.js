class Student
{
    constructor(name, surname, age, course)
    {
        var re = RegExp("^[A-Za-z]+$");
        if(re.test(surname) && re.test(name)
                && typeof(age) == "number"
                && typeof(course) == "number"
                && 0 < age
                && 150 > age
                && 0 < course
                && 6 >= course){
            this.name = name;
            this.surname = surname;
            this.age = age;
            this.course = course;
        }
        else
            throw -1;     
    }

    SetOlder(age)
    {
        if(typeof(age) == "number" && 0 < age && 150 > age){
            this.age = age;
        }        
    }

    ChangeSurname(surname)
    {
        var re = RegExp("^[A-Za-z]+$");
        if(typeof(surname) == "string" && re.test(surname))
            this.surname = surname;
    }

    MoveToSecondCourse()
    {
        if(this.course < 6)
            this.course++;
    }
}

function printReverse(arr)
{
    revArr = [];
    if(Array.isArray(arr))
    {
        for(i = arr.length -1; i >=0; i--){
            revArr = arr[i];
        }
    }
    return revArr;
}