#include "fileops.h"
#include <math.h>

int CallMeMaybe( inv_val *inv, int length)
{
        int i, j, k;
        int maxval = 0;
        double power = length-1;
        double maximum = pow(2, power);//gives me the maximum number of combinations 2^n-1

        int store[(int)maximum];

        //should set up all the number values to be 0
        for (i =0; i < maximum;i++)
                store[i] = 0;

        int curlen = length;
        if (length <= 0 )//if the length entered was 0 its worth exactly 0 dollars...
                return 0;

        maxval = inv->val[length];//sets the max val to be zero cuts (ie full length)


                for (i = 1; i <= length; i++)
                {
                        for(j = 0; j<i;j++)
                        {
                                if (maxval < inv->val[j] + store[(i-1)-j])
                                {
                                        maxval = inv->val[j] + store[(i-1)-j];
                                }
                        }

                        store[i] = maxval;
                }

        return maxval;
}
