#include <stdbool.h>

typedef struct {
    int items[10];
    //
} Queue;

typedef struct {
    bool locked;
    Queue waiting_threads;
} Mutex;

void mutex_init(Mutex* M) {
    M->locked = false;
    queue_init(&M->waiting_threads);
}

void mutex_lock(Mutex* M) {
    if (M->locked) {
        queue_push(&M->waiting_threads, get_current_thread());
        thread_suspend(get_current_thread());
    }
    M->locked = true;
}

void mutex_unlock(Mutex* M) {
    M->locked = false;
    if (!queue_is_empty(&M->waiting_threads)) {
        Thread* next = queue_pop(&M->waiting_threads);
        thread_resume(next);
    }
}