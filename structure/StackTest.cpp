//
//  StackTest.cpp
//  mi1
//
//  Created by yankhoba cisse on 09/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#include <iostream>
#include "Stack.h"


int main(){
    
    Stack<> pileEntier;
    
    for (int i=0; i<10; i++) {
        pileEntier.push(i );
    }
    
    
    cout<< "{ ";
    
    while (!pileEntier.isEmpty()) {
        cout << pileEntier .pop()<< "; ";
    }
    
    cout<< " }" << endl;
    
    Stack< char> pileChar;
    
    for (int i=0; i<10; i++) {
        pileChar.push('a'+i);
    }
    
    cout<< "{ ";
    
    while (!pileChar.isEmpty()) {
        cout << pileChar.pop()<< "; ";
    }
    
    cout<< " }" << endl;
    
    return 0;

}

