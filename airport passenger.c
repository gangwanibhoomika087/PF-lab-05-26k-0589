#include <stdio.h>

int main(void)
{
    int category, destination;
    int age, documents;
    float baggage, allowance;
    int remainder;
    char *categoryName;
    char *destinationName;
    char *documentStatus;
    char *verificationCategory;
    char *priorityStatus;
    char *boardingDecision;

    /* Input passenger category */
    printf("=== Airport Passenger Classification System ===\n\n");

    printf("Select Passenger Category:\n");
    printf("1. Adult\n");
    printf("2. Student\n");
    printf("3. Senior Citizen\n");
    printf("Enter your choice: ");
    scanf("%d", &category);

    /* Input destination type */
    printf("\nSelect Destination Type:\n");
    printf("1. Domestic\n");
    printf("2. International\n");
    printf("Enter your choice: ");
    scanf("%d", &destination);

    /* Input age and baggage */
    printf("\nEnter passenger age: ");
    scanf("%d", &age);

    printf("Enter actual baggage weight (kg): ");
    scanf("%f", &baggage);

    /* Input document status */
    printf("\nAre the travel documents valid?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &documents);

    /* Determine passenger category and baggage allowance */
    switch (category)
    {
        case 1:
            categoryName = "Adult";

            /* Nested switch for destination */
            switch (destination)
            {
                case 1:
                    allowance = 20.0;
                    destinationName = "Domestic";
                    break;

                case 2:
                    allowance = 30.0;
                    destinationName = "International";
                    break;

                default:
                    printf("\nInvalid destination type.\n");
                    return 1;
            }
            break;

        case 2:
            categoryName = "Student";

            /* Nested switch for destination */
            switch (destination)
            {
                case 1:
                    allowance = 25.0;
                    destinationName = "Domestic";
                    break;

                case 2:
                    allowance = 35.0;
                    destinationName = "International";
                    break;

                default:
                    printf("\nInvalid destination type.\n");
                    return 1;
            }
            break;

        case 3:
            categoryName = "Senior Citizen";

            /* Nested switch for destination */
            switch (destination)
            {
                case 1:
                    allowance = 30.0;
                    destinationName = "Domestic";
                    break;

                case 2:
                    allowance = 40.0;
                    destinationName = "International";
                    break;

                default:
                    printf("\nInvalid destination type.\n");
                    return 1;
            }
            break;

        default:
            printf("\nInvalid passenger category.\n");
            return 1;
    }

    /* Determine document status */
    documentStatus = (documents == 1) ? "Valid" : "Invalid";

    /* Calculate verification category using modulus operator */
    remainder = age % 5;

    switch (remainder)
    {
        case 0:
            verificationCategory = "Category A";
            break;

        case 1:
            verificationCategory = "Category B";
            break;

        case 2:
            verificationCategory = "Category C";
            break;

        case 3:
            verificationCategory = "Category D";
            break;

        case 4:
            verificationCategory = "Category E";
            break;

        default:
            verificationCategory = "Unknown";
    }

    /* Determine priority assistance using logical operator */
    if (category == 3 || (category == 2 && destination == 2))
    {
        priorityStatus = "Available";
    }
    else
    {
        priorityStatus = "Not Available";
    }

    /* Determine final boarding decision */
    if (documents != 1)
    {
        boardingDecision = "Denied Boarding";
    }
    else if (baggage <= allowance && documents == 1)
    {
        boardingDecision = "Normal Boarding";
    }
    else if (baggage > allowance && documents == 1)
    {
        boardingDecision = "Enhanced Baggage Screening";
    }
    else
    {
        boardingDecision = "Denied Boarding";
    }

    /* Display final results */
    printf("\n============================================\n");
    printf("       PASSENGER VERIFICATION RESULT\n");
    printf("============================================\n");

    printf("Passenger Category       : %s\n", categoryName);
    printf("Destination Type         : %s\n", destinationName);
    printf("Permitted Baggage        : %.2f kg\n", allowance);
    printf("Actual Baggage Weight    : %.2f kg\n", baggage);
    printf("Travel Documents         : %s\n", documentStatus);
    printf("Verification Category    : %s\n", verificationCategory);
    printf("Priority Assistance      : %s\n", priorityStatus);
    printf("Final Boarding Decision  : %s\n", boardingDecision);

    printf("============================================\n");

    return 0;
}

