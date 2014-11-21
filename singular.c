#include <stdio.h>

double **dmatrix(int, int, int, int);
double *dvector(int, int);
void svdcmp(double **, int, int, double *, double **);

const int dim = 3;

int main() {
	double **a;
	double *w;
	double **u,**v;
	int i,j,k;
	double t;
	double t1[dim],t2[dim];

	a = dmatrix(1,dim,1,dim);
	u = dmatrix(1,dim,1,dim);
	w = dvector(1,dim);
	v = dmatrix(1,dim,1,dim);

	for(i = 1; i <= dim; i++)
		for(j = 1; j <= dim; j++){
			scanf("%le", &a[i][j]);
		}

	for (i=1; i<=dim; i++) {
		for (j=1; j<=dim; j++)
			u[i][j] = a[i][j];
	}

	svdcmp(u,dim,dim,w,v);

	/* Sort the singular values in descending order */
	for (i=1; i<dim; i++) {
		for (j=i+1; j<=dim; j++) {
			if (w[i]<w[j]) {
				t = w[i];
				w[i] = w[j];
				w[j] = t;
				for (k=1;  k<=dim; k++) {
					t1[k] = u[k][i];
					t2[k] = v[k][i];
				}
				for (k=1; k <=dim; k++) {
					u[k][i] = u[k][j];
					v[k][i] = v[k][j];
				}
				for (k=1; k<=dim; k++) {
					u[k][j] = t1[k];
					v[k][j] = t2[k];
				}
			}
		}
	}

	for (i=1; i<=dim; i++) {
		printf("Sigular value %d = %le\n",i,w[i]);

		printf("        vector   = %le",u[1][i]);
		for(j = 2; j <= dim; j++)
			printf( " %le", u[j][i]);

		printf("\n");

	}

	return 0;
}
