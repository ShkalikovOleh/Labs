using System;
using System.Collections.Generic;

public static partial class SortExtensions
{
    public static IList<T> InsertionSort<T>(this IList<T> collection, IComparer<T> comparer)
    {
        for(int i = 1; i < collection.Count; i++)
        {
            int j = i - 1;
            var current = collection[i];
            
            while(j >= 0 && comparer.Compare(current, collection[j]) != 1)
            {
                collection[j+1] = collection[j];
                j--;
            }

            if(j != i - 1)
                collection[j + 1] = current;
        }
        return collection;
    }

    public static IList<T> InsertionSort<T>(this IList<T> collection) where T : IComparable<T>
    {
        for(int i = 1; i < collection.Count; i++)
        {
            int j = i - 1;
            var current = collection[i];

            while(j >= 0 && current.CompareTo(collection[j]) != 1)
            {
                collection[j+1] = collection[j];                                
                j--;
            }

            if(j != i - 1)
                collection[j + 1] = current;
        }        
        return collection;
    }
}