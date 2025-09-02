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

void highestValuePalindrome(int n,char string[n],int k){
    
    int mismatches = 0;
    for(int i=0;i<(n/2);i++){
        if(string[i]!=string[n-i-1]){
            mismatches++;
        }
    }

    if(mismatches > k){
        printf("-1");
        return;
    }

    int changed[n];
    memset(changed, 0, sizeof(changed));
    int op=0;
    
    for(int i=0;i<n/2;i++){
        if(string[i]!=string[n-i-1]){
            if(string[i]>string[n-i-1]){
                string[n-i-1]=string[i];
            }else{
                string[i]=string[n-i-1];
            }
            changed[i]=1;
            op++;
        }
    }
    
    
    for(int i=0;i<(n/2) && op<k;i++){
        if(string[i]!='9'){
            if(changed[i]){
                string[i]=string[n-i-1]='9';
                op++;
            }else if(!changed[i] && op<=k-2){
                string[i]=string[n-i-1]='9';
                op+=2;
            }
        }
    }
    
    if (n%2==1 && op<k) {
        string[n / 2] = '9';
    }
    
    printf("%s",string);
    return;
}

int main(){
    
    int n,k;
    scanf("%d %d",&n,&k);
    char string[n+1];
    
    scanf("%s",string);
    highestValuePalindrome(n,string,k);
    
    return 0;
}
