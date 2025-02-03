#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


void liste(int N, char nom[N][100], char numero[N][100], char adresse[N][100]){
    printf("\n-------------------------------------------------------------");
    int i;
    printf("\nVoici le liste de vos contacts : ");
    printf("\nNom\t\tNumero de telephone\t\tAdresse");
    for(i=0;i<N;i++){
       printf("\n%s\t\t%s\t\t%s", nom[i], numero[i], adresse[i]);
    }
    printf("\n-------------------------------------------------------------");

}

void Recherche(int N, char nom[N][100], char numero[N][100], char adresse[N][100]){
    char nomRecherche[100];
    int i;

    printf("\n-------------------------------------------------------------");
        printf("\nVeillez entrez le nom du contact que vous voulez recherchez : ");
         fgets(nomRecherche, 100, stdin);
         nomRecherche[strcspn(nomRecherche, "\n")] = 0;

         bool trouve = 0;
         i = 0;
         int pi;
         while(i<N && trouve == 0){
            if(strcmp(nom[i], nomRecherche) == 0){
                trouve = 1;
                pi = i;
            }else{
                i++;
            }
         }

         if(trouve == 1){
            printf("\nLe contact %s a bien etait trouver dans la liste et voici ses conrdonees : ", nomRecherche);
            printf("\nNumero : %s\nAdresse : %s", numero[pi], adresse[pi]);
         }else{
            printf("\nLe nom %s ne figure pas dans la liste de vos contacts", nomRecherche);
         }
    printf("\n-------------------------------------------------------------");
}

void modification(int N, char nom[N][100], char numero[N][100], char adresse[N][100]){

    printf("\n-------------------------------------------------------------");
    char nomModification[100];
    printf("\nModification d'un contact : ");
    char newNom[100], newNumero[100],newAdresse[100];
  int i;
    bool trouve = false;
    int pi;
    do{
printf("\nVeillez entrez le nom du contact que vous voulez modifiez : ");
    fgets(nomModification, 100, stdin);
    nomModification[strcspn(nomModification, "\n")] = 0;
 
 i = 0;
 
     while(i<N && trouve == 0){
        if(strcmp(nom[i], nomModification) == 0){
            trouve = 1;
            pi  = i;
        }else{
            i++;
        }
     }
     
    }while(trouve == 0);


    int poursuivre;
  int varChange;



  do{


 printf("\nVoici la liste des modification : ");
    printf("\n1)-Changez le nom.");
    printf("\n2)-Changer le numero.");
    printf("\n3)-Changer L'adresse.");

    do{
printf("\nTapez le numero de la tache que vous voulez effectuer : ");
    scanf("%d", &varChange);
    }while(varChange < 1 || varChange > 3);
    
    getchar();

    if(varChange == 1){
    printf("\nVeillez entrez le nouveau nom du contact %s : ", nomModification);
    fgets(newNom, 100, stdin);
    newNom[strcspn(newNom, "\n")] = 0;
    strcpy(nom[pi], newNom);
   
   printf("\nLe nom du contact %s a etait modifier avec succes pas %s : ", nomModification, newNom);


    }else if(varChange == 2){

        printf("\nVeillez entrez le nouveau numero du contact %s : ", nomModification);
        fgets(newNumero, 100, stdin);
        newNumero[strcspn(newNumero, "\n")] = 0;
        strcpy(numero[pi], newNumero);
        printf("\nLe numero du contact %s a etait modifier avec succes", nomModification);


    }else if(varChange == 3){

         printf("\nVeillez entrez la nouvelle adresse du contact %s : ", nomModification);
         fgets(newAdresse, 100, stdin);
         newAdresse[strcspn(newAdresse, "\n")] = 0;
         strcpy(adresse[pi], newAdresse);
         printf("\nL'adresse du contact %s a etait modifier pas %s", nomModification, newAdresse);


    }
getchar();
    do{
        printf("\nVoulez effectuer d'autre modifications au contact %s ? \nTapez 1 pour oui ou 0 pour Non : ", nomModification);
        scanf("%d", &poursuivre);
    }while(poursuivre < 0);
  getchar();


  }while(poursuivre != 0);

  printf("\n\nLes modification on etait effectuer avec succes.");

   
printf("\n-------------------------------------------------------------");

}

