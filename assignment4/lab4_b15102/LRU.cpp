/*
Submitted by:- Abhijeet Sharma
Roll No.- B15102
*/

#include <iostream>
#include "OpenMap.hpp"
#include <stdlib.h>
#include <limits.h>
using namespace std;


int main()
{
	int M,N,size,count,val,i,j,flag,max,max_ele;
	count = 0;
	char ch = 'y';
	cout<<"Enter M(cache): ";
	cin>>M;
	cout<<"Enter N(main memory): ";
	cin>>N;
	cout<<"Enter size of word: ";
	cin>>size;

	cs202::OpenMap<int,int> counter(M);
	cs202::OpenMap<int,int> cache(M);

	while(1)
	{	
		cout<<"\nEnter address to be referenced in cache(from main memory): ";
		cin>>val;
		if(!(val < N*size && val >= 0))
		{	
			cout<<"invalid memory";
			break;
		}

		int val1 = val/size;			//address of the memory block
if(count<M)								//count variable to find status of the cache
{	
	if(!cache.has(val1))
	{		
		cache.put(val1,val1);

		for(i=0;i<N;i++)
			if(cache.has(i))
				counter[i] = counter[i]+1;


		counter.put(val1,0);
		count++;
	}
	else
	{
		for(i=0;i<N;i++)
			if(cache.has(i))
				counter[i] = counter[i]+1;

		counter.put(val1,0);

	}
}		
	else							//if the cache is full then in else
	{	
		if(cache.has(val1))			//if value is already in cache then don't delete the max counter
		{
		for(i=0;i<N;i++)
			if(cache.has(i))
				counter[i] = counter[i]+1;

		counter.put(val1,0);
		}
		else
		{		
		max_ele = INT_MIN;
		max = 0;
		for(i = 0 ; i<N ; i++)
		{
			if(counter.has(i)&&(counter[i] > max_ele))
			{	
				max_ele = counter[i];
				max = i;
			}
		}
		cout<<"\nMax counter value is: "<<counter[max]<<"and key is: "<<max<<endl;
		cache.remove(max);
		counter.remove(max);

		//cache.print();	
		//cout<<"\n";
		//counter.print();

		cache.put(val1,val1);

		for(i=0;i<N;i++)
			if(cache.has(i))
				counter[i] = counter[i]+1;

		counter.put(val1,0);
		//cache.print();
		//counter.print();

		}
	}
	cout<<"\n";
	cout<<"cache     counter"<<endl;
	for(i = 0 ; i<N ; i++)
		if(counter.has(i))
		{
			cout<<i<<"         "<<counter[i]<<endl;;
		}
		//cache.print();
		cout<<"\n";

		//counter.print();

		cout<<"\nDo you want to continue:(N/Y)";
		cin>>ch;
		if(ch == 'N' || ch == 'n')
			exit(0);
	}
	return 0;
}