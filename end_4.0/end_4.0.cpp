#include "stdafx.h"
#include <string.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <locale.h>
#include <iostream>
typedef struct name_surname
{
	char name[20]; //��� �������� , ������������ ������� 
	char surname[20]; //������� �������� , ������������ ������� 
	char work[20];//��� ������������
	name_surname *next;
} x;
typedef struct information
{
	char password[15]; // ������ ������������ 
	char login[15]; // ����� ������������ 
	information *next;
} y;
y adm = { "1", "1" };
typedef struct usluga
{
	char usluga_name[30]; //�������� ������ 
	int code_sdelki; //����������������� ��� ������ 
	int client_code; // �������������� ��� ������� 
	long int sum; //����� ������ 
	usluga *next;
} z;
typedef struct date
{
	int day; // ���� ���������� �������� 
	char month[20]; // ����� ���������� �������� 
	int year; // ��� ���������� �������� 
	date *next;
}date;
typedef struct Uchet
{
	x incl_ns;
	y incl_dat;
	z incl_dog;
}uchet;
x *begin = NULL;
x *end = NULL;
y *begin1 = NULL;
y *end1 = NULL;
z *begin2 = NULL;
z *end2 = NULL;
date *begin3 = NULL;
date *end3 = NULL;
int useri = 0;
char clear[] = { '\0' };
int i = 0;
int opn = 1;
int schit = 0;
void sort_menu();
void print_uslug();
void del_client();
void print_menu();
void add_client();
void add_uslug();
void edit_usluga();
void edit_client();
void print_client();
void registration();
int chislo();
void search_menu();
void filtr();
void task() {
	z *uslug = begin2;
	int nomer = 1;
	while (uslug != NULL) {
		uslug = uslug->next;
		nomer++;
	}
	if (nomer > 2) {
		uslug = begin2;
		int max;
		int h1, h2, h3;
		max = uslug->sum;
		while (uslug != NULL) {
			if (uslug->sum > max) {
				max = uslug->sum;
			}
			uslug = uslug->next;
		}
		h1 = max;
		uslug = begin2;
		max = uslug->sum;
		while (uslug != NULL) {
			if (uslug->sum > max && uslug->sum != h1) {
				max = uslug->sum;
			}
			uslug = uslug->next;
		}
		h2 = max;
		uslug = begin2;
		max = uslug->sum;
		while (uslug != NULL) {
			if (uslug->sum > max && uslug->sum != h1 && uslug->sum != h2) {
				max = uslug->sum;
			}
			uslug = uslug->next;

		}
		h3 = max;
		uslug = begin2;
		x*client = begin;
		date *dat = begin3;
		while (uslug->sum != h1) {
			uslug = uslug->next;
			client = client->next;
			dat = dat->next;
		}
		printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
		printf("| �  |  ��� ������  |   ��� �������   |        �������� ������       |  ����� ������ |     ��� �������    |   ������� �������  |      ����    |\n");
		printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
		printf("| 1. |%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", uslug->code_sdelki, uslug->client_code, uslug->usluga_name, uslug->sum, client->name, client->surname, dat->day, dat->month, dat->year);
		uslug = begin2;
		client = begin;
		dat = begin3;
		while (uslug->sum != h2) {
			uslug = uslug->next;
			client = client->next;
			dat = dat->next;
		}
		printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
		printf("| 2. |%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", uslug->code_sdelki, uslug->client_code, uslug->usluga_name, uslug->sum, client->name, client->surname, dat->day, dat->month, dat->year);
		uslug = begin2;
		client = begin;
		dat = begin3;
		while (uslug->sum != h3) {
			uslug = uslug->next;
			client = client->next;
			dat = dat->next;
		}
		printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
		printf("| 3. |%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", uslug->code_sdelki, uslug->client_code, uslug->usluga_name, uslug->sum, client->name, client->surname, dat->day, dat->month, dat->year);
		printf("`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");
		return;
	}
	else { system("cls"); printf("����������� ����� ������ 3\n"); return; }
}
void menu_filtr() {
	system("cls");
	printf("1.�����\n");
	printf("2.����������\n");
	printf("3.����� � ����\n");
	char a;
	a = _getch();
	switch (a) {
	case '1':search_menu(); break;
	case '2':filtr(); break;
	case '3':return; break;
	default:printf("�������� ������\n");
	}
}
int chislo() {
	char pot;
	char in[15];
	int g = 0;
	int i = 0;
	while (1) {
		do
			pot = _getch();
		while (!((pot >= 48 && pot <= 57) || pot == 8) && pot != 13);
		if (pot == 8 && i != 0) {
			i--;
			g = (g - in[i]) / 10;
			printf("\b");
			printf(" ");
			printf("\b");
		}
		if (i <= 14) {
			if (pot == 48) {
				g = g * 10 + 0;
				in[i] = 0;
				i++;
			}
			if (pot == 49) {
				g = g * 10 + 1;
				in[i] = 1;
				i++;
			}
			if (pot == 50) {
				g = g * 10 + 2;
				in[i] = 2;
				i++;
			}
			if (pot == 51) {
				g = g * 10 + 3;
				in[i] = 3;
				i++;
			}
			if (pot == 52) {
				g = g * 10 + 4;
				in[i] = 4;
				i++;
			}
			if (pot == 53) {
				g = g * 10 + 5;
				in[i] = 5;
				i++;
			}
			if (pot == 54) {
				g = g * 10 + 6;
				in[i] = 6;
				i++;
			}
			if (pot == 55) {
				g = g * 10 + 7;
				in[i] = 7;
				i++;
			}
			if (pot == 56) {
				g = g * 10 + 8;
				in[i] = 8;
				i++;
			}
			if (pot == 57) {
				g = g * 10 + 9;
				in[i] = 9;
				i++;
			}
			if (pot == 13) {
				return g;
				break;
			}
			if (pot != 8) {
				printf("%c", pot);
			}
		}
	}
	printf("\n");
	return g;
}
void filtr() {
	system("cls");
	printf("1.������� ������, ��������� ������� ������ � �������� �� � �� ��������� ����\n");
	printf("2.������� ������ ����������� ������ � ��������� ����\n");
	printf("3.����� � ����\n");
	char a;
	a = _getch();
	switch (a) {
	case '1': {
		if (begin2 != NULL) {
			int a, b;
			printf("������� �����, �� ������� ������ ����������: ");
			a = chislo();
			printf("\n");
			printf("������� �����, ������� ���������� ����������: ");
			b = chislo();
			printf("\n");
			if (a > b) {
				system("cls");
				printf("�� ����� ������������ ������(%d>%d)\n", a, b);
				return;
			}
			else {
				z * uslug = begin2;
				x * client = begin;
				date *dat = begin3;
				int kolvo = 1;
				printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
				printf("| �  |  ��� ������  |   ��� �������   |        �������� ������       |  ����� ������ |     ��� �������    |   ������� �������  |      ����    |\n");
				while (uslug != NULL) {
					if (uslug->sum >= a && uslug->sum <= b) {
						printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
						printf("|%4d|%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", kolvo, uslug->code_sdelki, uslug->client_code, uslug->usluga_name, uslug->sum, client->name, client->surname, dat->day, dat->month, dat->year);
						uslug = uslug->next;
						client = client->next;
						dat = dat->next;
						kolvo++;
					}
					else {
						uslug = uslug->next;
						client = client->next;
						dat = dat->next;
					}
				}
				printf("`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");
				return;
			}
		}
		else { system("cls"); printf("��� �����\n"); }break; }
	case '2': { if (begin2 != NULL) {
		printf("������� ���: ");
		int a;
		a = chislo();
		z * uslug = begin2;
		x * client = begin;
		date *dat = begin3;
		int kolvo = 1;
		printf("\n");
		printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
		printf("| �  |  ��� ������  |   ��� �������   |        �������� ������       |  ����� ������ |     ��� �������    |   ������� �������  |      ����    |\n");
		while (uslug != NULL) {
			if (dat->year == a) {
				printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
				printf("|%4d|%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", kolvo, uslug->code_sdelki, uslug->client_code, uslug->usluga_name, uslug->sum, client->name, client->surname, dat->day, dat->month, dat->year);
				uslug = uslug->next;
				client = client->next;
				dat = dat->next;
				kolvo++;
			}
			else {
				uslug = uslug->next;
				client = client->next;
				dat = dat->next;
			}
		}
		printf("`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");
		return;

	}
			  else { system("cls"); printf("��� �����\n"); } break; }
	case '3':return; break;
	default:printf("�������� ������\n"); return; break;
	}
}
bool name(char left[30], char right[30]) {
	return strcmp(left, right)>0;
}
bool surname(char left[30], char right[30]) {
	return strcmp(left, right) > 0;
}
bool work(char left[30], char right[30]) {
	return strcmp(left, right) > 0;
}
bool sum(long int left, long int right) {
	return left > right;
}
void sort_name(bool(*predicate)(char left[30], char right[30])) {
	x *client = begin;
	x *client1 = begin;
	z *uslug = begin2;
	z *uslug1 = begin2;
	date *dat = begin3;
	date *dat1 = begin3;
	while (client->next != NULL) {
		client1 = client->next;
		uslug1 = uslug->next;
		dat1 = dat->next;
		while (client1 != NULL) {
			if (predicate(client->name, client1->name)) {
				std::swap(client->name, client1->name);
				std::swap(client->surname, client1->surname);
				std::swap(client->work, client1->work);
				std::swap(uslug->usluga_name, uslug1->usluga_name);
				std::swap(uslug->code_sdelki, uslug1->code_sdelki);
				std::swap(uslug->client_code, uslug1->client_code);
				std::swap(uslug->sum, uslug1->sum);
				std::swap(dat->day, dat1->day);
				std::swap(dat->month, dat1->month);
				std::swap(dat->year, dat1->year);
			}
			client1 = client1->next;
			uslug1 = uslug1->next;
			dat1 = dat1->next;
		}
		client = client->next;
		dat = dat->next;
		uslug = uslug->next;
	}
	return;
}
void sort_surname(bool(*predicate)(char left[30], char right[30])) {
	x *client = begin;
	x *client1 = begin;
	z *uslug = begin2;
	z *uslug1 = begin2;
	date *dat = begin3;
	date *dat1 = begin3;
	while (client->next != NULL) {
		client1 = client->next;
		uslug1 = uslug->next;
		dat1 = dat->next;
		while (client1 != NULL) {
			if (predicate(client->surname, client1->surname)) {
				std::swap(client->surname, client1->surname);
				std::swap(client->name, client1->name);
				std::swap(client->work, client1->work);
				std::swap(uslug->usluga_name, uslug1->usluga_name);
				std::swap(uslug->code_sdelki, uslug1->code_sdelki);
				std::swap(uslug->client_code, uslug1->client_code);
				std::swap(uslug->sum, uslug1->sum);
				std::swap(dat->day, dat1->day);
				std::swap(dat->month, dat1->month);
				std::swap(dat->year, dat1->year);
			}
			client1 = client1->next;
			uslug1 = uslug1->next;
			dat1 = dat1->next;
		}
		client = client->next;
		dat = dat->next;
		uslug = uslug->next;
	}
	return;
}
void sort_work(bool(*predicate)(char left[30], char right[30])) {
	x *client = begin;
	x *client1 = begin;
	z *uslug = begin2;
	z *uslug1 = begin2;
	date *dat = begin3;
	date *dat1 = begin3;
	while (client->next != NULL) {
		client1 = client->next;
		uslug1 = uslug->next;
		dat1 = dat->next;
		while (client1 != NULL) {
			if (predicate(client->work, client1->work)) {
				std::swap(client->work, client1->work);
				std::swap(client->surname, client1->surname);
				std::swap(client->name, client1->name);
				std::swap(uslug->usluga_name, uslug1->usluga_name);
				std::swap(uslug->code_sdelki, uslug1->code_sdelki);
				std::swap(uslug->client_code, uslug1->client_code);
				std::swap(uslug->sum, uslug1->sum);
				std::swap(dat->day, dat1->day);
				std::swap(dat->month, dat1->month);
				std::swap(dat->year, dat1->year);
			}
			client1 = client1->next;
			uslug1 = uslug1->next;
			dat1 = dat1->next;
		}
		client = client->next;
		dat = dat->next;
		uslug = uslug->next;
	}
	return;
}
void sort_sum(bool(*predicate)(long int left, long int right)) {
	x *client = begin;
	x *client1 = begin;
	z *uslug = begin2;
	z *uslug1 = begin2;
	date *dat = begin3;
	date *dat1 = begin3;
	while (client->next != NULL) {
		client1 = client->next;
		uslug1 = uslug->next;
		dat1 = dat->next;
		while (client1 != NULL) {
			if (predicate(uslug->sum, uslug1->sum)) {
				std::swap(uslug->sum, uslug1->sum);
				std::swap(uslug->usluga_name, uslug1->usluga_name);
				std::swap(uslug->code_sdelki, uslug1->code_sdelki);
				std::swap(uslug->client_code, uslug1->client_code);
				std::swap(client->surname, client1->surname);
				std::swap(client->name, client1->name);
				std::swap(client->work, client1->work);
				std::swap(dat->day, dat1->day);
				std::swap(dat->month, dat1->month);
				std::swap(dat->year, dat1->year);
			}
			client1 = client1->next;
			uslug1 = uslug1->next;
			dat1 = dat1->next;
		}
		client = client->next;
		dat = dat->next;
		uslug = uslug->next;
	}
	return;
}
void sort_menu() {
	system("cls");
	printf("1.���������� ����� (�� ��������)\n");
	printf("2.���������� ������� (�� ��������)\n");
	printf("3.���������� �� ���� ������������� (�� ��������)\n");
	printf("4.���������� ���������� ����� �� ������� � �������\n");
	printf("5.����� � ����\n");
	char a;
	a = _getch();
	switch (a) {
	case '1':sort_name(name); break;
	case '2':sort_surname(surname); break;
	case '3':sort_work(work); break;
	case '4':sort_sum(sum); break;
	case '5':return; break;
	default:printf("�������� ������\n");
	}
}
void search_uslug() {
	if (begin2 != NULL) {
		system("cls");
		printf("1.����� �� �������� ������\n");
		printf("2.����� �� ���� ������\n");
		printf("3.����� � ����\n");
		char string[40];
		char o;
		o = _getch();
		switch (o) {
		case '1': {
			printf("������� �������� ������: ");
			char mas[40];
			char c;
			int i = 0;
			while (1)
			{
				do
				{
					c = _getch();
				} while (!(c >= -128 && c <= 0 || c == 32) && c != '\r' && c != '\b');

				if (c != '\r' && c != '\b' && i != 39)
				{
					mas[i] = c;
					i++;
					printf("%c", c);
				}
				else if (c == '\b' && i != 0)
				{
					printf("\b \b");
					i--;
				}
				else if (c == '\r' && i != 0)
					break;
			}
			mas[i] = '\0';
			puts("\r");
			strcpy_s(string, mas);
			int kolvo = 0;
			z *uslug = begin2;
			x *client = begin;
			date *dat = begin3;
			printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
			printf("| �  |  ��� ������  |   ��� �������   |        �������� ������       |  ����� ������ |     ��� �������    |   ������� �������  |      ����    |\n");
			while (uslug != NULL) {
				if (strcmp(uslug->usluga_name, string) == 0) {
					kolvo++;
					printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
					printf("|%4d|%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", kolvo, uslug->code_sdelki, uslug->client_code, uslug->usluga_name, uslug->sum, client->name, client->surname, dat->day, dat->month, dat->year);
					uslug = uslug->next;
					client = client->next;
					dat = dat->next;
				}
				else {
					uslug = uslug->next;
					client = client->next;
					dat = dat->next;
				}
			}
			printf("`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");
			if (kolvo < 1) {
				printf("���������� ���");
			}
			break; }
		case '2': {
			printf("������� ��� ������: ");
			int kod;
			kod = chislo();
			printf("\n");
			int kolvo = 0;
			z *uslug = begin2;
			x *client = begin;
			date *dat = begin3;
			printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
			printf("| �  |  ��� ������  |   ��� �������   |        �������� ������       |  ����� ������ |     ��� �������    |   ������� �������  |      ����    |\n");
			while (uslug != NULL) {
				if (uslug->code_sdelki == kod) {
					kolvo++;
					printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
					printf("|%4d|%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", kolvo, uslug->code_sdelki, uslug->client_code, uslug->usluga_name, uslug->sum, client->name, client->surname, dat->day, dat->month, dat->year);
					uslug = uslug->next;
					client = client->next;
					dat = dat->next;
				}
				else {
					uslug = uslug->next;
					client = client->next;
					dat = dat->next;
				}
			}
			printf("`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");
			if (kolvo < 1) {
				printf("���������� ���");
			}
			break; }
		case '3':return; break;
		default:system("cls"); printf("�������� ������");
		}
	}
	else printf("��� �����!");
}
void search_client() {
	if (begin != NULL) {
		system("cls");
		printf("1.����� �� �����\n");
		printf("2.����� �� �������\n");
		printf("3.����� �� ���� ������������\n");
		printf("4.����� � ����\n");
		char string[30];
		char o;
		o = _getch();
		switch (o) {
		case '1': {printf("������� ���: ");
			char mas[30];
			char c;
			int i = 0;
			while (1)
			{
				do
				{
					c = _getch();
				} while (!(c >= -128 && c <= 0) && c != '\r' && c != '\b');

				if (c != '\r' && c != '\b' && i != 29)
				{
					mas[i] = c;
					i++;
					printf("%c", c);
				}
				else if (c == '\b' && i != 0)
				{
					printf("\b \b");
					i--;
				}
				else if (c == '\r' && i != 0)
					break;
			}
			mas[i] = '\0';
			puts("\r");
			strcpy_s(string, mas);
			int h = 0;
			x *client = begin;
			if (begin != NULL) {
				printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
				printf("| �  |          ��� �������         |        ������� �������       |        ��� ������������      |\n");
				while (client != NULL) {
					if (strcmp(client->name, string) == 0) {
						printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
						h++;
						printf("|%3d.|%30s|%30s|%30s|\n", h, client->name, client->surname, client->work);
						client = client->next;
					}
					else { client = client->next; }
				}
				printf("```````````````````````````````````````````````````````````````````````````````````````````````````\n");
			}
			else {
				printf("��� ��������");
				return;
			}
			if (h < 1) {
				printf("���������� �� �������\n"); return;
			}
			printf("\n");
			return;
			break; }
		case '2': {printf("������� �������: ");
			char mas[30];
			char c;
			int i = 0;
			while (1)
			{
				do
				{
					c = _getch();
				} while (!(c >= -128 && c <= 0) && c != '\r' && c != '\b');

				if (c != '\r' && c != '\b' && i != 29)
				{
					mas[i] = c;
					i++;
					printf("%c", c);
				}
				else if (c == '\b' && i != 0)
				{
					printf("\b \b");
					i--;
				}
				else if (c == '\r' && i != 0)
					break;
			}
			mas[i] = '\0';
			puts("\r");
			strcpy_s(string, mas);
			int h = 0;
			x *client = begin;
			if (begin != NULL) {
				printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
				printf("| �  |          ��� �������         |        ������� �������       |        ��� ������������      |\n");
				while (client != NULL) {
					if (strcmp(client->surname, string) == 0) {
						printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
						h++;
						printf("|%3d.|%30s|%30s|%30s|\n", h, client->name, client->surname, client->work);
						client = client->next;
					}
					else { client = client->next; }
				}
				printf("```````````````````````````````````````````````````````````````````````````````````````````````````\n");
			}
			else {
				printf("��� ��������");
				return;
			}
			if (h < 1) {
				printf("���������� �� �������\n"); return;
			}
			printf("\n");
			return;
			break; }
		case '3': {printf("������� ��� ������������: ");
			char mas[30];
			char c;
			int i = 0;
			while (1)
			{
				do
				{
					c = _getch();
				} while (!(c >= -128 && c <= 0 || c == 32) && c != '\r' && c != '\b');

				if (c != '\r' && c != '\b' && i != 29)
				{
					mas[i] = c;
					i++;
					printf("%c", c);
				}
				else if (c == '\b' && i != 0)
				{
					printf("\b \b");
					i--;
				}
				else if (c == '\r' && i != 0)
					break;
			}
			mas[i] = '\0';
			puts("\r");
			strcpy_s(string, mas);
			int h = 0;
			x *client = begin;
			if (begin != NULL) {
				printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
				printf("| �  |          ��� �������         |        ������� �������       |        ��� ������������      |\n");
				while (client != NULL) {
					if (strcmp(client->work, string) == 0) {
						printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
						h++;
						printf("|%3d.|%30s|%30s|%30s|\n", h, client->name, client->surname, client->work);
						client = client->next;
					}
					else { client = client->next; }
				}
				printf("```````````````````````````````````````````````````````````````````````````````````````````````````\n");
			}
			else {
				printf("��� ��������");
				return;
			}
			if (h < 1) {
				printf("���������� �� �������\n"); return;
			}
			printf("\n");
			return;
			break; }
		case '4':system("cls"); return; break;
		default:printf("�������� ������");
		}
	}
	else {
		system("cls"); printf("��� ��������\n"); return;
	}
}
void search_menu() {
	system("cls");
	printf("1.����� �� ��������\n");
	printf("2.����� �� �������\n");
	printf("3.����� � ����\n");
	char a;
	a = _getch();
	switch (a) {
	case '1':search_client(); break;
	case '2':search_uslug(); break;
	case '3':system("cls"); return; break;
	default:printf("�������� ������\n");
	}
}
void del_client() {
	x *p = begin;
	int m = 0;
	printf("������ ��������\n");
	if (begin != NULL) {
		printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
		printf("| �  |          ��� �������         |        ������� �������       |        ��� ������������      |\n");
		while (p != NULL) {
			m++;
			printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
			printf("|%3d.|%30s|%30s|%30s|\n", m, p->name, p->surname, p->work);
			p = p->next;
		}
		printf("```````````````````````````````````````````````````````````````````````````````````````````````````\n");
	}
	else {
		printf("��� ��������");
		return;
	}
	x *client = begin;
	z *uslug = begin2;
	date *dat = begin3;
	printf("�������� �������, �������� ������ �������:");
	int nomer;
	int schet = 1;
	nomer = chislo();
	x *previous = NULL;
	z *prev = NULL;
	date *pr = NULL;
	if (nomer <= m && nomer>0 && nomer != 0) {
		while (schet != nomer) {
			previous = client;
			prev = uslug;
			pr = dat;
			client = client->next;
			uslug = uslug->next;
			dat = dat->next;
			schet++;
		}
		if (previous != NULL) {
			previous->next = client->next;
			prev->next = uslug->next;
			pr->next = dat->next;
		}
		if (begin == client) {
			begin = begin->next;
			begin2 = begin2->next;
			begin3 = begin3->next;
		}
		delete client;
		delete uslug;
		delete dat;
		printf("\n������ %d ������\n", nomer);
		return;
	}
	else {
		printf("\n������ ������� ���\n"); return;
	}
}
void print_menu() {
	system("cls");
	printf("1.������� ������ ������� � �������\n");
	printf("2.������� ������ �� ������� � �������\n");
	printf("3.����� � ����\n");
	char a;
	a = _getch();
	switch (a) {
	case '1':print_client(); break;
	case '2':print_uslug(); break;
	case '3':system("cls"); return; break;
	default:printf("�������� ������\n");
	}
}
void open() {
	if (schit == 0) {
		schit = 1;
		FILE *fp;
		int length, i = 0, j = 0;
		fopen_s(&fp, "������ � ��������.txt", "rb+");
		fseek(fp, 0, 2);
		length = ftell(fp);
		rewind(fp);

		if (length > 0)
		{
			while (i == 0)
			{
				x *client = new x;
				if (fread(&(*client), sizeof(x), 1, fp) == 0)
				{
					i++;
				}
				else
				{
					if (j == 0)
					{
						client->next = NULL;
						begin = client;
						end = begin;
					}
					if (j > 0)
					{
						client->next = NULL;
						end->next = client;
						end = client;
					}
				}
				j++;
			}
		}
		fclose(fp);
		FILE *us;
		i = 0, j = 0;
		fopen_s(&us, "������ �� �������.txt", "rb+");
		fseek(us, 0, 2);
		length = ftell(us);
		rewind(us);

		if (length > 0)
		{
			while (i == 0)
			{
				z *uslug = new z;
				if (fread(&(*uslug), sizeof(z), 1, us) == 0)
				{
					i++;
				}
				else
				{
					if (j == 0)
					{
						uslug->next = NULL;
						begin2 = uslug;
						end2 = begin2;
					}
					if (j > 0)
					{
						uslug->next = NULL;
						end2->next = uslug;
						end2 = uslug;
					}
				}
				j++;
			}
		}
		fclose(us);
		FILE *dt;
		i = 0, j = 0;
		fopen_s(&dt, "������ � ����.txt", "rb+");
		fseek(dt, 0, 2);
		length = ftell(dt);
		rewind(dt);

		if (length > 0)
		{
			while (i == 0)
			{
				date *dat = new date;
				if (fread(&(*dat), sizeof(date), 1, dt) == 0)
				{
					i++;
				}
				else
				{
					if (j == 0)
					{
						dat->next = NULL;
						begin3 = dat;
						end3 = begin3;
					}
					if (j > 0)
					{
						dat->next = NULL;
						end3->next = dat;
						end3 = dat;
					}
				}
				j++;
			}
		}
		fclose(dt);
		FILE *usr;
		i = 0, j = 0;
		fopen_s(&usr, "������ � �������������.txt", "rb+");
		fseek(usr, 0, 2);
		length = ftell(usr);
		rewind(dt);
		if (length > 0)
		{
			while (i == 0)
			{
				y *user = new y;
				if (fread(&(*user), sizeof(y), 1, usr) == 0)
				{
					i++;
				}
				else
				{
					if (j == 0)
					{
						user->next = NULL;
						begin1 = user;
						end1 = begin1;
					}
					if (j > 0)
					{
						user->next = NULL;
						end1->next = user;
						end1 = user;
					}
				}
				j++;
			}
		}
		fclose(usr);
	}
	else {
		system("cls"); printf("�� ��� ��������� ������ �� �����\n"); return;
	}
}
void save() {
	FILE *fp;
	fopen_s(&fp, "������ � ��������.txt", "wb+");
	x *client = begin;
	while (client != NULL)
	{
		fwrite(&(*client), sizeof(x), 1, fp);
		client = client->next;
	}
	fclose(fp);
	FILE *us;
	fopen_s(&us, "������ �� �������.txt", "wb+");
	z *uslug = begin2;
	while (uslug != NULL)
	{
		fwrite(&(*uslug), sizeof(z), 1, us);
		uslug = uslug->next;
	}
	fclose(us);
	FILE *dt;
	fopen_s(&dt, "������ � ����.txt", "wb+");
	date *dat = begin3;
	while (dat != NULL)
	{
		fwrite(&(*dat), sizeof(date), 1, dt);
		dat = dat->next;
	}
	fclose(dt);
	FILE *usr;
	fopen_s(&usr, "������ � �������������.txt", "wb+");
	y *user = begin1;
	while (user != NULL)
	{
		fwrite(&(*user), sizeof(y), 1, usr);
		user = user->next;
	}
	fclose(usr);
}
void add_menu() {
	system("cls");
	printf("1.�������� �������\n");
	printf("2.�������� ������\n");
	printf("3.����� � ����\n");
	char a;
	a = _getch();
	switch (a) {
	case '1':add_client(); break;
	case '2':add_uslug(); break;
	case '3':system("cls"); return; break;
	default:printf("�������� ������\n");
	}
}
void edit_client() {
	system("cls");
	int nomer;
	x *p = begin;
	int m = 1;
	printf("������ ��������\n");
	if (begin != NULL) {
		printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
		printf("| �  |          ��� �������         |        ������� �������       |        ��� ������������      |\n");
		while (p != NULL) {
			printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
			printf("|%3d.|%30s|%30s|%30s|\n", m, p->name, p->surname, p->work);
			p = p->next;
			m++;
		}
		printf("```````````````````````````````````````````````````````````````````````````````````````````````````\n");
	}
	else {
		printf("��� ��������\n");
		return;
	}
	printf("�������� �������, ������ �������� ������ �������������:");
	int kolvo = 1;
	x *client = begin;
	nomer = chislo();
	m = m - 1;
	if (nomer <= m && nomer != 0) {
		printf("\n1.������������� ��� �������\n");
		printf("2.������������� ������� �������\n");
		printf("3.������������� ������������ �������\n");
		printf("4.�������� � ����� � ����");
		char vibor;
		vibor = _getch();
		switch (vibor) {
		case '1':
			while (kolvo != nomer) {
				client = client->next;
				kolvo++;
			}
			printf("\n������ ��� %s\n", client->name);
			printf("������� ����� ���:");
			gets_s(client->name);
			printf("\n������ ������� ���������������\n"); break;
		case '2':	while (kolvo != nomer) {
			client = client->next;
			kolvo++;
		}
					printf("\n������ ������� %s\n", client->surname);
					printf("������� ����� �������:");
					gets_s(client->surname);
					printf("\n������ ������� ���������������\n"); break;
		case '3':	while (kolvo != nomer) {
			client = client->next;
			kolvo++;
		}
					printf("\n������ ��� ������������ %s\n", client->work);

					printf("������� ����� ��� ������������:");
					gets_s(client->work);
					printf("\n������ ������� ���������������\n"); break;
		case '4':system("cls"); return; break;
		default:printf("�������� 1 �� ��������� ���������\n");
		}
	}
	else printf("\n�������� ������ �� ��������� ��������\n");
}
void edit_usluga() {
	system("cls");
	int kolvo = 1;
	z *uslug1 = begin2;
	x *client = begin;
	date *dat = begin3;
	if (begin2 != NULL) {
		printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
		printf("| �  |  ��� ������  |   ��� �������   |        �������� ������       |  ����� ������ |     ��� �������    |   ������� �������  |      ����    |\n");
		while (uslug1 != NULL) {
			if (uslug1->sum == 0) {
				uslug1 = uslug1->next;
				client = client->next;
				dat = dat->next;
			}
			else {
				printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
				printf("|%4d|%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", kolvo, uslug1->code_sdelki, uslug1->client_code, uslug1->usluga_name, uslug1->sum, client->name, client->surname, dat->day, dat->month, dat->year);
				uslug1 = uslug1->next;
				client = client->next;
				dat = dat->next;
				kolvo++;
			}
		}
		printf("``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");
	}
	else {
		printf("��� ��������� �����\n");
		return;
	}
	printf("�������� ����� ������, � ������� �� ������ ������������� ������:");
	int nomer;
	nomer = chislo();
	kolvo--;
	char vibor;
	z *uslug = begin2;
	if (nomer <= kolvo && nomer != 0) {
		printf("\n1.������������� �������� ������\n");
		printf("2.������������� ��� ������\n");
		printf("3.������������� ��� �������\n");
		printf("4.������������� ����� ������\n");
		printf("5.�������� � ����� � ����");
		kolvo = 1;
		vibor = _getch();
		switch (vibor) {
		case '1': {
			while (kolvo != nomer) {
				uslug = uslug->next;
				kolvo++;
			}
			printf("\n������ �������� ������ %s\n", uslug->usluga_name);
			printf("������� ����� �������� ������:");
			char usl[31];
			char c;
			int i = 0;
			while (1)
			{
				do
				{
					c = _getch();
				} while (!(c >= -128 && c <= 0 || c == 32) && c != '\r' && c != '\b');

				if (c != '\r' && c != '\b' && i != 29)
				{
					usl[i] = c;
					i++;
					printf("%c", c);
				}
				else if (c == '\b' && i != 0)
				{
					printf("\b \b");
					i--;
				}
				else if (c == '\r' && i != 0)
					break;
			}
			usl[i] = '\0';
			puts("\r");
			strcpy_s(uslug->usluga_name, usl);
			printf("\n������ ������� ���������������\n"); break; }
		case '2': {
			while (kolvo != nomer) {
				uslug = uslug->next;
				kolvo++;
			}
			printf("\n������ ��� ������ %d\n", uslug->code_sdelki);
			int hr = 0;
			printf("������� ����� ��� ������: ");
			while (true) {
				z *g = begin2;
				uslug->code_sdelki = chislo();
				if (uslug->code_sdelki == 0) {
					printf("\n��� ������ �� ����� ���� ����� 0\n");
				}
				if (uslug->code_sdelki < 0) {
					printf("\n��� ������ �� ����� ���� �������������\n");
				}
				hr = 0;
				while (g != NULL) {
					if (g->code_sdelki == uslug->code_sdelki) {
						hr++;
						if (hr != 1) {
							printf("���� ��� ������ ��� �����, ������� ������\n");
							break;
						}
					}
					g = g->next;
				}
				if (hr == 1) {
					break;
				}
			}
			printf("\n");
			hr = 0;
			printf("\n������ ������� ���������������\n"); break; }
		case '3': {
			int hr = 0;
			while (kolvo != nomer) {
				uslug = uslug->next;
				kolvo++;
			}
			printf("\n������ ��� ������� %d\n", uslug->client_code);
			while (true) {
				z *j = begin2;
				uslug->client_code = chislo();
				if (uslug->client_code == 0) {
					printf("\n��� ������� �� ����� ���� ����� 0\n");
				}
				if (uslug->client_code < 0) {
					printf("\n��� ������� �� ����� ���� �������������\n");
				}
				hr = 0;
				while (j != NULL) {
					if (j->client_code == uslug->client_code) {
						hr++;
						if (hr != 1) {
							printf("���� ��� ������� ��� �����, ������� ������\n");
							break;
						}
					}
					j = j->next;
				}
				if (hr == 1) {
					break;
				}
			}
			hr = 0;
			printf("\n");
			printf("������ ������� ���������������\n"); break; }
		case '4': {
			while (kolvo != nomer) {
				uslug = uslug->next;
				kolvo++;
			}
			printf("\n������ ����� ������ %d\n", uslug->sum);
			printf("������� ����� ����� ������:");
			while (true) {
				char pot;
				char in[9];
				long int  g = 0;
				int i = 0;
				while (1) {
					do
						pot = _getch();
					while (!((pot >= 48 && pot <= 57) || pot == 8) && pot != 13);
					if (pot == 8 && i != 0) {
						i--;
						g = (g - in[i]) / 10;
						printf("\b");
						printf(" ");
						printf("\b");
					}
					if (i <= 8) {
						if (pot == 48) {
							g = g * 10 + 0;
							in[i] = 0;
							i++;
						}
						if (pot == 49) {
							g = g * 10 + 1;
							in[i] = 1;
							i++;
						}
						if (pot == 50) {
							g = g * 10 + 2;
							in[i] = 2;
							i++;
						}
						if (pot == 51) {
							g = g * 10 + 3;
							in[i] = 3;
							i++;
						}
						if (pot == 52) {
							g = g * 10 + 4;
							in[i] = 4;
							i++;
						}
						if (pot == 53) {
							g = g * 10 + 5;
							in[i] = 5;
							i++;
						}
						if (pot == 54) {
							g = g * 10 + 6;
							in[i] = 6;
							i++;
						}
						if (pot == 55) {
							g = g * 10 + 7;
							in[i] = 7;
							i++;
						}
						if (pot == 56) {
							g = g * 10 + 8;
							in[i] = 8;
							i++;
						}
						if (pot == 57) {
							g = g * 10 + 9;
							in[i] = 9;
							i++;
						}
						if (pot == 13) {
							uslug->sum = g;
							break;
						}
						if (pot != 8 && i != 9) {
							printf("%c", pot);
						}
					}
					if (pot == 13) {
						uslug->sum = g;
						break;
					}
				}
				break;
			}
			printf("\n������ ������� ���������������\n"); break; }
		case '5':system("cls"); return; break;
		default:printf("");
		}
	}
	else printf("\n�������� ���� �� ��������� �����\n");
}
void edit_menu() {
	system("cls");
	printf("1.������������� ������ �������\n");
	printf("2.������������� ������\n");
	printf("3.����� � ����\n");
	char a;
	a = _getch();
	switch (a) {
	case '1':edit_client(); break;
	case '2':edit_usluga(); break;
	case '3':system("cls"); return; break;
	default:printf("�������� ������\n");
	}
}
void del_user() {
	if (begin1 != NULL) {
		y *user = begin1;
		int kolvo = 1;
		printf("|```|```````````````|```````````````|\n");
		printf("| � |     �����     |     ������    |\n");
		printf("|```|```````````````|```````````````|\n");
		while (user != NULL) {
			printf("|```|```````````````|```````````````|\n");
			printf("|%3d|%15s|%15s|\n", kolvo, user->login, user->password);
			user = user->next;
			kolvo++;
		}
		printf("`````````````````````````````````````\n");
	}
	else {
		printf("�������� ���� �� ������ ������������\n");
		return;
	}
	printf("�������� ������������, �������� ������ �������:");
	int nomer;
	int schet = 1;
	y *user = begin1;
	nomer = chislo();
	y *previous = NULL;
	if (nomer <= useri && nomer != 0) {
		user = begin1;
		while (schet != nomer) {
			previous = user;
			user = user->next;
			schet++;
		}
		if (previous != NULL) {
			previous->next = user->next;
		}
		if (begin1 == user) { begin1 = begin1->next; }
		delete user;
		printf("������������ %d ������\n", nomer);
		useri = useri - 1;
		return;
	}
	else {
		printf("������ ������������ ���\n"); return;
	}
}
void edit_user() {
	int kolvo = 1;
	if (begin1 != NULL) {
		y *user = begin1;
		printf("|```|```````````````|```````````````|\n");
		printf("| � |     �����     |     ������    |\n");
		printf("|```|```````````````|```````````````|\n");
		while (user != NULL) {
			printf("|```|```````````````|```````````````|\n");
			printf("|%3d|%15s|%15s|\n", kolvo, user->login, user->password);
			user = user->next;
			kolvo++;
		}
		printf("`````````````````````````````````````\n");
	}
	else {
		printf("�������� ���� �� ������ ������������\n");
		return;
	}
	printf("�������� ������������, ������ �������� �� ������ ��������:");
	printf("\n");
	int a;
	a = chislo();
	kolvo--;
	if (a <= kolvo) {
		printf("\n1.�������� ����� ������������\n");
		printf("2.�������� ������ ������������\n");
		char u;
		u = _getch();
		switch (u) {
		case '1':
		{
			y *user = begin1;
			int nomer = 1;
			while (nomer != a) {
				user = user->next;
				nomer++;
			}
			printf("������� ����� �����:");
			char log[16];
			char c;
			int i = 0;
			while (1)
			{
				do
				{
					c = _getch();
				} while (!(c >= -128 && c <= 128) && c != '\r' && c != '\b');

				if (c != '\r' && c != '\b' && i != 19)
				{
					log[i] = c;
					i++;
					printf("%c", c);
				}
				else if (c == '\b' && i != 0)
				{
					printf("\b \b");
					i--;
				}
				else if (c == '\r' && i != 0)
					break;
			}
			log[i] = '\0';
			puts("\r");
			strcpy_s(user->login, log);
			return;
		}
		case '2': {
			y *user = begin1;
			int nomer = 1;
			while (nomer != a) {
				user = user->next;
				nomer++;
			}
			printf("������� ����� ������:");
			char pas[16];
			char c;
			int i = 0;
			while (1)
			{
				do
				{
					c = _getch();
				} while (!(c >= -128 && c <= 128) && c != '\r' && c != '\b');

				if (c != '\r' && c != '\b' && i != 19)
				{
					pas[i] = c;
					i++;
					printf("%c", c);
				}
				else if (c == '\b' && i != 0)
				{
					printf("\b \b");
					i--;
				}
				else if (c == '\r' && i != 0)
					break;
			}
			pas[i] = '\0';
			puts("\r");
			strcpy_s(user->password, pas);
			return;
		}
		default:printf("������� ���������� ������"); break;
		}
	}
	else printf("�������� ������ �� ��������� �������������\n");
	return;
}
void print_user() {
	if (begin1 != NULL) {
		y *user = begin1;
		int kolvo = 1;
		printf("|```|```````````````|```````````````|\n");
		printf("| � |     �����     |     ������    |\n");
		printf("|```|```````````````|```````````````|\n");
		while (user != NULL) {
			printf("|```|```````````````|```````````````|\n");
			printf("|%3d|%15s|%15s|\n", kolvo, user->login, user->password);
			user = user->next;
			kolvo++;
		}
		printf("`````````````````````````````````````\n");
		return;
	}
	else {
		printf("�������� ���� �� ������ ������������\n");
		return;
	}
}
void controluser() {
	system("cls");
	printf("1.���������� ������ ������������\n");
	printf("2.�������� ���� �������������\n");
	printf("3.�������������� �������������\n");
	printf("4.�������� �������������\n");
	printf("5.����� � ����\n");
	char q;
	q = _getch();
	switch (q) {
	case '1':registration(); break;
	case '2':print_user(); break;
	case '3':edit_user(); break;
	case '4':del_user(); break;
	case '5':system("cls"); return; break;
	default:printf("������� ������ ������"); break;
	}
}
void registration() {
	if (begin1 == NULL) {
		y *user = new y;
		printf("������� ��� �����\n");
		char log[16];
		char c;
		int i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 128) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 14)
			{
				log[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		log[i] = '\0';
		puts("\r");
		strcpy_s(user->login, log);
		printf("������� ��� ������\n");
		char pas[16];
		i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 128) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 14)
			{
				pas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		pas[i] = '\0';
		puts("\r");
		strcpy_s(user->password, pas);
		user->next = NULL;
		begin1 = end1 = user;
		printf("������������ ������� ��������!\n");
		useri++;
		return;
	}
	else {
		y *user = new y;
		printf("������� ��� �����\n");
		char log[16];
		char c;
		int i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 128) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 14)
			{
				log[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		log[i] = '\0';
		puts("\r");
		strcpy_s(user->login, log);
		printf("������� ��� ������\n");
		char pas[16];
		i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 128) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 14)
			{
				pas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		pas[i] = '\0';
		puts("\r");
		strcpy_s(user->password, pas);
		user->next = NULL;
		end1->next = user;
		end1 = user;
		printf("������������ ������� ��������!\n");
		useri++;
		return;
	}
}
void print_uslug() {
	int kolvo = 1;
	z *uslug = begin2;
	x *client = begin;
	date *dat = begin3;
	if (begin2 != NULL) {
		printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
		printf("| �  |  ��� ������  |   ��� �������   |        �������� ������       |  ����� ������ |     ��� �������    |   ������� �������  |      ����    |\n");
		while (uslug != NULL) {
			if (uslug->sum == 0) {
				uslug = uslug->next;
				client = client->next;
				dat = dat->next;
			}
			else {
				printf("|````|``````````````|`````````````````|``````````````````````````````|```````````````|````````````````````|````````````````````|``````````````|\n");
				printf("|%4d|%14d|%17d|%30s|%15d|%20s|%20s|%2d%8s%4d|\n", kolvo, uslug->code_sdelki, uslug->client_code, uslug->usluga_name, uslug->sum, client->name, client->surname, dat->day, dat->month, dat->year);
				uslug = uslug->next;
				client = client->next;
				dat = dat->next;
				kolvo++;
			}
		}
		printf("``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n");
		return;
	}
	else {
		printf("��� ��������� �����\n");
		return;
	}
}
void add_uslug() {
	x *p = begin;
	int m = 1;
	printf("������ ��������\n");
	if (begin != NULL) {
		printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
		printf("| �  |          ��� �������         |        ������� �������       |        ��� ������������      |\n");
		while (p != NULL) {
			printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
			printf("|%3d.|%30s|%30s|%30s|\n", m, p->name, p->surname, p->work);
			p = p->next;
			m++;
		}
		printf("```````````````````````````````````````````````````````````````````````````````````````````````````\n");
	}
	else {
		printf("��� ��������");
		return;
	}
	printf("�������� ����� �������, �������� ����� ������� ������:");
	m = m - 1;
	int nomer;
	int kolvo = 1;
	nomer = chislo();
	x *client = begin;
	z *uslug = begin2;
	date *dat = begin3;
	printf("\n");
	if (begin != NULL) {
		if (nomer <= m && nomer != 0) {
			while (kolvo != nomer) {
				uslug = uslug->next;
				client = client->next;
				dat = dat->next;
				kolvo++;
			}
			if (uslug->sum == 0) {
				printf("������� �������� ������:");
				char usl[31];
				char c;
				int i = 0;
				while (1)
				{
					do
					{
						c = _getch();
					} while (!(c >= -128 && c <= 0 || c == 32) && c != '\r' && c != '\b');

					if (c != '\r' && c != '\b' && i != 29)
					{
						usl[i] = c;
						i++;
						printf("%c", c);
					}
					else if (c == '\b' && i != 0)
					{
						printf("\b \b");
						i--;
					}
					else if (c == '\r' && i != 0)
						break;
				}
				usl[i] = '\0';
				puts("\r");
				strcpy_s(uslug->usluga_name, usl);
				int hr = 0;
				printf("������� ��� ������: ");
				while (true) {
					z *g = begin2;
					uslug->code_sdelki = chislo();
					if (uslug->code_sdelki == 0) {
						printf("\n��� ������ �� ����� ���� ����� 0\n");
					}
					if (uslug->code_sdelki < 0) {
						printf("\n��� ������ �� ����� ���� �������������\n");
					}
					hr = 0;
					while (g != NULL) {
						if (g->code_sdelki == uslug->code_sdelki) {
							hr++;
							if (hr != 1) {
								printf("���� ��� ������ ��� �����, ������� ������\n");
								break;
							}
						}
						g = g->next;
					}
					if (hr == 1) {
						break;
					}
				}
				printf("\n");
				hr = 0;
				printf("������� ��� �������: ");
				while (true) {
					z *j = begin2;
					uslug->client_code = chislo();
					if (uslug->client_code == 0) {
						printf("\n��� ������� �� ����� ���� ����� 0\n");
					}
					if (uslug->client_code < 0) {
						printf("\n��� ������� �� ����� ���� �������������\n");
					}
					hr = 0;
					while (j != NULL) {
						if (j->client_code == uslug->client_code) {
							hr++;
							if (hr != 1) {
								printf("���� ��� ������� ��� �����, ������� ������\n");
								break;
							}
						}
						j = j->next;
					}
					if (hr == 1) {
						break;
					}
				}
				printf("\n");
				printf("������� ����� ������:");
				while (uslug->sum <= 0) {
					char pot;
					char in[9];
					long int  g = 0;
					int i = 0;
					while (1) {
						do
							pot = _getch();
						while (!((pot >= 48 && pot <= 57) || pot == 8) && pot != 13);
						if (pot == 8 && i != 0) {
							i--;
							g = (g - in[i]) / 10;
							printf("\b");
							printf(" ");
							printf("\b");
						}
						if (i <= 8) {
							if (pot == 48) {
								g = g * 10 + 0;
								in[i] = 0;
								i++;
							}
							if (pot == 49) {
								g = g * 10 + 1;
								in[i] = 1;
								i++;
							}
							if (pot == 50) {
								g = g * 10 + 2;
								in[i] = 2;
								i++;
							}
							if (pot == 51) {
								g = g * 10 + 3;
								in[i] = 3;
								i++;
							}
							if (pot == 52) {
								g = g * 10 + 4;
								in[i] = 4;
								i++;
							}
							if (pot == 53) {
								g = g * 10 + 5;
								in[i] = 5;
								i++;
							}
							if (pot == 54) {
								g = g * 10 + 6;
								in[i] = 6;
								i++;
							}
							if (pot == 55) {
								g = g * 10 + 7;
								in[i] = 7;
								i++;
							}
							if (pot == 56) {
								g = g * 10 + 8;
								in[i] = 8;
								i++;
							}
							if (pot == 57) {
								g = g * 10 + 9;
								in[i] = 9;
								i++;
							}
							if (pot == 13) {
								uslug->sum = g;
								break;
							}
							if (pot != 8 && i != 9) {
								printf("%c", pot);
							}
						}
						if (pot == 13) {
							uslug->sum = g;
							break;
						}
					}
					if (uslug->sum == 0) {
						printf("\n���� ������ �� ����� ���� ����� 0\n");
					}
					if (uslug->sum < 0) {
						printf("\n����� �� ����� ���� �������������\n");
					}
				}
				printf("\n");
				printf("������� ���� ���������� ������: ");
				while (!(dat->day >= 1 && dat->day <= 31)) {
					dat->day = chislo();
					if (!(dat->day >= 1 && dat->day <= 31)) {
						printf("\n��� ������ ���\n");
					}
				}
				printf("\n");
				printf("������� ����� ���������� ������: ");
				char mon[10];
				i = 0;
				while (1)
				{
					do
					{
						c = _getch();
					} while (!(c >= -128 && c <= 0) && c != '\r' && c != '\b');

					if (c != '\r' && c != '\b' && i != 9)
					{
						mon[i] = c;
						i++;
						printf("%c", c);
					}
					else if (c == '\b' && i != 0)
					{
						printf("\b \b");
						i--;
					}
					else if (c == '\r' && i != 0)
						break;
				}
				mon[i] = '\0';
				puts("\r");
				strcpy_s(dat->month, mon);
				printf("������� ��� ���������� ������: ");
				while (!(dat->year >= 2000 && dat->year <= 2100)) {
					dat->year = chislo();
					if (!(dat->year >= 2000 && dat->year <= 2100)) {
						printf("\n������� ���������� ������\n");
					}
				}
				printf("\n");
				printf("������� %s %s � ����� %d ������� ��������� ������ %s � ����� %d ������ %d\n", client->name, client->surname, uslug->client_code, uslug->usluga_name, uslug->code_sdelki, uslug->sum);
				printf("���� ���������� ������ %d %s %d ����\n", dat->day, dat->month, dat->year);
				return;
			}
			else {
				system("cls"); printf("� ����� ������� ��� ���� ����������� ������\n");
			}
		}
		else {
			printf("������ ������� ���\n"); return;
		}
	}
	else {
		printf("�������� ���� �� 1 ������� ��� ���������� �����\n"); return;
	}
}
void print_client() {
	x *p = begin;
	int m = 1;
	printf("������ ��������\n");
	if (begin != NULL) {
		printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
		printf("| �  |          ��� �������         |        ������� �������       |        ��� ������������      |\n");
		while (p != NULL) {
			printf("|````|``````````````````````````````|``````````````````````````````|``````````````````````````````|\n");
			printf("|%3d.|%30s|%30s|%30s|\n", m, p->name, p->surname, p->work);
			p = p->next;
			m++;
		}
		printf("```````````````````````````````````````````````````````````````````````````````````````````````````\n");
	}
	else printf("��� ��������");
	return;
}
void add_client() {
	if (begin == NULL) {
		x *p = new x;
		printf("������� ��� �������:");
		char mas[30];
		char c;
		int i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 0) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 29)
			{
				mas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		mas[i] = '\0';
		puts("\r");
		strcpy_s(p->name, mas);
		printf("������� ������� �������:");
		char mas1[30];
		i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 0) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 29)
			{
				mas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		mas[i] = '\0';
		puts("\r");
		strcpy_s(p->surname, mas);
		printf("������� ��� ������������:");
		char mas2[30];
		i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 0 || c == 32) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 29)
			{
				mas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		mas[i] = '\0';
		puts("\r");
		strcpy_s(p->work, mas);
		p->next = NULL;
		begin = end = p;
		printf("������ %s %s ������� ���������������\n", p->name, p->surname);
		z *uslug = new z;
		strcpy_s(uslug->usluga_name, clear);
		uslug->code_sdelki = 0;
		uslug->client_code = 0;
		uslug->sum = 0;
		uslug->next = NULL;
		begin2 = end2 = uslug;
		date *dat = new date;
		strcpy_s(dat->month, clear);
		dat->day = 0;
		dat->year = 0;
		dat->next = NULL;
		begin3 = end3 = dat;
	}
	else {
		x *p = new x;
		z *uslug = new z;
		printf("������� ��� �������:");
		char mas[30];
		char c;
		int i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 0) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 29)
			{
				mas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		mas[i] = '\0';
		puts("\r");
		strcpy_s(p->name, mas);
		printf("������� ������� �������:");
		char mas1[30];
		i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 0) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 29)
			{
				mas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		mas[i] = '\0';
		puts("\r");
		strcpy_s(p->surname, mas);
		printf("������� ��� ������������:");
		char mas2[30];
		i = 0;
		while (1)
		{
			do
			{
				c = _getch();
			} while (!(c >= -128 && c <= 0 || c == 32) && c != '\r' && c != '\b');

			if (c != '\r' && c != '\b' && i != 29)
			{
				mas[i] = c;
				i++;
				printf("%c", c);
			}
			else if (c == '\b' && i != 0)
			{
				printf("\b \b");
				i--;
			}
			else if (c == '\r' && i != 0)
				break;
		}
		mas[i] = '\0';
		puts("\r");
		strcpy_s(p->work, mas);
		p->next = NULL;
		end->next = p;
		end = p;
		printf("������ %s %s ������� ���������������\n", p->name, p->surname);
		strcpy_s(uslug->usluga_name, clear);
		uslug->code_sdelki = 0;
		uslug->client_code = 0;
		uslug->sum = 0;
		uslug->next = NULL;
		end2->next = uslug;
		end2 = uslug;
		date *dat = new date;
		strcpy_s(dat->month, clear);
		dat->day = 0;
		dat->year = 0;
		dat->next = NULL;
		end3->next = dat;
		end3 = dat;
	}
}
void user() {
	system("cls");
	while (1) {
		printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_����_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
		printf("1.����� ������ � ��������� ����\n");
		printf("2.����������\n");
		printf("3.����� \n");
		printf("4.���������� ������\n");
		printf("5.����� � ����\n");
		char m;
		m = _getch();
		switch (m) {
		case '1':print_menu(); break;
		case '2':filtr(); break;
		case '3':search_menu(); break;
		case '4':system("cls"); task(); break;
		case '5':system("cls"); return; break;
		default:system("cls"); printf("������� ���������� ������\n"); break;
		}
	}
}
void admin() {
	while (1) {
		printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_����_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
		printf("1.����������\n");
		printf("2.����� ������ � ��������� ����\n");
		printf("3.�������� \n");
		printf("4.�����/����������\n");
		printf("5.����������\n");
		printf("6.��������������\n");
		printf("7.���������� ��������������\n");
		printf("8.���������� � ����\n");
		printf("9.�������� ������ �� �����\n");
		printf("0.����� � ����\n");
		char m;
		m = _getch();
		switch (m) {
		case '1':add_menu(); break;
		case '2':print_menu(); break;
		case '3':del_client(); break;
		case '4':menu_filtr(); break;
		case '5':sort_menu(); break;
		case '7':controluser(); break;
		case '6':edit_menu(); break;
		case '8':save(); break;
		case '9':open(); break;
		case '0':system("cls"); return; break;
		default: printf("������� ���������� ������\n"); break;
		}
	}
}
int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_����_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
		printf("1.���� � ������� ��������������\n");
		printf("2.���� � ������� ������������\n");
		printf("3.����� �� ���������\n");
		char c, log[15], par[15];
		c = _getch();
		switch (c) {
		case '1': {
			printf("������� �����\n");
			char s = 1;
			int h = 0;
			while (true) {
				s = _getch();
				if (s == 13) {
					break;
				}
				if (h <= 13) {
					if (s == 8 && h != 0) {
						printf("\b");
						printf(" ");
						printf("\b");
						log[h] = '\0';
						h--;
					}
					else {
						if (s != 8) {
							printf("%c", s);
							log[h] = s;
							h++;
						}
					}
				}
			}
			log[h] = '\0';
			printf("\n");
			printf("������� ������\n");
			h = 0;
			while (true) {
				s = _getch();
				if (s == 13) {
					break;
				}
				if (h <= 13) {
					if (s == 8 && h != 0) {
						printf("\b");
						printf(" ");
						printf("\b");
						par[h] = '\0';
						h--;
					}
					else {
						if (s != 8) {
							printf("*");
							par[h] = s;
							h++;
						}
					}
				}
			}
			par[h] = '\0';
			printf("\n");
			if ((strcmp(log, adm.login) == 0) && (strcmp(par, adm.password) == 0)) {
				printf("\n");
				system("cls");
				admin();
			}
			else printf("������� ������ ����� ��� ������, ����� ��������������� ������� ��������������\n");
			break; }
		case '2': {
			if (begin1 != NULL) {
				char logi[15], pass[15];
				system("cls"); printf("������� �����: ");
				char log[15];
				char q;
				int schet = 0;
				while (1)
				{
					do
					{
						q = _getch();
					} while (!(q >= -128 && q <= 129) && q != '\r' && q != '\b');

					if (q != '\r' && q != '\b' && schet != 14)
					{
						log[schet] = q;
						schet++;
						printf("%c", q);
					}
					else if (q == '\b' && schet != 0)
					{
						printf("\b \b");
						schet--;
					}
					else if (q == '\r' && schet != 0)
						break;
				}
				log[schet] = '\0';
				puts("\r");
				strcpy_s(logi, log);
				printf("������� ������: ");
				char pas[15];
				schet = 0;
				while (1)
				{
					do
					{
						q = _getch();
					} while (!(q >= -128 && q <= 129) && q != '\r' && q != '\b');

					if (q != '\r' && q != '\b' && schet != 14)
					{
						pas[schet] = q;
						schet++;
						printf("%c", q);
					}
					else if (q == '\b' && schet != 0)
					{
						printf("\b \b");
						schet--;
					}
					else if (q == '\r' && schet != 0)
						break;
				}
				pas[schet] = '\0';
				puts("\r");
				strcpy_s(pass, pas);
				y *usr = begin1;
				int sch = 0;
				while (usr != NULL) {
					if (strcmp(usr->login, logi) == 0 && strcmp(usr->password, pass) == 0) {
						sch++;
						usr = usr->next;
					}
					else {
						usr = usr->next;
					}
				}
				if (sch == 1) {
					system("cls"); printf("�� ������� ����� ��� �������������\n");
					user();
				}
				else
					printf("�� ����� �������� ����� ��� ������\n");
			}
			else printf("�� �� ���������������� �� ������ ������������\n");
			break; }
		case '3':
			exit(0);
			break;
		default: printf("������� ���������� ������\n");
		}
	}
}