//Program to check if given number is perfect number or not


#include <stdio.h>

int isPerfectNumber(int number)
{
    int iterator, divisor = 0;

    for (iterator = 1; iterator < number; iterator++)
    {
        if (number % iterator == 0)
        {
            divisor = divisor + iterator;
        }
    }

    if (divisor == number)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

char *numberToString(int number)
{
	switch (number)
	{
		case 1: return "Perfect number";
		break;
	
		case 0: return "Not a perfect number";
	}
}

void testPerfectNumber()
{
    int day, month, year, expectedOutput, actualOutput, iterator;

	int testCases[5][2] = {{1, 6}, {1, 28}, {0, 35}, {0, 99}, {0, 496}};

	char *tableHeadings[] = {"Sr.No.", "Input", "Expected output", "Actual output", "Status"};
	char *status[] = {"passed", "failed"};

	printf("================================================================================================================");
	printf("\n%s\t\t| %-10s\t\t| %-10s\t\t| %-15s\t\t| %-3s", tableHeadings[0], tableHeadings[1], tableHeadings[2], tableHeadings[3], tableHeadings[4]);
	printf("\n================================================================================================================");

    for (iterator = 0; iterator < 5; iterator++)
	{
        expectedOutput = testCases[iterator][0];
        actualOutput = isPerfectNumber(testCases[iterator][1]);
        
        if(expectedOutput == actualOutput)
        {
            printf("\n%d\t\t| %-10d\t\t| %-10s\t\t| %-15s\t\t| %-3s", iterator+1, testCases[iterator][1], numberToString(expectedOutput), numberToString(actualOutput), status[0]);
			
			printf("\n----------------------------------------------------------------------------------------------------------------");
        }

        else
        {
            printf("\n%d\t\t| %-10d\t\t| %-10s\t\t| %-10s\t\t| %-3s", iterator+1, testCases[iterator][1], numberToString(expectedOutput), numberToString(actualOutput), status[1]);
			
			printf("\n----------------------------------------------------------------------------------------------------------------");
        }
    }

}

void main()
{
    testPerfectNumber();
}
