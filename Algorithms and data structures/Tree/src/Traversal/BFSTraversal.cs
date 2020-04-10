using System;
using System.Collections.Generic;

namespace Tree
{
    public class BFSTraversal<TKey, TValue> : BaseTraversal<TKey, TValue>
                    where TKey : IComparable<TKey>
    {
        private Queue<BSTNode<TKey, TValue>> queue = new Queue<BSTNode<TKey, TValue>>();

        public BFSTraversal(IBSTree<TKey, TValue> tree) : base(tree)
        {
            if (tree.Root != null)
                queue.Enqueue(tree.Root);
        }

        public override bool MoveNext()
        {
            if (queue.Count != 0)
            {
                Current = queue.Dequeue();
                if (Current.Left != null)
                    queue.Enqueue(Current.Left);
                if (Current.Right != null)
                    queue.Enqueue(Current.Right);
                return true;
            }
            return false;
        }
    }
}