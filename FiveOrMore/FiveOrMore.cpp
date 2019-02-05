//
//  FiveOrMore.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 18/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#include <iostream>
#include "FiveOrMore.h"
#include "./../structure/Iterateur.h"
#include "./../structure/Collection.h"
FiveOrMore::FiveOrMore():Plateau(){
    
    score1=0;
    // Collection c();
    
    collection=new Collection();
    //Iterateur * i=collection.getIterateurCouleur();
    
    cout<<"[ ";
    
    for (int i=0; i<collection->getTaille(); i++) {
        cout<<"   ";
        afficheCouleur(collection->getCouleurValeur(i));
        cout<<" ;";
    }
    cout<<" ]"<<endl;
    
}

FiveOrMore::FiveOrMore(int ligne,int colonne):Plateau(ligne,colonne,Vide,Vide){
    
    score1=0;
    collection=new Collection();
    
    //cout<<random_0_9();
}

FiveOrMore::FiveOrMore(const FiveOrMore &f):Plateau(f){
    
    (*this)=f;
}

FiveOrMore::~FiveOrMore(){
    delete collection;
    
    
}
ostream & FiveOrMore::affiche(ostream & out) const{
    
    //Iterateur * i=collection.getIterateurCouleur();
    
    cout<<"[ ";
    for (int i=0; i<collection->getTaille(); i++) {
        cout<<"   ";
        afficheCouleur(collection->getCouleurValeur(i));
        cout<<" ;";
    }
    cout<<" ]"<<endl;
    out<< "Score :"<<score1 <<endl;
    return Plateau::affiche(out);
}

ostream & operator<<(ostream &out,const FiveOrMore & f){
    
    return  f.affiche(out);
}

int FiveOrMore::random_0_9(int a,int b){
    
    //srand((unsigned int)time(NULL));
     srand(static_cast<unsigned int>(time(0)));
    return rand()%(b-a)+a;
   ; 
  
    
}

bool FiveOrMore::fini(){
    
   
    /* for (int i=0; i<ligne; i++) {
     for (int j=0; j<colonne; j++) {
     if (grille[i][j]==Vide) {
     return false;
     }
     }
     }*/
    if(estRempli()){
        return true;
    }
    
    return false;
    
    cout<< " votre score finile : " << score1<<endl;
    
    //return true;
    
}
bool FiveOrMore::chemin(int x1,int y1,int x2,int y2){
    
    bool drapeau=false;
    
    if (x1==x2 && y1==y2) {
        return false;
    }
    
    for (int direcLigne=-1; direcLigne<=1; direcLigne++) {
        for (int directColone=-1; directColone<=1;directColone ++) {
            
            
            if (direcLigne!=0 or directColone!=0) {
                if (grille[x1][y1]!=Vide) {
                    
                    drapeau=Plateau::chemin(x1, y1, x2, y2, direcLigne, directColone);
                    cout <<drapeau;
                } 
                if (drapeau) {
                    return true;
                }
            }
            
        }
    }
    return drapeau;
    
}

bool FiveOrMore::deplacement(int x1,int y1,int x2,int y2){
    if (!caseExiste(x1, y1)&&caseExiste(x2, y2)) {
        return false;
    }
    
    if (grille[x1][y1]==Vide) {
        return false;
    }
    if (chemin(x1, y1, x2, y2) && grille[x2][y2]==Vide) {
        
        //cout<< "chemin"<<endl;
        
        grille[x2][y2]=grille[x1][y1];
        grille[x1][y1]=Vide;
        return true;
    }
    
    return false;
}

bool FiveOrMore::coupValideOrdinateur(int ligne,int colonne){
    
    return caseExiste(ligne, colonne)&& grille[ligne][colonne]==Vide;
    
}

bool FiveOrMore::coupValide(int ligne,int colonne){
    return caseExiste(ligne, colonne)&& grille[ligne][colonne]!=Vide;
    
}
void FiveOrMore::affiche_score( ){
    
    cout <<" Score : "<<score1<<endl;
}

void FiveOrMore::ordinateur(){
    
    // Iterateur * i=collection->getIterateurCouleur();
    
    int lign;
    
    int colon;
    int tmp;
    for (int k=0; k<3; k++) {
        
        lign=random_0_9(0,ligne+3);
        colon=random_0_9(0,colonne+3);
        
        while (!coupValideOrdinateur(lign, colon)) {
            lign=random_0_9(0,ligne+3);
            colon=random_0_9(0,colonne+3);
          
        }
        do {
            tmp=random_0_9(0,collection->getTaille()+3);
        } while (tmp<0 or tmp>(collection->getTaille()-1));
        grille[lign][colon]= collection->getCouleurValeur(tmp);
    }
    
}



int FiveOrMore::recuperGain(){
    
    int gain;
    int nombrePiont=0;
    //Iterateur * I=collection->getIterateurCouleur();
    //while (I->alaFin()) {
    for (int k=0; k<collection->getTaille(); k++) {
        
        for (int i=0; i<ligne; i++) {
            for (int j=0; j<colonne; j++) {
                
                for (int direcLigne=-1; direcLigne<=1; direcLigne++) {
                    for (int directColone=-1; directColone<=1;directColone ++) {
                        
                        gain=eliminerGainPoint( collection->getCouleurValeur(k) , i, j, direcLigne, directColone, 5);
                        if (gain>0) {
                            score1+=gain*(gain+1)/3;
                            nombrePiont++;
                        }
                    }
                }
            }
        }
        
    }
    return nombrePiont; 
}

void FiveOrMore::placerJetto(couleur jetton, int &lign,int &colonn){
    
    Plateau::placerJetto(jetton, lign, colonn);
    
    while (!coupValide(lign, colonn)) { 
        cout<<"Ce coup n'est pas valide"<<endl; 
        cout<<"Choisissez une autre case colone ligne :"<<endl;; 
        
        cin>>colonn;
        colonn--;
        cin>>lign;
        lign--; 
    } 
    
}

void FiveOrMore::JoueCoup(couleur joueur){
    int ligne, colone;
    int lign ,colon;
     int tmp;
    cout <<(*this);
    affiche_score();
    ordinateur();
    cout<<(*this);
    affiche_score();
    
    do {
        cout<< "Choisir l'indice de la couleur à deplacer"<<endl;
        placerJetto(Vide, ligne, colone);

    cout<<" choisir la colonne et la ligne d'arrivée "<<endl;
    Plateau::placerJetto(Vide, lign, colon);
    
        while (!deplacement(ligne, colone, lign, colon)) {
            cout<< "deplacement impossimple"<<endl;
            Plateau::placerJetto(Vide, lign, colon);
        }
        tmp=recuperGain();
        cout<<(*this);
    } while (tmp!=0);
}

