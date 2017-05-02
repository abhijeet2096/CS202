#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"

class AdjacencyMatrix : public GraphAdjacencyBase {
	private:
	int **ary;
	int vertices1;
	public:
   AdjacencyMatrix(int vertices );

  ~AdjacencyMatrix();
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
  int outdegree(int i);
  void display();
}; 
  AdjacencyMatrix :: AdjacencyMatrix(int vertices ){
  			int i=0,j=0;
  			this->vertices1 = vertices;
            ary = new int*[vertices];       //Declaring a 2D matrix through double pointer
            for(i = 0; i < vertices; ++i)
                ary[i] = new int[vertices];
            for (i = 0; i < vertices; ++i)        //Assigning them default value
            {
              for (j = 0; j < vertices; ++j)
              {
                ary[i][j] = 0;
              }
              
            }
  }
  AdjacencyMatrix :: ~AdjacencyMatrix(){
			int i=0,vertices;
			vertices = this->vertices1;	  			//Free each sub-array
		    for(i = 0; i < vertices; ++i) {
		        delete[] ary[i];   
		    }
		    //Free the array of pointers
		    delete[] ary;
  }

	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
  bool AdjacencyMatrix :: edgeExits(int i, int j){
  	if(ary[i][j] == 1)
  		return true;
  	else
  		return false;

  }
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  int AdjacencyMatrix :: vertices(){
  	return this->vertices1;
  }
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  int AdjacencyMatrix :: edges(){
  	int count=0;
  	int i=0,j=0;
  	 
                
            for (i = 0; i < vertices1; ++i)       
            {
              for (j = 0; j < vertices1; ++j)
              {
              	if(ary[i][j] == 1)
                	count++;
              }
              
            }
        return count;

  }
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  void AdjacencyMatrix :: add(int i, int j){
  	ary[i][j] = 1;
  }
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  void AdjacencyMatrix :: remove(int i, int j){
  	ary[i][j] = 0;
  }
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  int AdjacencyMatrix :: degree(int i){
  		return indegree(i) + outdegree(i);
  }
  int AdjacencyMatrix :: outdegree(int i){
  		int count=0;
  		for (int j = 0; j < vertices1; ++j)
  		{
  			if(ary[i][j] == 1)
  				count++;
  		}
  		return count;
  }
  int AdjacencyMatrix :: indegree(int i){
  		int count=0;
  		for (int j = 0; j < vertices1; ++j)
  		{
  			if(ary[j][i] == 1)
  				count++;
  		}
  		return count;
  }
  void AdjacencyMatrix :: display(){
  	int i=0,j=0;
  	std::cout << "\n" ;
  	std::cout << "  ";
  	for (i = 0; i < vertices1; ++i)       
            {
            	std::cout << "_" << i;
            }
    std::cout << "\n" ;
  	
  	for (i = 0; i < vertices1; ++i)       
            {
            	std::cout << i << "|";
              for (j = 0; j < vertices1; ++j)
              {
               std::cout << " " << ary[i][j] ;
              }
            std::cout << "\n" ;  
            }
  }
#endif /* ifndef ADJACENCY_MATRIX */