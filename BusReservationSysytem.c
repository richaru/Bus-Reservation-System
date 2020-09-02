#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>
char type;
struct time
{
int hrs,mins;

};

struct bus
{
int busNum;
int busCode;
char seat[8][4][20];
char driversName[20];
struct time stDeparture_Time, stArrival_Time;
char goesTo[20];
char goesFrom[20];
float fFare;
int ticketSold;
};

/*~~~~~~~~~~~~~~~~~~~~~~GLOBAL VARIABLES~~~~~~~~~~~~~~~~~~~~~~*/


char chEmpty[]="Empty";

static int number=1;
char i=':'; 
struct bus stBus[40];


/*~~~~~~~~~~~~~~~~~~~~~~FUNCTION PROTOTYPES~~~~~~~~~~~~~~~~~~~~~~*/

void adminScreen();
void userScreen();
void login();
void newBus();
void mainMenu();
void showBuses();
void empty();
void seatReservation();
void showStatus();
void printLine();
void dailyReport();


void main()
{
mainMenu();
}

void mainMenu()
{
int choice;
	login();
    if(type=='A')
    adminScreen();
    if(type=='U')
    userScreen();
printf("\n\n\t\t\t______________________");
printf("\n\n\t\t\tBUS RESERVATION SYSTEM");
printf("\n\n\t\t\t______________________\n");
printLine();
}

void adminScreen()
{
	int choice;
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\t ADMIN SCREEN");
	printf("\n\n\t\t\t______________________\n");
	printLine();
	
	printf("\n\n\t\t1.Add New Bus");
	printf("\n\t\t2.Offers");
	printf("\n\t\t3.Change Bus Details");
	printf("\n\t\t4.Logout");
	printf("\n\n\n\tEnter your choice as(1/2/3/4):-\t");
	fflush(stdin);
	scanf("%d",&choice);
	switch(choice)
	{
	case 1 : newBus();
	break;
	case 2: printf("\t\t\tOffers to be Added!!!!");
	break;
	case 3: printf("\t\t\tChange Bus Details");
	break;
	case 4: exit(0);
	default:	printf("\t\t\tU have entered Wrong Choice!!!!");
	getch();
	mainMenu();
	}
}
void userScreen()
{
	int choice;
	printf("\n\n\t\t\t______________________");
	printf("\n\n\t\t\t USER SCREEN");
	printf("\n\n\t\t\t______________________\n");
	printLine();
	printf("\n\n\t\t1.Seat Reservation");
	printf("\n\n\t\t2.Availability of Buses");
	printf("\n\t\t3.Check Status");
	printf("\n\t\t4.Offers");
	printf("\n\t\t5.Customer Care");
	printf("\n\t\t6.Exit");
	printf("\n\n\n\tEnter your choice as(1/2/3/4/5/6):-\t");
	fflush(stdin);
	scanf("%d",&choice);
	switch(choice)
	{
	case 1: seatReservation();
	break;
	case 2: showBuses();
	break;
	case 3: showStatus();
	break;
	case 4: dailyReport();
	break;
	case 5: printf("Contact us at abc@xyz.com");
	break;
	case 6: exit(0);
	default:	printf("\t\t\tU have entered Wrong Choice!!!!");
	getch();
	mainMenu();
	}
}
void newBus()
{ 
char chChoice;
printf("\n\n\t\tEnter Information about bus\n");
do{
printLine();
printf("\n\n\t\t Bus No:\t%d",number);
busC:	printf("\n\n\tEnter Bus Code:\t");
fflush(stdin);
stBus[number].busNum=number;
scanf("%d",&stBus[number].busCode);
if(stBus[number].busCode<1||stBus[number].busCode>9999)
{
printf("\n\t\tInvalid Bus Code!!!!");
goto busC;
}
dname: printf("\n\n\tEnter driver's name:\t");
fflush(stdin);
gets(stBus[number].driversName);
if(strlen(stBus[number].driversName)>20)
{
printf("Maximum 20 characters are allowed");
goto dname;
}
artime:	printf("\n\tEnter arrival time:\t");
fflush(stdin);
scanf("%d%c%d",&stBus[number].stArrival_Time.hrs,&i,&stBus[number].stArrival_Time.mins);
if(stBus[number].stArrival_Time.hrs==0)
{
printf("\n\n\t\tInvalid tTme!!!!");
goto artime;
}
if((i!=':')||(stBus[number].stArrival_Time.hrs>=24)||(stBus[number].stArrival_Time.hrs<0)||(stBus[number].stArrival_Time.mins>=60)||(stBus[number].stArrival_Time.mins<0))
{
printf("\n\t\tInvalid Time!!!!\n");
printf("\t\tEnter only--hh:mm!!!!");
goto artime;
}
deptime: printf("\n\tEnter departure time:\t");
fflush(stdin);
scanf("%d%c%d",&stBus[number].stDeparture_Time.hrs,&i,&stBus[number].stDeparture_Time.mins);
if(stBus[number].stDeparture_Time.hrs==0)
{
printf("\t\tinvalid Time!!!!");
goto deptime;
}
if((i!=':')||(stBus[number].stDeparture_Time.hrs>=24)||(stBus[number].stDeparture_Time.hrs<0)||(stBus[number].stDeparture_Time.mins>=60)||(stBus[number].stDeparture_Time.mins<0))
{
printf("\n\t\tInvalid Time!!!!");
printf("\n\t\tEnter only--hh:mm");
goto deptime;
}
from:	printf("\n\tFrom:\t");
fflush(stdin);
gets(stBus[number].goesFrom);
if(strlen(stBus[number].goesFrom)>20)
{
printf("Maximum 20 characters are allowed");
goto from;
}

to: printf("\n\tTo:\t");
fflush(stdin);
gets(stBus[number].goesTo);
if(strlen(stBus[number].goesTo)>20)
{
printf("Maximum 20 characters are allowed");
goto to;
}
printf("\n\tFare:\t");
fflush(stdin);
scanf("%f",&stBus[number].fFare);
stBus[number].ticketSold=0;
printf("\n");
empty();
printLine();

printf("\n\n\n\tDo u want to continue to add information about new bus(y/n)?? ");
fflush(stdin);
scanf("%c",&chChoice);

number++;

}while(chChoice=='y'||chChoice=='Y');
mainMenu();
}

