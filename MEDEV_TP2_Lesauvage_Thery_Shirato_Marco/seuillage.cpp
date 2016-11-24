#include <cstdlib>
#include <iostream>
#include <fstream>
#include "seuillage.h"

using namespace std;

void seuillage(ifstream image, int argseuil, string outputname){//on propose à l'utilisateur
                                //de mettre son propre argument de seuillage
    string current_line;
    ofstream outfile(outputname);
    getline(image, current_line);//P2, inutile
    outfile << current_line;//on recopie dans le nouveau fichier
    getline(image, current_line);//commentaires, inutiles
    outfile << current_line;
    getline(image, current_line);//on a maintenant la largeur puis la hauteur, 
    //qui nous donnerons les bornes de nos boucles for, séparés par un espace
    outfile << current_line;
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
    getline(image, current_line);//maximum, inutiles
    int maximum = (int) current_line;
    outfile << current_line;
    for(int h = 0;h<hauteur;h++){
        getline(image, current_line);//on se place sur la ligne qu'on va traiter
        j=current_line[0];//on récupère le premier caractère
        int k=0;//on indente k sur les pixels, dont on connaît le nombre
        i = 0;
        while(k<largeur){//on se repère grâce au nbre de pixels
        string current_nbr = '';
            while(j!='\t'&& j!='\n'){
                current_nbr.append(j);
                i++;
                j = current_line[i];
            }
        int nombre = (int) current_nbr;
        if (nombre<argseuil){
            outfile << 0 << j;
        }else{
            outfile << maximum << j;
        }
        k++;
        }
        
    }
    outfile.close();
}
