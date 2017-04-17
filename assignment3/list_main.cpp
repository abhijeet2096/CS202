/**************************
*Name: Abhijeet sharma
*Date: 20/03/2017
*Roll No. B15102
*********************/
#include "list.hpp"


int main(){
	list <int> A = list <int> ();
	list <int> B = list <int> ();
	B.append(1);
	B.append(2);
	B.append(3); 
	int option;
	int data;
	while(1){
		cout << "\nPlease Select one of the option below";
		cout << "\n1.Insert(*in front*)\n2.Delete\n3.Append a List\n4.Lenght\n5.Isempty\n6.Insert(*Adds element but in front*)\n7.Display\n8.Exit";
		cin >> option;
		switch(option){
			case 1: {cout << "please enter value you want to insert?";
				   cin >> data;
				 																																																																							  A.append(data);
				   break;}

			case 2:{
				   cout << "\nplease enter value you want to delete?";
				   cin >> data;
				   A.remove(data);
				   break;}
			case 3:{
				   cout << "\nAppending a list of (1,2,3) to show working of function?";
				   //list <int> B = A;
				   A.append(B);
				   break;}
			case 4: {cout << "\nThe Lenght of our List is:";
					cout << A.length() ;
					break;}

			case 5: {if(A.empty()==1)
						cout << "Yes Empty";
					else
						cout << "Not Empty";
					break;}
			case 6:	{cout << "\nplease enter value you want to insert?\n";
				    cin >> data;
				    A.cons(data);
					break;}
			case 7: {cout << "\n Our current Linked List :\n";
					A.display();
					break;}
			case 8: {//exit(1);
      			    break;}
      		case 9: {cout << "\n Our current Linked List :\n";
					B.display();
					break;}
  		    default : {
     				 cout << "\nYou not selected any option !\n\n\n"; // giving default option!
     				}
			
		}
	}
	return 0;
}