#include <stdio.h>

int main() {
    int subsystem, severity;
    int mileage, warranty;
    int serviceCode;

    printf("========================================\n");
    printf("   VEHICLE DIAGNOSTIC TERMINAL\n");
    printf("========================================\n");

    // Select vehicle subsystem
    printf("\nSelect Vehicle Subsystem:\n");
    printf("1. Engine\n");
    printf("2. Transmission\n");
    printf("3. Braking System\n");
    printf("4. Electrical System\n");
    printf("Enter your choice: ");
    scanf("%d", &subsystem);

    // Input validation
    if (subsystem < 1 || subsystem > 4) {
        printf("Invalid subsystem choice!\n");
        return 0;
    }

    // Select severity
    printf("\nSelect Diagnostic Severity:\n");
    printf("1. Minor\n");
    printf("2. Moderate\n");
    printf("3. Critical\n");
    printf("Enter your choice: ");
    scanf("%d", &severity);

    if (severity < 1 || severity > 3) {
        printf("Invalid severity choice!\n");
        return 0;
    }

    // Enter mileage
    printf("\nEnter vehicle mileage (km): ");
    scanf("%d", &mileage);

    if (mileage < 0) {
        printf("Invalid mileage!\n");
        return 0;
    }

    // Warranty status
    printf("\nIs the vehicle under warranty?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter choice: ");
    scanf("%d", &warranty);

    if (warranty != 1 && warranty != 2) {
        printf("Invalid warranty choice!\n");
        return 0;
    }

    printf("\n========================================\n");
    printf("          DIAGNOSTIC RESULT\n");
    printf("========================================\n");

    // Nested switch
    switch (subsystem) {

        case 1:
            printf("Subsystem: Engine\n");

            switch (severity) {
                case 1:
                    printf("Severity: Minor\n");
                    printf("Decision: Inspection required.\n");
                    break;

                case 2:
                    printf("Severity: Moderate\n");
                    printf("Decision: Maintenance required.\n");
                    break;

                case 3:
                    printf("Severity: Critical\n");
                    printf("Decision: IMMEDIATE SHUTDOWN required.\n");
                    break;
            }
            break;


        case 2:
            printf("Subsystem: Transmission\n");

            switch (severity) {
                case 1:
                    printf("Severity: Minor\n");
                    printf("Decision: Issue may be monitored.\n");
                    break;

                case 2:
                    printf("Severity: Moderate\n");
                    printf("Decision: Service required within 24 hours.\n");
                    break;

                case 3:
                    printf("Severity: Critical\n");
                    printf("Decision: Vehicle requires towing.\n");
                    break;
            }
            break;


        case 3:
            printf("Subsystem: Braking System\n");

            switch (severity) {
                case 1:
                    printf("Severity: Minor\n");
                    printf("Decision: Immediate inspection required.\n");
                    break;

                case 2:
                    printf("Severity: Moderate\n");
                    printf("Decision: Long-distance driving is prohibited.\n");
                    break;

                case 3:
                    printf("Severity: Critical\n");
                    printf("Decision: Vehicle operation is prohibited.\n");
                    break;
            }
            break;


        case 4:
            printf("Subsystem: Electrical System\n");

            switch (severity) {
                case 1:
                    printf("Severity: Minor\n");
                    printf("Decision: Issue may be ignored temporarily.\n");
                    break;

                case 2:
                    printf("Severity: Moderate\n");
                    printf("Decision: Battery diagnostics required.\n");
                    break;

                case 3:
                    printf("Severity: Critical\n");
                    printf("Decision: Complete electrical isolation required.\n");
                    break;
            }
            break;
    }


    // HIGH PRIORITY using logical OR
    if (severity == 3 || mileage > 200000) {
        printf("\n*** HIGH PRIORITY ***\n");
    }

    // Maintenance priority using logical AND
    if (mileage > 200000 && severity >= 2) {
        printf("Maintenance priority increased.\n");
    }

    // Warranty check using logical AND
    if (warranty == 1 && severity != 3) {
        printf("This service may be FREE under warranty.\n");
    } else if (warranty == 1 && severity == 3) {
        printf("Critical services may require warranty verification.\n");
    } else {
        printf("Service charges may apply.\n");
    }

    // Conditional operator
    printf("\nPriority Level: %s\n",
           (severity == 3 || mileage > 200000) ? "HIGH" : "NORMAL");

    // Modulus operator for service code generation
    serviceCode = (mileage % 1000) + (severity * 10) + subsystem;

    printf("Generated Service Code: %d\n", serviceCode);

    printf("\n========================================\n");
    printf("        END OF DIAGNOSTIC\n");
    printf("========================================\n");

    return 0;
}
