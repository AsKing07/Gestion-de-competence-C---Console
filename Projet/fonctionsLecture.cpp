#include "fonctionsLecture.h"
#include "vector"
#include <iostream>
#include <algorithm>

using namespace std;

void just_show_profils(string cheminFichier)//Lister tous les Profils
{


    ifstream mon_flux(cheminFichier.c_str());//On ouvre le fichier en mode Lecture

  //  int tmp;
    string lecture;//La variable Lecture contiendra la ligne du fichier sur laquelle on est
    vector<string> liste;
    string espace = " \t";



    if(!mon_flux)//Si le fichier n'arrive pas à etre ouvert
    {

        cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else //Sinon
    {
        cout << "\t\t\t\t||--------------------PROFILS--------------------||" << endl;
        while(getline(mon_flux, lecture))//On parcourt le fichier ligne par ligne
        {

            if(lecture == "PFL:") //Si on tombe sur une ligne où est écrit "PFL:" marquant le debut d'un profil
            {
                //  cout <<"\t\t\t\t\t\t\t"<< lecture << endl;//On affiche "PFL:"
                for(int j = 0; j < 1; j++)//Pour les 2 lignes qui suivent(nom du profil et nombre de comptence)
                {
                    getline(mon_flux, lecture);//On récupere la ligne
                    //cout <<"\t\t\t\t\t\t\t"<< lecture << endl; //On l'affiche
                    lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                    liste.push_back(lecture);//On ajoute à la suite du vecteur

                }

            }

        }
    }
    sort(liste.begin(), liste.end());

    int num = 1;
    for(auto const &P : liste)
    {
        cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
        cout <<"\t\t\t\t|\t"<<num<<"--"<< P << endl;
        num++;
    }
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout << endl;
}



void just_show_professionnals(string cheminFichier)//Lister tous les Professionnels
{


    ifstream mon_flux(cheminFichier.c_str());//On ouvre le fichier en mode Lecture

    vector<string> liste;
    string espace = "\t";

    //int tmp;
    int t=0;
    string temp;
    string lecture;//Contiendra chaque ligne courante du fichier en lecture

    if(!mon_flux)
    {

        cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else
    {
        cout << "\t\t\t\t||--------------------PROFESSIONNELS--------------------||" << endl;
        while(getline(mon_flux, lecture))//Tant qu'on récupere une ligne dans le fichier
        {
            t=0;
            temp="";
            if(lecture == "PRO:")//On tombe sur un Professionnels
            {
                //cout << "\t\t\t\t\t\t\t"<<lecture<< endl;//On affiche "PRO:"
                for(int j = 0; j < 2; j++)//Pour les 2 prochaines lignes (nom,prenom)
                {
                    getline(mon_flux, lecture);//On recupere la ligne i
                    lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation

                    temp=temp+" "+lecture;
                    t=1;

                }
                if(t==1)
                {

                    liste.push_back(temp);//On ajoute à la suite du vecteur
                }

            }

        }
    }

    sort(liste.begin(), liste.end());//Trier en ordre alphabetique

    int num = 1;
    for(auto const &P : liste)
    {
        cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
        cout <<"\t\t\t\t|\t"<<num<<"--"<< P << endl;
        num++;
    }
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout << endl;
}


void show_professionnals_profil_1(int nbrCmpPfl, vector<string>& competences,string cheminFichier)
{
    ifstream mon_flux(cheminFichier.c_str());//On ouvre le fichier en mode Lecture
    string espace="\t";
    int nbrCmpPro, total(0);
    vector<string> liste;
    string lecture;
    if(!mon_flux)
    {

        cout <<"Il y a eu une erreur lors de l'affichage du programme !";
    }
    else
    {
        while(getline(mon_flux, lecture))
        {

            if(lecture == "PRO:")//Si on tombe sur un professionnel
            {
                string results;//On crée une variable result1 qui va contenir le nom le prenom et le nombre de cpt du professionnel
                for(int j = 0; j < 2; j++)
                {

                    getline(mon_flux, lecture);
                    lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                    results=results+" "+lecture;

                }
                getline(mon_flux, lecture);
                lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                istringstream(lecture) >> nbrCmpPro;//cm dab on convertit le nombre de competence en int

                int cmptrouv(0);
                for(int i = 0; i < nbrCmpPro; i++ )//On parcourt les competences du professionnel
                    {
                        getline(mon_flux, lecture);
                        lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                        for(const auto &item : competences)
                        {
                            if(equal(item.begin(), item.end(), lecture.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))
                            {
                                cmptrouv=cmptrouv+1;//On incrémente le nombre total de competences trouvées
                            }
                        }

                    }


                if(cmptrouv==nbrCmpPfl)//Si le nombre de competences trouvées est égale au nombre de competences du profil
                {

                        liste.push_back(results);//On ajoute à la suite du vecteur
                        total++;


                }

            }
        }

        if(total==0)
        {
            cout<<endl<<"\t\t\t\t\tNous avons trouve aucun professionnel correspondant a votre profil."<<endl;
        }
        else
        {
               cout<<endl<<"\t\t\t\t\tNous avons trouve "<<total<<" professionnel(s) correspondant a votre profil."<<endl;
               cout<<"\t\t\t\t\tVoici la liste des professionnels correspondant a ce Profil:"<<endl;
               sort(liste.begin(), liste.end());

                int num = 1;
                cout << endl;
                for(auto const &P : liste)
                {
                    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
                    cout <<"\t\t\t\t|\t"<<num<<"--"<< P << endl;
                    num++;
                }
                cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
                cout << endl;
        }

    }


}


void show_professionnals_profil(string cheminFichier)//Afficher les professionnels correspondant à un profils
{
    vector<string> competence;
    string nomProfil, tmp;
    cout<<"\t\t\t\t\tNom du Profil:";
    cin.ignore();
    getline(cin, nomProfil);

    nomProfil="\t"+nomProfil;//Je fais précéder le nom d'une tabulation comme dans le fichier



    ifstream mon_flux(cheminFichier.c_str());//On ouvre le fichier en mode Lecture

    int nmbrCmpPfl, existPfl(0), repet=1;
    string lecture, espace("\t");

    if(!mon_flux)
    {

        cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else
    {
        while(getline(mon_flux, lecture))
        {
            if(lecture == "PFL:")
            {

                for(int j = 0; j < 2; j++)
                {
                    getline(mon_flux, lecture);
                    if(j==0)
                    {
                        if(equal(lecture.begin(), lecture.end(), nomProfil.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))//Si on tombe sur le profil recherché
                        {
                            existPfl++;//Represente le nombre de fois qu'on est tombé sur le profil recherché
                        }
                    }
                }

                if(existPfl==1 && repet!=0)
                {
                    istringstream(lecture) >> nmbrCmpPfl;

                    repet=0;//Pour s'assurer qu'on récupere les competences du profil juste une seule fois
                   for(int i = 0; i < nmbrCmpPfl; i++ )
                    {
                        getline(mon_flux, lecture);
                        lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                        competence.push_back(lecture);//On ajoute à la suite du vecteur


                    }

                }
            }
        }
    }

        if(existPfl==0)//Si on est jamais tombé sur le profil recherché
        {
            cout<<"\t\t\t\t\tCe profil n'existe pas!!!"<<endl;
        }

        else if(existPfl>1)//Si on est tombé plus d'une fois sur le profil
        {
            cout<<"\t\t\t\t\tCe profil est repertorie plus d'une fois. Veuillez vous assurer qu'il est enregistre une seule fois dans le fichier en supprimant les doublons."<<endl;
        }
        else
        {
            sort(competence.begin(), competence.end());//Trier en ordre alphabetique

            cout << endl;
            cout<<"\t\t\t\t\tLes competences du profil "<<nomProfil<<" sont:"<<endl;//On rappelle les competence du profil
            for(auto const &P : competence)
            {
               cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
               cout <<"\t\t\t\t|\t"<< P << endl;

            }
            cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
            cout << endl;

            cout<<"\t\t\t\t\tElles sont au nombre de "<<nmbrCmpPfl<<endl<<endl;
            show_professionnals_profil_1(nmbrCmpPfl, competence, cheminFichier);
            /* On envoie la liste des competence à la fonction show_professionnals_profil_1() qui va comparer les competences des professionnels
            à celles du profil*/
        }


}

void show_professionnals_cmp(string cheminFichier)//Liste des compétences d'un Professionnels spécifique
{
    string nom, prenom, espace="\t";
    cout<<"\t\t\t\t\tNom du Professionnel:";
    cin>>nom;
    cin.ignore();
    nom="\t"+nom;


    cout<<"\t\t\t\t\tPrenom du Professionnel:";
    getline(cin, prenom);
    prenom="\t"+prenom;

    vector<string> liste;
    ifstream mon_flux(cheminFichier.c_str());

    int tmp=0,occurence=0, nmbrCmpPro(0);
    string lecture, prof,proff;

    if(!mon_flux)
    {

        cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else
    {
        while(getline(mon_flux, lecture))
        {

            if(lecture == "PRO:")//Si on tombe sur un professionnel
            {

                for(int j = 0; j < 2; j++)//On parcourt le nom et le prenom qu'on enregistre dans la variable prof
                {
                    getline(mon_flux, lecture);
                    if(j==0)
                    {
                        prof=lecture;
                    }
                    if(j==1)
                    {
                        proff=lecture;

                    }
                }
                getline(mon_flux, lecture);
                istringstream(lecture) >> nmbrCmpPro;


                if( equal(prof.begin(), prof.end(), nom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }) && equal(proff.begin(), proff.end(), prenom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); })  )//On verifie qu'il s'agit du Professionnel concerne
                {
                    occurence=occurence+1;//Le nombre de fois qu'on est tombé sur le professionnel
                }

                if(occurence>0)//Ce bloc n'est realise que si on trouve au moins une fois le professionnel
                {
                    if(tmp==0)//On s'assure que ce bloc ne sera réalisé qu'une seule fois
                    {
                        cout << "\t\t\t\t\t||------------------------IDENTITE------------------------||" << endl;
                        cout << "\t\t\t\t\t|\t" <<prof<<" "<<proff<<endl;
                        cout << "\t\t\t\t\t||--------------------COMPETENCES--------------------||" << endl;
                        tmp=tmp+1;//On s'assure que ce bloc ne sera réalisé qu'une seule fois
                    }

                    if( equal(prof.begin(), prof.end(), nom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }) && equal(proff.begin(), proff.end(), prenom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }) )
                    {
                        if(nmbrCmpPro<1)//Si nombre de competence inferieur a un
                        {
                            cout<<"\t\t\t\t\t||\tPas de Competences;"<<endl;
                        }
                        else
                        {
                            for(int i = 0; i < nmbrCmpPro; i++ )//Si il y a des competence on les affiche
                                {
                                    getline(mon_flux, lecture);
                                    lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                                    liste.push_back(lecture);//On ajoute à la suite du vecteur
                                }
                        }
                    }
                }

            }

        }
            if(occurence==0)
            {
                cout<<"\t\t\t\t\t\tCe Professionnel n'existe pas dans la base"<<endl;
            }
            else
            {
                 sort(liste.begin(), liste.end());//Trier en ordre alphabetique
                int num = 1;

                for(auto const &P : liste)
                {
                    cout <<"\t\t\t\t\t|---------------------------------------------------------------------------------------|\n";
                    cout << "\t\t\t\t\t||\t" << num << " --" << P << endl;
                    num++;
                }
                cout << "\t\t\t\t\t||---------------------------------------------------||" << endl ;
                cout << endl;
            }
    }


}


