#include <iostream>
#include "AdjacencyList.hpp"

using namespace std;

int main()
{
	AdjacencyList list;
	list.create(5);
	list.add(1,2);
	list.add(2,3);
	list.add(1,4);
	list.add(1,3);
	list.add(3,2);
	list.add(1,5);
	list.display();
	cout<<"\n\nAfter remove\n\n";
	int edges = list.edges();
	cout<<"\nNumber of Edges : "<<edges<<endl;
	list.remove(1,2);
	list.display();
	edges = list.edges();
	cout<<"\nNumber of Edges : "<<edges<<endl;
	/*int in = list.indegree(2);
	int out = list.outdegree(1);
	cout<<"\n"<<in<<endl;
*/
	return 0;

}
