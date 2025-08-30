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

int* maxSubarray(int n,int arr[n]){
    
    int *res=(int *)malloc(2*sizeof(int));
    res[0]=0,res[1]=0;
    int tn= 1;
    
    int maxElem = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            res[1]+=arr[i];
            tn=0;
        }
        if(arr[i]>maxElem && tn==1){
            maxElem = arr[i];
        }
    }
    
    if(tn){
        res[0]=maxElem;
        res[1]=maxElem;
        return res;
    }

    int curr=arr[0];   
    int fin= arr[0]; 
    for(int i=1;i<n;i++){
        if(curr + arr[i]>arr[i]){
            curr = curr + arr[i];
        }else{
            curr = arr[i];
        }
        if(curr>fin){
            fin=curr;
        }
    }
    res[0]=fin;
    
    return res;
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
        int* res=maxSubarray(n,arr);
        printf("%d %d\n",res[0],res[1]);
    }
    
    return 0;
}
