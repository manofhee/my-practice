sem_t sem_1;
sem_t sem_2;

void* task1(void* arg) {
    while (1) {
        sem_wait(&sem_1);
        printf("ping\n"); // do work
        sem_post(&sem_2);
        sleep(2); // do other work
    }
    return NULL;
}

void* task2(void* arg) {
    while (1) {
        sem_wait(&sem_2);
        printf("pong\n"); // do work
        sem_post(&sem_1);
        sleep(2);
    }
    return NULL;
}

int main() {
    sem_init(&sem_1, 1);
    sem_init(&sem_2, 0);

    pthread_t thread1, thread2;

    pthread_create(&thread1, task1);
    pthread_create(&thread2, task2);

    pthread_join(thread1);
    pthread_join(thread2);

    sem_destroy(&sem_1);
    sem_destroy(&sem_2);

    return 0;
}

