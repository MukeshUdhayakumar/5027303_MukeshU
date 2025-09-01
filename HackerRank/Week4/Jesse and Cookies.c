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

long heap[1000000];
int size=0;

void swap(long *a,long *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapifyUp(int i){
    if(i){
        if(heap[(i-1)/2]>heap[i]){
            swap(&heap[(i-1)/2],&heap[i]);
            heapifyUp((i-1)/2);
        }
    }
}


void insert(long val){
    if(size==1000000) return;
    heap[size++]=val;
    heapifyUp(size-1);
}

void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

 long removeRoot(){
    if(size<=0) return -1;
    if(size==1) return heap[--size];
    
    int root=heap[0];
    heap[0]=heap[--size];
    heapifyDown(0);
    return root;
}

int main(){
    
    int n;
    long k;
    scanf("%d %ld",&n,&k);
    for(int i=0;i<n;i++){
        long val;
        scanf("%ld",&val);
        insert(val);
    }
    long op=0;
    while(size>0 && heap[0]<k){
        if(size<2){
            op=-1;
            break;
        }
        long val1=removeRoot();
        long val2=removeRoot();
        long val3=val1+(2l*val2);
        insert(val3);
        op++;
    }
    if(op==-1){
        printf("-1\n");
    }else{
        printf("%ld\n",op);
    }
    return 0;
}
