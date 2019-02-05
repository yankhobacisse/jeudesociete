//
//  Othello.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 13/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_Othello_h
#define PlateauDeJeau_Othello_h
#include "./../Plateau/Plateau.h"

class Othello :public Plateau{
   
private:
    
   couleur joueur1;
   couleur joueur2;
    int score1;
    int score2;
    int ligne, colonne;
 
   
    
public:
    
    Othello();
    Othello(int ligne,int colonne);
    Othello(const Othello&);
    virtual ~Othello();
    //virtual char vainqueur();
    
    
    void initialier();
    
    virtual ostream & affiche(ostream &)const;
    friend  ostream & operator<<(ostream &,const Othello &);
    
   // virtual void jouer(couleur joueur);
    virtual bool fini();
    virtual void affiche_score( );
    
    int getLigne()const;
    int getColonne() const;
    
    virtual void placerJetto(couleur jetton, int &ligne,int &colonne);
   
    //bool alignementValige(char joueur, int lign,int colon,int dirlign,int dircolon);
    bool coupValide(couleur joueur, int ligne,int colonne);
    bool peutJouer(couleur joueur);
    virtual void JoueCoup(couleur joueur); 
    
    
};
#endif
