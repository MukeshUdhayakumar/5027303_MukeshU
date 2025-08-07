#include <stdio.h>

int main(){
    
    int n;
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int positive=0,negative=0,zero=0;
    
    for(int j=0;j<n;j++){
        if(arr[j]>0){
            positive+=1;
        }else if(arr[j]<0){
            negative+=1;
        }else{
            zero+=1;
        }
    }
    
    printf("%.6f\n%.6f\n%.6f",(float)positive/n,(float)negative/n,(float)zero/n);
    
    return 0;
}