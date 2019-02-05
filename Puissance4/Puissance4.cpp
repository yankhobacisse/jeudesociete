//
//  Puissance4.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 17/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#include <iostream>
#include "Puissance4.h"



Puissance4::Puissance4():Plateau(){
    
    joueur1=Vide;
    joueur2=Vide;
    score1=0;
    score2=0;
   
     
}

Puissance4::Puissance4(int lign,int colonn,couleur coul1,couleur coul):Plateau(lign,colonn,coul1,coul){
    
    joueur1=coul1;
    joueur2=coul;
    score1=0;
    score2=0;
        
}
Puissance4::~Puissance4(){
   /* for (int i=0; i<ligne; i++) {
        delete [] grille[i];
    }
    delete [] grille;
    */
}

Puissance4::Puissance4(const Puissance4 &unAutre):Plateau(unAutre){
    (*this)=unAutre;
}
ostream & Puissance4::affiche(ostream & out) const{
    out<< "   ";
    afficheCouleur(joueur1);
    out<<" score: " <<score1 <<endl;
    out<<"   ";
    afficheCouleur(joueur2);
    out<<" score: " << score2<<endl;
    return Plateau::affiche(out);
}
ostream & operator<<(ostream & out,const Puissance4 &pui){
    return pui.affiche(out);
}

bool Puissance4::fini(){
    
    
    if (score1!=0 or score2!=0 or estRempli()) {
        return true;
    }
    
    return false;
}

void Puissance4::affiche_score(){
    
    
    cout<< "   ";
    afficheCouleur(joueur1);
    cout<<" score: " <<score1 <<endl;
    cout<<"   ";
    afficheCouleur(joueur2);
    cout<<" score: " << score2<<endl;
    
    if (fini()) {
        
  
        if (score1>score2) {
            afficheCouleur(joueur1);
            cout<< " gagne"<<endl;
        }
        else if(score1<score2){
            afficheCouleur(joueur2);
            cout<<" gagne" <<endl;
        }
        else 
            cout<<" Parti nnul"<<endl;
 
    }
    
}

bool Puissance4::coupValide(couleur jou,int colonne){
   
    int lign=0;
    
    if (jou==Vide) {
        return false;
    }
    
    while (caseExiste(lign,colonne) && grille[lign][colonne]==Vide&&lign<ligne) {
        ++lign;
    }
    if (lign>ligne) {
        return  false;
    }
    
    grille[lign-1][colonne]=jou;
    
    return true;
}

void Puissance4::placerJetto(couleur jett,int &colonne){
    
    Plateau::placerJetto(jett, colonne);
    
    while (!coupValide(jett, colonne)) {
        cout<<"Ce coup non valide"<<endl; 
        cout<<"Choisissez une autre  colone :"<<endl;
        cin >>colonne;
        colonne--;
        
    }
    
}
void Puissance4::graviteUneColonne(int colonn){
    for (int i=ligne-1; i>=0; i--) {
        if (grille[i][colonn]!=Vide) {
            while (caseExiste(i+1, colonn)&&grille[i+1][colonn]==Vide ) {
                
                grille[i+1][colonn]=grille[i][colonn];
                grille[i][colonn]=Vide;
               
            }
        }
   }


}

void Puissance4::gravite(){
    
    
    for (int j=0; j<colonne; j++) {
        
        graviteUneColonne(j);
    }
}


void Puissance4::JoueCoup(couleur joueu){
    int colone;
    int gain;
    //int nombrePiont=0;
    cout <<(*this);
    affiche_score();
    cout<<"Le joueur ";
    afficheCouleur(joueu);
    cout<<" joue son tour "<<endl;
    placerJetto(joueu, colone) ;
    
    for (int i=0; i<ligne; i++) {
        for (int j=0; j<colonne; j++) {
        
            for (int direcLigne=-1; direcLigne<=1; direcLigne++) {
                for (int directColone=-1; directColone<=1;directColone ++) {
                    
                    if (grille[i][j]==joueu) {
                        
                   
                        gain=eliminerGainPoint(joueu, i, j, direcLigne, directColone, 4);
                        if (gain==4) {
                           gravite(); 
                            //nombrePiont++;
                            if (joueu==joueur1) {
                                score1++;
                            }
                            else
                                score2++;
                        
                    }
                    if (grille[i][j]==jourSuivant(joueu)) {
                        
                   
                    gain=eliminerGainPoint(jourSuivant(joueu), i, j, direcLigne, directColone, 4);
                    if (gain==4) {
                        gravite();
                        if (jourSuivant(joueu)==joueur1) {
                            score1++;
                        }
                        else
                            score2++;
                    
                        //nombrePiont++;
                            }
                        }
                    
                    }
                }
            }
        }
    }  
   
}


