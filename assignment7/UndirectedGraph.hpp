#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "AbstractGraph.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
class UndirectedGraph : public AbstractGraph {
 private:
  char mode;
  AdjacencyList *list;
  AdjacencyMatrix *matrix;

 public:
  

  /*
   * Constructor: UndirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  UndirectedGraph(int vertices, char rep);
  /*
   * Returns the degree of the vertex.
   */
  int degree(int i);
  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  bool edgeExits(int i, int j);
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  int edges();
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  int vertices();
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
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void dfs(void (*work)(int&));
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void bfs(void (*work)(int&));
  void display();
};
  UndirectedGraph :: UndirectedGraph(int vertices, char rep){
    this->mode = rep;
    if(mode == 'l'){
      list = new AdjacencyList(vertices);
    }
    else if(mode == 'm'){
      matrix = new AdjacencyMatrix(vertices);
    }
    else{
      /*To Do*/
      std::cout << "Wrong Mode Parameters passed !" << std::endl;
    }
  }
  /*
   * Returns the degree of the vertex.
   */
  int UndirectedGraph :: degree(int i){
    if(mode == 'l'){
      return list->degree(i);
    }
    else{
      return matrix->degree(i);
    }
  }
  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  bool UndirectedGraph :: edgeExits(int i, int j){
    if(mode == 'l'){
      return list->edgeExits(i,j);
    }
    else{
      return matrix->edgeExits(i,j);
    }
  }
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  int UndirectedGraph :: edges(){
    if(mode == 'l'){
      return (list->edges())/2;
    }
    else{
      return (matrix->edges())/2;
    }
  }
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  int UndirectedGraph :: vertices(){
    if(mode == 'l'){
      return list->vertices();
    }
    else{
      return matrix->vertices();
    }
  }
  /*
   * Function add:
   * Adds an edge between vertices i and j
   */
  void UndirectedGraph :: add(int i, int j){
    if(mode == 'l'){
      list->add(i,j);
      list->add(j,i);
    }
    else{
      matrix->add(i,j);
      matrix->add(j,i);
    }
  }
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  void UndirectedGraph :: remove(int i, int j){
    if(mode == 'l'){
      list->remove(i,j);
      list->remove(j,i);
    }
    else{
      matrix->remove(i,j);
      matrix->remove(j,i);
    }
  }
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void UndirectedGraph :: dfs(void (*work)(int&)){

  }
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void UndirectedGraph :: bfs(void (*work)(int&)){

  }
  void UndirectedGraph :: display(){
    if(mode == 'l')
      list->display();
    else
      matrix->display();
  }
#endif /* ifndef UNDIRECTED_GRAPH */