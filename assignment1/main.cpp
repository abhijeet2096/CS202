/*
Abhijeet Sharma
B15102
main file
*/
//libraries

#include <iostream>
#include "seqLinearList.hpp"
#include "seqLinearList.cpp"
#include "sorting.hpp"
#include "sorting.cpp"
#include "timer.hpp"
#include "timer.cpp"
#include <stdlib.h>
#include <time.h>


int main(){

//variables
int MaxSize,inputSize;
int temp,option;
int low,high;
clock_t start,end;

system("clear");
cout << "Please Enter the Max size of our LinearList "<< endl;
cin >> MaxSize;
cout << "Please Enter the input size of our LinearList "<< endl;
cin >> inputSize;

//creating objects
LinearList <int> MyObject =  LinearList <int>(MaxSize);
Sort <int> MySortObject;


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

//Making A copy of object 
LinearList <int> MyObjectCopy = MyObject;
cout << "Copying...\n";
MyObjectCopy.display(1,inputSize);

//giving options
while(1){
	cout << " Please select below methord for Sorting of these Numbers";
	cout << "\n\n1. Insertion Sort. \n\n";
	cout << "2. Bubble Sort.\n\n";
	cout << "3. Rank Sort.\n\n";
	cout << "4. Selection Sort.\n\n";
	cout << "5. Exit.\n\n";
	cin >> option;
	switch(option){
   case 1  :
   	  cout << "Please Select Starting and ending positions ?";
   	  cin >> low >> high;
   	  start=clock_return();
      MySortObject.insertionSort(MyObject,low,high);  
      end=clock_return();
      cout<< "\n\n\nInsertion Sort Result\n\n";  // Insertion Sort !
	  MyObject.display(low,high);
	  cout << "\nExceution Time " << ((double)(end -start)/CLOCKS_PER_SEC)*1000 ;
 	  cout<< "\n\n\n";
      MyObject=MyObjectCopy;
      break; 
   case 2  :
   	  cout << "Please Select Starting and ending positions ?";
   	  cin >> low >> high;
   	  start=clock_return();
      MySortObject.bubbleSort(MyObject,low,high);
      end=clock_return();
      cout<< "\n\n\nBubble Sort Result\n\n";   // Bubble Sort 
	  MyObject.display(low,high);
	  cout << "\nExceution Time " << ((double)(end -start)/CLOCKS_PER_SEC)*1000 ;
	  cout<< "\n\n\n";
      MyObject=MyObjectCopy;
      break; 
   case 3 :
   	  cout << "Please Select Starting and ending positions ?";
   	  cin >> low >> high;
   	  start=clock_return();
   	  MySortObject.rankSort(MyObject,low,high);
   	  end=clock_return();
   	  cout<< "\n\n\nRank Sort Result\n\n";    // Rank Sort
	  MyObject.display(low,high);
	  cout << "\nExceution Time " <<((double)(end -start)/CLOCKS_PER_SEC)*1000 ; //calculatings time
	  cout<< "\n\n\n";
   	  MyObject=MyObjectCopy;
   	  break;
   case 4 :
   	  cout << "Please Select Starting and ending positions ?";
   	  cin >> low >> high;
   	  start=clock_return();
   	  MySortObject.selectionSort(MyObject,low,high);  //Selection Sort
   	  end=clock_return();
   	  cout<< "\n\n\nSelection Sort Result\n\n";
	  MyObject.display(low,high);
	  cout << "\nExceution Time " << ((double)(end -start)/CLOCKS_PER_SEC)*1000;
	  cout<< "\n\n\n";
   	  MyObject=MyObjectCopy;
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