using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Priority_Queue_Using_Min_Heap_in_C_
{
    internal class Program
    {
        public class Node
        {
            public int Priority { get; set; }
            public string Text { get; set; }
            public Node (string text, int priority)
            {
                this.Priority = priority;
                this.Text = text;
            }
        }
        public class Priority_Queue
        {
            List<Node> Heap = new List<Node>();
            public string Peek()
            {
                if (Heap.Count == 0)
                    return "";
                return Heap[0].Text;
            }
            public void Enqueue(string text, int  priority)
            {
                Node temp = new Node(text, priority);
                Heap.Add(temp);

                HeapfiyUp(Heap.Count - 1);
            }


            public bool Empty()
            {
                return Heap.Count == 0;
            }
            public string Dequeue()
            {
                if(Heap.Count == 0)
                    return string.Empty;
                string text = Heap[0].Text;

                Heap[0] = Heap[Heap.Count-1];
                Heap.RemoveAt(Heap.Count-1);
                HeapfiyDown(0);
                return text;
            }
            // Helper Metheod
            private void HeapfiyUp(int index)
            {
                while (index > 0)
                {
                    int Parent = (index - 1) / 2;
                    if (Heap[index].Priority < Heap[Parent].Priority)
                    {
                        Node temp = Heap[index];
                        Heap[index] = Heap[Parent];
                        Heap[Parent] = temp;
                        index = Parent;
                    }
                    else
                        break;


                }
            }

            private void HeapfiyDown(int index)
            {
                int lastIndex = Heap.Count - 1;

                while (index <= lastIndex)
                {
                    int left = (index * 2) + 1;
                    int right = (index * 2) + 2;
                    int Smailest = index;

                    if (left <= lastIndex && Heap[Smailest].Priority > Heap[left].Priority)
                        Smailest = left;

                    if (right <= lastIndex && Heap[Smailest].Priority > Heap[right].Priority)
                        Smailest = right;

                    if(index != Smailest)
                    {
                        Node node = Heap[Smailest];
                        Heap[Smailest] = Heap[index];
                        Heap[index] = node;
                        index = Smailest;
                    }
                    else
                        break;
                }
            }
        }
        static void Main(string[] args)
        {
            Priority_Queue QPriority = new Priority_Queue();
            QPriority.Enqueue("Kirollos", 2);
            QPriority.Enqueue("Ereny", 1);
            QPriority.Enqueue("Test", 3);
            while (!QPriority.Empty())
            {
                Console.WriteLine(QPriority.Dequeue());
            }
        }
    }
}
