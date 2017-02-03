//https://www.hackerrank.com/challenges/extra-long-factorials
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
struct bigInt{
    int * digits;
    int length;
};
struct bigInt * intToBigInt(int num){
    struct bigInt * bigNum = (struct bigInt *) malloc(sizeof(struct bigInt));
    if(num>0){
        int numOfDigits = ((int)log10(num))+1;
        bigNum->length = numOfDigits;
        bigNum->digits = (int *) malloc(numOfDigits*sizeof(int));
        for(int i=0;i<numOfDigits;i++){
            bigNum->digits[i] = num%10;
            num = num/10;
        }
        for(int i=numOfDigits;i<bigNum->length;i++){
            bigNum->digits[i] = 0;
        }
    }
    else{
        int numOfDigits = 1;
        bigNum->length = numOfDigits;
        bigNum->digits = (int *) malloc(numOfDigits*sizeof(int));
        for(int i=0;i<numOfDigits;i++){
            bigNum->digits[i] = 0;
        }
    }
    return bigNum;
}
void bigIntFree(struct bigInt * in){
    free(in->digits);
    free(in);
}
void bigIntPrint(struct bigInt * bigNum){
    for(int i=bigNum->length-1;i>=0;i--){
        printf("%d",bigNum->digits[i]);
    }
    printf("\n");
}
void bigIntChangeLength(struct bigInt * bigNum, int newLength){
    if(newLength>bigNum->length){
        int * oldDigits = bigNum->digits;
        int * newDigits = (int *) malloc(newLength*sizeof(int));
        for(int i=0;i<bigNum->length;i++){
            newDigits[i] = oldDigits[i];
        }
        for(int i=bigNum->length;i<newLength;i++){
            newDigits[i] = 0;
        }
        bigNum->digits = newDigits;
        bigNum->length = newLength;
        free(oldDigits);
    }
    else if(newLength<bigNum->length){
        int * oldDigits = bigNum->digits;
        int * newDigits = (int *) malloc(newLength*sizeof(int));
        for(int i=0;i<newLength;i++){
            newDigits[i] = oldDigits[i];
        }
        bigNum->digits = newDigits;
        bigNum->length = newLength;
        free(oldDigits);
    }
}
struct bigInt * bigIntDeepCopy(struct bigInt * in){//A->B
    struct bigInt * out = (struct bigInt *) malloc(sizeof(struct bigInt));
    out->digits = (int *) malloc(in->length*sizeof(int));
    out->length = in->length;
    for(int i=0;i<in->length;i++){
        out->digits[i] = in->digits[i];
    }
    return out;
}
void bigIntTrim(struct bigInt * bigNum){
    int i= bigNum->length-1;
    while(bigNum->digits[i]==0 && i>1){
        i--;
    }
    //printf("i: %d\n",i);
    bigIntChangeLength(bigNum,i+1);
}
struct bigInt * bigIntAdd(struct bigInt * bigA, struct bigInt * bigB){
    struct bigInt * bigC = intToBigInt(0);
    int biggestLength;
    if(bigA->length>=bigB->length){
        biggestLength = bigA->length;
    }
    else{
        biggestLength = bigB->length;
    }
    bigIntChangeLength(bigA,biggestLength);
    bigIntChangeLength(bigB,biggestLength);
    bigIntChangeLength(bigC,biggestLength);
    int carry = 0;
    for(int i=0;i<biggestLength;i++){
        int sum = carry + bigA->digits[i] + bigB->digits[i];
        bigC->digits[i] = sum%10;
        carry = sum/10;
    }
    if(carry>0){
        bigIntChangeLength(bigC,biggestLength+1);
        bigC->digits[biggestLength] = carry;   
    }
    bigIntTrim(bigC);
    bigIntTrim(bigA);
    bigIntTrim(bigB);
    return bigC;
}
void bigIntLeftShift(struct bigInt * bigNum, int shifts){
    if(shifts>0){
        int newLength = bigNum->length+shifts;
        int * oldDigits = bigNum->digits;
        int * newDigits = (int *) malloc((newLength)*sizeof(int));
        for(int i=shifts;i<newLength;i++){
            newDigits[i] = oldDigits[i-shifts];
            //printf("i: %d\n", i);
        }
        for(int i=0;i<shifts;i++){
            newDigits[i] = 0;
        }
        bigNum->digits = newDigits;
        bigNum->length = newLength;
        free(oldDigits);
        bigIntTrim(bigNum);
    }
}
struct bigInt * bigIntMultiply(struct bigInt * bigA, struct bigInt * bigB){
    int biggestLength = bigA->length+bigB->length;
    struct bigInt * bigC = intToBigInt(0);
    for(int i=0;i<bigB->length;i++){
        int carry = 0;
        struct bigInt * bigPartialResult = intToBigInt(0);
        bigIntChangeLength(bigPartialResult,bigA->length);
        for(int j=0;j<bigA->length;j++){
            int sum = carry + (bigA->digits[j] * bigB->digits[i]);
            bigPartialResult->digits[j] = sum%10;
            carry = sum/10;
        }
        if(carry>0){
            bigIntChangeLength(bigPartialResult,bigA->length+1);
            bigPartialResult->digits[bigA->length] = carry;
        }
        bigIntLeftShift(bigPartialResult,i);
        struct bigInt * bigTemp = bigIntAdd(bigPartialResult,bigC);
        bigIntFree(bigC);
        bigC = bigIntDeepCopy(bigTemp);
        bigIntFree(bigTemp);
        bigIntFree(bigPartialResult);
    }
    bigIntTrim(bigC);
    return bigC;
}
struct bigInt * bigIntFactorial(int n){
    int numberOfDigits = 0;
    for(int i=1;i<=n;i++){
        numberOfDigits += ((int)log10(i))+1;
    }
    struct bigInt * bigCounter = intToBigInt(1);
    struct bigInt * bigOne = intToBigInt(1);
    struct bigInt * bigA = intToBigInt(1);
    for(int i=1;i<=n;i++){
        struct bigInt * bigTemp = bigIntMultiply(bigCounter,bigA);
        bigIntFree(bigA);
        bigA = bigIntDeepCopy(bigTemp);
        //printf("bigA: ");
        //bigIntPrint(bigA);
        bigTemp = bigIntAdd(bigCounter,bigOne);
        bigIntFree(bigCounter);
        bigCounter = bigIntDeepCopy(bigTemp);
        //printf("bigCounter: ");
        //bigIntPrint(bigCounter);
    }
    return bigA;
}
int main(){
    int n; 
    scanf("%d",&n);
    struct bigInt * a = intToBigInt(21);
    struct bigInt * b = intToBigInt(1);
    struct bigInt * c = bigIntFactorial(n);
    bigIntPrint(c);
    return 0;
}
