#include <iostream>
#include "DoubleHashMap.hpp"
#include <cstdlib>
#include <stdlib.h>
#include "dictionary.hpp"




int main()
{
    int n;
    std::string k_max,k_min;
    int v_max,v_min; 

    std::cout<<"enter the number for hash function: ";
    std::cin>>n;
    
    std::string key;

    std::cout<<"enter the marker for hash table: MAX and MIN ! ";
    std::cin >> k_max;
     std::cin>> k_min;
     std::cin >> v_max;
     std::cin  >> v_min;
   cs202::DoubleHashMap<std::string,int> hash(n);
    hash.ChangeMarker(k_max,k_min,v_max,v_min);
    int value;
    int choice;

    while (1)
    {
        std::cout<<"1.Insert element into the table\n2.Search element from the key\n3.Delete element at a key\n4.Print elements\n5.Exit"<<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            std::cout<<"Enter element to be inserted: ";
            std::cin>>value;
            std::cout<<"Enter key at which element to be inserted: ";
            std::cin>>key;
            hash.put(key, value);
            break;
        case 2:
            std::cout<<"Enter key of the element to be searched: ";
            std::cin>>key;
            std::cout<<"Element at key "<<key<<" : ";
            if (!hash.has(key))
            {
	        std::cout<<"No element found at key "<<key<<std::endl;
            continue;
	     
	        }
            std::cout<<hash.get(key)<<std::endl;
            break;
        case 3:
            std::cout<<"Enter key of the element to be deleted: ";
            std::cin>>key;
            hash.remove(key);

            break;
        case 4:hash.print();break;
            
        case 5:exit(1);
        default:
           std::cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}