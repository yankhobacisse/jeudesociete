//
//  TableauCouleur.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 11/01/14.
//  Copyright (c) 2014 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_TableauCouleur_h
#define PlateauDeJeau_TableauCouleur_h

#include"ListeCouleur.h"

namespace TableauCouleur {
    using namespace ListeCouleur;
    couleur tableauCouleur [8]={Blanc,Noir, Rouge, vert, Bleu ,Vide, Orange,Maron};
    
    static couleur getCouleur(int i){
        
        return tableauCouleur[i];
    }
    
    static int getTaille(){
        
        return 8;
    }
    
}

#endif
