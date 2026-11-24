#include<stdio.h>
#include<string.h>

struct Robot
{   int id;
    char type[50];
    float capacity;
    float load;
    float operating_time;
    float utilization;
    char status[20];
};

int main ()
{   int n;

    printf("Enter number of robots: ");
    scanf("%d", &n);

    struct Robot robots[n];
    for (int i = 0 ; i < n ; i++)
    {   printf ("\n Enter details for robot %d :\n", i + 1);
        printf("Robot ID:");
        scanf("%d", &robots[i].id);

        printf("Robot Type:");
        scanf("%s", robots[i].type);

        printf("Payload Capacity :");
        scanf("%f", &robots[i].capacity);

        printf("Actual load:");
        scanf("%f", &robots[i].load);

        printf("Operating Time :");
        scanf("%f", &robots[i].operating_time);

        robots[i].utilization = (robots[i].load / robots[i].capacity) * 100.0;

        if(robots[i].load > robots[i].capacity)
        {   strcpy (robots[i].status, "Overloaded");
        }
        else
        {   strcpy (robots[i].status, "Within Limit");
        }
    }

    printf("\n ID \t Type \t Capacity \t load \t Time \t Util (%%) \t Status \n");

    for (int i = 0 ; i < n ; i++)
    {   printf("%d \t %s \t %.2f \t %.2f \t %.2f \t %.2f \t %s \n",
               robots[i].id, robots[i].type, robots[i].capacity,
               robots[i].load, robots[i].operating_time,
               robots[i].utilization, robots[i].status);
    }

    return 0;
}
