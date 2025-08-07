#include <stdio.h>

int main(){
    char time[10];
    scanf("%s",time);
    
    int hr=0;
    
    for(int i=0;i<2;i++){
        hr=hr*10 + (time[i]-'0');
    }
    
    if(time[8]=='P'){
        if(hr!=12){
            hr+=12;
        }
    }else if(time[8]=='A'){
        if(hr==12){
            hr=0;
        }
    }
    
    char conv[10];
    
    conv[0]=(hr/10)+'0';
    conv[1]=(hr%10)+'0';
    
    for(int j=2;j<=7;j++){
        conv[j]=time[j];
    }
    conv[8]='\0';
    
    printf("%s",conv);
       
    return 0;
}