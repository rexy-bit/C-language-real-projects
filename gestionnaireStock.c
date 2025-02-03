#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


void afficher(int N,char nom[N][100], int quantite[N], int prixU[N], int code[N]){
    int i;
     printf("\n----------------------------------------------------------------------------");
    printf("\nVoici l'etat de votre stock : ");
     printf("\nNom\t\tQuantite\t\tPrix Unitaire\t\tCode");
    for(i=0;i<N;i++){
       printf("\n%s\t\t%d\t\t%d\t\t%d", nom[i], quantite[i], prixU[i], code[i]);
    }
}

void rechercher(int N,char nom[N][100], int quantite[N], int prixU[N], int code[N]){
  int i;
  int recode;
  int pi;
  printf("\nVeillez Entrer le code du produit que vous voulez recherchez : ");
  scanf("%d", &recode);
  getchar();

  bool trouve = 0;
  i = 0;
  while(i<N && trouve == 0){
    if (code[i] == recode){
        pi = i;
        trouve = 1;
    }
  }
  if(trouve){
    printf("\nle produit %s existe dans le stock sa quantite est de %d et son prix est de %d", nom[pi], quantite[pi], prixU[pi]);
  }else{
    printf("\nLe produit du nom de code est %d n'existe pas", recode);
  }
}

void vendre(int N,char nom[N][100], int quantite[N], int prixU[N], int code[N]){
    int i;
    int copro;
    int numero;
    printf("\nveillez Entrez le code du produit que vous voulez vendre : ");
    scanf("%d", &copro);
    getchar();

    int quantiteProduit;

    for(i=0;i<N;i++){
     if(code[i]==copro){
        quantite[i] = quantiteProduit;
        break;
     }
    }
    do{
  printf("\nVeillez entrez la quantite du produit que vous voulez acheter : ");
    scanf("%d", &numero);
    }while(numero<=quantiteProduit);
  
    getchar();

    for(i=0;i<N;i++){
        if(code[i]==copro){
            quantite[i] -= numero;
             printf("\nla quantite restante est : %d", quantite[i]);
             break;
        }
    }
    
}

void ajouter(int *N,char nom[*N][100], int quantite[*N], int prixU[*N], int code[*N]){

   int i;

   char nouveauNom[100];
   int nouvelleQuantite;
   int nouveauPrix;
   int nouveauCode;

   printf("\nVeillez Entrez le nouveau nom de produit que vous voulez ajouter : ");
   fgets(nouveauNom, 100, stdin);
   nouveauNom[strcspn(nouveauNom, "\n")] = 0;

   do{
    printf("\nveillez entre la quantite du produit %s : ", nouveauNom);
    scanf("%d", &nouvelleQuantite);
   }while(nouvelleQuantite<=0);

   do{
    printf("\nveillez ntrez le prix du produit %s : ", nouveauPrix);
    scanf("%d", &nouveauPrix);
   }while(nouveauPrix<=0);

   printf("\nVeillez Entrez le code du nouveau produit %s :  ", nouveauNom);
   scanf("%d", &nouveauCode);
   getchar();

   (*N)++;
   strcpy(nom[*N - 1], nouveauNom);
   quantite[*N - 1] = nouvelleQuantite;
   prixU[*N - 1] = nouveauPrix;
   code[*N - 1] = nouveauCode;

}

void supprimer(int *N,char nom[*N][100], int quantite[*N], int prixU[*N], int code[*N]){
    int i;
    int codeProduitAsupprimer;
     printf("\nVeillez Entrez le code du produit a supprimer : ");
     scanf("%d", &codeProduitAsupprimer);
     getchar();

     int j;
     int pi;
     for(i=0;i<*N;i++){
        if(code[i] == codeProduitAsupprimer){
            for(j=i;j<*N-1;j++){
                strcpy(nom[j], nom[j+1]);
                quantite[j]=quantite[j+1];
                prixU[j] = prixU[j+1];
                code[j]=code[j+1];
                
            }
      (*N)--;
      i--;
      pi = i;
        }
     }
     printf("\nle produit %s a bien ete supprimer", nom[pi]);
}
int main(){

    int nbrProduit;

    do{
        printf("\nVeillez Entrez le nombre de produits dans votre magasin : ");
        scanf("%d", &nbrProduit);
    }while(nbrProduit < 0);
    getchar();

    char nomProduit[nbrProduit][100];
    int quantiteProduit[nbrProduit];
    int prixUnitaire[nbrProduit];
    int codeProduit[nbrProduit];

    int i;
    for(i=0;i<nbrProduit;i++){
        printf("\nVeillez Entrez le nom du produit numero %d : ", i+1);
        fgets(nomProduit[i],100,stdin);
        nomProduit[i][strcspn(nomProduit[i], "\n")] = 0;

        do{
            printf("\nVeillez entrez la quantite de %s que vous avez : ", nomProduit[i]);
            scanf("%d", &quantiteProduit[i]);
        }while(quantiteProduit[i]<=0);
        getchar();

        do{
            printf("\nveillez Entrez le prix unitaire de %s : ", nomProduit[i]);
            scanf("%d", &prixUnitaire[i]);
        }while(prixUnitaire[i]<=0);
        getchar();

        printf("\nVeillez Entrez le code du produit %s : ", nomProduit[i]);
        scanf("%d", &codeProduit[i]);
        getchar();
    }
  printf("\n----------------------------------------------------------------------------");
    printf("\nVoici l'etat de votre stock : ");
     printf("\nNom\t\tQuantite\t\tPrix Unitaire\t\tCode");
    for(i=0;i<nbrProduit;i++){
       printf("\n%s\t\t%d\t\t%d\t\t%d", nomProduit[i], quantiteProduit[i], prixUnitaire[i], codeProduit[i]);
    }

    int choix;

    do{
        printf("\nVoici le menu de votre logiciel : ");
        printf("\n1)-Ajouter Afficher l'etat du stock.");
        printf("\n2)-Vendre un produit.");
        printf("_n3)-Rechercher un produit.");
        printf("\n4)-Ajouter un produit.");
        printf("\n5)-Supprimer un produit.");

        printf("\n6)-Quitter le programme.");
        printf("\nVeillez entrez le numero de la tache que vous voulez : ");
        scanf("%d", &choix);
        getchar();

        if(choix == 1){
            afficher(nbrProduit, nomProduit,quantiteProduit,prixUnitaire,codeProduit);
        }else if(choix == 2){
            vendre(nbrProduit, nomProduit,quantiteProduit,prixUnitaire,codeProduit);
        }else if(choix == 3){
            rechercher(nbrProduit, nomProduit,quantiteProduit,prixUnitaire,codeProduit);
        }else if(choix == 4){
            ajouter(&nbrProduit, nomProduit,quantiteProduit,prixUnitaire,codeProduit);
        }else if(choix == 5){
            supprimer(&nbrProduit, nomProduit,quantiteProduit,prixUnitaire,codeProduit);
        }


    }while(choix != 6);
    printf("\nBonner journee");

    return 0;
    
}