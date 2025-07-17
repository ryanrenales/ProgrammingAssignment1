#ifndef CHATBOTS_H
#define CHATBOTS_H

#include <semaphore.h>
#include <pthread.h>

void create_file(); // function to create the file
sem_t* create_semaphore(); // function to create the semaphore
void* thread_function(void* arg); // thread function for chat bots
void create_threads(pthread_t threads[], sem_t* sem); // function to create the threads
void destroy_semaphore(sem_t *sem); // function to destroy the semaphore

#endif // CHATBOTS_H
