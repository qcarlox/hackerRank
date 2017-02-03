//https://www.hackerrank.com/challenges/beautiful-days-at-the-movies
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int firstDay;
    int lastDay;
    int k;
    scanf("%i %i %i",&firstDay,&lastDay,&k);
    int totalBeautyful = 0;
    int reverse = 10;
    for(int i=firstDay; i<= lastDay; i++){
        int numberOfDigits = (int)(log10(i)+1);
        //printf("numberOfDigits: %i\n",numberOfDigits);
        char digits[numberOfDigits+1];
        sprintf(digits,"%i",i);
        //printf("digits: %s\n",digits);
        char reverseDigits[numberOfDigits+1];
        int j = 0;
        while(digits[j] != 0){
            //printf("j: %i\n",numberOfDigits-j);
            reverseDigits[numberOfDigits-1-j] = digits[j];
            j++;
            
        }
        reverseDigits[j] = 0; //copy NULL
        //printf("reverseDigits: %s\n",reverseDigits);
        int reverse;
        sscanf(reverseDigits,"%d",&reverse);
        //printf("reverse: %d\n",reverse);
        if(abs(reverse-i)%k == 0){
            totalBeautyful++;
        }
    }
    printf("%d", totalBeautyful);
    return 0;
}
