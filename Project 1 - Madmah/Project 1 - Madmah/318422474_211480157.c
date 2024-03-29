#define _CRT_SECURE_NO_WARNINGS
#define N 3

/*Libraries*/
#include <stdio.h>
#include <math.h>

/*
	Assigned by:
		Koren_Abugov #211480157
		Avihai_Levi #318422474
*/

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

/* Declarations of other sub-functions */

int sumDigits(int);
int checkID(int);
int sumLongestArithmeticList(int);
int numberLength(int);
int rotateNumber(int, int);

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("Please select 0-%d : ", N);
				scanf("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */

void Ex1()
{
	int id = 0, answer = 0;
	printf("Please enter your id: ");
	scanf("%d", &id);
	answer = checkID(id);
	if (answer)
	{
		printf("Your id is a correct id.\n");
	}
	else
	{
		printf("Your id is incorrent.\n");
	}

}

void Ex2()
{
	int size = 0, answer = 0;
	printf("Please enter the arithmetic list size: ");
	scanf("%d", &size);
	answer = sumLongestArithmeticList(size);
	printf("The sum of the longest sequence arithmetic list is: %d.\n", answer);
}

void Ex3()
{
	int number = 0, spins = 0, answer = 0;
	printf("Please enter the number and the amount of spins: ");
	scanf("%d%d", &number, &spins);
	answer = rotateNumber(number, spins);
	printf("The number %d after %d spins is: %d.\n", number, spins, answer);
}

/* Sub-Function definitions */

int sumDigits(int num)
{
	int sum = 0, i;

	while (num > 0)
	{
		i = num % 10;
		sum += i;
		num /= 10;
	}

	return sum;
}


int checkID(int id)
{
	int sumid = 0, sumid2 = 0, scale;
	int id2 = id / 10;

	if (log10(id) + 1 < 10) // log10 of a number + 1 = length of the number
	{
		while (id > 0)
		{
			scale = id % 10;
			sumid += scale;
			id = id / 100;
		}


		while (id2 > 0)
		{
			scale = id2 % 10;
			scale = (scale * 2);
			if (scale >= 10)
			{
				scale = scale % 10 + 1;
				sumid2 += scale;
			}
			else
				sumid2 += scale;

			id2 = id2 / 100;
		}


		if ((sumid + sumid2) == 0) return 0;
		else if ((sumid + sumid2) % 10 == 0)
		{
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;

}

int sumLongestArithmeticList(int n)
{
	int CurrentNumber = 0;
	int LastNumber = 0;
	int diff = 0;
	int MaxRowLength = 0;
	int CurrentRowLength = 0;

	printf("Enter the first number:\n");
	scanf_s("%d", &LastNumber);

	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return LastNumber;
	}
	int maxSum = LastNumber;
	int currentSum = maxSum;

	for (int i = 1; i < n; i++)
	{
		printf("Enter another number:\n");
		scanf_s("%d", &CurrentNumber);
		if (diff == (CurrentNumber - LastNumber))
		{
			CurrentRowLength++;
			currentSum += CurrentNumber;

		}
		else
		{
			if (MaxRowLength == CurrentRowLength && maxSum < currentSum || MaxRowLength < CurrentRowLength)
			{
				maxSum = currentSum;
				MaxRowLength = CurrentRowLength;
			}
			diff = (CurrentNumber - LastNumber);
			CurrentRowLength = 2;
			currentSum = CurrentNumber + LastNumber;
		}
		LastNumber = CurrentNumber;
	}

	//Case when the Longest Arithmetic sequence is the last sequence
	if (MaxRowLength == CurrentRowLength && maxSum < currentSum || MaxRowLength < CurrentRowLength)
	{
		maxSum = currentSum;
		MaxRowLength = CurrentRowLength;
	}

	return maxSum;
}

int numberLength(int num)
{
	return log10(num) + 1;
}

int rotateNumber(int num, int spins)
{
	int ahadot;
	int length = numberLength(num);

	if (spins % length == 0) return num;

	for (int i = 0; i < spins; i++)
	{
		ahadot = num % 10;
		num /= 10;
		ahadot = ahadot * pow(10, length - 1);
		num += ahadot;
	}

	return num;
}

/* ------------------- */
