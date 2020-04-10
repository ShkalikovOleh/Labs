using System;

namespace Tree
{
    public interface IBSTree<TKey, TValue> where TKey : IComparable<TKey>
    {
        BSTNode<TKey, TValue> Root { get; }

        bool Empty();

        bool Contains(TKey key);

        void Add(TKey key, TValue value);

        void Remove(TKey key);

        TValue Search(TKey key);

        int Height { get; }

        BSTNode<TKey, TValue> Min();

        BSTNode<TKey, TValue> Max();

        BSTNode<TKey, TValue> Find(TKey key);
    }
}