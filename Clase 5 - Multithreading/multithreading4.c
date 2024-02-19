#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  
#include <sys/wait.h>

void* myFunction(void *arg)
{
    int n = *(int*)arg;  // Obtenemos el valor del id

    static int x = 10;  // Creamos una variable estatica que será compartida entre hilos

    int y = x;  // Asignamos esta variable estatica a una variable local del hilo

    // Ya que asignnamos x a y suponemos que el valor de estas será el mismo verdad?

    printf("Hilo %d: x = %d, y = %d\n", n, x, y);

    // En algunos casos lo es, pero por la naturaleza de los hilos es posible que no lo sean

    // Lo que pasa es que otro hilo aumenta el valor del x
    // pero el valor de y en este hilo se mantiene igual, entonces dejan de tener el mismo valor

    if (x != y) {
        printf("Hilo %d: Error! x != y! %d != %d\n", n, x, y);
    }

    x++;  // Aumentamos el valor de x

    return 0;
}

#define THREAD_COUNT 5

int main(void)
{
    pthread_t thread[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {

        int *a = malloc(sizeof *n);  // Almacenamos el id del hilo
        *a = i;
        pthread_create(&thread[i], NULL, myFunction, (void *) a);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(thread[i], NULL);
    }
}
