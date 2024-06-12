#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para dividir o array e retornar o índice do pivô
int particionar(int array[], int baixo, int alto) {
    int pivo = array[alto];
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++) {
        if (array[j] < pivo) {
            i++;
            trocar(&array[i], &array[j]);
        }
    }
    trocar(&array[i + 1], &array[alto]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int array[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(array, baixo, alto);

        // Ordena os elementos antes e depois da partição
        quickSort(array, baixo, pi - 1);
        quickSort(array, pi + 1, alto);
    }
}

// Função para imprimir o array
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int array[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);
    printf("Array original:\n");
    imprimirArray(array, tamanho);
    quickSort(array, 0, tamanho - 1);
    printf("Array ordenado:\n");
    imprimirArray(array, tamanho);
    return 0;
}
