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

long long arrayManipulation(long long n,long long m,long long queries[m][3]){
    long long r1,r2,k;
    
    long long* arr = (long long*)calloc(n, sizeof(long long));
    
    for(int i=0;i<m;i++){
        r1=queries[i][0];
        r2=queries[i][1];
        k=queries[i][2];
        arr[r1-1]+=k;
        arr[r2]-=k;
    }
    
    long long val=0;
    long long max=0;
    
    for(int i=0;i<n;i++){
        val+=arr[i];
        if(val>max){
            max=val;
        }
    }
    free(arr);
    return max;
    
}

int main(){
    
    long long n,m;
    scanf("%lld %lld",&n,&m);
    long long queries[m][3];
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            scanf("%lld",&queries[i][j]);
        }
    }

    long long max=arrayManipulation(n,m,queries);
    printf("%lld\n",max);
    return 0;
}