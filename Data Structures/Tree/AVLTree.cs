using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace AVL__C
{
    internal class Program
    {
        public  class Node
        {
            public int value { get; set; }
            public int Hieght { get; set; }
            public Node Left { get; set; }
            public Node Right { get; set; }
            public Node(int val)
            {
                Left = Right = null;
                Hieght = 1;
                value = val;
            }
        }

        public class TreeAVl
        {
            Node Root;
            private Node MaxNode(Node root)
            {
                while(root.Right != null)
                    root = root.Right;
                return root;
            }
            private Node Remove(Node root, int Value)
            {
                if(Value > root.value)
                    root.Right = Remove(root.Right, Value);
                if (Value < root.value)
                    root.Left = Remove(root.Left, Value);
                else
                {
                    if (root.Left == null)
                        return root.Right;
                    else if (root.Right == null)
                        return root.Left;
                    else
                    {
                        Node Max = MaxNode(root.Left);
                        root.value = Max.value;
                        root.Left = Remove(root.Left, Max.value);

                    }

                }

                return Balance(root);
            }
            public void Remove(int Value)
            {
                Root =Remove(Root, Value);
            }
            public TreeAVl()
            {
                Root = null;
            }

            private int GetHeight(Node node)
            {
                return node == null ? 0 : node.Hieght;
            }
            private int GetBalanceFactor(Node node)
            {
                return node != null ? GetHeight(node.Left) - GetHeight(node.Right): 0;
            }

            private void UpdateHeight(Node node)
            {
                node.Hieght = Math.Max(GetHeight(node.Left), GetHeight(node.Right)) + 1;
            }
            private Node Insert(Node root , int val)
            {
                if (root == null) return new Node(val);


                if (val > root.value)
                    root.Right = Insert(root.Right, val);
                else if (val < root.value)
                    root.Left = Insert(root.Left, val);
                else
                    return root;
                UpdateHeight(root);
                return Balance(root);
            }

            public void Insert(int val)
            {
                Root = Insert(Root, val);
            }

            private Node Balance(Node node)
            {
                int FactorBalanced = GetBalanceFactor(node);

                if (FactorBalanced > 1)
                {
                    if(GetBalanceFactor(node.Left) < 1)
                        node.Left = LeftRotate(node.Left);
                    return RightRotate(node);
                }
                if(FactorBalanced < -1)
                {
                    if (GetBalanceFactor(node.Right) > 1)
                        node.Right = RightRotate(node.Right);
                    return LeftRotate(node);
                }

                return node;
            }

            private Node LeftRotate(Node root)
            {
                Node NewRoot = root.Right;
                Node ChildNode = NewRoot.Left;

                root.Right = ChildNode;
                NewRoot.Left = root;
                UpdateHeight(root);
                UpdateHeight(NewRoot);
                return NewRoot;
            }
            private Node RightRotate(Node root)
            {
                Node NewRoot = root.Left;
                Node ChildNew = NewRoot.Right;

                root.Left = ChildNew;
                NewRoot.Right = root;
                UpdateHeight(root);
                UpdateHeight(NewRoot);
                return NewRoot;
            }

            private void InOrder(Node root)
            {
                if(root == null) return;
                InOrder(root.Left);
                Console.WriteLine(root.value + "  ");
                InOrder(root.Right);
            }

            public void Print()
            {
                InOrder(Root);
            }
        }
        static void Main(string[] args)
        {
            TreeAVl treeAVl = new TreeAVl();
            treeAVl.Insert(1);
            treeAVl.Insert(3);
            treeAVl.Insert(5);
            treeAVl.Insert(66);
            treeAVl.Print();
        }
    }
}
