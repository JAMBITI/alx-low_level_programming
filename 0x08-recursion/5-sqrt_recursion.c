#include "main.h"
/**
 * _sqrt_recursion - fuction
 * @n: inp
 *
 * Return: to 0
 */
int _sqrt_recursion(int n);

int main(void)
{
	int num = 144;
	int result = _sqrt_recursion(num);

	if (result == -1)
	printf("%d is not a perfect square.\n", num);
	else
	printf("Square root of %d is %d\n", num, result);

	return (0);
}

int _sqrt_recursion(int n)
{
	if (n < 0)
	return (-1);
	if (n == 0 || n == 1)
	return (n);

	int start = 1, end = n / 2;
	int mid, res;

	while (start <= end)
	{
	mid = (start + end) / 2;
	if (mid * mid == n)
	return (mid);
	if (mid * mid < n)
	{
	start = mid + 1;
	res = mid;
	}
	else
	end = mid - 1;
	}

	return (res);
}
