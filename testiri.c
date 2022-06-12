#include <stdio.h>
extern void read_ig_rz_();
extern void readapf107_();
extern void iri_sub_(int jf[50], 
                     int *jmag, 
                     float *alat, 
                     float *along, 
                     int *iyear, 
                     int *idate, 
                     float *time, 
                     float *heibeg, 
                     float *heiend, 
                     float *heistp,
                     float outf[20001],
                     float oarr[100]);

int main() {
  FILE *fp1;
  FILE *fp2;
  read_ig_rz_();
  readapf107_();

  int jf[50];
  int   jmag   = 1;
  float alat   = 37.8;
  float along  = 360.0 - 75.4;
  int iyear    = 2021;
  int idate1   = 303;
  int idate2   = 304;
  float time1  = 11.0;
  float time2  = 23.0;
  float heibeg = 80.0;
  float heiend = 1500.0;
  float heinc  = (heiend - heibeg)/999.0;
  float heistp = 1.0;
  float outf1[20000];
  float outf2[20000];
  float outfc1[20][1000];
  float outfc2[20][1000];
  float oarr[100];
  float alt[1000];

  jf[0]        = 1;
  jf[1]        = 1;
  jf[2]        = 1;
  jf[3]        = 0;
  jf[4]        = 0;
  jf[5]        = 0;
  jf[6]        = 1;
  jf[7]        = 1;
  jf[8]        = 1;
  jf[9]        = 1;
  jf[10]       = 1;
  jf[11]       = 1;
  jf[12]       = 1;
  jf[13]       = 1;
  jf[14]       = 1;
  jf[15]       = 1;
  jf[16]       = 1;
  jf[17]       = 1;
  jf[18]       = 1;
  jf[19]       = 1;

  jf[20]       = 0;
  jf[21]       = 1;
  jf[22]       = 0;
  jf[23]       = 1;
  jf[24]       = 1;
  jf[25]       = 1;
  jf[26]       = 1;
  jf[27]       = 0;
  jf[28]       = 0;
  jf[29]       = 0;
  jf[30]       = 1;
  jf[31]       = 1;
  jf[32]       = 0;
  jf[33]       = 1;
  jf[34]       = 0;
  jf[35]       = 1;
  jf[36]       = 1;
  jf[37]       = 1;
  jf[38]       = 0;
  jf[39]       = 0;
  jf[40]       = 1;
  jf[41]       = 1;
  jf[42]       = 1;
  jf[43]       = 1;
  jf[44]       = 1;
  jf[45]       = 1;
  jf[46]       = 0;
  jf[47]       = 0;
  jf[48]       = 0;
  jf[49]       = 0;

         iri_sub_(jf, &jmag, &alat, &along, &iyear, &idate1, &time1, &heibeg, &heiend, &heistp, outf1, oarr);
         iri_sub_(jf, &jmag, &alat, &along, &iyear, &idate2, &time2, &heibeg, &heiend, &heistp, outf2, oarr);

         for (int k=0; k<1000; k++){
           alt[k] = heibeg + k*heinc;
         }

         for (int j = 0; j<20; j++) {
           for (int i=0; i < 1000; i++) {
             outfc1[j][i] = outf1[j+(i*20)];
             outfc2[j][i] = outf2[j+(i*20)];
           }
         }
 
         fp1 = fopen("data1.dat","w+");
         fp2 = fopen("data2.dat","w+");

         for (int k = 0; k<1000;k++) {
           fprintf(fp1,"%f\t%f\n",alt[k],outfc1[0][k]);
           fprintf(fp2,"%f\t%f\n",alt[k],outfc2[0][k]);
         }

         fclose(fp1);
         fclose(fp2);

  return 0;
}
