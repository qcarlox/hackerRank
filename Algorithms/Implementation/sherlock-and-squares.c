//https://www.hackerrank.com/challenges/sherlock-and-squares
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        int b;
        scanf("%d %d",&a,&b);
        //printf("%d %d\n",a,b);
        int rootA = ceil(sqrt(a));
        int rootB = floor(sqrt(b));
        int count = rootB-rootA+1;
        //printf("%d %d\n",rootA,rootB);
        printf("%d\n",count);
        
    }
    
    return 0;
}
