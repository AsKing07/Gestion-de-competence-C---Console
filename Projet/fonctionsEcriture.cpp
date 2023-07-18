#include "fonctionsEcriture.h"




using namespace std;


void ajout_cmp_pfl(string cheminFichier)//Ajouter une competence a un profil
{
    string profil, cmp;

    cout<<"\t\t\t\t\tNom du Profil:";
    cin.ignore();
    getline(cin, profil);//On enregistre le nom du profil entré


    cout<<"\t\t\t\t\tCompetence a ajouter:";
    getline(cin, cmp);

    cout<<"\t\t\t\t\tLa competence "<<cmp<<" sera ajoute au profil "<<profil<<endl;

    profil="\t"+profil; //On fait précédé le nom par une tabulation pour que ce soit au format du fichier
    cmp="\t"+cmp;//On fait précédé la competence par une tabulation pour que ce soit au format du fichier




    string tmp1,tmp2;;//Dans la variable tmp1 je vais réécrire le fichier ligne par ligne en prenant soin d'ajouter la competence à la ligne correspondante.
                    //A la fin tmp1 sera reverse dans le fichier


    ifstream mon_flux(cheminFichier.c_str());// On ouvre le fichier en lecture

    string lecture;//La variable lecture contiendra à chaque fois la ligne sur laquelle on est
    int nbrCpt, k=0;  //nbrCpt est le nombre de competence d'un profil. A comprendre un peu plus bas dans le code
    bool t=true; // A comprendre un peu plus bas

    if(!mon_flux) //Si le fichier n'a pas pu s'ouvrir
    {

        cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else //sinin si il a pu s'ouvrir
    {
        while(getline(mon_flux, lecture))//tant qu'il y a une ligne dans le fichier, on lit le fichier ligne par ligne
        {
            tmp1=tmp1+lecture+"\n";//tmp1 recois la ligne actuelle et un retour à la ligne

            if(lecture == "PFL:")// Si on tombe sur un PROFIL
            {

                for(int j = 0; j < 1; j++)
                {
                    getline(mon_flux, lecture);//Vu qu'on etait sur PFL alors la prochaine ligne represente le nom du profil
                    //en se basant sur le format du fichier.Donc à cette etape la variable lecture contient le nom du profil sur lequel on est
                    tmp1=tmp1+lecture+"\n";
                    tmp2=lecture;// tmp2 recoit le nom du profil



                    if(equal(tmp2.begin(), tmp2.end(), profil.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); })) //On vérifie qu'on est sur le profil entré par l'utiliateur
                    {
                        k=k+1;//Si Oui, la variable k qui valait 0 au debut du programme sera implémentée de 1
                              //A la fin si k est tjr egal à 0 alors le profil recherché n'existe pas
                        getline(mon_flux, lecture);//Vu qu'on etait sur le nom du profil; ce getline nous redonne la ligne contenant le nbre de competence
                        istringstream(lecture) >> nbrCpt;//On convertit cette valeur en int dans la variable nbrCpt
                        string u;
                        u=to_string(nbrCpt+1);//Et on la reconverti en string apres lui avec ajouter +1 vu qu'on veut ajouter une competence
                        tmp1=tmp1+"\t"+u+"\n";//Et on réécris la nouvelle valeur du nbr de competence dans tmp1

                            for(int i = 0; i < nbrCpt; i++ )//On parcoure les competence une à une jusqu'à la derniere
                            {
                                getline(mon_flux, lecture);
                                if(equal(lecture.begin(), lecture.end(), cmp.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))//Si on retrouve parmis les competence la competence qu'on veut ajouter
                                {
                                    t=false;//t nous permet de savoir si la competence existe deja. Si t=false alors elle existe deja
                                }

                                         int v;
                                    v=nbrCpt-1; //v nous permet de savoir qu'on est sur la derniere ligne

                                    tmp1=tmp1+lecture+"\n";
                                    if(i==v && t==true)//Si on est sur la derniere et la competence n'existait pas
                                    {
                                        tmp1=tmp1+cmp+"\n";//On rajoute la competence
                                    }

                            }

                    }

                }

            }

        }
    }

    mon_flux.close();//On arrete la lecture du fichier

    if(k==0)//Si le profil n'a pas été retrouvé au moins une fois
    {
        cout<<"\t\t\t\t\tCe profil n'existe pas."<<endl;
    }

    else //Si le profil existe
    {
        if(t)//Si la competence à ajouter n'existait pas
        {
            ofstream monFlux(cheminFichier.c_str());  //On essaye d'ouvrir le fichier en mode ecriture

            if(monFlux)  //On teste si tout est OK
                {
                    monFlux<<tmp1;//On réécrit dans le fichier tmp1 qui contient l'ancien fichier ainsi que la competence ajoutée
                    cout<<"\t\t\t\t\tL'ajout de la compétence a bien ete effectuee"<<endl<<endl;
                    monFlux.close();//On ferme le fichier
                }
            else
                {
                    cout << "\t\t\t\t\tERREUR: Impossible d'ouvrir le fichier." << endl;
                }
        }
        else//Sinon si elle existait
        {
            cout<<"\t\t\t\t\tCette competence existe deja!!"<<endl;
        }

    }

}


