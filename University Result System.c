#include<stdio.h>
int main (){
	int department;
	printf("1.computer science\n");
	printf("2.electrical engineering\n");
	printf("3.business administration\n");
	printf("4.mathematics\n");
	printf("Enter your department: ");
	scanf("%d",&department);
	float theorymarks;
	float practicalmarks;
	float attendance;
	printf("Enter your theory marks: ");
	scanf("%f",&theorymarks);
	printf("Enter your practical marks: ");
	scanf("%f",&practicalmarks);
	printf("Enter your attendance: ");
	scanf("%f",&attendance);
	switch(department){
		case 1:
			if(theorymarks>=50&&practicalmarks>=40&&attendance>=75){
				printf("passed");
			}
			else{
				printf("failed");
			}
			break;
		case 2:
			if(theorymarks>=55&&practicalmarks>=45&&attendance>=75)
			{printf("passed");
			}
			else {
			printf("failed");}
			break;
		case 3:
			if(theorymarks>=50&&practicalmarks>=35&&attendance>=80)
			{printf("passed");
			}
			else{
			printf("failed");}
			break;
		case 4:
			if(theorymarks>=60&&practicalmarks>=40&&attendance>=75)
			{printf("passed");
	    	}
	    	else{
	    	printf("failed");}
			break;
		}
		if(theorymarks>=85&&practicalmarks>=80&&attendance>=90)
		{printf("Eligible for distinction");}
		else{
		printf("Not eligible for distinction");}
		if((int)theorymarks%3==1)
		{printf("seat category A");
		}
		else if((int)theorymarks%3==1)
		{printf("seat category B");
		}
		else 
		{printf("seat category C");
		}
		return 0;
		
			
		
			
	}


