#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  
#include <sys/wait.h>

struct args {
    int numero;
    char* cadena;
}; 

void* myFunction(void* id){

    int *thread_id = (int*)id; //Casteamos el puntero de tipo void* a int*

    printf("Imprimiendo desde Hilo %d\n", *thread_id); //Obtenemos el valor del puntero

    sleep(5);
    printf("Trabajo realizado - Hilo %d\n", *thread_id);
}

int main(){

    pthread_t threads[5];
  
    for(int i = 0; i < 5; i++){ 

        int *a = malloc(sizeof(int)); //Creamos un puntero 'a''y le asignamos espacio para almacenar un entero
        *a = i; //Almacenamos el valor de i en la posicion de memoria a donde apunta el puntero a

        pthread_create(&threads[i], NULL, myFunction, (void *) a); //Pasamos el puntero que creamos como agumento en la creacion del hilo
    }   
    


    // printf("Esperando a los hilos...\n");

    for(int i = 0; i < 5; i++){
        pthread_join(threads[i], NULL);
    }   

    // printf("Trabajo terminado\n");

    return 0;
}
