#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct cnt
{
  char srn[50];
  char phone[50];
  char addr[50];
  char email[50];
  char name[50];
  char cate[50];
}cnt1;


void menu();
void add_cnt();
void cnt_list();
void ed_cnt();
void ser_cnt();
void del_cnt();
void cng_pass();
void password();
int main()
{

//loading window

	FILE *ptr;
	char pass[20];
	char temp[20];
	char ch;
	int k,i;
	int choise;
	/*
	clrscr();
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();
	gotoxy(32,2);
	textcolor(20);
	cprintf("Contact Manager");
	gotoxy(1,3);
	cprintf("--------------------------------------------------------------------------------");
	gotoxy(30,4);
	textcolor(11);
	cprintf("Developer Om Shahane");
	gotoxy(31,5);
	cprintf("Date : %s\n",__DATE__);
	textcolor(BLUE);
	gotoxy(1,6);
	cprintf("--------------------------------------------------------------------------------");
	gotoxy(10,17);
	textcolor(WHITE);
	cprintf("loading...");
	gotoxy(31,18);
	window(10,20,70,20);
	textbackground(WHITE);
	clrscr();
	for(i=0;i<60;i++)
	{
		if(i<25)
		{
			delay(100);
			textcolor(RED);
			cprintf("#");
		}
		else if(i>40)
		{
			delay(500);
			textcolor(RED);
			cprintf("#");
		}
		else
		{
			textcolor(RED);
			cprintf("#");
		}

	}

	gotoxy(35,22);
	textcolor(RED+BLINK);
	clrscr();
	cprintf("\nPress any key...");


	*/
//password window
   //	password();


	menu();
	scanf("%d",&choise);
	switch(choise)
	{
		case 1:
		{
		  add_cnt();
		}
		break;
		case 2:
		{
		  cnt_list();
		}
		break;
		case 3:
		{
		  ed_cnt();
		}
		break;
		case 4:
		{
		  del_cnt();
		}
		break;
		case 5:
		{
		  ser_cnt();
		}
		break;
		case 6:
		{
		  cng_pass();
		}
		break;
		case 7:
		{
		  goto end;
		}


	}
	end:
	getch();
	return 0;
}
void menu()
{

	clrscr();

	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(RED);

	gotoxy(30,9);
	textcolor(RED);
	cprintf("MAIN MENU");

	gotoxy(30,10);
	textcolor(BLUE);
	cprintf("--------------------");
	textcolor(11);
	gotoxy(30,11);
	cprintf("1 . Add New Contact");
	gotoxy(30,12);
	cprintf("2 . Contact list");
	gotoxy(30,13);
	cprintf("3 . Edit contact");
	gotoxy(30,14);
	cprintf("4 . Delete contact");
	gotoxy(30,15);
	cprintf("5 . Search Contact");
	gotoxy(30,16);
	cprintf("6 . Change Password");
	gotoxy(30,17);
	cprintf("7 . EXIT");
	textcolor(BLUE);
	gotoxy(30,18);
	cprintf("--------------------");
	gotoxy(30,19);
	textcolor(YELLOW);
	cprintf("Enter your choise !");
	gotoxy(30,20);


}

void add_cnt()
{
	FILE *ptr1;

	clrscr();
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(11);

	ptr1 = fopen("contact.dat","a+b");
	gotoxy(5,3);

	cprintf("Enter SRN. : ");
	gotoxy(20,3);
	fflush(stdin);
	scanf("%s",cnt1.srn );


	gotoxy(5,4);
	cprintf("Enter Name : ");
	gotoxy(20,4);
	fflush(stdin);
	gets(cnt1.name);


	gotoxy(5,5);
	cprintf("Enter Phone: ");
	gotoxy(20,5);
	fflush(stdin);

	gets(cnt1.phone);
	gotoxy(5,6);
	cprintf("Enter Email: ");
	gotoxy(20,6);
	fflush(stdin);
	gets(cnt1.email);

	gotoxy(5,7);
	cprintf("Enter Address:");
	gotoxy(20,7);
	fflush(stdin);

	gets(cnt1.addr);
	gotoxy(5,8);
	cprintf("Enter Category(Friend/Home/Office) : ");
	gotoxy(45,8);
	fflush(stdin);
	gets(cnt1.cate);
	fwrite(&cnt1,sizeof(cnt1),1,ptr1);
	gotoxy(5,10);
	textcolor(YELLOW);
	cprintf("Data added successfully... Press any key...");
	fclose(ptr1);
}

