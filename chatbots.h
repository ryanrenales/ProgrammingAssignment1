#ifndef CHATBOTS_H
#define CHATBOTS_H

#include <stdio.h>
#include <sys/types.h> //Fetches specific data types for
#include <unistd.h> //POSIX access
#include <semaphore.h>
#include <fcntl.h> //Allows access to file control options
#include <pthread.h>

void create_file();
sem_t* create_semaphore();
void create_threads(pthread_t threads[]);
void* thread_function(void* arg, sem_t* sem);
void destroy_semaphore(sem_t *sem);

#endif // CHATBOTS_H