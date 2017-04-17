#include <iostream>
#include "ChainedMap.hpp"
#include <cstdlib>
#include <stdlib.h>
#include "dictionary.hpp"




int main()
{
    int n;
    std::cout<<"enter the number for hash function: ";
    std::cin>>n;
    cs202::ChainedMap<std::string,int> hash(n);
    std::string key;
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