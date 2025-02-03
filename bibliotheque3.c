#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

    void menu(){
        
      printf("\nVeillez Selectionner la tache que vous voulez effectuer.");
      printf("\n1-Afficher le contenu de votre bibliotheque.")    ;
      printf("\n2-rechercher un livre a partir de son nom.");
      printf("\n3-Ajouter un livre.");
      printf("\n4-Supprimer un livre.");
      printf("\n5-Quitter le programme.");
      
    }

    void afficherBibliothque(int N,char titre[N][100], char auteur[N][100],int annee[N], int code[N]){
          printf("\nvoici le contenu de votre bibliotheque : ");
        printf("\n----------------------------------------------------");
        printf("\nTitre\t\t\tAuteur\t\t\tAnnee de Publication\t\t\tCode");

  int i;
        for(i=0;i<N;i++){
            printf("\n%s\t\t\t%s\t\t\t%d\t\t\t%d", titre[i], auteur[i], annee[i], code[i]);
        }
    }

  void rechercher(int N,char titre[N][100]){
           int i = 0;
           char nomRecherche[100];
           getchar();
      printf("\nveillez Entrez le nom du livre que vous voulez recherchez : ");
      fgets(nomRecherche,100,stdin);
   nomRecherche[strcspn(nomRecherche, "\n")] = 0;

      bool trouve = 0;
  
      while(i <N && trouve == 0){
          if (strcmp(nomRecherche, titre[i]) == 0){
            trouve = 1;
          }
          i++;
      }


      if ( trouve == 1){
        printf("\nLe livre %s existe dans la bibliotheque", nomRecherche);
      }else{
         printf("\nLe livre %s n'existe pas dans la bibliotheque", nomRecherche);
      }
  }
  
  void supprimer(int *N,char titre[*N][100], char auteur[*N][100],int annee[*N], int code[*N]){
    int codeSup;
    printf("\nSuppression de livre : ");
    printf("\n--------------------------------------------------------------------------------");

    printf("\nVeillez Entrez le code du livre que vous voulez supprimer : ");
    scanf("%d", &codeSup);
    getchar();

    int j,i;
    for(i=0;i<*N;i++){
       if(code[i]==codeSup){
        for(j=i;j<*N-1;j++){
            strcpy(titre[j], titre[j+1]);
            strcpy(auteur[j], auteur[j+1]);
            annee[j] = annee[j+1];
            code[j] = code[j+1];
        }
        (*N)--;
        i--;

       }
    }

        printf("\n--------------------------------------------------------------------------------");
    
  }

  void ajouter(int *N,char titre[*N][100], char auteur[*N][100],int annee[*N], int code[*N]){
    char nouveauTitre[100];
    char nouveauAuteur[100];
    int nouvelleAnnee;
    int nouveauCode;
    printf("\nAjoute de livre : ");
  printf("\n------------------------------------------------------------------------");
    printf("\nVeillez Entrez le titre de votre nouveau livre : ");
    fgets(nouveauTitre,100,stdin);
    nouveauTitre[strcspn(nouveauTitre, "\n")] = 0;

    printf("\nVeillez Entrez l'auteur de %s : ", nouveauTitre);
    fgets(nouveauAuteur,100,stdin);
    nouveauAuteur[strcspn(nouveauAuteur, "\n")] = 0;

    printf("\nVeillez Entrez l'annee de publication de %s : ", nouveauTitre);
    scanf("%d", &nouvelleAnnee);
    getchar();


    printf("\nVeillez Entrez le code de votre nouveau livre : ");
    scanf("%d", &nouveauCode);
    getchar();

    (*N)++;

    strcpy(titre[*N-1], nouveauTitre);
    strcpy(auteur[*N-1], nouveauAuteur);
    annee[*N -1]=nouvelleAnnee;
    code[*N-1]=nouveauCode;

    printf("\nLe nouveau livre %s a ete ajouter avec succes : ", nouveauTitre);
    printf("\n----------------------------------------------------------------------");


  }
   

int main(){

printf("\nBienvenu dans votre logiciel bibliotheque.");
printf("\n----------------------------------------------------------------------------------");
    int nbrLivres;


    do{
        printf("\nVeillez Le nombre de livres que vous b*voulez initialement stocker : ");
        scanf("%d", &nbrLivres);
    }while(nbrLivres<=0);
    getchar();

    char titreLivre[nbrLivres][100];
    char auteurLivre[nbrLivres][100];
    int anneeLivre[nbrLivres];
    int codeLivre[nbrLivres];

    int i;
    for(i=0;i<nbrLivres;i++){
        printf("\nVeillez Entrez le titre du livre numero %d : ", i+1);
        fgets(titreLivre[i], 100, stdin);
        titreLivre[i][strcspn(titreLivre[i], "\n")] = 0;

        printf("\nVeillez Entrez le nom de l'auteur du livre '%s' : ", titreLivre[i]);
        fgets(auteurLivre[i], 100, stdin);
        auteurLivre[i][strcspn(auteurLivre[i], "\n")]= 0;

        do{
            printf("\nVeillez Entrez l'annee de publication du livre '%s' : ", titreLivre[i]);
            scanf("%d", &anneeLivre[i]);
        }while(anneeLivre[i]<=0 || anneeLivre[i]>2025);
        getchar();

        do{
            printf("\nVeillz Entrez le code du livre %s : ", titreLivre[i]);
            scanf("%d", &codeLivre[i]);
        }while(codeLivre[i]<0);
        getchar();
        
    }

          printf("\nvoici le contenu de votre bibliotheque : ");
        printf("\n----------------------------------------------------");
        printf("\nTitre\t\t\tAuteur\t\t\tAnnee de Publication\t\t\tCode");
        printf("\n---------------------------------------------------------------------------");

        for(i=0;i<nbrLivres;i++){
            printf("\n%s\t\t\t%s\t\t\t%d\t\t\t%d", titreLivre[i], auteurLivre[i], anneeLivre[i], codeLivre[i]);
        }
         printf("\n---------------------------------------------------------------------------");
         printf("\n");

       
 int choix;
        do{
              int choix;
            menu();
            do{
printf("\nVeillez Entrez le numero De la tache que vous voulez Effectuer : ");
            scanf("%d",&choix);
            }while(choix<1 || choix >5);
            getchar();
            printf("\n");

        if(choix == 1){
            afficherBibliothque(nbrLivres, titreLivre, auteurLivre, anneeLivre, codeLivre);
        }else if(choix == 2){
           rechercher(nbrLivres, titreLivre);
        }else if(choix == 3){
            ajouter(&nbrLivres, titreLivre, auteurLivre,anneeLivre,codeLivre);
        }else if(choix == 4){
            supprimer(&nbrLivres, titreLivre, auteurLivre,anneeLivre,codeLivre);
        }
        
        int Poursuivre = 0;

        do{
            printf("\nVoulez vous poursuivre le programme Tpez 1 pour oui et 0 pour non : ");
            scanf("%d", &Poursuivre);
        }while(Poursuivre<0);
        getchar();

     printf("\n------------------------------------------------------------------------------------");
            
        }while(choix != 5);
printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        printf("\nBonne journnee et merci de nous avoir choisi :)");
        printf("\n---------------------------------------------------------------------");

        return 0;

}
