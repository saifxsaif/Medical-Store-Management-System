#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include<time.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

struct Medicine{
   int id,price,quantity;
   char medicneName[100],Company[100],Mfg_Date[11],Exp_Date[11],info[5000];
  }m[100];
void PurchaseMedicine();
void StockOfMedicine(int number);
void KnowInfoAboutMedicine(int number);
void AddMedicineinStore(int number,struct Medicine m[]);
void DeleteMedicineStore(int number);
void ChangeMedicineDetails(int number);
void printloyal ();
void makeloyal ();
void login();
void bookapp();

static int n_r = 0;
typedef enum {
    MALE = 0,
    FEMALE = 1
} gender;

typedef struct tag_customer {
    unsigned id;
    char firstname[20];
    char lastname[20];

    unsigned age;
    gender gender;
    char city[20];
} customer;

static void displayMainMenu();
static void scanLoop(const char *prompt, const char *fmt, void *dest);
static char menuChoice();
static unsigned readCustomerAge();
static gender readCustomerGender();
static void displayCustomer(const customer *c);
static void readCustomers(const char *filename);
static void scanCustomer(customer *c);
static void addCustomer(const char *filename);
static unsigned readYear();
COORD coord= {0,0};
void gotoxy(int x,int y);
int pattern ();
void display();

main () {
	
	int pass,i,type,option,num,c,x=12,y=12;
	int password = 1234;
	
	display();
	
	gotoxy(x,y);
	printf("Select 1 for Administrator or 2 for user: ");
	gotoxy(13,13);
	scanf("%d", &type);
	switch (type) {
		case 1:
		login(); 
		gotoxy(16,16);
			printf("Enter password: ");
		gotoxy(17,17);	
			scanf("%d", &pass);
		if (pass == password){
			system("cls");
			printf("Welcome Administrator !!!");
			admin_menu();
		}
		else {
			system("cls");
			printf("Incorrect Id and password. Please try again!!");
			main();
		}
		break;
		case 2: 
			system("cls");
			printf("Welcome Customer!!!\n");
			do {
			printf("\nPress\n1 To purchase medicine \n2 To book appointment \n3 Make Loyalty card \n4 To go to previous menu ");
			scanf("%d", &option );
	switch(option){
		case 1: 
			system("cls");
			PurchaseMedicine();
		break;	
		case 2:
			system("cls");
			bookapp();
		break;	
		case 3:
			system("cls");			
			printf("Enter 1 for registering in loyalty card or 2 for checking your Loyalty points\n");
			scanf("%d", &num);
			switch (num){
			case 1:
			printf("\n*****************MAKING LOYALTY CARD*****************\n");
			makeloyal();
			break;
			case 2:
			printf("\n*****************EXISTING LOYALTY CARDS******************\n");
			printloyal();
			break;
			}
		break;
		case 4:
			system("cls");
			main();
		break;
	}
	printf("To Continue with other Options Enter 1 Else any other number\n");
	scanf("%d",&c);
	system("cls");
	}while(c==1);
}
}

