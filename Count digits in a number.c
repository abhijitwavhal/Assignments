#include <stdio.h>

int digitCount(int num)
{
    int i, count=0;
    
    if(num==0)
	{
		count = 1;
	}
    
	else
	{
		if(num<0)
		{
		    num = num * (-1);
		}
		        
		for(i=0; num>0; i++)
		{
		    num = num/10;
		                
		    count = count+1;
		}
	}
    
    return count;
}

void test_digit_func()
{
	int testCases[6][2] = {{123,3}, {54,2}, {7,1}, {0,1}, {7852,5}, {345,4}};
	
	int num, count=0;
	int i,j;
	char *tableHeadings[] = {"Sr.No.", "Input", "Expected output", "Actual output", "Status"};
	char *status[] = {"passed", "failed"};
	
	//printf("\n%*-3s\t\t| %*-3s\t\t| %*-3s\t\t| %*-3s\t\t| %*-3s", tableHeadings[0], tableHeadings[1], tableHeadings[2], tableHeadings[3], tableHeadings[4]);

	for(num=0; num<6; num++)
	{
		count = digitCount(testCases[num][0]);
		
		if(count == testCases[num][1])
		{
			printf("\n%-3d\t\t| %-3d\t\t| %-3d\t\t| %-3d\t\t| %-3s", num, testCases[num][0], testCases[num][1], count, status[0]);
		}
		
		else
		{
			printf("\n%-3d\t\t| %-3d\t\t| %-3d\t\t| %-3d\t\t| %-3s", num, testCases[num][0], testCases[num][1], count, status[1]);
		}
	}
}

void main()
{
   test_digit_func();
}
