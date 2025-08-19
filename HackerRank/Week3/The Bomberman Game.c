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

void bomberMan(int r,int c,char grid[r][c+1],int n){
    
    if(n == 1){
        for(int i=0;i<r;i++){
            printf("%s\n",grid[i]);
        }
        return;
    }
    
    if(n % 2 == 0){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){ 
                printf("O");
            }
            printf("\n");
        }
        return;
    }
    
    int itr=(n%4==3) ? 3 : 5;        
    
    int j=1;
    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            arr[i][j]=0;
        }
    }
    for(int k=0;k<itr;k++){
        if(k==0){
            ++j;
            continue;
        }
        if(j%2==0){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(grid[i][j]=='O'){
                        arr[i][j]=1;
                    }
                    grid[i][j]='O';
                }
            }
        }else{
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(arr[i][j]==1){
                        grid[i][j]='.';
                        if(i>0) grid[i-1][j]='.';
                        if(i<r-1) grid[i+1][j]='.';
                        if(j>0) grid[i][j-1]='.';
                        if(j<c-1) grid[i][j+1]='.'; 
                    }
                }
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    arr[i][j]=0;
                }
            }
        }
        ++j;
        
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
    
    int r,c,n;
    scanf("%d   %d   %d",&r,&c,&n);
    char grid[r][c+1];
    for(int i=0;i<r;i++){
        scanf("%s",grid[i]);
    }
    
    bomberMan(r,c,grid,n);
    
    return 0;
}
