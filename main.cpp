//
//  main.cpp
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 11/12/13.
//  Copyright (c) 2013 Paris VII. All rights reserved.
//

#include <iostream>
#include "Plateau/Plateau.h"
#include "Othello/Othello.h"
#include "Puissance4/Puissance4.h"
#include "Puissance4Var/Puissance4Var.h"
#include "FiveOrMore/FiveOrMore.h"
#include "FiveOrMoreVar/FiveOrMoreVar.h"
#include <sstream>
# include <ncurses.h>
#include "cstdio"
#include "structure/Collection.h"
//#include "color.h"
using namespace std;
bool choixElement(int &ligne,int &colonne,couleur &joueur1,couleur &joueur2);
bool choixElement(int &ligne,int &colonne);
int InterfaceChoi();

int main (int argc, const char * argv[])
{    
  
    
     cout<<"*********************************************************************************"<<endl;
     cout<<"**                                   ,%%%%%%%%%%%%%%%%,                        **"<<endl;
     cout<<"**                                  ,%%%%/\\%%%%%%%%/\\%%,                     **"<<endl;
     cout<<"**                                 ,%%%%%%\\c \"\" J/%%%%,                     **"<<endl;
     cout<<"**            %%.                   %%%%%%%%/ d  b \\%%%%%%                    **"<<endl;
     cout<<"**            `%%%%.         __      %%%%%%%%    _  |%%%%%%                    **"<<endl;
     cout<<"**             `%%%%      .-'  `\"~--\"`%%%%%%%%(=_Y_=)%%%%'                   **"<<endl;
     cout<<"**              //    .'     `.      `%%%%%%%%\\7/%%%%%%'____                  **"<<endl;
     cout<<"**             ((    /         ;      `%%%%%%%%%%%%%%'____)))                  **"<<endl;
     cout<<"**             `.`--'         ,'   _,`-._____`-,                               **"<<endl;
     cout<<"**               `\"\"\"`._____  `--,`  +-------`)))-------+                   **"<<endl;
     cout<<"**                          `~\"-)))    |                  |                   **"<<endl;
     cout<<"**                                      |   Jeux de        |                   **"<<endl;
     cout<<"**                                      |   societes       |                   **"<<endl;
     cout<<"**                                      | ***************  |                   **"<<endl; 
     cout<<"**                                      |                  |                   **"<<endl; 
     cout<<"**                                      |                  |                   **"<<endl; 
     cout<<"**                                      |  Yankhoba Cisse  |                   **"<<endl; 
     cout<<"**                                      |                  |                   **"<<endl; 
     cout<<"**                                      +------------------+                   **"<<endl; 
     cout<<"**                                                                             **"<<endl;
     cout<<"*********************************************************************************"<<endl;
     
     
     
    int choix;
    do {
        choix=InterfaceChoi();
        
    
    
    InterfacePlateau *plateau;
    Collection *collection=new Collection();
    int ligne,colonne;
    couleur joueur1,joueur2;
    int indiceCouleur;
    //bool drapeau;
    
    if (choix==1) {
        
        if (!choixElement(ligne, colonne, joueur1, joueur2)) {
            Puissance4 p(ligne,colonne,joueur1,joueur2);
            plateau=&p;
            plateau->jouer(joueur1);
        }
        else{
            Puissance4 p(6,7,joueur1,joueur2);
            plateau=&p;
            plateau->jouer(joueur1); 
        }
    } 
    else if (choix==2) {
        
        if (!choixElement(ligne, colonne, joueur1, joueur2)) {
            
            cout<<" Choisir le nombre de coup à jouer"<<endl;
            int nbCoup;
            cin>>nbCoup;
            cin.ignore();
            if (nbCoup<4) {
                Puissance4var p(ligne,colonne,joueur1,joueur2);
                plateau=&p;
                plateau->jouer(joueur1);
            }
            else {
                Puissance4var p(ligne,colonne,joueur1,joueur2,nbCoup);
                plateau=&p;
                plateau->jouer(joueur1);
            }
            
        }
        else{
            
            cout<<" Choisir le nombre de coup à jouer"<<endl;
            int nbCoup;
            cin>>nbCoup;
            cin.ignore();
            if (nbCoup<4) {
                Puissance4var pv(6,7,joueur1,joueur2);
                plateau=&pv;
                plateau->jouer(joueur1);
            }
            else {
                Puissance4var p(6,7,joueur1,joueur2,nbCoup);
                plateau=&p;
                plateau->jouer(joueur1);
            }

            
        }

        
    }
      else if (choix==3) {
          
          if (!choixElement(ligne,colonne)) {
            Othello o(ligne, colonne);
              int tmp;
              do {
                  cout<<"Quelle joueur qui commence 1 pour NOIR,2 pour Blanc"<<endl;
                  
                  cin>>tmp;
              } while (tmp<0  or tmp>1);
              cin.ignore();
              if (tmp==1) {
                  plateau=&o;
                  plateau->jouer(Noir);
              }
              else{
                  plateau=&o;
                  plateau->jouer(Blanc); 
              }
          }
          else{
              Othello o(8,8);
              int tmp;
              do {
                  cout<<"Quelle joueur qui commence 1 pour NOIR,2 pour Blanc"<<endl;
                  
                  cin>>tmp;
              } while (tmp<1  or tmp>2);
              cin.ignore();
              if (tmp==1) {
                  plateau=&o;
                  plateau->jouer(Noir);
              }
              else{
                  plateau=&o;
                  plateau->jouer(Blanc); 
              }

          }
          
      }
    else if (choix==4) {
        cout<<"Choisir l'indice  la couleur pour joueur n°1"<<endl;
        
        /*
        
        do {
            
            cout<<"[ ";
            
            for (int i=0; i<collection->getTaille(); i++) {
                cout<<"N° "<<i+1<<" " ;
                afficheCouleur(collection->getCouleurValeur(i));
                cout<<" ;";
            }
            cout<<" ]"<<endl;
            cin>>indiceCouleur;
            indiceCouleur--;
            
        } while (indiceCouleur>collection->getTaille() or indiceCouleur<0);
        cin.ignore();
        
        joueur1=  collection->getCouleurValeur(indiceCouleur);
        
        cout<<"Choisir l'indice  la couleur pour joueur n°2"<<endl;
        do {
            
            cout<<"[ ";
            
            for (int i=0; i<collection->getTaille(); i++) {
                cout<<"N° "<<i+1<<" ";
                afficheCouleur(collection->getCouleurValeur(i));
                cout<<" ;";
            }
            cout<<" ]"<<endl;
            cin>>indiceCouleur;
            indiceCouleur--;
            
        } while (indiceCouleur>collection->getTaille() or indiceCouleur<0);
        cin.ignore();
        joueur2=  collection->getCouleurValeur(indiceCouleur);
        
        Morpion m(3, 3, joueur1, joueur2);
        int tmp;
        do {
            cout<<"Quelle joueur qui commence 1 pour ";
            afficheCouleur(joueur1);
            cout<< " 2 pour ";
            afficheCouleur(joueur2);
            cout<<endl;
            
            cin>>tmp;
        } while (tmp<1  or tmp>2);
        cin.ignore();
        if (tmp==1) {
            plateau=&m;
            plateau->jouer(joueur1);
        }
        else{
            plateau=&m;
            plateau->jouer(joueur2); 
        }*/
               
    }
   else if (choix==5) {
       cout<< " Le jeux est lancer "<<endl;
       if (!choixElement(ligne,colonne)) {
           FiveOrMore f(ligne,colonne);
           plateau=&f;
           plateau->jouer(Vide);
           
            }
       else{
           
           FiveOrMore f(8,8);
           plateau=&f;
           plateau->jouer(Vide);
       }

       
    }
   else if (choix==6) {
       cout<< " Le jeux est lancer "<<endl;
       if (!choixElement(ligne,colonne)) {
           FiveOrMoreVar fv(ligne,colonne);
           plateau=&fv;
           plateau->jouer(Vide);
           
       }
       else{
           
           FiveOrMoreVar fv(8,8);
           plateau=&fv;
           plateau->jouer(Vide);
       }
       
       
   }
    } while (choix!=7); 
    cout<<"Fin de Jeux ,Au travail"<<endl;
    return 0;
    
  }

