using System;
using System.Collections.Generic;

public static partial class ShellSort
{
    public static IList<T> PartialInsertionSort<T>(this IList<T> collection, int step, IComparer<T> comparer)
    {
        if(step <= 0)
            throw new ArgumentOutOfRangeException();

        for(int s = 0; s < step; s++)
        {
            for(int i = s + step; i < collection.Count; i += step)
            {
                int j = i - step;                
                var current = collection[i];

                while(j >= 0 && comparer.Compare(current,collection[j]) != 1)
                {
                    collection[j + step] = collection[j];                                
                    j -= step;                    
                }

                if(j != i - step)
                    collection[j + step] = current;
            }            
        }        
        return collection;
    }

    public static IList<T> PartialInsertionSort<T>(this IList<T> collection, int step) where T : IComparable<T>
    {
        if(step <= 0)
            throw new ArgumentOutOfRangeException();

        for(int s = 0; s < step; s++)
        {
            for(int i = s + step; i < collection.Count; i += step)
            {
                int j = i - step;                
                var current = collection[i];

                while(j >= 0 && current.CompareTo(collection[j]) != 1)
                {
                    collection[j + step] = collection[j];                                
                    j -= step;                    
                }

                if(j != i - step)
                    collection[j + step] = current;
            }            
        }        
        return collection;
    }
}