void admin_menu(){
	int option;
	int i,j,choice,num,number=0,c; 
	printf("\nPress\n1 for Customer list\n2 for Appointment Scheduling\n3 for Medicine List\n4 To go to previous menu");
	scanf("%d", &option );
	switch(option){
		case 1: 
		customerlist();
		printf("Press 1 to go to previous menu or any number to terminate program");
            scanf("%d", &num);
                if (num==1){
                	system("cls");
                	admin_menu();
				}
				else {
                return;					
				}
		break;
		case 2:
			system("cls");
		readYear();
    while (true) {
        switch (menuChoice())
        {
            case 'a':
                addCustomer("customer.txt");
                n_r++;
                break;

            case 'd':
                readCustomers("customer.txt");
                break;

            case 'e':
                puts(
                    "Press 1 to go to previous menu or any number to terminate program"
                );
                scanf("%d", &num);
                if (num==1){
                	system("cls");
                	admin_menu();
				}
				else {
                return 0;					
				}
            default:
                puts("Invalid selection! Please try again.");
        }
    }
    	break;
		case 3:
			system("cls");
   		for(i=0;i<100;i++) {
			    m[i].id=0;
			   m[i].price=0;
			   m[i].quantity=0;
			   strcpy(m[i].Mfg_Date,"");
			  strcpy(m[i].Exp_Date,"");
			   strcpy(m[i].medicneName,"");
			   strcpy(m[i].Company,"");
			   strcpy(m[i].info,"");
   		}
   		m[0].id=1;
   		m[0].price=120;
   		m[0].quantity=30;
		strcpy(m[0].Mfg_Date,"23-04-2016");
		strcpy(m[0].Exp_Date,"24-04-2020");
		strcpy(m[0].medicneName,"Paracetmol");
		strcpy(m[0].Company,"ABCD");
		strcpy(m[0].info,"Good Medicine for Fever");
		m[1].id=1;
   		m[1].price=220;
   		m[1].quantity=30;
		strcpy(m[1].Mfg_Date,"23-04-2012");
		strcpy(m[1].Exp_Date,"24-04-2021");
		strcpy(m[1].medicneName,"Panadol");
		strcpy(m[1].Company,"ABCDE");
		strcpy(m[1].info,"Removes Headache");
   do{
   	menu:
   		system("cls");
   printf("Enter\n1 - Stock of Medicine in Store\n2 - Medicine Information\n3 - Add Medicine\n4 - To go back to menu");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
    {
    	system("cls");
    StockOfMedicine(number+1);	
     break;
    }
     case 2:
    {
    	system("cls");
     KnowInfoAboutMedicine(number+1);
     break;
    }
      case 3:
      {
      	system("cls");
	  	++number;
       AddMedicineinStore(number,m);        
       break;
      }
      case 4:
      	{
			system("cls");
      		admin_menu();
		  }
		  default : 
		  	goto menu;
   }
     printf("To Continue with other Options Enter 1 Else any other number\n");
	 scanf("%d",&c);
   }while(c==1);
	break;
	case 4: 
	system("cls");
		printf("Press 1 to go to previous menu or any number to terminate program");
            scanf("%d", &num);
                if (num==1){
                	system("cls");
                	admin_menu();
				}
				else {
                return 0;					
				}
	}
}