bool choixElement(int &ligne,int &colonne,couleur &joueur1,couleur &joueur2){
    
    Collection *collection=new Collection();
    int indiceCouleur;
    int drapeau;

    do {
        cout<< "Version Standars ?: 1 pour oui, 0 pour non"<<endl;
        cin>>drapeau;
        
    } while (drapeau<0  or drapeau>1);
    cin.ignore();
    if (drapeau==0) {
        cout<<"Entrer le nombre de ligne"<<endl;
        cin>>ligne;
        cout<<"Entrer le nombre de colonne"<<endl;
        cin>>colonne;
        
        cout<<"Choisir l'indice  la couleur pour joueur n°1"<<endl;
        
        
        
        do {
            
            cout<<"[ ";
            
            for (int i=0; i<collection->getTaille(); i++) {
                cout<<"N°"<<i+1<<" " ;
                afficheCouleur(collection->getCouleurValeur(i));
                cout<<" ;";
            }
            cout<<" ]"<<endl;
            cin>>indiceCouleur;
            indiceCouleur-=1;
            
        } while (indiceCouleur>collection->getTaille() or indiceCouleur<0);
        cin.ignore();
        
        joueur1=  collection->getCouleurValeur(--indiceCouleur);
        
        cout<<"Choisir l'indice  la couleur pour joueur n°2"<<endl;
        do {
            
            cout<<"[ ";
            
            for (int i=0; i<collection->getTaille(); i++) {
                cout<<"N°"<<i+1<<" ";
                afficheCouleur(collection->getCouleurValeur(i));
                cout<<" ;";
            }
            cout<<" ]"<<endl;
            cin>>indiceCouleur;
            indiceCouleur-=1;
            
        } while (indiceCouleur>collection->getTaille() or indiceCouleur<0);
        cin.ignore();
        joueur2=  collection->getCouleurValeur(indiceCouleur);
        delete collection;
        return false;
    }
    else if(drapeau==1){
        cout<<"Choisir l'indice  la couleur pour joueur n°1"<<endl;
        
        do {
            
            cout<<"[ ";
            
            for (int i=0; i<collection->getTaille(); i++) {
                cout<<"N°"<<i+1<<" " ;
                afficheCouleur(collection->getCouleurValeur(i));
                cout<<" ;";
            }
            cout<<" ]"<<endl;
            cin>>indiceCouleur;
            indiceCouleur-=1;
            
        } while (indiceCouleur>collection->getTaille() or indiceCouleur<0);
        cin.ignore();
        
        joueur1=  collection->getCouleurValeur(indiceCouleur);
        
        cout<<"Choisir l'indice  la couleur pour joueur n°2"<<endl;
        do {
            
            cout<<"[ ";
            
            for (int i=0; i<collection->getTaille(); i++) {
                cout<<"N°"<<i+1<<" ";
                afficheCouleur(collection->getCouleurValeur(i));
                cout<<" ;";
            }
            cout<<" ]"<<endl;
            cin>>indiceCouleur;
            indiceCouleur-=1;
            
        } while (indiceCouleur>collection->getTaille() or indiceCouleur<0);
        cin.ignore();
        joueur2=  collection->getCouleurValeur(indiceCouleur);
       
        delete collection;
    }
   return true; 
}
bool choixElement(int &ligne,int &colonne){
    int drapeau;
    
    do {
        cout<< "Version Standars ?: 1 pour oui, 0 pour non"<<endl;
        cin>>drapeau;
        
    } while (drapeau<0  or drapeau>1);
    cin.ignore();
    if (drapeau==0) {
        cout<<"Entrer le nombre de ligne"<<endl;
        cin>>ligne;
        cout<<"Entrer le nombre de colonne"<<endl;
        cin>>colonne;
        cin.ignore();

        return false;
    }
    else if(drapeau==1){
                       
    }
    return true; 
}

