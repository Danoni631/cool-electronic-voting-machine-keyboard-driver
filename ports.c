// Only if you want ports in/out made in C

#include "ports.h"

VOID outb(WORD port, BYTE value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

CHAR inb(WORD port)
{
    CHAR ret;
    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}
