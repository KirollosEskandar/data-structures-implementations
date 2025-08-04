using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Min_Heap
{
    internal class Program
    {
        public class HeapMIn
        {
            private List<int> Heap = new List<int>();
            private void HeapifyUp(int index)
            {

                while (index > 0)
                {
                    int Parent = (index - 1) / 2;
                    if (Heap[index] < Heap[Parent])
                    {
                        int temp = Heap[index];
                        Heap[index] = Heap[Parent];
                        Heap[Parent] = temp;
                        index = Parent;

                    }
                    else
                    {
                        break;
                    }
                }
            }
            public int Peek()
            {
                if (Heap.Count > 0)
                {
                    return Heap[0];
                }
                return int.MinValue;
            }

            public void Insert(int value)
            {
                Heap.Add(value);
                HeapifyUp(Heap.Count - 1);

            }

            private void HeapifyDown(int index)
            {
                int lastindex = Heap.Count - 1;
                while (index < Heap.Count)
                {
                    int left = 2 * index + 1;
                    int Right = 2 * index + 2;
                    int SmailIndex = index;

                    if (left <= lastindex && Heap[left] < Heap[SmailIndex])
                        SmailIndex = left;
                    if (Right <= lastindex && Heap[Right] < Heap[SmailIndex])
                        SmailIndex = Right;


                    if (SmailIndex != index)
                    {
                        int temp = Heap[SmailIndex];
                        Heap[SmailIndex] = Heap[index];
                        Heap[index] = temp;

                        index = SmailIndex;
                    }
                    else
                        break;
                }
            }
            public int ExractMin()
            {
                int Value = Heap[0];

                Heap[0] = Heap[Heap.Count - 1];

                Heap.RemoveAt(Heap.Count - 1);
                HeapifyDown(0);

                return Value;
            }
            public void Display()
            {
                Console.WriteLine(string.Join(", ", Heap));
            }
        }
        static void Main(string[] args)
        {
            HeapMIn heapMIn = new HeapMIn();
            heapMIn.Insert(9);
            heapMIn.Insert(8);
            heapMIn.Insert(4);
            heapMIn.Insert(1);
            heapMIn.Insert(0);
            heapMIn.ExractMin();
            heapMIn.Display();
        }
    }
}
