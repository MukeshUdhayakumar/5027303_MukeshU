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

int t[1000000][10];
int end[1000000];
int pos=1;

int isFound(char word[]){
    int c=0;
    int l=strlen(word);
    for(int i=0;i<l;i++) {
        int ind=word[i]-'a';
        if(t[c][ind]==0) {
            t[c][ind]=pos++;
        }
        c=t[c][ind];
        if(end[c]){
            return 0;
        }
    }
    end[c]=1;
    for(int i=0;i<10;i++) {
        if(t[c][i]!=0) {
            return 0;
        }
    }
    return 1;
}

void noPrefix(int n,char words[n][60]){
    for (int i=0;i<n;i++) {
        if (!isFound(words[i])) {
            printf("BAD SET\n%s\n",words[i]);
            return;
        }
    }
    printf("GOOD SET\n");
}

int main(){
    int n;
    scanf("%d", &n);
    char words[n][60];
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }
    noPrefix(n, words);
    return 0;
}
