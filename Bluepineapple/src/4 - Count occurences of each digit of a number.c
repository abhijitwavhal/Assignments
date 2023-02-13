// Program to count occurences of each digit of a number

#include <stdio.h>

int digitCount[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int *countDigitOccurence(int number)
{
    int iterator, tempNumber = 0;
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    if (number < 0)
    {
        number = number * (-1);
    }

    while (number > 0)
    {
        tempNumber = number % 10;

        for (iterator = 0; iterator <= 9; iterator++)
        {
            if (digits[iterator] == tempNumber)
            {
                digitCount[iterator] = digitCount[iterator] + 1;
            }
        }

        number = number / 10;
    }

    return digitCount;
}

int testDigitOccurence()
{
    int iterator1, iterator2, iterator3, count = 0, number = 0, expectedOutput = 0, actualOutput = 0, *digitOccurence;

    int testCases[5][11] = {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 123}, {0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 77}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 45}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 123456789}};

    char *tableHeadings[] = {"Sr.No.", "Input", "Expected output", "Actual output", "Status"};
    char *status[] = {"passed", "failed"};

    printf("================================================================================================================");
    printf("\n%s\t\t| %-10s\t\t| %-50s\t\t| %-50s\t\t| %-3s", tableHeadings[0], tableHeadings[1], tableHeadings[2], tableHeadings[3], tableHeadings[4]);
    printf("\n================================================================================================================");

    for (iterator1 = 0; iterator1 < 5; iterator1++)
    {
        number = testCases[iterator1][10];
        
		digitOccurence = countDigitOccurence(number);

        for (iterator2 = 0; iterator2 < 10; iterator2++)
        {
            expectedOutput = testCases[iterator1][iterator2];
            actualOutput = digitOccurence[iterator2];

            if (expectedOutput == actualOutput)
            {
                count = count + 1;
            }
        }

        if (count == 10)
        {
            printf("\n%d\t\t| %-10d\t\t| '0'-%d, '1'-%d, '2'-%d, '3'-%d, '4'-%d, '5'-%d, '6'-%d, '7'-%d, '8'-%d, '9'-%-50d\t\t| '0'-%d, '1'-%d, '2'-%d, '3'-%d, '4'-%d, '5'-%d, '6'-%d, '7'-%d, '8'-%d, '9'-%-50d\t\t| %-3s", iterator1 + 1, testCases[iterator1][10],
                   testCases[iterator1][0], testCases[iterator1][1], testCases[iterator1][2], testCases[iterator1][3], testCases[iterator1][4], testCases[iterator1][5], testCases[iterator1][6], testCases[iterator1][7], testCases[iterator1][8], testCases[iterator1][9],
                   digitOccurence[0], digitOccurence[1], digitOccurence[2], digitOccurence[3], digitOccurence[4], digitOccurence[5], digitOccurence[6], digitOccurence[7], digitOccurence[8], digitOccurence[9],
                   status[0]);

            printf("\n----------------------------------------------------------------------------------------------------------------");
        }

        else
        {
            printf("\n%d\t\t| %-10d\t\t| '0'-%d, '1'-%d, '2'-%d, '3'-%d, '4'-%d, '5'-%d, '6'-%d, '7'-%d, '8'-%d, '9'-%-50d\t\t| '0'-%d, '1'-%d, '2'-%d, '3'-%d, '4'-%d, '5'-%d, '6'-%d, '7'-%d, '8'-%d, '9'-%-50d\t\t| %-3s", iterator1 + 1, testCases[iterator1][10],
                   testCases[iterator1][0], testCases[iterator1][1], testCases[iterator1][2], testCases[iterator1][3], testCases[iterator1][4], testCases[iterator1][5], testCases[iterator1][6], testCases[iterator1][7], testCases[iterator1][8], testCases[iterator1][9],
                   digitOccurence[0], digitOccurence[1], digitOccurence[2], digitOccurence[3], digitOccurence[4], digitOccurence[5], digitOccurence[6], digitOccurence[7], digitOccurence[8], digitOccurence[9],
                   status[1]);

            printf("\n----------------------------------------------------------------------------------------------------------------");
        }
        
        //resetting the counters
        count = 0;

        for(iterator3 = 0; iterator3 < 10; iterator3++)  
	    {  
	        digitCount[iterator3] = 0;  
	    }
    }
}

void main()
{
    testDigitOccurence();
}
