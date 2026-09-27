/*
 * Course: CL1002 - Programming Fundamentals
 * Lab 05 Home Tasks - Question 3: E-Commerce Order Processing System
 * Description: Processes customer orders, applies category-specific discounts,
 *              evaluates free shipping and priority handling conditions,
 *              and classifies orders into processing groups using modulus.
 *              Uses switch, nested switch, logical operators (&&, ||),
 *              conditional operators (?:), and modulus (%), without loops.
 */

#include <stdio.h>

int main(void) {
    int productChoice = 0;
    int customerChoice = 0;
    int orderNumber = 0;
    double orderAmount = 0.0;
    double deliveryDistance = 0.0;

    double discountPercent = 0.0;
    const char *productName = "";
    const char *customerCategoryName = "";

    printf("===================================================\n");
    printf("         E-COMMERCE ORDER PROCESSING SYSTEM        \n");
    printf("===================================================\n");

    printf("Enter Order Number: ");
    if (scanf("%d", &orderNumber) != 1) {
        printf("Error: Invalid order number.\n");
        return 1;
    }

    printf("\nSelect Product Category:\n");
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Books\n");
    printf("4. Household\n");
    printf("Enter choice (1-4): ");
    if (scanf("%d", &productChoice) != 1) {
        printf("Error: Invalid choice.\n");
        return 1;
    }

    printf("\nSelect Customer Category:\n");
    printf("1. Regular\n");
    printf("2. Premium\n");
    printf("3. Corporate\n");
    printf("Enter choice (1-3): ");
    if (scanf("%d", &customerChoice) != 1) {
        printf("Error: Invalid choice.\n");
        return 1;
    }

    printf("\nEnter Total Order Amount (PKR): ");
    if (scanf("%lf", &orderAmount) != 1 || orderAmount < 0) {
        printf("Error: Invalid order amount.\n");
        return 1;
    }

    printf("Enter Delivery Distance (km): ");
    if (scanf("%lf", &deliveryDistance) != 1 || deliveryDistance < 0) {
        printf("Error: Invalid distance.\n");
        return 1;
    }

    // Outer switch for Product Category and Nested switch for Customer Category discount
    switch (productChoice) {
        case 1:
            productName = "Electronics";
            switch (customerChoice) {
                case 1:
                    customerCategoryName = "Regular";
                    discountPercent = 5.0;
                    break;
                case 2:
                    customerCategoryName = "Premium";
                    discountPercent = 10.0;
                    break;
                case 3:
                    customerCategoryName = "Corporate";
                    discountPercent = 15.0;
                    break;
                default:
                    printf("Error: Invalid customer category.\n");
                    return 1;
            }
            break;

        case 2:
            productName = "Clothing";
            switch (customerChoice) {
                case 1:
                    customerCategoryName = "Regular";
                    discountPercent = 10.0;
                    break;
                case 2:
                    customerCategoryName = "Premium";
                    discountPercent = 15.0;
                    break;
                case 3:
                    customerCategoryName = "Corporate";
                    discountPercent = 20.0;
                    break;
                default:
                    printf("Error: Invalid customer category.\n");
                    return 1;
            }
            break;

        case 3:
            productName = "Books";
            switch (customerChoice) {
                case 1:
                    customerCategoryName = "Regular";
                    discountPercent = 8.0;
                    break;
                case 2:
                    customerCategoryName = "Premium";
                    discountPercent = 12.0;
                    break;
                case 3:
                    customerCategoryName = "Corporate";
                    discountPercent = 18.0;
                    break;
                default:
                    printf("Error: Invalid customer category.\n");
                    return 1;
            }
            break;

        case 4:
            productName = "Household";
            switch (customerChoice) {
                case 1:
                    customerCategoryName = "Regular";
                    discountPercent = 7.0;
                    break;
                case 2:
                    customerCategoryName = "Premium";
                    discountPercent = 14.0;
                    break;
                case 3:
                    customerCategoryName = "Corporate";
                    discountPercent = 20.0;
                    break;
                default:
                    printf("Error: Invalid customer category.\n");
                    return 1;
            }
            break;

        default:
            printf("Error: Invalid product category selected.\n");
            return 1;
    }

    // Calculate discount amount and net order payable amount
    double discountAmount = orderAmount * (discountPercent / 100.0);
    double finalPayableAmount = orderAmount - discountAmount;

    // Free shipping qualification evaluated using logical operators:
    // Net order >= Rs. 5000 OR customer is Premium (2) or Corporate (3)
    int isFreeShipping = (finalPayableAmount >= 5000.0) ||
                         (customerChoice == 2 || customerChoice == 3);

    // Delivery charge calculation based on distance (standard rate of Rs. 25/km if not free)
    double deliveryCharge = isFreeShipping ? 0.0 : (deliveryDistance * 25.0);

    // Priority delivery qualification evaluated using logical operators:
    // Customer is Premium or Corporate AND order amount before discount >= Rs. 10,000
    int isPriority = (customerChoice == 2 || customerChoice == 3) &&
                     (orderAmount >= 10000.0);

    // Priority delivery charge using conditional operator
    double priorityCharge = isPriority ? 500.0 : 0.0;

    // Order classification into processing group using modulus operator (% 4)
    int groupRemainder = orderNumber % 4;
    char processingGroup = ' ';
    switch (groupRemainder) {
        case 0:
            processingGroup = 'A';
            break;
        case 1:
            processingGroup = 'B';
            break;
        case 2:
            processingGroup = 'C';
            break;
        case 3:
            processingGroup = 'D';
            break;
        default:
            processingGroup = 'A';
            break;
    }

    // Final total amount payable calculation
    double totalPayable = finalPayableAmount + deliveryCharge + priorityCharge;

    // Display final comprehensive invoice / order summary
    printf("\n===================================================\n");
    printf("               ORDER SUMMARY & INVOICE             \n");
    printf("===================================================\n");
    printf("Order Number             : #%d\n", orderNumber);
    printf("Processing Group         : Group %c\n", processingGroup);
    printf("Selected Product Category: %s\n", productName);
    printf("Customer Category        : %s\n", customerCategoryName);
    printf("Original Order Amount    : Rs. %.2f\n", orderAmount);
    printf("Discount Percentage      : %.2f%%\n", discountPercent);
    printf("Discount Amount          : Rs. %.2f\n", discountAmount);
    printf("Final Payable Amount     : Rs. %.2f (after discount)\n", finalPayableAmount);
    printf("---------------------------------------------------\n");
    printf("Delivery Distance        : %.2f km\n", deliveryDistance);
    printf("Shipping Status          : %s\n",
           isFreeShipping ? "Free Shipping" : "Standard Paid Shipping");
    printf("Delivery Charges         : Rs. %.2f\n", deliveryCharge);
    printf("Priority Delivery Status : %s\n",
           isPriority ? "Priority Delivery Qualified" : "Normal Delivery");
    printf("Priority Charges         : Rs. %.2f\n", priorityCharge);
    printf("---------------------------------------------------\n");
    printf("TOTAL AMOUNT PAYABLE     : Rs. %.2f\n", totalPayable);
    printf("===================================================\n");

    return 0;
}
