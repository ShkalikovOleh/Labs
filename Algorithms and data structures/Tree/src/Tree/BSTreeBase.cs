using System;
using System.Collections.Generic;

namespace Tree
{
    public abstract class BSTreeBase<TKey, TValue> : IBSTree<TKey, TValue>
            where TKey : IComparable<TKey>
    {
        public BSTNode<TKey, TValue> Root { get; protected set; }

        public int Height
        {
            get
            {
                if(Root != null)
                    return HeightFromNode(Root);
                return 0;
            }
        }

        public abstract void Add(TKey key, TValue value);

        public abstract void Remove(TKey key);

        public BSTNode<TKey, TValue> Find(TKey key)
        {
            var current = Root;
            while (current != null)
            {
                if (current.Key.CompareTo(key) > 0)
                    current = current.Left;
                else if (current.Key.CompareTo(key) < 0)
                    current = current.Right;
                else
                    break;
            }
            return current;
        }

        public TValue Search(TKey key)
        {
            var node = Find(key);
            if (node != null)
                return node.Value;
            return default(TValue);
        }

        public bool Contains(TKey key)
        {
            var node = Find(key);
            if (node != null)
                return true;
            return false;
        }

        public bool Empty()
        {
            if (Root == null)
                return true;
            return false;
        }

        public BSTNode<TKey, TValue> Min()
        {
            return MinFromNode(Root);
        }

        public BSTNode<TKey, TValue> Max()
        {
            return MaxFromNode(Root);
        }

        protected int HeightFromNode(BSTNode<TKey, TValue> node)
        {
            Queue<BSTNode<TKey, TValue>> visited = new Queue<BSTNode<TKey, TValue>>();
            visited.Enqueue(node);

            int height = 0;
            while (visited.Count != 0)
            {
                height++;
                int countInLevel = visited.Count;
                for (int i = 0; i < countInLevel; i++)
                {
                    var temp = visited.Dequeue();
                    if (temp.Left != null)
                        visited.Enqueue(temp.Left);
                    if (temp.Right != null)
                        visited.Enqueue(temp.Right);
                }
            }
            if(height != 0)
                return height - 1;
            return 0;
        }

        protected BSTNode<TKey, TValue> MinFromNode(BSTNode<TKey, TValue> node)
        {
            if (node == null)
                throw new ArgumentNullException("node is null");

            var current = node;
            while (current.Left != null)
                current = current.Left;
            return current;
        }

        protected BSTNode<TKey, TValue> MaxFromNode(BSTNode<TKey, TValue> node)
        {
            if (node == null)
                throw new ArgumentNullException("node is null");

            var current = node;
            while (current.Right != null)
                current = current.Right;
            return current;
        }
    }
}