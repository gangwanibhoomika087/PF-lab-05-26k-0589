#include <stdio.h>

int main()
{
    int permission = 0;
    int choice;

    // Permission flags
    int READ = 1;       // 0001
    int WRITE = 2;      // 0010
    int EXECUTE = 4;    // 0100
    int ADMIN = 8;      // 1000

    printf("====================================\n");
    printf(" CYBERSECURITY ACCESS CONTROL SYSTEM\n");
    printf("====================================\n");

    printf("\n1. Add Permission");
    printf("\n2. Check Permission");
    printf("\n3. Toggle Permission");
    printf("\n4. Remove Permission");
    printf("\n5. Display Permission Value");
    printf("\n6. Exit");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        // Add permission using OR
        case 1:
            printf("\nSelect Permission to Add:");
            printf("\n1. Read");
            printf("\n2. Write");
            printf("\n3. Execute");
            printf("\n4. Admin");

            printf("\nEnter choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    permission = permission | READ;
                    printf("Read permission added.\n");
                    break;

                case 2:
                    permission = permission | WRITE;
                    printf("Write permission added.\n");
                    break;

                case 3:
                    permission = permission | EXECUTE;
                    printf("Execute permission added.\n");
                    break;

                case 4:
                    permission = permission | ADMIN;
                    printf("Admin permission added.\n");
                    break;

                default:
                    printf("Invalid permission!\n");
            }
            break;


        // Check permission using AND
        case 2:
            printf("\nEnter permission value: ");
            scanf("%d", &permission);

            printf("\nCheck which permission?");
            printf("\n1. Read");
            printf("\n2. Write");
            printf("\n3. Execute");
            printf("\n4. Admin");

            printf("\nEnter choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    if(permission & READ)
                        printf("Read permission is available.\n");
                    else
                        printf("Read permission is NOT available.\n");
                    break;

                case 2:
                    if(permission & WRITE)
                        printf("Write permission is available.\n");
                    else
                        printf("Write permission is NOT available.\n");
                    break;

                case 3:
                    if(permission & EXECUTE)
                        printf("Execute permission is available.\n");
                    else
                        printf("Execute permission is NOT available.\n");
                    break;

                case 4:
                    if(permission & ADMIN)
                        printf("Admin permission is available.\n");
                    else
                        printf("Admin permission is NOT available.\n");
                    break;

                default:
                    printf("Invalid permission!\n");
            }
            break;


        // Toggle permission using XOR
        case 3:
            printf("\nEnter current permission value: ");
            scanf("%d", &permission);

            printf("\nSelect Permission to Toggle:");
            printf("\n1. Read");
            printf("\n2. Write");
            printf("\n3. Execute");
            printf("\n4. Admin");

            printf("\nEnter choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    permission = permission ^ READ;
                    break;

                case 2:
                    permission = permission ^ WRITE;
                    break;

                case 3:
                    permission = permission ^ EXECUTE;
                    break;

                case 4:
                    permission = permission ^ ADMIN;
                    break;

                default:
                    printf("Invalid permission!\n");
                    return 0;
            }

            printf("Permission toggled successfully.\n");
            printf("New permission value = %d\n", permission);
            break;


        // Remove permission using AND with NOT
        case 4:
            printf("\nEnter current permission value: ");
            scanf("%d", &permission);

            printf("\nSelect Permission to Remove:");
            printf("\n1. Read");
            printf("\n2. Write");
            printf("\n3. Execute");
            printf("\n4. Admin");

            printf("\nEnter choice: ");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    permission = permission & ~READ;
                    break;

                case 2:
                    permission = permission & ~WRITE;
                    break;

                case 3:
                    permission = permission & ~EXECUTE;
                    break;

                case 4:
                    permission = permission & ~ADMIN;
                    break;

                default:
                    printf("Invalid permission!\n");
                    return 0;
            }

            printf("Permission removed successfully.\n");
            printf("New permission value = %d\n", permission);
            break;


        // Display permission value
        case 5:
            printf("\nEnter permission value: ");
            scanf("%d", &permission);

            printf("\nPermission Value = %d\n", permission);

            if(permission & READ)
                printf("Read: YES\n");
            else
                printf("Read: NO\n");

            if(permission & WRITE)
                printf("Write: YES\n");
            else
                printf("Write: NO\n");

            if(permission & EXECUTE)
                printf("Execute: YES\n");
            else
                printf("Execute: NO\n");

            if(permission & ADMIN)
                printf("Admin: YES\n");
            else
                printf("Admin: NO\n");

            break;


        case 6:
            printf("\nExiting program...\n");
            break;

        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}
