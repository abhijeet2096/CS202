/*
*Name :- Abhijeet Sharma
*Roll No. :- B15102
*Problem :- Driver Function for priority queue
*/
#include "seqlinearlist.hpp"
#include "min_priority_queue.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int min,v,HeapSize;
	int MaxSize,Size,x,choice;
	bool empty;

	cout<<"\n----------------------Build Heap---------------------\n";
	cout<<"Enter max Size of the Heap ";
	cin>>MaxSize;
	cout<<"Enter Size of the Heap ";
	cin>>Size;
	LinearList <int> heap2 = LinearList <int> (MaxSize);
	for(int i = 1 ; i <= Size ; i++)
	{
		cout<<"\nEnter element "<<(i)<<" ";
		cin>>x;
		heap2.insert(i,x);
	}

	MinPriorityQueue <int> min_heap;
	min_heap.build_heap(heap2);
	while(1)
	{
	cout<<"\n1.Insert\n2.Minimum\n3.Extract minimum\n4.IsEmpty\n5.Heap Size\n6.Display\n7.Exit\n";
	cin>>choice;
	switch(choice)
		{
		case 1:
				{
					if(Size <= MaxSize)
					{
						cout<<"\nEnter value to be inseted in heap ";
						cin>>v;
						min_heap.insert(v);
						Size++;
					}
					else
						cout<<"\nHeap full\n";	
					break;
				}
		case 2:
				{
					int min = min_heap.minimum();
					cout<<min<<endl;
					break;
				}
		case 3:
				{
					if(Size > 0)
					{	int min = min_heap.extract_min();
						cout<<min<<endl;
						Size--;
					}
					else
						cout<<"\nEmpty heap\n";
					break;
				}
		case 4:
				{
					empty = min_heap.empty();
					if(empty)
						cout<<"empty";
					else
						cout<<"not empty";
					cout<<endl;
				}
		case 5:
				{
					HeapSize = min_heap.heap_size1();
					cout<<"\nHeap Size : "<<HeapSize;
					break;
				}
		case 6:{
					min_heap.display();
					break;
				}
		case 7:	exit(0);
		
		default:
				cout<<"\nEnter correct option\n";
		}
	}
/*

	cout<<"\nEnter max Size";
	cin>>MaxSize;
	cout<<"\nEnter heap Size";
	cin>>Size;
	LinearList <int> heap2 = LinearList <int> (MaxSize);


	for(int i = 1 ; i <= Size ; i++)
	{
		cout<<"\nEnter element "<<(i)<<" ";
		cin>>x;
		heap2.insert(i,x);
	}

	cout<<endl;
	MinPriorityQueue <int> min_heap;
	
	min_heap.build_heap(heap2);

	min_heap.display();
	min = min_heap.extract_min();
	min_heap.display();
	min = min_heap.extract_min();
	min_heap.display();
	
	cout<<"\nminimum = "<<min;	*/	
	return 0;
}