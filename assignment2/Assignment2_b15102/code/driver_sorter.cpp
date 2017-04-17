// Driver Program for testing `sorting` class
// Author:Abhijeet Sharma
// Roll Number: B15102
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "seqLinearList.hpp"
#include "sorting.hpp"
#include "timer.hpp"
using namespace std;

double start_s;
void start()
{
	start_s = clock();
}

float stop()
{
	double stop_s = clock();
	float t = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000;
	cout<<"\nExecution time(s)="<<t<<"ms"<<endl;
	return t;
}

int main(int argc , char* argv[])
{

	fstream fout;
	fout.open("rand1.txt",ios::out|ios::app);

	int length = 0;
	int maxsize = 10;
	int size;
	double x,def;
	
	cin>>maxsize;
	
	cout<<"\nsize:"<<maxsize<<endl;
	size = maxsize;
	
	cs202::LinearList<double> a(maxsize);
	fout<<size<<"\t\t";

if(size>0)
{	
	for(int i = 0 ; i<size ; i++)
	{
		//cout<<"Enter entry "<<(i+1)<<" ";
		cin>>x;
		a.insert(x,i);
	}
}


	cs202::Sort <double> ob;
	int low = 1;
	int t;
	float time;
		
for(t = 1 ; t<5 ; t++)
{	
	switch(t)
	{
		case(1):{
				cs202::LinearList <double> Insertionlist = a;

				start();
				ob.insertionSort(Insertionlist,low,Insertionlist.sizel());
				//ob.insertionSort(a,low,a.sizel());
				time = stop();
				fout<<time;
				//fout<<maxsize<<"\t\t"<<time;
				cout<<endl;
				cout<<"displaying insertion sorted list\n";
				//Insertionlist.display();
	
				cout<<endl;
				break;

				}
		case(2):{
				cs202::LinearList <double> Selectionlist = a;

				start();
				ob.selectionSort(Selectionlist,low,Selectionlist.sizel());
				//ob.selectionSort(a,low,a.sizel());
				time = stop();
				fout<<"\t\t\t"<<time;
				cout<<"displaying selection sorted list\n";
				//Selectionlist.display();
				cout<<endl;
				break;
				}
		case(3):{
				cs202::LinearList <double> Bubblelist = a;
				start();
				ob.bubbleSort(Bubblelist,low,Bubblelist.sizel());
				//ob.bubbleSort(a,low,a.sizel());
				time = stop();
				fout<<"\t\t\t\t\t\t"<<time;
				cout<<"displaying bubble sorted list\n";
				//Bubblelist.display();
				cout<<endl;
				break;
				}
		case(4):{
				cs202::LinearList <double> ranklist = a;
				start();
				ob.rankSort(ranklist,low,ranklist.sizel());
				//ob.rankSort(a,low,a.sizel());
				time = stop();
				fout<<"\t\t\t\t\t\t\t\t\t"<<time;
				cout<<"displaying rank sorted list\n";
				//ranklist.display();
				cout<<endl;
				break;
				}
		case(5):{
				//cs202::LinearList <double> mergelist = a;
				start();
				//ob.mergeSort(mergelist,low,mergelist.sizel());
				ob.mergeSort(a,low,a.sizel());
				time = stop();

				cout<<"displaying merge sorted list\n";
				//a.display();
				cout<<endl;	
				break;
				}
		case(6):{
				//cs202::LinearList <double> quicklist = a;
				start();
				//ob.quickSort(quicklist,low,quicklist.sizel());
				ob.quickSort(a,1,a.sizel());
				time = stop();

				cout<<"displaying quick sorted list\n";
				//a.display();
				cout<<endl;	
				break;
				}			
		default:
						
				break;
				
		}
}	
	fout<<"\n";
	fout.close();
	return 0;
}
