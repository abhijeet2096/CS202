#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "BinaryTree.hpp"
template <class Key,class Value>
class BSTree : public BinaryTree<Key,Value> {

/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
 public:
  int _size;
  int height(BinaryNode<Key, Value>* rt);
  BinaryNode<Key, Value>* find_minimum(BinaryNode<Key,Value> *temp1);
  BinaryNode<Key, Value>* find_maximum(BinaryNode<Key,Value> *temp1);
  /*
   * This method returns the current height of the binary search tree.
   */

  virtual int getHeight(BinaryNode<Key,Value> *temp1);

  int getHeight();
  /* Implement get function to retrieve the value corresponding to given key in binary search tree.
   */
  Value get(const Key& key);
    /* Implement get function to retrieve the value corresponding to given key in binary tree.
   Overloaded*/
  BinaryNode<Key,Value> * get(BinaryNode<Key,Value> *,const Key& key);
  /* Implement remove function that can delete a node in binary tree with given key. 
   */
  virtual void remove(const Key& key) ;
  /*Inserts node at correct position !
  */
  void put(const Key& key, const Value& value) ;
  /*Inserts node at correct position !
  OVERLOADED !
  */
  BinaryNode<Key,Value> * put(BinaryNode<Key,Value> *temp1,const Key& key, const Value& value) ;
  /*
   * This method returns the total number of elements in the binary search tree.
   */
  bool has(const Key& key) ;
  
  /* Implement put function such that newly inserted node keep the tree balanced. 
   */
  virtual int size();
  /*
   * This method prints the key value pairs of the binary search tree, sorted by
   * their keys.
   */
  virtual void print();
  /*
   *This method returns the minimum element in the binary tree.
   */
   Key minimum();
  /*
   * This method returns the maximum element in the binary tree.
   */
  Key maximum();
  /*
   *This method returns the successor, i.e, the next larget element in the
   *binary tree, after Key.
   */
   Key successor(const Key& key);
  /*
   * This method returns the predessor, ie, the next smallest element in the
   * binary tree, after Key.
   */
   Key predecessor(const Key& key);
};
template<class Key,class Value>  void BSTree <Key,Value>::put(const Key& key,const Value& value){
  //this->root= new BinaryNode<Key,Value> (1,1);
  //(this->root)->val=5;
  //(this->root)->left=new BinaryNode<Key,Value> (2,2);
  //(this->root)->right=new BinaryNode<Key,Value> (3,3);
  //((this->root)->left)->val=1;
  //((this->root)->left)->val=6
  //  ;
  this->root=put(this->root,key,value);
  _size++;
}
template<class Key,class Value> BinaryNode<Key,Value>*   BSTree <Key,Value>::put(BinaryNode<Key,Value> *node,const Key& key,const Value& value){
   /* If the tree is empty, return a new node */
    if (node == NULL){ 
      return new BinaryNode<Key,Value> (key,value);
    }
    if(key == node->key){
      node->val = value;
      return node;
    }
    /* Otherwise, recur down the tree */
    else if (key < node->key){
        node->left  = put(node->left, key,value);
        (node->left)->parent=node;
     }
    else {
        node->right = put(node->right, key,value);
        (node->right)->parent=node;
     }   
    return node;
    /* return the (unchanged) node pointer */
    
}
template<class Key,class Value>  int BSTree <Key,Value>::getHeight(){
  getHeight(this->root);
}
template<class Key,class Value>  int BSTree <Key,Value>::getHeight(BinaryNode<Key,Value> *temp1){
  if(temp1==NULL){
    return 0;
  } 
  else{
    int lheight = getHeight(temp1->left);
    int rheight = getHeight(temp1->right);
    if(lheight>rheight) 
      return lheight+1;
    else
      return rheight+1;
  }
}
template<class Key,class Value>  bool BSTree <Key,Value>::has(const Key& key){
BinaryNode<Key,Value> *temp1;
temp1 = get(this->root,key);
if(temp1!=NULL)
  return true;
else
  return false;
}

