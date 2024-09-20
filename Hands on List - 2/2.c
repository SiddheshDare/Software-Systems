/* 
   Name : 2.c
   Author: Siddhesh Dare
   Description :2. Write a program to print the system resource limits. Use getrlimit system call.
   Date :  10 Sep
*/


#include <sys/time.h>     
#include <sys/resource.h> 
#include <stdio.h>        

void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", hard, unit);

    printf("====================\n");
}

void main()
{
    int status;                   // Determines the success of the `getrlimit` call
    struct rlimit resourceLimits; // Holds the hard & soft limits for a resource


    // RLIMIT_AS -> This  is  the maximum size of the process's virtual memory (address space).
    status = getrlimit(RLIMIT_AS, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_AS!");
    else
        print("Max size of process's virtual memory", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_CORE -> Max size of a core file
    status = getrlimit(RLIMIT_CORE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_CORE!");
    else
        print("Max size of a core file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_CPU -> Amount of CPU time that the process can consume
    status = getrlimit(RLIMIT_CPU, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_CPU!");
    else
        print("Max CPU time that the process can consume", resourceLimits.rlim_cur, resourceLimits.rlim_max, "seconds");

    // RLIMIT_DATA -> Maximum size of the process's data segment
    status = getrlimit(RLIMIT_DATA, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_DATA!");
    else
        print("Max size of process's data segement", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_FSIZE -> Maximum size of files that  the  process  may  create
    status = getrlimit(RLIMIT_FSIZE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_FSIZE!");
    else
        print("Max size of files that  the  process  may  create", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_LOCKS -> Maximum number of locks that a process may establish
    status = getrlimit(RLIMIT_LOCKS, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_LOCKS!");
    else
        print("Max number of locks that a process may establish", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    // RLIMIT_MEMLOCK -> Maximum number of bytes of memory that may be locked into RAM
    status = getrlimit(RLIMIT_MEMLOCK, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_MEMLOCK!");
    else
        print("Max number of bytes of memory that may be locked into RAM", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_MSGQUEUE -> Maximum number of bytes that can be allocated for POSIX message queues
    status = getrlimit(RLIMIT_MSGQUEUE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_MSGQUEUE!");
    else
        print("Max number of bytes of that can be allocated for POSIX message queues", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_NICE -> Ceiling of the process's nice value
    status = getrlimit(RLIMIT_NICE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_NICE!");
    else
        print("Ceiling of the process's nice value", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    // RLIMIT_NOFILE -> specifies a value one greater than the maximum file descriptor number that can be opened by this process
    status = getrlimit(RLIMIT_NOFILE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_NOFILE!");
    else
        print("Max file descriptor", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_NPROC -> Limit on the number of threads
    status = getrlimit(RLIMIT_NPROC, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_NPROC!");
    else
        print("Limit on the number of threads", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    // RLIMIT_RSS -> Limit on the number of virtual pages resident in the RAM
    status = getrlimit(RLIMIT_RSS, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_RSS!");
    else
        print("Limit on the  number of virtual pages resident in the RAM", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_RTPRIO -> a ceiling on the real-time priority
    status = getrlimit(RLIMIT_RTPRIO, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_RTPRIO!");
    else
        print("Ceiling on the real-time priority", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    // RLIMIT_RTTIME -> Amount of CPU time that a  process scheduled  under a real-time scheduling policy may consume without making a blocking system call.
    status = getrlimit(RLIMIT_RTTIME, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_RTTIME!");
    else
        print("Amount of CPU time that a  process scheduled  under a real-time scheduling policy", resourceLimits.rlim_cur, resourceLimits.rlim_max, "ms");

    // RLIMIT_SIGPENDING ->The number of signals that may be queued
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_SIGPENDING!");
    else
        print("The number of signals that may be queued", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    // RLIMIT_STACK -> Maximum  size of the process stack
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
}


/*
Output:
Max size of process's virtual memory - 
        Soft Limit: Unlimited
        Hard Limit: Unlimited
====================
Max size of a core file - 
        Soft Limit: 0 bytes
        Hard Limit: Unlimited
====================
Max CPU time that the process can consume - 
        Soft Limit: Unlimited
        Hard Limit: Unlimited
====================
Max size of process's data segement - 
        Soft Limit: Unlimited
        Hard Limit: Unlimited
====================
Max size of files that  the  process  may  create - 
        Soft Limit: Unlimited
        Hard Limit: Unlimited
====================
Max number of locks that a process may establish - 
        Soft Limit: Unlimited
        Hard Limit: Unlimited
====================
Max number of bytes of memory that may be locked into RAM - 
        Soft Limit: 761204736 bytes
        Hard Limit: 761204736 bytes
====================
Max number of bytes of that can be allocated for POSIX message queues - 
        Soft Limit: 819200 bytes
        Hard Limit: 819200 bytes
====================
Ceiling of the process's nice value - 
        Soft Limit: 0 
        Hard Limit: 0 
====================
Max file descriptor - 
        Soft Limit: 1048576 bytes
        Hard Limit: 1048576 bytes
====================
Limit on the number of threads - 
        Soft Limit: 22952 
        Hard Limit: 22952 
====================
Limit on the  number of virtual pages resident in the RAM - 
        Soft Limit: Unlimited
        Hard Limit: Unlimited
====================
Ceiling on the real-time priority - 
        Soft Limit: 0 
        Hard Limit: 0 
====================
Amount of CPU time that a  process scheduled  under a real-time scheduling policy - 
        Soft Limit: Unlimited
        Hard Limit: Unlimited
====================
The number of signals that may be queued - 
        Soft Limit: 22952 
        Hard Limit: 22952 
====================
Maximum  size of the process stack - 
        Soft Limit: 22952 bytes
        Hard Limit: 22952 bytes
====================
*/