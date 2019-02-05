//
//  Puissance4var.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 06/01/14.
//  Copyright (c) 2014 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_Puissance4var_h
#define PlateauDeJeau_Puissance4var_h
#include "./../Puissance4/Puissance4.h"
#include "./../structure/Stack.h"
class Puissance4var:public Puissance4{
protected:
    couleur joueur1, joueur2;
    int score1, score2;
    int nbCoup;
    Stack<couleur> pileJoueur1;
    Stack<couleur> pileJoueur2;
public:
    
    Puissance4var();
    Puissance4var(int lign,int colonn,couleur coul1,couleur coul2, int nobCoup=21);
    Puissance4var(const Puissance4var&);
    virtual ~Puissance4var();
    //void initialier();
    
    //virtual ostream & affiche(ostream &) const;
   // friend  ostream & operator<<(ostream &,const Puissance4 &);
    virtual void JoueCoup(couleur joueur);
    //virtual void jouer(couleur joueur);
    virtual bool fini();
   // virtual void affiche_score( )const;
    
    //void graviteUneColonne( int colonne);
   // void gravite();
    //virtual void placerJetto(char jetton,int &colonne);
    //void JoueCoup(char joueur,int colone); 
    
   // bool coupValide(char joueur,int colonne);
    
    
    
};



#endif
