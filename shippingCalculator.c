#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>


void facture(int N,char nom[N][100], int quantite[N], float prixU[N], float prixT[N]){
    int i;
printf("\n-------------------------------------------------------------------------------------");
    float Total = 0;
    printf("\nVoici votre facture : ");
    printf("\nNom produit\t\tQuantite\t\tPrix Unitaire\t\tPrix Total");
    for(i=0;i<N;i++){
        printf("\n%s\t\t%d\t\t%f\t\t%f", nom[i], quantite[i], prixU[i], prixT[i]);
        Total += prixT[i];
    }

    printf("\n\nLe total a payer est de ; %.2f DA", Total);
    if(Total > 1000){
        printf("\nVous beneficiez d'une reduction de 10 pourcents sur vos achats");
        Total = Total - (Total * 10)/100;
        printf("\nA present votre total a payer est de %.2fDA", Total);
    }
    printf("\n-------------------------------------------------------------------------------------");

}

void ajouter(int *N,char nom[*N][100], int quantite[*N], float prixU[*N], float prixT[*N]){
    char nouveauNom[100];
    int nouvelleQuantite;
    float nouveauPu;
    float nouveauPt;
  printf("\n---------------------------------------------------------------------------------");

    printf("\nAjout de produit.");
    printf("\n\nVeillez Entrez le nom du produit que vous voulez ajouter : ");
    fgets(nouveauNom, 100, stdin);
    nouveauNom[strcspn(nouveauNom, "\n")] = 0;

    do{
        printf("\nveillez entrez la quantite de votre nouveau produit %s : ", nouveauNom);
        scanf("%d", &nouvelleQuantite);

    }while(nouvelleQuantite<=0);
    getchar();
do{
 printf("\nVeillez entrez le prix unitaire de votre produit %s : ", nouveauNom);
    scanf("%f", &nouveauPu);
}while(nouveauPu =0);
getchar();

   nouveauPt = nouveauPu*nouvelleQuantite;

   (*N)++;
    strcpy(nom[*N - 1], nouveauNom);
    quantite[*N - 1]= nouvelleQuantite;
    prixU[*N - 1]= nouveauPu;
    prixT[*N - 1]= nouveauPt;

    printf("\nVotre nouveau produit %s a bien ete ajouter", nouveauNom);
}

void supprimer(int *N,char nom[*N][100], int quantite[*N], float prixU[*N], float prixT[*N]){
    char nomSupprimer[100];
    int j,i;

    printf("\nveillez entrez le nom du produit a supprimer : ");
    fgets(nomSupprimer, 100, stdin);
    nomSupprimer[strcspn(nomSupprimer, "\n")] = 0;

    for(i=0;i<*N;i++){
        if(strcmp(nom[i], nomSupprimer)==0){
            for(j=i;j<*N-1;j++){
                strcpy(nom[j],nom[j+1]);
                quantite[j]=quantite[j+1];
                prixU[j]=prixU[j+1];
                prixT[j]=prixT[j+1];

            }
            (*N)--;
            i--;
        }
    }
    printf("\nVotre produit %s a bien ete supprimer", nomSupprimer);
    printf("\n--------------------------------------------------------------------");
}

void reclamation(){
    char reclamation[1000];
    char email[200];
    printf("\n--------------------------------------------------------------------");
    printf("\nVeillez entrez votre raclamation : ");
    fgets(reclamation, 1000, stdin);
    reclamation[strcspn(reclamation, "\n")] = 0;
    printf("\nVeillez entrez votre email : ");
    fgets(email, 200, stdin);
    email[strcspn(email, "\n")] = 0;
    int verificatioMail = 0;
    do{
        printf("\nEst ce bien votre email(Tapez 1 pour oui ou 0 pour Non) : %s", email);
        scanf("%d", &verificatioMail);
        getchar();

        if(verificatioMail == 0 ){
            printf("\nVeillez entrez a nouveau votre mail : ");
            fgets(email, 200, stdin);
            email[strcspn(email, "\n")] = 0;
            
        }

    }while(verificatioMail == 0);
    printf("\nVotre reclamation a bien ete enregistrer veillez rester a l'affut de votre boite mail pour recevoir notre reponse.");
    printf("\nNous ferons de notre mieux merci et bonne journee :)");
    printf("\n------------------------------------------------------------------------------------------------");
}

int main(){

    int nbrProduit;

    do{
        printf("\nVeilez entrez le nombre de produits : ");
        scanf("%d", &nbrProduit);
    }while(nbrProduit <= 0);

    getchar();

    char nomProduit[nbrProduit][100];
    int quantite[nbrProduit];
    float prixUnitaire[nbrProduit];
    float prixTotal[nbrProduit];

    int i;
    for(i=0;i<nbrProduit;i++){
        printf("\nVeillez Entrez le nom du produit numero %d : ", i+1);
        fgets(nomProduit[i], 100, stdin);
        nomProduit[i][strcspn(nomProduit[i], "\n")] = 0;

        do{
            printf("\nVeillez Entrez la quantite que vous avez : ");
            scanf("%d", &quantite[i]);
        }while(quantite[i] <= 0);
        getchar();

        do{
            printf("\nVeillez entrez le prix unitaire du produit %s : ", nomProduit[i]);
            scanf("%f", &prixUnitaire[i]);
        }while(prixUnitaire[i]<=0);
        getchar();

        prixTotal[i] = prixUnitaire[i]*quantite[i];
    }

    facture(nbrProduit, nomProduit, quantite, prixUnitaire, prixTotal);

    int choix;

    do{
        printf("\nVoici le menu du programme : ");
        printf("\n1)-Afficher la facture : ");
        printf("\n2)-Ajouter un produit.");
        printf("\n3)-Supprimer un produit.");
        printf("\n4)-Avez vous un reclamatio ? Tapez 1 pour Oui ou 0 pour Non.");
        printf("\n5)-Sortir du programme.");
        printf("\nTapez le numero de l'operation que vous voulez effectuer .");
        scanf("%d", &choix);
        getchar();

        if(choix == 1){
            facture(nbrProduit, nomProduit, quantite, prixUnitaire, prixTotal);
        }else if(choix == 2){
            ajouter(&nbrProduit,nomProduit,quantite,prixUnitaire, prixTotal);
        }else if(choix == 3){
             supprimer(&nbrProduit,nomProduit,quantite,prixUnitaire, prixTotal);
        }else if(choix == 4){
            reclamation();
        }

        int poursuivre = 0;
        printf("\nVoulez poursuivre a nouveau ? tapez 1 pour Oui et 0 pour Non : ");
        scanf("%d", &poursuivre);
        getchar();
    }while(choix != 5 || poursuivre == 0);
    printf("\n---------------------------------------------------------------------");
    printf("\nNotre etablissement vous souhaitre une tres bonne journee");



  return 0;
}