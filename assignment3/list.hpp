/*
 * list.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * 
 */

#ifndef LIST_HPP
#define LIST_HPP 1
#include <iostream>
#include <cstddef>


using namespace std;

template<class P>
    class ListNode{
    	  template <class T> 
    	friend class  list;
    	private :
    	  P data;
    	  ListNode *link;
    		int len;
    	
    	public:
	    /* Constructors with No Arguments */
	    ListNode(void)
	    : link(NULL)
	    { }
	    
	    /* Constructors with a given value */
	    ListNode(P val)
	    : data(val), link(NULL)
	    { }
	    
	    /* Constructors with a given value and a link of the next node */
	    ListNode(P val, ListNode* next)
	    : data(val), link(next)
	    {}
	    
	    /* Getters */
	    P getValue(void)
	    { return data; }
	    
	    ListNode* getNext(void)
	    { return link; }
    };

  template<class T>
    class list
    {
    	ListNode <T> *first=NULL;
      private:
      	ListNode <T>*Value_add;
      	 ListNode <T>*ptr;

      public:
        /*
         * Primary contructor.
         * Should construct an empty list.
         * Size of the created list should be zero.
         */
        list(){
        	first=NULL;
        }
        /*
         * Seondary constructor.
         * Creates a new list which is a copy of the provided list.
         */
        list(const list<T> & x){
        	ptr = new ListNode <T> ();
			ptr =x.first; 
        }
        /*
         * Destructor.
         * Frees all the memory acquired by the list.
         */
        ~list(){
        		ListNode <T> *next;//next node
				while(first){
					next=first->link;
					delete first;
					first=next;
				}
        }
        /*
         * adds value at the end of the list.
         */
        void append(const T& value){
        	ListNode <T>*next,*temp;//next node
				temp=next=first;
				while(next){
					temp=next;
					next=next->link;
				}
				 Value_add= new ListNode <T>(value);
				 Value_add->data = value;
				 Value_add->link = NULL;
				if(first==NULL)
					first=Value_add;
				else
				temp->link=Value_add;
				

        }/*
        Display our Linked List
        */
        void display(){
         	ListNode <T>*next;//next node
         		next=first;
         		cout << "\n ";
				while(next){
					
					cout << "\t ";
					cout << next->data;
					next=next->link;
					
				}
				
         }
         T front(){
         	if(first!=NULL)
         	return first->data;
         	
         }
         T back(){
         	ListNode <T>*next,*temp;//next node
         		temp=next=first;
         		
				while(next){
					temp=first;
					
					next=next->link;
					
				}
         	return temp->data; 
         }
        /*
         * Returns the length of the list.
         */
         int length(){
         	ListNode <T>*next;//next node
				next=first;
				int counter=0;
				while(next){
					next=next->link;
					counter++;
				}
				return counter;	
         }
        /*
         * Returns a boolean indicating whether the list is empty.
         */
         bool empty(){
         	if(first==NULL)
					return true;
			else
					return false;
         }
        /*
         * Adds a value to the front of the list.
         */
        void cons(const T& value){
        	Value_add = new ListNode <T>(value)  ;
				Value_add->data = value;
				Value_add->link = first;
				first = Value_add; 
        }
        /*
         * Removes the first occurence of the value from list.
         */
        void remove(const T & x){
        	ListNode<T> *next,*temp;
				next=first;
				temp=next;
				while(next){
					if(next==first&&(next->data==x)){
							first=next->link;
							delete temp;
							break;
					}
					
					if(next->data==x){
						temp->link=next->link;
						delete next;
						break;
					}
					else{
						//Todo if not found then what ?
					}
					temp=next;
					next=next->link;
				}
        }
        /*
         * Appends the given list x at the end of the current list.
         */
        void append(list<T>& x){
        	ListNode <T>*next,*temp;
				next=temp=first;
				while(next){
					temp=next;
					next=next->link;
				}
				temp->link = x.first; 
        }
    };
  
  
 

#endif