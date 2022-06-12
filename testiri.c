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
  printf("Hello, World!\n");
  read_ig_rz_();
  readapf107_();

  int jf[50];
  int   jmag   = 1;
  float alat   = 37.8;
  float along  = 360.0 - 75.4;
  int iyear    = 2021;
  int idate    =303;
  float time   = 11.0;
  float heibeg = 80.0;
  float heiend = 1500.0;
  float heistp = 1.0;
  float outf[20000];
  float outfc[20][1000];
  float oarr[100];

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

         iri_sub_(jf, &jmag, &alat, &along, &iyear, &idate, &time, &heibeg, &heiend, &heistp, outf, oarr);

         for (int j = 0; j<20; j++) {
           for (int i=0; i < 1000; i++) {
             outfc[j][i] = outf[j+(i*20)];
           }
         //   printf("%s%d%s%f\n","outfc[0][", i, "] = ", outf[(i)*20]);
         }
         for (int k = 0; k<1000;k++) {
           printf("%s%d%s%f\n","outfc[0][", k, "] = ", outfc[0][k]);
         }
 
  return 0;
}
