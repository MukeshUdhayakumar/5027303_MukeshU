#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int n,p;
    scanf("%d",&n);
    scanf("%d",&p);
    
    int flip,mid=n/2;

    if(p<=mid){
        flip=p/2;
    }else{
        flip=mid - (p/2);
    }

    printf("%d",flip);

    return 0;
}