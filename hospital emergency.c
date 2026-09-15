#include <stdio.h>

int main(void)
{
    int department;
    int age, heartRate, consciousness, severity;
    float temperature;

    int critical;
    int seniorStatus;
    int temperatureAlert;
    int departmentPriority;

    int caseRemainder;

    char *departmentName;
    char *consciousnessStatus;
    char *severityStatus;
    char *departmentPriorityStatus;
    char *criticalStatus;
    char *seniorStatusText;
    char *temperatureAlertStatus;
    char *caseCategory;
    char *finalDecision;

    /* Display department options */
    printf("============================================\n");
    printf("       HOSPITAL EMERGENCY TRIAGE SYSTEM\n");
    printf("============================================\n\n");

    printf("Select Emergency Department:\n");
    printf("1. General Emergency\n");
    printf("2. Cardiology\n");
    printf("3. Neurology\n");
    printf("4. Trauma\n");
    printf("Enter department choice: ");
    scanf("%d", &department);

    /* Validate and assign department name */
    switch (department)
    {
        case 1:
            departmentName = "General Emergency";
            break;

        case 2:
            departmentName = "Cardiology";
            break;

        case 3:
            departmentName = "Neurology";
            break;

        case 4:
            departmentName = "Trauma";
            break;

        default:
            printf("\nInvalid department selection.\n");
            return 1;
    }

    /* Collect patient information */
    printf("\nEnter patient age: ");
    scanf("%d", &age);

    printf("Enter heart rate (beats per minute): ");
    scanf("%d", &heartRate);

    printf("Enter body temperature (Celsius): ");
    scanf("%f", &temperature);

    printf("\nLevel of Consciousness:\n");
    printf("1. Conscious\n");
    printf("2. Unconscious\n");
    printf("Enter choice: ");
    scanf("%d", &consciousness);

    printf("\nSeverity Level:\n");
    printf("1. Low\n");
    printf("2. Medium\n");
    printf("3. High\n");
    printf("Enter severity level: ");
    scanf("%d", &severity);

    /* Convert consciousness into text */
    consciousnessStatus = (consciousness == 1) ? "Conscious" : "Unconscious";

    /* Convert severity into text */
    switch (severity)
    {
        case 1:
            severityStatus = "Low";
            break;

        case 2:
            severityStatus = "Medium";
            break;

        case 3:
            severityStatus = "High";
            break;

        default:
            severityStatus = "Invalid";
    }

    /*
       Department-specific priority
       Uses a switch with a nested switch.
    */
    departmentPriority = 0;

    switch (department)
    {
        case 1:
            /*
               Nested switch for General Emergency.
               High severity requires department-specific priority.
            */
            switch (severity)
            {
                case 3:
                    departmentPriority = 1;
                    break;

                case 1:
                case 2:
                    departmentPriority = 0;
                    break;

                default:
                    departmentPriority = 0;
            }
            break;

        case 2:
            /*
               Nested switch for Cardiology.
               Abnormally high or low heart rate requires
               immediate cardiac attention.
            */
            switch (severity)
            {
                case 1:
                case 2:
                case 3:
                    if (heartRate < 50 || heartRate > 120)
                    {
                        departmentPriority = 1;
                    }
                    break;

                default:
                    departmentPriority = 0;
            }
            break;

        case 3:
            /*
               Nested switch for Neurology.
               An unconscious patient requires urgent attention.
            */
            switch (consciousness)
            {
                case 1:
                    departmentPriority = 0;
                    break;

                case 2:
                    departmentPriority = 1;
                    break;

                default:
                    departmentPriority = 0;
            }
            break;

        case 4:
            /*
               Nested switch for Trauma.
               High severity trauma patients are high priority.
            */
            switch (severity)
            {
                case 3:
                    departmentPriority = 1;
                    break;

                case 1:
                case 2:
                    departmentPriority = 0;
                    break;

                default:
                    departmentPriority = 0;
            }
            break;

        default:
            departmentPriority = 0;
    }

    /* Department priority status */
    departmentPriorityStatus =
        (departmentPriority == 1) ? "High Priority" : "No Department-Specific Emergency";

    /* Determine critical condition */
    /*
       Critical when:
       Heart rate < 50 OR > 120
       AND patient is unconscious.
    */
    if ((heartRate < 50 || heartRate > 120) && consciousness == 2)
    {
        critical = 1;
    }
    else
    {
        critical = 0;
    }

    criticalStatus = (critical == 1) ? "Critical" : "Not Critical";

    /* Determine senior status */
    seniorStatus = (age >= 65) ? 1 : 0;

    seniorStatusText =
        (seniorStatus == 1) ? "Senior Priority" : "Not Senior Priority";

    /* Determine temperature alert */
    if (temperature < 36.0 || temperature > 38.0)
    {
        temperatureAlert = 1;
    }
    else
    {
        temperatureAlert = 0;
    }

    temperatureAlertStatus =
        (temperatureAlert == 1) ? "Temperature Alert" : "Normal Temperature";

    /*
       Calculate case category using modulus operator.
       (Age + Heart Rate) % 4
    */
    caseRemainder = (age + heartRate) % 4;

    switch (caseRemainder)
    {
        case 0:
            caseCategory = "Case Category A";
            break;

        case 1:
            caseCategory = "Case Category B";
            break;

        case 2:
            caseCategory = "Case Category C";
            break;

        case 3:
            caseCategory = "Case Category D";
            break;

        default:
            caseCategory = "Unknown";
    }

    /*
       Final triage decision:
       1. Critical -> Immediate Medical Attention
       2. Department priority OR senior OR temperature alert
          -> Priority Further Assessment
       3. Otherwise -> Routine Medical Assessment
    */
    if (critical == 1)
    {
        finalDecision = "Immediate Medical Attention";
    }
    else if (departmentPriority == 1 ||
             seniorStatus == 1 ||
             temperatureAlert == 1)
    {
        finalDecision = "Priority Further Assessment";
    }
    else
    {
        finalDecision = "Routine Medical Assessment";
    }

    /* Display final results */
    printf("\n============================================\n");
    printf("          PATIENT TRIAGE RESULT\n");
    printf("============================================\n");

    printf("Department                : %s\n", departmentName);
    printf("Patient Age               : %d years\n", age);
    printf("Heart Rate                : %d bpm\n", heartRate);
    printf("Body Temperature          : %.1f C\n", temperature);
    printf("Level of Consciousness    : %s\n", consciousnessStatus);
    printf("Severity Level            : %s\n", severityStatus);

    printf("\nDepartment-Specific Status: %s\n",
           departmentPriorityStatus);

    printf("Critical Condition        : %s\n", criticalStatus);

    printf("Senior Status             : %s\n",
           seniorStatusText);

    printf("Temperature Status        : %s\n",
           temperatureAlertStatus);

    printf("Case Category             : %s\n", caseCategory);

    printf("\n--------------------------------------------\n");
    printf("FINAL TRIAGE DECISION     : %s\n", finalDecision);
    printf("--------------------------------------------\n");

    return 0;
}

