#include <stdio.h>

int main()
{
    int productcategory;
    int customercategory;
    int ordernumber;
    int processinggroup;

    float orderamount;
    float deliverydistance;
    float discountpercent;
    float discountamount;
    float finalpayableamount;
    float deliverycharges;
    float prioritycharges;
    float totalamount;
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Books\n");
    printf("4. Household\n");
    printf("Enter the product category: ");
    scanf("%d", &productcategory);
    printf("\n1. Regular\n");
    printf("2. Premium\n");
    printf("3. Corporate\n");
    printf("Enter the customer category: ");
    scanf("%d", &customercategory);


    printf("\nEnter order amount: ");
    scanf("%f", &orderamount);

    printf("Enter delivery distance: ");
    scanf("%f", &deliverydistance);

    printf("Enter order number: ");
    scanf("%d", &ordernumber);

  
    switch(productcategory)
    {
        case 1:
            switch(customercategory)
            {
                case 1:
                    discountpercent = 5;
                    break;

                case 2:
                    discountpercent = 10;
                    break;

                case 3:
                    discountpercent = 15;
                    break;
            }
            break;

        case 2:
            switch(customercategory)
            {
                case 1:
                    discountpercent = 10;
                    break;

                case 2:
                    discountpercent = 15;
                    break;

                case 3:
                    discountpercent = 20;
                    break;
            }
            break;

        case 3:
            switch(customercategory)
            {
                case 1:
                    discountpercent = 8;
                    break;

                case 2:
                    discountpercent = 12;
                    break;

                case 3:
                    discountpercent = 18;
                    break;
            }
            break;

        case 4:
            switch(customercategory)
            {
                case 1:
                    discountpercent = 7;
                    break;

                case 2:
                    discountpercent = 14;
                    break;

                case 3:
                    discountpercent = 20;
                    break;
            }
            break;
    }

    discountamount = orderamount * discountpercent / 100;
    finalpayableamount = orderamount - discountamount;

    if(finalpayableamount >= 5000 ||
       customercategory == 2 ||
       customercategory == 3)
    {
        deliverycharges = 0;
    }
    else
    {
        deliverycharges = deliverydistance * 100;
    }

    if((customercategory == 2 || customercategory == 3) &&
       orderamount >= 10000)
    {
        prioritycharges = 500;
    }
    else
    {
        prioritycharges = 0;
    }

 
    processinggroup = ordernumber % 4;

 
    totalamount = finalpayableamount + deliverycharges + prioritycharges;

   
    printf("\n========== FINAL ORDER REPORT ==========\n");

    printf("Product Category: ");

    switch(productcategory)
    {
        case 1:
            printf("Electronics\n");
            break;

        case 2:
            printf("Clothing\n");
            break;

        case 3:
            printf("Books\n");
            break;

        case 4:
            printf("Household\n");
            break;
    }

    printf("Customer Category: ");

    switch(customercategory)
    {
        case 1:
            printf("Regular\n");
            break;

        case 2:
            printf("Premium\n");
            break;

        case 3:
            printf("Corporate\n");
            break;
    }

    printf("Original Order Amount: Rs. %.2f\n", orderamount);
    printf("Discount Percentage: %.2f%%\n", discountpercent);
    printf("Discount Amount: Rs. %.2f\n", discountamount);
    printf("Final Payable Amount: Rs. %.2f\n", finalpayableamount);
    printf("Delivery Distance: %.2f km\n", deliverydistance);

    printf("Shipping Status: %s\n",
           deliverycharges == 0 ? "Free Shipping" : "Shipping Charges Apply");

    printf("Delivery Charges: Rs. %.2f\n", deliverycharges);

    printf("Priority Delivery: %s\n",
           prioritycharges == 500 ? "Yes" : "No");

    printf("Priority Charges: Rs. %.2f\n", prioritycharges);

    printf("Processing Group: ");

    switch(processinggroup)
    {
        case 0:
            printf("Processing Group A\n");
            break;

        case 1:
            printf("Processing Group B\n");
            break;

        case 2:
            printf("Processing Group C\n");
            break;

        case 3:
            printf("Processing Group D\n");
            break;
    }

    printf("Total Amount Payable: Rs. %.2f\n", totalamount);

    return 0;
}
