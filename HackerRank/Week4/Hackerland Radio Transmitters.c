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

int hackerland(int n,int x[n],int k){
    int l=x[0];
    for(int i=1;i<n;i++){
        if(x[i]>l){
            l=x[i];
        }
    }
    int arr[l+1];
    memset(arr, 0, sizeof(int)*(l+1));
    
    for(int i=0;i<n;i++){
        int ind=x[i];
        arr[ind]=1;
    }
    
    int trans=0;
    int a=0;
    for(int i=0;i<l+1;i++){
        if(arr[i]==0 && a==0) continue;
        if(a==k){
            if(arr[i]==0){
                i--;
                while(1){
                    if(arr[i]==0){
                        i--;
                    }else{
                        break;
                    }
                }
            }
            trans++;
            a=0;
            arr[i]++;
            i+=k;
            continue;
        }
        a++;
    }
    if(a>0) trans++;
    
    return trans;
    
}

int main(){
    
    int n,k;
    scanf("%d  %d",&n,&k);
    int x[n];
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }
    printf("%d",hackerland(n,x,k));
    return 0;
}