void showBuses()
{
int i1;
printf("\n\n\t\t\t______________________");
printf("\n\n\t\t\t BUSES AVALAIBLE");
printf("\n\n\t\t\t______________________\n");

for(i1=1;i1<number;i1++)	
{	
printf("\n");
printLine();
printf("\n\t\tbus no-\t\t%d",stBus[i1].busNum);
printf("\n\t\tbus code-\t%d",stBus[i1].busCode);
printf("\n\t\tDrivers Name-\t%s",stBus[i1].driversName);
printf("\n\t\tFrom-\t\t%s",stBus[i1].goesFrom);
printf("\n\t\tTo-\t\t%s",stBus[i1].goesTo);
printf("\n\t\tArrival time-\t%d%c%d",stBus[i1].stArrival_Time.hrs,i,stBus[i1].stArrival_Time.mins);
printf("\n\t\tDeparture time-\t%d%c%d",stBus[i1].stDeparture_Time.hrs,i,stBus[i1].stDeparture_Time.mins);
printf("\n\t\tFare-\t\t%.4f",stBus[i1].fFare);
printf("\n\t\tTickets Sold-\t%d",stBus[i1].ticketSold);
printf("\n");
printLine();

}

getch();

mainMenu();
}

void seatReservation()
{
char name[20];
int busN;
int seat;
char chChoice;
printf("\n\n\t\t\t______________________");
printf("\n\n\t\t\t ALLOTMENT");
printf("\n\n\t\t\t______________________\n");
printLine();
printf("\n\n\t\tEnter the Bus Number-\t");
fflush(stdin);
scanf("%d",&busN);
if(busN>=number)
{
printf("\n\t\t\tSorry Bus Doesn,t Exist!!!!");
seatReservation();
}

seat: printf("\n\t\tEnter the Seat number-\t");
fflush(stdin);
scanf("%d",&seat);
if(seat>32)
{
printf("\n\t\tSorry!! There r only 32 seats in the bus!!!!") ;
goto seat;
}
else if(strcmp(stBus[busN].seat[seat/4][(seat%4)-1],"Empty")==0)
{
printf("\n\t\tEnter the passenger's name-\t");
name:	fflush(stdin);
gets(name);
if(strlen(name)>20)
{
printf("\n\t\tplz enter only 20 characters!!!!");
goto name;
}
else
{
strcpy(stBus[busN].seat[seat/4][seat%4-1],name);
printf("\n\t\tYour seat is reserved now!!");
stBus[busN].ticketSold++;
printf("\n\t do u want to continue with reservation(y/n)??");
fflush(stdin);
chChoice=getchar();
if(chChoice=='y'||chChoice=='Y')
seatReservation();
else
mainMenu();
}


}else
{
printf("\n\tThis seat is already reserved!!!!");
printf("\n\t do u want to try again??");
fflush(stdin);
chChoice=getchar();
if(chChoice=='y'||chChoice=='Y')
seatReservation();
else
mainMenu();
}
}

