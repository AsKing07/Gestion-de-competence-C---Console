#ifndef FONCTIONSLECTURE_H_INCLUDED
#define FONCTIONSLECTURE_H_INCLUDED
#include <iostream>
#include <sstream>
#include <fstream>
#include<string.h>
#include <vector>
#include <algorithm>

using namespace std;



void just_show_profils(string cheminFichier);

void just_show_professionnals(string cheminFichier);

void show_professionnals_profil_1(int nbrCmpPfl, vector<string>& competences,string cheminFichier);

void show_professionnals_profil(string cheminFichier);

void show_professionnals_cmp(string cheminFichier);

void show_profil_cmp(string cheminFichier);

void just_show_cmp(string cheminFichier);



#endif // FONCTIONSLECTURE_H_INCLUDED
