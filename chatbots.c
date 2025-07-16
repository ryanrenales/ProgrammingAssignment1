#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

sem_t FLAG; // Semaphore FLAG

void* thread(void* arg) {
    // even numbered quote
    const char* even = "Controlling complexity is the essence of computer programming. --Brian Kernighan";
    // odd numbered quote
    const char* odd  = "Computer science is no more about computers than astronomy is about telescopes. --Edsger Dijkstra";
    int threadNum = *(int*)arg; // thread number

    // repeat 8 times total
    for (int i = 0; i < 8; i++) {
        if (threadNum % 2 == 0) {
            sleep(2); // even numbered thread
        }
        else {
            sleep(3); // odd numbered thread
        }

        sem_wait(&FLAG); // get semaphore flag

        FILE* fp = fopen("QUOTE.txt", "a"); // open file QUOTE.txt

        if (threadNum % 2 == 0) {
            // print thread ID followed by quote for even numbered thread
            fprintf(fp,"Thread ID %d: \"%s\"\n", threadNum, even);
        }
        else {
            // print thread ID followed by quote for odd numbered thread
            fprintf(fp,"Thread ID %d: \"%s\"\n", threadNum, odd);
        }

        // write to the console
        printf("Thread %d is running\n", threadNum);

        fclose(fp); // close file QUOTE.txt

        sem_post(&FLAG); // release semaphore FLAG

    }
    return NULL; // exit

}

