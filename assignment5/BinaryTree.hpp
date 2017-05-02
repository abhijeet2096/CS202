//Code By :- Abhijeet Sharma
//B15102

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1
#define Default_key  596
#define Default_key_minimum -30
#define Default_value  796
#define Default_value_minimum  -796
#include <queue>

using namespace std;

template <class Key,class Value>
class BinaryNode
{
public:
	Key key;
	Value val;
	BinaryNode<Key,Value> * root,* left,* right,* parent;
  int color ;
    /*Default constructor. Should assign the default value to key and value
     */
	BinaryNode();
	/*This contructor should assign the key and val from the passed parameters
     */
	BinaryNode(Key key, Value value);
};

template<class Key,class Value>
class BinaryTree
{
private:
  queue <BinaryNode<Key,Value> * > A ;
 
  
	/* You can implement your own helper functions whenever required.
	 */
protected://why used protected here not public?


public:
    BinaryNode<Key,Value> * root=NULL;
    BinaryNode<Key,Value> * temp=NULL;
  /* Implement get function to retrieve the value corresponding to given key in binary tree.
   */
  Value get(const Key& key);
  /*Display Binary tree by level wise 
  */
  void display(BinaryNode<Key,Value> *);
  void display_fake();
  void find_minimum(BinaryNode<Key,Value> *,Key& key_received);
  void find_maximum(BinaryNode<Key,Value> *,Key& key_received);
  void find_successor(BinaryNode<Key,Value> *,Value& value_received,Value& value_received_old);
  void find_predecessor(BinaryNode<Key,Value> *,Value& value_received,Value& value_received_old);
  /* Implement get function to retrieve the value corresponding to given key in binary tree.
   Overloaded*/
  Value get(BinaryNode<Key,Value> *,const Key& key,Value& value_received);
  /* Resets a node ! copy end element into deleted node !
   Overloaded*/
  Value changeValue(BinaryNode<Key,Value> *temp1,const Key& key,Key& key_received,Value& value_received);
  /* finds last element !
  */
  void findLast(BinaryNode<Key,Value> * temp1, Key& key,Value& value);
  /* Implement remove function that can delete a node in binary tree with given key. 
   */
  virtual void remove(const Key& key) ;
  /* Implement has function which will return true if the given key is present in binary tree 
   * otherwise return false.  
   */
  virtual bool has(const Key& key) ;
  /* Implement has function which will return true if the given key is present in binary tree 
   * otherwise return false.OVERLOADED  
   */
  virtual bool has(BinaryNode<Key,Value> *,const Key& key,Value& value_received) ;	
  /* Implement put function such that newly inserted node keep the tree balanced. 
   */	
  virtual void put(const Key& key, const Value& value) ;

  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an in order traversal.
   */
  virtual void print_in_order();
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an in order traversal.
   */
  virtual void print_in_order(BinaryNode<Key,Value> *);
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an pre order traversal.
   */
  virtual void print_pre_order();
  
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an pre order traversal.
   OVERLOEDED
   */
  virtual void print_pre_order(BinaryNode<Key,Value> * );
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in a post order traversal.
  
   */
  virtual void print_post_order();
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in a post order traversal.
   OVERLOADED
   */
  virtual void print_post_order(BinaryNode<Key,Value> * );
  
