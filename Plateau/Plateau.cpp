
//  Plateau.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 11/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#include <iostream>
#include "Plateau.h"




Plateau::Plateau():InterfacePlateau(){

    ligne=0;
    colonne=0;
    joueur1=Vide;
    joueur2=Vide;
    grille= new couleur*[ligne];

    for (int i=0; i<ligne; i++) {
        grille[i]=new couleur[colonne];
    }


}

Plateau::Plateau(int lign,int colonn,couleur coul1,couleur coul2):InterfacePlateau(coul1,coul2){
    ligne=lign;
    colonne=colonn;
    joueur1=coul1;
    joueur2=coul2;
    grille= new couleur*[ligne];

    for (int i=0; i<ligne; i++) {
        grille[i]=new couleur[colonne];
    }

}

Plateau:: Plateau(const Plateau& p):InterfacePlateau(p){

    *this=p;
}

int Plateau::getLigne()const{

    return ligne;
}
int Plateau::getColonne() const{

    return colonne;
}

couleur ** Plateau::getGrille()const{

    return grille;
}

void Plateau::setJoueur1(couleur joueur){
    joueur1=joueur;
}
void Plateau::setJoueur2(couleur joueur){

    joueur2=joueur;
}

 Plateau::~Plateau(){

    for (int i=0; i<ligne; i++) {
         delete [] grille[i];
     }
     delete [] grille;


}

void Plateau::initialier(){

    for (int i=0; i<ligne; i++) {
        for (int j=0; j<colonne; j++) {
            grille[i][j]=Vide;
        }
    }
}

ostream & Plateau::affiche(ostream & out)const{


    int i, j;
    out<<endl;
    out<<"   ";
    out << "   ";
    for(j=0; j<colonne ;j++)
        out<<" "<<j+1<<"  ";
    out<<endl;


    for(i=0;i<ligne;i++)
    {
        out<<"      ";
        for(j=0; j<colonne ;j++)
            out<<"+---";
        out<<"+";
        out<<endl;
        out<<"    "<<i+1<<" ";
        for(j=0;j<colonne;j++)
            if(grille[i][j]!=Vide){
                out<<"| ";
        afficheCouleur(grille[i][j]) ;
        out<<" ";
            }
            else out<<"|   ";
        out<<"|"<<endl;
    }

    out<<"      ";
    for(j=0; j<colonne ;j++)
        out<<"+---";
    out<<"+"<<endl;

    out<<"   ";
    out << "   ";
    for(j=0; j<colonne ;j++)
        out<<" "<<j+1<<"  ";
    out<<endl;
     out<<endl;

      out<< endl;

    return out;
}


ostream & operator<<(ostream &out,const Plateau &p){

    return p.affiche(out);
}

bool Plateau::caseExiste(int lign, int colon) const{

    return (lign >=0 && lign<ligne) &&(colon>=0 && colon<colonne);
}

bool Plateau::AlignementExiste(couleur joueur, int &lign, int &colonn, int direcLigne, int direcColonne){


    bool verificateur=false;

    if(direcLigne!=0 or direcColonne!=0){
    lign+=direcLigne;
    colonn+=direcColonne;
        while (caseExiste(lign,colonn) && grille[lign][colonn]==joueur) {
           // cout <<" Existe un Alignement"<<endl;
            lign+=direcLigne;
            colonn+=direcColonne;
            verificateur=true;

        }
   }

    return  verificateur;




}
int Plateau::CompteurAlignement(couleur jour, int lign,int colonn,int directionLigne, int directionColonne ){

    int nombreAlignee=1;

    if(directionLigne!=0 or directionColonne!=0){
        lign+=directionLigne;
        colonn+=directionColonne;
        while (caseExiste(lign,colonn) && grille[lign][colonn]==jour) {
           // cout<<"Compteur existe "<<endl;
            lign+=directionLigne;
            colonn+=directionColonne;
            ++nombreAlignee;
           // cout<<nombreAlignee;
        }
    }

    return nombreAlignee;
   }

