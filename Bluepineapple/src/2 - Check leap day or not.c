//Program to find if given day is leap day or not


#include <stdio.h>

int isLeapYear(int year)
{
    if ((year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0)))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int dateValidation(int day, int month, int year)
{
	if ((year > 0) && (month > 0) && (month <= 12) && (day > 0))
	{
		if (month == 2)
		{
			if (isLeapYear(year) && (day <= 29))
			{
				return 1;
			}

			else if (!(isLeapYear(year)) && (day <= 28))
			{
				return 1;
			}

			else if (day > 29)
			{
				return 0; //Leap year has 29 days in February and non-leap year has 28 days in February
			}
		}

		else if (month % 2 == 0)
		{
			if ((month <= 7) && (day <= 30))
			{
				return 1;
			}

			else if ((month >= 8 && month <= 12) && (day <= 31))
			{
				return 1;
			}
		}

		else if (month % 2 != 0)
		{
			if ((month <= 7) && (day <= 31))
			{
				return 1;
			}

			else if ((month >= 8 && month <= 12) && (day <= 30))
			{
				return 1;
			}
		}

		else
		{
			return 0;
		}
	}

	else
	{
		return 0;
	}
}

int checkLeapDay(int day, int month, int year)
{
	if (dateValidation(day, month, year))
	{
		if ((year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0)))
		{
			if (month == 2)
			{
				if (day == 29)
				{
					return 1; //Leap day
				}

				else if (day <= 28)
				{
					return 2; //Not a leap day
				}
			}

			else
			{
				return 3; //Leap day lies in Februay month only
			}
		}

		else
		{
			return 4; //Not a leap year
		}
	}

	else
	{
		return 5; //Not a valide date
	}
}

char *numberToString(int number)
{
	switch (number)
	{
		case 1: return "Leap day";
		break;
	
		case 2: return "Not a leap day";
		break;
	
		case 3: return "Leap day lies in Februay month only";
		break;
	
		case 4: return "Not a leap year";
		break;
	
		case 5: return "Not a valide date";
		break;
	}
}

void testLeapDay()
{
	int day, month, year, actualOutput, iterator;

	int dates[6][4] = {{1, 29, 2, 2024}, {2, 15, 2, 2024}, {3, 4, 11, 2024}, {4, 12, 4, 2023}, {5, -1, 12, 2022}, {2, 29, 2, 2028}};

	char *tableHeadings[] = {"Sr.No.", "Input", "Expected output", "Actual output", "Status"};
	char *status[] = {"passed", "failed"};

	printf("=================================================================================================================================================");
	printf("\n%s\t\t| %-10s\t\t| %-30s\t\t| %-30s\t\t| %-3s", tableHeadings[0], tableHeadings[1], tableHeadings[2], tableHeadings[3], tableHeadings[4]);
	printf("\n=================================================================================================================================================");

	for (iterator = 0; iterator < 6; iterator++)
	{
		actualOutput = checkLeapDay(dates[iterator][1], dates[iterator][2], dates[iterator][3]);

		if (actualOutput == dates[iterator][0])
		{
			printf("\n%d\t\t| %d/%d/%d\t\t| %-30s\t\t| %-30s\t\t| %-3s", iterator+1, dates[iterator][1], dates[iterator][2], dates[iterator][3], numberToString(dates[iterator][0]), numberToString(actualOutput), status[0]);
			
			printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");
		}

		else
		{
			printf("\n%d\t\t| %d/%d/%d\t\t| %-30s\t\t| %-30s\t\t| %-3s", iterator+1, dates[iterator][1], dates[iterator][2], dates[iterator][3], numberToString(dates[iterator][0]), numberToString(actualOutput), status[1]);
			
			printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------");

		}
	}
}

void main()
{
	testLeapDay();
}
