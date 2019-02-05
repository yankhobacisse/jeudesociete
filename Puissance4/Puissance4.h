//
//  Puissance4.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 16/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_Puissance4_h
#define PlateauDeJeau_Puissance4_h
#include "./../Plateau/Plateau.h"

class Puissance4:public Plateau{
protected:
    couleur joueur1, joueur2;
    int score1, score2;
   
    
public:
    
    Puissance4();
    Puissance4(int lign,int colonn,couleur coul1=Blanc,couleur coul2=Noir);
    Puissance4(const Puissance4&);
    virtual ~Puissance4();
    //void initialier();
    
    virtual ostream & affiche(ostream &) const;
    friend  ostream & operator<<(ostream &,const Puissance4 &);
    
    //virtual void jouer(couleur joueur);
    virtual bool fini();
    virtual void affiche_score( );
    
    void graviteUneColonne( int colonne);
    void gravite();
    virtual void placerJetto(couleur jetton,int &colonne);
    virtual void JoueCoup(couleur joueur); 

    bool coupValide(couleur joueur,int colonne);


    
};

#endif
