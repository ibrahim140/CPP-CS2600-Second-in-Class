#include <string.h>
#include "../include/employee.h"

//NOTE: 5 functions have been defined below

//ptr: points to table to be searched
//tableSize: size of tehe table
//targetPtr: points to value that will be searched for in table
//functionPtr: points to comparison function  below and will perform the associated check


//what does settinga  function to static do? The functions can only be used within in this file/class
//functionPtr is the address of the function just as the name
//()(The second set of parentheses is the arguments of the function cell)

static PtrToEmployee searchEmployeeTable (PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
                                        int (*functionPtr)(const void *, PtrToConstEmployee))
{ //static, for functions = only usable in this file. Basically private.
    PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++)
    {
        if ((*functionPtr)(targetPtr, ptr) == 0)    //compareEmployeeNumber(&1045, TableRow)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

//The functionPtr will point to one of these comparison functions to perform a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return * (long *) targetPtr != tableValuePtr->number;
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr->name);
}

//These are called wrappers. These functinos are what you will use in your main.c
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number)
{   //pass the ADDRESS of number
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name)
{
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}
