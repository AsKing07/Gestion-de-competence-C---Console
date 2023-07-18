#include <iostream>
#include <sstream>
#include <fstream>
#include<string.h>
#include<windows.h>
#include "fonctionsEcriture.h"
#include "fonctionsLecture.h"
#include "Menu.h"

using namespace std;







int main()
{

    HWND hwnd=GetForegroundWindow();
    ShowWindow(hwnd,SW_MAXIMIZE);

    system("color 2f");
    string cheminFichier;

	cout<<"Un Logiciel de QUALITE";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t Tous droits Reserves"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t--GESTION DES COMPETENCES--"<<endl;
	cout<<"\t\t\t\t\t\t  -----------------------"<<endl;
    cout <<"\t\t\t||-----------BIENVENUE DANS NOTRE PROGRAMME DE GESTION DE COMPETENCES-----------||"<< endl;
    cout <<"\t\t\t||-----------Nous allons charger le ficher qui servira de base de donnees.-----------||"<< endl;
    cout << " \t\t\t\tCopier le fichier d'extension \".cpt\" a charger dans le dossier de l'application."<<endl;
    cout << "\t\t\t\t\tEntrer le nom du fichier (avec l'extension \".cpt\") : ";
                do
                {
                    getline(cin, cheminFichier);
                    if(cheminFichier.find(".cpt") == string::npos)
                    {
                        cout<< endl <<"\t\t\t\t||-----------Format non pris en charge !-----------|| Reessayer :" ;
                    }

                }while(cheminFichier.find(".cpt") == string::npos);

    menu(cheminFichier);

    return 0;

}
