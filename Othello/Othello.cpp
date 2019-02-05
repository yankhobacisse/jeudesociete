//
//  Othello.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 13/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#include <iostream>
#include "Othello.h"
//#include "./../Plateau/Plateau.h"


Othello::Othello():Plateau(){
    ligne=0;
    colonne=0;
    score1=2;
    score2=2;
  
}

Othello::Othello(int ligne,int colonne):Plateau(ligne,colonne,Noir,Blanc),joueur1(Noir),joueur2(Blanc){
    this->ligne=ligne;
    this->colonne=colonne;
    score1=2;
    score2=2;
   
   
   grille= new couleur*[ligne];
    
    for (int i=0; i<ligne; i++) {
        grille[i]=new couleur[colonne];
    }
    
    //grille=Plateau::grille;
    
    
}
Othello::Othello(const Othello &o):Plateau(o),joueur1(Noir),joueur2(Blanc){
    (*this)=o;
    
}

Othello::~Othello(){
    
  /*for (int i=0; i<ligne; i++) {
        delete [] grille[i];
    }
    delete [] grille;*/
   
}

void Othello::initialier(){
    
   Plateau::initialier();
    
    grille[ligne/2-1][colonne/2-1] = joueur1;; 
    grille[ligne/2-1][colonne/2] =joueur2 ;
    grille[ligne/2][colonne/2-1] = joueur2; 
    grille[ligne/2][colonne/2] = joueur1; 
    
    
}

ostream & Othello::affiche(ostream & out) const{
    
    return Plateau::affiche(out);
}
ostream & operator<<(ostream & out,const Othello &o){
    out<< "   'N' score: " <<o.score1 <<endl;
    out<<"   'B' score: " << o.score2<<endl;
      return o.affiche(out);
}

int Othello::getLigne()const{
    
    return  ligne;
}
int Othello::getColonne() const{
    return colonne;   
}

bool Othello::coupValide(couleur joueur, int lign,int colon){
    
    if (!caseExiste(lign, colon)) {
        return false;
    }
    
    int tmp1=lign;
    int tmp2=colon;
    couleur adv;
    bool drapeau;
    if (joueur==Noir) {
        adv=Blanc;
    }
    else{
        adv=Noir;
    }
        
    for (int direcLigne=-1; direcLigne<=1; direcLigne++) {
        for (int directColone=-1; directColone<=1; directColone++) {
            if (direcLigne!=0 or directColone!=0) {
           
                drapeau=Plateau::AlignementExiste(adv, tmp1,tmp2, direcLigne, directColone);
                if (drapeau==true && grille[tmp1][tmp2]==joueur) {
                   // cout<< "coup valide"<<endl;
                    
                    return true;
                }

                tmp1=lign;
                tmp2=colon;
           
            }
        }
    }
    
    return  false;
}

bool Othello::peutJouer(couleur joueur){
    
    for (int i=0; i<ligne; i++) 
        for (int j=0; j<colonne; j++) 
                
            if (coupValide(joueur,i , j)) {
                return true;
            }
    return  false;
}

void Othello::JoueCoup(couleur joueur){
    int lign ,colon;
    cout <<(*this);
    affiche_score();
    placerJetto(joueur, lign, colon) ;
    
    int tmp1=lign;
    int tmp2=colon;
    couleur adv;
    
    if (joueur==Noir) {
        adv=Blanc;
    }
    else
        adv=Noir;
    bool drapeau;
    if (peutJouer(joueur)) {
        
 
    for (int direcLigne=-1; direcLigne<=1; direcLigne++) {
        for (int directColone=-1; directColone<=1;directColone ++) {
            if (direcLigne!=0 or directColone!=0) {
            int gain=CompteurAlignement(adv, tmp1, tmp2, direcLigne ,directColone);
            drapeau=AlignementExiste(adv, tmp1, tmp2, direcLigne, directColone);
                if (grille[tmp1][tmp2]==joueur && drapeau==true) {
                    grille[lign][colon]=joueur;   
                retournerCouleur(joueur,adv, lign, colon, direcLigne, directColone);
                tmp1=lign;
                tmp2=colon;
                    if (joueur==Noir) {
                       score1+=gain; 
                        score2-=gain-1;
                    }else{
                    score2+=gain;
                        score1-=gain-1;
                    }
                }
                tmp1=lign;
                tmp2=colon;  
            }
        }
    }
    }
    else {
        cout<<"Le joueur ";
        afficheCouleur(joueur);
        cout<<" passe son tour "<<endl; 
    }
        
    
}
 

void Othello::placerJetto(couleur jetton, int &lign,int &colonn){
    
    //char c ;
    
    Plateau::placerJetto(jetton, lign, colonn);
    //cout<<coupValide(jetton, lign, colonn)<<endl;
    
    while (!coupValide(jetton, lign, colonn)) { 
        cout<<"Ce coup n'est pas valide"<<endl; 
        cout<<"Choisissez une autre case colone ligne :"<<endl;; 
        //cin>>c; 
        //On change les minuscules en majuscules 
        //if ((c >= 'a') && (c < 'a'+this->colonne)) 
           // c = c + 'A' - 'a'; 
        //*colonne = c - 'A'; 
        cin>>colonn;
        colonn--;
        cin>>lign;
       lign--; 
    } 

}


bool Othello::fini(){
    
    int nbNoir, nbBlanc, cpt; 
    
    
    nbNoir = 0; 
    nbBlanc = 0; 
    for (int i=0; i<ligne; i++) { 
        for (int j=0; j<colonne; j++) { 
            if ((grille[i][j] ==Vide) && (peutJouer(Noir) || peutJouer(Blanc))) { 
                return false; 
            } else { 
                if (grille[i][j] ==Noir) nbNoir++; 
                else if (grille[i][j] ==Blanc) nbBlanc++; 
            } 
        } 
    } 
    
    
    cpt = 0; 
    for (int i=0; i<ligne; i++) 
        for (int j=0; j<colonne; j++) { 
            if (cpt < nbNoir) 
                grille[i][j] =Noir; 
            else if ((cpt >= nbNoir) && (cpt < nbBlanc + nbNoir -1)) 
                grille[i][j] =Blanc; 
            else grille[i][j] =Vide; 
            cpt++; 
        } 
    cout << *this;
    return true; 
    
}
void Othello::affiche_score(){
    
    
    cout<< "   'N' score: " <<score1 <<endl;
    cout<<"   'B' score: " << score2<<endl;
    if (fini()) {
        if (score1 >score2 ) {
            afficheCouleur(joueur1);
            cout<<" a gagne !!!"<<endl;
        }
        else if (score2> score1){
            afficheCouleur(joueur2);
            cout<<" a gagne !!!"<<endl; 
        }
        else cout<<"Partie Nulle"<<endl; 
    }
    

           
    
}

/*void Othello::jouer(couleur joueur){
    
    //int lign ,colon;
   
     
    initialier();
    cout <<(*this);
    
    while (!fini()) { 
        cout<< "c'est au joueur " ;
        afficheCouleur(joueur);
        cout<< " de jouer" << endl;
        placerJetto(joueur, lign, colon) ;
       
        JoueCoup(joueur);
        cout<<(*this); 
      //if (peutJouer(jourSuivant(joueur)))
            joueur =jourSuivant(joueur); 
        else {
            cout<<"Le joueur ";
            afficheCouleur(jourSuivant(joueur));
            cout<<" passe son tour "<<endl; 
        }
         }   
}

*/
