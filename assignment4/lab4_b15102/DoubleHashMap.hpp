/*
Submitted by:- Abhijeet Sharma
Roll No.- B15102
*/
#include <limits.h>
#ifndef DoubleHashMap_HPP_
#define DoubleHashMap_HPP_


namespace cs202
{
template<class Key, class Value>
class DoubleHashMap  //: public Dictionary<Key,Value>
{
    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */

    unsigned int capacity;
    void rehash();
    int hash(int key);
    int hash(std::string key);
    Key* key_array;
    Value* value_array;
     Key marker;//marker
    Key marker1;//marker1
    Value marker2;
    Value marker3;
    int dhash(int key);
    int dhash(std::string key);
    
    public:
    /*
     * Constructor: DoubleHashMap
     * Creates a Open Hash Table with some default size.
     * capacityTE: Please try to ensure that the size is a prime number for better performance.
     */
    DoubleHashMap();
      
          
    
    /*
     * Constructor:DoubleHashMap
     * Creates an empty Open Map with the ability to hold atleast num Key value pairs.
     */
    DoubleHashMap(const int& num);
    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
    DoubleHashMap(DoubleHashMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
    ~DoubleHashMap();
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * DoubleHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
    void ChangeMarker(Key k_max,Key k_min,Value v_max,Value v_min);
      bool has(const Key& key);
     Value get(const Key& key);
     int  prime(int n1);
     void remove(const Key& key);
    void  print();
     void put(const Key& key, const Value& value);  
	void resize(const int& n);


    Value& operator[](const Key& key);
};
	
	template<class Key, class Value> void DoubleHashMap<Key,Value> :: ChangeMarker(Key k_max,Key k_min,Value v_max,Value v_min){

		marker = k_max;
		std::cout << marker;
		marker1= k_min;
		std::cout << marker1;
		marker2=v_max;
		std::cout << marker2;
		marker3=v_min;
		std::cout << marker3;
		int i;
            //capacity = 11;
            key_array=new Key[11];
            value_array=new Value[11];
            
            for(i=0;i<11;i++){
                key_array[i]=marker;
                value_array[i]=marker2;
              }
	}
  template<class Key, class Value>DoubleHashMap<Key,Value> :: DoubleHashMap(){
            int i;
            capacity = 11;
            key_array=new Key[11];
            value_array=new Value[11];
            std::cout << "Default Constructor" << std::endl;
            for(i=0;i<11;i++){
                key_array[i]=marker;
                value_array[i]=marker2;
              }
            
           
  }
     template<class Key, class Value>int DoubleHashMap<Key,Value> :: dhash(int key){
        
        return (5-(key%5));

    }
    template<class Key, class Value>int DoubleHashMap<Key,Value> :: dhash(std::string key){
        
        return (5-(hash(key)));

    }


    template<class Key, class Value>int DoubleHashMap<Key,Value> :: hash(int key){
        
    
        return key % capacity;

    }

    template<class Key, class Value>int DoubleHashMap<Key,Value> :: hash(std::string key){
        int sum=0;
        int x=33;
        int i=0,count=key.length();
        for (int i = 0; i < count; ++i)
        {
        	sum=sum*x+key[i];
        }
        //std::cout << sum;
        return (int)sum%capacity;
    }

    
    template<class Key, class Value>DoubleHashMap<Key,Value> :: ~DoubleHashMap(){

            delete []key_array;
            delete []value_array;
  
  }
  template<class Key, class Value>void DoubleHashMap<Key,Value> :: resize(const int& n){


        
        Key* buffer1 = new Key[n];
        Value* buffer2=new Value[n];
       for(int i=0;i<n;i++)
       {

            buffer1[i]=marker;
            buffer2[i]=marker2;
       }

       for(int i=0;i<capacity-1;i++)
       {

            buffer1[i]=key_array[i];
            buffer2[i]=value_array[i];
       }
        
        delete[] key_array;
        delete[] value_array;

        key_array=buffer1;
        value_array=buffer2;
         capacity = n;
     
}

    template<class Key, class Value>void DoubleHashMap<Key,Value> :: rehash()
    {
           
        int i,j;
        capacity=capacity+1;
        //std::cout<<capacity;
        int p;
        p=prime(capacity);
         //std::cout<<p;
       resize(p);
        Key* key_array1 = new Key[capacity];
        Value* value_array1=new Value[capacity];
        
        
        for(i=0;i<capacity;i++)
        {
          key_array1[i]=key_array[i];
          key_array[i]=marker;
          value_array1[i]=value_array[i];
          value_array[i]=marker2;
        }
        
        for(j=0;j<capacity;j++)
        {
          if(key_array1[j]!=marker&&key_array1[j]!=marker1)
          {
              put(key_array1[j],value_array1[j]);

          }
        }

        


    }


