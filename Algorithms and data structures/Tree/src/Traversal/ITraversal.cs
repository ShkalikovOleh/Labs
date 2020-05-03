using System;
using System.Collections;
using System.Collections.Generic;

namespace Tree
{
    public interface ITraversal<TKey, TValue> : 
                IEnumerable<BSTNode<TKey, TValue>>, 
                IEnumerator<BSTNode<TKey, TValue>>
                    where TKey : IComparable<TKey>
    {
        IBSTree<TKey, TValue> tree { get; }
    }

    public abstract class BaseTraversal<TKey, TValue> : ITraversal<TKey, TValue>
                    where TKey : IComparable<TKey>
    {        
        public BaseTraversal(IBSTree<TKey, TValue> tree)
        {
            if(tree == null)
                throw new ArgumentNullException("Tree is null");
            this.tree = tree;
        }

        public IBSTree<TKey, TValue> tree { get; protected set; }    

        public BSTNode<TKey, TValue> Current { get; protected set; }

        object IEnumerator.Current => Current;

        public void Dispose() { }

        public virtual void Reset()
        {
            Current = tree.Root;
        }

        public IEnumerator<BSTNode<TKey, TValue>> GetEnumerator()
        {
            return this;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {            
            return GetEnumerator();
        }

        public abstract bool MoveNext();        
    }
}