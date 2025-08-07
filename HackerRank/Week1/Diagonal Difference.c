#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;
    scanf("%d",&n);
    
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    int left=0,right=0;
    
    for(int i=0;i<n;i++){
        left+=arr[i][i];
        right+=arr[i][n-1-i];
    }
    
    printf("%d",abs(left-right));
    
    
    return 0;
}