#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "contact.h"

int main()
{

char f_pers[55];
int num;
char nom [50] ;
char pren[50] ;
liste *debut =NULL ;


while(num!=7){
        printf("--------------------------------------MENU:-------------------------------------------\n\n");
printf("\t\t   1. Ajouter un nouveau contact .\n");
printf("\t\t   2. Suppression d'un contact .\n");
printf("\t\t   3. Modification d'un contact \n");
printf("\t\t   4. Affichage de tous les contacts.\n");
printf("\t\t   5. Sauvegarde des contact dans un fichier .\n");
printf("\t\t   6. Chargement des contacts depuis un fichier .\n");
printf("\t\t   7. Terminer . \n");
printf("---------------------------------------------------------------------------------------------\n\n");

 printf("-->Veuillez saisir un numero a partir de MENU (1,2...,7) :");
 scanf("%d",&num);
 printf("\n\n");
  switch(num){
    case 1:debut=ajout_contact(debut) ;
    break;
    case 2:printf("-->Veuillez saisir le nom   :");
           scanf(" %[^\n]s",&nom);
           printf("-->Veuillez saisir le prenom  :");
           scanf(" %[^\n]s",&pren);
        debut=supression_contact(debut,nom,pren) ;
    break;
    case 3:printf("-->Veuillez saisir le nom   :");
           scanf(" %[^\n]s",&nom);
           printf("-->Veuillez saisir le prenom  :");
           scanf(" %[^\n]s",&pren);
           debut=modifier_contact(debut,nom,pren) ;
    break;
    case 4:
          afficher_Liste(debut);
    break;
    case 5:printf("-->Veuillez saisir le fichier pour sauvegarde les contacts   :");
           scanf(" %[^\n]s",&f_pers);
           printf("\n");
           Inserer_contact(f_pers,debut) ;
    break;
    case 6:printf("-->Veuillez saisir le fichier pour Chargement des contacts   :");
           scanf(" %[^\n]s",&f_pers);
           Charge_contact(f_pers) ;
    break;

    case 7:printf("--------------------------------Au Revoir ;)!-----------------------------------\n") ;
    break;
    default :printf("\n (-_-) -->Ce numero n'existe pas dans le MENU \n\n") ;
  }
}
    return 0;
}
