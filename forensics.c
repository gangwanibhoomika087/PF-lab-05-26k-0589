#include <stdio.h>

int main()
{
    int category;
    int encryption;
    int sensitive;
    int priority;
    int size;

    printf("========================================\n");
    printf("   DIGITAL FORENSICS EVIDENCE SYSTEM\n");
    printf("========================================\n");

    // Select evidence category
    printf("\nSelect Evidence Category:\n");
    printf("1. Mobile Device\n");
    printf("2. Computer System\n");
    printf("3. Network Capture\n");
    printf("4. Cloud Account\n");
    printf("Enter your choice: ");
    scanf("%d", &category);

    if (category < 1 || category > 4)
    {
        printf("Invalid evidence category!\n");
        return 0;
    }

    // Evidence size
    printf("\nEnter evidence size in GB: ");
    scanf("%d", &size);

    if (size < 0)
    {
        printf("Invalid evidence size!\n");
        return 0;
    }

    // Encryption status
    printf("\nIs encryption detected?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter choice: ");
    scanf("%d", &encryption);

    if (encryption != 1 && encryption != 2)
    {
        printf("Invalid encryption choice!\n");
        return 0;
    }

    // Sensitive information
    printf("\nDoes the evidence contain sensitive information?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter choice: ");
    scanf("%d", &sensitive);

    if (sensitive != 1 && sensitive != 2)
    {
        printf("Invalid choice!\n");
        return 0;
    }

    // Investigation priority
    printf("\nSelect Investigation Priority:\n");
    printf("1. Low\n");
    printf("2. Medium\n");
    printf("3. High\n");
    printf("Enter choice: ");
    scanf("%d", &priority);

    if (priority < 1 || priority > 3)
    {
        printf("Invalid priority!\n");
        return 0;
    }

    printf("\n========================================\n");
    printf("       FORENSIC ANALYSIS RESULT\n");
    printf("========================================\n");

    // Main switch
    switch (category)
    {
        case 1:
            printf("Evidence Category: Mobile Device\n");

            // Nested switch
            switch (encryption)
            {
                case 1:
                    printf("Encryption: Detected\n");
                    printf("Decision: Specialized extraction is required.\n");
                    break;

                case 2:
                    printf("Encryption: Not Detected\n");
                    printf("Decision: Standard extraction can be performed.\n");
                    break;
            }
            break;


        case 2:
            printf("Evidence Category: Computer System\n");

            // Nested switch
            switch (encryption)
            {
                case 1:
                    printf("Encryption: Detected\n");

                    // Logical AND
                    if (size > 500 && encryption == 1)
                    {
                        priority = 3;
                        printf("Storage exceeds 500 GB and encryption is enabled.\n");
                        printf("Priority has been changed to HIGH.\n");
                    }
                    else
                    {
                        printf("High-priority condition not met.\n");
                    }
                    break;

                case 2:
                    printf("Encryption: Not Detected\n");
                    break;
            }
            break;


        case 3:
            printf("Evidence Category: Network Capture\n");

            /*
               Modulus operator:
               If packet size is divisible by 2000,
               remainder will be 0.
            */
            if (size % 2000 == 0)
            {
                printf("Classification: Structured Capture\n");
            }
            else
            {
                printf("Classification: Irregular Traffic Data\n");
            }
            break;


        case 4:
            printf("Evidence Category: Cloud Account\n");

            // Logical AND
            if (sensitive == 1 && encryption == 1)
            {
                printf("Sensitive information and encryption detected.\n");
                printf("Decision: Legal authorization verification required.\n");
            }
            else
            {
                printf("Legal authorization verification is not required.\n");
            }
            break;
    }

    // Conditional operator
    printf("\nInvestigation Priority: %s\n",
           (priority == 3) ? "HIGH" :
           (priority == 2) ? "MEDIUM" : "LOW");

    // Assignment operator
    priority += 0;

    printf("Evidence Size: %d GB\n", size);

    printf("\n========================================\n");
    printf("        END OF FORENSIC ANALYSIS\n");
    printf("========================================\n");

    return 0;
}
