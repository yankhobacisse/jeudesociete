//
//  Puissance4var.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 06/01/14.
//  Copyright (c) 2014 Paris VII. All rights reserved.
//

#include <iostream>
#include "Puissance4Var.h"



Puissance4var::Puissance4var():Puissance4(){
    
    joueur1=Vide;
    joueur2=Vide;
    score1=0;
    score2=0;
    Stack<couleur> p1, p2;
    pileJoueur1=p1;
    pileJoueur2=p2;
    
}

Puissance4var::Puissance4var(int lign,int colonn,couleur coul1,couleur coul2,int nobCoup):Puissance4(lign,colonn,coul1,coul2){
    
    joueur1=coul1;
    joueur2=coul2;
    score1=0;
    score2=0;
    Stack<couleur> p1(nobCoup), p2(nobCoup);
    pileJoueur1=p1;
    pileJoueur2=p2;
    nbCoup=nobCoup;
    
    for (int i=0; i<nobCoup; i++) {
        pileJoueur1.push(coul1);
        pileJoueur2.push(coul2);
    }
    
}
Puissance4var::~Puissance4var(){
   
    
    
}

Puissance4var::Puissance4var(const Puissance4var &unAutre):Puissance4(unAutre){
    (*this)=unAutre;
}

bool Puissance4var::fini(){
    
    if (pileJoueur1.isEmpty() && pileJoueur2.isEmpty()) {
        
        return true;
    }
    
    if (estRempli()) {
        return true;
    }
    
   
    return false;
}
 void Puissance4var::JoueCoup(couleur joueur){
     if (joueur==joueur1) {
      
      joueur=pileJoueur1.pop();
      }
      else
      joueur=pileJoueur2.pop();
     
     Puissance4::JoueCoup(joueur);
}

