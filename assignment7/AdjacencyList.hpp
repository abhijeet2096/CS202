#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include "GraphAdjacencyBase.hpp"
/*
	 * Adjacency List Node
	 */ 
	class AdjListNode
	{
	  public:
	    AdjListNode* next;
	    int value;
	    AdjListNode();
	    AdjListNode(int value);

	};
class AdjacencyList : public GraphAdjacencyBase {
  public:
  	AdjListNode **ary;
  	int vertices1;
  AdjacencyList(int vertices);
  ~AdjacencyList();

  /*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
   bool edgeExits(int i, int j);
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  int vertices();
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  int edges();
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  void add(int i, int j);
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  void remove(int i, int j);
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  int degree(int i);
  int indegree(int i);
  int outdegree(int j);
  void display();
};
	
	//Default constructor for Node
	 AdjListNode :: AdjListNode(){
	  this->value = 0;
	}
	//Overloaded Constructor for node
	 AdjListNode :: AdjListNode(int value){
	  this->value = value;
	  this->next = NULL;
	}	
	AdjacencyList :: AdjacencyList(int vertices){
	int i=0,j=0;
	this->vertices1 = vertices;
      ary  = new AdjListNode*[vertices];
    for(i = 0; i < vertices; ++i)
                ary[i] = NULL;	
	} 
	AdjacencyList :: ~AdjacencyList(){
	 int vertices = this->vertices1;
	 AdjListNode * temp,*temp1;
	 for (int i = 0; i < vertices; ++i)
	 {
	 	temp = ary[i];
	 	ary[i] = NULL;
	 	while(temp != NULL)
	 	{	temp1=temp;
	 		delete temp1;
	 		temp = temp->next;
	 	}
	 }
	 delete[] ary;
	}  
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
   bool AdjacencyList :: edgeExits(int i, int j){
   	AdjListNode *temp;
   	temp = ary[i];
   	while(temp!=NULL){
   		if(temp->value == j)
   			return true;
   		temp=temp->next;
   	}
   	return false;
   }
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  int AdjacencyList :: vertices(){
  	return this->vertices1;
  }
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  int AdjacencyList :: edges(){
  	int count=0;
  	AdjListNode * temp;
  	for (int i = 0; i < this->vertices1 ; ++i)
  	{
  		temp = ary[i];
  		while(temp){
  			count++;
  			temp=temp->next;
  		}
  	}
  	return count;
  }
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  void AdjacencyList :: add(int i, int j){
  	AdjListNode *temp,*temp1;
  	temp = ary[i];
  	ary[i] = new AdjListNode(j);
  	temp1 = ary[i];
  	temp1->next = temp;
  }
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  void AdjacencyList :: remove(int i, int j){
  	AdjListNode *temp,*temp1;
  	temp = ary[i];
  		while(temp){
  			if(ary[i]->value == j){
  				temp1 = ary[i];
  				ary[i] = ary[i]->next;
  				delete temp;
  				return;
  			}
  			temp1=temp;
  			temp=temp->next;
  			if(temp->value == j){
  				temp1->next = temp->next;
  				delete temp;
				return;
  			}
  			
  		}
  }
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  int AdjacencyList :: degree(int i){
  	return indegree(i)+outdegree(i);
  }

  int AdjacencyList :: indegree(int i){
  	AdjListNode *temp;
  	int count=0;
  	temp = ary[i];
  		while(temp){
  			count++;
  			temp=temp->next;
  		}
  	return count;
  }
  int AdjacencyList :: outdegree(int j){
  	int count=0;
  	AdjListNode *temp;
  	for (int i = 0; i < this->vertices1 ; ++i)
  	{	if(i != j){
	  		temp = ary[i];
	  		while(temp){
	  			if(temp->value == j)
	  			count++;
	  			temp=temp->next;
	  		}
  		}
  	}
  	return count;
  }
  void AdjacencyList :: display(){
  	int i;
  	AdjListNode *temp;
  
  	std::cout << "\n";
  	for ( i = 0; i < this->vertices1 ; ++i)
  	{	
	  		temp = ary[i];
	  		std::cout << i <<" :" ;
	  		while(temp){
	  			std::cout << " " << temp->value; 
	  			temp=temp->next;
	  		}
	  		std::cout << "\n";
  		
  	}
  	std::cout << "\n";
  }
#endif /* ifndef ADJACENCY_LIST */