void cnt_list()
{
	FILE *ptr;
	char temp[200];
	char ch;
	int pos,i;
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(RED);
	clrscr();
	ptr = fopen("contact.dat","rb");
	fseek(ptr,0,SEEK_SET);
	gotoxy(1,2);
	textcolor(11);
	cprintf("--------------------------------------------------------------------------------");
	gotoxy(2,3);
	cprintf("SRN");
	gotoxy(6,3);
	cprintf("NAME");
	gotoxy(20,3);
	cprintf("PHONE");
	gotoxy(31,3);
	cprintf("EMAIL");
	gotoxy(54,3);
	cprintf("ADDRESS");
	gotoxy(73,3);
	cprintf("CATEGORY");

	gotoxy(1,4);
	cprintf("--------------------------------------------------------------------------------");
	i = 5;
	while((fread(&cnt1,sizeof(cnt1),1,ptr))!=NULL)
	{
		gotoxy(2,i);
		textcolor(11);
		cprintf("%s",cnt1.srn);
		gotoxy(6,i);
		textcolor(YELLOW);
		cprintf("%s",cnt1.name);
		gotoxy(20,i);
		textcolor(BLUE);
		cprintf("%s",cnt1.phone);
		gotoxy(31,i);
		textcolor(RED + WHITE);
		cprintf("%s",cnt1.email);
		gotoxy(54,i);
		textcolor(12);
		cprintf("%s",cnt1.addr);
		gotoxy(73,i);
		textcolor(YELLOW);
		cprintf("%s",cnt1.cate);

		i++;
	}
	gotoxy(2,i+1);
	textcolor(WHITE+BLINK);
	cprintf("Press any key to continue...");
	fclose(ptr);
	getch();
}
void ed_cnt()
{

}
void ser_cnt()
{

}
void del_cnt()
{

}
void cng_pass()
{
	FILE *ptr;
	char temp[20];
	char pass[20];

	password();
	clrscr();
	fgets(temp,10,ptr);
	gotoxy(35,16);
	cprintf("Enter New Password:");
	gotoxy(35,17);
	fflush(stdin);
	gets(pass);
	ptr = fopen("pass.dat","w");
	fputs(pass,ptr);
	gotoxy(35,20);
	textcolor(RED+BLINK);
	cprintf("Password Successfully changed");
	fclose(ptr);
	getch();
}

void password()
{
	FILE *ptr;
	char pass[20];
	char temp[20];
	char ch;
	int k,i;
	int choise;
	retry:
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();
	textcolor(11);

	ptr = fopen("pass.dat","r");
	gotoxy(30,15);
	cprintf("Password : ");
	gotoxy(45,15);
	fgets(pass,20,ptr);
	//cprintf("%s",pass);
	i=0;
	while(i<20)
	{

		ch = getch();
		if(ch == 13)
		{
			break;
		}
		else
		{
			temp[i] = ch;
			cprintf("*");
			i++;
		}
	 }
	 temp[i] = '\0';
	 fclose(ptr);
	//cprintf("%s",temp);
	i = 0;
	while(i<20)
	{
		if(strcmp(temp,pass)==0)
		{

			gotoxy(35,19);

			printf("correct password");
			menu();
			break;

		}
		else
		{
			gotoxy(35,19);

			printf("wrong password");
			goto retry;
		}
	}
}