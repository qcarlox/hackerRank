//https://www.hackerrank.com/challenges/save-the-prisoner
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        long int N, M, S;
        scanf("%li %li %li",&N,&M,&S);
        printf("%li\n", ((S-2+M)%N)+1);
    }
    return 0;
}
