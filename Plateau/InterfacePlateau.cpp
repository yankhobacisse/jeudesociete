//
//  InterfacePlateau.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 19/01/14.
//  Copyright (c) 2014 Paris VII. All rights reserved.
//

#include <iostream>
#include "InterfacePlateau.h"

InterfacePlateau::InterfacePlateau(){
    joueur1=Vide;
    joueur2=Vide;
}

InterfacePlateau::InterfacePlateau(couleur joueur1,couleur joueur2){
    this->joueur1=joueur1;
    this->joueur2=joueur2;
}
InterfacePlateau::InterfacePlateau(const InterfacePlateau& p){
    joueur1=p.joueur1;
    joueur2=p.joueur2;
    
}
InterfacePlateau::~InterfacePlateau(){
    
}


void InterfacePlateau::jouer(couleur joueur){
    
    initialier();

   
    while (!fini()) { 
        cout<< "c'est au joueur " ;
        afficheCouleur(joueur);
        cout<< " de jouer" << endl;
        JoueCoup(joueur);
        if (joueur==joueur1) {
            joueur=joueur2;
        } else 
            joueur=joueur1;
    } 
     affiche_score();
}
