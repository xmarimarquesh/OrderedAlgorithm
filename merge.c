#include <stdio.h>

//função para juntar os arrays que foram divididos
void merge(int * array1, int * array2, int size1, int size2) {

    int * copyA1 = malloc(size1 * sizeof(int)); 
    int * copyA2 = malloc(size2 * sizeof(int)); 
    int * arrayFinal = array1;


    for(int i = 0; i < size1; i++) {

        copyA1[i] = array1[i];
    }

    for(int i = 0; i < size2; i++) {

        copyA2[i] = array2[i];
    }

    int esquerda = 0;
    int direita = 0;
    int final = 0;

    while(esquerda < size1 && direita < size2) {

        if(copyA1[esquerda] < copyA2[direita]) {

            arrayFinal[final] = copyA1[esquerda];
            final++;
            esquerda++;
        }

        else {

            arrayFinal[final] = copyA2[direita];
            final++;
            direita++;
        }
    }

    while (esquerda < size1) {
        
        arrayFinal[final] = copyA1[esquerda];
        final++;
        esquerda++;
    }

    while (direita < size2) {
        
        arrayFinal[final] = copyA2[direita];
        final++;
        direita++;
    }

    free(copyA1);
    free(copyA2);
}

void mergeSort(int * array, int size) {

    if(size == 1) {

        return;
    }

    int espaco_esquerda = size/2;
    int espaco_direita = (size/2) + (size % 2);

    int size1 = espaco_esquerda;
    int size2 = espaco_direita;

    //array+espaco_esquerda   pula as posições do array
    int * array2 = array+espaco_esquerda;

    mergeSort(array, size1);
    mergeSort(array2, size2);

    merge(array, array2, size1, size2);

}

int main() {
    
    int array[] = {1,6,8,4,6,3,7,5,9};
    int size = sizeof(array)/sizeof(array[0]);

    mergeSort(array, size);

    for(int i = 0; i < size; i++) {

        printf(" %i ", array[i]);
    }
}