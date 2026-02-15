#include <stdio.h>
#include <string.h>

#define MAX 100

struct User
{
    char name[50];
    char teach[50];
    char learn[50];
    char language[30];
    char level[20];

    int totalRating;
    int ratingCount;
    int courses;

    int premium;
    int teachBack;
};

struct User users[MAX];
int totalUsers = 0;

void addDemoUsers()
{
    totalUsers = 2;

    strcpy(users[0].name, "Aarav");
    strcpy(users[0].teach, "C Programming");
    strcpy(users[0].learn, "Data Structures");
    strcpy(users[0].language, "English");
    strcpy(users[0].level, "Expert");
    users[0].totalRating = 20;
    users[0].ratingCount = 4;
    users[0].courses = 5;
    users[0].premium = 1;
    users[0].teachBack = 0;

    strcpy(users[1].name, "Priya");
    strcpy(users[1].teach, "None");
    strcpy(users[1].learn, "Python");
    strcpy(users[1].language, "Hindi");
    strcpy(users[1].level, "Beginner");
    users[1].totalRating = 0;
    users[1].ratingCount = 0;
    users[1].courses = 0;
    users[1].premium = 0;
    users[1].teachBack = 1;
}

void registerUser()
{
    if(totalUsers >= MAX)
    {
        printf("Platform Full\n");
        return;
    }

    struct User u;

    printf("Enter Name: ");
    scanf(" %[^\n]", u.name);

    printf("Skill you can teach (write None if nothing): ");
    scanf(" %[^\n]", u.teach);

    printf("Skill you want to learn: ");
    scanf(" %[^\n]", u.learn);

    printf("Language: ");
    scanf(" %[^\n]", u.language);

    printf("Level: ");
    scanf(" %[^\n]", u.level);

    printf("Premium? (1 Yes / 0 No): ");
    scanf("%d", &u.premium);

    u.totalRating = 0;
    u.ratingCount = 0;
    u.courses = 0;

    if(strcmp(u.teach, "None") == 0)
        u.teachBack = 1;
    else
        u.teachBack = 0;

    users[totalUsers] = u;
    totalUsers++;

    printf("User Registered Successfully\n");
}

void viewUsers()
{
    if(totalUsers == 0)
    {
        printf("No Users\n");
        return;
    }

    for(int i=0; i<totalUsers; i++)
    {
        printf("\nUser %d\n", i+1);
        printf("Name: %s\n", users[i].name);
        printf("Teaches: %s\n", users[i].teach);
        printf("Wants to Learn: %s\n", users[i].learn);
        printf("Level: %s\n", users[i].level);

        if(users[i].ratingCount > 0)
        {
            float avg = (float)users[i].totalRating / users[i].ratingCount;
            printf("Rating: %.2f\n", avg);
        }
        else
        {
            printf("No Ratings Yet\n");
        }

        printf("Courses Completed: %d\n", users[i].courses);

        if(users[i].premium == 1)
            printf("Premium Member\n");

        if(users[i].teachBack == 1)
            printf("Must Teach After Learning\n");
    }
}

void rateUser()
{
    int num, rate;

    printf("Enter User Number: ");
    scanf("%d", &num);

    if(num <= 0 || num > totalUsers)
    {
        printf("Invalid Number\n");
        return;
    }

    printf("Give Rating (1 to 5): ");
    scanf("%d", &rate);

    if(rate < 1 || rate > 5)
    {
        printf("Invalid Rating\n");
        return;
    }

    users[num-1].totalRating += rate;
    users[num-1].ratingCount++;

    printf("Rating Added\n");
}

void analytics()
{
    int premiumCount = 0;

    for(int i=0; i<totalUsers; i++)
    {
        if(users[i].premium == 1)
            premiumCount++;
    }

    printf("\nTotal Users: %d\n", totalUsers);
    printf("Premium Users: %d\n", premiumCount);
}

int main()
{
    addDemoUsers();

    int choice;

    do
    {
        printf("\n---- EduSkill Platform ----\n");
        printf("1. Register\n");
        printf("2. View Users\n");
        printf("3. Rate User\n");
        printf("4. Analytics\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            registerUser();
        else if(choice == 2)
            viewUsers();
        else if(choice == 3)
            rateUser();
        else if(choice == 4)
            analytics();
        else if(choice == 5)
            printf("Exiting...\n");
        else
            printf("Wrong Choice\n");

    } while(choice != 5);

    return 0;
}