int Plateau::eliminerGainPoint(couleur jour, int lign,int colonn,int directionLigne, int directionColonne,int drapeau ){

    int tmp1=lign;
    int tmp2=colonn;

    int gain=CompteurAlignement(jour, tmp1, tmp2, directionLigne ,directionColonne);

    if (((directionLigne!=0) or (directionColonne!=0)) && gain>=(drapeau)) {

        tmp1=lign+directionLigne;
        tmp2= colonn+directionColonne;
        eliminerGainPoint(jour,lign, colonn) ;
        while ( caseExiste(tmp1,tmp2) && grille[tmp1][tmp2] ==jour ){
                eliminerGainPoint(jour,tmp1,tmp2) ;
                tmp1+=directionLigne;
                tmp2+=directionColonne;
            }

        return gain;
    }

    return 0;

}
int Plateau::eliminerGainPoint(couleur jour, int lign,int colonn,int directionLigne, int directionColonne){

    int tmp1=lign;
    int tmp2=colonn;
    int nombreAlignee=1;
       if (((directionLigne!=0) or (directionColonne!=0))) {
        tmp1=lign+directionLigne;
        tmp2= colonn+directionColonne;
        eliminerGainPoint(jour,lign, colonn) ;
        while ( caseExiste(tmp1,tmp2) && grille[tmp1][tmp2] ==jour){
            eliminerGainPoint(jour,tmp1, tmp2);
            tmp1+=directionLigne;
            tmp2+=directionColonne;
            nombreAlignee++;
        }

        eliminerGainPoint(jour,tmp1, tmp2);
    }
    return nombreAlignee;

}

void Plateau::eliminerGainPoint(couleur jou,int lign,int colon){


    if ( grille[lign][colon]==jou) {
        grille[lign][colon]=Vide;
    }
    }

bool Plateau::estRempli(){


    for (int i=0; i<ligne; i++) {
        for (int j=0; j<colonne; j++) {
            if (grille[i][j]==Vide) {
                return false;
            }
        }
    }
    return true;
}

void Plateau::retournerCouleur(couleur jou,couleur adv, int lign, int colon, int directionLigne, int directionColonne){



        if(directionLigne!=0 or directionColonne!=0){
            lign+=directionLigne;
            colon+=directionColonne;
            while (caseExiste(lign,colon) && grille[lign][colon]==adv) {
               // cout <<" Teste retourne"<<endl;

                retournerCouleur(jou,adv, lign, colon);
                lign+=directionLigne;
                colon+=directionColonne;
            }
        }
}

void Plateau::retournerCouleur(couleur jou,couleur adv, int lign, int colon){

    if ( grille[lign][colon]==adv) {
        grille[lign][colon]=jou;
    }
}

couleur Plateau::jourSuivant(couleur jou){

    if (jou==joueur1) {
        return joueur2;
    }
    return joueur1;
}

void Plateau::placerJetto(couleur jou, int &lign,int &colon){




    cout<<"choisir une case Colone Ligne " << endl;

    cin>>colon;
    colon--;
    cin >>lign;
    lign--;



}

void Plateau::placerJetto(couleur jou,int &colon){




    cout<<"choisir une colonne (ex 1) " << endl;

    cin>> colon;

    colon--;

}

bool Plateau::chemin(int l1,int c1,int l2,int c2,int directionLigne, int directionColonne){

    if (!caseExiste(l1, c1)&&!caseExiste(l2, c2)) {
        return false;
    }

    if(directionLigne!=0 or directionColonne!=0){
        l1+=directionLigne;
        c1+=directionColonne;
        while (caseExiste(l1,c1) && grille[l1][c1]==Vide) {
            if ((l1==l2) && (c1==c2)) {
                return true;
            }
            l1+=directionLigne;
            c1+=directionColonne;
        }
        /*if ((l1==l2) && (c1==c2)) {
            return true;
        }*/
    }
    return false;

}

Plateau & Plateau::operator=(const Plateau & unAutre){

    if (this!=&unAutre) {
        ligne=unAutre.ligne;
        colonne=unAutre.colonne;
        for (int i=0; i<ligne; i++) {
            delete grille[i];
        }
        delete grille;
        grille= new couleur*[ligne];

        for (int i=0; i<ligne; i++) {
            grille[i]=new couleur[colonne];
        }


        for (int i=0; i<ligne; i++) {
            for (int j=0; j<colonne; j++) {
                grille[i][j]=unAutre.grille[i][j];
            }
        }

    }
    return *this;
}

/*void Plateau::jouer(couleur joueur){

    initialier();
    cout <<(*this);
    affiche_score();
    while (!fini()) {
        cout<< "c'est au joueur " ;
        afficheCouleur(joueur);
        cout<< " de jouer" << endl;
        JoueCoup(joueur);
        cout<<(*this);
        affiche_score();
        //if (peutJouer(jourSuivant(joueur)))
        joueur =jourSuivant(joueur);

    }
}
*/
