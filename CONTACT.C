#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct cnt
{
	int srn;
	char phone[50];
	char addr[50];
	char email[50];
	char name[50];
	char cate[50];
} cnt1;
struct pas
{
	char pass[50];
}pas;
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
	int k, i;
	int choise;

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



	//password window
	password();

	while (1)
	{
		menu();
		scanf("%d", &choise);
		switch (choise)
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
	}
end:
	getch();
	return 0;
}
void menu()
{

	clrscr();

	window(1, 1, 80, 25);
	textbackground(BLACK);
	textcolor(RED);

	gotoxy(30, 9);
	textcolor(RED);
	cprintf("MAIN MENU");

	gotoxy(30, 10);
	textcolor(BLUE);
	cprintf("--------------------");
	textcolor(11);
	gotoxy(30, 11);
	cprintf("1 . Add New Contact");
	gotoxy(30, 12);
	cprintf("2 . Contact list");
	gotoxy(30, 13);
	cprintf("3 . Edit contact");
	gotoxy(30, 14);
	cprintf("4 . Delete contact");
	gotoxy(30, 15);
	cprintf("5 . Search Contact");
	gotoxy(30, 16);
	cprintf("6 . Change Password");
	gotoxy(30, 17);
	cprintf("7 . EXIT");
	textcolor(BLUE);
	gotoxy(30, 18);
	cprintf("--------------------");
	gotoxy(30, 19);
	textcolor(YELLOW);
	cprintf("Enter your choise !");
	gotoxy(30, 20);
}

void add_cnt()
{
	FILE *ptr1;

	clrscr();
	window(1, 1, 80, 25);
	textbackground(BLACK);
	textcolor(11);

	ptr1 = fopen("contact.dat", "a+b");
	gotoxy(5, 3);

	cprintf("Enter SRN. : ");
	gotoxy(20, 3);
	fflush(stdin);
	scanf("%d", &cnt1.srn);

	gotoxy(5, 4);
	cprintf("Enter Name : ");
	gotoxy(20, 4);
	fflush(stdin);
	gets(cnt1.name);

	gotoxy(5, 5);
	cprintf("Enter Phone: ");
	gotoxy(20, 5);
	fflush(stdin);

	gets(cnt1.phone);
	gotoxy(5, 6);
	cprintf("Enter Email: ");
	gotoxy(20, 6);
	fflush(stdin);
	gets(cnt1.email);

	gotoxy(5, 7);
	cprintf("Enter Address:");
	gotoxy(20, 7);
	fflush(stdin);

	gets(cnt1.addr);
	gotoxy(5, 8);
	cprintf("Enter Category(Friend/Home/Office) : ");
	gotoxy(45, 8);
	fflush(stdin);
	gets(cnt1.cate);
	fwrite(&cnt1, sizeof(cnt1), 1, ptr1);
	gotoxy(5, 10);
	textcolor(YELLOW);

	cprintf("Data added successfully... Press any key...");

	fclose(ptr1);
	getch();
}

