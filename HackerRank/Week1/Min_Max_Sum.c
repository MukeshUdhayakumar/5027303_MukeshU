#include <stdio.h>


int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    
    long int sum=0;
    for(int i=0;i<5;i++){
        sum+=arr[i];
    }
    
    long int total[5];
    for(int i=0;i<5;i++){
        total[i]=sum-arr[i];
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4-i;j++){
            if(total[j]>total[j+1]){
                long int temp=total[j];
                total[j]=total[j+1];
                total[j+1]=temp;
            }
        }
    }
    
    printf("%ld %ld",total[0],total[4]);
    return 0;
}