/***************************************************************
 **                                                           **
 **   Francisco Rosa Dias de Miranda             4402962      **
 **                                                           **
 ***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int pc,p,pb,px,troca;
    /* pc eh a porta com o carro, p a porta escolhida, pb a porta eliminada e px a porta escolhida antes da troca*/
    srand(time(NULL));

    pc = 1+ rand()%3;

    printf("Problema das portas do Silvio Santos. Escolha sua porta (1-3): ");
    scanf("%d",&p);

    pb=1+rand()%3;
        do
        {
            pb = rand() % 3 + 1;
        } while (pb==p||pb==pc);


    printf("A porta %d contem um bode. Deseja trocar de porta? (0-nao 1-sim): ",pb);
    scanf("%d",&troca);

    px=p;
    if(troca){
        do
        {
            p = rand() % 3 + 1;
        } while (px==p||p==pb);
    }

   if (p==pc)
        printf("parabens, vc ganhou um carro!\n");
    else
        printf("parabens, vc ganhou um bode!\n");

return 0;
}
