using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binary_Tree___C
{
    internal class Program
    {
        public class Node
        {
            public int Value { set; get; }
            public Node Left { set; get; }
            public Node Right { set; get; }

            public Node(int Value)
            {
                this.Value = Value;
                Left = null;
                Right = null;
            }
        }

        public class BinarryTree
        {
            private Node Root;
            public BinarryTree(int Value)
            {
                Root = new Node(Value);
            }

            public void InsertLevelOrder(int Value)
            {
                if (Root == null)
                {
                    Root = new Node(Value);
                    return;
                }
                Queue<Node> queue = new Queue<Node>();
                queue.Enqueue(Root);

                while (queue.Count > 0)
                {
                    Node node = queue.Dequeue();
                    if (node.Left == null)
                    {
                        node.Left = new Node(Value);
                        return;
                    }
                    else
                        queue.Enqueue(node.Left);
                    if (node.Right == null)
                    {
                        node.Right = new Node(Value);
                        return;
                    }
                    else
                        queue.Enqueue(node.Right);
                }

            }

            private void pReverseInorderTraversal(Node roo)
            {
                if (roo == null)
                    return;
                pReverseInorderTraversal(roo.Right);
                Console.WriteLine(roo.Value);
                pReverseInorderTraversal(roo.Left);
            }

            private void pPrOrderTraversal(Node roo)
            {
                if (roo == null)
                    return;
                Console.WriteLine(roo.Value);
                pPrOrderTraversal(roo.Left);
                pPrOrderTraversal(roo.Right);
            }

            public void ReverseInorderTraversal()
            {
                pReverseInorderTraversal(Root);
            }


            public void PrOrderTraversal()
            {
                pPrOrderTraversal(Root);
            }


            public void PostOrderTraversal()
            {
                pPostOrderTraversal(Root);
            }

            private void pPostOrderTraversal(Node roo)
            {
                if (roo == null)
                    return;
                pPrOrderTraversal(roo.Left);
                pPrOrderTraversal(roo.Right);
                Console.WriteLine(roo.Value);
            }


            public void InOrderTraversal()
            {
                pInOrderTraversal(Root);
            }

            private void pInOrderTraversal(Node roo)
            {
                if (roo == null)
                    return;
                pPrOrderTraversal(roo.Left);
                Console.WriteLine(roo.Value);
                pPrOrderTraversal(roo.Right);
            }
            public void PrintLevelOrder()
            {
                if (Root == null)
                    return;

                Queue<Node> queue = new Queue<Node>();
                queue.Enqueue(Root);
                while (queue.Count > 0)
                {
                    Node node = queue.Dequeue();
                    Console.WriteLine(node.Value);
                    if (node.Left != null)
                        queue.Enqueue(node.Left);
                    if (node.Right != null)
                        queue.Enqueue(node.Right);
                }

            }
        }
        static void Main(string[] args)
        {
            BinarryTree binarryTree = new BinarryTree(5);
            binarryTree.InsertLevelOrder(3);
            binarryTree.InsertLevelOrder(2);
            binarryTree.InsertLevelOrder(1);
            binarryTree.InsertLevelOrder(4);
            binarryTree.InsertLevelOrder(7);
            binarryTree.InsertLevelOrder(8);

            binarryTree.PrintLevelOrder();
            //Binary Tree Implementation #C :: Preorder Traversal (Right → Root → Left)
        }
    }
}
