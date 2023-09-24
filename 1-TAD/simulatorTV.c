#include <stdio.h>

typedef struct tv{
    int state; // 0 or 1
    int channel; // any
    int volume; // 0 to 10
}TV;

TV buyTV(){
    TV anyTV;
    anyTV.state = 0;
    anyTV.channel = 1;
    anyTV.volume = 5;
    return anyTV;
}

void tunrOnOff(TV* anyTV){
    switch(anyTV->state){
        case 0:
            printf("A TV foi ligada!\n");
            anyTV->state = 1;
            break;
        case 1:
            printf("A TV foi desligada!\n");
            anyTV->state = 0;
            break;
        default:
            printf("erro");
    }
}

void changeChannel(TV* anyTV, int newChannel){
    if(!(anyTV->state)){printf("TV desligada\n"); return;} 
    anyTV->channel = newChannel;
    printf("Canal da tv foi mudado\n");
}

void changeVolume(TV* anyTV, int volume){
    if(!(anyTV->state)){printf("TV desligada\n"); return;} 
    if(volume>10 || volume<0){
        printf("Volume informado inexistente\n");
    } else{
        switch(volume){
            case 0:
                printf("TV no mudo\n");
                anyTV->volume = volume;
                break;
            case 10:
                printf("TV no volume maximo\n");
                anyTV->volume = volume;
                break;
            default:
                printf("Volume da TV em %d\n", volume);
                anyTV->volume = volume;
        }
    }
}

void showTvStatus(TV* anyTV){
    if(anyTV->state){
        printf("TV ligada no canal %d e volume %d\n", anyTV->channel, anyTV->volume);
    }else{
        printf("TV desligada\n");
    }
    
}

int main(){
    TV kaioTV = buyTV();
    showTvStatus(&kaioTV);
    changeChannel(&kaioTV,12);
    tunrOnOff(&kaioTV);
    changeChannel(&kaioTV,12);
    changeVolume(&kaioTV,10);
    showTvStatus(&kaioTV);
    return 0;
}