/*
 ============================================================================
 Name		 : Power_Of_Three.c
 Author		 : Manar Hashem
 Date		 : Oct 24, 2023
 Version	 : 1.0
 Description : Checks whether a given number is a power of 3 or not
			   with 2 approaches
 ============================================================================
*/

/********* Include Libraries *********/
#include <stdio.h>
#include <math.h>

#include "STD_Types.h"

/************* First approach: Remider .. If the number is divisible by 3 *************
 ********* and the remaining number is 1 (3 pow 0) then it's a power of 3 *************/
/*int main()
{
    u32 num = 0;
	u8 TrueFlag = 0;
	printf("\nPower of 3:\n");
	printf("Enter a number: ");
	
	scanf("%d",&num);
	if(num > 1)
	{
		u32 x = num;
		while(1)
		{
			if(x == 1)
			{
				TrueFlag = 1;
				break;
			}
			else if ((x % 3 != 0) || (x == 0))
			{
				TrueFlag = 0;
				break;
			}
			else
			{
				x = x / 3;
			}
		}
		if(TrueFlag == 1)
		{
			TrueFlag = 0;
			printf("%d is a power of 3", num);
		}
		else
		{
			printf("%d is not a power of 3", num);
		}
	}
	else
	{
		printf("Invalid Range.. Try again\n");
	}
    return 0;
}
*/

/************ Second approach: Log.. If the log3(num) is an integer number ************
 ************ then it's a power of 3.. Ex: log3(9) = 2 as 3 pow 2 = 9      ************/

int main(void)
{
	u32 num = 0;
	printf("\nPower of 3:\n");
	printf("Enter a number: ");
	
	scanf("%d",&num);
	if(num > 0)
	{
		f64 result = log10(num) / log10(3);
		if(result == (u32)result)
		{
			printf("%d is a Power of 3 =)",num);
		}
		else
		{
			printf("%d is not a power of 3",num);
		}
	}
	else
	{
		printf("Invalid Range.. Try again\n");
	}
	return 0;
}