void retirer_cmp_pfl(string cheminFichier)//Retirer une competence a un profil
{
    //Meme format que la fonction precedente sauf qu'ici quand on tombe sur la competence a supprimer on ne la reecrit pas dans le fichier
    bool v=false, t=false;
    string profil, cmp;

    cout<<"\t\t\t\t\tNom du Profil:";
    cin.ignore();
    getline(cin, profil);

    cout<<"\t\t\t\t\tCompetence a retirer:";
    getline(cin, cmp);

    cout<<"\t\t\t\tLa competence "<<cmp<<" sera supprimee du profil "<<profil<<endl;

    profil="\t"+profil;
    cmp="\t"+cmp;


    string tmp1,tmp2;


    ifstream mon_flux(cheminFichier.c_str());

    string lecture;
    int nbrCpt, compt=0, comptt=0, comptt2=0;

    if(!mon_flux)
    {

        cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else
    {
        while(getline(mon_flux, lecture))
        {
            tmp1=tmp1+lecture+"\n";//A chaque fois on reecrit la ligne a la suite dans la variable tmp1


            if(lecture=="PFL:")//Si on est sur un Profil
            {


                    getline(mon_flux, lecture);
                    tmp1=tmp1+lecture+"\n";
                    tmp2=lecture;//La variable tmp2 contient le nom du profil actuel



                    if(equal(tmp2.begin(), tmp2.end(), profil.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))//Verifier qu'il s'agit du profil concerné
                    {
                        compt=compt+1;//Le nombre de fois qu'on est tombé sur le profil
                        getline(mon_flux, lecture);
                        istringstream(lecture) >> nbrCpt;
                        tmp1=tmp1+lecture+"\n";


                            for(int i = 0; i < nbrCpt; i++ )
                            {

                                getline(mon_flux, lecture);
                                if(!equal(lecture.begin(), lecture.end(), cmp.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))//Si ce n'est pas la competence a supprimer
                                {
                                   tmp1=tmp1+lecture+"\n";//On recupere la ligne

                                }
                                if(equal(lecture.begin(), lecture.end(), cmp.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))//Si c'est la competence a supprimer, on ne recupere pas la ligne
                                {
                                    comptt=comptt+1;//Le nombre de fois que la competence a ete supprimer
                                    comptt2=comptt2+1;
                                }

                            }

                    }


                }

            }

        }

    mon_flux.close();

    if(compt==0)//Si on est jamais tombé sur le profil
    {
        cout<<"\t\t\t\tCe profil n'existe pas."<<endl;
    }

    else//Si on est tombe au moins une fois sur le profil
    {
        if (comptt==0)//Si on a jamais rencontré la competence à supprimer
        {
            cout<<"\t\t\t\tCette competence n'existe pas."<<endl;
        }
        else
        {
                ofstream monFlux(cheminFichier.c_str());  //On essaye d'ouvrir le fichier

                if(monFlux)  //On teste si tout est OK
                {

                    monFlux<<tmp1;//On reecrit tout le fichier en ecrasant l'ancien contenu
                    monFlux.close();
                     v=true;//Permet de savoir si la reecriture a ete faite

                }
                else
                {
                    cout << "\t\t\t\tERREUR: Impossible d'ouvrir le fichier." << endl;
                }
        }

    }


    if(v)//Si la reecriture a été faite on va reprendre cette fois si le mm processus de lecture et reecriture mais pour modifier le nombre de competence vu qu'une competence a ete supprimee
    {
        tmp1="";
        t=true;
        ifstream mon_flux(cheminFichier.c_str());
        if(!mon_flux)
        {

            cout <<"\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
        }
        else
        {
            while(getline(mon_flux, lecture))
            {
                tmp1=tmp1+lecture+"\n";

                if(lecture == "PFL:")
                {

                    for(int j = 0; j < 1; j++)
                    {
                        getline(mon_flux, lecture);
                        tmp1=tmp1+lecture+"\n";
                        tmp2=lecture;

                        if(equal(tmp2.begin(), tmp2.end(), profil.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))
                        {
                            getline(mon_flux, lecture);
                            istringstream(lecture) >> nbrCpt;

                           string u;
                            u=to_string(nbrCpt-comptt2);//Le nombre de competence moins le nombre de fois que la competence a ete supprimée
                            tmp1=tmp1+"\t"+u+"\n";

                                for(int i = 0; i < (nbrCpt-1); i++ )
                                {

                                    getline(mon_flux, lecture);

                                        tmp1=tmp1+lecture+"\n";
                                }

                        }
                        else
                        {
                            getline(mon_flux, lecture);
                            tmp1=tmp1+lecture+"\n";
                        }

                    }

                }
            }
         }

    }

    mon_flux.close();

    if (t)
    {
        ofstream monFlux(cheminFichier.c_str());  //On essaye d'ouvrir le fichier en ecriture

                if(monFlux)  //On teste si tout est OK
                {
                    monFlux<<tmp1;
                    monFlux.close();
                    cout<<"\t\t\t\tLa suppression a bien ete effectuee!!!"<<endl;
                }
                else
                {
                    cout << "\t\t\t\tERREUR: Impossible d'ouvrir le fichier." << endl;
                }
    }

}


void ajout_cmp_pro(string cheminFichier)
{
    string nom, prenom, cmp;

    cout<<"\t\t\t\t\tNom du Professionnel:";
    cin>>nom;


    cout<<"\t\t\t\t\tPrenom du professionnel:";
    cin.ignore();
    getline(cin, prenom);

    cout<<"\t\t\t\t\tCompetence a ajouter:";
    getline(cin, cmp);

    cout<<"\t\t\t\t\tLe professionnel "<<nom<<" "<<prenom<<" recevra la competence "<<cmp<<endl;

    nom="\t"+nom;
    prenom="\t"+prenom;
    cmp="\t"+cmp;




    string tmp1, prof, proff;


    ifstream mon_flux(cheminFichier.c_str());

    string lecture;
    int nbrCpt, k=0;
    bool t=true;

    if(!mon_flux)
    {

        cout <<"\t\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
    }
    else
    {
        while(getline(mon_flux, lecture))
        {
            tmp1=tmp1+lecture+"\n";

            if(lecture == "PRO:")
            {

                int occurence=0;


                        for(int j = 0; j < 2; j++)
                        {
                            getline(mon_flux, lecture);
                            tmp1=tmp1+lecture+"\n";
                            if(j==0)
                            {
                                prof=lecture;//nom du professionnel actuel
                            }
                            if(j==1)
                            {
                                proff=lecture;//prenom du professionnel actuel

                            }

                        }



                        if( (equal(prof.begin(), prof.end(), nom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); })) && (equal(proff.begin(), proff.end(), prenom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))  )//Si on tombe sur le professionnel recherché
                        {
                            occurence=occurence+1;
                            k=k+1;//Le nombre de fois qu'on est tombe sur le professionnel
                            getline(mon_flux, lecture);
                            istringstream(lecture) >> nbrCpt;
                            string u;
                            u=to_string(nbrCpt+1);
                            tmp1=tmp1+"\t"+u+"\n";
                        }

                        else
                        {
                            getline(mon_flux, lecture);
                            tmp1=tmp1+"\t"+lecture+"\n";
                        }

                        if(occurence>0)
                        {
                            for(int i = 0; i < nbrCpt; i++ )
                            {
                                getline(mon_flux, lecture);
                                if(equal(lecture.begin(), lecture.end(), cmp.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))//On verifie que la competence n'existait pas
                                {
                                    t=false;//t=false si la competence existait deja
                                }

                                         int v;
                                    v=nbrCpt-1;

                                    tmp1=tmp1+lecture+"\n";
                                    if(i==v && t==true)
                                    {
                                        tmp1=tmp1+cmp+"\n";
                                    }

                            }
                        }
                }


                }

            }

        mon_flux.close();



    if(k==0)
    {
        cout<<"\t\t\t\t\tCe professionnel n'existe pas."<<endl;
    }

    else
    {
        if(t==true)
        {
            ofstream monFlux(cheminFichier.c_str());  //On essaye d'ouvrir le fichier

            if(monFlux)  //On teste si tout est OK
                {
                    monFlux<<tmp1;
                    cout<<"\t\t\t\t\tL'ajout de la compétence a bien ete effectuee"<<endl<<endl;
                    monFlux.close();
                }
            else
                {
                    cout << "\t\t\t\t\tERREUR: Impossible d'ouvrir le fichier." << endl;
                }
        }
        else
        {
            cout<<"\t\t\t\t\tCette competence existe deja!!"<<endl;
        }

    }

}


