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

void seuillage(ifstream image){
    string current_line;
    getline(image, current_line);//P2, inutile
    getline(image, current_line);//commentaires, inutiles
    getline(image, current_line);//on a maintenant la largeur puis la hauteur, 
    //qui nous donnerons les bornes de nos boucles for, séparés par un espace
    
}

int main(int argc, char** argv) {

    return 0;
}