void cnt_list()
{
	FILE *ptr;
	char temp[200];
	char ch;
	int pos, i;
	window(1, 1, 80, 25);
	textbackground(BLACK);
	textcolor(RED);
	clrscr();
	ptr = fopen("contact.dat", "rb");
	fseek(ptr, 0, SEEK_SET);
	gotoxy(1, 2);
	textcolor(11);
	cprintf("--------------------------------------------------------------------------------");
	gotoxy(2, 3);
	cprintf("SRN");
	gotoxy(6, 3);
	cprintf("NAME");
	gotoxy(20, 3);
	cprintf("PHONE");
	gotoxy(31, 3);
	cprintf("EMAIL");
	gotoxy(54, 3);
	cprintf("ADDRESS");
	gotoxy(73, 3);
	cprintf("CATEGORY");

	gotoxy(1, 4);
	cprintf("--------------------------------------------------------------------------------");
	i = 5;
	while ((fread(&cnt1, sizeof(cnt1), 1, ptr)) != NULL)
	{
		gotoxy(2, i);
		textcolor(11);
		cprintf("%d", cnt1.srn);
		gotoxy(6, i);
		textcolor(YELLOW);
		cprintf("%s", cnt1.name);
		gotoxy(20, i);
		textcolor(BLUE);
		cprintf("%s", cnt1.phone);
		gotoxy(31, i);
		textcolor(RED + WHITE);
		cprintf("%s", cnt1.email);
		gotoxy(54, i);
		textcolor(12);
		cprintf("%s", cnt1.addr);
		gotoxy(73, i);
		textcolor(YELLOW);
		cprintf("%s", cnt1.cate);

		i++;
	}
	gotoxy(2, i + 1);
	textcolor(WHITE + BLINK);
	cprintf("Press any key to continue...");
	fclose(ptr);
	getch();
}
void ed_cnt()
{
	FILE *ptr;
	int pos, found, n;
	window(1, 1, 80, 25);
	textbackground(BLACK);
	textcolor(YELLOW);
	clrscr();
	printf("EDIT CONTACT");
	printf("---------------------------------");
	printf("Enter serial no : \n");
	scanf("%d", &n);
	ptr = fopen("contact.dat", "r+b");
	found = 0;
	while (fread(&cnt1, sizeof(cnt1), 1, ptr) != NULL)
		;
	{
		if (cnt1.srn == n)
		{
			textcolor(11);
			found = 1;
			gotoxy(3, 3);
			cprintf("srn        :  %d", cnt1.srn);
			gotoxy(3, 4);
			cprintf("\nName     :  %s", cnt1.name);
			gotoxy(3, 5);
			cprintf("\nPhone    :  %s", cnt1.phone);
			gotoxy(3, 6);
			cprintf("\nEmail    :  %s", cnt1.email);
			gotoxy(3, 7);
			cprintf("\nAddress  :  %s", cnt1.addr);
			gotoxy(3, 8);
			cprintf("\nCategory :  %s", cnt1.cate);
		}
	}
	if (found == 0)
	{
		printf("DATA NOT FOUND");
		fclose(ptr);
		getch();
		return;
	}
	pos = ftell(ptr);
	fseek(ptr, pos - sizeof(cnt1), SEEK_SET);
	gotoxy(5, 13);

	cprintf("Enter SRN. : ");
	gotoxy(20, 13);
	fflush(stdin);
	scanf("%d", &cnt1.srn);

	gotoxy(5, 14);
	cprintf("Enter Name : ");
	gotoxy(20, 14);
	fflush(stdin);
	gets(cnt1.name);

	gotoxy(5, 15);
	cprintf("Enter Phone: ");
	gotoxy(20, 15);
	fflush(stdin);

	gets(cnt1.phone);
	gotoxy(5, 16);
	cprintf("Enter Email: ");
	gotoxy(20, 16);
	fflush(stdin);
	gets(cnt1.email);

	gotoxy(5, 17);
	cprintf("Enter Address:");
	gotoxy(20, 17);
	fflush(stdin);

	gets(cnt1.addr);
	gotoxy(5, 18);
	cprintf("Enter Category(Friend/Home/Office) : ");
	gotoxy(45, 18);
	fflush(stdin);
	gets(cnt1.cate);
	fwrite(&cnt1, sizeof(cnt1), 1, ptr);
	gotoxy(5, 19);
	textcolor(YELLOW);

	cprintf("Data added successfully... Press any key...");

	fclose(ptr);
	getch();
}
void ser_cnt()
{
	FILE *ptr;
	int found;

	int srn;
	char name[50];
	char phone[50];
	char addr[50];
	char email[50];
	char category[50];
	int ch;
	window(1, 1, 80, 25);
	textbackground(BLACK);
	textcolor(11);
	clrscr();
	ptr = fopen("contact.dat", "rb");
	found = 0;
	printf("Search by\n");
	printf("1.SRN\n");
	printf("2.NAME\n");
	printf("3.PHONE\n");
	printf("4.EMAIl\n");
	printf("5.ADDRESS\n");
	printf("6.CATEGORY\n");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
	{
		clrscr();
		printf("Search by srn\n");
		printf("Enter SRN\n ");
		scanf("%d", &srn);
		while (fread(&cnt1, sizeof(cnt1), 1, ptr) != NULL)
		{
			if (cnt1.srn == srn)

			{
				textcolor(11);
				found = 1;
				gotoxy(3, 3);
				cprintf("srn        :  %d", cnt1.srn);
				gotoxy(3, 4);
				cprintf("\nName     :  %s", cnt1.name);
				gotoxy(3, 5);
				cprintf("\nPhone    :  %s", cnt1.phone);
				gotoxy(3, 6);
				cprintf("\nEmail    :  %s", cnt1.email);
				gotoxy(3, 7);
				cprintf("\nAddress  :  %s", cnt1.addr);
				gotoxy(3, 8);
				cprintf("\nCategory :  %s", cnt1.cate);
				getch();
			}
		}
		if (found == 0)
		{
			printf("DATA NOT FOUND");
			fclose(ptr);

			getch();
			return;
		}
	}

	break;
	case 2:
	{
		clrscr();
		printf("Search by Name\n");
		printf("Enter Name\n ");
		fflush(stdin);

		gets(name);
		while (fread(&cnt1, sizeof(cnt1), 1, ptr) != NULL)
		{
			if (strcmp(cnt1.name, name) == 0)
			{
				textcolor(11);
				found = 1;
				gotoxy(3, 3);
				cprintf("srn        :  %d", cnt1.srn);
				gotoxy(3, 4);
				cprintf("\nName     :  %s", cnt1.name);
				gotoxy(3, 5);
				cprintf("\nPhone    :  %s", cnt1.phone);
				gotoxy(3, 6);
				cprintf("\nEmail    :  %s", cnt1.email);
				gotoxy(3, 7);
				cprintf("\nAddress  :  %s", cnt1.addr);
				gotoxy(3, 8);
				cprintf("\nCategory :  %s", cnt1.cate);
				getch();
			}
		}
		if (found == 0)
		{
			printf("DATA NOT FOUND");
			fclose(ptr);
			getch();
			return;
		}
	}

	break;
	case 3:
	{
		clrscr();
		printf("Search by Phone\n");
		printf("Enter Phone\n ");
		fflush(stdin);

		gets(phone);
		while (fread(&cnt1, sizeof(cnt1), 1, ptr) != NULL)
		{

			if (strcmp(cnt1.phone, phone) == 0)
			{
				textcolor(11);
				found = 1;
				gotoxy(3, 3);
				cprintf("srn        :  %d", cnt1.srn);
				gotoxy(3, 4);
				cprintf("\nName     :  %s", cnt1.name);
				gotoxy(3, 5);
				cprintf("\nPhone    :  %s", cnt1.phone);
				gotoxy(3, 6);
				cprintf("\nEmail    :  %s", cnt1.email);
				gotoxy(3, 7);
				cprintf("\nAddress  :  %s", cnt1.addr);
				gotoxy(3, 8);
				cprintf("\nCategory :  %s", cnt1.cate);
				getch();
			}
		}
		if (found == 0)
		{
			printf("DATA NOT FOUND");
			fclose(ptr);
			getch();
			return;
		}
	}
	break;
	case 4:
	{
		clrscr();
		printf("Search by Email\n");
		printf("Enter Email\n ");
		fflush(stdin);
		gets(email);
		while (fread(&cnt1, sizeof(cnt1), 1, ptr) != NULL)
		{

			if (strcmp(cnt1.email, email) == 0)
			{
				textcolor(11);
				found = 1;
				gotoxy(3, 3);
				cprintf("srn        :  %d", cnt1.srn);
				gotoxy(3, 4);
				cprintf("\nName     :  %s", cnt1.name);
				gotoxy(3, 5);
				cprintf("\nPhone    :  %s", cnt1.phone);
				gotoxy(3, 6);
				cprintf("\nEmail    :  %s", cnt1.email);
				gotoxy(3, 7);
				cprintf("\nAddress  :  %s", cnt1.addr);
				gotoxy(3, 8);
				cprintf("\nCategory :  %s", cnt1.cate);
				getch();

			}

			if (found == 0)
			{
				printf("DATA NOT FOUND");
				fclose(ptr);
				getch();
				return;
			}
		}
	}
	break;
	case 5:
	{
		clrscr();
		printf("Search by Address\n");
		printf("Enter Address\n ");
		fflush(stdin);
		gets(addr);
		while (fread(&cnt1, sizeof(cnt1), 1, ptr) != NULL)
		{

			if (strcmp(cnt1.addr, addr) == 0)
			{
				textcolor(11);
				found = 1;
				gotoxy(3, 3);
				cprintf("srn        :  %d", cnt1.srn);
				gotoxy(3, 4);
				cprintf("\nName     :  %s", cnt1.name);
				gotoxy(3, 5);
				cprintf("\nPhone    :  %s", cnt1.phone);
				gotoxy(3, 6);
				cprintf("\nEmail    :  %s", cnt1.email);
				gotoxy(3, 7);
				cprintf("\nAddress  :  %s", cnt1.addr);
				gotoxy(3, 8);
				cprintf("\nCategory :  %s", cnt1.cate);
				getch();
			}

			if (found == 0)
			{
				printf("DATA NOT FOUND");
				fclose(ptr);
				getch();
				return;
			}
		}
	}
	break;
	case 6:
	{

		clrscr();
		printf("Search by Category\n");
		printf("Enter Category(Friend/Home/Office)\n ");
		fflush(stdin);
		gets(category);
		while (fread(&cnt1, sizeof(cnt1), 1, ptr) != NULL)
		{
			if (strcmp(cnt1.cate, category) == 0)
			{
				textcolor(11);
				found = 1;
				gotoxy(3, 3);
				cprintf("srn        :  %d", cnt1.srn);
				gotoxy(3, 4);
				cprintf("\nName     :  %s", cnt1.name);
				gotoxy(3, 5);
				cprintf("\nPhone    :  %s", cnt1.phone);
				gotoxy(3, 6);
				cprintf("\nEmail    :  %s", cnt1.email);
				gotoxy(3, 7);
				cprintf("\nAddress  :  %s", cnt1.addr);
				gotoxy(3, 8);
				cprintf("\nCategory :  %s", cnt1.cate);
				getch();
			}

			if (found == 0)
			{
				printf("DATA NOT FOUND");
				fclose(ptr);
				getch();
				return;
			}
		}
	}
		fclose(ptr);
		getch();
	}
}
	void del_cnt()
	{
		FILE *ptr1, *ptr2;
		int n, found;
		char ch;
		window(1, 1, 80, 25);
		textbackground(BLACK);
		textcolor(YELLOW);
		clrscr();
		ptr1 = fopen("contact.dat", "rb");
		ptr2 = fopen("temp.dat", "wb");

		fseek(ptr1, 0, SEEK_SET);
		printf("Enter SRN \n");
		fflush(stdin);
		scanf("%d", &n);
		found = 0;
		while (fread(&cnt1, sizeof(cnt1), 1, ptr1) != NULL)
		{
			if (cnt1.srn == n)
			{
				printf("srn : %d", cnt1.srn);
				printf("\nName : %s", cnt1.name);
				printf("\nPhone : %s", cnt1.phone);
				printf("\nEmail : %s", cnt1.email);
				printf("\nAddress : %s", cnt1.addr);
				printf("\nCategory : %s", cnt1.cate);
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			textcolor(YELLOW);

			printf("data not found\n");
			getch();
			return;
		}

		printf("Do you want to delete it y/n?\n");
		ch = getche();
		if (ch == 'y' || ch == 'Y')
		{
			rewind(ptr1);
			while (fread(&cnt1, sizeof(cnt1), 1, ptr1) != NULL)
			{
				if (cnt1.srn != n)
				{
					fwrite(&cnt1, sizeof(cnt1), 1, ptr2);
				}
			}

			fclose(ptr1);
			fclose(ptr2);
			remove("contact.dat");
			rename("temp.dat", "contact.dat");
			getch();
			printf("\nData successfully deleted\n");
			getch();
		}
	}
	void cng_pass()
	{
		FILE *ptr;
		char temp[20];
		char pass[20];

		password();
		clrscr();
		fgets(temp, 10, ptr);
		gotoxy(35, 16);
		cprintf("Enter New Password:");
		gotoxy(35, 17);
		fflush(stdin);
		gets(pas.pass);
		ptr = fopen("pass.dat", "wb");
		fwrite(&pas,sizeof(pas),1,ptr);
		gotoxy(35, 20);
		textcolor(RED + BLINK);
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
		int k, i;
		int choise;
	retry:
		window(1, 1, 80, 25);
		textbackground(BLACK);
		clrscr();
		textcolor(11);

		ptr = fopen("pass.dat", "rb");
		gotoxy(30, 15);
		cprintf("Password : ");
		gotoxy(45, 15);
		//fgets(pass, 20, ptr);
		fread(&pas,sizeof(pas),1,ptr);
		//cprintf("%s",pass);
		i = 0;
		while (i < 20)
		{

			ch = getch();
			if (ch == 13)
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
		while (i < 20)
		{
			if (strcmp(temp, pas.pass) == 0)
			{

				gotoxy(35, 19);

				printf("correct password");
				menu();
				break;
			}
			else
			{
				gotoxy(35, 19);

				printf("wrong password");
				goto retry;
			}
		}
	}