
//  FiveOrMoreVar.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 06/01/14.
//  Copyright (c) 2014 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_FiveOrMoreVar_h
#define PlateauDeJeau_FiveOrMoreVar_h

#include "./../Plateau/Plateau.h"
#include <ctime>
#include <cstdlib>

#include "./../structure/Collection.h"
#include "./../FiveOrMore/FiveOrMore.h"

class FiveOrMoreVar:public FiveOrMore {
protected:

    int score1;
    Collection * collection;
public:
    FiveOrMoreVar();
    FiveOrMoreVar(int ligne,int colonne);
    FiveOrMoreVar(const FiveOrMore&);
    virtual ~FiveOrMoreVar();
    //virtual void jouer(couleur joueur);
    virtual void JoueCoup(couleur joueur);
};



#endif
