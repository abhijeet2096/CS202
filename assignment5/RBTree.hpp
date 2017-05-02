#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
#include "limits.h"
/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 */
int black_height=0;

enum Color { RED, BLACK };
Color col;



template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {
/* Inherit as many functions as possible from BSTree.
 * Only override those which absolutely need it.
 * Also make sure that all inherited functions work correctly in the context of a red black tree.
 * node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 * Use a typedef to refer to a pointer to your node via node_ptr
 */

	/* Function insertRBFixup
	 *
	 * Used for:
	 * Used after an insertion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	
	void insertRBFixup(BinaryNode<Key,Value>* z);

/* Function deleteRBFixup
	 * Used for:
	 * Used after a deletion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */
	void deleteRBFixup(BinaryNode<Key,Value>* x,BinaryNode<Key,Value>* p);

	int blackHeight1(BinaryNode<Key,Value>* root);
	void left_rotate(BinaryNode<Key,Value>*  z);
	void right_rotate(BinaryNode<Key,Value>*  z);

public:
	/* Function : blackHeight
	 * 
	 * Returns:
	 * the black height of the red black tree which begins at node_ptr root
	 */	

		void put(const Key& key, const Value& value);
		int blackHeight();
		void remove(const Key& key);
		int color(Key key);
	/*
	 * Apart from these functions, also provide functions for rotations in the tree.
	 * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 */
};


template<class Key, class Value>
void RBTree<Key,Value>::put(const Key& key, const Value& value){


	BSTree<Key,Value> :: put(key,value);
	BinaryNode<Key,Value>* z = this->get(this->root,key);

	z->color=RED;

	insertRBFixup(z);

}	



template <class Key, class Value> 
void RBTree<Key,Value> :: insertRBFixup(BinaryNode<Key,Value>*  z){
	if(z == this->root)
	{
		this->root->color = BLACK;
	}
	else
	{


	while(1)
	{
		if(z==this->root){
			this->root->color = BLACK;
			break;
		}
		if(z->parent->color != RED){
			break;
		}
		if(!z->parent->parent)
		{
			break;
		}
		if (z->parent == z->parent->parent->left)
		{
			BinaryNode<Key,Value>* y = z->parent->parent->right;
			if(y){
				
				if(y->color == RED)
				{
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color=RED;
					z = z->parent->parent;
				}
				else {
					
					if(z==z->parent->right)
					{
						z=z->parent;
						left_rotate(z);
					}
				
				
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					right_rotate(z->parent->parent);	
					
				}
			}
			else
			{
				if(z==z->parent->right)
				{
					z=z->parent;
					left_rotate(z);
				}
			
			
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				right_rotate(z->parent->parent);	
			
			}
			
		}
		else
		{
			BinaryNode<Key,Value>* y = z->parent->parent->left;

			if(y){
				
				if(y->color == RED)
				{
					z->parent->color = BLACK;
					y->color = BLACK;
					z->parent->parent->color=RED;
					z = z->parent->parent;
				}
				else{

					if(z==z->parent->left)
					{
						z=z->parent;
						right_rotate(z);
					}
				
				
					z->parent->color = BLACK;
					z->parent->parent->color = RED;
					left_rotate(z->parent->parent);	
				}
			}
			else
			{
				
				if(z==z->parent->left)
				{
					z=z->parent;
					right_rotate(z);
				}
		
			
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				left_rotate(z->parent->parent);	
			
			}
			
		}
		
		}

		this->root->color = BLACK;
	
	}

}

template <class Key, class Value>
void RBTree<Key,Value> :: left_rotate(BinaryNode<Key,Value>*  z){

	BinaryNode<Key,Value>* y = z->right;
	z->right = y->left;

	if(y->left != NULL)
	{
		y->left->parent = z;
	}

	y->parent = z->parent;

	if(z->parent == NULL)
	{
		this->root = y;
	}
	else if(z == z->parent->left)
	{
		z->parent->left = y;
	}
	else z->parent->right = y;
	
	y->left = z;
	z->parent = y;

}


template <class Key, class Value>
void RBTree<Key,Value> :: right_rotate(BinaryNode<Key,Value>*  z){

	BinaryNode<Key,Value>* y = z->left;
	z->left = y->right;

	if(y->right != NULL)
	{
		y->right->parent = z;
	}

	y->parent = z->parent;

	if(z->parent == NULL)
	{
		this->root = y;
	}
	else if(z == z->parent->right)
	{
		z->parent->right = y;
	}
	else z->parent->left = y;
	
	y->right = z;
	z->parent = y;

}


template <class Key, class Value>
int RBTree<Key,Value> :: blackHeight(){

	if(this->root){
		blackHeight1(this->root);
	}
	else
	{
		black_height=1;
	}

	

	std::cout<<black_height;

}

template <class Key, class Value>
int RBTree<Key,Value> :: blackHeight1(BinaryNode<Key,Value>*  root){

	
	if (root == NULL)   
           return black_height;
    if(root->color==BLACK)
           black_height++;    
    int black_height = blackHeight1(root->left);

}


