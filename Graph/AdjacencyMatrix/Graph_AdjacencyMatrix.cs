using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph_Using_Adjacency_Matrix
{
    internal class Program
    {
        public class Graph
        {
            private int SizeOfVercies;
            private Dictionary<string, int> DicVertices;
            private int[,] _Adjacency;
            public enum eTypeGraph { Directed, UnDirected };
            private eTypeGraph TypeGraph = eTypeGraph.UnDirected;

            public Graph(List<string> vertices, eTypeGraph TypeGraph)
            {
                SizeOfVercies = vertices.Count;
                this.TypeGraph = TypeGraph;
                _Adjacency = new int[SizeOfVercies, SizeOfVercies];
                DicVertices = new Dictionary<string, int>();
                for (int i = 0; i < SizeOfVercies; i++)
                {
                    DicVertices[vertices[i]] = i;
                }
            }

            public void AddEdge(string So, string De, int Weght)
            {
                if (DicVertices.ContainsKey(So) && DicVertices.ContainsKey(De))
                {
                    int S = DicVertices[So];
                    int D = DicVertices[De];

                    _Adjacency[S, D] = Weght;

                    if (TypeGraph == eTypeGraph.UnDirected)
                        _Adjacency[D, S] = Weght;
                }
                else
                {
                    Console.WriteLine("Not Found {0} Or {1} .", So, De);
                }
            }

            public bool RemoveEdge(string So, string De)
            {
                if (DicVertices.ContainsKey(So) && DicVertices.ContainsKey(De))
                {
                    int S = DicVertices[So];
                    int D = DicVertices[De];

                    _Adjacency[S, D] = 0;

                    if (TypeGraph == eTypeGraph.UnDirected)
                        _Adjacency[D, S] = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
            public void Display()
            {
                Console.WriteLine();
                Console.Write("   ");
                foreach (var s in DicVertices)
                {
                    Console.Write(s.Key + "  ");
                }
                Console.WriteLine();
                foreach (var s in DicVertices)
                {
                    Console.Write(s.Key + "  ");
                    for (int j = 0; j < SizeOfVercies; j++)
                    {
                        Console.Write(_Adjacency[s.Value, j] + "  ");
                    }
                    Console.WriteLine();
                }
            }
            public bool IsEdge(string So, string De)
            {
                if (DicVertices.ContainsKey(So) && DicVertices.ContainsKey(De))
                {
                    int S = DicVertices[So];
                    int D = DicVertices[De];


                    return _Adjacency[S, D] != 0;
                }
                else
                {
                    return false;
                }
            }

            public int GetInDegree(string So)
            {
                int Degree = 0;

                if (DicVertices.ContainsKey(So))
                {
                    int S = DicVertices[So];
                    for (int i = 0; i < SizeOfVercies; i++)
                    {
                        if (_Adjacency[i, S] != 0)
                            Degree++;
                    }
                }


                return Degree;
            }
            public int GetDeOutgree(string So)
            {
                int Degree = 0;

                if (DicVertices.ContainsKey(So))
                {
                    int S = DicVertices[So];
                    for (int i = 0; i < SizeOfVercies; i++)
                    {
                        if (_Adjacency[S, i] != 0)
                            Degree++;
                    }
                }


                return Degree;
            }

            public void BFS(string StartVirtces)
            {
                if (!DicVertices.ContainsKey(StartVirtces))
                    return;

                int StartInadex = DicVertices[StartVirtces];

                bool[] Visted = new bool[SizeOfVercies];
                Queue<int> queue = new Queue<int>();
                queue.Enqueue(StartInadex);
                Visted[StartInadex] = true;

                while (queue.Count > 0)
                {
                    int Current = queue.Dequeue();
                    Console.Write(Current + " ");

                    for (int i = 0; i < SizeOfVercies; i++)
                    {
                        if (_Adjacency[Current, i] > 0 && !Visted[i])
                        {
                            queue.Enqueue(i);
                            Visted[i] = true;
                        }
                    }
                }
            }

            public void bfs(string StartNode)
            {

                if (!DicVertices.ContainsKey(StartNode))
                    return;

                int IndexStart = DicVertices[StartNode];
                Queue<int> queue = new Queue<int>();
                queue.Enqueue(IndexStart);
                bool[] Visted = new bool[SizeOfVercies];
                Visted[IndexStart] = true;

                while (queue.Count > 0)
                {
                    int Curr = queue.Dequeue();

                    Console.Write(Curr + " ");

                    for (int i = 0; i < SizeOfVercies; i++)
                    {
                        if (_Adjacency[Curr, i] > 0 && !Visted[i])
                        {
                            queue.Enqueue(i);
                            Visted[i] = true;
                        }
                    }
                }



            }
            public void dfs(string StartNode)
            {
                if (!DicVertices.ContainsKey(StartNode))
                    return;

                Stack<int> stact = new Stack<int>();
                bool[] Visted = new bool[SizeOfVercies];
                int index = DicVertices[StartNode];
                stact.Push(index);
                Visted[index] = true;
                while (stact.Count > 0)
                {
                    int Curr = stact.Pop();
                    Console.WriteLine(Curr + " ");

                    for (int i = 0; i < SizeOfVercies; i++)
                    {
                        if (_Adjacency[Curr, i] > 0 && !Visted[i])
                        {
                            Visted[i] = true;
                            stact.Push(i);
                        }
                    }
                }

            }

        }
        static void Main(string[] args)
        {
            List<string> list = new List<string> { "A", "B", "C" };

            Graph graph1 = new Graph(list, Graph.eTypeGraph.UnDirected);
            graph1.AddEdge("A", "B", 5);
            graph1.AddEdge("A", "C", 5);

            graph1.Display();
            graph1.RemoveEdge("A", "B");
            graph1.Display();

            Console.Write("BFs");
            graph1.BFS("B");
        }
    }
}
