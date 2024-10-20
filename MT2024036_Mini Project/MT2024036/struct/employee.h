#ifndef EMPLOYEE_RECORD
#define EMPLOYEE_RECORD

struct Employee
{
    int id; // 0, 1, 2 ....
    char name[25];
    char gender; // M -> Male, F -> Female, O -> Other
    int age;
    // Login Credentials
    char username[30]; // Format : name-id (name will the first word in the structure member `name`)
    char password[30];
    bool isMag;
};

#endif