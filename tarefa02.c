/***************************************************************
 **                                                           **
 **   Francisco Rosa Dias de Miranda             4402962      **
 **                                                           **
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int pc,p,pb,px,troca,i=0,n,carro;
    float porcento;

    srand(time(NULL));

    printf("Problema das portas do Silvio Santos.\nNumero de iteracoes da simulacao: ");
    scanf("%d",&n);
    printf("Deseja trocar de porta? (0-nao 1-sim): ");
    scanf("%d",&troca);

    while(i<n){


        pc = 1+ rand()%3;
        p = 1+rand()%3;
        pb = 1+rand()%3;

        do
        {
            pb = rand() % 3 + 1;
        } while (pb==p||pb==pc);

        px = p;
        if(troca){
            do
            {
                p = rand() % 3 + 1;
            }
            while (px==p||p==pb);
        }

        if (p==pc)
            carro++;
        i++;
        }

    porcento = (carro*100)/((float)n);

    printf("Ganhou o carro em %.2f%% das vezes.\n",porcento);


return 0;
}
