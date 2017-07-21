#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<omp.h>

void main(int argc, char *argv[])
{
	int i,j,k=0,n;
	double sigma,Xi,error,big;
	float tol,w;
//	printf("Introduce el tamaño de la matriz A, x y b: ");
//	scanf("%d",&n) ;
	n=atoi(argv[1]);
	printf(" Este es n %d\n", n);
//	printf("Introduce la tolerancia: ");
//	scanf("%lf",&tol) ;
	sscanf(argv[2], "%f", &tol);
	printf(" Este es tol %f\n", tol);
//	printf("Introduce el factor de relajacion: ");
//	scanf("%lf",&w) ;
	sscanf(argv[3], "%f", &w);
        printf(" Este es w %f\n", w);
	clock_t t_ini, t_fin;
	double secs;
	t_ini = clock();

	float **a = (float **)malloc(n * sizeof(float *));
	for (i = 1; i <= n; i++) {
		a[i] = (float *)malloc((n+1) * sizeof(float));
  	}

	float *x = (float *)malloc(n * sizeof(float));

	//float a[n][n+1],x[n];
	//generacion de matriz aleatoria

	int suma;
	for(i = 1; i <= n; i++) {
		suma = 0;
		for(j=1;j<=n+1;j++){
			a[i][j]=rand()%(n+1);
			suma += a[i][j];
		}
		a[i][i] = suma;
		x[i]=0;
	}

	/*float suma;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			suma+=a[i][j];
		}
		a[i][i]=suma+1;
	}*/

	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++){
			printf("%f ",a[i][j]);
		}
		printf("\n");
	}
	//Solucion numerica de la relajacion
	do{
		big=0;
		for(i=1;i<=n;i++){
			sigma=0;
			for(j=1;j<=n;j++){
				if(j!=i){
					sigma+=a[i][j]*x[j];
				}
			}
			//Xi=(1/a[i][i])*(a[i][n+1]-sigma);
			Xi=((w/a[i][i])*(a[i][n+1]-sigma))+((1-w)*x[i]);
			error=fabs(x[i]-Xi);
			if(error>big){
				big=error;
			}
			x[i]=Xi;
 			//printf("\nx[%d] =%f",i,x[i]);
		}
		k++;
	} while(big>=tol);

	t_fin = clock();
	printf("\nConverge en la solucion");
	for(i=1;i<=n;i++){
		printf("\nx[%d]=%f",i,x[i]);
	}
	printf("\nCantidad de iteraciones:\n%d\n", k);
	secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
	printf("Tiempo de ejecucion:\n");
	printf("%.16g milisegundos\n", secs * 1000.0);
	printf("\n");
}

