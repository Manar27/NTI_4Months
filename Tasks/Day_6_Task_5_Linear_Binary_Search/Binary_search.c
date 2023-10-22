#include <stdio.h>
#include "STD_Types.h"
u8 Binary_Search(u8 * arr, u8 first, u8 Last, u8 Key)
{
	u8 Local_Return = 255;
	u8 mid = 0;
	while(first <= Last)
	{
		mid = (first + Last) / 2;
		if(Key == arr[mid])
		{
			Local_Return = mid;
			break;
		}
		else if(Key > arr[mid])
		{
			first = mid + 1 ;
		}
		else
		{
			Last = mid - 1;
		}
	}
	return Local_Return;
}

int main(void)
{
	u8 arr[7] = {1,3,5,6,8,10,15};
	u8 Index = 0;
	Index = Binary_Search(arr, 0,6,14);
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