using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Graph_Using_Adjacency_List__C
{
    internal class Program
    {
        public class Graph
        {
            public enum TypeGraph { Dircted, UnDircted };


            private Dictionary<string, List<Tuple<string, int>>> _AdjacencyList;
            private Dictionary<String, int> _VirtciesDic;
            private TypeGraph typeGraph;
            private int SizeOFVirtces;

            public Graph(List<string> Virtcie, TypeGraph typeGraph)
            {
                this.typeGraph = typeGraph;
                SizeOFVirtces = Virtcie.Count;
                _VirtciesDic = new Dictionary<string, int>();
                _AdjacencyList = new Dictionary<string, List<Tuple<string, int>>>();

                for (int i = 0; i < SizeOFVirtces; i++)
                {
                    _VirtciesDic[Virtcie[i]] = i;
                    _AdjacencyList[Virtcie[i]] = new List<Tuple<string, int>>();
                }
            }


            public void AddEdge(string Sourse, string Des, int Weght)
            {
                if (_VirtciesDic.ContainsKey(Sourse) && _VirtciesDic.ContainsKey(Des))
                {
                    _AdjacencyList[Sourse].Add(new Tuple<string, int>(Des, Weght));

                    if (typeGraph == TypeGraph.UnDircted)
                        _AdjacencyList[Des].Add(new Tuple<string, int>(Sourse, Weght));
                }
                else
                {
                    Console.WriteLine("Not Found {0} Or {1} ", Sourse, Des);
                }
            }

            public void RemoveEdge(string Sourse, string Des)
            {
                if (_VirtciesDic.ContainsKey(Sourse) && _VirtciesDic.ContainsKey(Des))
                {
                    _AdjacencyList[Sourse].RemoveAll(X => X.Item1 == Des);

                    if (typeGraph == TypeGraph.UnDircted)
                        _AdjacencyList[Des].RemoveAll(X => X.Item1 == Sourse);
                }
                else
                {
                    Console.WriteLine("Not Found {0} Or {1} ", Sourse, Des);
                }
            }

            public int GetInDegree(string Sourse)
            {
                int degree = 0;
                if (!_AdjacencyList.ContainsKey(Sourse))
                    return degree;

                foreach (var s in _AdjacencyList)
                {
                    foreach (var v in s.Value)
                    {
                        if (v.Item1 == Sourse) degree++;
                    }
                }

                return degree;
            }

            public int GetOutDegree(string Sourse)
            {
                return _AdjacencyList[Sourse].Count;
            }


            public void PrintGraph()
            {
                foreach (var v in _AdjacencyList)
                {
                    Console.Write(v.Key + "  ");
                    foreach (var vDes in v.Value)
                    {
                        Console.Write(vDes.Item1 + " " + vDes.Item2 + "  ");

                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
                Console.WriteLine();

            }

        }
        static void Main(string[] args)
        {
            List<string> L = new List<string> { "A", "B", "C" };

            Graph graph = new Graph(L, Graph.TypeGraph.UnDircted);
            graph.AddEdge("A", "B", 2);
            graph.AddEdge("A", "C", 5);
            graph.PrintGraph();
            graph.RemoveEdge("A", "B");
            graph.PrintGraph();
        }
    }
}
ٍ