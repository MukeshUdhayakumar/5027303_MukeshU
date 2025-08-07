#include <math.h>
#include <stdio.h>


int main(){
    
    int q;
    scanf("%d",&q);
    
    int arr[q];
    for(int i=0;i<q;i++){
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<q;i++){
        int a=arr[i];
        int bi[32];
        int j=0;
        
        while(a>0){
            bi[j++]=a%2;
            a=a/2;
        }
        
        a=arr[i];
        
        for(int k=0;k<32;k++){
            bi[k]=(a>>k) & 1;
        }
        
        for(int l=0;l<32;l++){
            if(bi[l]==1){
                bi[l]=0;
            }else{
                bi[l]=1;
            }
        }
        
        unsigned int fin=0;
        for(int m=0;m<32;m++){
            fin+=(pow(2,m)*bi[m]);
        }
        printf("%u\n",fin);
        
        
    }
    
        
    return 0;
}