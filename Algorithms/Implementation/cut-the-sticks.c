//https://www.hackerrank.com/challenges/cut-the-sticks
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int comparator(const void *p, const void *q) {
    int elem1 = *(int*)p;
    int elem2 = *(int*)q;
    if (elem1 > elem2){
        return  1;
    } 
    else if (elem1 < elem2){
        return -1;
    }
    else{
        return 0;
    }
}
int main(){
    int n; 
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    qsort(arr,n,sizeof(int),comparator);
    //printf("min: %d\n",arr[0]);
    //printf("max: %d\n",arr[n-1]);
    int sum=0;
    int min=arr[0];
    int max=arr[n-1];
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        if(sum>=max){
            break;
        }
        if(arr[i]>min){
            min = arr[i];
            printf("%d\n",n-i);
        }
        
    }
    
    return 0;
}
