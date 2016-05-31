#include <stdio.h>
#include <stdlib.h>

char tablero[3][3];
char jugadorActual = 'X';

void inicializar(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tablero[i][j] = '_';
        }
    }
}
bool hayGanador(){
    //horizontal
    char jugadorEncontrado = tablero[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tablero[i][j] =='_'){
                break;
            }
            if(jugadorEncontrado != tablero[i][j]){
                break;
            }
            jugadorEncontrado = tablero[i][j];
            if(j == 2){
                printf("Ha ganado %c", jugadorEncontrado);
                return true;
            }
        }
    }

    //vertical
    jugadorEncontrado = tablero[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tablero[j][i] =='_'){
                break;
            }
            if(jugadorEncontrado != tablero[j][i]){
                break;
            }
            jugadorEncontrado = tablero[j][i];
            if(j == 2){
                printf("Ha ganado %c", jugadorEncontrado);
                return true;
            }
        }
    }


    //diagonal de izquierda a derecha
    jugadorEncontrado = tablero[0][0];
    for(int i=0; i<3; i++){
        if(tablero[i][i] =='_'){
            break;
        }
        if(jugadorEncontrado != tablero[i][i]){
                break;
        }
        jugadorEncontrado = tablero[i][i];
        if(i == 2){
            printf("Ha ganado %c", jugadorEncontrado);
            return true;
        }
    }

    //diagonal de derecha a izquierda
    jugadorEncontrado = tablero[0][2];
    for(int i=2; i>=0; i--){
        if(tablero[2-i][i] =='_'){
            break;
        }
        if(jugadorEncontrado != tablero[2-i][i]){
                break;
        }
        jugadorEncontrado = tablero[2-i][i];
        if(i == 0){
            printf("Ha ganado %c", jugadorEncontrado);
            return true;
        }
    }
    return false;
}

void desplegarTablero(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c\t", tablero[i][j]);
        }
        printf("\n");
    }
}

bool hayEmpate(){
    for(int i=0; i<3; i++){
        for(int j=0;j<3;j++){
            if(tablero[i][j] == '_'){
                return false;
            }
        }
    }
    printf("Hay un empate \n");
    return true;
}

int main(){
    inicializar();
    while(!hayGanador() && !hayEmpate()){
        desplegarTablero();
        int fila = 0;
        int columna = 0;
        printf("En que fila quiere jugar %c: ", jugadorActual);
        scanf("%d", &fila);
        printf("En que columna quiere jugar %c: ", jugadorActual);
        scanf("%d", &columna);
        if(tablero[fila][columna] != '_'){
            printf("Esa casilla ya esta ocupada, intente de nuevo\n");
        }else{
            tablero[fila][columna] = jugadorActual;
            if(jugadorActual == 'X'){
                jugadorActual = 'O';
            }else{
                jugadorActual = 'X';
            }
        }
    }
    printf("\n");
    desplegarTablero();
    printf("\n");
    system("pause");
}
