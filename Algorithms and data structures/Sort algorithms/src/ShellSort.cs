using System;
using System.Collections.Generic;

public static partial class SortExtensions
{
    public static IList<T> ShellSort<T>(this IList<T> collection, IComparer<T> comparer, IStepSequenceGenerator sequenceGenerator)
    {
        var steps = sequenceGenerator.Generate(collection.Count);
        foreach (var step in steps)
        {
            collection.PartialInsertionSort(step, comparer);
        }
        return collection;
    }

    public static IList<T> ShellSort<T>(this IList<T> collection, IStepSequenceGenerator sequenceGenerator) where T : IComparable<T>
    {
        var steps = sequenceGenerator.Generate(collection.Count);
        foreach (var step in steps)
        {
            collection.PartialInsertionSort(step);
        }
        return collection;
    }
}