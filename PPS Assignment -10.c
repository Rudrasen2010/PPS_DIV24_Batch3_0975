#include <stdio.h>

int isLeapYear(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}

void printMonth(int month, int year, int startDay)
{
    char *months[] = {"January", "February", "March", "April",
                      "May", "June", "July", "August",
                      "September", "October", "November", "December"};

    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        days[1] = 29;

    printf("\n     %s %d\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < startDay; i++)
        printf("    ");

    for (int date = 1; date <= days[month - 1]; date++)
    {
        printf("%3d ", date);

        if ((startDay + date) % 7 == 0)
            printf("\n");
    }

    printf("\n");
}

int main()
{
    int year, startDay;
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    printf("Enter the year: ");
    scanf("%d", &year);

    int y = year - 1;
    startDay = (y + y / 4 - y / 100 + y / 400 + 1) % 7;

    for (int month = 1; month <= 12; month++)
    {
        printMonth(month, year, startDay);

        if (month == 2 && isLeapYear(year))
            days[1] = 29;

        startDay = (startDay + days[month - 1]) % 7;
    }

    return 0;
}
