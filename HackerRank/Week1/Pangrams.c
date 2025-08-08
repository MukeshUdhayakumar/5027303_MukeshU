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

int main(){
    
    char s[1000];
    fgets(s,sizeof(s),stdin);
    
    int arr[26]={0};
    
    for(int i=0;i<strlen(s);i++){
        int letter=s[i];
        if((letter>=65 && letter<=90) || (letter>=97 && s[i]<=122)){
            if(letter>=65 && letter<=90){
                arr[letter-65]+=1;
            }else{
                arr[letter-97]+=1;
            }
        }
    }
    
    for(int i=0;i<26;i++){
        if(!(arr[i]>=1)){
            printf("not pangram");
            return 0;
        }
    }
    
    printf("pangram");
    
    return 0;
}