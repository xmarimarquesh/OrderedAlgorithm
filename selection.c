#include <stdio.h>

int *selection(int *array, int tamanho){
    for(int i = -1; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++)
        {
            if(array[i] < array[j]){
                int variavel = array[i];
                array[i] = array[j];
                array[j] = variavel;
            }
        }
    }

    return array;
}

int main(){
    int array[] = {9,4,5,8,1,3,2,7,6};

    int tamanho = sizeof(array)/sizeof(array[0]);
    
    int *newArray = selection(array, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("\n%d", newArray[i]);
    }
}