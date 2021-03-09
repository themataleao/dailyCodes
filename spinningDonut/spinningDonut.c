//To run the donut, run the command: gcc spinningDonut.c -lm && ./a.out

#include <stdio.h>
#include <string.h>
#include <math.h>

int k;
double sin() ,cos();
main(){
    float A=0, B=0, i, j, z[1760];
    char b[1760];
    printf("\x1b[2J");
    while(1) {
        memset(b,32,1760);
        memset(z,0,7040);
        // We spin around one axis, 6.28 = 2pi, the lower the steps the slower the animation
        for(j=0; 6.28>j; j+=0.005) {
            // We spin around the other axis, the lower the steps the slower the animation
            for(i=0; 6.28>i; i+=0.02) {
                float sini=sin(i),
                      cosj=cos(j),
                      sinA=sin(A),
                      sinj=sin(j),
                      cosA=cos(A),
                      cosj2=cosj+2,
                      mess=1/(sini*cosj2*sinA+sinj*cosA+5),
                      cosi=cos(i),
                      cosB=cos(B),
                      sinB=sin(B),
                      t=sini*cosj2*cosA-sinj* sinA;
                // our projections of i,j,A to x,y
                int x=40+30*mess*(cosi*cosj2*cosB-t*sinB),
                    y= 12+15*mess*(cosi*cosj2*sinB +t*cosB),
                    o=x+80*y,
                    // our surface normal to create the illumination
                    N=8*((sinj*sinA-sini*cosj*cosA)*cosB-sini*cosj*sinA-sinj*cosA-cosi *cosj*sinB);
                if(22>y&&y>0&&x>0&&80>x&&mess>z[o]){
                    z[o]=mess;
                    b[o]=".,-~:;=!*#$@"[N>0?N:0];
                }
            }
        }
        printf("\x1b[d");
        // Iterate through the created array of numbers
        for(k=0; 1761>k; k++)
            putchar(k%80?b[k]:10);
        A+=0.04;
        B+= 0.02;
    }
}