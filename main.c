#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//AGGIUNGI UNA FUNZIONE CHE CERCA UN DETERMINATO VALORE NELL'ALBERO
struct Tree{
    int value;
    struct Tree* left;
    struct Tree* right;
};


void insertLeft(struct Tree *tr){
    tr -> left = realloc(NULL,sizeof(struct Tree));
    printf("Inserisci valore del nodo a sinistra: ");
    scanf("%d\n", &(tr->left -> value));
    //printf("Hai inserito il valore %d a sinistra\n"  , tr->left -> value);
}

void insertRight(struct Tree *tr){
    printf("Inserisci valore del nodo a destra: ");
    tr -> right = realloc(NULL,sizeof(struct Tree));
    scanf("%d\n", &(tr->right -> value));
    //printf("Hai inserito il valore %d a destra\n" , tr->right -> value);
}

void moveLeft(struct Tree *tr){
    *tr = *(tr -> left);
    printf("Ti sei spostato a sinistra\n");
}

void moveRight(struct Tree *tr){
    *tr = *(tr -> right); // perche' non va bene tr = &(tr -> right)????
    printf("Ti sei spostato a destra\n");
}


void moveUp(struct Tree *tr){
    
}

void printVal(struct Tree *tr){
    printf("Il valore del nodo corrente e': %d\n", tr -> value);

}

void searchVal(int val){

}

//void traverseUpwards serve una variabile che tiene la storia
int main(){
    // se si prova ad accedere ad un nodo che non e' neancora stato creato ez segFault
    struct Tree* currTr;
    int* history = (int*)malloc(sizeof(int)); //potrei usare un puntatore alla struct ma preferisco vedere i valori, oppure uso void* ?????
    int length = 1;
    currTr = realloc(NULL,sizeof(struct Tree));
    printf("Inserisci valore del nodo: ");
    scanf("%d", &(currTr -> value));
    *history = currTr -> value;
    char* comm = (char*)malloc(11 * sizeof(char)); // questo e' puro bofonchio
    while(1){
        scanf("%s",comm);
        if(strcmp("insertLeft",comm) == 0){
            insertLeft(currTr);
        }
        if(strcmp("insertRight",comm) == 0){
            insertRight(currTr);
        }
        if(strcmp("moveLeft",comm) == 0){
            moveLeft(currTr);
            history = realloc(history,sizeof(int));
            *(history + length++) = currTr -> value; //sintassi mostruosa
        }
        if(strcmp("moveRight",comm) == 0){
            moveRight(currTr);
            history = realloc(history,sizeof(int));
            *(history + length++) = currTr -> value;
        }
        if(strcmp("print",comm) == 0){
            printVal(currTr);
        }
        if(strcmp("quit",comm) == 0){
            break;
        }
        if(strcmp("search",comm) == 0){
            printf("Which element do you want to search: ");
            int val;
            scanf("%d",&val);
            searchVal(val);
        }
    }

    for(int i = 0; i < length; i++){
        printf("The element number %d is: %d\n",i, history[i]);
    }

    return 0;
}