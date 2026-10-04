#include <stdio.h>
#include <string.h>

#define MAX_BUDGETS 50

struct Budget
{
    char department[50];
    double allocated;
    double spent;
};

struct Budget budgets[MAX_BUDGETS];
int budgetCount = 0;

void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("\nBudget list is full.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             ADD BUDGET\n");
    printf("========================================\n");

    getchar();

    printf("Enter Department: ");
    fgets(budgets[budgetCount].department,
          sizeof(budgets[budgetCount].department), stdin);

    budgets[budgetCount].department[
        strcspn(budgets[budgetCount].department, "\n")] = '\0';

    printf("Enter Allocated Budget: N$");
    scanf("%lf", &budgets[budgetCount].allocated);

    printf("Enter Expenditure: N$");
    scanf("%lf", &budgets[budgetCount].spent);

    budgetCount++;

    printf("\nBudget added successfully!\n");
}

void displayBudgets(void)
{
    int i;

    if (budgetCount == 0)
    {
        printf("\nNo budgets registered.\n");
        return;
    }

    printf("\n========================================\n");
    printf("             BUDGET LIST\n");
    printf("========================================\n");

    for (i = 0; i < budgetCount; i++)
    {
        double remaining;

        remaining = budgets[i].allocated - budgets[i].spent;

        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: N$%.2f\n", budgets[i].allocated);
        printf("Expenditure: N$%.2f\n", budgets[i].spent);
        printf("Remaining Budget: N$%.2f\n", remaining);

        if (remaining < 0)
        {
            printf("Status: OVER BUDGET\n");
        }
        else
        {
            printf("Status: Within Budget\n");
        }
    }
}

void searchBudget(void)
{
    char department[50];
    int i;
    int found = 0;

    printf("\n========================================\n");
    printf("             SEARCH BUDGET\n");
    printf("========================================\n");

    getchar();

    printf("Enter Department: ");
    fgets(department, sizeof(department), stdin);
    department[strcspn(department, "\n")] = '\0';

    for (i = 0; i < budgetCount; i++)
    {
        if (strcmp(budgets[i].department, department) == 0)
        {
            double remaining;

            remaining = budgets[i].allocated - budgets[i].spent;

            printf("\nBudget Found!\n");
            printf("----------------------------------------\n");
            printf("Department:        %s\n", budgets[i].department);
            printf("Allocated Budget:  N$%.2f\n", budgets[i].allocated);
            printf("Expenditure:       N$%.2f\n", budgets[i].spent);
            printf("Remaining Budget:  N$%.2f\n", remaining);

            if (remaining < 0)
            {
                printf("Status: OVER BUDGET\n");
            }
            else
            {
                printf("Status: Within Budget\n");
            }

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBudget for that department was not found.\n");
    }
}

void budgetManagement(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("          BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Budget\n");
        printf("2. View Budgets\n");
        printf("3. Search Budget\n");
        printf("4. Back to Main Menu\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                displayBudgets();
                break;

            case 3:
                searchBudget();
                break;

            case 4:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);
}
