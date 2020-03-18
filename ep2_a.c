/*************************************************************************
**        FRANCISCO ROSA DIAS DE MIRANDA                                ** 
**                                          4402962                     **
**                                                                      **
**                    MAC110 - INTRODUCAO A COMPUTACAO                  **
**************************************************************************/

#include <stdio.h>
#define MAXBR 10 //brilho maximo no arquivo pgm
#define XMAX 1024
#define YMAX 768

int main(){

  static int b[XMAX][YMAX];
  int i, imax, hx, hy, hxres=XMAX, hyres=YMAX;
  FILE *fp;
  double aux, x, y, cx, cy, cxmin, cymin, cxmax, cymax;

  fp = fopen("mandel.pgm","w");
  
  printf("Digite o numero de iteracoes: ");
  scanf("%d", &imax);
  printf("Digite as coordenadas de P1 e P2: ");
  scanf("%lf %lf %lf %lf",&cxmin, &cymin, &cxmax, &cymax);
  
  //formatacao .pgm
  fprintf(fp, "P2\n%d %d\n%d\n", hxres, hyres, MAXBR);
  
  for (hy = 0; hy < hyres; hy++)
    {
      cy =   cymin + (double)hy * ((cymax-cymin)/hyres);
      
      for(hx = 0; hx < hxres; hx++) 
	{   
	  cx = cxmin + (double)hx * ((cxmax-cxmin)/hxres);
	  
	  x = 0.0;
	  y = 0.0;
	  
	  for (i = 0; i < imax && (x*x + y*y) < 4; i++)
	    {
	      aux = x;
	      x = x*x-y*y+cx;
	      y = 2.0*aux*y+cy;
	      
	    }
	  
	  //pontos pertencentes ao conjunto de mandelbrot
	  if(i == imax)
	    b[hx][hy]  = 0;
	  
	  else //nao pertencentes
	    b[hx][hy] = 10;
    	}
    }	     
  
  //imprimindo a matriz
  for (hy = hyres; hy > 1; hy--)
    {
    for (hx = 0; hx < hxres; hx++)
      {
	fprintf(fp,"%d\n",b[hx][hy]);
      }
    }
  
  fclose(fp);
  return 0;
}
