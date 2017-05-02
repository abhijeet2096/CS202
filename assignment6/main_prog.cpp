/*
*Name :- Abhijeet Sharma
*Roll No. :- B15102
*Problem :- Main Problem
*/


#include "seqlinearlist.hpp"
#include "min_priority_queue.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

class process
{
	public : 
			int id;
			int BurstTime;
			int PriorityValue;
			bool InsertCheck;
			int delay;
			int counter;
			int time;
	
};


int main()
{
	
	int CPUPriority=10,N,total_BurstTime=0,n=0,i,j,k,counter=0,ch=0,flag=0;
	
	cout<<"Enter the number of interrupt requests which will be received by processor\n\nN :  ";
	cin>>N;

	process P[N];

	for (int i = 0; i < N; i++)
	{
		cout<<"\n\n--------------------------Enter Device Details--------------------------\n";
		cout<<"\n\tID["<<i+1<<"] : ----> ";
		cin>>P[i].id;
		cout<<"\n\tBurst Time["<<i+1<<"] : ----> ";
		cin>>P[i].BurstTime;
		cout<<"\n\tDelay["<<i+1<<"] : ----> ";
		cin>>P[i].delay;		
		cout<<"\n\tPriority Value["<<i+1<<"] : ----> ";
		cin>>P[i].PriorityValue;
		P[i].InsertCheck = false;
	}

	P[0].time=0;
	for (int i = 1; i < N; i++)
	{
		P[i].time = P[i-1].time + P[i].delay;
	}
	system("clear");
	cout<<"\t\t\t -------------------------------------------------------------CPU ANALYSIS----------------------------------------------------"<<endl;
	cout<<"\n\n\n";
	cout<<"\t\t\t  \t\t\t  --------------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t  \t\t\t  |Sl.No.  |   I/O Device ID  |  Burst Time(in ms)  |  Delay (in ms) |   Priority Value |\n";
	cout<<"\t\t\t  \t\t\t  --------------------------------------------------------------------------------------\n"<<endl;
	for (int i = 0; i < N; i++)
	{
		cout<<"\t\t\t  \t\t\t  |"<<i+1<<"\t   |"<<P[i].id<<"\t\t      |"<<P[i].BurstTime<<"\t\t    |"<<P[i].delay<<"\t\t     |"<<P[i].PriorityValue<<"\t"<<"      \t\t|\n";
		cout<<"\t\t\t  \t\t\t  --------------------------------------------------------------------------------------"<<endl;
	}
	cout<<"\n\n\n";

	MinPriorityQueue<int>q;

	cout<<"\t\t\t  \t\t\t \t\t\t \t|ID \t STATUS    |"<<endl;
	cout<<"\t\t\t  \t\t\t \t\t\t \t|------------------|"<<endl;
	LinearList <int> heap2(N);
	heap2.insert(1,P[0].PriorityValue);
	q.build_heap(heap2);
	q.extract_min();

	while(1)
	{
		flag=0;	k=0;

		for(i=0;i<N;i++)
        {
            if(counter >= P[i].time && P[i].InsertCheck == false)
            {
                n = i;
                break;
            }
        }	
        for(i=0;i<N;i++)
        {
            if(counter >= P[i].time )
            {
                if(P[n].PriorityValue > P[i].PriorityValue  && P[i].InsertCheck == false)
                    n = i;
            }
            else
                break;
        }
        if(n == CPUPriority)
        {
        	P[CPUPriority].BurstTime = P[CPUPriority].BurstTime -1;
        	if(P[CPUPriority].BurstTime == 0)
        	{
        		q.extract_min();
        		cout<<"\t\t\t  \t\t\t  \t\t\t \t|"<<P[CPUPriority].id<<" \t completed |\t"<<endl;
        		ch++;
        		 if(!q.empty())
                {
                    for(j=0;j<N;j++)
                    {
                        if(P[j].PriorityValue == q.minimum())
                        break;
                    }

                    CPUPriority = j;
                    n=j;
                }   
        	}

        }
        else
        {      	
        	if(q.empty())
        	{
        		 cout<<"\t\t\t  \t\t\t  \t\t\t \t|"<<P[n].id<<" \t Started   |\t";
        		q.insert(P[n].PriorityValue);
                P[n].InsertCheck = true;
                CPUPriority =  n;
	        	

        		continue;
        	}
        	
        	if(P[CPUPriority].BurstTime != 0)
        	{
        		if(P[n].PriorityValue < P[CPUPriority].PriorityValue){

                    cout<<"\t\t\t  \t\t\t \t\t\t \t|"<<P[CPUPriority].id<<" \t Paused    |\t"<<endl;

	                cout<<"\t\t\t  \t\t\t \t\t\t \t|"<<P[n].id<<" \t Started   |\t";
	                q.insert(P[n].PriorityValue);
	                CPUPriority =  n;
	                P[n].InsertCheck = true;
                }
                else
                {
                	flag=1;
                	 counter = counter+P[CPUPriority].BurstTime;
                    cout<<"\t\t\t  \t\t\t \t\t\t \t|"<<P[CPUPriority].id<<" \t Completed  |\t"<<endl;
                    ch++;
                    q.extract_min();
                    for(i=0;i<N;i++)
                    {
                        if(counter >= P[i].time )
                        {
                                if(P[n].PriorityValue > P[i].PriorityValue  && P[i].InsertCheck == false)
                                    n = i;
                        }
                        else
                            break;
                    }
                    cout<<"\t\t\t  \t\t\t \t\t\t \t|"<<P[n].id<<" \t Started  |\t";
	                q.insert(P[n].PriorityValue);
	                CPUPriority =  n;
	                P[n].InsertCheck = true;
                   
                }

              
                continue;

        	}
        	else
        	{
                cout<<"\t\t\t  \t\t\t \t\t\t \t|"<<P[CPUPriority].id<<" \t Completed |\t"<<endl;
                ch++;
                q.extract_min();

                if(!q.empty())
                {
                    for(j=0;j<N;j++)
                    {
                        if(P[j].PriorityValue == q.minimum())
                        break;
                    }

                    	CPUPriority = j;
                }   
            }

        }

        if(ch==N)
        {
        	break;
        }

        counter = counter + 1;
        if(flag==1)
        {
        	counter = counter-1;
        }

       

	}
	cout<<"\t\t\t  \t\t\t \t\t\t \t|------------------|"<<endl;
	return 0; 

}

