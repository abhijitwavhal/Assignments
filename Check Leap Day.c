#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int validate_date(int day, int month, int year)
{
	if(year>0)
	{
	    if((month>0) && (month<=12))
	    {
	        
			if((month==2) && ((year%4==0) && ((year%400==0) || (year%100!=0))) && (day<=29) && (day>0))
	        {
	            return 1;
	        }
	           
	        else if((month==2) && (!((year%4==0) && ((year%400==0) || (year%100!=0)))) && (day<=28) && (day>0))
	        {
	            return 1;
	        }
	           
	        else if((month==2) && (day>29))
	        {
	            printf("\nLeap year has 29 days in February and non-leap year has 28 days in February");
	            return 0;
	        }
			
			else if((month%2==0) && (month<=7) && (day<=30) && (day>0))
	        {
	           return 1;
	        }
	        
	        else if((month%2!=0) && (month<=7) && (day<=31) && (day>0))
	        {
	            return 1;
	        }

            else if((month%2==0) && (month>=8 && month<=12) && (day<=31) && (day>0))
	        {
	            return 1;
	        }

            else if((month%2!=0) && (month>=8 && month<=12) && (day<=30) && (day>0))
	        {
	            return 1;
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
	
	else
	{
	    return 0;
	}
}

void leap_day(int day, int month, int year)
{
    if(validate_date(day, month, year))
    {
    	if((year%4==0) && ((year%400==0) || (year%100!=0)))
        {
        	if(month==2)
            {
            	if(day==29)
                {
                	printf("\nLeap day");
                }
                
                else if(day<=28)
                {
                	printf("\nNot a leap day");
                }
            }
            
            else
            {
            	printf("\nleap day lies in Februay month only");
            }
        }
        
        else
        {
        	printf("\nNot a leap year");
        }
    }
    
    else
    {
        printf("\nNot a valide date");
    }
}

void check_leap_day()
{
	int i, day, month, year;
	
	for(i=1; i<=10; i++)
    {
    	day = rand() % 29 + 1;
    }

    for(i=1; i<=10; i++)
    {
    	month = rand() % 2 + 1;
    }

    for(i=1; i<=10; i++)
    {
    	year = rand() % 2020 + 1;
    }
    
    printf("\n%d-%d-%d", day, month, year);
    leap_day(day, month, year);
    
}

void main()
{
  int n = 1;
  
  while(n<=20)
  {
  	check_leap_day();
  	n++;
  }
}
