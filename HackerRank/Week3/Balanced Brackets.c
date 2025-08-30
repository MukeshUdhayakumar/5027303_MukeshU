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

int stack[1000];
int top=-1;

void push(int br){
    if(top==999) return;
    stack[++top]=br;
}

int peek(){
    if(top==-1) return -1;
    return stack[top];
}

void pop(){
    if(top==-1) return;
    top--;
}

int isBalanced(char s[]){
    top=-1;
    int l=strlen(s);
    int br;
    for(int i=0;i<l;i++){
        br=s[i];
        int inStack=peek();
        if(inStack==40 && br==41){
            pop();
        }else if(inStack==91 && br==93){
            pop();
        }else if(inStack==123 && br==125){
            pop();
        }else{
            push(br);
        }
    }
    
    return top==-1;
    
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char s[1000];
        scanf("%s",s);
        int res=isBalanced(s);
        
        if(res){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