void PurchaseMedicine() {
	int z;
  struct beve{
	char name[50];
	int price;
	int code;
}bev1;
struct peps{
	char name[50];
	int price;
	int code;
}bea1;
struct mari{
	char name[50];
	int price;
	int code;
}mar;
struct lemo{
	char name[50];
	int price;
	int code;
}lem;
struct klar{
	char name[50];
	int price;
	int code;
}kla;
struct cipr{
	char name[50];
	int price;
	int code;
}cip;
struct azom{
	char name[50];
	int price;
	int code;
}azo;
struct velo{
	char name[50];
	int price;
	int code;
}vel;
struct rise{
	char name[50];
	int price;
	int code;
}ris;
struct malt{
	char name[50];
	int price;
	int code;
}mal;

	int i,q,price=0,c,chk,loop;
    char s1[10],b;
    char s2[10];
    	menu:
	    printf("             *  INVENTORY * \n");
	    printf("------------------------------------------------------------------\n");
	    printf("CODE |    NAME      |  PRICE |\tMFG.DATE \n");    
  		printf("\n1\t panadol\t300\t10/01/2007 \n2\t paracetmol\t200\t10/01/2008 \n3\t aspirin\t400\t10/01/2009 \n4\t doda\t\t500\t10/01/2010 \n5\t klaricid\t440\t15/10/2011 \n6\t ciproxin\t290\t22/05/2009 \n7\t azomax \t550\t11/11/2012 \n8\t veloref\t180\t09/06/2013 \n9\t risek\t \t280 \t21/04/2007 \n10\t maltofer\t300\t03/07/2014      ");
  		printf("\n------------------------------------------------------------------\n");

		strcpy(bea1.name,"panadol");
		bea1.price=300;
		bea1.code=1;		
		
		strcpy(bev1.name,"paracetmol");
		bev1.price = 200;
		bev1.code = 2;
	
		strcpy(lem.name,"aspirin");	
		lem.price = 400;
		lem.code = 3;
		
		strcpy(mar.name,"doda");	
		mar.price = 500;
		mar.code = 4;
		
		strcpy(kla.name,"Klaricid");	
		kla.price = 440;
		kla.code = 5;
		
		strcpy(cip.name,"Ciproxin");	
		cip.price = 290;
		cip.code = 6;
		
		strcpy(azo.name,"Azomax");	
		azo.price = 550;
		azo.code = 7;
		
		strcpy(vel.name,"Veloref");	
		vel.price = 180;
		vel.code = 8;
		
		strcpy(ris.name,"Risek");	
		ris.price = 280;
		ris.code = 9;
		
		strcpy(mal.name,"Maltofer");	
		mal.price = 300;
		mal.code = 10;
		
			
		printf("\nHow many products do you want : ");
		scanf("%d",&loop);
		for(i=1;i<=loop;i++) {
		printf("\nEnter the code");
		scanf("%d",&c);	
		
	    switch (c)
		{
		
		case 1:
			price = price + bev1.price;
			printf("\nYou have ordered panadol\n");
		break;
	    case 2:
	    	price = price + bea1.price;
	    	printf("You have ordered paracetmol\n");
	    break;	
		case 3:
			price = price + lem.price;
			printf("You have ordered aspirin\n");
		break; 
		case 4:
			price = price + mar.price;
			printf("You have ordered doda\n");
		break; 	
		case 5:
			price = price + kla.price;
			printf("You have ordered klaricid\n");
		break; 
		case 6:
			price = price + cip.price;
			printf("You have ordered ciproxin\n");
		break; 
		case 7:
			price = price + azo.price;
			printf("You have ordered azomax\n");
		break; 
		case 8:
			price = price + vel.price;
			printf("You have ordered veloref\n");
		break; 	
		case 9:
			price = price + ris.price;
			printf("You have ordered risek\n");
		break; 
		case 10:
			price = price + mal.price;
			printf("You have ordered maltofer\n");
		break; 
		default :
			goto menu;
	}
	}
	printf("\n------------------------------------------------------------------\n");
	printf("TOTAL PRICE IS : %d", price);
	printf("\n------------------------------------------------------------------\n");
	
	}
  void KnowInfoAboutMedicine(int number){
   int i,flag=0;
  char name[100];
  printf("\nEnter Name of the medicine you want to see Review and Info\n");
  fflush(stdin);
  gets(name);
  for(i=0;i<number;i++)
  {
   if(strcmp(m[i].medicneName,name)==0)
   {
    flag=1;
    printf("\nThese are the details of Medicine\n");
    printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
    if(strcmp(m[i].info,"")!=0)
    {
     printf("Review or Info=%s\n",m[i].info);
    }
    else
    {
     printf("Review or Info=Not Available\n");
    }   
   }
  }
  if(flag==0)
  {
   printf("Entered Name Not Found\n");
  }
 }
 
 
 void StockOfMedicine(int number){
  int i;
  if(number!=0)
  {
      printf("All Available Items are : \n");
   for(i=0;i<number;i++)
   {
    if(m[i].id!=0){
    printf("Id=%d\nName=%s\t\tPrice=%d\tAvailable Quantity=%d\nCompany=%s\t\tMfg Date=%s\tExp Date=%s\n",m[i].id,m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
    if(strcmp(m[i].info,"")!=0)
    {
     printf("Review or Info =  %s\n",m[i].info);
    }
    else
    {
     printf("Review or Info =  Not Available\n");
    }
      }
   }  
  }
  else{
   printf("No Items or Medicines Available\n");
  } 
 }
 
 void AddMedicineinStore(int number,struct Medicine m[]) {
  char name[100];
  printf("Enter Medicine Id\n\n");
  scanf("%d",&(m[number].id));
  fflush(stdin);
  printf("Enter Medicine Name\n\n");
  fflush(stdin);
  gets(name);
  strcpy(m[number].medicneName,name);
  printf("Enter Company Name\n\n");
  fflush(stdin);
  gets(m[number].Company);
  printf("Enter Manufactured Date\n\n");
  fflush(stdin);
  gets(m[number].Mfg_Date);
  printf("Enter Expiry Date\n\n");
  fflush(stdin);
  gets(m[number].Exp_Date);
  printf("Enter Quantity\n\n");
  fflush(stdin);
  scanf("%d",&(m[number].quantity));
  printf("Enter Price\n\n");
  fflush(stdin);
  scanf("%d",&(m[number].price));
  strcpy(m[number].info,"");
  printf("Medicine with id %d Added Successfully\n\n",m[number].id);
 }
 
 
 void additem() {
    struct date {
        int day;
        int month;
        int year;
    };
    struct details {
        char name[20];
        int price;
        int code;
        int qty;
        struct date mfg;
    };
    struct details item[50];
    int n, i;
 
    printf("Enter number of items:");
    scanf("%d", &n);
    fflush(stdin);
    for (i = 0; i < n; i++) {
        fflush(stdin);
        printf("Item name %d : \n", i+1);
        scanf("%s", item[i].name);
        fflush(stdin);
        printf("Item code: \n");
        scanf("%d", &item[i].code);
        fflush(stdin);
        printf("Quantity: \n");
        scanf("%d", &item[i].qty);
        fflush(stdin);
        printf("price: \n");
        scanf("%d",  &item[i].price);
        fflush(stdin);
        printf("Manufacturing date(dd-mm-yyyy): \n");
        scanf("%d-%d-%d", &item[i].mfg.day,
        &item[i].mfg.month, &item[i].mfg.year);
    }
    printf("\n\n");
    printf("             *****  INVENTORY ***** \n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE| MFG.DATE \n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    printf("%d     %-15s        %-d          %-5d     %-5d%d/%d/%d \n", i + 1, item[i].name, item[i].code, item[i].qty,item[i].price, item[i].mfg.day, item[i].mfg.month,item[i].mfg.year);
    printf("------------------------------------------------------------------\n");
}

void printloyal () {
int id=21357813;
srand(time(0));
int point = rand()%999;
char sentence[80];
int i;
srand(time(0));
printf("Enter First Name :\n");
scanf("%s", sentence);



printf("\n\n                WELCOME TO XXX PHARMACY     \n");
printf("                     LOYALTY CARD         \n\n");
printf("\tName:%s\t\tId:%d\n  ", sentence, id++);
printf("\tCity:Karachi\t\tNo.0331234567   \n\n");
printf("                   LOYALTY POINTS:%d         \n\n", point);
printf("                   |||||||||||||||||| \n");
printf("                   133687971234567893           \n");

}

void makeloyal () {
int id=21357813;
char sentence[80];
char city[80];
int c_no[80];

printf("Enter First Name :\n");
scanf(" %s", sentence);
printf("Enter City :\n");
scanf(" %s", city);
printf("Enter Contact no : 03");
scanf("%d", c_no);

printf("\n\n                WELCOME TO XXX PHARMACY     \n");
printf("                     LOYALTY CARD         \n\n");
printf("\tName:%s\t\tId:%d\n  ", sentence, id++);
printf("\tCity:%s\t\tNo.: 03%d   \n\n", city, c_no);
printf("                   LOYALTY POINTS:000         \n\n");
printf("                   |||||||||||||||||| \n");
printf("                   133687971234567893           \n");

}

static void displayMainMenu() {
    puts(
        "\n A|a: Add a Customer"
        "\n D|d: Print Customer Details"
        "\n E|e: To go back to previous menu"
    );
}

static void scanLoop(const char *prompt, const char *fmt, void *dest)
{
    char buffer[80];
    int fields;
    do
    {
        printf(prompt);
        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            perror("I/O error on stdin");
            exit(1);
        }

        fields = sscanf(buffer, fmt, dest);
    } while (fields != 1);
}

static char menuChoice()
{
    displayMainMenu();
    char choice;
    scanLoop("Please enter your choice: ", "%c\n", &choice);
    return tolower(choice);
}

static unsigned readCustomerAge()
{
    while (true)
    {
        unsigned age;
        scanLoop("Enter age: ", "%u", &age);
        if (age >= 15 && age <= 90)
            return age;
        puts("Invalid selection! (Age must be between 15 and 90)");
    }
}

static gender readCustomerGender()
{
    char buffer[10];
    char *p = buffer;
    while (true)
    {
        scanLoop("Enter gender (male|female): ", "%9s", buffer);

        for (*p ; *p; p++ )
            *p = tolower(*p);

        if (!strcmp(buffer, "male"))
            return MALE;
        if (!strcmp(buffer, "female"))
            return FEMALE;

        puts("Invalid selection!");
    }
}

static void displayCustomer(const customer *c)
{
    printf(
        "Id: %u"
        "\nName: %s %s"
        "\nAge: %u"
        "\nGender: %s"
        "\nCity: %s"
        "\n",
        c->id, c->firstname, c->lastname, c->age,
        c->gender == MALE ? "male" : "female",
        c->city
    );
}

static void readCustomers(const char *filename)
{
    FILE *fp;
    customer c;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file for customer display");
        exit(1);
    }

    while (fread(&c, sizeof(customer), 1, fp))
        displayCustomer(&c);

    fclose(fp);
}

