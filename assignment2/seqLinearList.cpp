#include <iostream>
#include "seqLinearList.hpp"


template <class Item>
LinearList <Item> :: LinearList(void) : element(NULL), MaxSize(4){
}

template <class Item>
LinearList <Item> :: LinearList(const int& MaxListSize){
	element=new Item[MaxListSize]; 
	cout << "Constructor being called ..." << endl	;
	len=0;
	MaxSize=MaxListSize;

	for (int i = 0; i < MaxListSize; i++)
	{
		element[i]=0;
	}
}

//copy constructor
template <class Item>
LinearList <Item>::LinearList (const LinearList &obj,const int& MaxListSize) {
  // cout << "Copy constructor allocating ptr." << endl;
   element = new Item[MaxListSize];
   *element = *obj.element; // copy the value
}

template <class Item>
LinearList <Item>:: ~LinearList(void){
	//delete [] element;
	element=NULL;
}
template <class Item>
/* Insert x after k-th element.
		 * */
void LinearList <Item>:: insert(const int  k, Item& x){

	if(len==0){
		element[k-1]=x;
		len++;
    	}
   
	else if(len!=0&&len<MaxSize){
	//Moving elements towards right side of list 
		
		for (int i = len-1; i >= k-1; i--)
			{
				if(element[i]!=0)
				element[i+1]=element[i];
			}
		element[k-1]=x;
		len++;	
	}
	else if(len>=MaxSize)
	cout << "Error!";
	
}

template <class Item>
/* Set x to the k-th element and delete that k-th element.
		 * */
void LinearList <Item> :: deleteElement(const int  k, Item& x){
	x=*(element+k-1);
	for (int i = k-1; i < len-1; i++)
	{
		element[i]=element[i+1];
	}
	len--;
}
template <class Item>
/* Search for x and 
		 * return the position if found, else return 0.
		 * */
int LinearList <Item>::  search(Item& x){
	for(int i=0;i<len;i++){
		if(*(element+i)==x)
			return i+1;
	}
			return 0;
}
template <class Item>
/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
bool LinearList <Item>:: find(const int k, Item& x){
	x=element[k];
	
		if(k<=len)
			return true;
		else	
			return false;
}
template <class Item>
/* Returns the k-th element of the list. 
		 * */
Item LinearList <Item>:: returnListElement(const int k){
	return element[k-1];
}
template <class Item>
/* Returns the maximum size of the list.
     		 * */
int LinearList <Item>::  maxSize(){
	return MaxSize;
}
template <class Item>
/* Returns the actual length (number of elements) in the list.
     		 * */
int LinearList <Item>:: length(){
	return len;
}
template <class Item>
/* Returns true if the list is empty, false otherwise.
     		 * */
bool LinearList <Item>:: isEmpty(){
	if(len==0)
		return true;
	else 
		return false;
}

template <class Item>
/* Set x to the k-th element and delete that k-th element.
		 * */
void LinearList <Item> :: display(int a,int b){
	cout << "LinearList :";
	cout << "\t";
	for (int i = a-1; i <= b-1; i++)
	{
		cout << element[i];
		cout << "\t";
	}
	cout<< endl;
}

/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
template <class Item>

//return i'th element of list
Item& LinearList <Item> :: operator[](const int& i){
	return element[i];
}
