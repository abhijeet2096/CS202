/*
Submitted by:- Abhijeet Sharma
Roll No.- B15102
*/

#include "dictionary.hpp"
#include <typeinfo>
#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_



namespace cs202
{
const int SIZE= 1;
const int DEFAULT_VALUE =-1;

    template<class Key, class Value>			//template variables
    class ChainedMap;    
  template<class Key, class Value> 
    class ChainNode
    {
        friend  ChainedMap<Key,Value>;
        
        private:
        Key key;
        Value value;
        ChainNode<Key,Value>*link;
        ChainNode(Key key,Value value){
            
            this->key = key;
            this->value = value;
            this->link = NULL;

        }
    };


template<class Key, class Value>
class ChainedMap: public Dictionary<Key,Value>
{
    private:    
    ChainNode<Key,Value>** H,**J;   
    int no;
    int hash(int key);
     int hash(std::string key);
     int  rehash();
public:
    /*.
     * Constructor: ChainedMap
     * Creates a Chained Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	ChainedMap();
    /*
     * Constructor:ChainedMap
     * Creates an empty Chained Map with the ability to hold atleast num Key value pairs.
     */
	ChainedMap(const int& num);
    /*
     * Constructor: Chained Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	ChainedMap(ChainedMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~ChainedMap();

 
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * ChainedMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
     void print();
     bool has(const Key& key);
     Value get(const Key& key);

     void remove(const Key& key);

     void put(const Key& key, const Value& value);  



	Value& operator[](const Key& key);
};
    




    template<class Key, class Value>int ChainedMap<Key,Value> :: hash(int key){
        return key % no;

    }
    template<class Key, class Value>int ChainedMap<Key,Value> :: hash(std::string key){
        int sum=0;
        int x=33;
        int i=0,count=key.length();
        for (int i = 0; i < count; ++i)
        {
        	sum=sum*x+key[i];
        }
        //std::cout << sum;
        return (int)sum%no;
    }
    /*template<class Key, class Value>int ChainedMap<Key,Value> :: rehash(){
        int i,j,k;
       k=2*no;
        J = new ChainNode<Key,Value>*[num];
            for (i = 0; i < k; i++)
                J[i] = NULL;
        
         

    }
*/
     template<class Key, class Value>ChainedMap<Key,Value> :: ChainedMap(){
         int i;
         H = new ChainNode<Key,Value>*[SIZE];
            for (int i = 0; i < SIZE; i++)
                H[i] = NULL;

     }

     template<class Key, class Value>ChainedMap<Key,Value> :: ChainedMap(const int& num){
            no=num;
         int i;
         H = new ChainNode<Key,Value>*[num];
            for (int i = 0; i < num; i++)
                H[i] = NULL;

     }

     template<class Key, class Value>ChainedMap<Key,Value> :: ~ChainedMap(){
          int i;
          for (i = 0; i < no; ++i)
            {
                ChainNode<Key,Value>* p = H[i];
                while (p != NULL)
                {
                   ChainNode<Key,Value>* prev = p;
                    p= p->link;
                    delete p;
                }
            }
            delete[] H;
     }

     template<class Key, class Value>bool ChainedMap<Key,Value> :: has(const Key& key)
     {

            
            bool flag = false;
            int hash_val = hash(key);
            ChainNode<Key,Value>* p = H[hash_val];
            while (p != NULL)
            {
                if (p->key == key)
                {
                    return true;
                   // flag = true;
                }
               p = p->link;
                }
            if (!flag)
                return false;
            

           
     }


     template<class Key, class Value>Value ChainedMap<Key,Value> :: get(const Key& key){

          bool flag = false;
            int hash_val = hash(key);
            ChainNode<Key,Value>* p = H[hash_val];
            while (p != NULL)
            {
                if (p->key == key)
                {
                    return p->value;
                    flag = true;
                }
               p = p->link;
                }
            if (!flag)
                return false;
            

    }



     template<class Key, class Value>void ChainedMap<Key,Value> :: remove(const Key& key)
     {
        
       
            int hash_val = hash(key);
            if (H[hash_val] != NULL)
            {
                ChainNode<Key,Value> *p = H[hash_val];
                ChainNode<Key,Value> *prev = NULL;
                while (p->link != NULL && p->key != key)
                {
                    prev = p;
                    p = p->link;
                }
                if (p->key == key)
                {
                    if (prev == NULL)
                    {
                        ChainNode<Key,Value> *link = p->link;
                        delete p;
                        H[hash_val] = link;
                    }
                    else
                    {
                        ChainNode<Key,Value> *link = p->link;
                        delete p;
                        prev->link = link;
                    }
                }
            }
            
     }



     template<class Key, class Value>void ChainedMap<Key,Value> :: put(const Key& key, const Value& value)
     {
        
            int index = hash(key);
           
            ChainNode<Key,Value>* first = H[index];
            ChainNode<Key,Value>* last = H[index];
            while(last){
                last=last->link;
            }
            /*
            if(!has(key)){

            ChainNode<Key,Value> *p = new ChainNode<Key,Value>;
            p->key=key;
            p->value = value;

            p->link = NULL;
            if (first) {
                last->link = p;   
            }
            else 
            {
                first = p; 
            }           

                last = p;*/
            int hash_val = hash(key);
            ChainNode<Key,Value>* prev = NULL;
            ChainNode<Key,Value>* p = H[hash_val];

            if(!has(key)){

            while (p != NULL)
            {
                prev = p;
                p = p->link;
            }
            if (p == NULL)
            {
                p = new ChainNode<Key,Value>(key, value);
                if (prev == NULL)
            {
                    H[hash_val] = p;
                }
            else
            {
                    prev->link = p;
                }
            }
            else
            {
                p->value = value;
            }

        }
        else
        {
            ChainNode<Key,Value>*current=first;
            
            while(current->key!=key)
            {
                current=current->link;
            }
            current->value = value;
            
        }


        
     }   


    template<class Key, class Value>Value& ChainedMap<Key,Value> :: operator[](const Key& key)
     {

   if(has(key))
    {
            int index = hash(key);

            ChainNode<Key,Value>*current=H[index];
   
            while(current->key!=key || current==0)
            {
                current=current->link;
            }
           
            return current->value;
    }    
    else
    {
        put(key,DEFAULT_VALUE);
        int index = hash(key);

            ChainNode<Key,Value>*current1=H[index];
   
            while(current1->key!=key || current1==0)
            {
                current1=current1->link;
            }
           
            return current1->value;
    }


    }

    template<class Key,class Value> void ChainedMap<Key,Value> :: print()
    {

        int i;
        for(i=0;i<no;i++){
         ChainNode<Key,Value>* first = H[i];
         ChainNode<Key,Value>*current=first;
            std::cout<<"Key:"<<i<<"->";
       while(current)
       {

            std::cout<<current->value<<"->";
            current=current->link;
       }
       std::cout<<std::endl;
      

        }
    }
      

    



}

#endif /* CHAINEDMAP_HPP_ */