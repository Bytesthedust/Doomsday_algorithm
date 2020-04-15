#include <stdio.h>
#include <stdlib.h>

void doomsdayInfo(void)//prints out information about doomsdays
{
    printf("In 1970, British mathematician John Conway devised a way\
 to use the doomsday phenomenon to quickly calculate the weekday of any given date \
 without the help of calculators, computers, or calendars.His algorithm is based on the fact that\
 there are some dates that inevitably share the same weekday within any given year:\n\n");

    printf(" January: 1/3 in a common year, 1/4 in a leap year \n February: 2/28 in a common year, 2/29 in a leap year\n\
 March: 3/7\n April: 4/4\n May: 5/9\n June: 6/6\n July: 7/11\n August: 8/8\n September: 9/5\n October: 10/10\n November:11/7\n December: 12/12\n\n ");
    printf("Each weekday is represented by a number\n");
    printf(" Sunday= 0\n Monday= 1\n Tuesday= 2\n Wednesday= 3\n Thursday= 4\n Friday= 5\n Saturday=6\n");

    printf("\n");
    printf("Anchor days:\n");
    printf(" 1800-1899:Friday \n 1900-1999: Wednesday \n 2000-2099: Tuesday \n 2100-2199 Sunday\n");
}

int getYear(void)//asks user for year that they want to know the doomsday of
{
    int year;
    printf("Enter the year:");
    scanf("%d", &year);
    return year;
}

int convertYear(int year)//retrieves the last two digits of the inputted year
{
    return (year % 100);
}

int getAnchorDay(int year)//determines the century code of the inputted year
{
    if (year > 1800 && year < 1899)
        return 5;
    else if (year > 1900 && year < 1999)
        return 3;
    else if (year > 2000 && year < 2099)
        return 2;
    else if (year > 2100 && year < 2199)
        return 0;
    return 0;
}

void checkLeapYear(int year)//checks if inputted year is a leap year
{
    if(year % 4 == 0 || year % 400 == 0)
    {
        printf("%d is a leap year!\n", year);
    }
    else
    {
        printf("%d is not a leap year.\n", year);
    }
}

int calculateDoomsday(int year, int anchor)//calculates the doomsday using Conway's algorithm
{
    int doomsday;
    doomsday = (((year / 12) + (year % 12) + (year % 12) / 4) % 7 + anchor) % 7;
    return doomsday;
}

void get_day(int doomsday)//prints what the doomsday of the year based on the results of the algorithm
{
    if(doomsday == 0)
        printf("Doomsday: Sunday\n");
    else if(doomsday == 1)
        printf("Doomsday: Monday\n");
    else if(doomsday == 2)
        printf("Doomsday: Tuesday\n");
    else if(doomsday == 3)
        printf("Doomsday: Wednesday\n");
    else if(doomsday == 4)
        printf("Doomsday: Thursday\n");
    else if(doomsday == 5)
        printf("Doomsday: Friday\n");
    else if(doomsday == 6)
        printf("Doomsday: Saturday\n");
}



int main(void)
{
   int year, anchor, doomsday, year_nums;
   char loopContinue;
   doomsdayInfo();

   while(loopContinue != 'q')
   {
    year = getYear();
    checkLeapYear(year);

    year_nums = convertYear(year);
    anchor = getAnchorDay(year);
    doomsday = calculateDoomsday(year_nums, anchor);
    get_day(doomsday);
    printf("Do you want to input another year? \n");
    printf("'c' to continue or 'q' to quit: ");
    scanf(" %c", &loopContinue);
    if(loopContinue == 'c')
    {
        continue;
    }
   }


    return 0;
}
