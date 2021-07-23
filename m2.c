#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mkl.h>

void inverse(double* A, int N1) {
	lapack_int *IPIV = (lapack_int *)malloc(N1 * sizeof(lapack_int));
	int LWORK = N1*N1;
	//double *WORK = (double *)malloc(LWORK * sizeof(double));
	int INFO;

	LAPACKE_dgetrf(LAPACK_ROW_MAJOR,N1,N1,A,N1,IPIV);
	LAPACKE_dgetri(LAPACK_ROW_MAJOR,N1,A,N1,IPIV);

	free(IPIV);
	//free(WORK);
}

int main(){
    
int m;
m=2;
double p1,p2,p12,q1,q2,q12,pq12,pq21,r;
int i,j;
FILE* fp;
fp=fopen("f.out","w");

printf ("Enter probabilities:\n");
printf ("p1\n");
scanf ("%lf", &p1);
printf ("p2\n");
scanf ("%lf", &p2);
printf ("p12\n");
scanf ("%lf", &p12);
printf ("q1\n");
scanf ("%lf", &q1);
printf ("q2\n");
scanf ("%lf", &q2);
printf ("q12\n");
scanf ("%lf", &q12);
printf ("pq12\n");
scanf ("%lf", &pq12);
printf ("pq21\n");
scanf ("%lf", &pq21);
r = 1-p1-q1-p2-q2-p12-q12-pq12-pq21;



    double A [6*6];
    
    for (i=0; i<6; i++) {
        for (j=0; j<6; j++) {
            A[i*6+j]=0;
        }
        
    }

   // 1-я строка
   A[0*6+1]=p1+pq12;
   A[0*6+2]=p2+pq21;
   A[0*6+4]=p12;
   A[0*6+0]=r+q1+q2+q12;

   //2
   A[1*6+3]=p1;
   A[1*6+4]=p2+pq12;
   A[1*6+2]=+pq21;
   A[1*6+0]=q1+q12;
   A[1*6+1]=r+q2;
   
   //3

   A[2*6+4]=p1+pq21;
   A[2*6+5]=p2;
   A[2*6+1]=pq12;
   A[2*6+0]=q2;
   A[2*6+2]=r+q12+q1;
   
   //4


   A[3*6+1]=q1+q12;
   A[3*6+4]=q2;
   A[3*6+3]=r;

   //5
   

   A[4*6+2]=q1;
   A[4*6+1]=q2;
   A[4*6+0]=q12;
   A[4*6+4]=r;
   
   //6


   A[5*6+4]=q1;
   A[5*6+2]=q2;
   A[5*6+1]=q12;
   A[5*6+5]=r;

     
     for (i=0; i<6; i++) {
      for (j=0; j<6; j++) {
          
    fprintf(fp," %f ", A[i*6+j]);
            
       }
        
       fprintf(fp,"\n");
        
    
        
    }
   
    for (i=0; i<6; i++) {
 
        for (j=0; j<6; j++) {
          if(i==j){ A[i*6+j]=1-A[i*6+j];}
           else{A[i*6+j]=0-A[i*6+j];}
 
            
        }

        
    }
fprintf(fp,"\n");
//printf("inverse");
fprintf(fp,"\n");
    inverse(A, 6);
    
     for (i=0; i<6; i++) {
      for (j=0; j<6; j++) {
          
    fprintf(fp," %f ", A[i*6+j]);
            
       }
        
       fprintf(fp,"\n");
        
    
        
    }
        
printf("\n");
    
    double t;
    t=0;

   
        for (i=0; i<6; i++) {
            t=t+A[0*6+i];
 
        }
        
  
    printf("t = %f\n", t);


    return 0;
}
