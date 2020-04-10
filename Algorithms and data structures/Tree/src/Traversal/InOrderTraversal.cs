using System;
using System.Collections.Generic;

namespace Tree
{
    public class InOrderTraversal<TKey, TValue> : BaseTraversal<TKey, TValue>
                where TKey : IComparable<TKey>
    {
        private readonly Stack<BSTNode<TKey, TValue>> stash = new Stack<BSTNode<TKey, TValue>>();

        public InOrderTraversal(IBSTree<TKey, TValue> tree) : base(tree)
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
                Current = stash.Pop();

                if (Current.Right != null && stash.Count > 0 && Current.Right.Key.CompareTo(stash.Peek().Key) == 0)
                {                    
                    TreeToStash(stash.Pop());
                }                
                return true;
            }
            return false;
        }
    }
}