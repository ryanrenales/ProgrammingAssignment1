#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // Fetches system-level data types 
#include <unistd.h> // POSIX access
#include <fcntl.h> // Allows access to file control options

#include "chatbots.h"

// struct to hold thread data; thread number and semaphore
typedef struct{
    int threadNum;
    sem_t* sem;
} ThreadData;

void create_file(){
    FILE *thisFile;

    // Create the QUOTE.txt file 
    thisFile = fopen("QUOTE.txt", "w");

    // Checks that the file was successfully created
    if(thisFile == NULL){
        perror("Error: Attempt to create QUOTE.txt was unsuccessful");
        exit(1); // exit with error
    }

    // Initialize variable for the current running process ID
    pid_t pid; 
    pid = getpid();

    // write process ID to file
    fprintf(thisFile, "Process ID: %d\r\n", pid);

    // close file
    fclose(thisFile);
}

sem_t* create_semaphore(){
    // Creates the pointer and sets values for the semaphore
    sem_t *sem;
    const char *sem_name = "/FLAG";
    unsigned int initial_value = 1;

    // Initializes the named semaphore
    sem = sem_open(sem_name, O_CREAT, 0666, initial_value);
    return sem;
}

void* thread_function(void* arg) {
    // even numbered quote
    const char* even = "Controlling complexity is the essence of computer programming. --Brian Kernighan";
    // odd numbered quote
    const char* odd  = "Computer science is no more about computers than astronomy is about telescopes. --Edsger Dijkstra";

    // takes thread data and assigns it to respective variables
    ThreadData* data = (ThreadData*)arg;
    int tid = data->threadNum ;
    sem_t* sem = data->sem;

    // repeat 8 times total
    for (int i = 0; i < 8; i++) {
        if (tid % 2 == 0) {
            sleep(2); // even numbered thread
        }
        else {
            sleep(3); // odd numbered thread
        }

        sem_wait(sem); // get semaphore flag

        FILE* fp = fopen("QUOTE.txt", "a"); // open file QUOTE.txt

        if (tid % 2 == 0) {
            // print thread ID followed by quote for even numbered thread
            fprintf(fp,"Thread ID %d: \"%s\"\n", tid, even);
        }
        else {
            // print thread ID followed by quote for odd numbered thread
            fprintf(fp,"Thread ID %d: \"%s\"\n", tid, odd);
        }

        // write to the console
        printf("Thread %d is running\n", tid);

        fclose(fp); // close file QUOTE.txt

        sem_post(sem); // release semaphore FLAG

    }
    free(data);
    return NULL; // exit
}

void create_threads(pthread_t threads[], sem_t* sem){
    //Loop to create 7 unique threads 
    for(int i = 0; i < 7; i++){
        // takes thread data and assigns it to respective variables
        ThreadData* data = malloc(sizeof(ThreadData));
        data->threadNum = i+1;
        data->sem = sem;
        // Check that the threads are successfully created
        printf("Creating thread, in main(): %d\n", data->threadNum);
        if(pthread_create(&threads[i], NULL, thread_function, data) != 0){
            printf("Error: Unsuccessful thread creation -> Thread %d", i+1);
        }
    }

    // Wait for the threads to complete their work
    for (int i = 0; i < 7; i++) {
        pthread_join(threads[i], NULL);
    }

}

void destroy_semaphore(sem_t *sem) {
    // Checks that the named sempahore is properly closed and unlinked
    if (sem_close(sem) == -1) {
        perror("Error: Failed to close semaphore");
    }
    if (sem_unlink("/FLAG") == -1) {
        perror("Error: Failed to unlink semaphore");
    } else {
        printf("Semaphore was successfully destroyed.\n");
    }
}

