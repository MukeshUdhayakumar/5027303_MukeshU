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

long long sumXor(long long n){
    if(n==0) return 1;
    long long res=1,temp=n;
    while(temp){
        if((temp&1)==0){
            res*=2;
        }
        temp>>=1;
    }
        
    return res;
}

int main(){
    long long n;
    scanf("%lld",&n);
    long long res=sumXor(n);
    printf("%lld\n",res);
    return 0;
}
