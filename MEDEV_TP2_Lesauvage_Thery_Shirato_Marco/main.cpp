/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 24 novembre 2016, 09:21
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

void seuillage(ifstream image, int argseuil, string outputname){//on propose à l'utilisateur
                                //de mettre son propre argument de seuillage
    string current_line;
    ofstream outfile(outputname);
    getline(image, current_line);//P2, inutile
    outfile << current_line <<endl;//on recopie dans le nouveau fichier
    getline(image, current_line);//commentaires, inutiles
    outfile << current_line <<endl;
    getline(image, current_line);//on a maintenant la largeur puis la hauteur, 
    //qui nous donnerons les bornes de nos boucles for, séparés par un espace
    outfile << current_line <<endl;
    string lar;
    string hau;
    unsigned int i=0;//entier de parcours
    unsigned int taille = current_line.size();
    char j=current_line(i);//caractère de parcours
    while (i < taille && j!=' '){
        j=current_line(i);
        lar.append(j);
        i++;
    }
    i++;
    while (i<taille){
        j=current_line(i);
        hau.append(j);
        i++;
    }
    int largeur = (int) lar;
    int hauteur = (int) hau;
    for(int h = 0;h<hauteur;h++){
        getline(image, current_line);//on se place sur la ligne qu'on va traiter
        j=current_line[0];//on récupère le premier caractère
        i=0;
        while(i<largeur){
            
            i++;
        }
        
    }
}

int main(int argc, char** argv) {

    return 0;
}

