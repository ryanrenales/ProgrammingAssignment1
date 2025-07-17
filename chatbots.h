#ifndef CHATBOTS_H
#define CHATBOTS_H

#include <semaphore.h>
#include <pthread.h>

void create_file();
sem_t* create_semaphore();
void* thread_function(void* arg);
void create_threads(pthread_t threads[], sem_t* sem);
void destroy_semaphore(sem_t *sem);

#endif // CHATBOTS_H
