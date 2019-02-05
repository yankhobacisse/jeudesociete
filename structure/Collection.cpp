//
//  Collection.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 19/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#include <iostream>

#include "Iterateur.h"
/*Collection::Collection(){
    
    for (int i=0; i<10; i++) {
        valeur[i]='A'+i;
    }
 }*/


class Collection {
private:
    char valeurs[10];
    class IterateurCouleur: public Iterateur {
    private:
        Collection *collection;
        int i;
    public:
        IterateurCouleur(Collection *c):collection(c), i(9) {}
        
        char nexElement() { 
            return collection->valeurs[i--]; 
        }
        bool alaFin() { 
            return i==-1; 
        }
        //char  elementAt(int i){
        //     return collection->valeurs[i];
        // }
        
    };
public:
    Collection() {
        for (int i=0; i<10; i++) 
            valeurs[i] = 'A'+10;
    }
    Iterateur *getIterateurCouleur(){
        return new IterateurCouleur(this);
    }
};
