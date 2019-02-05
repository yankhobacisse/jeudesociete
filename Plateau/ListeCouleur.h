//
//  ListeCouleur.h
//  PlateauDeJeau
//
//  Created by yankhoba cisse on 06/01/14.
//  Copyright (c) 2014 Paris VII. All rights reserved.
//

#ifndef PlateauDeJeau_ListeCouleur_h
#define PlateauDeJeau_ListeCouleur_h
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

extern "C"
{
//#include "structure/color.h"
}
#define BLEUCLAIR "\033[01;34m"
#define ROUGE "\033[00;31m"
#define BLEU "\033[00;34m"
#define SOULIGNE "\033[04m"
#define NORMAL "\033[00m"

using namespace std;
namespace ListeCouleur {
    enum couleur{Blanc = 37,Noir = 30, Rouge =31, vert=32, Bleu =34,Vide=0, Cyan=36,Magenda=35,Jaune=33};
 
    static string set_color(couleur foreground = Vide, couleur background = Vide)
    {
        //"\x1b[1;35;42m"
        std::stringstream s;
        s << "\x1b[";
        if (!foreground && ! background){
            s << "0"; // reset colors if no params
        }
        if (foreground) {
            s << 29 + foreground;
            if (background) s << ";";
        }
        if (background) {
            s << 39 + background;
        }
        s << "m";
        return s.str();
    }

    
   static int arrierPlan(couleur col){
   
       switch (col) {
           case Blanc: return 37; break;
           case Noir: return 30; break;
           case Rouge: return 31; break;  
           case vert: return 32; break;
           case Jaune: return 33; break;
           case Bleu: return 34; break; 
           case Cyan: return 36; break;
           case Magenda: return 35; break;    
           default:
               return 0;
               break;
       }
   
    }

    static int avantPlan(couleur col){
        
        switch (col) {
            case Blanc: return 47; break;
            case Noir: return 40; break;
            case Rouge: return 41; break;  
            case vert: return 42; break; 
            case Jaune: return 43; break;    
            case Bleu: return 44; break; 
            case Cyan: return 46; break;
            case Magenda: return 45; break;    
            default:
                return 0;
                break;
        }
        
    }
        
   /* static string set_color(couleur arrierplan= Vide, couleur avantplan =Vide)
    {
        string s;
        s = "\033[";
        if (! arrierPlan(avantplan) && ! avantPlan(avantplan)){
            s +="0"; // reset colors if no params
        }
        if (arrierPlan(arrierplan)) {
            s+= 29 + arrierPlan(arrierplan);
            if (avantPlan(avantplan)) s+= ";";
        }
        if (avantPlan(avantplan)) {
            s+= 39 + avantPlan(avantplan);
        }
        s +="m";
        return s;
    }
    
   static void textcolor(couleur color)
    {
        std::cout<<"\033]"<<arrierPlan(color);"\x1b[1;35;42m"
    }*/
    
   static void afficheCouleur(couleur c)
    {
        switch (c) {
            case Blanc:
             
                cout<<'B';
                //cout<<set_color();
                break;
            case Noir:  cout<<'N'; break;
            case Rouge: cout<<'R'; break;
            case vert: cout<<'V'; break;
            case Bleu: cout<<'X'; break;
            case Magenda: cout<<'M'; break;
            case Cyan: cout<<'O'; break;
            default:cout<<' '; break;
        };
    };
}


 

 

#endif
