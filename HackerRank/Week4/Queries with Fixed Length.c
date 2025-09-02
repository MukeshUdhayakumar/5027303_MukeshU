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

int minmax(int n,int arr[n],int val){
    int max[n];
    int ind=0;

    int large=arr[0];
    for(int j=1;j<val;j++){
        if(arr[j]>large){
            large=arr[j];
        }
    }
    max[ind++]=large;

    for(int i=1;i+val<=n;i++){
        if(arr[i-1]!=large){
            if(arr[i+val-1]>large){
                large=arr[i+val-1];
            }
        }else{
            large=arr[i];
            for(int j=i+1;j<i+val;j++){
                if(arr[j]>large){
                    large=arr[j];
                }
            }
        }
        max[ind++]=large;
    }

    int small = max[0];
    for(int i=1;i<ind;i++){
        if(max[i]<small){
            small=max[i];
        }
    }
    return small;
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    while(q--){
        int val;
        scanf("%d",&val);
        printf("%d\n",minmax(n,arr,val));
    }
    return 0;
}
