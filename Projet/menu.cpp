#include "Menu.h"


void menu(string cheminFichier)
{


    char i;
    int choix;

do
{
	system("color 2f");
	system("cls");
	cout<<"Un Logiciel de QUALITE";
	cout<<"\t\t\t\t\t\t\t\t\t\t  Tous droits Reserves"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t     --GESTION DES COMPETENCES--"<<endl;
	cout<<"\t\t\t\t\t\t\t       -----------------------"<<endl;



	cout <<"\n\t\t\t\t\t\t\t|-------------------------------------|\n";
    cout <<"\t\t\t\t\t\t\t|\t\tMENU                  |" << endl;
    cout <<"\t\t\t\t\t\t\t|\t\t                      |" << endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t1-- Ajouter une competence a un profil \n" << endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t2-- Retirer une competence a un profil \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t3-- Ajouter une competence a un professionnel  \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t4-- Retirer une competence a un professionnel \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t5-- Lister toutes les competences presentes dans le fichier  \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t6-- Lister tous les profils presents dans le fichier    \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t7-- Lister tous les professionnels presents dans le fichier \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t8-- Lister toutes les competences d'un profil specifique  \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t9-- Lister toutes les competences d'un professionnel specifique \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t10- Lister tous les professionnels correspondant a un profil specifique \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t11- Sauvegarder dans un nouveau fichier sous l'extension .cpt \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t12- A Propos de l'application \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";
    cout <<"\t\t\t\t|\t13- QUITTER \n"<< endl;
    cout <<"\t\t\t\t|---------------------------------------------------------------------------------------|\n";

	cout<<"\t\t\t\t\t\t\tVotre Choix:";
	cin>>choix;
	switch(choix)
		{
            case 1:
            {
                system("cls");
                cout<<"\t\t\t\tVeuillez vous assurer de strictement respecter les accents si il y en a tel que dans le fichier."<<endl<<endl;
                ajout_cmp_pfl(cheminFichier);
                cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                        break;

            }

            case 2:
            {
                system("cls");
                 cout<<"\t\t\t\tVeuillez vous assurer de strictement respecter les accents si il y en a tel que dans le ficher."<<endl<<endl;
                retirer_cmp_pfl(cheminFichier);
                cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                        break;
            }

            case 3:
            {
                system("cls");
               cout<<"\t\t\t\tVeuillez vous assurer de strictement respecter les accents si il y en a tel que dans le fichier."<<endl<<endl;
                ajout_cmp_pro(cheminFichier);
                cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                        break;
            }

            case 4:
            {
                system("cls");
cout<<"\t\t\t\tVeuillez vous assurer de strictement respecter les accents si il y en a tel que dans le fichier."<<endl<<endl;
                retirer_cmp_pro(cheminFichier);
                cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                        break;
            }


            case 5:
            {
                     system("cls");
                     just_show_cmp(cheminFichier);
                     cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                        break;
            }
            case 6:
                {
                     system("cls");
                     just_show_profils(cheminFichier);
                     cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                        break;
                }

            case 7 :
                {
                     system("cls");
                     just_show_professionnals(cheminFichier);
                     cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                        break;
                }

            case 8:
                {
                    system("cls");
                    cout<<"\t\t\t\tVeuillez vous assurer de strictement respecter les accents si il y en a tel que dans le fichier."<<endl<<endl;
                    show_profil_cmp(cheminFichier);
                    cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                    cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                    break;
                }

            case 9:
                {
                    system("cls");
                    cout<<"\t\t\t\tVeuillez vous assurer de strictement respecter les accents si il y en a tel que dans le fichier."<<endl<<endl;
                    show_professionnals_cmp(cheminFichier);
                    cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                    cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                    break;
                }

            case 10 :
                {cout<<"\t\t\t\tVeuillez vous assurer de strictement respecter les accents si il y en a tel que dans le fichier."<<endl<<endl;cout<<"\t\t\t\tVeuillez vous assurer de strictement respecter la casse telle que dans le fichier."<<endl<<endl;
                     show_professionnals_profil(cheminFichier);
                     cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                    break;
                }

                 case 11 :
                {
                    string nomFichier,tmp,lecture;
                     system("cls");
                     cout<<"\t\t\t\tNom du nouveau fichier sans extension:";
                     cin.ignore();
                     getline(cin, nomFichier);
                     nomFichier=nomFichier+".cpt";
                     ofstream flux(nomFichier.c_str());
                     fstream flux_2(cheminFichier.c_str());
                     while(getline(flux_2, lecture))
                     {
                         tmp=tmp+lecture+"\n";

                     }
                     flux<<tmp;

                     cout<<"\n\t\t\t\tSauvegarde bien effectuee!!!";
                     cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=13;
                     }
                    break;
                }


            case 12:
                {
                    system("cls");
                    cout<<"\t\t\t\t\t\t\t REMERCIEMENTS"<<endl;
                    cout<<"\t\t\t\t\t\t\t -------------"<<endl<<endl;
                    cout<<"\t\t\t\tCe programme a ete realise par les etudiants de l'IFRI L2 2022-2023 du groupe 11 C++"<<endl;
                    cout<<"\t\t\t\t\t\t\t Il s'agit de: \n \t\t\t\t\t\t\t1-BOTON Elfriede \n \t\t\t\t\t\t\t2-LALEYE Charlene \n \t\t\t\t\t\t\t3-SONON Charbel \n \t\t\t\t\t\t\t4-ZOGLOBOSSOU Beni \n \t\t\t\t\t\t\t5-AINAN Noel \n \t\t\t\t\t\t\t6-AMIDOU Anifath \n \t\t\t\t\t\t\t7-BABIO Ahmed \n \t\t\t\t\t\t\t8-DOUMATE Valery \n \t\t\t\t\t\t\t9-ADJOVI Primael \n \t\t\t\t\t\t\t10-CHEDEME Eunock \n \t\t\t\t\t\t\t11-SOSSOU Nelson"<<endl;
                    cout<<"\t\t\t\t En Esperant qu'il puisse combler vos attentes *^____^* "<<endl;
                    cout<<"\n\t\t\t\tPour retourner au menu appuyer sur n'importe quel touche et pour quitter appuyez sur 0:";
                     cin>>i;

                     if(i=='0')
                     {
                         choix=12;
                     }
                        break;
                }
            case 13:
                {
                   choix=13;
                   break;
                }

            default:
                {
                    cout<<"Veuillez reverifier votre choix"<<endl;
                    break;
                }
		}

}while (choix!=13);


}
