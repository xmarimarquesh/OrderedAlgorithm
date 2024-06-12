#include <stdio.h>

int *insertion(int *array, int tamanho){

    int comparados = 0;

    for(int i = 1; i < tamanho ; i++){
        for(int j = 0; j<comparados; j++){
            if(array[j] > array[i]){
                int variavel = array[j];
                array[j] = array[i];
                array[i] = variavel;
            }
        }
        comparados++;
    }
    return array;
}

int main(){
    int array[] = {9,4,5,8,1,3,2,7,6};

    int tamanho = sizeof(array)/sizeof(array[0]);
    
    int *newArray = insertion(array, tamanho);

    for(int i = 0; i < tamanho; i++){
        printf("\n%d", newArray[i]);
    }
}