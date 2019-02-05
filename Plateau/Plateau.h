//
//  Plateau.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 11/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_Plateau_h
#define PlateauDeJeau_Plateau_h
#include <iostream>
#include "cstdio"
#include "ctime"
#include "ListeCouleur.h"
#include "InterfacePlateau.h"
using namespace std;
using namespace ListeCouleur;
class Plateau:public InterfacePlateau {

protected:
    couleur joueur1, joueur2;
    int ligne, colonne;
    couleur **grille  ;


    bool caseExiste(int lign, int colon)const;
    int CompteurAlignement(couleur jour, int ligne,int colonne,int directionLigne, int directionColonne );

    bool AlignementExiste(couleur jour, int &ligne,int &colonne,int directionLigne, int directionColonne );

    virtual int eliminerGainPoint(couleur jour, int ligne,int colonne,int directionLigne, int directionColonne,int drapeau );
    virtual int eliminerGainPoint(couleur jour, int ligne,int colonne,int directionLigne, int directionColonne);
    virtual void eliminerGainPoint(couleur jou,int ligne,int colonne);


    virtual void retournerCouleur(couleur jou, couleur adv,int ligne,int colonne);
    virtual void retournerCouleur(couleur jou,couleur adv, int lign, int colon, int directionLigne, int directionColonne);
   //virtual void retournerCouleur(char jou, int lign, int colon);

    virtual bool chemin(int l1,int c1,int l2,int c2,int directionLigne, int directionColonne);

    virtual void placerJetto(couleur jetton, int &igne,int &colonne);
    virtual void placerJetto(couleur jetton,int &colonne);
    virtual bool estRempli();

    couleur jourSuivant(couleur jou);
   // virtual int gain(char joueur,int ligne, int colonne, int dirligne,int dircolonne);

    //virtual char vainqueur() const=0;

    virtual void initialier();

    virtual ostream & affiche(ostream &) const;
    friend  ostream & operator<<(ostream &,const Plateau &);

    virtual Plateau & operator=(const Plateau &);

    int getLigne()const;
    int getColonne() const;
    couleur ** getGrille()const;
    void setJoueur1(couleur joueur);
    void setJoueur2(couleur joueur);


    virtual void JoueCoup(couleur joueur)=0;
    virtual bool fini()=0;
    virtual void affiche_score()=0;
  /* virtual void initialiserLeJeu ()=0;
    virtual void faireJouer(int joueur)=0;
    virtual bool partieTerminee ()=0;
    virtual void proclamerLeVainqueur ()=0;*/


public:
    Plateau();
    Plateau(int ligne,int colonne,couleur coul1,couleur coul2);
    Plateau(const Plateau&);
    //virtual void jouer(couleur joueur);
    virtual ~Plateau();

};

#endif
