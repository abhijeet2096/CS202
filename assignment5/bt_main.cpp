#include <iostream>
#include <stdlib.h>
#include "BinaryTree.hpp"




int main()
{
    
    int choice;
    BSTree : BinaryTree <int,int> Myobject;
    int value,temp5;
    int key;

    while (1)
    {
        std::cout<<"1.Insert element into the table\n2.Search element from the key\n3.Delete element at a key\n4.Give Value At given key\n5.Print In Order\n6.Print Pre Order";
        std::cout<<" \n7.Print Post Order\n8.Minimum Element\n9.Maximum Element\n10.Succesor\n11Predecessor\n12.Display\n13.Exit"<<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            std::cout<<"Enter element to be inserted: ";
            std::cin>>value;
            std::cout<<"Enter key at which element to be inserted: ";
            std::cin>>key;
            Myobject.put(key, value);
            break;
        case 2:
            std::cout<<"Enter key of the element to be searched: ";
            std::cin>>key;
            if (!Myobject.has(key))
                std::cout<<"No Element Present" << std::endl;
            else    
                std::cout<<"Element Present"<<std::endl;
            break;
        case 3:
            std::cout<<"Enter key of the element to be deleted: ";
            std::cin>>key;
            Myobject.remove(key);
            std::cout << "Succesfully Removed" << std::endl;
            break;
        case 4:
            std::cout<<"Enter key at which element to be Found: ";
            std::cin>>key;
           temp5=Myobject.get(key);
            if(temp5!=Default_value)
        	    std::cout <<  "\nValue At Given Key is :" << temp5<<  "\n"<< std::endl;
        	else
        		std::cout << "No Key Exist !" << std::endl;
            break;
        
        case 5:
            std::cout << "Below is the Inorder of our Binary Tree\n" << std::endl;
            Myobject.print_in_order();
            std::cout << " \n" << std::endl;
            break;
        case 6:
            std::cout << "Below is the Preorder of our Binary Tree\n" << std::endl;
            Myobject.print_pre_order();
            std::cout << " \n" << std::endl;
            break;
        case 7:
            std::cout << "Below is the Posteorder of our Binary Tree\n" << std::endl;
            Myobject.print_post_order();
            std::cout << " \n" << std::endl;
            break;
        case 8:
            std::cout << "Minimum Value of our Binary Tree\n" << std::endl;
            std::cout << Myobject.minimum() << std::endl;
            break;
        case 9:
            std::cout << "Maximum Value of our Binary Tree\n" << std::endl;
            std::cout << Myobject.maximum() << std::endl;
            break;
        case 10:
            std::cout<<"Enter key for which Succesor is to be Found: ";
            std::cin>>key;
            std::cout << "Succesor of given key of our Binary Tree\n" << std::endl;
            std::cout << Myobject.successor(key) << std::endl;
            break;
        case 11:
            std::cout<<"Enter key for which predecessor is to be Found: ";
            std::cin>>key;
            std::cout << "predecessor of given key of our Binary Tree\n" << std::endl;
            std::cout << Myobject.predecessor(key) << std::endl;
            break;
        case 12:
        	std::cout << "Below is our Binary Tree:\n" << std::endl;
        	Myobject.display_fake();
        	break;
        case 13:
            exit(1);
        
        default:
            std::cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}