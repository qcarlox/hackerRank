//https://www.hackerrank.com/challenges/utopian-tree
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
        int h = 1;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                h += 1;
            }
            else{
                h *=2;
            }
        }
        printf("%i\n",h);
    }
    return 0;
}
