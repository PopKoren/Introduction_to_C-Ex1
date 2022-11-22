#include <stdio.h>
int sumDigits(int num)
{
	int sum = 0, i;

	while (num > 0)
	{
		i = num % 10;
		sum = sum + i;
		num = num / 10;
	}

	return sum;
}


int main()
{
	int num, sum;

	printf("Enter a number:");
	scanf_s("%d", &num);

	sum = sumDigits(num);

	printf("%d", sum);
}

