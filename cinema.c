#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int main(){

    int nbrSalles;
    int i;

    printf("\nVeillez entrez le nombre de salles disponibles : ");
    scanf("%d", &nbrSalles);

    int salles[nbrSalles];

    printf("\nSaisie de nombre de places dans chaque salle : ");
    for(i=0;i<nbrSalles;i++){
        printf("\nVeillez entrez le nombre de places dans la salle %d : ", i+1);
        scanf("%d", &salles[i]);
    }
    
    
    printf("\nVoici les salles aves pour chaque salles le nombre de places disponibles : ");
    for(i=0;i<nbrSalles;i++){
        printf("\nLe nombre de places dans la salle %d est : %d", i+1, salles[i]);

    }

    int operation;
    
 
do{

       printf("\nVoici le menu du programme : ");
    printf("\n- Tapez 1 poour la reservation de places ");
    printf("\n- Tapez 2 pour afficher le nombre de places disponibles danjs chaque salle");
    printf("\n-Tapez 3 pour quitter le programme\n");
    scanf("%d", &operation);

  if(operation == 1){


 int nombrePlaces = 0;
    int numeroSalle = 0;
    
    printf("\nBienvenu dans le programme qui vous permet de reserver des places : ");
    printf("\n-------------------------------------------------------");
    
       do{
        printf("\nveillez entrez le numero de la salle que vous voulez choisir : ");
        scanf("%d", &numeroSalle);
       }while(numeroSalle < 0 || numeroSalle > nbrSalles);

       do{
         printf("\nVeillez entrez le nombre de places que vous voulez choisir dans la salle : ");
         scanf("%d", &nombrePlaces);
       }while(nombrePlaces<=0 && nombrePlaces > salles[numeroSalle - 1]);

       salles[numeroSalle - 1] -= nombrePlaces;
       printf("\nVotre resercation est reussi vous disposez de %d places dans la salle numero %d", nombrePlaces, numeroSalle);

       printf("\nLe nombre de places disponible dans toutes les salles est : ");
       for(i=0;i<nbrSalles;i++){
        printf("\nSalle %d : %d places", i+1, salles[i]);
       }


  }else if(operation == 2){
       printf("\nVoici le nombre de places disponible dans chaque salle : ");

       for(i=0;i<nbrSalles;i++){
        printf("\nSalle %d : %d places", i+1,salles[i]);
       }
  }

   
    }while(operation != 3);

    printf("\nFin du programme");


   return 0;
}
