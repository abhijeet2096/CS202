#include <iostream>
#include "DirectedGraph.hpp"
#include <stdlib.h>


int main()
{
	//DirectedGraph list(4 , 'l');
	char ch;
	int choice , V , i , j;
	std::cout << "\n********************************Menu For Directed Graph************************************\n";
	std::cout << "\nEnter mode m:-Matrix l:-Adjacency list : ";
	std::cin >> ch;
	std::cout << "\n*******************************************************************************************\n";
	std::cout << "\nEnter Number of vertices : ";
	std::cin >> V;
	DirectedGraph list(V,ch);

	while(1)
	{
	std::cout << "\n1.Add Edge\n2.Remove Edge\n3.Display\n4.Indegree\n5.Outdegree\n6.Edges\n7.DFS traversal(Only for AdjList)\n8.BFS traversal(Only for AdjList)\n9.EXIT\n";
	std::cin >> choice;
		switch(choice)	
				{
					case(1):std::cout << "\nEnter src and dest: ";
							std::cin >> i >> j;
							list.add(i,j);
							break;
					case(2):std::cout << "\nEnter src and dest to remove edge: ";
							std::cin >> i >> j;
							list.remove(i,j);
							break;
					case(3):list.display();
							break;
					case(4):std::cout << "\nEnter Vertex to find In degree: ";
							std::cin >> i;
							std::cout << "\nIn degree: " << list.indegree(i);
							break;
					case(5):std::cout << "\nEnter Vertex to find Out degree: ";
							std::cin >> i;
							std::cout << "\nOut degree: "  << list.outdegree(i) << std::endl;
							break;
					case(6):std::cout << "\nNumber of edges: " << list.edges() << std::endl;
							break;
					case(7)://list.dfs(1);
							break;
					case(8)://list.bfs(1);
							break;
					case(9):exit(0);
					default: std::cout << "\nEnter correct option\n";		

				}
	}
	std::cout << std::endl;	
	return 0;
}