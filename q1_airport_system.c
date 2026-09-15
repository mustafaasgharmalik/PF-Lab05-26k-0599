#include <stdio.h>

int main() {
    int category, flightType, docsValid;
    int age, baggageWeight, allowance = 0;
    int rem;
    int isPriority = 0;

    printf("======================================\n");
    printf(" AIRPORT PASSENGER CLASSIFICATION SYSTEM\n");
    printf("======================================\n");

    printf("Select Passenger Category:\n");
    printf("1. Adult\n2. Student\n3. Senior Citizen\nChoice: ");
    scanf("%d", &category);

    printf("\nSelect Flight Type:\n");
    printf("1. Domestic\n2. International\nChoice: ");
    scanf("%d", &flightType);

    printf("\nEnter passenger age: ");
    scanf("%d", &age);

    printf("Enter baggage weight (kg): ");
    scanf("%d", &baggageWeight);

    printf("Are travel documents valid? (1 for Yes, 0 for No): ");
    scanf("%d", &docsValid);

    // Switch and nested switch for baggage allowance and priority status
    switch (category) {
        case 1: // Adult
            switch (flightType) {
                case 1: allowance = 20; break;
                case 2: allowance = 30; break;
                default: printf("Invalid flight type selected.\n"); return 1;
            }
            break;

        case 2: // Student
            switch (flightType) {
                case 1: allowance = 25; break;
                case 2: allowance = 35; isPriority = 1; break; // Student travelling int. gets priority
                default: printf("Invalid flight type selected.\n"); return 1;
            }
            break;

        case 3: // Senior Citizen
            switch (flightType) {
                case 1: allowance = 30; break;
                case 2: allowance = 40; break;
                default: printf("Invalid flight type selected.\n"); return 1;
            }
            isPriority = 1; // Senior citizens always get priority
            break;

        default:
            printf("Invalid category selected.\n");
            return 1;
    }

    // Verification category using modulus
    rem = age % 5;

    printf("\n--------------------------------------\n");
    printf("           SUMMARY REPORT             \n");
    printf("--------------------------------------\n");

    // Display basic passenger information
    switch (category) {
        case 1: printf("Passenger Category  : Adult\n"); break;
        case 2: printf("Passenger Category  : Student\n"); break;
        case 3: printf("Passenger Category  : Senior Citizen\n"); break;
    }

    switch (flightType) {
        case 1: printf("Flight Type         : Domestic\n"); break;
        case 2: printf("Flight Type         : International\n"); break;
    }

    printf("Allowed Baggage     : %d kg\n", allowance);
    printf("Actual Baggage      : %d kg\n", baggageWeight);
    printf("Document Status     : %s\n", docsValid ? "Valid" : "Invalid");

    // Display verification category using switch
    switch (rem) {
        case 0: printf("Verification Code   : Category A\n"); break;
        case 1: printf("Verification Code   : Category B\n"); break;
        case 2: printf("Verification Code   : Category C\n"); break;
        case 3: printf("Verification Code   : Category D\n"); break;
        case 4: printf("Verification Code   : Category E\n"); break;
    }

    // Priority assistance display using conditional operator
    printf("Priority Assistance : %s\n", isPriority ? "Yes (Qualified)" : "No");

    // Boarding Decision logic
    printf("Boarding Decision   : ");
    if (!docsValid) {
        printf("DENIED (Invalid Travel Documents)\n");
    } else if (baggageWeight > allowance) {
        printf("REFERRAL (Enhanced Baggage Screening Required)\n");
    } else {
        printf("APPROVED (Normal Boarding Allowed)\n");
    }
    printf("--------------------------------------\n");

    return 0;
}