void show_profil_cmp(string cheminFichier)//Liste des competences d'un Profil specifique
{
    //Pas de commentaires. Meme format que la fonction précédente
    string profil, lecture, pfl, espace=("\t");
    cout<<"\t\t\t\t\tNom du Profil:";
    cin.ignore();
    getline(cin, profil);
    profil="\t"+profil;
    vector<string> liste;


    ifstream mon_flux(cheminFichier.c_str());

    int tmp=0,occurence=0, nmbrCmpPfl(0);

    if(!mon_flux)
    {

        cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else
    {
        while(getline(mon_flux, lecture))
        {

            if(lecture == "PFL:")
            {

                for(int j = 0; j < 2; j++)
                {
                    getline(mon_flux, lecture);
                    if(j==0)
                    {
                        pfl=lecture;
                    }

                }

                istringstream(lecture) >> nmbrCmpPfl;


                if(equal(pfl.begin(), pfl.end(), profil.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))
                {
                    occurence=occurence+1;
                }

                if(occurence>0)
                {
                    if(tmp==0)
                    {
                        cout << "\t\t\t\t\t||------------------------NOM------------------------||" << endl;
                        cout << "\t\t\t\t\t|\t" << pfl<<endl;
                        cout << "\t\t\t\t\t||--------------------COMPETENCES--------------------||" << endl;
                        tmp=tmp+1;
                    }

                    if(equal(pfl.begin(), pfl.end(), profil.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))
                    {
                        if(nmbrCmpPfl<1)
                        {
                            cout<<"\t\t\t\t\t||\tPas de Competences;"<<endl;
                        }
                        else
                        {
                            for(int i = 0; i < nmbrCmpPfl; i++ )
                                {
                                    getline(mon_flux, lecture);
                                    lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                                    liste.push_back(lecture);//On ajoute à la suite du vecteur
                                }
                        }
                    }
                }

            }

        }
            if(occurence==0)
            {
                cout<<"\t\t\t\t\t\tCe Profil n'existe pas dans la base"<<endl;
            }
            else
            {
                 sort(liste.begin(), liste.end());//Trier en ordre alphabetique
                int num = 1;
                for(auto const &P : liste)
                {
                     cout <<"\t\t\t\t\t|---------------------------------------------------------------------------------------|\n";
                    cout << "\t\t\t\t\t||\t" << num << " --" << P << endl;
                    num++;
                }
                cout << "\t\t\t\t\t||---------------------------------------------------||" << endl ;
                cout << endl;
            }
    }


}


void just_show_cmp(string cheminFichier)//Liste des competences
{

   ifstream mon_flux(cheminFichier.c_str());
   vector<string> liste;

    int tmp;
    string lecture, result="", espace="\t";//La liste des competences sera enregistré dans la variable result
    bool t;

    if(!mon_flux)
    {

        cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else
    {
         cout << "\t\t\t\t\t||--------------------COMPETENCES--------------------||" << endl;
        while(getline(mon_flux, lecture))
        {

            if(lecture == "CPT:")//Les competences en vrac
            {
                getline(mon_flux, lecture);
                istringstream(lecture) >> tmp;
                for(int j = 0; j < tmp; j++)
                {
                     t=true;
                        getline(mon_flux, lecture);
                        lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                        for(const auto &item : liste)
                        {
                            if(item == lecture)
                            {
                                t=false;
                            }
                        }
                        if(t)
                        {
                            liste.push_back(lecture);
                        }
                }
            }

            if (lecture == "PFL:")//Les competences disponibles au niveau des Profils
            {
                for(int j = 0; j < 2; j++)
                {
                    getline(mon_flux, lecture);
                }
                istringstream(lecture) >> tmp;
                for(int j = 0; j < tmp; j++)
                {
                    t=true;
                        getline(mon_flux, lecture);
                        lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                        for(const auto &item : liste)
                        {
                            if(equal(item.begin(), item.end(), lecture.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))
                            {
                                t=false;
                            }
                        }
                        if(t)
                        {
                            liste.push_back(lecture);
                        }
                }
            }

            if (lecture == "PRO:")//Les competences disponibles au niveau des Professionnels
            {
                for(int j = 0; j < 3; j++)
                {
                    getline(mon_flux, lecture);
                }

                istringstream(lecture) >> tmp;

                for(int j = 0; j < tmp; j++)
                {
                     t=true;
                        getline(mon_flux, lecture);
                        lecture.erase(0, lecture.find_first_not_of(espace));//Supprimer la tabulation
                        for(const auto &item : liste)
                        {
                            if(equal(item.begin(), item.end(), lecture.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))
                            {
                                t=false;
                            }
                        }
                        if(t)
                        {
                            liste.push_back(lecture);
                        }
                }
            }

        }

    }

     sort(liste.begin(), liste.end());//Trier en ordre alphabetique
                int num = 1;
                for(auto const &P : liste)
                {
                    cout <<"\t\t\t\t\t|---------------------------------------------------------------------------------------|\n";
                    cout << "\t\t\t\t\t||\t" << num << " --" << P << endl;
                    num++;
                }
                cout << "\t\t\t\t\t||---------------------------------------------------||" << endl<<endl ;
}