  /*
   *This method returns the minimum element in the binary tree.
   */
  virtual Key minimum();
  /*
   * This method returns the maximum element in the binary tree.
   */
  virtual Key maximum();
  /*
   *This method returns the successor, i.e, the next larget element in the
   *binary tree, after Key.
   */
  virtual Key successor(const Key& key);
  /*
   * This method returns the predessor, ie, the next smallest element in the
   * binary tree, after Key.
   */
  virtual Key predecessor(const Key& key);

};
//Default constructor
template<class Key,class Value>  BinaryNode <Key,Value> :: BinaryNode(){
            this->key = Default_key;
            this->val = Default_value;
            this->left = NULL;
            this->right= NULL;
            this->parent= NULL;
            this->color=0;

}
//Overloaded constructor
template<class Key,class Value> BinaryNode <Key,Value> :: BinaryNode(Key key, Value value){
            this->key = key;
            this->val = value;
            this->left = NULL;
            this->right= NULL;
            this->parent= NULL;
             this->color=0;

}
template<class Key,class Value> Value BinaryTree <Key,Value> :: get(const Key& key){
			 Value key_value=Default_value; 
           get(root,key,key_value);
		  
		  	return key_value;

}
template<class Key,class Value> Value BinaryTree <Key,Value> :: get(BinaryNode<Key,Value> * temp1,const Key& key, Value& value_received){
            if(temp1 == NULL){
              return false;
            }
            else if(temp1->key == key){
             value_received=temp1->val;
              return true; 
            }
            this->has(temp1->left,key,value_received);
            this->has(temp1->right,key,value_received);
}
template<class Key,class Value> void BinaryTree <Key,Value> :: remove(const Key& key){
  Value value_received;
  Key key_received;
  findLast(root,key_received,value_received);
  changeValue(root,key,key_received,value_received);
}
template<class Key,class Value> bool BinaryTree <Key,Value> :: has(const Key& key){

 Value key_value=Default_value; 
  has(root,key,key_value);
  if(key_value!=Default_value)
  	return true;
  else
  	return false;
}
template<class Key,class Value> bool BinaryTree <Key,Value> :: has(BinaryNode<Key,Value> * temp1,const Key& key,Value& value_received){
            if(temp1 == NULL)
              return false;
            else if (temp1->key == key){
              value_received=temp1->val;
              return true;
            }
            this->has(temp1->left,key,value_received);
            this->has(temp1->right,key,value_received);
            
            
            
}
template<class Key,class Value> void BinaryTree <Key,Value> :: put(const Key& key, const Value& value){

            
            if(!root){
              root = new BinaryNode<Key,Value> (key,value);
              A.push(root);
            }
            else{
              if(!(A.front())->left){
              A.front()->left = new BinaryNode<Key,Value> (key,value);
              (A.front()->left)->parent = A.front();
              A.push(A.front()->left);
              }
              else if(!A.front()->right){
              A.front()->right = new BinaryNode<Key,Value> (key,value);
              (A.front()->right)->parent = A.front();
              A.push(A.front()->right);
              A.pop();
              }
              
            }
}
template<class Key,class Value> void BinaryTree <Key,Value> :: print_in_order(){
  print_in_order(root);
}
template<class Key,class Value> void BinaryTree <Key,Value> :: print_in_order(BinaryNode<Key,Value> * temp1){
  if(temp1 == NULL)
    return ;
  this->print_in_order(temp1->left);
  std::cout << "\nKey:" << temp1->key << endl;
  std::cout << "Value:" << temp1->val << "\n" <<endl;
  this->print_in_order(temp1->right);
  
}
template<class Key,class Value> void BinaryTree <Key,Value> :: print_pre_order(){
  print_pre_order(root);
}
template<class Key,class Value> void BinaryTree <Key,Value> :: print_pre_order(BinaryNode<Key,Value> * temp1){
  if(temp1== NULL)
    return ;
  std::cout << "\nKey:" << temp1->key << endl;
  std::cout << "Value:" << temp1->val << "\n" <<endl;
  this->print_pre_order(temp1->left);
  this->print_pre_order(temp1->right);
  
}
template<class Key,class Value> void BinaryTree <Key,Value> :: print_post_order(){
  print_post_order(root);
}
template<class Key,class Value> void BinaryTree <Key,Value> :: print_post_order(BinaryNode<Key,Value> * temp1){
  if(temp1== NULL)
    return ;
  this->print_post_order(temp1->left);
  this->print_post_order(temp1->right);
  std::cout << "\nKey:" << temp1->key << endl;
  std::cout << "Value:" << temp1->val << "\n" <<endl;
  
}

template<class Key,class Value> Value BinaryTree <Key,Value> ::changeValue(BinaryNode<Key,Value> * temp1,const Key& key,Key& key_received,Value& value_received){
	 if(temp1 == NULL)
              return false;
     else if (temp1->key == key){
              temp1->val = value_received;
              temp1->key = key_received;
              return true;
            }
	this->changeValue(temp1->left,key,key_received,value_received);
    this->changeValue(temp1->right,key,key_received,value_received);
}
 