void dailyReport()
{	int i;
double dailyTotal=0;
double busTotal=0;
printf("\n\n\t\t\t______________________");
printf("\n\n\t\t\t DAILY REPORT");
printf("\n\n\t\t\t______________________\n");
printLine();
for(i=1;i<number;i++)
{	busTotal=stBus[i].ticketSold*stBus[i].fFare;
printf("\n\t\tBus no-\t%d\t Total tickets Sold-\t%d",i,stBus[i].ticketSold);
printf("\n\t\t\tTotal Fare-\t%.4lf\n",busTotal);
dailyTotal+=busTotal;

}
printf("\n\n\t\t\tDaily Total=\t%lf",dailyTotal);
getch();
mainMenu();

}

void empty()
{
	int i,j;
for(i=0;i<8;i++)
{
for(j=0;j<4;j++)
{
strcpy(stBus[number].seat[i][j],chEmpty);
}

}
}

void showStatus()
{
int busN,index=0,j,k;
char chChoice;
printf("\n\n\t\tEnter Bus no.-\t");
fflush(stdin);
scanf("%d",&busN);
if(busN>=number)
{
printf("\n\t\tBus doesn't Exist!!!!");
showStatus();
}
else
{
printLine();
printf("\nBus code-\t%d\t\tDriver's Name-\t%s",stBus[busN].busCode,stBus[busN].driversName);
printf("\nArrival Time-\t%d%c%d\t\tDeparture Time\t%d%c%d",stBus[busN].stArrival_Time.hrs,i,stBus[busN].stArrival_Time.mins,stBus[busN].stDeparture_Time.hrs,i,stBus[busN].stDeparture_Time.mins);
printf("\nFrom-\t\t%s\t\tTo-\t\t%s",stBus[busN].goesFrom,stBus[busN].goesTo);
printf("\nFare-\t\t%f\tTickets Sold-\t%d",stBus[busN].fFare,stBus[busN].ticketSold);
printf("\n");
printLine();
for(j=0;j<8;j++)
{
printf("\n");
for(k=0;k<4;k++)
{	index++;
printf("%d .%s\t",index,stBus[busN].seat[j][k]);
}
}
}
printf("\n\n\t\tDo u want to continue with another bus(y/n)??");
fflush(stdin);
chChoice=getchar();
if(chChoice=='y'||chChoice=='Y')
showStatus();
else
mainMenu();
}


void printLine()
{	int j;
for(j=0;j<60;j++)
printf("*");
}


void login()
{
	int choice, a=0;
	char adminusername[10],adminpassword[10];
	char username[10],password[10];
	printf("\n======= Press 1 for Admin Login -- Press 2 for User Login =======\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		do
		{
			printf("\n======= ADMIN LOGIN FORM =======\n");
			printf("\n Enter username  ");
			scanf("%s",&adminusername);
			printf("\n Enter password  ");
			scanf("%s",&adminpassword);
			if(strcmp(adminusername,"admin")==0 && strcmp(adminpassword,"admin")==0)
			{
				type='A';
				printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
				printf("\n\n\n\t\t\t\tPress any key to continue...");
				getch();//holds the screen
				break;
			}
			else
			{
				printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
				a++;
				
				getch();//holds the screen	
			}	
		}
		while(a<=2);
			if (a>2)
			{
				printf("\nSorry you have entered the wrong username and password for four times!!!");
				
				getch();
				
				}
				system("cls");	

	}

	
	else if (choice==2)
	{
		do
		{
			printf("\n======= USER LOGIN FORM =======\n");
			printf("\n Enter username  ");
			scanf("%s",&username);
			printf("\n Enter password  ");
			scanf("%s",&password);
			if(strcmp(username,"user")==0 && strcmp(password,"user")==0)
			{
				type='U';
				printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
				printf("\n\n\n\t\t\t\tPress any key to continue...");
				getch();//holds the screen
				break;
			}
			else
			{
				printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
				a++;
				
				getch();//holds the screen	
			}	
		}
		while(a<=2);
			if (a>2)
			{
				printf("\nSorry you have entered the wrong username and password for four times!!!");
				
				getch();
				
				}
				system("cls");	
	}
	else 
	{
		printf("\n======= INVALID INPUT =======");
	}
}
