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

bool powerOf(unsigned long long a){
    return (a > 0) && ((a & (a - 1)) == 0);
}


int counterGame(){
    unsigned long long n;
    scanf("%llu",&n);
    int lo=1;
    while(n!=1){
        if(powerOf(n)){
            n/=2;
        }else{
            unsigned long long v=0llu;
            int i=1;
            while(pow(2,i)<n){
                v=pow(2,i);
                i++;
            }
            n=n-v;
        }
        if(lo==1){
            lo=0;
        }else{
            lo=1;
        }
    }
    
    return (lo==1);
    
    
}

int main(){
    
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        if(counterGame()){
            printf("Richard\n");
        }else{
            printf("Louise\n");
        }
    }
    
    
    return 0;
}
