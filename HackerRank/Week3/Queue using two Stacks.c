#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int stack1[100000],stack2[100000];
int top1=-1,top2=-1;

void push1(int x){
    if(top1==99999) return;
    stack1[++top1]=x;
}

int pop1(){
    if(top1==-1) return;
    return stack1[top1--];
}

void push2(int x){
    if(top2==99999) return;
    stack2[++top2]=x;
}

int pop2(){
    if(top2==-1) return;
    return stack2[top2--];
    
}

void enqueue(int x){
    push1(x);
}

void dequeue(){
    if(top1==-1 && top2==-1){
        return;
    }
    int x;
    if(top2==-1){
        while(top1!=-1){
            x=pop1();
            push2(x);
        }
    }
    x=pop2();
}

void printTop(){
    if(top1==-1 && top2==-1) return;
    
    if(top2!=-1){
        printf("%d\n",stack2[top2]);
    }else{
        printf("%d\n",stack1[0]);
    }
}

int main() {
    
    int q;
    scanf("%d",&q);
    while(q--){
        int type,x;
        scanf("%d",&type);
        if(type==1){
            scanf("%d",&x);
            enqueue(x);
        }else if(type==2){
            dequeue();
        }else{
            printTop();
        }
    }
    
     
    return 0;
}