static void scanCustomer(customer *c)
{
    scanLoop("Enter customer ID: ", "%u", &c->id);
    scanLoop("Enter customer first name: ", "%20s", c->firstname);
    scanLoop("Enter customer last name: ", "%20s", c->lastname);

    c->age = readCustomerAge();
    c->gender = readCustomerGender();

    scanLoop("Enter city: ", "%20s", c->city);
}

static void addCustomer(const char *filename)
{
    const char *mode;
    if (n_r == 0)
        mode = "w";
    else mode = "a";

    FILE *fp = fopen(filename, mode);
    if (fp == NULL)
    {
        perror("Error in opening customer file for writing");
        exit(1);
    }

    customer c;
    scanCustomer(&c);
    fwrite(&c, sizeof(customer), 1, fp);
    fclose(fp);
}

static unsigned readYear()
{
    unsigned year;
    while (true)
    {
        scanLoop("Please Enter Customer registration year (ex:2017): ", "%u", &year);
        if (year >= 2000 && year <= 2500)
            return year;
        puts("Year out of range");
    }
}

void customerlist() {
    struct e_date
    {
        int day;
        int month;
        int year;
    };
    struct e_details
    {
        char name[20];
        char city[20];
        int price;
        int code;
        int qty;
        struct e_date mfg;
    };
    struct e_details item[50];
    int n, i;
 
    printf("How many customers do you want to add in list? \n");
    scanf("%d", &n);
    fflush(stdin);
    for (i = 0; i < n; i++) {
        fflush(stdin);
        printf("Customer name: \n\n");
        scanf("%s", item[i].name);
        fflush(stdin);
        printf("Customer id : \n\n");
        scanf("%d", &item[i].code);
        fflush(stdin);
        printf("Contact number : \n\n");
        scanf("%d", &item[i].qty);
        printf("Customer city: \n\n");
        scanf("%s", &item[i].city);
        fflush(stdin);
    }
    printf("\n\n             *****  CUSTOMER LIST ***** \n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.|    NAME           |    CITY         |   ID     |  Contact no. \n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
        printf("%d     %-15s        %-15s  %-d    %-5d \n", i + 1, item[i].name, item[i].city, item[i].code, item[i].qty,item[i].price);
    printf("------------------------------------------------------------------\n");
}

void login() {
	int ret;
	char user_name[80] = {"saifullah"};
	char str2[80];
	menu:
	gotoxy (14,14);
	printf("Enter username (case sensitive) : ");
	gotoxy(15,15);
	scanf("%s", &str2);
		ret = strcmp(user_name, str2);
		if(ret == 0) {
		printf("");
		} 
		else {
		system("cls");
		printf("Invalid username.Please try again!!!");
		goto menu;
		}
}

void display()
{
   int x, y, i, j;

   x = 12;
   y = 15;

	pattern ();

   gotoxy(x, y);

   printf("WELCOME TO RAAS PHARMACY !!");
   
   gotoxy(42, 25);

   printf("Press enter to Continue ");

   getch();
	system("cls");
	
}


int pattern() {
int n=14, x=14,  y=14,  s = 1, k;
for(x = 0; x <= n; x++)
{
for(y = n; y > x; y--)
{
printf(" ");
}
printf("\t* *");
if (x > 0)
{
for(k = 1; k <= s;  k++)
{
printf(" ");
}
s += 2;
printf("\t* *");
}
printf("\n");
}
s -= 4;
for(x = 0; x <= n -1; x++)
{
for(y = 0; y <= x; y++)
{
printf(" ");
}
printf("\t* *");
for(k = 1; k <= s; k++)
{
printf(" ");
}
s -= 2;
if(x != n -1)
{
printf ("\t* *");
}
//ending line after each row
printf("\n");
}
return 0;
// ending line after each row
printf("\n");
}


void gotoxy(int x,int y) {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void bookapp(){
    struct e_date
    {
        int day;
        int month;
        int year;
    };
    struct e_details
    {
        char name[20];
        int price;
        int code;
        int qty;
        struct e_date mfg;
    };
    struct e_details item[50];
    int n, i;
 
    printf("How many appointments do you want to book?\n");
    scanf("%d", &n);
    fflush(stdin);
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Name: \n");
        scanf("%s", item[i].name);
        fflush(stdin);
        printf("Id : \n");
        scanf("%d", &item[i].code);
        fflush(stdin);
        printf("Age : \n");
        scanf("%d", &item[i].qty);
        fflush(stdin);
        printf("Time : \n");
        scanf("%d",  &item[i].price);
        fflush(stdin);
        printf("date of birth (dd-mm-yyyy): \n");
        scanf("%d-%d-%d", &item[i].mfg.day,&item[i].mfg.month, &item[i].mfg.year);
    }
    printf("\n\n             *****  INVENTORY ***** \n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.|    NAME           |   ID     |    AGE    |  TIME |   DOB    \n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
        printf("%d     %-15s        %-d          %-5d       %-5d%d/%d/%d \n", i + 1, item[i].name, item[i].code, item[i].qty,item[i].price, item[i].mfg.day, item[i].mfg.month,item[i].mfg.year);
    printf("------------------------------------------------------------------\n");
}

