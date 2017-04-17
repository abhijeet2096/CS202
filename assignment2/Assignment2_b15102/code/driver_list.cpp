// Driver Program for testing `seqLinearList` class
// Author:
// Roll Number:
#include <iostream>
#include "seqLinearList.hpp"

using namespace std;
// Please read the guidelines carefully before writing any piece of code
int main(int argc, char const *argv[])
{
	int length = 0;
	int maxsize = 10;
	int size;
	float x,def;
	cout<<"Max Size:";
	cin>>maxsize;
	cout<<"how many entries:";
	cin>>size;
	cout<<"\ndefault value for buffer ";
	cin>>def;
	//LinearList <float> a = LinearList<float>(maxsize,def);
	//LinearList<float> a;
	cs202::LinearList<float> a(maxsize,def);

if(size>0)
{	
	for(int i = 0 ; i<size ; i++)
	{
		cout<<"Enter entry "<<(i+1)<<" ";
		cin>>x;
		a.insert(x,i);
	}
}
	int k,k2;
	cout<<"calling operator function input the value of position(1-n indexing) ";
	cin>>k;
	cout<<"value returned is: "<<a[k]<<endl;
	int s;
	int e3,e4;
	float e,e2,x2,e5;
	a.display();

	cout<<"calling empty(1 for empty) "<<a.empty()<<endl;

	cout<<"size of list "<<a.sizel()<<endl;

	cout<<"Max Size of list "<<a.capacityl()<<endl;

	cout<<"Enter which element (if not found then size) calling find";
	cin>>e;
	cout<<"The element's position is: "<<a.find(e)<<endl;

	cout<<"Enter value to be appended in list(calling pushback) ";
	cin>>e2;
	a.push_back(e2);
	a.display();

	cout<<"Enter new size "<<endl;
	cin>>e3;
	a.resize(e3);
	a.display();
	
	cout<<"Enter element to be erased "<<endl;
	cin>>x2;
	a.erase(x2);
	a.display();

	cout<<"Enter legal position to be erased "<<endl;
	cin>>e4;
	a.erase_pos(e4);
	a.display();

	cout<<"Enter value to be inserted and its position ";
	cin>>e5>>k2;
	a.insert(e5,k2);
	a.display();
	return 0;
}