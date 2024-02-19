#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  
#include <sys/wait.h>

struct args {
    int numero;
    char* cadena;
}; 

void* myFunction(void* name){

    printf("Imprimiendo desde %s\n", (char*) name);

    sleep(5);
    printf("Trabajo realizado - %s\n", (char*) name);
}

int main(){

    pthread_t thread1, thread2; //Se crea una variable tipo pthread_t, está será el identificador del hilo  
    
    // Creamos un hilo, este necesita un identificador (pthread_t), atributos del hilo, la funcion que ejecutara y los argumentos
    pthread_create(&thread1, NULL, myFunction, "Hilo 1");
    pthread_create(&thread2, NULL, myFunction, "Hilo 2");


    printf("Esperando a los hilos...\n");
    
    // Para terminar un hilo utilizamos pthread_join, este espera a que el hilo termine su operacion y luego elimina el hilo
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Trabajo terminado\n");

    return 0;
}
