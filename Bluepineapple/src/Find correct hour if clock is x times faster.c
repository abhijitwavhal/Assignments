// Program to find correct current hour if a clock moves faster by 'x' minutes

#include <stdio.h>
#include <math.h>

int validateTime(int hour, int minutes)
{
	if ((hour >= 1) && (hour <= 24))
	{
		if ((minutes >= 0) && (minutes <= 60))
		{
			return 1;
		}

		else
		{
			printf("\nWrong minute format");
			return 0;
		}
	}

	else
	{
		printf("\nWrong hour format");
		return 0;
	}
}

int hourToMinutes(int hour, int minutes)
{
	int totalMinutes;

	totalMinutes = (hour * 60) + minutes;

	return totalMinutes;
}

int processCorrectHour(int x, int hour, int minutes)
{
	int iterator, hourToMin, speed;
	float totalMinutes, actualHour;

	if (x >= 0)
	{
		if (validateTime(hour, minutes))
		{
			hourToMin = hourToMinutes(hour, minutes);

			for (iterator = 1; iterator <= 24; iterator++)
			{
				if (iterator == hour)
				{
					speed = x * iterator;
				}
			}

			totalMinutes = hourToMin - speed;

			actualHour = Math.trunc(totalMinutes / 60);

			actualHour = Math.round(actualHour);

			return actualHour;
		}
	}

	else
	{
		return -1; //This program is not designed for slower clock speed;
	}
}

void testCorrectHour()
{
	int x, hour, minutes, actualOutput, expectedOutput, iterator;

	char *tableHeadings[] = {"Sr.No.", "Input", "Expected output", "Actual output", "Status"};
    char *status[] = {"passed", "failed"};
	
	int testCases[5][4] = {{15, 2, 30, 2}, {15, 5, 0, 4}, {15, 11, 15, 9}, {-15, 8, 45, -1}, {15, 6, 15, 6}};

	printf("=================================================================================================================================================");
    printf("\n%s\t\t| %-30s\t\t| %-10s\t\t| %-10s\t\t| %-3s", tableHeadings[0], tableHeadings[1], tableHeadings[2], tableHeadings[3], tableHeadings[4]);
    printf("\n=================================================================================================================================================");
	
	for(iterator = 0; iterator < 5; iterator++)
	{
		x = testCases[iterator][0];
		hour = testCases[iterator][1];
		minutes = testCases[iterator][2];
		expectedOutput = testCases[iterator][3];

		actualOutput = processCorrectHour(x, hour, minutes);

		if(expectedOutput == actualOutput)
		{
			printf("\n%d\t\t| Fast by=%d, Hour=%d, Minutes=%-2d\t\t| %-15d\t\t| %-10d\t\t| %s", iterator+1, x, hour, minutes, expectedOutput, actualOutput, status[0]);
			
			printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");
		}

		else
		{
			printf("\n%d\t\t| Fast by=%d, Hour=%d, Minutes=%-2d\t\t| %-15d\t\t| %-10d\t\t| %s", iterator+1, x, hour, minutes, expectedOutput, actualOutput, status[1]);
			
			printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");
		}
	}

	
}

void main()
{
	testCorrectHour();
}
