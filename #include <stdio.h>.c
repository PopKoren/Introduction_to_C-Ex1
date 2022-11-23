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

#include <stdio.h>
#include <math.h>

int checkID(int id)
{
    int sumid = 0, sumid2 = 0, scale;
    int id2 = id / 10;

    if (log10(id) + 1 < 10)
    {
        while (id > 0)
        {
            scale = id % 10;
            sumid = sumid + scale;
            id = id / 100;
        }
        

        while (id2 > 0) 
        {
            scale = id2 % 10; 
            scale = (scale * 2); 
            if (scale >= 10)
            {
                scale = scale % 10 + 1; 
                sumid2 = scale + sumid2; 
            }
            else
                sumid2 = sumid2 + scale;

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
