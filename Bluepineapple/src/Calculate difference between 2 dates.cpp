//Program to find difference between two dates in days using object oriented programming

#include <iostream>

using namespace std;

int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
    public:
            int startDay, endDay, startMonth, endMonth, startYear, endYear;

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

            int isDateValid(int day, int month, int year)
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

            int daysCounter(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear)
            {
                int tempMonth, count = 0, days = 0;

                for (tempMonth = startMonth; tempMonth <= 12; tempMonth++)
                {
                    count = count + monthDays[tempMonth];
                }

                days = days + count - startDay;
                count = 0;

                for (tempMonth = 1; tempMonth < endMonth; tempMonth++)
                {
                    count = count + monthDays[tempMonth];
                }

                days = days + count + endDay;
                count = 0;

                if (((startMonth > 2) && (isLeapYear(startYear))) || ((endMonth < 2) && (isLeapYear(endYear))))
                {
                    days = days - 1;
                }

                return days;
            }

            int dateDifference(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear)
            {
                int days = 0, year = 0, tempDays, tempMonth, tempYear, count = 0;

                if ((isDateValid(startDay, startMonth, startYear) == 0) || (isDateValid(endDay, endMonth, endYear) == 0) || (startYear > endYear))
                {
                    days = -2; //-2 to indicate date is not valid
					return days;
                }

                else
                {
                    if (startYear == endYear)
                    {
                        if (startMonth == endMonth)
                        {
                            if (startDay == endDay)
                            {
                                days = 0;
                                return days;
                            }

                            else
                            {
                                days = endDay - startDay;
                                return days;
                            }
                        }

                        else
                        {
                            for (tempDays = startMonth; tempDays < endMonth; tempDays++)
                            {
                                days = days + monthDays[tempDays];
                            }

                            days = days + endDay - startDay;

                            return days;
                        }
                    }

                    else
                    {
                        for (tempYear = startYear; tempYear <= endYear; tempYear++)
                        {
                            if (isLeapYear(tempYear))
                            {
                                count = count + 1;
                            }
                        }
                        
                        days = count;
                        count = 0;

                        year = (endYear - 1) - (startYear + 1);

                        if (year == -1)
                        {
                            days = days + daysCounter(startDay, startMonth, startYear, endDay, endMonth, endYear);
                        }

                        else if (year >= 0)
                        {
                            days = days + daysCounter(startDay, startMonth, startYear, endDay, endMonth, endYear) + ((year + 1) * 365);
                        }

                        return days;
                    }
                }
            }

            int testDateDifference()
            {
                int dates[4][7] = {{397, 1, 3, 2023, 1, 4, 2024}, {563, 23, 2, 2025, 9, 9, 2026}, {18570, 17,1,1940, 21,11,1990}, {-2, 1, 13, 2023, 1, 4, 2024}};

                int startDay, startMonth, startYear, endDay, endMonth, endYear, daysCount, iterator, expectedOutput;

                char *tableHeadings[] = {"Sr.No.", "Input", "Expected output", "Actual output", "Status"};

                char *status[] = {"passed", "failed"};


                printf("========================================================================================================================");
                printf("\n%s\t\t| %-15s\t\t| %-3s\t\t| %-15s\t\t| %-3s", tableHeadings[0], tableHeadings[1], tableHeadings[2], tableHeadings[3], tableHeadings[4]);
                printf("\n========================================================================================================================");
                
                for (iterator = 0; iterator < 4; iterator++)
                {
                    expectedOutput = dates[iterator][0];
                    startDay = dates[iterator][1];
                    startMonth = dates[iterator][2];
                    startYear = dates[iterator][3];
                    endDay = dates[iterator][4];
                    endMonth = dates[iterator][5];
                    endYear = dates[iterator][6];

                    daysCount = dateDifference(startDay, startMonth, startYear, endDay, endMonth, endYear);

                    if (expectedOutput == daysCount)
                    {
                        printf("\n%d\t\t| %d/%d/%d, %d/%d/%d\t\t| %-15d\t\t| %-15d\t\t| %-3s", iterator+1, startDay, startMonth, startYear, endDay, endMonth, endYear, expectedOutput, daysCount, status[0]);

                        printf("\n------------------------------------------------------------------------------------------------------------------------");
                    }

                    else
                    {
                        printf("\n%d\t\t| %d/%d/%d, %d/%d/%d\t\t| %-15d\t\t| %-15d\t\t| %-3s", iterator+1, startDay, startMonth, startYear, endDay, endMonth, endYear, expectedOutput, daysCount, status[1]);

                        printf("\n------------------------------------------------------------------------------------------------------------------------");
                    }
                }
            }
};

int main()
{
    // int startDay, endDay, startMonth, endMonth, startYear, endYear, daysCount;
    Date date;

    // date.startDay = 1;
    // startDay = date.startDay;

    // date.startMonth = 3;
    // startMonth = date.startMonth;

    // date.startYear = 2023;
    // startYear = date.startYear;

    // date.endDay = 1;
    // endDay = date.endDay;

    // date.endMonth = 4;
    // endMonth = date.endMonth;

    // date.endYear = 2024;
    // endYear = date.endYear;

    // daysCount = date.dateDifference(startDay, startMonth, startYear, endDay, endMonth, endYear);

    // printf("\nTotal days = %d", daysCount);

    date.testDateDifference();

    return 0;
}
