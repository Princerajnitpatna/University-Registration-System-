#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 10
typedef struct node SLL;
struct node
{
    int data;
    SLL *next;
};
SLL *Table[MAX] = {NULL}, *c;

void ZeroArray(int *);
int sum(int *);
void PrintStudent();
SLL *Insert_End(SLL *, int);

int sum(int *arr)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    return sum;
}
void ZeroArray(int *Arr)
{
    for (int i = 0; i < 5; i++)
    {
        Arr[i] = 0;
    }
    return;
}
void PrintStudent()
{
    int k;
    printf("\n\t\t\t\t\t\t\t*** Student detail ***\n\n");
    printf("\t\t\t\t---------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tid\t\t  Class\t\tCourses\n");
    printf("\t\t\t\t---------------------------------------------------------------------------------\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("\n");
        if (Table[i] == NULL)
        {
            continue;
        }
        else
        {
            printf("\t\t\t\t\t %d\t\t ", i + 1); // change
            for (c = Table[i]; c != NULL; c = c->next)
            {

                printf("%5d", c->data);
            }
        }
    }
}

SLL *Insert_End(SLL *head, int newData)
{
    SLL *New_Node;
    New_Node = (SLL *)malloc(sizeof(SLL));

    if (New_Node == NULL)
    {
        printf("NO Memory");
        return head;
    }
    New_Node->next = NULL;
    New_Node->data = newData;
    if (head == NULL)
    {
        head = New_Node;
        return head;
    }
    else
    {
        SLL *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = New_Node;
        return head;
    }
}
void delay(int milliseconds)
{
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause)
        now = clock();
}
int main()
{

    int classCode, courseCode;
    int NumOfCourses;

    // 10 Students-Id No:1,2,3,4,5,6,7,8,9,10
    // 5 Courses -
    // Course Name             Course Code
    // 1.Data Structure        1
    // 2.Graph Theory          2
    // 3.Maths                 3
    // 4.Web Technology        4
    // 5.Electronics           5

    // 5 Classes
    // Class1,Class2,Class3,Class4,Class5

    printf("\n\t\t\t\t\t\t\tOur University has 10 students, 5 courses and 5 classes.\n\n");
    delay(1000);
    printf("\t\t\t\t\t\t\t\t               10 STUDENTS\n\t\t\t\t\t\t\t\t\tId No:1,2,3,4,5,6,7,8,9,10\n\n\t\t\t\t\t\t\t\t               5 COURSES\n");
delay(1000);
    printf("\t\t\t\t\t\t\t\t------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t    Course Name         Course Code     \n");
    printf("\t\t\t\t\t\t\t\t------------------------------------------\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  1. Data Structure           1\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  2. Graph Theory             2\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  3. Maths                    3\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  4. Web Technology           4\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  5. Electronics              5\n\n\n");delay(1000);

    printf("\t\t\t\t\t\t\t\t                5 CLASSES\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\t    Class no.            Class Code     \n");
    printf("\t\t\t\t\t\t\t\t------------------------------------------\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  1. Class 1                  3401\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  2. Class 2                  3402\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  3. Class 3                  3403\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  4. Class 4                  3404\n");delay(1000);
    printf("\t\t\t\t\t\t\t\t  5. Class 5                  3405\n\n\n");delay(1000);

    int i;
    int *Class1 = (int *)calloc(5, sizeof(int));
    int *Class2 = (int *)calloc(5, sizeof(int));
    int *Class3 = (int *)calloc(5, sizeof(int));
    int *Class4 = (int *)calloc(5, sizeof(int));
    int *Class5 = (int *)calloc(5, sizeof(int));
    int *TempArray = (int *)calloc(5, sizeof(int));

    for (i = 0; i < MAX; i++)
    {
        ZeroArray(TempArray);
        printf("\nEnter the Data Of Student With ID : %d ", i + 1); // change
        printf("\nEnter The Class code:\n");
        scanf("%d", &classCode);
        switch (classCode)
        {
        case 3401:
            printf("\nEnter the Number of Courses You want to opt between 1 to 5:\n");
            scanf("%d", &NumOfCourses);
            while (NumOfCourses > 5 || NumOfCourses <= 0)
            {
                printf("\nInvalid input, select a number between 1 to 5:\n");
                scanf("%d", &NumOfCourses);
            }
            printf("\nEnter the Course Code one by one:\n");
            Table[i] = Insert_End(Table[i], classCode);
            for (int j = 0; j < NumOfCourses; j++)
            {
                scanf("%d", &courseCode);
                while (courseCode > 5 || courseCode <= 0)
                {
                    printf("\nInvalid input, select a number between 1 to 5:\n");
                    scanf("%d", &courseCode);
                }
                while (TempArray[courseCode - 1] == 1 || courseCode > 5 || courseCode <= 0)
                {
                    if (TempArray[courseCode - 1] == 1)
                    {
                        printf("This course has already been selected by you, please select another course\n");
                        scanf("%d", &courseCode);
                    }

                    if (courseCode > 5 || courseCode <= 0)
                    {
                        printf("\nInvalid input, select a number between 1 to 5:\n");
                        scanf("%d", &courseCode);
                    }
                }
                TempArray[courseCode - 1] = 1;
                Class1[courseCode - 1] = 1;
                Table[i] = Insert_End(Table[i], courseCode);
            }
            break;

        case 3402:
            printf("\nEnter the Number of Courses You want to opt between 1 to 5:\n");
            scanf("%d", &NumOfCourses);
            while (NumOfCourses > 5 || NumOfCourses <= 0)
            {
                printf("\nInvalid input, select a number between 1 to 5:\n");
                scanf("%d", &NumOfCourses);
            }
            printf("\nEnter the Course Code one by one:\n");
            Table[i] = Insert_End(Table[i], classCode);
            for (int j = 0; j < NumOfCourses; j++)
            {
                scanf("%d", &courseCode);
                while (courseCode > 5 || courseCode <= 0)
                {
                    printf("\nInvalid input, select a number between 1 to 5:\n");
                    scanf("%d", &courseCode);
                }
                while (TempArray[courseCode - 1] == 1 || courseCode > 5 || courseCode <= 0)
                {
                    if (TempArray[courseCode - 1] == 1)
                    {
                        printf("This course has already been selected by you, please select another course\n");
                        scanf("%d", &courseCode);
                    }

                    if (courseCode > 5 || courseCode <= 0)
                    {
                        printf("\nInvalid input, select a number between 1 to 5:\n");
                        scanf("%d", &courseCode);
                    }
                }
                TempArray[courseCode - 1] = 1;//one course is not choose more then one
                Class2[courseCode - 1] = 1;//for uniqueness
                Table[i] = Insert_End(Table[i], courseCode);
            }
            break;

        case 3403:
            printf("\nEnter the Number of Courses You want to opt between 1 to 5:\n");
            scanf("%d", &NumOfCourses);
            while (NumOfCourses > 5 || NumOfCourses <= 0)
            {
                printf("\nInvalid input, select a number between 1 to 5:\n");
                scanf("%d", &NumOfCourses);
            }
            printf("\nEnter the Course Code one by one:\n");
            Table[i] = Insert_End(Table[i], classCode);
            for (int j = 0; j < NumOfCourses; j++)
            {
                scanf("%d", &courseCode);
                while (courseCode > 5 || courseCode <= 0)
                {
                    printf("\nInvalid input, select a number between 1 to 5:\n");
                    scanf("%d", &courseCode);
                }
                while (TempArray[courseCode - 1] == 1 || courseCode > 5 || courseCode <= 0)
                {
                    if (TempArray[courseCode - 1] == 1)
                    {
                        printf("This course has already been selected by you, please select another course\n");
                        scanf("%d", &courseCode);
                    }

                    if (courseCode > 5 || courseCode <= 0)
                    {
                        printf("\nInvalid input, select a number between 1 to 5:\n");
                        scanf("%d", &courseCode);
                    }
                }
                TempArray[courseCode - 1] = 1;
                Class3[courseCode - 1] = 1;
                Table[i] = Insert_End(Table[i], courseCode);
            }
            break;

        case 3404:
            printf("\nEnter the Number of Courses You want to Opt between 1 to 5:\n");
            scanf("%d", &NumOfCourses);
            while (NumOfCourses > 5 || NumOfCourses <= 0)
            {
                printf("\nInvalid input, select a number between 1 to 5:\n");
                scanf("%d", &NumOfCourses);
            }
            printf("\nEnter the Course Code one by one:\n");
            Table[i] = Insert_End(Table[i], classCode);
            for (int j = 0; j < NumOfCourses; j++)
            {
                scanf("%d", &courseCode);
                while (courseCode > 5 || courseCode <= 0)
                {
                    printf("\nInvalid input, select a number between 1 to 5:\n");
                    scanf("%d", &courseCode);
                }
                while (TempArray[courseCode - 1] == 1 || courseCode > 5 || courseCode <= 0)
                {
                    if (TempArray[courseCode - 1] == 1)
                    {
                        printf("This course has already been selected by you, please select another course\n");
                        scanf("%d", &courseCode);
                    }

                    if (courseCode > 5 || courseCode <= 0)
                    {
                        printf("\nInvalid input, select a number between 1 to 5:\n");
                        scanf("%d", &courseCode);
                    }
                }
                TempArray[courseCode - 1] = 1;
                Class4[courseCode - 1] = 1;
                Table[i] = Insert_End(Table[i], courseCode);
            }
            break;

        case 3405:
            printf("\nEnter the Number of Courses You want to Opt between 1 to 5:\n");
            scanf("%d", &NumOfCourses);
            while (NumOfCourses > 5 || NumOfCourses <= 0)
            {
                printf("\nInvalid input, select a number between 1 to 5:\n");
                scanf("%d", &NumOfCourses);
            }
            printf("\nEnter the Course Code one by one:\n");
            Table[i] = Insert_End(Table[i], classCode);
            for (int j = 0; j < NumOfCourses; j++)
            {
                scanf("%d", &courseCode);
                while (courseCode > 5 || courseCode <= 0)
                {
                    printf("\nInvalid input, select a number between 1 to 5:\n");
                    scanf("%d", &courseCode);
                }
                while (TempArray[courseCode - 1] == 1 || courseCode > 5 || courseCode <= 0)
                {
                    if (TempArray[courseCode - 1] == 1)
                    {
                        printf("This course has already been selected by you, please select another course\n");
                        scanf("%d", &courseCode);
                    }

                    if (courseCode > 5 || courseCode <= 0)
                    {
                        printf("\nInvalid input, select a number between 1 to 5:\n");
                        scanf("%d", &courseCode);
                    }
                }
                TempArray[courseCode - 1] = 1;
                Class5[courseCode - 1] = 1;
                Table[i] = Insert_End(Table[i], courseCode);
            }
            break;

        default:
            printf("Invalid class selection\n");
            i = i - 1;
            break;
        }
    }
    // change
    int reportNum;
    printf("\nChoose the report\n");
    while (1)
    {
        printf("\nFor report 1 press 1");
        printf("\nFor report 2 press 2");
        printf("\nFor Exit press 3\n");
        scanf("%d", &reportNum);
        switch (reportNum)
        {
        case 1:
            printf("\t\t\t\t\t\t\t\t\t       *** Report 1 ***\n\n");
            printf("\t\t\t\t\t\t\t\t  Total number of Registrations in Different Courses  \n\n");
            printf("\t\t\t\t\t\t\t\t --------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t\t  Classes               No. of Courses\n");
            printf("\t\t\t\t\t\t\t\t --------------------------------------------------\n");
            printf("\t\t\t\t\t\t\t\t\t  Class 1\t             %d \n", sum(Class1));
            printf("\t\t\t\t\t\t\t\t\t  Class 2\t             %d \n", sum(Class2));
            printf("\t\t\t\t\t\t\t\t\t  Class 3\t             %d \n", sum(Class3));
            printf("\t\t\t\t\t\t\t\t\t  Class 4\t             %d \n", sum(Class4));
            printf("\t\t\t\t\t\t\t\t\t  Class 5\t             %d \n", sum(Class5));
            break;
        case 2:
            printf("Report 2 \n");
            printf("This is the Report Of students \n");
            PrintStudent(Table, 0);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("!!! Invalid selection !!! /n");
            break;
        }
    }
}
