using System;

public static class GCD
{
    public static int Calculate(int a, int b)
    {
        if(a == 0 && b == 0)
            throw new ArgumentOutOfRangeException();
        if(a == 0)
            return b;
        if(b == 0)
            return a;        
        var result = a > b ? Euclid(a,b) : Euclid(b,a);
        return result;
    }

    private static int Euclid(int max, int min)
    {
        var remainder = max % min;
        var result = remainder != 0 ? Euclid(min, remainder) : min;        
        return result > 0 ? result : Math.Abs(result);
    }
}