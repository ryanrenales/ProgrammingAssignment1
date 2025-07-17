#include "chatbots.h"

int main(){
    create_file();

    sem_t FLAG = create_semaphore();

    pthread_t threads[7];
    create_threads(threads[7]);

    destroy_semaphore(FLAG);

    return 0;
}
