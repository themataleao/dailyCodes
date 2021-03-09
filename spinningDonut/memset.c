#include <stdio.h>
#include <string.h>
#include <math.h>

void main(){
    char b[1760];
    memset(b,32,1760);
    printf("type a string: ");
    scanf("%s", b);
    printf("Your name is %s.",b);
}