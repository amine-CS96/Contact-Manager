typedef struct data{
char nom[50] ;
char prenom[50];
long num ;
char gmail[66];
}data ;
typedef struct liste{
data contact ;
struct liste * next;
struct liste * prev;
}liste ;

liste * sais_contact(){
liste *p ;
p =(liste *)malloc(sizeof(liste));
if(p==NULL){
    perror("Erreur d'allocation  !!");
    exit(0);
    }
    printf("\n (^-^)-------------  Inserer le nouveau contact:-------------\n");
     printf("Nom : ");
     scanf(" %[^\n]s",&p->contact.nom);

     printf("Prenom : ");
     scanf(" %[^\n]s",&p->contact.prenom);

     printf("Numero de telephone : ");
    scanf("%ld",&p->contact.num);

     printf("Adresse email  : ");
    scanf(" %[^\n]s",&p->contact.gmail);
     printf("\n");

p->next=p->prev=NULL ;
return p ;
}
liste *  ajout_contact(liste *debut){
liste* cel ;
liste* tmp =debut ;
cel=sais_contact() ;

if(debut==NULL)
 debut= cel;

else{
while(tmp->next!=NULL)
   tmp=tmp->next ;

cel->prev=tmp ;
tmp->next=cel;

}

return debut ;
}

void afficher_Liste(liste *ls){

liste *tmp=ls ;
int cmp =0 ;
if (ls==NULL){
    perror("\n!ERREUR : la liste est vide (-_-) \n ");
    return ;
}
    else{
    printf("\n (^-^)----------------------- Voici la liste des  contacts :---------------------\n");
     while(tmp!=NULL){
     cmp++ ;
     printf("\n --> les informations de contact %d : \n",cmp);
     printf(" Nom  : %s \n",tmp->contact.nom);
     printf(" Prenom : %s \n",tmp->contact.prenom);
     printf(" Numero de telephone : %ld \n",tmp->contact.num);
     printf(" Adresse email  : %s \n",tmp->contact.gmail);
     printf("\n");

        tmp=tmp->next ;
     }
      printf("\n------------------------------------------------------------------------------------\n\n");
     printf("\n");
    }
}

liste * supression_contact(liste * debut,char * nom ,char *prenom ){
  liste * tmp = debut ;
  liste * tmp2 = debut ;
 if(debut==NULL){
 printf(" \n !!-->ERREUR:la liste est vide !!!");
 return;
 }

  if(strcmp(debut->contact.nom,nom)==0 && strcmp(debut->contact.prenom,prenom)==0){

    if (debut->next==NULL ){
        debut=debut->next ;
        free(tmp);
        }
    else{
    debut=debut->next ;
    debut->prev=NULL ;
    free(tmp);
   }
   printf("\n (^_^)--> Suppression avec success .\n");
   return debut ;
  }
    tmp=tmp->next ;
while(tmp!=NULL){
  if(strcmp(tmp->contact.nom,nom)==0 && strcmp(tmp->contact.prenom,prenom)==0 ) {
    if(tmp->next==NULL){
     tmp->prev->next=tmp->next ;
     free(tmp);
      }
    else{
     tmp->prev->next=tmp->next ;
     tmp->next->prev=tmp->prev ;
     free(tmp);
    }
    break ;
  }
   tmp=tmp->next ;
}

   if(tmp==NULL)
    perror("\n !!--> ERREUR:l'element n'existe pas dans la liste \n \n!!");
   else
     printf("\n (^_^)--> Suppression avec success .\n");

    return debut ;
}

liste * modifier_contact(liste * debut,char * nom ,char *prenom ){

  liste * tmp = debut ;
  liste * tmp2 = debut ;
 if(debut==NULL){
 printf(" \n !!--> ERREUR:la liste est vide !!!");
 return ;
 }


while(tmp!=NULL){
  if(strcmp(tmp->contact.nom,nom)==0 && strcmp(tmp->contact.prenom,prenom)==0 ) {
    printf("\n ------------------- Modifier le contact  nomme '%s %s'  : ------------------\n",nom,prenom) ;
     printf("Nom : ");
     scanf(" %[^\n]s",&tmp->contact.nom);

     printf("Prenom : ");
     scanf(" %[^\n]s",&tmp->contact.prenom);

     printf("Numero de telephone : ");
    scanf(" %ld",&tmp->contact.num);

     printf("Adresse email  : ");
    scanf(" %[^\n]s",&tmp->contact.gmail);
     printf("\n");
     printf("\n (^_^)--> Modification avec success .\n");
    return debut ;
  }
   tmp=tmp->next ;
}
   if(tmp==NULL)
    perror("\n !ERREUR:l'element n'existe pas dans la liste \n \n!!");

    return debut ;
}
void Inserer_contact(char *f_pers,liste *debut ){
FILE *fw2;
liste * tmp =debut ;
fw2= fopen(f_pers,"a");

if(fw2==NULL){
   printf(" !!--> Erreur d'ouverture de fichier '%s' !",f_pers);
   return ;
}
int cmt = 0 ;
while (tmp!=NULL){
cmt++ ;
 fprintf(fw2,"-------------------------------les informations de contact  %d  :-----------------------------\n",cmt);
     fprintf(fw2,"Nom : %s \n",tmp->contact.nom);
     fprintf(fw2,"Prenom : %s \n",tmp->contact.prenom);
     fprintf(fw2,"Numero de telephone  :%ld\n",tmp->contact.num);
     fprintf(fw2,"Adresse gmail  : %s \n",tmp->contact.gmail);
     fprintf(fw2,"---------------------------------------------------------------------------------------------\n\n");
tmp=tmp->next ;
}
printf("\n (^_^)--> sauvegarde avec success .\n") ;
  fclose(fw2);
}
void Charge_contact(char *f_pers){
FILE *pr;
char aff_pers[555];
pr= fopen(f_pers, "r");

  if(pr==NULL){
   puts("\n (-_-)--> Erreur d'ouverture de fichier contact  !");
   return ;
  }
     while(fscanf(pr," %[^\n]s",aff_pers)==1 ) {
         printf(" %s \n\n",aff_pers);
     }

    fclose(pr);
}
