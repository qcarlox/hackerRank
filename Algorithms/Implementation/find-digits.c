//https://www.hackerrank.com/challenges/find-digits
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        int numberOfDigits = (int)(log10(n)+1);
        char digits[numberOfDigits+1];
        sprintf(digits,"%d",n);
        int count = 0;
        for(int i=0; i<numberOfDigits;i++){
            if(digits[i]-'0' != 0 && n%(digits[i]-'0')==0){
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
