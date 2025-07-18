/*
Team Members: Kevin Townsend, Ryan Renales
Class Accounts: cssc1461 (Kevin), cssc1453 (Ryan) 
Class Info: CS 480, Summer 2025 
Assignment Info: Programming Assignment #1, Chatbots 
Filename: chatbots.h
*/

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
