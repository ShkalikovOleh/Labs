using System;
using System.Collections.Generic;

namespace Tree
{
    public class DFSTraversal<TKey, TValue> : BaseTraversal<TKey, TValue>
                    where TKey : IComparable<TKey>
    {
        private Stack<BSTNode<TKey, TValue>> stack = new Stack<BSTNode<TKey, TValue>>();

        public DFSTraversal(IBSTree<TKey, TValue> tree) : base(tree)
        {
            if (tree.Root != null)
                stack.Push(tree.Root);
        }

        public override bool MoveNext()
        {
            if (stack.Count != 0)
            {
                Current = stack.Pop();                
                if (Current.Right != null)
                    stack.Push(Current.Right);
                if (Current.Left != null)
                    stack.Push(Current.Left);
                return true;
            }
            return false;
        }
    }
}