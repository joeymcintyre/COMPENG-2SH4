
#include "Questions.h"



int Q1_for(int num)
{
	int sum = 0;

	for (int i = 1; i < 1001; i++)
	{
		if (i % num == 0)
		{
			sum += i;
		}
	}
	return sum;
}
int Q1_while(int num){
	int sum = 0;
	int i = 1;

	while (i < 1001)
	{
		if (i % num == 0)
		{
			sum += i;
		}
		i ++;
	}
	return sum;
}
int Q1_dowhile(int num){
	int sum = 0;
	int i = 1;

	do
	{
		if (i % num == 0)
		{
			sum += i;
		}
		i++;
	} while (i < 1001);

	return sum;
}
//===============================================================================================
int Q2_FPN(float Q2_input, float Q2_threshold){
	
	int result;
	if ((-2*Q2_threshold) <= Q2_input && Q2_input < (-1*Q2_threshold))
	{
		result = 0;
	}
	else if ((-1*Q2_threshold) <= Q2_input && Q2_input < 0)
	{
		result = 1;
	}
	else if (0 <= Q2_input && Q2_input < Q2_threshold)
	{
		result = 2;
	}
	else if (Q2_threshold <= Q2_input && Q2_input <= (2*Q2_threshold))
	{
		result = 3;
	}
	else
	{
		result = -999;
	}

	return result;
}
//===============================================================================================
int Q3(int Q3_input, int perfect[]){
	
	    int counts = 0;
		
		for (int num = 2; num <= Q3_input; num++)
		{
			int divisors_sum = 0;

			for (int divisor = 1; divisor < num; divisor++)
			{
				if (num % divisor == 0)
				{
					divisors_sum += divisor;
				}
			}
			if (divisors_sum == num)
			{
				perfect[counts] = num;
				counts++;
			}
		}
	   return counts;

}
//===============================================================================================
int Q4_Bubble(int array[], int size){
	
	
	int passes = 0;
	int i;
	int x;
	int swapping;

	do {
		swapping = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i+1])
			{
				x = array[i];
				array[i] = array[i+1];
				array[i+1] = x;
				swapping = 1;
			}
		}
		passes++;
	}
	while (swapping);

	return passes;	
}