void retirer_cmp_pro(string cheminFichier)
{
    bool v=false, t=false;
    string nom,prenom, cmp;

    cout<<"\t\t\t\t\tNom du Professionnel:";
    cin>>nom;


    cout<<"\t\t\t\t\tPrenom du professionnel:";
    cin.ignore();
    getline(cin, prenom);


    cout<<"\t\t\t\t\tCompetence a retirer:";
    getline(cin, cmp);

     cout<<"\t\t\t\t\tLe professionnel "<<nom<<" "<<prenom<<" ne disposera plus de la competence "<<cmp<<endl;

    nom="\t"+nom;
    prenom="\t"+prenom;
    cmp="\t"+cmp;



    string tmp1,prof,proff;


    ifstream mon_flux(cheminFichier.c_str());//On ouvre le fichier en lecture

    string lecture;//Comme dab lecture contiendra la ligne courante
    int nbrCpt, compt=0, comptt=0, comptt2=0; //L'utilité de ces variable seront expliquée plus bas

    if(!mon_flux)//Si le fichier n'a pas pu etre ouvert
    {

        cout <<"Il y a eu une erreur lors de l'affichage du programme !";
    }
    else//Si Oui
    {
        while(getline(mon_flux, lecture))//On lit le fichier ligne par ligne
        {
            tmp1=tmp1+lecture+"\n";//Dans tmp2 on réécrira tout le fichier sans la competence à supprimer.Ma technique


            if(lecture=="PRO:") //Si on tombe sur un professionnel
            {


                    int occurence=0;//Nous permet de savoir si on est tombé sur le professionnel recherché


                        for(int j = 0; j < 2; j++)//On parcour les 2 lignes suivant "PRO:" (En se refferant au fichier il s'agit du nom et prenom)
                        {
                            getline(mon_flux, lecture);
                            tmp1=tmp1+lecture+"\n";
                            if(j==0)
                            {
                                prof=lecture;//prof contient le nom du professionnel sur lequel on est
                            }
                            if(j==1)
                            {
                                proff=lecture;//proff contient le prenom du professionnel sur lequel on est

                            }

                        }


                        getline(mon_flux, lecture);//Avec cette ligne on recuperer le nombre de competence car c'est ce qui suit le prenom
                        istringstream(lecture) >> nbrCpt;//On le convertit en int dans la variable nbrCpt

                        tmp1=tmp1+lecture+"\n";

                        if( (equal(prof.begin(), prof.end(), nom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); })) && (equal(proff.begin(), proff.end(), prenom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))  )//Si on est exactement sur le professionnel recherche
                        {
                            occurence=occurence+1;//Occurence est incremente
                            compt=compt+1;//compt est incrémenté. A la fin si k=0 alors on est jamais tombé sur le professionnel. Donc il n'existe pas
                        }


                         if(occurence>0)//On est sur le profil recherche
                        {
                            for(int i = 0; i < nbrCpt; i++ )//On parcourt les competences
                            {
                                getline(mon_flux, lecture);
                                if(lecture!=cmp)//Si on n'est pas sur la competence à supprimer
                                {
                                     tmp1=tmp1+lecture+"\n";//On enregistre les autres competences dans tmp1
                                }

                                if(equal(lecture.begin(), lecture.end(), cmp.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))//Si on est sur la competence à supprimer
                                {
                                    comptt=comptt+1;//comptt permet de savoir si la competence à supprimer existe
                                    comptt2=comptt2+1;//comptt2 permettra de savoir cmb de fois la competence a ete supprimer en cas de doublon pour retrancher du nombre total de competence
                                }


                            }
                        }



                    }


                }

            }



    mon_flux.close();//On ferme le fichier

    if(compt==0)//Si le professionnel n'existe pas
    {
        cout<<"Ce professionnel n'existe pas."<<endl;
    }

    else//Si il existe
    {
        if (comptt==0)//Si on est jamais tombé sur la competence à supprimer
        {
            cout<<"Cette competence n'existe pas."<<endl;
        }
        else//Sinon
        {
                ofstream monFlux(cheminFichier.c_str());  //On essaye d'ouvrir le fichier en mode ecriture

                if(monFlux)  //On teste si tout est OK
                {

                    monFlux<<tmp1;//On réécrit tt ca dans le fichier
                    monFlux.close();
                     v=true;//v permet de savoir si la réécriture s'est faite

                }
                else
                {
                    cout << "\t\t\t\t\tERREUR: Impossible d'ouvrir le fichier." << endl;
                }
        }



    //Maintenant il va falloir reparcourir tout le fichier pour changer la valeur du nbre de competence du profil


    if(v)//Si la premiere réécriture a eu lieu
    {
        tmp1="";//On vide tmp1
        t=true; //t permet de savoir si la deuxieme lecture a eu lieu
        ifstream mon_flux("sample.cpt"); //On ouvre le fichier en lecture
        if(!mon_flux)
        {

            cout <<"\t\t\t\t\tIl y a eu une erreur lors de l'affichage du programme !";
        }
        else
        {
            while(getline(mon_flux, lecture))
            {
                tmp1=tmp1+lecture+"\n";

                if(lecture == "PRO:")
                {
                        for(int j = 0; j < 2; j++)
                        {
                            getline(mon_flux, lecture);
                            tmp1=tmp1+lecture+"\n";
                            if(j==0)
                            {
                                prof=lecture;
                            }
                            if(j==1)
                            {
                                proff=lecture;

                            }

                        }

                                 if( (equal(prof.begin(), prof.end(), nom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); })) && (equal(proff.begin(), proff.end(), prenom.begin(),[](char a, char b) { return std::tolower(a) == std::tolower(b); }))  )//Si on est exactement sur le professionnel recherche
                                 {
                                      getline(mon_flux, lecture);
                                        istringstream(lecture) >> nbrCpt;
                                        string u;
                                        u=to_string(nbrCpt-comptt2);//nombre de competence moins le nombre d'occurence de la competence susion
                                        tmp1=tmp1+"\t"+u+"\n";

                                        for(int i = 0; i < (nbrCpt-comptt2); i++ )
                                        {

                                            getline(mon_flux, lecture);

                                            tmp1=tmp1+lecture+"\n";
                                        }
                                 }

                                 else
                                 {
                                      getline(mon_flux, lecture);
                                        istringstream(lecture) >> nbrCpt;

                                        tmp1=tmp1+lecture+"\n";

                                        for(int i = 0; i < (nbrCpt); i++ )
                                        {

                                            getline(mon_flux, lecture);

                                            tmp1=tmp1+lecture+"\n";
                                        }
                                 }



                        }

                    }

                }
        }




    mon_flux.close();

    if (t)//On reecrit le fichier pour la derniere fois
    {
        ofstream monFlux(cheminFichier.c_str());  //On essaye d'ouvrir le fichier

                if(monFlux)  //On teste si tout est OK
                {
                    monFlux<<tmp1;
                    monFlux.close();
                    cout<<"\t\t\t\t\tLa suppression a bien ete effectuee!!!"<<endl;
                }
                else
                {
                    cout << "\t\t\t\t\tERREUR: Impossible d'ouvrir le fichier." << endl;
                }
    }

}
}
