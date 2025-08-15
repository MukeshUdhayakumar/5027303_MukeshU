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

int superDigit(int n){
    
    int digit=0;
    while(n>0){
        int l=n%10;
        digit+=l;
        n/=10;
    }
    
    return digit;
}

int main(){
    char num[1000000];
    int k;
    scanf("%s  %d",num,&k);
    int n=0;
    for(int i=0;i<strlen(num);i++){
        int l=num[i]-'0';
        n+=l;
    }
    for(int i=0;i<k-1;i++){
        n=superDigit(n);
    }
    
    printf("%d",superDigit(n*k));
    
    
    return 0;
}