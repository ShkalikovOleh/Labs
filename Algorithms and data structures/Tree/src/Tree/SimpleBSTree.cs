using System;

namespace Tree
{
    public class SimpleBSTree<TKey, TValue> : BSTreeBase<TKey, TValue>
                where TKey : IComparable<TKey>
    {
        public SimpleBSTree() { }

        public SimpleBSTree(BSTNode<TKey, TValue> root)
        {
            this.Root = root;
        }

        public SimpleBSTree(TKey rootKey, TValue rootValue)
        {
            Root = new BSTNode<TKey, TValue>(rootKey, rootValue);
        }

        public override void Add(TKey key, TValue value)
        {
            if (key == null || value == null)
                throw new System.ArgumentNullException();

            var newNode = new BSTNode<TKey, TValue>(key, value);

            if (Root == null)
            {
                Root = newNode;
                return;
            }

            BSTNode<TKey, TValue> parent = null;
            BSTNode<TKey, TValue> current = Root;

            while (current != null)
            {
                parent = current;
                if (current.Key.CompareTo(key) > 0)
                    current = current.Left;
                else
                    current = current.Right;
            }

            if (parent.Key.CompareTo(key) > 0)
                parent.Left = newNode;
            else if (parent.Key.CompareTo(key) < 0)
                parent.Right = newNode;
            else
                throw new ArgumentException("Tree already contains key");

            newNode.Parent = parent;
        }

        public override void Remove(TKey key)
        {
            if (key == null)
                throw new ArgumentNullException("key is null");

            var current = Root;

            while (current != null)
            {
                if (current.Key.CompareTo(key) > 0)
                    current = current.Left;
                else if (current.Key.CompareTo(key) < 0)
                    current = current.Right;
                else
                {
                    if (current.Left != null && current.Right != null)
                    {
                        var min = MinFromNode(current.Right);

                        min.Left = current.Left;
                        if (current.Left != null)
                            current.Left.Parent = min;

                        if (min.Key.CompareTo(current.Right.Key) != 0)
                        {
                            min.Right = current.Right;
                            if (current.Right != null)
                                current.Right.Parent = min;
                        }

                        if (min.Parent.Left.Key.CompareTo(min.Key) == 0)
                            min.Parent.Left = null;
                        else
                            min.Parent.Right = null;

                        Swap(current, min);
                    }
                    else if (current.Right != null)
                        Swap(current, current.Right);
                    else if (current.Left != null)
                        Swap(current, current.Left);
                    else
                        Swap(current, null);
                    break;
                }
            }
        }

        protected void Swap(BSTNode<TKey, TValue> source, BSTNode<TKey, TValue> destination)
        {
            if (source.Key.CompareTo(Root.Key) == 0)
                Root = destination;

            if (destination != null)
                destination.Parent = source.Parent;

            if (source.Parent != null)
            {
                if (source.Parent.Left != null)
                {
                    if (source.Parent.Left.Key.CompareTo(source.Key) == 0)
                    {
                        source.Parent.Left = destination;
                        return;
                    }
                }
                source.Parent.Right = destination;
            }
        }
    }
}