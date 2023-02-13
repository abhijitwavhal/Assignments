// Program to check if string is palindrome or not


#include <stdio.h>
#include <string.h>
#include <malloc.h>

int isStringPalindrome(char *inputString)
{
    int iterator1, iterator2 = 0, cnt = 0;

    char *reverseString = (char *)malloc(sizeof(inputString));

    for (iterator1 = strlen(inputString) - 1; iterator1 >= 0; iterator1--)
    {
        reverseString[iterator2] = inputString[iterator1];
        iterator2++;
    }

    if (strcmp(inputString, reverseString) == 0)
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
		case 1: return "Palindrome string";
		break;
	
		case 0: return "Not a palindrome string";
        break;
	}
}

void checkPalindromeString()
{
    const char *output;
    int expectedOutput, actualOutput, iterator;

    char *tableHeadings[] = {"Sr.No.", "Input", "Expected output", "Actual output", "Status"};
    char *status[] = {"passed", "failed"};

    char *testCases[5][10] = {{"1", "level"}, {"1", "anna"}, {"0", "tiger"}, {"0", "tree"}, {"1", "earth"}};

    printf("=================================================================================================================================================");
    printf("\n%s\t\t| %-10s\t\t| %-30s\t\t| %-30s\t\t| %-3s", tableHeadings[0], tableHeadings[1], tableHeadings[2], tableHeadings[3], tableHeadings[4]);
    printf("\n=================================================================================================================================================");

    for (iterator = 0; iterator < 5; iterator++)
    {
        output = testCases[iterator][0];

        sscanf(output, "%d", &expectedOutput);

        actualOutput = isStringPalindrome(testCases[iterator][1]);

        if (expectedOutput == actualOutput)
        {
            printf("\n%d\t\t| %-10s\t\t| %-30s\t\t| %-30s\t\t| %-3s", iterator+1, testCases[iterator][1], numberToString(expectedOutput), numberToString(actualOutput), status[0]);
			
			printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");
        }
        
        else
        {
            printf("\n%d\t\t| %-10s\t\t| %-30s\t\t| %-30s\t\t| %-3s", iterator+1, testCases[iterator][1], numberToString(expectedOutput), numberToString(actualOutput), status[1]);
			
			printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");
        }
        
    }
}

void main()
{
    checkPalindromeString();
}
