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

int h1[100000];
int top1=-1;
int h2[100000];
int top2=-1;
int h3[100000];
int top3=-1;

void push(int stack[], int *top, int val) {
    stack[++(*top)] = val;
}

int pop(int stack[], int *top) {
    if (*top == -1) return 0;
    return stack[(*top)--];
}

int equalStacks(int n1, int arr1[], int n2, int arr2[], int n3, int arr3[]) {
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for(int i = n1-1; i >=0; i--) {
        push(h1, &top1, arr1[i]);
        sum1 += arr1[i];
    }
    for(int i = n2-1; i >=0; i--) {
        push(h2, &top2, arr2[i]);
        sum2 += arr2[i];
    }
    for(int i = n3-1; i >=0; i--) {
        push(h3, &top3, arr3[i]);
        sum3 += arr3[i];
    }
    
    while(1) {

        if(sum1 == sum2 && sum2 == sum3) return sum1;
        
        if(sum1 >= sum2 && sum1 >= sum3){
            sum1 -= pop(h1, &top1);
        }else if(sum2 >= sum1 && sum2 >= sum3){
            sum2 -= pop(h2, &top2);
        }else{
            sum3 -= pop(h3, &top3);
        }
    }
}

int main() {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    
    int arr1[n1], arr2[n2], arr3[n3];
    for(int i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }
    for(int i = 0; i < n2; i++){ 
        scanf("%d", &arr2[i]);
    }
    for(int i = 0; i < n3; i++){
        scanf("%d", &arr3[i]);
    }
    int result = equalStacks(n1, arr1, n2, arr2, n3, arr3);
    printf("%d\n", result);
    
    return 0;
}
