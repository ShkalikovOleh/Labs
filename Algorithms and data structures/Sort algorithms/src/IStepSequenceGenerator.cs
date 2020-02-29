using System;
using System.Collections.Generic;

public interface IStepSequenceGenerator
{
    IEnumerable<int> Generate(int count);
}

public class ShellSequence : IStepSequenceGenerator
{
    public IEnumerable<int> Generate(int count)
    {
        var max = Math.Floor(Math.Log(count, 2));
        for(int i = 1; i <= max; i++)
            yield return (int)(Math.Floor(count / Math.Pow(2,i)));
    }
}

public class HibbardSequence : IStepSequenceGenerator
{
    public IEnumerable<int> Generate(int count)
    {
        var max = (int)Math.Floor(Math.Log(count + 1, 2));
        for(int i = max; i > 0; i--)
            yield return (int)(Math.Pow(2, i) - 1);
    }
}

public class KnuthSequence : IStepSequenceGenerator
{
    public IEnumerable<int> Generate(int count)
    {
        int K = (int)Math.Floor(Math.Log(count, 2)) - 1; 
        
        var result = new List<int>{ 1 };
        for(int i = 1; i < K; i++)
        {
            var d = result[result.Count - 1] * 2 + 1;
            result.Add(d);
        }
        
        result.Reverse();
        return result;
    }
}