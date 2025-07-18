/*
Team Members: Kevin Townsend, Ryan Renales
Class Accounts: cssc1461 (Kevin), cssc1453 (Ryan) 
Class Info: CS 480, Summer 2025 
Assignment Info: Programming Assignment #1, Chatbots 
Filename: main.c
*/

#include <stdio.h>

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

    printf("The process has completed.\n");

    return 0;
}
