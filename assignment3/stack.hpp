/* 
 * stack.hpp
 * 
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of stacks
 * 
 */

#ifndef STACK_HPP_
#define STACK_HPP_
#include "list.hpp"


  template<typename T>
    class stack
    { 
    private:
    list <T> A ;
      public:
        /*
         * Constructs a new stack.
         */
        stack(){

        }
        /*
         * Pushes t to on the top of the stack.
         */
        void push(const T& t){
            A.cons(t);
        }
        /*
         * Returns the element at the top of the stack.
         * Also removes the top element from the stack.
         */
        T pop(){
          T a;
          a = A.front();
          A.remove(a);
          return a;}
        /*
         * Returns the element at the top of the stack.
         * Does not remove the top element.
         */
        T top(){
            return A.front();
        }
        /*
         * Returns the number of elements currently in the stack.
         */
        int size(){
            return A.length();
        }
        void display(){
            A.display();
        }
        /*
         * Returns a boolean indicating whether the stack is empty or not.
         */
        bool empty(){
            return A.empty();
        }
        /*
         * Destructor
         * Fress the memory occupied by the stack elements.
         */
        ~stack(){
            
        }
    };


#endif