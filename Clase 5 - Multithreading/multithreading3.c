#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  
#include <sys/wait.h>

//Creamos el struct que utilizaremos para pasar los argumentos
struct args_struct {
    int numero;
    char* cadena;
}; 

void* myFunction(void* input){
    
    //Casteamos el puntero void* a args_struct* y luego obtenemos los calores que contiene
    printf("Cadena: %s\n", ((struct args_struct*)input)->cadena); 
    printf("Numero: %d\n", ((struct args_struct*)input)->numero);

    sleep(5);
    printf("Trabajo realizado\n");
}

int main(){

    pthread_t thread;
    int err;
    char cadena[] = "Hola Mundo";
    
    struct args_struct myArgs; //Creamos un struct
    myArgs.cadena = cadena; //Asignamos los valores al struct
    myArgs.numero = 24;

    err = pthread_create(&thread, NULL, myFunction, (void *) &myArgs); //Pasamos el puntero del struct a la funcion
    if(err){
        printf("Error al crear el hilo: %d\n", err);
        return 1;
    }

    printf("Esperando al hilo...\n");

    pthread_join(thread, NULL);

    printf("Hilo terminado\n");

    return 0;
}
