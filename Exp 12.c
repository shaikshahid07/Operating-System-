#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];

void* philosopher(void* n) {
    int i = *(int*)n;
    sem_wait(&chopstick[i]);
    sem_wait(&chopstick[(i+1)%5]);

    printf("Philosopher %d is eating\n", i);
    sleep(1);
    printf("Philosopher %d finished eating\n", i);

    sem_post(&chopstick[i]);
    sem_post(&chopstick[(i+1)%5]);
}

int main() {
    pthread_t th[5];
    int i, id[5];
    for(i = 0; i < 5; i++) sem_init(&chopstick[i], 0, 1);
    for(i = 0; i < 5; i++) {
        id[i] = i;
        pthread_create(&th[i], NULL, philosopher, &id[i]);
    }
    for(i = 0; i < 5; i++) pthread_join(th[i], NULL);
    return 0;
}
