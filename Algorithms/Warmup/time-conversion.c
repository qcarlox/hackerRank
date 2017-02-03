https://www.hackerrank.com/challenges/time-conversion
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    char hoursString[3];
    snprintf(hoursString,3, "%s", time);
    int hours = atoi(hoursString);
    if(strstr(time,"AM") != NULL){ //check if AM or PM
        if(time[0] == '1' && time[1] == '2'){            
           time[0] = '0';
           time[1] = '0';
        }
    }
    else{
        if(time[0] != '1' || time[1] != '2'){            
           hours = hours + 12;
           snprintf(hoursString,3, "%d", hours);;
           time[0] = hoursString[0];
           time[1] = hoursString[1];
        }
    }
    printf("%.8s", time);
    return 0;
}
