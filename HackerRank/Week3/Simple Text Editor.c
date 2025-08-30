#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[10000000];
int top = -1;

int undo[1000000];
int utop = -1;

char deleted[10000000];
int dtop = -1;

void push(char c){ 
    s[++top] = c; 
}

char pop(){ 
    return s[top--]; 
}

void upush(int val){ 
    undo[++utop] = val; 
}

int upop(){ 
    return undo[utop--]; 
}

void dpush(char c){ 
    deleted[++dtop] = c; 
}

char dpop(){ 
    return deleted[dtop--]; 
}

void textEditor(int q){
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){ 
            char str[100000];
            scanf("%s", str);
            int l=strlen(str);
            
            for(int i=0;i<l;i++){
                push(str[i]);
            }
            upush(l); 
            upush(1);  
        }else if(op==2){ 
            int k;
            scanf("%d", &k);

            for(int i=0;i<k;i++){
                dpush(pop());
            }
            upush(k);  
            upush(2);  
        }else if(op==3){ 
            int k;
            scanf("%d", &k);
            printf("%c\n", s[k-1]);
        }
        else if(op == 4){ 
            int type=upop();
            int l=upop();
            if(type == 1){      
                while(l--){
                    pop();
                }
            } else if(type == 2){ 
                while(l--){
                    push(dpop());
                }
            }
        }
    }
}

int main(){
    int q;
    scanf("%d",&q);
    textEditor(q);
    return 0;
}
