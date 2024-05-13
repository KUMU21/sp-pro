#include <stdio.h>

// Function prototypes
void displayMenu();
void takeOrder();
float calculateBill(int quantity, float price);
void generateReceipt(float totalBill);

// Global variables for menu items
float menuPrices[] = {400, 300, 275}; // Prices of menu items
char *menuItems[] = {"Coffee", "Sandwich", "Cookie"}; // Names of menu items

int main() {
    int choice;

    do {
        printf("\nCafeteria Management System\n");
        printf("1. Display Menu\n");
        printf("2. Take Order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                takeOrder();
           break;
            case 3:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\nMenu:\n");
    for(int i = 0; i < 3; i++) {
        printf("%d. %s - %.2f\n", i+1, menuItems[i], menuPrices[i]);
    }
}

// Function to take order
void takeOrder() {
    int choice, quantity;
    float totalBill = 0.0;

    do {
        displayMenu();
        printf("Enter item number to order (0 to exit): ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 3) {
            printf("Enter quantity: ");
  scanf("%d", &quantity);
            totalBill += calculateBill(quantity, menuPrices[choice-1]);
        } else if(choice != 0) {
            printf("Invalid item number. Please try again.\n");
        }
    } while(choice != 0);

    generateReceipt(totalBill);
}

// Function to calculate total bill
float calculateBill(int quantity, float price) {
    return quantity * price;
}

// Function to generate receipt
void generateReceipt(float totalBill) {
    printf("\nReceipt:\n");
    printf("Total Bill: %.2f\n", totalBill);
    printf("Thank you for your order!\n");
}
