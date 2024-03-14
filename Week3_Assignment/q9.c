#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;
int shared_variable = 0;

void *thread_function(void *arg) {
    pthread_mutex_lock(&mutex);
    shared_variable++;
    printf("Shared variable = %d\n", shared_variable);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(thread, NULL) != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}
