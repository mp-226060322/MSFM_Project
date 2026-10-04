#include <stdio.h>
#include <string.h>

void displayMenu();

void employeeManagement();
void addEmployee();
void displayEmployees();
void searchEmployee();

void assetManagement();
void addAsset();
void displayAssets();
void searchAsset();

void budgetManagement();

void supplierManagement();

void reports();


int main(){

  int choice;
  
  do{
    displayMenu();

    printf("Enter your choice:");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Employee Management\n");
            employeeManagement();
            break;

        case 2:
            printf("Budget Management\n");
            budgetManagement();
            break;

        case 3:
            printf("Supplier Management\n");
            supplierManagement();
            break;

        case 4:
            printf("Asset Management\n");
            assetManagement();
            break;

        case 5:
            printf("Reports\n");
            reports();
            break;

        case 6:
            printf("Exiting system...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
  } while(choice != 6);
  return 0;
}

void displayMenu()
{
printf("\n================================================\n");
printf("       MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
printf("==================================================\n");
printf("1. Employee Management\n");
printf("2. Budget Management\n");
printf("3. Supplier Management\n");
printf("4. Asset Management\n");
printf("5. Reports\n");
printf("6. Exit\n");
printf("==================================================\n");
}