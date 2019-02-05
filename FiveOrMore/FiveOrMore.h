//
//  FiveOrMore.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 17/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_FiveOrMore_h
#define PlateauDeJeau_FiveOrMore_h
#include"./../Plateau/Plateau.h"
#include <ctime> 
#include <cstdlib>
#include "math.h"

#include "./../structure/Collection.h"

class FiveOrMore:public Plateau {
protected:
   
    int score1;
    Collection * collection;
public:
    FiveOrMore();
    FiveOrMore(int ligne,int colonne);
    FiveOrMore(const FiveOrMore&);
    virtual ~FiveOrMore();
    virtual ostream & affiche(ostream &) const;
    friend  ostream & operator<<(ostream &,const FiveOrMore &);
    
    bool coupValide(int ligne,int colonne);
    bool coupValideOrdinateur(int ligne,int colonne);
    void ordinateur();
    virtual void placerJetto(couleur jetton, int &ligne,int &colonne);
    int recuperGain();
    //virtual void jouer(couleur joueur);
    virtual void JoueCoup(couleur joueur=Vide);
    virtual bool fini();
    virtual void affiche_score( );
   
    bool chemin(int x1,int y1,int x2,int y2);
    bool deplacement(int x1,int y1,int x2,int y2);
    int random_0_9(int a=0,int b=9);
  
    
};


#endif
