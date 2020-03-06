using System;

public static class Fibonacci
{
    public static uint Calculate(uint number)
    {        
        if(0 <= number && number <= 1)
            return 1;
        return Calculate(number - 1) + Calculate(number - 2);
    }
}