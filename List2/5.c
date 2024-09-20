/* 
   Name : 5.c
   Author: Siddhesh Dare
   Description :5. Write a program to print the system limitation of
                a. maximum length of the arguments to the exec family of functions.
                b. maximum number of simultaneous process per user id.
                c. number of clock ticks (jiffy) per second.
                d. maximum number of open files
                e. size of a page
                f. total number of pages in the physical memory
                g. number of currently available pages in the physical memory.
   Date :  10 Sep
*/


#include <unistd.h> 
#include <stdio.h>  

void print(char *text, long value, char *unit)
{
    printf("%s - %ld %s\n", text, value, unit);
    printf("========================\n");
}

void main()
{
    long value;


    // _SC_ARG_MAX -  Maximum length of the arguments to the exec family of functions.
    value = sysconf(_SC_ARG_MAX);
    if(value == -1)
        perror("Error while getting _SC_ARG_MAX!");
    else 
        print("Maximum length of the arguments to the exec family of functions", value, "");

    // _SC_CHILD_MAX -  Maximum number of simultaneous process per user id.
    value = sysconf(_SC_CHILD_MAX);
    if(value == -1)
        perror("Error while getting _SC_CHILD_MAX!");
    else 
        print("Maximum number of simultaneous process per user id", value, "");

    // _SC_CLK_TCK -  Number of clock ticks (jiffy) per second.
    value = sysconf(_SC_CLK_TCK);
    if(value == -1)
        perror("Error while getting _SC_CLK_TCK!");
    else 
        print("Number of clock ticks (jiffy) per second", value, "");
        
    // _SC_OPEN_MAX -  Maximum number of open files
    value = sysconf(_SC_OPEN_MAX);
    if(value == -1)
        perror("Error while getting _SC_OPEN_MAX!");
    else 
        print("Maximum number of open files", value, "");

    // _SC_PAGESIZE -  Size of a page
    value = sysconf(_SC_PAGESIZE);
    if(value == -1)
        perror("Error while getting _SC_PAGESIZE!");
    else 
        print("Size of a page", value, "bytes");

    // _SC_PHYS_PAGES -  Total number of pages in the physical memory
    value = sysconf(_SC_PHYS_PAGES);
    if(value == -1)
        perror("Error while getting _SC_PHYS_PAGES!");
    else 
        print("Total number of pages in the physical memory", value, "");

    // _SC_AVPHYS_PAGES -  Number of  currently available pages in the physical memory.
    value = sysconf(_SC_AVPHYS_PAGES);
    if(value == -1)
        perror("Error while getting _SC_AVPHYS_PAGES!");
    else 
        print("Number of  currently available pages in the physical memory", value, "");

}


/*
Output:
Maximum length of the arguments to the exec family of functions - 2097152 
========================
Maximum number of simultaneous process per user id - 22952 
========================
Number of clock ticks (jiffy) per second - 100 
========================
Maximum number of open files - 1048576 
========================
Size of a page - 4096 bytes
========================
Total number of pages in the physical memory - 1486733 
========================
Number of  currently available pages in the physical memory - 248970 
========================
*/