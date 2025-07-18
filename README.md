# ProgrammingAssignment1
Team Members: Kevin Townsend, Ryan Renales
Class Accounts: cssc1461 (Kevin), cssc1453 (Ryan) 
Class Info: CS 480, Summer 2025 
Assignment Info: Programming Assignment #1, Chatbots 
Filename: README.md

## File Manifest
chatbots.h (Header file)
chatbots.c (Source file)
main.c (Source file)
Makefile (makefile)
README.md (README)

## Compile Instructions
This program uses gcc as the compiler and compilation is handled with the makefile. When all the files are in the same directory the user can type "make clean" on the command line to clean up any old builds, removing any executable or object files. Then the user can type "make" which creates object files and links them to create an executable, "bots". Finally, to run the program the user types "make run" and the executable will run the program.
make clean > make > make run

## Operating Instructions
For this program there are no command line options or arguments, and no required inputs. Once the files are compiled and the program is ran the chatbots perform all their actions independent of user input.

## Design Decisions
Our team's approach for this program was to make several functions for the key functions of the program e.g crate_file(), create_semaphore(), thread_function(), then in the main.c file only include function calls so it is easy to follow and laysout how each step of the program works. One key design implementation we used was to create a struct for thread data, because there are multiple threads and their values had to be shared across the functions. Using a struct made the thread data easy to transport and universally available through the chatbots.c file.

## Extra Features/Functionality
Our team did not implement any extra functionalities or features to this program.

## Known Bugs
In testing we found no bugs, however one setback during development was that not all threads were writing to the QUOTE.txt file. The cause of this was because we weren't properly implementing pthreads_join() so the threads were not able to wait for one another to perform their task, and we also had to take in account the placement of the free(data) tool because if memory is deallocated too early it can cause threads to not finish their task.

## Lessons Learned
Major takeaways from this assignment include the importance of communication and early testing. The great communication between our team allowed us to complete the assignment without confusion about each other's responsibilities and an understanding of what each other's functions contribute to the assignment. Addressing each other when we made changes to the files or found setbacks allowed the team to stay on the same page and work at a consistent rate. The communication between the team was excellent and should be used for future projects. Another lesson was that it's important to start testing early and often so bugs can be caught before the final implementation. While our team caught all known bugs, we did not start testing as early as we could've, which left less time at the end for polishing. However, we found it slightly difficult to perform tests on just a single function for this assignment, and found it better to combine all the functions into the main.c file and run the program, allowing us to see which functions were performing as intended.
