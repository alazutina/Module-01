#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mkl.h>

void inverse(double* A, int N1) {
	lapack_int *IPIV = (lapack_int *)malloc(N1 * sizeof(lapack_int));
	int LWORK = N1*N1;

	int INFO;

	LAPACKE_dgetrf(LAPACK_ROW_MAJOR,N1,N1,A,N1,IPIV);
	LAPACKE_dgetri(LAPACK_ROW_MAJOR,N1,A,N1,IPIV);

	free(IPIV);

}

int main(){
    
int m;
m=8;
double p1,p2,p12,q1,q2,q12,pq12,pq21,r;
int i,j;

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



    double A [101*101];
    
    for (i=0; i<101; i++) {
        for (j=0; j<101; j++) {
            A[i*101+j]=0;
        }
        
    }

   // 1-я строка
   A[0*101+1]=p1+pq12;
   A[0*101+2]=p2+pq21;
   A[0*101+81]=p12;
   A[0*101+0]=q1+q2+q12+r;

   //2
   A[1*101+3]=p1;
   A[1*101+81]=p2+pq12;
   A[1*101+67]=p12;
   A[1*101+0]=q1+q12;
   A[1*101+2]=pq21;
   A[1*101+1]=r+q2;
   
   //3

   A[2*101+81]=p1+pq21;
   A[2*101+5]=p2;
   A[2*101+83]=p12;
   A[2*101+1]=pq12;
   A[2*101+0]=q2+q12;
   A[2*101+2]=q1+r;
   
   //4

   A[3*101+6]=p1;
   A[3*101+67]=p2+pq12;
   A[3*101+69]=p12;
   A[3*101+1]=q1+q12;
   A[3*101+81]=q2+pq21;
   A[3*101+3]=r;

   //5
   
   A[4*101+8]=p2;
   A[4*101+2]=q1;
   A[4*101+1]=q2;
   A[4*101+0]=q12;
   A[4*101+5]=pq21;
   A[4*101+4]=r;
   
   //6

   A[5*101+68]=p1+pq21;
   A[5*101+9]=p2;
   A[5*101+71]=p12;
   A[5*101+1]=pq12;
    A[5*101+81]=q1;
   A[5*101+2]=q2;
   A[5*101+66]=pq12;
   A[5*101+5]=r;

   //7

   A[6*101+10]=p1;
   A[6*101+69]=p2+pq12;
   A[6*101+51]=p12;
   A[6*101+3]=q1;
   A[6*101+67]=q2;
      A[6*101+82]=pq21;
   A[6*101+81]=q12;
   A[6*101+6]=r;

   //8

   A[7*101+12]=p2;
   A[7*101+45]=q1;
   A[7*101+3]=q2;
   A[7*101+1]=q12;
   A[7*101+47]=pq21;
   A[7*101+7]=r;
   
      //9

   A[8*101+13]=p2;
   A[8*101+5]=q1;
   A[8*101+4]=q2;
   A[8*101+2]=q12;
   A[8*101+9]=pq21;
   A[8*101+8]=r;
   
      //10

   A[9*101+71]=p1+pq21;
   A[9*101+14]=p2;
   A[9*101+75]=p12;
   A[9*101+68]=q1;
   A[9*101+5]=q2;
   A[9*101+66]=q12;
      A[9*101+68]=pq12;
   A[9*101+9]=r;


   //11

   A[10*101+15]=p1;
   A[10*101+51]=p2+pq12;
   A[10*101+55]=p12;
   A[10*101+6]=q1;
   A[10*101+69]=q2+pq21;
   A[10*101+67]=q12;
   A[10*101+10]=r;
   

      //12

   A[11*101+17]=p2;
   A[11*101+46]=q1;
   A[11*101+6]=q2;
   A[11*101+3]=q12;
   A[11*101+49]=pq21;
   A[11*101+11]=r;
   
  //13

   A[12*101+18]=p2;
   A[12*101+47]=q1;
   A[12*101+7]=q2;
   A[12*101+45]=q12;
   A[12*101+50]=pq21;
   A[12*101+12]=r;
   

  //14

   A[13*101+19]=p2;
   A[13*101+9]=q1;
   A[13*101+8]=q2;
   A[13*101+5]=q12;
   A[13*101+14]=pq21;
   A[13*101+13]=r;

    //15

   A[14*101+54]=p1+pq21;
   A[14*101+20]=p2;
   A[14*101+59]=p12;
   A[14*101+71]=q1;
   A[14*101+9]=q2;
   A[14*101+68]=q12;
   A[14*101+50]=pq12;
   A[14*101+14]=r;

    //16

   A[15*101+21]=p1;
   A[15*101+55]=p2+pq12;
   A[15*101+29]=p12;
   A[15*101+10]=q1;
   A[15*101+51]=q2;
   A[15*101+69]=q12;
   A[15*101+72]=pq21;
   A[15*101+15]=r;

  //17

   A[16*101+23]=p2;
   A[16*101+48]=q1;
   A[16*101+10]=q2;
   A[16*101+6]=q12;
   A[16*101+52]=pq21;
   A[16*101+16]=r;

  //18

   A[17*101+24]=p2;
   A[17*101+49]=q1;
   A[17*101+11]=q2;
   A[17*101+46]=q12;
   A[17*101+53]=pq21;
   A[17*101+17]=r;

  //19

   A[18*101+25]=p2;
   A[18*101+50]=q1;
   A[18*101+12]=q2;
   A[18*101+47]=q12;
   A[18*101+54]=pq21;
   A[18*101+18]=r;   

   
  //20

   A[19*101+26]=p2;
   A[19*101+14]=q1;
   A[19*101+13]=q2;
   A[19*101+9]=q12;
   A[19*101+20]=pq21;
   A[19*101+19]=r;   

   //21

   A[20*101+59]=p1+pq21;
   A[20*101+27]=p2;
   A[20*101+65]=p12;
   A[20*101+54]=q1+pq12;
   A[20*101+14]=q2;
   A[20*101+50]=q12;

   A[20*101+20]=r;

  //22

   A[21*101+28]=p1;
   A[21*101+29]=p2+pq12;
      A[21*101+37]=p12;
   A[21*101+15]=q1;
   A[21*101+55]=q2;
   A[21*101+51]=q12;
   A[21*101+55]=pq21;
   A[21*101+21]=r;  

    //23
   A[22*101+30]=p2;
   A[22*101+51]=q1;
   A[22*101+15]=q2;
   A[22*101+10]=q12;
   A[22*101+56]=pq21;
   A[22*101+22]=r; 
   
       //24
   A[23*101+31]=p2;
   A[23*101+52]=q1;
   A[23*101+16]=q2;
   A[23*101+48]=q12;
      A[23*101+57]=pq21;
   A[23*101+23]=r; 
   
       //25
   A[24*101+32]=p2;
   A[24*101+53]=q1;
   A[24*101+17]=q2;
   A[24*101+49]=q12;
    A[24*101+58]=pq21;
   A[24*101+24]=r; 
   
       //26
   A[25*101+33]=p2;
   A[25*101+54]=q1;
   A[25*101+18]=q2;
   A[25*101+50]=q12;
       A[25*101+59]=pq21;
   A[25*101+25]=r;
   
          //27
  A[26*101+34]=p2;
   A[26*101+20]=q1;
   A[26*101+19]=q2;
   A[26*101+14]=q12;
         A[26*101+27]=pq21;
   A[26*101+26]=r;

      
          //28
  A[27*101+34]=p1+pq21;
   A[27*101+35]=p2;
     A[27*101+43]=p12;
   A[27*101+59]=q1;
   A[27*101+20]=q2;
   A[27*101+54]=q12;
     A[27*101+26]=pq12;
   //A[27*101+34]=pq21;
   A[27*101+27]=r;

   //29

      A[28*101+36]=p1;
   A[28*101+37]=p2+pq12;
   A[28*101+21]=q1;
   A[28*101+29]=q2;
   A[28*101+61]=q12;
 // A[28*101+37]=pq12;
    A[28*101+60]=pq21;
   A[28*101+28]=r;
   
  //30
  A[29*101+38]=p2;
   A[29*101+55]=q1;
   A[29*101+27]=q2;
   A[29*101+20]=q12;
   A[29*101+61]=pq21;
   A[29*101+29]=r;
    
  //31
  A[30*101+39]=p2;
   A[30*101+56]=q1;
   A[30*101+22]=q2;
   A[30*101+51]=q12;
  A[30*101+62]=pq21;
   A[30*101+30]=r;
   
     //32
   A[31*101+40]=p2;
   A[31*101+57]=q1;
   A[31*101+16]=q2;
   A[31*101+52]=q12;
   A[31*101+63]=pq21;
   A[31*101+31]=r;
   
        //33
   A[32*101+41]=p2;
   A[32*101+58]=q1;
   A[32*101+34]=q2;
   A[32*101+53]=q12;
   A[32*101+64]=pq21;
   A[32*101+32]=r;
   
        //34
   A[33*101+42]=p2;
   A[33*101+59]=q1;
   A[33*101+25]=q2;
   A[33*101+54]=q12;
   A[33*101+65]=pq21;
   A[33*101+33]=r;

      //35
   A[34*101+43]=p2;
   A[34*101+27]=q1;
   A[34*101+26]=q2;
   A[34*101+20]=q12;
      A[34*101+35]=pq21;
   A[34*101+34]=r;

      //36
   A[35*101+43]=p1+pq21;
   A[35*101+44]=p2;
   A[35*101+34]=q1+pq12;
   A[35*101+27]=q2;
   A[35*101+26]=q12;
  // A[35*101+34]=pq12;
   A[35*101+35]=r;
   
         //37

   A[36*101+28]=q1;
   A[36*101+37]=q2;
   A[36*101+29]=q12;

   A[36*101+36]=r;
   
         //38

   A[37*101+60]=q1;
   A[37*101+28]=q2;
   A[37*101+21]=q12;

   A[37*101+37]=r;
   
        //39
 
   A[38*101+61]=q1;
   A[38*101+29]=q2;
   A[38*101+55]=q12;

   A[38*101+38]=r;
   
        //40

   A[39*101+62]=q1;
   A[39*101+30]=q2;
   A[39*101+56]=q12;

   A[39*101+39]=r;

       //41

   A[40*101+63]=q1;
   A[40*101+31]=q2;
   A[40*101+57]=q12;

   A[40*101+40]=r;


       //42

   A[41*101+64]=q1;
   A[41*101+32]=q2;
   A[41*101+58]=q12;

   A[41*101+41]=r;


       //43

       A[42*101+65]=q1;
   A[42*101+33]=q1;
   A[42*101+59]=q2;

   A[42*101+42]=r;


       //44
 
   A[43*101+35]=q1;
   A[43*101+34]=q2;
   A[43*101+27]=q12;
   

   A[43*101+43]=r;

        //45

   A[44*101+43]=q1;
   A[44*101+35]=q2;
   A[44*101+34]=q12;

   A[44*101+44]=r;
  
   

       //46
   A[45*101+7]=p1;
      A[45*101+47]=p2;
         A[45*101+12]=p12;
   A[45*101+2]=q1;
   A[45*101+1]=q2;
   A[45*101+0]=q12;
      A[45*101+3]=pq12;
   A[45*101+5]=pq21;
   A[45*101+45]=r;


       //47
   A[46*101+11]=p1;
    A[46*101+49]=p2;
       A[46*101+17]=p12;
   A[46*101+66]=q1;
   A[46*101+3]=q2;
   A[46*101+1]=q12;
      A[46*101+6]=pq12;
   A[46*101+68]=pq21;

   A[46*101+46]=r;


       //48
   A[47*101+12]=p1;
     A[47*101+50]=p2;
       A[47*101+18]=p12;
   A[47*101+5]=q1;
   A[47*101+45]=q2;
   A[47*101+2]=q12;
   A[47*101+7]=pq12;
      A[47*101+9]=pq21;
   A[47*101+47]=r;
   
         //49
   A[48*101+16]=p1;
      A[48*101+52]=p2;
         A[48*101+23]=p12;
   A[48*101+67]=q1;
   A[48*101+6]=q2;
   A[48*101+3]=q12;
   A[48*101+10]=pq12;
      A[48*101+70]=pq21;
   A[48*101+48]=r;
   
           //50
   A[49*101+17]=p1;
      A[49*101+53]=p2;
         A[49*101+24]=p12;
   A[49*101+68]=q1;
   A[49*101+46]=q2;
   A[49*101+66]=q12;
      A[49*101+11]=pq12;
   A[49*101+71]=pq21;
   A[49*101+49]=r;
   
              //51
   A[50*101+18]=p1;
      A[50*101+54]=p2;
         A[50*101+25]=p12;
   A[50*101+9]=q1;
   A[50*101+47]=q2;
   A[50*101+5]=q12;
   A[50*101+12]=pq12;
      A[50*101+14]=pq21;
   A[50*101+50]=r;
   
   
                 //52
   A[51*101+22]=p1;
      A[51*101+56]=p2;
         A[51*101+30]=p12;
   A[51*101+69]=q1;
   A[51*101+10]=q2;
   A[51*101+6]=q12;
      A[51*101+15]=pq12;
   A[51*101+73]=pq21;
   A[51*101+51]=r;
   
                    //53
   A[52*101+23]=p1;
      A[52*101+57]=p2;
         A[52*101+31]=p12;
   A[52*101+70]=q1;
   A[52*101+48]=q2;
   A[52*101+67]=q12;
      A[52*101+16]=pq12;
   A[52*101+74]=pq21;
   A[52*101+52]=r;
   
                       //54
   A[53*101+24]=p1;
      A[53*101+58]=p2;
         A[53*101+32]=p12;
   A[53*101+71]=q1;
   A[53*101+49]=q2;
   A[53*101+68]=q12;
      A[53*101+17]=pq12;
   A[53*101+75]=pq21;
   A[53*101+53]=r;
   
                          //55
   A[54*101+25]=p1;
      A[54*101+59]=p2;
         A[54*101+33]=p12;
   A[54*101+14]=q1;
   A[54*101+50]=q2;
   A[54*101+9]=q12;
      A[54*101+18]=pq12;
   A[54*101+20]=pq21;
   A[54*101+54]=r;
      
                          //56
   A[55*101+29]=p1;
      A[55*101+61]=p2;
         A[55*101+38]=p12;
   A[55*101+72]=q1;
   A[55*101+15]=q2;
   A[55*101+10]=q12;
      A[55*101+21]=pq12;
   A[55*101+77]=pq21;
   A[55*101+55]=r;
 
                             //57
   A[56*101+30]=p1;
      A[56*101+62]=p2;
         A[56*101+39]=p12;
   A[56*101+73]=q1;
   A[56*101+51]=q2;
   A[56*101+69]=q12;
      A[56*101+22]=pq12;
   A[56*101+78]=pq21;
   A[56*101+56]=r;
   
    
                             //58
   A[57*101+31]=p1;
    A[57*101+63]=p1;
      A[57*101+40]=p1;
   A[57*101+74]=q1;
   A[57*101+52]=q2;
   A[57*101+70]=q12;
     A[57*101+23]=pq12;  
   A[57*101+79]=pq21;
   A[57*101+57]=r;
   
                                //59
   A[58*101+32]=p1;
     A[58*101+64]=p2;
       A[58*101+41]=p12;
   A[58*101+75]=q1;
   A[58*101+53]=q2;
   A[58*101+71]=q12;
      
   A[58*101+24]=pq12;
     A[58*101+80]=pq21;
   A[58*101+58]=r;
   
                                   //60
   A[59*101+33]=p1;
        A[59*101+65]=p2;
           A[59*101+42]=p12;
   A[59*101+20]=q1;
   A[59*101+54]=q2;
   A[59*101+15]=q12;
      
   A[59*101+25]=pq12;
      A[59*101+27]=pq21;
   A[58*101+59]=r;
   
   
                                      //61
   A[60*101+37]=p1;
     
   A[60*101+76]=q1;
   A[60*101+21]=q2;
   A[60*101+15]=q12;
      
   A[60*101+28]=pq12;
   A[60*101+60]=r;
   
   
      
                                      //62
   A[61*101+38]=p1;
   A[61*101+77]=q1;
   A[61*101+61]=q2;
   A[61*101+72]=q12;
      
   A[61*101+29]=pq12;
   A[61*101+61]=r;
   
                                         //63
   A[62*101+39]=p1;
   A[62*101+78]=q1;
   A[62*101+56]=q2;
   A[62*101+73]=q12;
   A[62*101+30]=p12;
   A[62*101+62]=r;
   
   
                                            //64
   A[63*101+40]=p1;     
   A[63*101+79]=q1;
   A[63*101+57]=q2;
   A[63*101+74]=q12;
      
   A[63*101+31]=pq12;
   A[63*101+63]=r;
   
                                              //65
   A[64*101+41]=p1;
       A[64*101+80]=q1;
   A[64*101+58]=q2;
   A[64*101+75]=q12;
         A[64*101+32]=pq12;
          A[64*101+64]=r;
          
                                                        //66
   A[65*101+42]=p1;
       A[65*101+27]=q1;
   A[65*101+59]=q2;
   A[65*101+20]=q12;
         A[65*101+33]=pq12;
          A[65*101+65]=r;
   
          
                                                                 //67
   A[66*101+46]=p1;
    A[66*101+68]=p2;
     A[66*101+49]=p12;
       A[66*101+2]=q1;
   A[66*101+1]=q2;
   A[66*101+0]=q12;
         A[66*101+3]=pq12;
          A[66*101+5]=pq21;
          A[66*101+66]=r;
   
                    
                                                                 //68
   A[67*101+48]=p1;
     A[67*101+70]=p2;
       A[67*101+52]=p12;
       A[67*101+81]=q1;
   A[67*101+3]=q2;
   A[67*101+1]=q12;
         A[67*101+6]=pq12;
               A[67*101+83]=pq12;
          A[67*101+67]=r;
   
                                                                         //69
   A[68*101+49]=p1;
     A[68*101+71]=p2;
       A[68*101+53]=p12;
       A[68*101+5]=q1;
   A[68*101+66]=q2;
   A[68*101+2]=q12;
         A[68*101+46]=pq12;
           A[68*101+9]=pq21;
          A[68*101+68]=r;
 
          
                                                                           //70
   A[69*101+51]=p1;
    A[69*101+73]=p2;
     A[69*101+56]=p12;
       A[69*101+82]=q1;
   A[69*101+6]=q2;
   A[69*101+3]=q12;
         A[69*101+10]=pq12;
              A[69*101+85]=pq21;
          A[69*101+69]=r;   
                                                                            //71
   A[70*101+52]=p1;
    A[70*101+74]=p2;
     A[70*101+57]=p12;
       A[70*101+83]=q1;
   A[70*101+67]=q2;
   A[70*101+81]=q12;
         A[70*101+48]=pq12;
              A[70*101+86]=pq21;
          A[70*101+70]=r;          
          
                                                                             //72
   A[71*101+53]=p1;
    A[71*101+75]=p2;
     A[71*101+58]=p12;
       A[71*101+9]=q1;
   A[71*101+68]=q2;
   A[71*101+5]=q12;
         A[71*101+49]=pq12;
              A[71*101+14]=pq21;
          A[71*101+71]=r;          
                                                                             //73
   A[72*101+55]=p1;
    A[72*101+77]=p2;
     A[72*101+61]=p12;
       A[72*101+84]=q1;
   A[72*101+10]=q2;
   A[72*101+6]=q12;
         A[72*101+15]=pq12;
              A[72*101+88]=pq21;
          A[72*101+72]=r; 
          
                                                                              //74
   A[73*101+56]=p1;
    A[73*101+78]=p2;
     A[73*101+62]=p12;
       A[73*101+85]=q1;
   A[73*101+69]=q2;
   A[73*101+82]=q12;
         A[73*101+51]=pq12;
              A[73*101+89]=pq21;
          A[73*101+73]=r;   
          
                                                                               //75
   A[74*101+57]=p1;
    A[74*101+79]=p2;
     A[74*101+63]=p12;
       A[74*101+86]=q1;
   A[74*101+70]=q2;
   A[74*101+83]=q12;
         A[74*101+52]=pq12;
              A[74*101+90]=pq21;
          A[74*101+74]=r;           
           
                                                                               //76
   A[75*101+58]=p1;
    A[75*101+80]=p2;
     A[75*101+64]=p12;
       A[75*101+10]=q1;
   A[75*101+71]=q2;
   A[75*101+6]=q12;
         A[75*101+53]=pq12;
              A[75*101+20]=pq21;
          A[75*101+75]=r;           
                   
                                                                                  //77
   A[76*101+60]=p1;
   A[76*101+87]=q1;
   A[76*101+15]=q2;
   A[76*101+10]=q12;
      A[76*101+21]=pq12;
   A[76*101+76]=r;     
   
                                                                                     //78
   A[77*101+61]=p1;
   A[77*101+88]=q1;
   A[77*101+72]=q2;
   A[77*101+84]=q12;
      A[77*101+55]=pq12;
   A[77*101+77]=r;   

                                                                                      //79
   A[78*101+62]=p1;
   A[78*101+89]=q1;
   A[78*101+73]=q2;
   A[78*101+85]=q12;
      A[78*101+56]=pq12;
   A[78*101+78]=r;    

                                                                                       //80
   A[79*101+63]=p1;
   A[79*101+90]=q1;
   A[79*101+74]=q2;
   A[79*101+86]=q12;
      A[79*101+57]=pq12;
   A[79*101+79]=r;    
 
   
                                                                                       //81
   A[80*101+64]=p1;
   A[80*101+20]=q1;
   A[80*101+75]=q2;
   A[80*101+14]=q12;
      A[80*101+58]=pq12;
   A[80*101+80]=r;    
   
   
                                                                                          //82
   A[81*101+67]=p1;
   A[81*101+83]=p2;
   A[81*101+70]=p12;
   A[81*101+2]=q1;
   A[81*101+1]=q2;
   A[81*101+0]=q12;
   A[81*101+3]=pq12;
   A[81*101+5]=pq21;
   A[81*101+81]=r;    

                                                                                           //83
   A[82*101+69]=p1;
   A[82*101+85]=p2;
   A[82*101+73]=p12;
   A[82*101+91]=q1;
   A[82*101+3]=q2;
   A[82*101+1]=q12;
   A[82*101+6]=pq12;
   A[82*101+93]=pq21;
   A[82*101+82]=r; 

                                                                                             //84
   A[83*101+70]=p1;
   A[83*101+86]=p2;
   A[83*101+74]=p12;
   A[83*101+5]=q1;
   A[83*101+81]=q2;
   A[83*101+2]=q12;
   A[83*101+67]=pq12;
   A[83*101+9]=pq21;
   A[83*101+83]=r;  
   
                                                                                              //85
   A[84*101+72]=p1;
   A[84*101+88]=p2;
   A[84*101+77]=p12;
   A[84*101+92]=q1;
   A[84*101+6]=q2;
   A[84*101+3]=q12;
   A[84*101+10]=pq12;
   A[84*101+95]=pq21;
   A[84*101+84]=r;   
   
                                                                                             //86
   A[85*101+73]=p1;
   A[85*101+89]=p2;
   A[85*101+78]=p12;
   A[85*101+93]=q1;
   A[85*101+82]=q2;
   A[85*101+91]=q12;
   A[85*101+69]=pq12;
   A[85*101+96]=pq21;
   A[85*101+85]=r;   
 
                                                                                              //87
   A[86*101+74]=p1;
   A[86*101+90]=p2;
   A[86*101+79]=p12;
   A[86*101+9]=q1;
   A[86*101+83]=q2;
   A[86*101+5]=q12;
   A[86*101+70]=pq12;
   A[86*101+14]=pq21;
   A[86*101+86]=r;  
   
                                                                                               //88
   A[87*101+76]=p1;
   A[87*101+94]=q1;
   A[87*101+10]=q2;
   A[87*101+6]=q12;
   A[87*101+15]=pq12;
   A[87*101+87]=r;  
   
                                                                                               //89
   A[88*101+77]=p1;
   A[88*101+95]=q1;
   A[88*101+84]=q2;
   A[88*101+92]=q12;
   A[88*101+72]=pq12;
   A[88*101+88]=r;    
   
                                                                                              //90
   A[89*101+78]=p1;
   A[89*101+96]=q1;
   A[89*101+85]=q2;
   A[89*101+93]=q12;
   A[89*101+73]=pq12;
   A[89*101+89]=r;  
 
                                                                                                 //91
   A[90*101+79]=p1;
   A[90*101+14]=q1;
   A[90*101+86]=q2;
   A[90*101+9]=q12;
   A[90*101+74]=pq12;
   A[90*101+90]=r;  
   
                                                                                                  //92
   A[91*101+82]=p1;
   A[91*101+93]=p2;
     A[91*101+85]=p12;
     A[91*101+2]=q1;
   A[91*101+1]=q2;
   A[91*101+0]=q12;
   A[91*101+3]=pq12;
   A[91*101+5]=pq21;
   A[91*101+91]=r;  
   
                                                                                                   //93
   A[92*101+84]=p1;
   A[92*101+95]=p2;
     A[92*101+88]=p12;
     A[92*101+97]=q1;
   A[92*101+3]=q2;
   A[92*101+1]=q12;
   A[92*101+6]=pq12;
   A[92*101+99]=pq21;
   A[92*101+92]=r; 

                                                                                                    //94
   A[93*101+85]=p1;
   A[93*101+96]=p2;
     A[93*101+89]=p12;
     A[93*101+5]=q1;
   A[93*101+91]=q2;
   A[93*101+2]=q12;
   A[93*101+82]=pq12;
   A[93*101+9]=pq21;
   A[93*101+93]=r;  
   
                                                                                                      //95
   A[94*101+87]=p1;
     A[94*101+98]=q1;
   A[94*101+6]=q2;
   A[94*101+3]=q12;
   A[94*101+10]=pq12;
    A[94*101+94]=r;  
    
                                                                                                       //96
   A[95*101+88]=p1;
     A[95*101+99]=q1;
   A[95*101+92]=q2;
   A[95*101+97]=q12;
   A[95*101+84]=pq12;
    A[95*101+95]=r;  
    
                                                                                                        //97
   A[96*101+89]=p1;
     A[96*101+9]=q1;
   A[96*101+93]=q2;
   A[96*101+5]=q12;
   A[96*101+85]=pq12;
    A[96*101+96]=r;   
    
                                                                                                            //98
   A[97*101+92]=p1;
   A[97*101+99]=p2;
   A[97*101+95]=p12;
   A[97*101+2]=q1;
   A[97*101+1]=q2;
   A[97*101+0]=q12;
   A[97*101+3]=pq12;
   A[97*101+5]=pq21;
   A[97*101+97]=r;   
    
     
                                                                                                            //99
   A[98*101+94]=p1;
   A[98*101+100]=q1;
   A[98*101+3]=q2;
   A[98*101+1]=q12;
   A[98*101+6]=pq12;
   A[98*101+98]=r;    
    
                                                                                                             //100
   A[99*101+95]=p1;
   A[99*101+5]=q1;
   A[99*101+97]=q2;
   A[99*101+2]=q12;
   A[99*101+92]=pq12;
   A[99*101+99]=r;    
   
                                                                                                                //101
   A[100*101+98]=p1;
   A[100*101+2]=q1;
   A[100*101+1]=q2;
   A[100*101+0]=q12;
   A[100*101+3]=pq12;
   A[100*101+100]=r;  
    
          
    for (i=0; i<101; i++) {

        for (j=0; j<101; j++) {
          if(i==j){ A[i*101+j]=1-A[i*101+j];}
           else{A[i*101+j]=0-A[i*101+j];}
 
            
        }

        
    }

    inverse(A, 101);
    
 
    
    double t;
    t=0;

   
        for (i=0; i<101; i++) {
            t=t+A[0*101+i];
            
        }
        
  
    printf("t = %f\n", t);


    return 0;
}