template<class Key,class Value> void BinaryTree <Key,Value> :: findLast(BinaryNode<Key,Value> * root,Key& key,Value& value){
    // Base Case
    if (root == NULL)  
    	return;
 
    // Create an empty queue for level order tarversal
    queue <BinaryNode<Key,Value> *> q;
 	BinaryNode<Key,Value> *temp1;
    // Enqueue Root and initialize height
    q.push(root);
 
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            BinaryNode<Key,Value> *node = q.front();
            
            //copying last value and last key in key and value 
            temp1 = node;
            key = node->key;
            value = node->val;
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
        
    }
    if((temp1->parent)->right == temp1)
        	(temp1->parent)->right = NULL;
        else
        	(temp1->parent)->left = NULL;
    delete temp1;
}
template<class Key,class Value> void BinaryTree <Key,Value> :: display_fake(){
display(root);
	
}
template<class Key,class Value> void BinaryTree <Key,Value> :: display(BinaryNode<Key,Value> * root){
    // Base Case
    if (root == NULL)  
    	return;
 
    // Create an empty queue for level order tarversal
    queue <BinaryNode<Key,Value> *> q;
    // Enqueue Root and initialize height
    q.push(root);
 
    while (1)
    {
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
 
        // Dequeue all nodes of current level and Enqueue all
        // nodes of next level
        while (nodeCount > 0)
        {
            BinaryNode<Key,Value> *node = q.front();
            std::cout << " "<< node->key << "|" << node->val << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        std::cout << std::endl;
        
    }
}
template<class Key,class Value> Key BinaryTree <Key,Value> :: minimum(){
  Key key_received = Default_key ;
  find_minimum(root,key_received);
  return key_received;
}
template<class Key,class Value> void BinaryTree <Key,Value> :: find_minimum( BinaryNode<Key,Value> *temp1, Key& key_received){
  if(temp1== NULL)
    return ;
  if(temp1->key <= key_received )
   key_received = temp1->key; 
  this->find_minimum(temp1->left,key_received);
  this->find_minimum(temp1->right,key_received);
}
template<class Key,class Value> Key BinaryTree <Key,Value> :: maximum(){
  Key key_received = Default_key_minimum ;
  find_maximum(root,key_received);
  return key_received;
}
template<class Key,class Value> void BinaryTree <Key,Value> :: find_maximum( BinaryNode<Key,Value> *temp1, Key& key_received){
  if(temp1== NULL)
    return ;
  if(temp1->key >= key_received )
   key_received = temp1->key; 
  this->find_maximum(temp1->left,key_received);
  this->find_maximum(temp1->right,key_received);
}
template<class Key,class Value> Key BinaryTree <Key,Value> :: successor(const Key& key){
  Value value_received,value_received_old;
  value_received = get(key);
  value_received_old = maximum();
  find_successor(root,value_received,value_received_old);
  return value_received_old;
}
template<class Key,class Value> void BinaryTree <Key,Value> :: find_successor( BinaryNode<Key,Value> *temp1,Value& value_received,Value& value_received_old){
  if(temp1== NULL)
    return ;
  if(temp1->val > value_received && temp1->val <= value_received_old)
  	value_received_old=temp1->val;
  this->find_successor(temp1->left,value_received,value_received_old);
  this->find_successor(temp1->right,value_received,value_received_old);
}
template<class Key,class Value> Key BinaryTree <Key,Value> :: predecessor(const Key& key){
   Value value_received,value_received_old;
  value_received = get(key);
  value_received_old = minimum();
  find_predecessor(root,value_received,value_received_old);
  return value_received_old; 
}
template<class Key,class Value> void BinaryTree <Key,Value> :: find_predecessor( BinaryNode<Key,Value> *temp1,Value& value_received,Value& value_received_old){
   if(temp1== NULL)
    return ;
  if(temp1->val < value_received && temp1->val >= value_received_old)
  	value_received_old=temp1->val;

  this->find_predecessor(temp1->left,value_received,value_received_old);
  this->find_predecessor(temp1->right,value_received,value_received_old);
}
#endif /* ifndef BINARYTREE_HPP */
