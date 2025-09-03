#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int operation(int n,int indOrder[]) {
    int *visit=(int*)calloc(n, sizeof(int));
    int swaps=0;
    for(int i=0;i<n;i++) {
        if(visit[i]) continue;
        int change=0;
        int j=i;
        while(!visit[j]){
            visit[j]=1;
            j = indOrder[j];
            change++;
        }
        if(change>1) {
            swaps+=(change-1);
        }
    }
    free(visit);
    return swaps;
}

int lilysHomework(int n,int arr[]) {
    
    int pairs[n][2];
    for(int i=0;i<n;i++) {
        pairs[i][0]=arr[i];
        pairs[i][1]=i;
    }
    qsort(pairs,n,sizeof(int[2]),compare);
    
    int ascInd[n];
    for(int i=0;i<n;i++) {
        int j=pairs[i][1];
        ascInd[j]=i;
    }
    
    int descInd[n];
    for(int i=0;i<n;i++) {
        int j=pairs[n-1-i][1];
        descInd[j]=i;
    }
    
    int ascOp=operation(n,ascInd);
    int descOp=operation(n,descInd);
    
    return (ascOp<descOp)?ascOp:descOp;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("%d\n",lilysHomework(n,arr));
    return 0;
}
