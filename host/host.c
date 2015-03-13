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
int main(void)
{
	FILE*spare;
	spare = fopen("mysparepart", "r");
	if (spare == NULL)
	{
		system("copy \"C:\\Windows\\system32\\drivers\\etc\\hosts\" mysparepart");
		system("cls");
		system("attrib mysparepart +s +h +a +r");
	}
	puts("Copyright (C) 2014-2015 Frank_feng Inc. All rights reserved.");
	char input[101];
	FILE *fp;
	fp = fopen("C:\\Windows\\system32\\drivers\\etc\\hosts", "a+");
	if (fp == NULL)
	{
		puts("WRONG!");
		getch();
		exit(0);
	}
	fgets(input, 100, stdin);
	if (strcmp(input, "professionaltools\n") == 0)
	{
		system("attrib mysparepart -s -h -a -r");
		system("copy mysparepart \"C:\\Windows\\system32\\drivers\\etc\\hosts\"/Y");
		system("attrib mysparepart +s +h +a +r");
	}
	else if (strcmp(input, "professionaltools1\n") == 0)
	{
		system("attrib systemsparepart -s -h -a -r");
		system("copy systemsparepart \"C:\\Windows\\system32\\drivers\\etc\\hosts\"/Y");
		system("attrib systemsparepart +s +h +a +r");
	}
	else
	{
		fprintf(fp, "\n129.0.0.1 %s", input);
	}
	getch();
}