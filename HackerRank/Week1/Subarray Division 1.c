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
    
    int n;
    scanf("%d",&n);
    int s[n];
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    
    int d,m;
    scanf("%d %d",&d,&m);
    
    int res=0;
    for(int i=0;i<n-m+1;i++){
        int sum=0;
        for(int j=i;j<m+i;j++){
            sum+=s[j];
        }
        if(sum==d){
            res+=1;
        }
    }
    
    printf("%d",res);
    
    
    return 0;
}
