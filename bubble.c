#include <stdio.h>

int *bubble(int *array, int tamanho){
    for(int i = tamanho; i > 0 ; i--){
        for(int j = -1; j<i; j++){
            if(array[j] > array[i]){
                int variavel = array[j];
                array[j] = array[i];
                array[i] = variavel;
            }
        }
    }
    return array;
}

int main(){
    int array[] = {9,4,5,8,1,3,2,7,6};

    int tamanho = sizeof(array)/sizeof(array[0]);
    
    int *newArray = bubble(array, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("\n%d", newArray[i]);
    }
}