/**************************
*Name: Abhijeet sharma
*Date: 20/03/2017
*Roll No. B15102
*********************/
#include <iostream>
#include "stack.hpp"


int main(){
	stack <int> A = stack <int> ();
	 
	int option;
	int data;
	while(1){
		cout << "\nPlease Select one of the option below";
		cout << "\n1.Push\n2.Pop\n3.Top\n4.Size\n5.Isempty\n6.Display\n7.Exit";
		cin >> option;
		switch(option){
			case 1: {cout << "please enter value you want to Push?";
				   cin >> data;
				   A.push(data);
				   break;}

			case 2:{
				   cout << "\nPoped Element :";
				   
				   cout << A.pop();
				   break;}
			case 3:{
				   cout << "\nDisplaying Top Value";
				   cout << A.top();
				   break;}
			case 4: {cout << "\nThe Lenght of our List is:";
					cout << A.size() ;
					break;}

			case 5: {if(A.empty()==1)
						cout << "Yes Empty";
					else
						cout << "Not Empty";
					break;}
			
			case 6: {cout << "\n Our current Stack is :\n";
					A.display();
					break;}
			case 7: {//exit(1);
      			    break;}
      		
  		    default : {
     				 cout << "\nYou not selected any option !\n\n\n"; // giving default option!
     				}
			
		}
	}
	return 0;
}