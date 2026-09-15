#include <stdio.h>

int main()
{
    int category, destination;
    int age, weight;
    int documents;
    int allowance;
    int remainder;
    char verificationCategory;
    int priority;

    /* Passenger Category */
    printf("Select Passenger Category:\n");
    printf("1. Adult\n");
    printf("2. Student\n");
    printf("3. Senior Citizen\n");
    printf("Enter your choice: ");
    scanf("%d", &category);

    /* Destination Type */
    printf("\nSelect Destination Type:\n");
    printf("1. Domestic\n");
    printf("2. International\n");
    printf("Enter your choice: ");
    scanf("%d", &destination);

    /* Age and baggage */
    printf("\nEnter passenger age: ");
    scanf("%d", &age);

    printf("Enter actual baggage weight (kg): ");
    scanf("%d", &weight);

    /* Document Status */
    printf("\nAre the travel documents valid?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &documents);

    /*
       Main switch determines passenger category.
       Nested switch determines destination type.
    */

    switch(category)
    {
        case 1:
            printf("\nPassenger Category: Adult\n");

            switch(destination)
            {
                case 1:
                    printf("Destination Type: Domestic\n");
                    allowance = 20;
                    break;

                case 2:
                    printf("Destination Type: International\n");
                    allowance = 30;
                    break;

                default:
                    printf("Invalid destination type.\n");
                    return 0;
            }

            break;

        case 2:
            printf("\nPassenger Category: Student\n");

            switch(destination)
            {
                case 1:
                    printf("Destination Type: Domestic\n");
                    allowance = 25;
                    break;

                case 2:
                    printf("Destination Type: International\n");
                    allowance = 35;
                    break;

                default:
                    printf("Invalid destination type.\n");
                    return 0;
            }

            break;

        case 3:
            printf("\nPassenger Category: Senior Citizen\n");

            switch(destination)
            {
                case 1:
                    printf("Destination Type: Domestic\n");
                    allowance = 30;
                    break;

                case 2:
                    printf("Destination Type: International\n");
                    allowance = 40;
                    break;

                default:
                    printf("Invalid destination type.\n");
                    return 0;
            }

            break;

        default:
            printf("Invalid passenger category.\n");
            return 0;
    }

    /* Verification Category using modulus operator */
    remainder = age % 5;

    switch(remainder)
    {
        case 0:
            verificationCategory = 'A';
            break;

        case 1:
            verificationCategory = 'B';
            break;

        case 2:
            verificationCategory = 'C';
            break;

        case 3:
            verificationCategory = 'D';
            break;

        case 4:
            verificationCategory = 'E';
            break;
    }

    /* Priority Assistance */
    priority = (category == 3 || (category == 2 && destination == 2));

    /* Final Output */
    printf("\n========== PASSENGER VERIFICATION ==========\n");

    printf("Permitted Baggage Allowance: %d kg\n", allowance);
    printf("Actual Baggage Weight: %d kg\n", weight);

    if(documents == 1)
    {
        printf("Document Status: Valid\n");
    }
    else if(documents == 2)
    {
        printf("Document Status: Invalid\n");
    }
    else
    {
        printf("Invalid document choice.\n");
        return 0;
    }

    printf("Verification Category: Category %c\n", verificationCategory);

    printf("Priority Assistance: %s\n",
           priority ? "Available" : "Not Available");

    /*
       Final Boarding Decision

       Documents invalid -> Denied
       Documents valid + baggage within allowance -> Normal Boarding
       Documents valid + baggage exceeds allowance -> Enhanced Screening
    */

    if(documents == 2)
    {
        printf("Final Boarding Decision: DENIED BOARDING\n");
    }
    else if(documents == 1 && weight <= allowance)
    {
        printf("Final Boarding Decision: NORMAL BOARDING\n");
    }
    else if(documents == 1 && weight > allowance)
    {
        printf("Final Boarding Decision: ENHANCED BAGGAGE SCREENING\n");
    }

    printf("=============================================\n");

    return 0;
}