     template<class Key, class Value>int DoubleHashMap<Key,Value> :: prime(int n1)
    { 
        bool flag;
        for(int i = n1; ; i++){
          flag = true;
          for(int j = 2; j <= n1/2 && flag; j++){
            if(!(i % j))
              flag = false;
          }

          if(flag){

            return i;
          }
        }

        
    } 




     template<class Key, class Value>DoubleHashMap<Key,Value> :: DoubleHashMap(const int& num){
          
           int i;
            capacity = prime(num);
            key_array=new Key[capacity];
            value_array=new Value[capacity];
            std::cout << "Overloaded Constructor" << std::endl;
            for(i=0;i<capacity;i++){
                key_array[i]=marker;
                value_array[i]=marker2;
              }
          
     }

   

     template<class Key, class Value>bool DoubleHashMap<Key,Value> :: has(const Key& key)
     {
      
        int i=0;
        int index = hash(key);
         int offset=dhash(key);
         //std::cout<<"offset: "<<offset;
           while(key_array[index]!=marker && i<capacity)
           {
                if(key_array[index]==key)
                    return true;
                else{
                    index=hash(index+offset);
                    i++;   } 
           }
           if(i==capacity || key_array[index]==  marker)
                return false;
     }


     template<class Key, class Value>Value DoubleHashMap<Key,Value> :: get(const Key& key)
     {
    
        int i=0;
       int offset=dhash(key);
        int index = hash(key);
           while(key_array[index]!=marker && i<capacity)
           {
                if(key_array[index]==key)
                    return value_array[index];
                else{
                    index=index+offset;
                    index=hash(index);
                    i++;}    
           }
           if(i==capacity || key_array[index]==  marker)
                return -1;
            
    }



     template<class Key, class Value>void DoubleHashMap<Key,Value> :: remove(const Key& key)
     {
        int i;
         int offset=dhash(key);
        int index = hash(key);
           while(key_array[index]!=marker && i<capacity)
           {
                if(key_array[index]==key){
                    key_array[index]=   marker1;
                    value_array[index]=marker3;
                  }
                else{
                    index=hash(index+offset);
                    i++;}    
           }
           if(i==capacity || key_array[index]==  marker)
                return ;
       
     }



     template<class Key, class Value>void DoubleHashMap<Key,Value> :: put(const Key& key, const Value& value)
     {
         int i=0;
          int offset=dhash(key);
          //std::cout<<"offset: "<<offset;
          int index = hash(key);
         //std::cout<<capacity<<std::endl;
        if(!has(key)){
          
           while((key_array[index]!= marker) && (i<capacity)) 
           {
            if(key_array[index]==marker1)
            {
            key_array[index]=key;
            value_array[index]=value;
            return;

            }

            index=hash(index+offset);
            i++;
           }


           if(i==capacity)
           {
            rehash();
            put(key,value);
           }
           else{

            key_array[index]=key;
            value_array[index]=value;

           }
        }   
        else{
            int index = hash(key);
            int offset=dhash(key);

            while(key_array[index]!= key) 
           {
            index=hash(index+offset);
            
           }
           value_array[index]=value;


           }
            
        
     }   


    template<class Key, class Value>Value& DoubleHashMap<Key,Value> :: operator[](const Key& key)
     {

        int i=0;
        int index = hash(key);
        int offset= dhash(key);
        if(has(key))
        {
            
           while(key_array[index]!=marker && i<capacity)
           {
                if(key_array[index]==key)
                    return value_array[index];
                else{
                    index=hash(index+offset);
                    i++;   } 
           }            

        }    
        else
        {
            put(key,marker);
             while(key_array[index]!=marker && i<capacity)
           {
                if(key_array[index]==key)
                    return value_array[index];
                else{
                    index=hash(index+offset);
                    i++;}    
           }    
       
        }

    }


    template<class Key, class Value>void DoubleHashMap<Key,Value> :: print()
    {
      int i;
      std::cout << "Capacity :" << capacity << std::endl;
      for(i=0;i<capacity;i++)
      {
        std::cout<<key_array[i]<<"\t"<<value_array[i]<<std::endl;
      }
  }


}

#endif 