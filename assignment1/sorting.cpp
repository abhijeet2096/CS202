#include <iostream>
#include "sorting.hpp"


template <class Item>
void Sort <Item> :: insertionSort(LinearList<Item>& A, int low, int high){
	int j,temp;
	for (int i = low; i <=high-1; i++)
	{
        temp=A[i];
		j=i-1;
		while(j>=0 && A[j]>temp){
			A[j+1]=A[j];
			
			j=j-1;
		}
		A[j+1]=temp;
	}
	
}
template <class Item>
void Sort <Item> :: bubbleSort(LinearList<Item>& A, int low, int high){
	Item temp;
 for (int i = low; i < high;++i)
 {
 	for (int j = low-1; j < high -i ; ++j)
 	{
 		if (A[j]>A[j+1])
 		{
 			temp =A[j];
 			A[j]=A[j+1];
 			A[j+1]=temp;
 		}
 	}
 	
 }
}
template <class Item>
void Sort <Item> :: rankSort(LinearList<Item>& A, int low, int high){

Item rank[high-low+1];
Item b[high-low+1];
int i,j;
for ( i = low-1; i <= high-1; i++){
	rank[i]=0;
}


for ( i = low; i < high; i++)
{
	for ( j = low-1; j < i; j++)
	{
		if (A[j]>A[i])
		{
			rank[j]++;
		}
		else
			rank[i]++;
	}
}
for ( i = low-1; i <= high-1; i++)
{
	b[rank[i]]=A[i];	
}
for ( i = low-1; i <= high-1; i++)
{
	A[i]=b[i];	
}
}
template <class Item>
void Sort <Item> :: selectionSort(LinearList<Item>& A, int low, int high){
Item temp ;
for (int i = low-1; i < high-low+1; i++)
{
	for (int j = i+1; j < high-low+1; j++)
	{
		if (A[i]>A[j])
		{
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}


	}
}
}
