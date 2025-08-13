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
    int t;
    scanf("%d",&t);
    while(t>0){
       int n,m;
       scanf("%d %d",&n,&m);
       
       if(m==1){
        printf("2\n");
       }else if(n%2==0){
        printf("2\n");
       }else{
        printf("1\n");
       }
       
       --t;
    }
    return 0;
}