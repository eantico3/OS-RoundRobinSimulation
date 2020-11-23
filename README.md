# RoundRobinSimulation

Write a C/C++ program which reads in a list of process names and integer times from stdin/cin and simulates round-robin CPU scheduling on the list. The input is a list of lines each consisting of a process name and an integer time, e.g.


ProcessA 4
ProcessB 10
Read the list until end of transmission, EOF(^d). You should read the list and represent it in a linked list data structure. You are allowed to use STL classes, BUT NOT a vector. You should use the alarm system call to schedule a timer interrupt every 3 seconds and sleep (or usleep) to simulate the process running. Use time remaining on the process for the call to sleep. It's easiest if the interrupt handler sets a flag. Upon returning from either sleep or the interrupt handler, update the time left to execute by subtracting 3 seconds or time remaining, if not interrupted. Write a message saying how much time it has left to execute, i.e.


ProcessA 1
If the time reamining is greater than 0, return it to the end of the queue. If the process has no time left to execute, you should write a message saying this i.e.


ProcessA Finished
and delete the process from the linked list. If there are no processes left to execute, write a message saying

No processes left
and terminate your program.
