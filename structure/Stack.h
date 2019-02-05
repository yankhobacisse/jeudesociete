//
//  Stack.h
//  mi1
//
//  Created by yankhoba cisse on 09/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#ifndef mi1_Stack_h
#define mi1_Stack_h

#include <iostream>
#include <string>
using namespace std;

template <class T=int>
class Stack {
private:
    int size;
    int top;
    T* stackTab;
    
public:
    Stack(int size=10){
        this->size=size;
        stackTab= new T [size];
        top=-1;
        
    }
    ~Stack(){
       // delete stackTab;
    }
    
    void push(const T & t){
        
        if (!isFull()) {
            stackTab[top+1]=t ;
            top++;
        }
    }
    T pop(){
        
        int tmp= top;
        
        if (isEmpty()) {
            throw "pileVide";
        }
        top--;
        return stackTab[tmp];
    }
    int isEmpty() const{
        
        return top==-1;
        
    }
    
    int isFull() const{
        return top==size-1;
    }
    
    template <class x> friend ostream & operator<<(ostream & os , const Stack<x>);
    
};

template <class x>  inline ostream & operator<<(ostream & os , const Stack<x> &pile){
    x * tmp =pile.pop();
    os<< "{ ";
    
    while (pile.isEmpty) {
        os << tmp << "; ";
    }
    
    os<< " }" << endl;
    
    return os;
}



#endif