template<class Key, class Value>
void RBTree<Key, Value>::remove(const Key& key){

	if(this->has(key)){

		BinaryNode<Key,Value>* x = this->get(this->root,key);

	if(x==this->root){

		BSTree<Key,Value> :: remove(key);
		x->color=BLACK;
	}
	else if(x->left==NULL&&x->right==NULL){
		BinaryNode<Key,Value>* y =x->parent;
		BSTree<Key,Value> :: remove(key);
		x=new BinaryNode<Key,Value>;
			//std::cout<<"hello";
			x=NULL;
			deleteRBFixup(x,y);
	}
	else
	{
		BinaryNode<Key,Value>* y =x->parent;

		BSTree<Key,Value> :: remove(key);

	
	
			deleteRBFixup(x,y);
			


	}
	}

	

}

template <class Key, class Value>
void RBTree<Key,Value> :: deleteRBFixup(BinaryNode<Key,Value>*  x,BinaryNode<Key,Value>*  p){
	while(1)
	{

		if(!x)
		{	
			if(p->left==NULL)
			{
				BinaryNode<Key,Value>* w=p->right;
				if(p->right==NULL)
				{
					break;
				}
				if(w->color==RED)
				{
					w->color = BLACK;
					p->color = RED;
					left_rotate(p);
					w=p->right;
				}

				if(w->right == NULL && w->left == NULL)
				{
					w->color=RED;
					x=p;	
				}
				else if(w->left->color == BLACK && w->right->color == BLACK)
				{
					w->color=RED;
					x=p;
				}
				else{
					if(w->right == NULL){

						w->left->color = BLACK;
						w->color = RED;
						right_rotate(w);
						w=p->right;
					
					}
					else if(w->right->color==BLACK)
					{
						w->left->color = BLACK;
						w->color = RED;
						right_rotate(w);
						w=p->right;
					
					}
				
					w->color =p->color;
					p->color = BLACK;
					w->right->color = BLACK;
					left_rotate(p);
					x=this->root;
									
				} 

			}
			else
			{
				BinaryNode<Key,Value>* w=p->left;
				if(p->left==NULL)
				{
					break;
				}
			
				if(w->color==RED)
				{
					w->color = BLACK;
					p->color = RED;
					right_rotate(p);
					w=p->left;
				}
				if(w->right == NULL && w->left == NULL)
				{
					w->color=RED;
					x=p;	
				}
				else if(w->right->color == BLACK && w->left->color ==BLACK)
				{
					w->color=RED;
					x= new BinaryNode<Key,Value>;
					x=p;
				}
				else 
				{

					if(w->left==NULL){
					
						w->right->color = BLACK;
						w->color = RED;
						left_rotate(w);
						w=p->left;
					}
					else if(w->left->color==BLACK)
					{
					
						w->right->color = BLACK;
						w->color = RED;
						left_rotate(w);
						w=p->left;
					}
				
					w->color = p->color;
					x->parent->color = BLACK;
					w->left->color = BLACK;
					right_rotate(p);
					x=this->root;
				
				}
			}

			if(x!=this->root){
				p=x->parent;
			}

		}
		else if(x==this->root){
			break;
		}
		else if(x->color!=BLACK)
			break;
		else
		{

			if(x==x->parent->left)
			{
				BinaryNode<Key,Value>* w=x->parent->right;
				if(x->parent->right==NULL)
				{
					break;
				}

				if(w->color==RED)
				{
					w->color = BLACK;
					x->parent->color = RED;
					left_rotate(x->parent);
					w=x->parent->right;
				}

				if(w->right == NULL && w->left == NULL)
				{
					w->color=RED;
					x=x->parent;	
				}
				else if(w->left->color == BLACK && w->right->color ==BLACK)
				{
					w->color=RED;
					x=x->parent;
				}
				else{

					if(w->right==NULL){


					w->left->color = BLACK;
					w->color = RED;
					right_rotate(w);
					w=x->parent->right;
				
					}
					else if(w->right->color==BLACK)
					{
						w->left->color = BLACK;
						w->color = RED;
						right_rotate(w);
						w=x->parent->right;
					}
				
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->right->color = BLACK;
					left_rotate(x->parent);
					x=this->root;
				
			} 
				
			}
			else
			{

				BinaryNode<Key,Value>* w=x->parent->left;
				if(x->parent->left==NULL)
				{
					break;
				}
				if(w->color==RED)
				{
					w->color = BLACK;
					x->parent->color = RED;
					right_rotate(x->parent);
					w=x->parent->left;
				}

				if(w->right == NULL && w->left == NULL)
				{
						w->color=RED;
						x=x->parent;	
				}
				else if(w->right->color == BLACK && w->left->color ==BLACK)
				{
					w->color=RED;
					x=x->parent;
				}
				else
				{
					if(w->left==NULL){


					w->right->color = BLACK;
					w->color = RED;
					left_rotate(w);
					w=x->parent->left;
					
				}
				else if(w->left->color==BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					left_rotate(w);
					w=x->parent->left;
				}
				
				
					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->left->color = BLACK;
					right_rotate(x->parent);
				
						x=this->root;
				
		
				}
			}

			if(x!=this->root){
				p=x->parent;
			}	
		}
	}
	if(x){
		x->color = BLACK;
	}
	
}


template <class Key, class Value>
int RBTree<Key,Value> :: color(Key key){

	if(this->has(key)){
		
		BinaryNode<Key,Value>*  z = this->get(this->root,key);

		if(z->color == RED)
		{
			std::cout << "RED";
		}
		else
		{
			std::cout << "BLACK";
		}
	}
	


}



#endif /* ifndef RBTree_HPP_ */