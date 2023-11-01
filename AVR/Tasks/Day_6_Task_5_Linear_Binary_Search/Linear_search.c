#include <stdio.h>
#include "STD_Types.h"

u8 Linear_Search(u8 * arr, u8 size, u8 Key)
{
	u8 Local_Return = 255;
	for(u8 count = 0; count < size; count++)
	{
		if(Key == arr[count])
		{
			Local_Return = count;
			break;
		}
		else
		{
			//No Code
		}
	}
	return Local_Return;
}

int main(void)
{
	u8 arr[7] = {1,3,5,6,8,10,15};
	u8 Index = 0;
	Index = Linear_Search(arr, 7, 14);
	if(Index == 255)
	{
		printf("\nThe Key doesn't exist in the array\n");
	}
	else
	{
		printf("\nThe Index of the key in the array is %d\n",Index);
	}
	
	return 0;
}