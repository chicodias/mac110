/*************************************************************************
**        FRANCISCO ROSA DIAS DE MIRANDA                                **
**                                          4402962                     **
**************************************************************************/

//UTILIZAR O PARAMETRO -lm NO GCC

#include <stdio.h>
#include <math.h>

#define MAXBR 255 //brilho maximo do arquivo ppm
#define XMAX 1024
#define YMAX 768

int main(){
  static int r[XMAX][YMAX], g[XMAX][YMAX], b[XMAX][YMAX], iter[XMAX][YMAX]; //matrizes de cor e registradora das iteraçoes de cada Z
  int i, imax, kmin = 0, kmax = 0;
  int hx, hy, hxres = XMAX, hyres = YMAX; //coords onsceen e tam. max. de img.
  FILE *fp;
  double aux, x, y, cx, cy, cxmin, cymin, cxmax, cymax;
  double p, q, m; //variaveis para calculo das cores

  fp = fopen("mandel.ppm","w");

  //entrada de dados pelo user
  printf("Digite o numero de iteracoes: ");
  scanf("%d", &imax);
  printf("Digite as coordenadas de P1 e P2: ");
  scanf("%lf %lf %lf %lf",&cxmin, &cymin, &cxmax, &cymax);

  //imprimindo o cabeçalho do arquivo
  fprintf(fp, "P3\n%d %d\n%d\n", hxres, hyres, MAXBR);

  for (hy = 0; hy < hyres; hy++)
    {//transpondo o pixel para c em y
      cy =   cymin + (double)hy * ((cymax-cymin)/hyres);

      for(hx = 0; hx < hxres; hx++)
	{   //transpondo o pixel para c em x
	  cx = cxmin + (double)hx * ((cxmax-cxmin)/hxres);
	  //primeira iteracao da formula de recorrencia
	  x = 0.0;
	  y = 0.0;
	  for (i = 0; i < imax && (x*x + y*y) < 4; i++)
	    {
	      aux = x;
	      x = x*x-y*y+cx;
	      y = 2.0*aux*y+cy;
	    }
	  iter[hx][hy] = i;

	  if(iter[hx][hy] < imax)
	    {
	      //pontos fora do conjunto. obtendo kmin e kmax
	      if (iter[hx][hy] > kmax)
		kmax = iter[hx][hy];
	      else if (iter[hx][hy] < kmin)
		kmin = iter[hx][hy];
	    }
	  else // pontos no conjunto = amarelinho
	    {
	      r[hx][hy]  = 200;
	      g[hx][hy]  = 200;
	      b[hx][hy]  = 0;
	    }
	}
    }

  for (hy = hyres-1; hy > 0; hy--)
    {
      for (hx = 0; hx < hxres; hx++)
	{
	  if(iter[hx][hy] < imax)
	    {
	      //calculando as cores para elementos fora do conjunto e seus respectivos pesos
	      p = (log(iter[hx][hy] - kmin + 1)) / (log(kmax - kmin + 1));
	      q = 1.0 - p;
	      m = ((4*p)+(6*q))/10;


	      r[hx][hy]  = 205 *m;
	      g[hx][hy]  = 225 *p;
	      b[hx][hy]  = 230 *q;
	    }
	  //imprimindo imagem em arquivo
	  fprintf(fp,"%d %d %d\n",r[hx][hy], g[hx][hy], b[hx][hy]);
	}
    }

  fclose(fp);
  return 0;
}