int InterfaceChoi(){
    int choix;
    do{
        
        cout<<endl;
        cout<<"         ######################          "<<endl; 
        cout<<"         ##      Menu        ##            +---+---+---+---+---+---+---+---+ "<<endl;
        cout<<"         ##    Principal     ##          1 |   |   |   |   |   |   |   |   | "<<endl;
        cout<<"         ######################            +---+---+---+---+---+---+---+---+  "<<endl;
        cout<<"         #  1  # Puissance4   #          2 |   |   |   |   |   |   |   |   | "<<endl;
        cout<<"         #********************#            +---+---+---+---+---+---+---+---+  "<<endl;
        cout<<"         #  2  # Puissance4Var#          3 |   |   |   |   |   |   |   |   | "<<endl;
        cout<<"         #********************#            +---+---+---+---+---+---+---+---+  "<<endl;
        cout<<"         #  3  # Othello      #          4 |   |   |   |   |   |   |   |   | "<<endl;
        cout<<"         #********************#            +---+---+---+---+---+---+---+---+ "<<endl;
        cout<<"         #  4  # Morpion      #          5 |   |   |   |   |   |   |   |   | "<<endl;
        cout<<"         #********************#            +---+---+---+---+---+---+---+---+ "<<endl;
        cout<<"         #  5  # FiveOrMore   #          6 |   |   |   |   |   |   |   |   | "<<endl;
        cout<<"         #********************#            +---+---+---+---+---+---+---+---+ "<<endl;
        cout<<"         #  6  # FiveOrMoreVar#          7 |   |   |   |   |   |   |   |   | "<<endl;
        cout<<"         #********************#            +---+---+---+---+---+---+---+---+ "<<endl; 	   
        cout<<"         #  7  #   QUITTER    #          7 |   |   |   |   |   |   |   |   |  "<<endl;  
        cout<<"         ######################            +---+---+---+---+---+---+---+---+  "<<endl;
        cout<<"                                             1   2   3   4   5   6   7   8    "<<endl; 
        cout<<endl; 
        cout<<endl;
        cout<<"                Saisir votre choix par le numero du jeu ..."<<endl;
        
        cin>>choix;
        
    } while(choix<1 || choix>7);
    cin.ignore();
    return choix;
}
