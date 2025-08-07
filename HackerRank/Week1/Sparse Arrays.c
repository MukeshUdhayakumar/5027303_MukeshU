#include <stdio.h>


int compare(char str[],char quer[]){
    for(int i=0;str[i]!='\0' || quer[i]!='\0';i++){
        if(str[i]!=quer[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    
    int n;
    scanf("%d",&n);
    char strings[n][20];
    for(int i=0;i<n;i++){
        scanf("%s",strings[i]);
    }
    
    int q;
    scanf("%d",&q);
    char queries[q][20];
    for(int i=0;i<q;i++){
        scanf("%s",queries[i]);
    }
    
    int results[q];
    for(int i=0;i<q;i++){
        results[i]=0;
    }
    
    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(compare(queries[i],strings[j])){
                results[i]+=1;
            }
        }
    }
    
    for(int i=0;i<q;i++){
        printf("%d\n",results[i]);
    }
    
    return 0;
  
} 