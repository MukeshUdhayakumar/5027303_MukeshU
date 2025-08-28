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

int* icecreamParlor(int m,int n,int cost[n]){
    int* ans=(int*)malloc(2*sizeof(int));
    int c1,c2;
    for(int i=0;i<n;i++){
        c1=cost[i];
        for(int j=i+1;j<n;j++){
            c2=cost[j];
            if(c1+c2 == m){
                ans[0]=i+1;
                ans[1]=j+1;
                return ans;
            }
        }
    }
    return ans;
} 

int main(){
    
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
        int cost[n];
        for(int i=0;i<n;i++){
            scanf("%d",&cost[i]);
        }
        int* ans=icecreamParlor(m,n,cost);
        printf("%d %d\n",ans[0],ans[1]);
    }
    
    return 0;
}
