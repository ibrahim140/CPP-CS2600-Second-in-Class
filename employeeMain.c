//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    //defined in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double nameToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration
    
    //Example not found
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if (matchPtr != NULL)
        printf("Employee ID %d is in the record %d\n", 1045, matchPtr - EmployeeTable);
    else 
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee %s is in record %d\n", "Tony Bobcat", matchPtr - EmployeeTable);
    else
        printf("Employee %s is NOT found in the record\n", "Tony Bobcat");


    //Example of Match
    double salary = 4.50;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salary);
    if (matchPtr != NULL)
        printf("Employee with a salary of %.2lf is in record %d.\n", salary, matchPtr - EmployeeTable);
    else
        printf("Employee with a salary of %.2lf is NOT found in the record.\n", salary);

    //Example of No match
    salary = 5.65;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salary);
    if (matchPtr != NULL)
        printf("Employee with a salary of %.2lf is in record %d.\n", salary, matchPtr - EmployeeTable);
    else
        printf("Employee with a salary of %.2lf is NOT found in the record.\n", salary);


    //Example of Match
    char * phoneNumber = "909-555-1235";
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, phoneNumber);
    if (matchPtr != NULL)
        printf("Employee with phone number '%s' is in record %d.\n", phoneNumber, matchPtr - EmployeeTable);
    else
        printf("Employee with phone number '%s' is NOT found in the record.\n", phoneNumber);

    //Example of No match
    phoneNumber = "714-259-7591";
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, phoneNumber);
    if (matchPtr != NULL)
        printf("Employee with phone number '%s' is in record %d.\n", phoneNumber, matchPtr - EmployeeTable);
    else
        printf("Employee with phone number '%s' is NOT found in the record.\n", phoneNumber);

    return EXIT_SUCCESS;
}