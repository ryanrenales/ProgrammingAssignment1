#include "chatbots.h"

int main(){
    // create QUOTE.txt file
    create_file();

    // create semaphore
    sem_t* sem = create_semaphore();

    // create an array for 7 threads
    pthread_t threads[7];
    // creates the 7 threads using the create_threads function
    create_threads(threads, sem);

    // destroys the semaphore
    destroy_semaphore(sem);

    return 0;
}
