#include "shell.h"
/**
*Ctrlc - does not exit main when ctrl c pressed
*@x:int
*/
void Ctrlc(int x)
{
	(void) x;
	write(1, "\n$ ", 3);
}

