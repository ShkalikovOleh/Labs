using System;
using System.Collections.Generic;

public static partial class SortExtensions
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

                while(j >= 0 && comparer.Compare(current,collection[j]) < 0)
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

                while(j >= 0 && current.CompareTo(collection[j]) < 0)
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

    public static IList<T> InsertionSort<T>(this IList<T> collection, IComparer<T> comparer)
    {
        return collection.PartialInsertionSort(1, comparer);
    }

    public static IList<T> InsertionSort<T>(this IList<T> collection) where T : IComparable<T>
    {
        return collection.PartialInsertionSort(1);
    }
}