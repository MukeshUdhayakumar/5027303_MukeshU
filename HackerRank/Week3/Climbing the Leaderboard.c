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

void climbingLeaderboard(int n,int m,int *ranked,int *player){    
    int unique[n],size=0;
    for(int i=0;i<n-1;i++){
        if(ranked[i]!=ranked[i+1]){
            unique[size++]=ranked[i];
        }
    }
    unique[size++] = ranked[n-1];

    int j=size-1;
    for(int i=0;i<m;i++){
        int a=player[i];
        while(j>=0 && a>=unique[j]){
            j--;
        }
        printf("%d\n",j+2);
    }
    
    return;
}

int main(){
    
    int n,m;
    scanf("%d",&n);
    int ranked[n];
    for(int i=0;i<n;i++){
        scanf("%d",&ranked[i]);
    }
    
    scanf("%d",&m);
    int player[m];
    for(int i=0;i<m;i++){
        scanf("%d",&player[i]);
    }
    
    climbingLeaderboard(n,m,ranked,player);
    
    return 0;
}