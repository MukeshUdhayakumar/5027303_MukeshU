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

int isValid(char *str){
    int len=strlen(str);
    if(len==1) return 1;
    int arr[26]={0};
    int let;
    for(int i=0;i<len;i++){
        let=str[i];
        arr[let-97]+=1;
    }
    int count;
    for(int i=25;i>=0;i--){
        if(arr[i]!=0){
            count=arr[i];
            break;
        }
    }
    int a,b=0;
    for(int i=0;i<26;i++){
        if(arr[i]==0) continue;
        
        if(b>1) return 0;
        ++b;
        a=arr[i];
        if(count==a) break;
        else{
            count=a;
        }      
    }
    
    int nt=0;
    for(int i=0;i<26;i++){
        if(arr[i]==0) continue;
        
        if(count==arr[i]-1 || count==arr[i]+1 || arr[i]==1){
            ++nt;
        }else if(count!=arr[i]){
            return 0;
        }
    }
    
    if(nt<=1){
        return 1;
    }else{
        return 0;
    }
    
}

int main(){
    
    char *str=(char *)malloc(100000 * sizeof(char));
    scanf("%s",str);
    
    if(isValid(str)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    free(str);
    return 0;
}
