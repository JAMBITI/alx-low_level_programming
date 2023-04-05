#include "main.h"
/**
 * factorial - fuction that return the factorial of numer
 * @n: numer of factorial 
 *
 * Return: factorial of number
 */
int factorial(int n)
{
	if (n < 0)
	return (-1);
	if (n == 0)
	return (1);
	return (n * factorial(n - 1));
}
