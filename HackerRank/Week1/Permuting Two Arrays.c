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
    
    int q;
    scanf("%d",&q);
    for(int m=0;m<q;m++){
        int n,k;
        scanf("%d %d",&n,&k);

        
        int A[n],B[n];
        for(int i=0;i<n;i++){
            scanf("%d",&A[i]);
        }
        
        for(int i=0;i<n;i++){
            scanf("%d",&B[i]);
        }
        
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(A[j]>A[j+1]){
                    int temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }
        }
        
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(B[j]<B[j+1]){
                    int temp=B[j];
                    B[j]=B[j+1];
                    B[j+1]=temp;
                }
            }
        }
        
        int j=0,f=0;
        for(int i=0;i<n;i++){
            if(A[i]+B[j]<k){
                f+=1;
                break;
            }
            ++j;
        }
        
        if(f==0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        
    }
    
    
    return 0;
}
