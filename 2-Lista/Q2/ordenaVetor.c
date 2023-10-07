#include <stdio.h>

int main(){
    int V[] = {4,5,8,9,1,0,2,3,4,6,78,4,97,35,67};
    for(int i=0; i<15; i++){
        for(int j = i+1; j< 15; j++){
            if(V[i] > V[j]){
                int aux = V[i];
                V[i] = V[j];
                V[j] = aux;
            }
        }
    }

    for(int i =0; i<15; i++){
        printf("%d ", V[i]);
    }

}