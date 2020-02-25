using System;
using System.Collections.Generic;

public static partial class ShellSort
{
    public static IList<T> PartialInsertionSort<T>(this IList<T> collection, int[] indexesForSort, IComparer<T> comparer)
    {
        if(indexesForSort.Length < 2)
            return collection;

        for(int i = 1; i < indexesForSort.Length; i++)
        {
            int j = i - 1;
            var index = indexesForSort[j];
            var current = collection[indexesForSort[i]];

            while(j >= 0 && comparer.Compare(current,collection[index]) != 1)
            {
                collection[indexesForSort[j+1]] = collection[index];                                
                j--;
                if(j >= 0)
                    index = indexesForSort[j];
            }

            if(j != i - 1)
                collection[indexesForSort[j + 1]] = current;
        }        
        return collection;
    }

    public static IList<T> PartialInsertionSort<T>(this IList<T> collection, int[] indexesForSort) where T : IComparable<T>
    {
        if(indexesForSort.Length < 2)
            return collection;

        for(int i = 1; i < indexesForSort.Length; i++)
        {
            int j = i - 1;
            var index = indexesForSort[j];
            var current = collection[indexesForSort[i]];

            while(j >= 0 && current.CompareTo(collection[index]) != 1)
            {
                collection[indexesForSort[j+1]] = collection[index];                                
                j--;
                if(j >= 0)
                    index = indexesForSort[j];
            }
            
            if(j != i - 1)
                collection[indexesForSort[j + 1]] = current;
        }        
        return collection;
    }
}