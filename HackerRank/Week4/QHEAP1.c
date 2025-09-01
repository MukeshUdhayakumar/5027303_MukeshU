#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int heap[100000];
int size=0;

void swap(int *a,int *b){
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

void insert(int val){
    if(size==100000) return;
    heap[size++]=val;
    heapifyUp(size-1);
}

void heapifyDown(int i){
    int left=2*i+1;
    int right=2*i+2;
    int small=i;
    if(left<size && heap[left]<heap[small]){
        small=left;
    }
    if(right<size && heap[right]<heap[small]){
        small=right;
    }
    if(small!=i){
        swap(&heap[i],&heap[small]);
        heapifyDown(small);
    }
}

void deleteVal(int val){
    if(size<=0) return;
    int i=0;
    while(i<size){
        if(heap[i]==val){
            break;
        }
        i++;
    }
    if(i==size) return;
    heap[i]=heap[--size];
    heapifyDown(i);
}

int main() {
    
    int q;
    scanf("%d",&q);
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int val;
            scanf("%d",&val);
            insert(val);
        }else if(t==2){
            int val;
            scanf("%d",&val);
            deleteVal(val);
        }else{
            if(size>0) printf("%d\n",heap[0]);
        }
    }
       
    return 0;
}
