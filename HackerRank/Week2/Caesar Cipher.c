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
    
    int n;
    scanf("%d",&n);
    getchar();
    
    char inp[n+1];
    fgets(inp, sizeof(inp), stdin);

    int k;
    scanf("%d",&k);
    
    if(k>=26){
        k=k-(26*(k/26));
    }
    
    char alph[26];
    
    char a=97+k;
    for(int i=0;i<26;i++){
        if(a>122){
            a-=26;
        }
        alph[i]=a;
        ++a;
    }

    char outp[n+1];
    
    for(int i=0;i<n;i++){
        int l=inp[i];
        if(l>=97 && l<=122){
            int ind=l-97;
            outp[i]=alph[ind];
        }else if(l>=65 && l<=90){
            int ind=l-65;
            char c=alph[ind];
            outp[i]=c-32;
        }else{
            outp[i]=inp[i];
        }
    }
    outp[n]='\0';
    printf("%s",outp);
    
    return 0;
}
