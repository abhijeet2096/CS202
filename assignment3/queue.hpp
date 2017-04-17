/*
 * queue.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of queues
 * 
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"


  template <class T>
    class queue
    {
      private:
      list <T> A ;
      public:
        /*
         * Constructs a new queue.
         */
        queue(){

        }
        /*
         * Pushes t to at the back of the queue.
         */
        void push(const T& t){
            A.append(t);
        }
        /*
         * Returns the element at the front of the queue.
         * Also removes the front element from the queue.
         */
        T pop(){
          T a;
          a = A.back();
          A.remove(a);
          return a;
        }
        /*
         * Returns the element at the front of the queue.
         * Does not remove the front element.
         */
        T front(){
            return A.back();
        }
        /*
         * Returns the number of elements currently in the queue.
         */
        inline int size(){
         return A.length();
        }
        /*
         * Returns a boolean indicating whether the queue is empty or not.
         */
        bool empty(){
            return A.empty();
        }
        void display(){
            A.display();
        }
        /*
         * Destructor
         * Fress the memory occupied by the queue elements.
         */
        ~queue(){

        }
    };

#endif