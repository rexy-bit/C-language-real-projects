#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void liste(int N,char noms[N][100], float notes[N]){
    printf("\n----------------------------------------------------");
    int i;
    for(i=0;i<N;i++){
   printf("\n%s a eu : %.2f/20", noms[i], notes[i]);
    }
    printf("\n----------------------------------------------------");
}

void auDessus(int N,char noms[N][100], float notes[N]){
    int i;
    int cpt = 0;
    for(i=0;i<N;i++){
        if(notes[i]>=10){
            printf("\n%s a eu : %.2lf", noms[i], notes[i]);
            cpt = 1;
        }
    }

    if(cpt == 0){
        printf("\nAucun etudiant a eu au dessus de la moyenne");
    }
}

void enDessous(int N,char noms[N][100], float notes[N]){
    int i;
    int cpt =0;
    getchar();
    for(i=0;i<N;i++){
        if(notes[i]<10){
            printf("\n%s a eu %.2f/20", noms[i], notes[i]);
            cpt = 1;
            getchar();
        }
    }

    if(cpt == 0){
        printf("\nAucun etudiant a eu en dessous de la moyenne");
    }
}

void moyenne(int N, float notes[N]){
    float moy;
    float S = 0;
    int i;
    printf("\n-----------------------------------------------------------------------");
  printf("\nCalculons la moyenne : ");
    for(i=0;i<N;i++){
        S += notes[i];
    }
    moy = S/N;
    printf("\nLa moyenne de la classe est : %.2f", moy);
}

void afficheMeilleurNote(int N,char noms[N][100], float notes[N]){
 float max = notes[0];
 int pmax = 0;
 int i;
 for(i=0;i<N;i++){
    if(max<notes[i]){
      max = notes[i];
      pmax = i;
    }
 }
 printf("\nL'etudiant qui a eu la meilleur notes est %s : %.2f/20 \nFelicitaions ;)", noms[pmax],notes[pmax]);

}

void ajoutEtudiant(int *N,char noms[*N][100], float notes[*N]){
    int i,j;

 printf("\nAjout d'un etudiant : ");
 printf("\n--------------------------------------------------------");
    char nouveauEtudiant[100];
    float nouvelleNote;

    printf("\nVeillez Entrez le nom du nouvel etudiant : ");
    fgets(nouveauEtudiant, 100, stdin);
    nouveauEtudiant[strcspn(nouveauEtudiant, "\n")] = 0;

    printf("\nVeillez Entrez la note de l'etudiant : %s : ", nouveauEtudiant);
    scanf("%f", &nouvelleNote);
 
     (*N)++;
     strcpy(noms[*N-1], nouveauEtudiant);
     notes[*N-1]= nouvelleNote;
     
    
}

void supprimerEtudiant(int *N,char noms[*N][100], float notes[*N]){
       int i,j;
       printf("\nSupprimer un etudiant : ");
       printf("\n----------------------------------------------------------------");
       char nomEtudiant[100];
       printf("\nVeillez Entrez le nom de l'etudiant que vous voulez supprimer : ");
       fgets(nomEtudiant, 100, stdin);
       nomEtudiant[strcspn(nomEtudiant, "\n")] = 0;

       for(i=0;i<*N;i++){
            if(strcmp(nomEtudiant, noms[i])==0){
                for(j=i;j<*N-1;j++){
                    strcpy(noms[j], noms[j+1]);
                    notes[j]= notes[j+1];
                }
                (*N)--;
                i--;
            }
            
       }

       printf("\nL'etudiant %s a bien ete supprimer de la liste", nomEtudiant);
}
int main(){

    printf("\nBienvenu dans le programme qui enregistre et calcule la moyenne des etudiant en module d'algorithmique : ");

    int N;
    
    do{
 printf("\nVeillez entrez le nombre d'etudiant dans la liste : ");
    scanf("%d", &N);
    }while(N<=0);
    getchar();

    int i;
    char nomEtudiant[N][100];

    float noteEtudiant[N];

   

    for(i=0;i<N;i++){
        printf("\nVeillez entrez le nom de l'etudiant numero %d : ", i+1);
        fgets(nomEtudiant[i], 100, stdin);
        nomEtudiant[i][strcspn(nomEtudiant[i], "\n")] = 0;

        printf("\nVeillez Entrez la note de l'etudiant '%s' : ", nomEtudiant[i]);
        scanf("%f", &noteEtudiant[i]);

 
 
              getchar();
    }

     
     printf("\nVoici la liste des notes des etudiant : ");
   liste(N,nomEtudiant,noteEtudiant);

   int choix;

   do{
     
     printf("\nVoici le menu du programmme .");
     printf("\n1)-Afficher la liste des etudiant.");
     printf("\n2)-Afficher La liste des etudiant avec les notes au dessus de la moyenne : ");
     printf("\n3)-Afficher la liste des etudiant avec les notes en dessous de la moyenne. ");
     printf("\n4)-Afficher la meilleur note");
     printf("\n5)-Calculer la moyenne de la classe");
     printf("\n6)-Ajouter un etudiant a la liste");
     printf("\n7)-Supprimer un etudiant de la liste");
     printf("\n8)-Quitter le programme");
     printf("\nVeillez Tapez  le numero de la tache que vous voulez effectuer");
     scanf("%d", &choix);
     getchar();

     if (choix == 1){
        liste(N,nomEtudiant,noteEtudiant);
     }else if(choix == 2){
        auDessus(N,nomEtudiant,noteEtudiant);
     }else if(choix == 3){
        enDessous(N,nomEtudiant,noteEtudiant);
     }else if(choix == 4){
        afficheMeilleurNote(N,nomEtudiant,noteEtudiant);
     }else if(choix == 5){
        moyenne(N,noteEtudiant);
     }else if(choix == 6){
        ajoutEtudiant(&N,nomEtudiant,noteEtudiant);
     }else if(choix == 7){
        supprimerEtudiant(&N,nomEtudiant,noteEtudiant);
     }

     int poursuivre = 0;
     do{
        printf("\nVoulez vous poursuivre ? Tapez 1 pour oui et 0 pour non : ");
        scanf("%d", &poursuivre);
     }while(poursuivre <0);
     getchar();

   }while(choix != 8);
  printf("\n----------------------------------------------------------------");
   printf("\nBonne journee :)");
   

   return 0;
}