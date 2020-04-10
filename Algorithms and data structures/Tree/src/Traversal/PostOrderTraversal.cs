using System;
using System.Collections.Generic;

namespace Tree
{
    public class PostOrderTraversal<TKey, TValue> : BaseTraversal<TKey, TValue>
                    where TKey : IComparable<TKey>
    {
        private readonly Stack<BSTNode<TKey, TValue>> stash = new Stack<BSTNode<TKey, TValue>>();

        public PostOrderTraversal(IBSTree<TKey, TValue> tree) : base(tree)
        {
            Reset();
        }

        public override void Reset()
        {            
            TreeToStash(tree.Root);
        }

        private void TreeToStash(BSTNode<TKey, TValue> from)
        {
            var temp = from;
            while (temp != null)
            {
                if (temp.Right != null)
                    stash.Push(temp.Right);
                stash.Push(temp);
                temp = temp.Left;
            }
        }

        public override bool MoveNext()
        {
            if (stash.Count != 0)
            {
                BSTNode<TKey, TValue> temp;
                temp = stash.Pop();

                if (temp.Right != null && stash.Count > 0 && temp.Right.Key.CompareTo(stash.Peek().Key) == 0)
                {
                    var right = stash.Pop();
                    stash.Push(temp);

                    TreeToStash(right);
                    temp = stash.Pop();
                }
                Current = temp;
                return true;
            }
            return false;
        }
    }
}