#include <stdio.h>

void minimumBribes(int n){
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int bribe = 0;

    for(int i = n-1; i >= 0; i--){
        int inbribe = 0;

        if(arr[i] - (i+1) > 2){
            printf("Too chaotic\n");
            return;
        }

        for(int j = (arr[i]-2>0 ? arr[i]-2 : 0); j < i; j++){
            if(arr[j] > arr[i]){
                inbribe++;
            }
        }

        bribe += inbribe;
    }

    printf("%d\n", bribe);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        minimumBribes(n);
    }
    return 0;
}
