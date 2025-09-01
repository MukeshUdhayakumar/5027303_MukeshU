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

long power(long base,int exp) {
    long res=1;
    while(exp>0) {
        if (exp % 2 == 1){
            res = (res * base) % 1000000007;
        }
        base=(base*base)%1000000007;
        exp/=2;
    }
    return res;
}

int legoBlocks(int n, int m) {
    long r[m+1]; 
    long h[m+1]; 
    long sh[m+1]; 
    
    r[0]=1;
    for (int i=1;i<=m;i++) {
        r[i]=0;
        for(int k = 1; k <= 4; k++) {
            if(i-k>=0){
                r[i] = (r[i] + r[i-k]) % 1000000007;
            }
        }
    }

    for (int i=1;i<=m;i++) {
        h[i]=power(r[i], n);
    }

    for (int i=1;i<=m;i++) {
        sh[i] = h[i];
        for (int k=1;k<i;k++) {
            sh[i]=(sh[i]-(sh[k]*h[i-k])%1000000007 + 1000000007) % 1000000007;
        }
    }

    return sh[m];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d\n", legoBlocks(n, m));
    }
    return 0;
}
