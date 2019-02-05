//
//  Collection.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 20/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_Collection_h
#define PlateauDeJeau_Collection_h
#include "./../Plateau/ListeCouleur.h"
using namespace ListeCouleur;

class Collection {

public:
  /*  Collection(){
        
        for (int i=0; i<10; i++) 
            valeurs[i] = 'A'+i;
    
 }*/
    Collection(){
        couleur tableauCouleur [7]={Blanc,Noir, Rouge, vert, Bleu ,Cyan,Magenda};
        valeurs= new couleur[7];
        taille=7;
        
        for (int i=0; i<7; i++) 
           valeurs[i] = tableauCouleur[i];
       
    }

    
    ~Collection(){
        delete [] valeurs;
    }
    int getTaille()const{
        return taille;
    }
    couleur getCouleurValeur(int i){
        return valeurs[i];
    }
    
    //friend class FiveOrMore;
   // friend class FiveOrMoreVar;
private:
    int taille;
    couleur *valeurs;
    };
#endif
