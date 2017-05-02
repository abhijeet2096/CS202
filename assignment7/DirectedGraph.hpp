#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : public AbstractGraph {
 private:
  char mode;
  AdjacencyList *list;
  AdjacencyMatrix *matrix;
 public:
  /*
   * Constructor: DirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  DirectedGraph(int vertices, char rep);
  /*
   * Function: indegree
   * Returns the indegree of a vertex
   */
  int indegree(int i);
  /*
   * Function: outdegree
   * Returns the outdegree of a vertex.
   */
  int outdegree(int j);
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
  /* 
  display utility function
  */
  void display();
};
  DirectedGraph :: DirectedGraph(int vertices, char rep){
    this->mode = rep;
    if(rep == 'l'){
      list = new AdjacencyList(vertices);
    }
    else if(rep == 'm'){
      matrix = new AdjacencyMatrix(vertices);
    }
    else{
      /*To Do*/
      std::cout << "Wrong Mode Parameters passed !" << std::endl;
    }
  }
  /*
   * Function: indegree
   * Returns the indegree of a vertex
   */
  int DirectedGraph :: indegree(int i){
    if(mode == 'l'){
      return list->indegree(i);
    }
    else{
      return matrix->indegree(i);
    }
  }
  /*
   * Function: outdegree
   * Returns the outdegree of a vertex.
   */
  int DirectedGraph :: outdegree(int j){
    if(mode == 'l'){
      return list->outdegree(j);
    }
    else{
      return matrix->outdegree(j);
    }
  }
  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  bool DirectedGraph :: edgeExits(int i, int j){
    if(mode == 'l'){
      return list->edgeExits(i,j);
    }
    else{
      return matrix->edgeExits(i,j);
    }
  }  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  int DirectedGraph ::  edges(){
    if(mode == 'l'){
      return list->edges();
    }
    else{
      return matrix->edges();
    }
  }
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  int DirectedGraph :: vertices(){
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
  void DirectedGraph :: add(int i, int j){
    if(mode == 'l'){
      list->add(i,j);
      }
    else{
      matrix->add(i,j);
      }
  }
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  void DirectedGraph :: remove(int i, int j){
       if(mode == 'l'){
      list->remove(i,j);
      }
    else{
      matrix->remove(i,j);
      }
  }
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void DirectedGraph :: dfs(void (*work)(int&)){

  }
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  void DirectedGraph :: bfs(void (*work)(int&)){

  }
  void DirectedGraph :: display(){
    
    if(this->mode == 'l'){
      list->display();
    }
    else{
      matrix->display();
    }
  }
#endif /* ifndef DIRECTED_GRAPH */