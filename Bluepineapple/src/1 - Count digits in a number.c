//Program to count number of digits of a number


#include <stdio.h>

int digitCount(int number)
{
    int i, count = 0;
    
    if(number == 0)
	{
		count = 1;
	}
    
	else
	{
		if(number < 0)
		{
		    number = number * (-1);
		}
		        
		for(i = 0; number > 0; i++)
		{
		    number = number / 10;
		                
		    count = count + 1;
		}
	}
    
    return count;
}

void testDigitCount()
{
	int testCases[6][2] = {{123,3}, {54,2}, {7,1}, {0,1}, {7852,5}, {345,4}};
	
	int number, count = 0;
	char *tableHeadings[] = {"Sr.No.", "Input", "Expected output", "Actual output", "Status"};
	char *status[] = {"passed", "failed"};
	
	printf("========================================================================================================");
    printf("\n%s\t\t| %-10s\t\t| %-10s\t\t| %-10s\t\t| %-3s", tableHeadings[0], tableHeadings[1], tableHeadings[2], tableHeadings[3], tableHeadings[4]);
	printf("\n========================================================================================================");
		

	for(number = 0; number < 6; number++)
	{
		count = digitCount(testCases[number][0]);
		
		if(count == testCases[number][1])
		{
			printf("\n%d\t\t| %-10d\t\t| %-15d\t\t| %-10d\t\t| %-3s", number+1, testCases[number][0], testCases[number][1], count, status[0]);
			
			printf("\n--------------------------------------------------------------------------------------------------------");
		}
		
		else
		{
			printf("\n%d\t\t| %-10d\t\t| %-15d\t\t| %-10d\t\t| %-3s", number+1, testCases[number][0], testCases[number][1], count, status[1]);
			
			printf("\n--------------------------------------------------------------------------------------------------------");
		}
	}
}

void main()
{
   testDigitCount();
}
