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

int primes[1200];

typedef struct {
    int arr[50000];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

void generatePrimes(int q) {
    int count = 0, num = 2;
    while(count < q) {
        int isprime = 1;
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) {
                isprime = 0;
                break;
            }
        }
        if(isprime) {
            primes[count++] = num;
        }
        num++;
    }
}

Stack waiter(int n, int q) {
    Stack A, B, nextA,Answer;
    init(&A);
    init(&Answer);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(&A, x);
    }

    generatePrimes(q);

    for(int i = 0; i < q; i++) {
        init(&B);
        init(&nextA);
        int p = primes[i];

        while(!isEmpty(&A)) {
            int x = pop(&A);
            if(x % p == 0) {
                push(&B, x);
            } else {
                push(&nextA, x);
            }
        }

        while(!isEmpty(&B)) {
            push(&Answer, pop(&B));
        }

        A = nextA;
    }

    while(!isEmpty(&A)) {
        push(&Answer, pop(&A));
    }
    
    return Answer;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    Stack Answer = waiter(n, q);
    
    for (int i = 0; i <= Answer.top; i++) {
        printf("%d\n", Answer.arr[i]);
    }
       
    return 0;
}
