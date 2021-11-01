#include <string.h>
#include <stdlib.h>
#include "employee.h"

Employee EmployeeTable[] =
{
    {1001l, "Daphne Borromeo", "909-555-2134", 8.78},
    {1011l, "Tammy Franklin",  "213-555-1212", 4.50},
    {1140l, "Dorris Perl",     "310-555-1215", 7.80},
    {4011l, "Tony Bobcat",     "909-555-1235", 6.34},
    {5045l, "Brian Height",    "714-555-2749", 8.32}
};

const int EmployeeTableEntries = sizeof(EmployeeTable)/sizeof(EmployeeTable[0]);    // 160/32 why??

//Explain padding in gcc compiler. Each member in struct Employee = 8 bytes
//Depends on Compiler used for Memory alighnment. All members can be accessed by incrementing equal distance
/*
void main()
{
    printf("%d\n", sizeof(EmployeeTable));
    printf("%d\n", sizeof(EmployeeTable[0]));
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(char*));
    printf("%d\n", sizeof(char*));
    printf("%d\n", sizeof(double));
}
*/
