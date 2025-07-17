#include "chatbots.h"

int main(){
    create_file();

    sem_t sem = create_semaphore();

    pthread_t threads[7];
    create_threads(threads);

    destroy_semaphore(sem);

    return 0;
}