template<class Key,class Value>  int BSTree <Key,Value>::size(){
if(!this->root)
    return 0;

return _size;
}
template<class Key, class Value>
int BSTree<Key, Value>::height(BinaryNode<Key, Value>* rt){
  if(!rt)
    return 0;

  int lHeight = height(rt->left);
  int rHeight = height(rt->right);

  return 1 + (lHeight > rHeight ? lHeight : rHeight); 
}
template<class Key,class Value>  void BSTree <Key,Value>::print(){
this->print_in_order();
}
template<class Key,class Value>  void BSTree <Key,Value>::remove(const Key& key){
    BinaryNode<Key,Value> * temp1;
    temp1 = get(this->root,key);
    
    _size--;
    if(temp1->left==NULL&&temp1->right==NULL){
      std::cout<<"Right : Null Left : NULL "<<std::endl;
        if((temp1->parent)->left==temp1){
          (temp1->parent)->left=NULL;
          delete temp1;
        }
        else{
          (temp1->parent)->right=NULL;
          delete temp1;
        } 
    }
    else{ 
      if((temp1->right==NULL&&temp1->left!=NULL)){
            if((temp1->parent)->left==temp1){
              
              (temp1->parent)->left = temp1->left;
              (temp1->left)->parent=temp1->parent;
              delete temp1;
              return;
            }
            else{
              
              (temp1->parent)->right = temp1->left;
              (temp1->left)->parent=temp1->parent;
              delete temp1;
              return;
            }
      }
      else{
        if((temp1->right!=NULL&&temp1->left==NULL)){
          if((temp1->parent)->left==temp1){
            
            (temp1->parent)->left = temp1->right;
            (temp1->right)->parent=temp1->parent;
            delete temp1;
            return;
          } 
          else{

            
            (temp1->parent)->right = temp1->right;
            (temp1->right)->parent=temp1->parent;
            delete temp1;
            return;
          }
        }
        else{
          if(temp1->right!=NULL&&temp1->left!=NULL){

            
              BinaryNode<Key,Value> *temp2 = find_minimum(temp1->right);
              temp1->key=temp2->key;
              temp1->val=temp2->val;
            if((temp2->parent)->left==temp2){
              (temp2->parent)->left=NULL;
            }
            else{
              (temp2->parent)->right=NULL;
            }
            delete temp2;
            return;
          }
        }
      }
    }
}
template<class Key,class Value> BinaryNode<Key,Value> * BSTree <Key,Value>::get(BinaryNode<Key,Value> *root,const Key& key){
// Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return get(root->right, key);
 
    // Key is smaller than root's key
    return get(root->left, key);
}
template<class Key,class Value>  Value BSTree <Key,Value>::get(const Key& key){
BinaryNode<Key,Value> * temp1;
temp1 = get(this->root,key);
if(temp1!=NULL)
  return temp1->val;
else
  return Default_value;
}

  template<class Key,class Value> Key BSTree <Key,Value>::minimum(){
    BinaryNode<Key,Value> * temp2;
    temp2 = find_minimum(this->root);
    return temp2->key;
  }
  
  template<class Key,class Value> BinaryNode<Key, Value>*  BSTree <Key,Value>::find_minimum(BinaryNode<Key,Value> *temp1){
    if(temp1->left==NULL){
      return temp1;
    }
    else
      return find_minimum(temp1->left);
  }
  template<class Key,class Value>Key BSTree <Key,Value>::maximum(){
  BinaryNode<Key,Value> * temp2;
  temp2 = find_maximum(this->root);
  return temp2->key;
 
  }
  
  template<class Key,class Value> BinaryNode<Key, Value>*  BSTree <Key,Value>::find_maximum(BinaryNode<Key,Value> *temp1){
  if(temp1->right==NULL){
    return temp1;
   }
   else
    return find_maximum(temp1->right);
  }
  template<class Key,class Value> Key BSTree <Key,Value>::successor(const Key& key){
BinaryNode<Key, Value> *temp2 = this->root;

  //to find position of given key
  while(temp2){

    if(temp2->key == key)
      break;

    if(temp2->key > key)
      temp2 = temp2->left;
    else
      temp2 = temp2->right;
  }

  if(!temp2)
    return Default_key_minimum;

  //to find smallest node in right subtree
  if(temp2->right){
    temp2 = temp2->right;

    while(temp2){
      if(!temp2->left)
        break;
      temp2 = temp2->left;
    }
    
    if(!temp2)
      return Default_key_minimum;

    return temp2->key;
  }//to traverse back if right subtree is empty
  else{

    while(temp2){
      if(temp2->key > key)
        return temp2->key;

      temp2 = temp2->parent;
    }

    if(!temp2)
      return Default_key_minimum;
}
   }
  
  template<class Key,class Value> Key BSTree <Key,Value>::predecessor(const Key& key){
   BinaryNode<Key, Value> *temp2 = this->root;

  //to find position of given key
  while(temp2){
    if(temp2->key == key)
      break;

    if(temp2->key > key)
      temp2 = temp2->left;
    else
      temp2 = temp2->right;
  }

  if(!temp2)
    return Default_key_minimum;

  //to find largest node in left subtree
  if(temp2->left){
    temp2 = temp2->left;

    while(temp2){
      if(!temp2->right)
        break;
      temp2 = temp2->right;
    }
    
    if(!temp2)
      return Default_key_minimum;

    return temp2->key;
  }//to traverse back if left subtree is empty 
  else{

    while(temp2){
      if(temp2->key < key)
        return temp2->key;

      temp2 = temp2->parent;
    }

    if(!temp2)
return Default_key_minimum;
   }
 }
#endif /* ifndef BSTREE_HPP */
  