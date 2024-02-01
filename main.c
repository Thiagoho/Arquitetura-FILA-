#include<stdio.h>

#define TAMFILA 10
int fila[TAMFILA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
int head = 0;
int tail = 0;
int i;

void lista_elementos() {
     printf("\t======= FILa Atual =======\n");
    for(i = 0; i < TAMFILA; i++) {
        printf("-");
        printf("|%d|", fila[i]);
        printf("-");
    }
    printf("\nHead: %d\n", head);
    printf("Tail: %d\n", tail);
    printf("\n\n");
}
void enqueue() {
    int val;
    if(tail < TAMFILA) {
        printf("Informe o elemento para adicionar na fila: ");
        scanf("%d", &val);
        fila[tail] = val;
        tail++;
        lista_elementos();

    } else {
        printf("A fila esta cheia!");
    }

}
void dequeue() {
    if(head < tail) {
        int removerdElement = fila[head];
        printf("Elemento removido: %d", removerdElement);
        for(i = 0; i < tail -1; i++) {
            fila[i] = fila[i + 1];

        }
        fila[tail - 1] = 0;
        tail--;
        lista_elementos();
    } else {
        printf("A fila esta vazia!");
    }
}
void clear() {
    for(i = 0; i < TAMFILA; i++) {
        fila[i] = 0; 
    }
    head = 0;
    tail = 0;
}
int main() {
    int opcao;
    do {
        printf("\tSeleciona a opcao: \n");
        printf("[1] + Inserir A FILA (enqueue)\n");
        printf("[2] + Inserir Remover (dequeue)\n");
        printf("[3] + Listar\n");
        printf("[4] + Limpar a fila\n");
        printf("[-1] + SAIR\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                enqueue();
                break;
            case 2: 
                dequeue();
                break;
            case 3:
                lista_elementos();
                break;
            case 4:
                clear();
                break;
            case -1:
                break;
            default:
                printf("Opcao Invalida!");
        }

    } while(opcao != -1);
        printf("Fim de Programa.");
    return 0;
}