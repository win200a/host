/*
Copyright (C) 2014-2015 Frank_feng Inc. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	time_t times;
	struct tm* nowtime;
	time(&times);
	nowtime = localtime(&times);
	clock_t start, end;
	double usetime;
	FILE*spare;
	spare = fopen("mysparepart", "r");
	if (spare == NULL)
	{
		system("copy \"C:\\Windows\\system32\\drivers\\etc\\hosts\" mysparepart");
		system("cls");
		system("attrib mysparepart +s +h +a +r");
	}
	puts("Copyright (C) 2014-2015 Frank_feng Inc. All rights reserved.");
	puts("Version:1.3");
	printf("Time   :%d/%d/%d %d:%d:%d\n", nowtime->tm_year + 1900, nowtime->tm_mon + 1, nowtime->tm_mday, nowtime->tm_hour, nowtime->tm_min, nowtime->tm_sec);
	puts("Enter the website that you want to prohibit.");
	char input[101];
	FILE *fp;
	fp = fopen("C:\\Windows\\system32\\drivers\\etc\\hosts", "a+");
	if (fp == NULL)
	{
		puts("WRONG!!!The Application cannot open the file");
		getch();
		exit(0);
	}
	fgets(input, 100, stdin);
	start = clock();
	if (strcmp(input, "\\accountlogin\n") == 0)
	{
		puts("Welcome");
		puts("Accountlogin:");
		printf("Account:");
		char account[50];
		fgets(account, 50, stdin);
		*(strchr(account, '\n')) = '\0';
		fflush(stdin);
		int i;
		char password[50] = {0};
		printf("Password:");
		for (i = 0; i < 50; i++)
		{
			password[i] = getch();
			if (password[i] == '\r')
			{
				password[i] = '\0';
				break;
			}
			else if (password[i] != '\b')
			{
				putchar('*');
			}
			else if (i != 0 && password[i] == '\b')
			{
				printf("\b \b");
				i--;
				i--;
			}
			else if (i==0)
			{
				i--;
			}
		}
		if ((strcmp(account,"zhangxianghenshuai")==0)&&(strcmp(password, "fengge8888") == 0))
		{
			while (1)
			{
				fflush(stdin);
				puts("\nEnter 1 is for returning your computer's sparepart.");
				puts("Enter 2 is for returning initial sparepart.");
				puts("Enter 3 is for covering your computer's sparepart.");
				puts("Enter 4 can prohibit the website that you want.(The application will exit)");
				puts("Enter 5 can open the hosts.");
				puts("Enter 6 can open the hosts by using notepad.");
				puts("Enter 7 can open the hosts'folder.");
				puts("Enter 8 to exit.");
				int i = 0;
				scanf_s("%d", &i, 1);
				fflush(stdin);
				if (i == 1)
				{
					system("attrib mysparepart -s -h -a -r");
					system("copy mysparepart \"C:\\Windows\\system32\\drivers\\etc\\hosts\"/Y");
					system("attrib mysparepart +s +h +a +r");
				}
				else if (i == 2)
				{
					system("attrib systemsparepart -s -h -a -r");
					system("copy systemsparepart \"C:\\Windows\\system32\\drivers\\etc\\hosts\"/Y");
					system("attrib systemsparepart +s +h +a +r");
				}
				else if (i == 3)
				{
					system("attrib mysparepart -s -h -a -r");
					system("copy \"C:\\Windows\\system32\\drivers\\etc\\hosts\" mysparepart /Y");
					system("attrib mysparepart +s +h +a +r");
				}
				else if (i == 4)
				{
					fgets(input, 100, stdin);
					start = clock();
					goto website;
				}
				else if (i == 5)
				{
					system("explorer \"C:\\Windows\\system32\\drivers\\etc\\hosts\"");
				}
				else if (i == 6)
				{
					system("notepad \"C:\\Windows\\system32\\drivers\\etc\\hosts\"");
				}
				else if (i == 7)
				{
					system("explorer \"C:\\Windows\\system32\\drivers\\etc\"");
				}
				else if (i == 8)
				{
					break;
				}
				else
				{
					puts("WRONG ENTER!!!");
				}
			}
		}
		else
		{
			puts("\nWRONG PASSWORD!!!");
		}
	}
	else
	{
		website:
		fprintf(fp, "\n127.0.0.1 %s", input);
		end = clock();
		usetime = (start - end) / CLOCKS_PER_SEC;
		printf("use time:%f", usetime);
	}
	getch();
}