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

int cmp(const void* a,const void* b){
    return (*(char*)a - *(char*)b);
}

int gridChallenge(char** grid,int n){

    for(int i=0;i<n;i++){
        qsort(grid[i],n,sizeof(char),cmp);
    }    
    
    int res=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(grid[j][i]>grid[j+1][i]){
                res=0;
                break;
            }
        }
        if(res==0){
            break;
        }
    }
    return res;    
}

int main(){
    
    int t;
    scanf("%d",&t);
    for(int l=0;l<t;l++){
        int n;
        scanf("%d",&n);
        char** grid= (char**)malloc(n * sizeof(char*));
        
        for(int i = 0; i < n; i++){
            grid[i] = (char*)malloc((n+1) * sizeof(char));
            scanf("%s", grid[i]);
        }
        
        int result=gridChallenge(grid,n);
        
        if(result==1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        for(int i=0;i<n;i++){
            free(grid[i]);
        }
        
        free(grid);
    }
    
    return 0;
}
