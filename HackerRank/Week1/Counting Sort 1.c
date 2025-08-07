#include <stdio.h>

int main(){
    
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int result[100]={0};
    for(int i=0;i<n;i++){
        int a=arr[i];
        result[a]+=1;
    }
    
    for(int i=0;i<100;i++){
        printf("%d ",result[i]);
    }
    return 0;
}
