using System;
using System.Collections.Generic;

namespace Tree
{
    public class DuplicableSimpleBSTree<TKey, TValue> : SimpleBSTree<TKey, TValue>
        where TKey : IComparable<TKey>
    {
        private readonly IDictionary<TKey, int> counts = new Dictionary<TKey, int>();

        public DuplicableSimpleBSTree() { }

        public DuplicableSimpleBSTree(BSTNode<TKey, TValue> root) : base(root) { }

        public DuplicableSimpleBSTree(TKey rootKey, TValue rootValue) : base(rootKey, rootValue) { }

        public override void Add(TKey key, TValue value)
        {
            if (counts.ContainsKey(key))
            {
                counts[key]++;
            }
            else
            {
                base.Add(key, value);
                counts.Add(key, 1);
            }
        }

        public override void Remove(TKey key)
        {
            if (counts.ContainsKey(key))
            {
                base.Remove(key);
                counts.Remove(key);
            }
        }

        public void Remove(TKey key, int count)
        {
            if (counts.ContainsKey(key))
            {
                if (counts[key] > count)
                    counts[key] -= count;
                else
                {
                    base.Remove(key);
                    counts.Remove(key);
                }
            }
        }

        public IDictionary<TKey, int> GetKeyCounts()
        {
            return counts;
        }

        public int GetKeyCount(TKey key)
        {
            if (!counts.ContainsKey(key))
                throw new ArgumentException("Tree does not contain key");
            return counts[key];
        }
    }
}