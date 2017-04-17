// Driver Program for testing `seqLinearList` class
// Author: Abhijeet Sharma
// Roll Number: B15102
#include <iostream>
#include "seqLinearList.hpp"
#include "seqLinearList.cpp"


int main(int argc, char const *argv[]){

//variables
int MaxSize,inputSize;
int temp,option;


system("clear");
cout << "Please Enter the Max size of our LinearList "<< endl;
cin >> MaxSize;
cout << "Please Enter the input size of our LinearList "<< endl;
cin >> inputSize;

//creating objects
LinearList <int> MyObject =  LinearList <int>(MaxSize);

//Taking inputs
cout << "Please enter elements of the linear list  "<< endl;
for (int i = 1; i <=inputSize; i++){

	cin >> temp;
	 
	MyObject.insert(i,temp);
}
MyObject.display(1,inputSize);
/*MyObject.deleteElement(2,temp);
MyObject.display();
temp=3;
cout << "Search:" << MyObject.search(temp)<<endl;
cout << "Find:" << MyObject.find(2,temp)<<endl;
cout << "returnListElement" <<MyObject.returnListElement(2);*/

//giving options
while(1){
	cout << " Please select below methord for Sorting of these Numbers";
	cout << "\n\n1. Insert \n\n";
	cout << "2. Bubble Sort.\n\n";
	cout << "3. Rank Sort.\n\n";
	cout << "4. Selection Sort.\n\n";
	cout << "5. Exit.\n\n";
	cin >> option;
	switch(option){
   case 1  :
   	  
      break; 
   case 2  :
   	 
      break; 
   case 3 :
   	  
   	  break;
   case 4 :
   	  
      break;
   case 5 :
   	  
      exit(1);
      break;
   default : 
      cout << "You not selected any option !\n\n\n"; // giving default option!
  }
}
return 1;
}