void Ajouter(int *N, char nom[*N][100], char numero[*N][100], char adresse[*N][100]){
    
printf("\n-------------------------------------------------------------");
printf("\nAjout d'un contact : ");
    char newNom[100];
    char newNumero[100], newAdresse[100];

    printf("\nveillez entrez le nom du nouveau contact : ");
    fgets(newNom, 100, stdin);
    newNom[strcspn(newNom,"\n")] = 0;

    printf("\nVeillez entrez le numero du nouveau contact que vous voulez ajouter %s : ", newNom);
    fgets(newNumero, 100, stdin);
    newNumero[strcspn(newNumero, "\n")] = 0;

    printf("\nVeillez entrez l'adresse du nouveau contact %s : ", newNom);
    fgets(newAdresse, 100, stdin);
    newAdresse[strcspn(newAdresse, "\n")] = 0;

    (*N)++;
    strcpy(nom[*N -1], newNom);
    strcpy(numero[*N-1], newNumero);
    strcpy(adresse[*N-1], newAdresse);
    
    printf("\nLe contact %s a etait ajouter avec succes ! ", newNom);
    printf("\n-------------------------------------------------------------");

}

void supprimer(int *N, char nom[*N][100], char numero[*N][100], char adresse[*N][100]){
    char nomSup[100];
    printf("\n-------------------------------------------------------------");
    printf("\nSupression d'un contact : ");
  bool trouve = false;
  int i,j;
    do{
      printf("\nveillez entrez le nom du contact que vous voulez supprimer : ");
      fgets(nomSup, 100, stdin);
      nomSup[strcspn(nomSup, "\n")] = 0;

      i = 0;
      while(i<*N && trouve == 0){
        if(strcmp(nom[i], nomSup) == 0){
            trouve = 1;
        }else{
            i++;
        }
      }

    }while(trouve == 0);

    for(i=0;i<*N;i++){
        if(strcmp(nom[i], nomSup) == 0){
        for(j=i;j<*N;j++){
            strcpy(nom[j], nom[j+1]);
            strcpy(numero[j], numero[j+1]);
            strcpy(adresse[j], adresse[j+1]);

        }
     (*N)--;
     i--;
        }
    }

    printf("\nLe contact %s a etait supprimer avec succes", nomSup);
    printf("\n-------------------------------------------------------------");

}

int main(){

    int nbrContacts;
    
    do{
        printf("\nVeillez entrez le nombre de contacts que vous voulez initialemnt stocker : ");
        scanf("%d", &nbrContacts);

    }while(nbrContacts <= 0);
    getchar();

    char nomContact[nbrContacts][100];
    char numero[nbrContacts][100];
    char adresse[nbrContacts][100];
    
    printf("\nRemplissage du carnet de contacts : ");
    int i;
      int comfirmation;
    for(i=0;i<nbrContacts;i++){
        printf("\nVeillez entrez le nom du contact numero %d : ", i+1);
        fgets(nomContact[i], 100, stdin);
        nomContact[i][strcspn(nomContact[i], "\n")] = 0;
  do{
     printf("\nVeillez entrez le numero de telephone du contact ' %s ' : ", nomContact[i]);
        fgets(numero[i], 100, stdin);
        numero[i][strcspn(numero[i], "\n")] = 0;

        printf("\nEst ce le numero de ' %s ' : %s", nomContact[i], numero[i]);
        printf("\nTapez 1 pour oui ou 0 pour non : ");
        scanf("%d", &comfirmation);
        getchar();

        
  }while(comfirmation == 0);

     printf("\nVeillez entrez l'adresse de votre contact ' %s ' : ", nomContact[i]);
     fgets(adresse[i], 100, stdin);
     adresse[i][strcspn(adresse[i], "\n")] = 0;
     
     printf("\nVotre contact ' %s ' a etait ajouter avec succes :  ", nomContact[i]);
   

    
    }

    liste(nbrContacts, nomContact, numero, adresse);

    int pours;

    int choix;
    do{
        printf("\n-------------------------------------------------------------");
        printf("\nVoici le menu de l'application contacts : ");
        printf("\n1-Affichez la liste des contacts.");
        printf("\n2-Recherchez un contact.");
        printf("\n3-Effectuer des modifications sur un contact.");
        printf("\n4-Ajouter un contact.");
        printf("\n5-Supprimer un contact.");
        printf("\n6-Quitter l'application.");
        printf("\nveillez entrez le numero de l'oparation que vous voulez effectuer.");
        scanf("%d", &choix);
        getchar();

        if(choix == 1){
            liste(nbrContacts, nomContact, numero, adresse);
        }else if(choix == 2){
            Recherche(nbrContacts, nomContact, numero, adresse);
        }else if(choix == 3){
            modification(nbrContacts, nomContact, numero, adresse);
        }else if(choix == 4){
            Ajouter(&nbrContacts, nomContact, numero, adresse);
        }else if(choix == 5){
            supprimer(&nbrContacts, nomContact, numero, adresse);
        }

        
        if(choix != 6){
            do{
                printf("\nvoulez vous poursuivre ? \nTapez 1 pour oui ou 0 pour non");
                scanf("%d", &pours);
            }while(pours < 0);
            getchar();
        }


        
    }while(choix != 6 && pours != 0);

    printf("\nBonne journee");


    
}
