using System;
using System.Collections.Generic;

public static class InversionExtension
{
    public static int CountInversion<T>(this IList<T> collection) where T : IComparable<T>
    {
        int inversion = 0;
        for(int i = 0; i < collection.Count - 1; i++)
        {
            for(int j = i + 1; j < collection.Count; j++)
            {
                if(collection[i].CompareTo(collection[j]) > 0)
                    inversion++;
            }
        }
        return inversion;
    }

    public static int CountInversion<T>(this IList<T> collection, IComparer<T> comparer)
    {
        int inversion = 0;
        for(int i = 0; i < collection.Count - 1; i++)
        {
            for(int j = i + 1; j < collection.Count; j++)
            {
                if(comparer.Compare(collection[i], collection[j]) > 0)
                    inversion++;
            }
        }
        return inversion;
    }
}