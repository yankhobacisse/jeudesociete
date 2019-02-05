//
//  FiveOrMoreVar.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 06/01/14.
//  Copyright (c) 2014 Paris VII. All rights reserved.
//


#include <iostream>
#include "FiveOrMoreVar.h"
#include "./../structure/Iterateur.h"
#include "./../structure/Collection.h"
FiveOrMoreVar::FiveOrMoreVar():FiveOrMore(){
    
    score1=0;
    // Collection c();
    
    collection=new Collection();
    //Iterateur * i=collection.getIterateurCouleur();
    
    cout<<"[ ";
    
    for (int i=0; i<10; i++) {
        cout<<"   ";
        afficheCouleur(collection->getCouleurValeur(i));
        cout<<" ;";
    }
    cout<<" ]"<<endl;
    
}

FiveOrMoreVar::FiveOrMoreVar(int ligne,int colonne):FiveOrMore(ligne,colonne){
    
    score1=0;
    collection=new Collection();
    
   
}

FiveOrMoreVar::FiveOrMoreVar(const FiveOrMore &f):FiveOrMore(f){
    
    (*this)=f;
}

FiveOrMoreVar::~FiveOrMoreVar(){
    
    
}


void FiveOrMoreVar::JoueCoup(couleur joueur){
    
    
    int tmp;
    int lign ,colon;

    cout <<(*this);
    affiche_score();
    ordinateur();
    cout<<(*this);
    affiche_score();
    
    do {
         placerJetto(Vide, lign, colon);
    
    cout<< "Choisir l'indice de la couleur à retourner"<<endl;
    cout<<"[ ";
    for (int i=0; i<10; i++) {
        cout<<" ";
        afficheCouleur(collection->getCouleurValeur(i));
        cout<<" ;";
    }
    cout<<" ]"<<endl;
    
    cin>>tmp;
    
    while (!(tmp>=0 && tmp<=collection->getTaille())) {
        cout<<" l'indice n'est pas valide choisir une indice entre 0 et "<< collection->getTaille()<<endl;
        
        cin>>tmp;
    }
    
    retournerCouleur(collection->getCouleurValeur(tmp),grille[lign][colon], lign, colon);
        
        
        tmp=recuperGain();
        cout<<(*this);
        
        
        
    } while (tmp!=0);
    

    
}




