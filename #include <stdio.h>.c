#include <stdio.h>
#include <math.h>


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

int checkID(int id)
{
    int sumid = 0, sumid2 = 0, scaleof1;
    int id2 = id / 10;

    if (log10(id) + 1 < 10)
    {
        while (id > 0)
        {
            scaleof1 = id % 10;
            sumid = sumid + scaleof1;
            id = id / 100;
        }
        

        while (id2 > 0) 
        {
            scaleof1 = id2 % 10; 
            scaleof1 = (scaleof1 * 2); 
            if (scaleof1 >= 10)
            {
                scaleof1 = scaleof1 % 10 + 1; 
                sumid2 = scaleof1 + sumid2; 
            }
            else
                sumid2 = sumid2 + scaleof1;

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
