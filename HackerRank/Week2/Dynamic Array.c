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
    
    int n,q;
    scanf("%d  %d",&n,&q);

    char query[q][100];
    for(int i=0;i<q;i++){
        scanf(" %[^\n]",query[i]);
    }
    
    int last=0;
    
    int** arr= (int**)malloc(n * sizeof(int*));
    int size[n];
    int avail[n];
    
    for(int i=0;i<n;i++){
        size[i]=0;
        avail[i]=1;
        arr[i]=(int*)malloc(avail[i]*sizeof(int));
    }
    
    
    for(int i=0;i<q;i++){
        
        int type=query[i][0]-'0',x=0,y=0,j=2;
        
        while(query[i][j]>='0' && query[i][j]<='9'){
            x=x*10+(query[i][j]-'0');
            ++j;
        }
        
        while(query[i][j]==' '){
            j++;
        }
        while(query[i][j]>='0' && query[i][j]<='9'){
            y=y*10+(query[i][j]-'0');
            ++j;
        }
        
        
        int ind1,ind2;
        
        if(type==1){
            ind1=(x^last)%n;
            if(size[ind1]==avail[ind1]){
                avail[ind1]*=2;
                arr[ind1] = (int*)realloc(arr[ind1], avail[ind1] * sizeof(int));
            }
            arr[ind1][size[ind1]]=y;
            size[ind1]++;
        }else {
            ind1=((x^last)%n);
            ind2=y % size[ind1];
            last=arr[ind1][ind2];
            printf("%d\n",last);
        }
    }
    
    for(int i=0;i<n;i++){
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
