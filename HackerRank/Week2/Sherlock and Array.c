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

int balancedSums(int arr[],int n){
    
    int total=0,left=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }

    for(int i=0;i<n;i++){
        int right=total-left-arr[i];
        if(left==right){
            return 1;
        }
        left+=arr[i];
    }
    return 0;    
        
}

int main(){
    
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        
        if(balancedSums(arr,n)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    
    return 0;
}
