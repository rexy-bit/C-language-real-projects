#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>


void stock(int N,char nom[N][100], int type[N], int annee[N], int duree[N]){
    int i;
    printf("\n----------------------------------------------------------------------------------");
    printf("\nVoici votre stock : ");
    printf("\nTitre\t\tType\tannee\tduree");
    for(i=0;i<N;i++){
        printf("\n%s\t\t%d\t%d\t%d", nom[i], type[i], annee[i], duree[i]);
    }
    printf("\n----------------------------------------------------------------------------------");
}

void specifique(int N,char nom[N][100], int type[N], int annee[N], int duree[N]){
    int i;
    int typeSpe;
    printf("\n---------------------------------------------------------");
    do{
        printf("\nveillez choisir le type de media que vous voulez afficher : ");
        scanf("%d", &typeSpe);
    }while(typeSpe<1 || typeSpe>3);
    getchar();
     printf("\nVoici les medias de type %d : ", typeSpe);
     bool trouve = 0;

     for(i=0;i<N;i++){
        if(type[i]==typeSpe){
              trouve = 1;
                     printf("\n%s\t\t%d\t%d\t%d", nom[i], type[i], annee[i], duree[i]);
        }
     }

     if(trouve == 0){
        printf("\nIl existe aucun media de type %d : ", typeSpe);
     }

}

void recherche( int N,char nom[N][100], int type[N], int annee[N], int duree[N]){
    char nomRecherche[100];
    printf("\nVeillez entrez le nom du media que vous recherchez : ");
    fgets(nomRecherche, 100, stdin);
    nomRecherche[strcspn(nomRecherche, "\n")] = 0;
    bool trouve = 0;
    int i=0;
    while(i<N && trouve == 0){
        if(strcmp(nom[i], nomRecherche) == 0){
            trouve = 1;
        }else{
            i++;
        }
    }

    if(trouve == 1){
        printf("\nLe media titre %s existe dans le tableau");
    }else{
         printf("\nLe media titre %s n'existe pas dans le tableau");
    }
}

void ajouter( int *N,char nom[*N][100], int type[*N], int annee[*N], int duree[*N]){
       
       printf("\n---------------------------------------------------------------------");
       printf("\nAjout de media");
       char nomNouveau[100];
       int typeNouveau;
       int anneeNouveau,dureeNouveau;

       printf("\nveillez entrez le titre du nouveau media que vous voulez enregistrez : ");
       fgets(nomNouveau, 100, stdin);
       nomNouveau[strcspn(nomNouveau, "\n")] = 0;

       do{
        printf("\nveillez entrez le type du media %s : ", nomNouveau);
        scanf("%d", &typeNouveau);
       }while(typeNouveau<1 && typeNouveau>3);
 getchar();
       do{
        printf("\nveillez entrez l'annee du media %s : ", nomNouveau);
        scanf("%d", &anneeNouveau);
       }while(anneeNouveau<0 && anneeNouveau > 2025);
 getchar();
       do{
        printf("\nveillez entrez la duree du media %s : ", nomNouveau);
         scanf("%d", &dureeNouveau);
       }while(dureeNouveau<=0);
        getchar();

        (*N)++;
        strcpy(nom[*N-1], nomNouveau);
        type[*N - 1] = typeNouveau;
        annee[*N - 1] = anneeNouveau;
        duree[*N - 1] = dureeNouveau;

        printf("\nVotre nouveau media %s a etait a ajouter avec succes. ");
        printf("\n-----------------------------------------------------------------------");
}

void supprimer( int *N,char nom[*N][100], int type[*N], int annee[*N], int duree[*N]){
    char nomAsupprimer[100];
    printf("\n-----------------------------------------------------------------------");
    printf("\nVeillez entrez le nom a supprimer : ");
    fgets(nomAsupprimer, 100, stdin);
    nomAsupprimer[strcspn(nomAsupprimer, "\n")] = 0;

    int i,j;
    for(i=0;i<*N;i++){
        if(strcmp(nom[i], nomAsupprimer) == 0){
            for(j=i;j<*N-1;j++){
                strcpy(nom[j],nom[j+1]);
                type[j] = type[j+1];
                annee[j] = annee[j+1];
                duree[j] = duree[j+1];

            }
            (*N)--;
            i--;
        }
    }

    printf("\nVotre media %s a etait supprimer avec succes", nomAsupprimer);
    printf("\n-----------------------------------------------------------------------");

}

int main(){

    int nbrMedia;

    do{
        printf("\nVeillez entres le nombre de media que vous voulez initialement stocker : ");
        scanf("%d", &nbrMedia);
    }while(nbrMedia <= 0);
    getchar();

    char nomMedia[100][nbrMedia];
    int typeMedia[nbrMedia];
    int anneeMedia[nbrMedia];
    int dureeMedia[nbrMedia];

    printf("\nNotation !");
    printf("\nLe type sera prit de tel façon : \n- numero 1 pour film\n- numero 2 pour musique\n- numero 3 pour livre");

    int i;
    printf("\nRemplissage du mediatheque : ");
    for(i=0;i<nbrMedia;i++){
       printf("\nVeillez entrez le nom du media : ");
       fgets(nomMedia[i], 100, stdin);
       nomMedia[i][strcspn(nomMedia[i], "\n")] = 0;

       do{
        printf("\nVeillez entrez le type du media : ");
        scanf("%d", &typeMedia[i]);
       }while(typeMedia[i]<1 && typeMedia[i]>3);
        getchar();
       do{
        printf("\nVeillez entrez l'annee de publication de '%s' : ", nomMedia[i]);
        scanf("%d", &anneeMedia[i]);
       }while(anneeMedia[i]<0 || anneeMedia[i]>2025);
       getchar();

       do{
        printf("\nveillez entrez la duree du media '%s' : ", nomMedia[i]);
        scanf("%d", &dureeMedia[i]);
       }while(dureeMedia[i]<=0);
       getchar();



    }


    stock(nbrMedia, nomMedia,typeMedia,anneeMedia,dureeMedia) ;

    int choix;
      int poursuivre = 0;
    do{

        printf("\nVoici le menu de notre mediatheque : ");
        printf("\n1-Afficher le stock.");
        printf("\n3-Afficher un type specifique.");
        printf("\n3-Rechercher un media par son type.");
        printf("\n4-Ajouter un media.");
        printf("\n5-Supprimer un media.");
        printf("\n6-Quitter.");
        scanf("%d", &choix);
        getchar();

        if(choix == 1){
                stock(nbrMedia, nomMedia,typeMedia,anneeMedia,dureeMedia) ;
        }else if(choix == 2){
            specifique(nbrMedia, nomMedia,typeMedia,anneeMedia,dureeMedia);
        }else if(choix == 3){
            recherche(nbrMedia, nomMedia, typeMedia, anneeMedia, dureeMedia);
        }else if(choix == 4){
            ajouter(&nbrMedia,nomMedia,typeMedia, anneeMedia, dureeMedia);
        }else if(choix == 5){
            supprimer(&nbrMedia, nomMedia, typeMedia, anneeMedia, dureeMedia);
        }

    
      do{
        printf("\nVoulez vous poursuivre (tapez 1 pour oui ou 0 pour non) : ");
        scanf("%d", &poursuivre);
      }while(poursuivre<0);
      getchar();

    }while(choix != 6 || poursuivre != 0);
  printf("\n------------------------------------------------------------------------");
    printf("\nBonne journee");

    return 0;
}