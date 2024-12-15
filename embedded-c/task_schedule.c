#include <stdlib.h>

sem_t sem0, sem1;

void* task0(void* arg) {
    while (1) {
        sem_wait(sem0);
        printf("ping\n");
        sem_post(sem1);
        sleep(1);
    }
    return NULL;
}

void* task1(void* arg) {
    while (1) {
        sem_wait(sem1);
        printf("pong\n");
        sem_post(sem0);
        sleep(1);
    }
    return NULL;
}

int main() {
    sem_init(&sem0, 1);
    sem_init(&sem1, 0);

    pthread_t th0, th1;

    thread_create(&th0, task0);
    thread_create(&th1, task1);

    thread_join(&th0);
    thread_join(&th1);

    sem_destroy(sem0);
    sem_destroy(sem1);

    return 0;
}