//
//  InterfacePlateau.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 19/01/14.
//  Copyright (c) 2014 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_InterfacePlateau_h
#define PlateauDeJeau_InterfacePlateau_h
#include "ListeCouleur.h"
using namespace ListeCouleur;
class InterfacePlateau {
private:
    couleur joueur1,joueur2;
protected:
    virtual void JoueCoup(couleur joueur)=0;
    virtual bool fini()=0;
    virtual void initialier()=0;
    virtual void affiche_score()=0;
public:
    InterfacePlateau();
    InterfacePlateau(couleur joueur1,couleur joueur2);
    InterfacePlateau(const InterfacePlateau& p);
   virtual ~InterfacePlateau();
virtual void jouer(couleur joueur);
};


#endif
