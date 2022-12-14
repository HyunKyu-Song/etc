#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>

#define N 100
#define MAX 55
#define STD_NUM 51

typedef struct student{
	char name[20];
	int num;
	char hometown[20];
	char food[N];
	char music[N];
	char movie[N];
	char exercise[N];
	char game[N];
	char drink[50];
	char hobby[50];
	char interest[50];
	char alcohol[30];
	char propensity[30];
	char season[30];
	int balance[6];
}STD;

typedef struct list{
	STD arr[MAX];
	int cnt;
}List;

typedef struct load{
	STD arr[MAX];
	int cnt;
}Load_List;

void admin(void);  
void menu(void); 
void now(void);
int catagory(void);

void Init(List *list, Load_List *load);  
void Insert(List *list);  
void fail(void);  
void Load(List *list, Load_List *load);  
void Load_Print(Load_List *load);   

int password(void);

void manual(void);

void ex(void);
int balance(int arr[]);

void Random_Matching(Load_List *load);

void Current_State(Load_List *load);

int Search(Load_List *load);
void Search_Name(Load_List *load, int n);

int std_hometown(Load_List *load, char str[]);
int std_food(Load_List *load, char str[]);
int std_music(Load_List *load, char str[]);
int std_movie(Load_List *load, char str[]);
int std_exercise(Load_List *load, char str[]);
int std_game(Load_List *load, char str[]);
int std_drink(Load_List *load, char str[]);
int std_hobby(Load_List *load, char str[]);
int std_interest(Load_List *load, char str[]);
int std_alcohol(Load_List *load, char str[]);
int std_propensity(Load_List *load, char str[]);
int std_season(Load_List *load, char str[]);

char* hometown(void);
char* food(void);
char* music(void);
char* movie(void);
char* exercise(void);
char* game(void);
char* drink(void);
char* hobby(void);
char* interest(void);
char* alcohol(void);
char* propensity(void);
char* season(void);

int item(Load_List *load, int num); 
void std_data(Load_List *load, int n);


int main(void){
	
	List list;
	Load_List load;
	int select, num;
	char *p;
	
	Init(&list, &load);
	Load(&list, &load);
	
	while(1)
	{
		system("cls");
		menu();
		
		printf("????: ");
		scanf("%d", &select);
		
		system("cls");
		
		switch(select)
		{
			case 0:
				if(password())
				{
					admin();
					
					printf("\n????: ");
					scanf("%d", &select);
					system("cls");
					
					if(select == 1)
						Load_Print(&load);
					else if(select == 2)
						Insert(&list);
					else if(select == 3)
						Load(&list, &load);
				}
				break;
			case 1:
				num = catagory();
				if(num == -1)
					fail();
				else
				{
					num = item(&load, num);
					if(num == 0)
						;
					else if(num == -1)
						fail();
					else
						std_data(&load, num);
				}
				break;
			case 2:
				num = Search(&load);
				Search_Name(&load, num);
				break;
			case 3:
				Random_Matching(&load);
				break;
			case 4:
				Current_State(&load);
				break;
			case 5:
				manual(); 
				break;	
			case 6:
				system("cls");
				printf("\n\n\n\n================================\n\n");
				printf(" - ?????????? ?????????????? -\n\n");
				printf("================================\n\n\n\n\n");
				break;
			default:
				fail();
		}
		if(select == 6)
			break;
		printf("\nEnter...");
		fflush(stdin);
		getch();
	}
	
	return 0;
}

void Init(List *list, Load_List *load)
{
	(list->cnt) = 1;
	(load->cnt) = 1;
}

void Insert(List *list)
{
	char s[N];
	int i;
		
	printf("\n==============[Insert]==================\n\n");
	printf("  < ???? ???? >\n");
	printf("\n  ????: ");
	scanf("%d", &list->arr[list->cnt].num); 
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].name, s);
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].hometown, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].food, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].music, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].movie, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].exercise, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].game, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].drink, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].hobby, s);
	
	fflush(stdin);
	
	printf("  ??????: ");
	gets(s);
	strcpy(list->arr[list->cnt].interest, s);
	
	fflush(stdin);
	
	printf("  ??: ");
	gets(s);
	strcpy(list->arr[list->cnt].alcohol, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].propensity, s);
	
	fflush(stdin);
	
	printf("  ????: ");
	gets(s);
	strcpy(list->arr[list->cnt].season, s);
	
	printf("  ?????? ????: ");
	for(i = 0; i < 6; i++)
		scanf("%d", &list->arr[list->cnt].balance[i]);
		
	printf("\n========================================\n");
	
	FILE *fp = NULL;
	fp=fopen("Student_Data.txt","a+");
	
	fprintf(fp,"%s %d %s %s %s %s %s %s %s %s %s %s %s %s ",
		list->arr[list->cnt].name, list->arr[list->cnt].num, list->arr[list->cnt].hometown, list->arr[list->cnt].food, 
		list->arr[list->cnt].music, list->arr[list->cnt].movie, list->arr[list->cnt].exercise, list->arr[list->cnt].game, 
		list->arr[list->cnt].drink, list->arr[list->cnt].hobby, list->arr[list->cnt].interest, list->arr[list->cnt].alcohol, 
		list->arr[list->cnt].propensity, list->arr[list->cnt].season);
	
	for(i = 0; i < 6; i++)
		fprintf(fp, "%d ", list->arr[list->cnt].balance[i]);
		
	fprintf(fp, "\n");
	
	fclose(fp);
	
	(list->cnt)++;
}

void fail(void)
{
	printf("\n\n\n\n================================\n\n");
	printf("     - ?????? ?????????? -\n\n");
	printf("================================\n\n");
}

void Load(List *list, Load_List *load)
{
	int num, i, j;
	
	FILE *fp = NULL;
	fp=fopen("Student_Data.txt","r+");
	
	for(i = 1; i <= STD_NUM; i++)
	{
		fscanf(fp,"%s %d %s %s %s %s %s %s %s %s %s %s %s %s ", 
		list->arr[i].name, &(list->arr[i].num), list->arr[i].hometown, list->arr[i].food, 
		list->arr[i].music, list->arr[i].movie, list->arr[i].exercise, list->arr[i].game, 
		list->arr[i].drink, list->arr[i].hobby, list->arr[i].interest, list->arr[i].alcohol, 
		list->arr[i].propensity, list->arr[i].season);
		
		for(j = 0; j < 6; j++)
			fscanf(fp, "%d ", &(list->arr[i].balance[j]));
	}
	
	for(i = 1; i <= STD_NUM; i++)
	{
		strcpy(load->arr[i].name, list->arr[i].name);
		load->arr[i].num = list->arr[i].num;
		strcpy(load->arr[i].hometown, list->arr[i].hometown);
		strcpy(load->arr[i].food, list->arr[i].food);
		strcpy(load->arr[i].music, list->arr[i].music);
		strcpy(load->arr[i].movie, list->arr[i].movie);
		strcpy(load->arr[i].exercise, list->arr[i].exercise);
		strcpy(load->arr[i].game, list->arr[i].game);
		strcpy(load->arr[i].drink, list->arr[i].drink);
		strcpy(load->arr[i].hobby, list->arr[i].hobby);
		strcpy(load->arr[i].interest, list->arr[i].interest);
		strcpy(load->arr[i].alcohol, list->arr[i].alcohol);
		strcpy(load->arr[i].propensity, list->arr[i].propensity);
		strcpy(load->arr[i].season, list->arr[i].season);
		
		for(j = 0; j < 6; j++)
			load->arr[i].balance[j] = list->arr[i].balance[j];
	}
	
	fclose(fp);
	
	printf("\n\n=======================================\n\n");
	printf("       ?? ???? Loading ???? ??\n\n");
	printf("=======================================\n");
}

void Load_Print(Load_List *load)
{
	int i, j;
	
	for(i = 1; i <= STD_NUM; i++)
	{
		printf("\n\n=========================================\n");
		printf("\n\t< ???? ???? >\n\n");
		printf("=========================================\n");
		printf("????????   %s\n", load->arr[i].name);
		printf("----------------------------------------\n");
		printf("????????   %d\n", load->arr[i].num);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].hometown);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].food);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].music);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].movie);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].exercise);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].game);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].drink);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].hobby);
		printf("----------------------------------------\n");
		printf("?????????? %s\n", load->arr[i].interest);
		printf("----------------------------------------\n");
		printf("??????     %s\n", load->arr[i].alcohol);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].propensity);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[i].season);
		printf("----------------------------------------\n");
		printf("?????????? ");
		for(j = 0; j < 6; j++)
			printf("%d ", load->arr[i].balance[j]);
		printf("\n=========================================\n\n");
	}
}

void admin(void)
{
	printf("\n -------------------------------\n");
	printf("|                               |\n"); 
	printf("|   < ?????? ???? >             |\n");
	printf("|                               |\n");
	printf("|                               |\n");  
	printf("| [1] ???? ???? ????            |\n");
	printf("|                               |\n");
	printf("| [2] ???? ???? ????            |\n");
	printf("|                               |\n");
	printf("| [3] ???? Load (???? ????????) |\n");
	printf("|                               |\n");
	printf(" -------------------------------\n");
}

void menu(void)
{
	printf("\n");
	printf("==================================\n");
	now();
	printf("==================================\n");
	
	printf("\n\n  ?? ???????? ????~ ??\n\n");
	printf("  ???? ???? ?????? ?????????\n\n");
	printf("----------------------------------\n");
	printf("|   < ?????? ???? >              |\n");
	printf("|                                |\n"); 
	printf("| [0] ?????? ????                |\n");
	printf("----------------------------------\n");
	printf("|                                |\n");
	printf("|   < ?????? ???? >              |\n");
	printf("|                                |\n");
	printf("| [1] Category ????              |\n");
	printf("|                                |\n");
	printf("| [2] ???????? ????              |\n");
	printf("|                                |\n");
	printf("| [3] ???? ????                  |\n");
	printf("|                                |\n");
	printf("| [4] ???? ????                  |\n");
	printf("|                                |\n");
	printf("| [5] ???????? ???? ?? ??????    |\n");
	printf("|                                |\n");
	printf("| [6] ???????? ????              |\n");
	printf("----------------------------------\n\n");
}

void now(void)
{
	struct tm *t;
	char *day[7] = {"??????", "??????", "??????", "??????", "??????", "??????", "??????"}; //?????? ???? 
	
	time_t timer;
	
	timer = time(NULL);
	t = localtime(&timer);
	
	printf("     %d?? %d?? %d?? %s\n\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, day[t->tm_wday]);
	printf("     ????????: %d?? %d?? %d??\n", t->tm_hour, t->tm_min, t->tm_sec);
}

int catagory(void)
{
	int n;
	system("cls");
	
	printf("\n	     < Category ???? >\n\n");
	printf("---------------------------------------------\n");
	printf("[1]  ????	");
	printf("[2]  ????	");
	printf("[3]  ????   |\n");
	printf("                                            |\n");
	printf("[4]  ????	");
	printf("[5]  ????	");
	printf("[6]  ????   |\n");
	printf("                                            |\n");
	printf("[7]  ????	");
	printf("[8]  ????	");
	printf("[9]  ?????? |\n");
	printf("                                            |\n");
	printf("[10] ??		");
	printf("[11] ????	");
	printf("[12] ????   |\n");
	printf("---------------------------------------------\n\n");
	
	printf("????: ");
	scanf("%d", &n);
	
	if(n >= 1 && n <=12)
		return n;
	else
		return -1;
}

int password(void)
{
	int i=0;
	char pw[50];
	char c;
	
	printf("\n\n  password: ");
	
	while(1)
	{
		c = getch();
		
		if(c == 13)
		{
			pw[i] = '\0';
			break;
		}
		else
		{
			printf("*");
			pw[i] = c;
		}
		i++;
	}
	
	if(strcmp(pw, "comedu5115") == 0)
	{
		system("cls");
		return 1;
	}
	else
	{
		system("cls");
		printf("\n\n?? ???????? ??\n\n");
		return 0;
	}
}

void std_data(Load_List *load, int n)
{
	int res=0;
	
	res = balance(load->arr[n].balance);
	system("cls");
	
	if(res >= 3)
	{
		printf("\n\n=========================================\n");
		printf("\n\t< ???? ???? >\n\n");
		printf("=========================================\n");
		printf("????????   %s\n", load->arr[n].name);
		printf("----------------------------------------\n");
		printf("????????   %d\n", load->arr[n].num);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].hometown);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].food);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].music);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].movie);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].exercise);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].game);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].drink);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].hobby);
		printf("----------------------------------------\n");
		printf("?????????? %s\n", load->arr[n].interest);
		printf("----------------------------------------\n");
		printf("??????     %s\n", load->arr[n].alcohol);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].propensity);
		printf("----------------------------------------\n");
		printf("????????   %s\n", load->arr[n].season);
		printf("=========================================\n\n");
	}
	else
		printf("\n\n?????? ????????...\n\n");
}

void manual(void)
{
	printf("\n==============[Manual]==================\n\n");
	printf("  < ???????? ???? ?? ?????? >\n\n\n");
	printf("????????\n\n");
	printf(" ???????????? '???????? ????~'??????.\n\n");
	printf(" ?????? ???? ???????? ???? ?????? ?????? ???? ????????\n\n");
	printf(" ?????? ?????? ?? ?? ?? ???? ?????? ?? ???? ???? ??????\n\n");
	printf(" ???????? ????????????.\n\n\n");
	printf("??????????\n\n");
	printf("-------------------------------------------\n");
	printf("?? ?????????? Setting ?? ???? ????\n\n");
	printf("   Setting: '?????? ????' -> '???? Load' ??\n\n");
	printf("   [?????? ????]?? ???? ???? ????\n");
	printf("-------------------------------------------\n\n");
	printf(" 1. ?????????? ???? ?????? ???? ?? ?????? ???? ??????.\n\n");
	printf(" 2. ?????? ???????? ?????? ????????.\n\n");
	printf(" 3. ???????? ?????? ???? ?????? ???? ???????? ????.\n\n\n");
	printf("===========================================================\n"); 
	printf(" ?????????????? ???? ?????? ??????, ?????? ?????? ??????.\n");
	printf("===========================================================\n");
}

void ex(void)
{
	system("cls");
	
	printf("\n----------------- < ?????? ???? > -----------------\n\n");
	printf("   2 ???? ?????? ?? ?????? ?????? ???? ????\n\n");
	printf("   6?? ?? ?????? ?????? 3?? ???? ??????\n\n");
	printf("   ?????? ?????? ???? ?????? ???? ?? ????????.\n\n");
	printf("   ??????, ?????? 3?? ???????? ?????? ????????...\n");
	printf("\n---------------------------------------------------\n\n\n");
}

int balance(int arr[])
{
	int select=0, cnt=0, i=0;
	
	system("cls");
	printf("\n???? ?????? ?????? ?????? ?? ?????? ???????? ?????? ?????? ??????????.\n");
	printf("\nEnter?? ???????? ?????? ??????????. ");
	getch(); 
	
	ex();
	printf("--------------------\n");
	printf("[1] ????\n");
	printf("--------------------\n");
	printf("[2] ????\n");
	printf("--------------------\n");
	printf("????: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;
	
	ex();
	printf("--------------------\n");
	printf("[1] ????\n");
	printf("--------------------\n");
	printf("[2] ??????\n");
	printf("--------------------\n");
	printf("????: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;
	
	ex();
	printf("----------------------\n");
	printf("[1] ?????? ??????????\n");
	printf("----------------------\n");
	printf("[2] ?????? ??????????\n");
	printf("----------------------\n");
	printf("????: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;

	ex();
	printf("----------------------\n");
	printf("[1] ???? 1?? ????\n");
	printf("----------------------\n");
	printf("[2] ?????? 4?? ????\n");
	printf("----------------------\n");
	printf("????: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;

	ex();
	printf("--------------------\n");
	printf("[1] ???? ????\n");
	printf("--------------------\n");
	printf("[2] ???????? ????\n");
	printf("--------------------\n");
	printf("????: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;
	
	ex();
	printf("----------------------------------\n");
	printf("[1] ?????? ?????????? ?????? ????\n");
	printf("----------------------------------\n");
	printf("[2] ?????? ???????? ?????? ??????\n");
	printf("----------------------------------\n");
	printf("????: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	
	return cnt;
}

void Random_Matching(Load_List *load)
{	
	int n, res, i, select;
	int arr[6] = {0};
	
	system("cls");
	
	printf("\n==============[Random_Matching]==================\n\n");
	printf("  < ???? ???? >\n\n");
	printf("Enter?? ???????? ???????? ??????????. ");
	fflush(stdin);
	getchar();
	
	srand((unsigned)time(NULL));
	
	n = 1+rand()%STD_NUM;
	printf("\n?????? ????: [ %s ]\n\n\n", load->arr[n].name);
	
	printf("--------------------------\n");
	printf("[1] ?????? ???? ???? ????\n");
	printf("--------------------------\n");
	printf("[2] ???????????? ????????\n");   
	printf("--------------------------\n");
	printf("????: ");
	scanf("%d", &select);
	
	if(select == 1)
	{
		res = balance(load->arr[n].balance);
	    system("cls");
	
		if(res >= 3)
		{
			printf("\n\n=========================================\n");
			printf("\n\t< ???? ???? >\n\n");
			printf("=========================================\n");
			printf("????????   %s\n", load->arr[n].name);
			printf("----------------------------------------\n");
			printf("????????   %d\n", load->arr[n].num);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].hometown);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].food);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].music);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].movie);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].exercise);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].game);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].drink);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].hobby);
			printf("----------------------------------------\n");
			printf("?????????? %s\n", load->arr[n].interest);
			printf("----------------------------------------\n");
			printf("??????     %s\n", load->arr[n].alcohol);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].propensity);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].season);
			printf("=========================================\n\n");
		}
		else
			printf("\n\n?????? ????????...\n\n");
	}
	else if(select == 2)
		;
}

void Current_State(Load_List *load)
{
	int first_grader, second_grader, third_grader, fourth_grader, others_grader;
	int i, num;
	
	first_grader = 0; second_grader = 0; third_grader = 0; fourth_grader = 0; others_grader = 0;
	
	for(i = 1; i <= STD_NUM; i++)
	{
		num = load->arr[i].num / 10000;
		num %= 100;
		
		if(num == 21)
			first_grader++;
		else if(num == 20)
			second_grader++;
		else if(num == 19)
			third_grader++;
		else if(num == 18)
			fourth_grader++;
		else
			others_grader++;
	}
	
	printf("\n\n===================================\n");
	printf("          [???? ????]\n");
	printf("===================================\n");
	printf("\n ?? ???? ??: [ %d ??] ", STD_NUM);
	
	printf("\n\n-----------------------------------------------------\n\n"); 
	printf(" 1???? (21 ????): ");
	for(i = 0; i < first_grader; i++)
		printf("??");
	printf(" [ %d ??]", first_grader);
	printf("\n\n-----------------------------------------------------\n\n"); 
	
	printf(" 2???? (20 ????): ");
	for(i = 0; i < second_grader; i++)
		printf("??");
	printf(" [ %d ??]", second_grader);
	printf("\n\n-----------------------------------------------------\n\n"); 
	
	printf(" 3???? (19 ????): ");
	for(i = 0; i < third_grader; i++)
		printf("??");
	printf(" [ %d ??]", third_grader);
	printf("\n\n-----------------------------------------------------\n\n"); 
	
	printf(" 4???? (18 ????): ");
	for(i = 0; i < fourth_grader; i++)
		printf("??");
	printf(" [ %d ??]", fourth_grader);
	printf("\n\n-----------------------------------------------------\n\n"); 
	printf(" 17????, 16 ????: ");
	for(i = 0; i < others_grader; i++)
		printf("??");
	printf(" [ %d ??]", others_grader);
	printf("\n\n-----------------------------------------------------\n"); 
	printf("\n\n");
} 

int Search(Load_List *load)
{
	char name[20];
	char i;
	
	system("cls");
	
	printf("\n==============[Search]==================\n\n");
	printf("  < ???????? ???? >\n\n");
	
	fflush(stdin);
	
	printf("???????? ???? ???? ????: ");
	gets(name);
	
	for(i = 1; i <= STD_NUM; i++)
	{
		if(strcmp(name, load->arr[i].name) == 0)
			return i;
	}
	return 0;
}

void Search_Name(Load_List *load, int n)
{	
	int res=0; 
	
	if(n == 0)
	{
		printf("\n\n===================================\n\n");
		printf("  - ???????? ???? ???? ?????? -\n\n");
		printf("===================================\n\n");
	}
	else
	{
		res = balance(load->arr[n].balance);
		system("cls");
		
		if(res >= 3)
		{
			printf("\n\n=========================================\n");
			printf("\n\t< ???? ???? >\n\n");
			printf("=========================================\n");
			printf("????????   %s\n", load->arr[n].name);
			printf("----------------------------------------\n");
			printf("????????   %d\n", load->arr[n].num);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].hometown);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].food);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].music);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].movie);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].exercise);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].game);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].drink);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].hobby);
			printf("----------------------------------------\n");
			printf("?????????? %s\n", load->arr[n].interest);
			printf("----------------------------------------\n");
			printf("??????     %s\n", load->arr[n].alcohol);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].propensity);
			printf("----------------------------------------\n");
			printf("????????   %s\n", load->arr[n].season);
			printf("=========================================\n\n");
		}
		else
			printf("\n\n?????? ????????...\n\n");
	}
}

int std_hometown(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n???????? '%s'?? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].hometown);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].hometown, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_food(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n??'%s'??(??) ???????? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].food);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].food, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_music(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n?????? ?????? '%s'?? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].music);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].music, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_movie(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n?????? ?????? '%s'?? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].movie);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].movie, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_exercise(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n??'%s'??(??) ???????? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].exercise);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].exercise, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_game(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n??'%s'??(??) ???????? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].game);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].game, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_drink(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n??'%s'??(??) ???????? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].drink);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].drink, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("---------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_hobby(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n???????? '%s'?? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].hobby);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].hobby, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_interest(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n?????? ???????? '%s'?? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].interest);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].interest, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_alcohol(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n??'%s'??(??) ?????? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].alcohol);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].alcohol, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_propensity(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n??'%s'?? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].propensity);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].propensity, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

int std_season(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n??'%s'??(??) ???????? ??????\n\n", str);
	printf("----------------\n");
	for(i = 1; i <= STD_NUM; i++)
	{	
		many = 0;
		result = 1;
		
		strcpy(string, load->arr[i].season);
		
		len = strlen(string);
		
		for(j = 0; j < len; j++)
		{
			if(string[j] == ',')
			{
				many = 1;
				break;
			}
		}
		
		if(many == 1)
		{
			n=0;
			for(j = 0; j < len; j++)
			{
				if(string[j] == ',' || string[j] == '.')
				{
					m=0;
					memset(name, 0, 10000 * sizeof(char));
					
					for(k = n; k < j; k++)
					{
						name[m] = string[k];
						m++;
					}
					n = j+1;
					result = strcmp(name, str);
				}
				if(result == 0)
					break;
			}
		}
		else
			result = strcmp(load->arr[i].season, str);
	
		if(result == 0)
		{
			printf(" %3d. %-6s   |\n", cnt, load->arr[i].name);
			printf("----------------\n");
			cnt++;
			s_num[num] = i;
			num++;
		}
	}
	printf("  0. ????????  |\n");
	printf("-----------------\n");
	printf("================\n");
	printf("?? ?? %3d ?? ??|\n", cnt-1);
	printf("================\n\n");
	
	printf("?? ???? ???? ?????? ??????\n");
	printf("???? ???? ????: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

char* hometown(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n	       < ???? >\n\n");
	printf("------------------------------------------\n");
	printf("    ????     ????     ????     ??????\n\n");
	printf("    ????     ????     ????     ????\n\n");
	printf("    ????     ????     ????     ????\n\n");
	printf("    ????     ????     ????     ????\n\n");
	printf("------------------------------------------\n\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* food(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t< ???? >\n\n");
	printf(" ????????\n");
	printf("=======================================================\n");
	printf("  ??????     ??????     ??????     ????     ????????\n\n");
	printf("  ????       ??????     ????????\n");
	printf("=======================================================\n\n");
	printf(" ????????\n");
	printf("=======================================================\n");
	printf("  ????     ??????     ??     ??????     ??????\n");
	printf("=======================================================\n\n");
	printf(" ????????\n");
	printf("=======================================================\n");
	printf("  ??????     ????????     ??????     ????     ????\n\n");
	printf("  ????       ????         ??         ????     ????????\n\n");
	printf("  ????\n");
	printf("=======================================================\n\n");
	printf(" ????????\n");
	printf("=======================================================\n");
	printf("  ??????     ??????\n");
	printf("=======================================================\n\n");
	printf(" ????????\n");
	printf("=======================================================\n");
	printf("  ????     ????     ??????     ??????     ????\n\n");
	printf("  ??????   ????     ??????     ??????     ????????\n\n");
	printf("  ????     ??????   ????       ????       ????\n\n");
	printf("  ??????   ????     ????????   ????       ????\n");
	printf("=======================================================\n\n");
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* music(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t          < ???? >\n\n");
	printf("----------------------------------------------\n");
	printf("  ??????      ??????      ????      ??\n\n");
	printf("  ????        ??????      ??        ????\n\n");
	printf("  ????        ??????      ??        ??????\n\n");
	printf("  ost         ????        ????\n");
	printf("----------------------------------------------\n");
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* movie(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t        < ???? >\n\n");
	printf("----------------------------------------------------------------------------\n");
	printf("  ??????           ????           ??????           ??????          SF\n\n");
	printf("  ????????????     ??????         ????             ????            ????\n\n");
	printf("  ??????           ????           ??????????       ??????          ????????\n\n");
	printf("  ????????         ????\n"); 
	printf("----------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* exercise(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t        < ???? >\n\n");
	printf("------------------------------------------------------------------------------\n");
	printf("  ??????           ??????          ????            ????             ????????\n\n");
	printf("  ????             ????            ????            ??????????       ????????\n\n");
	printf("  ????             ????            ????            ????             ????\n\n");
	printf("  ??????           ??????          ??????          ??????           ????????\n\n");
	printf("  ????             ????????        ????            ????????????     ????\n\n");
	printf("  ????             ????            ????\n"); 
	printf("------------------------------------------------------------------------------\n");
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* game(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t        < ???? >\n\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("  ????????       ????????     ??            ??????            ????????????\n\n");
	printf("  ??????????     ??????       ????????      ????              ????????\n\n");
	printf("  ??????         ??????       ????          ????????????1     ????????????????\n\n");
	printf("  FPS            ??????       ??????        RPG               ????????\n\n");
	printf("  ??????????     ??????????   ????????      ????????\n");
	printf("--------------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* drink(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t\t    < ???? >\n\n");
	printf("-----------------------------------------------------------------------------------\n");
	printf("  ????????????????     ??????????     ??????????     ????????     ??????????????\n\n");
	printf("  ????????????????     ??????????     ??????????     ????????     ????????????????\n\n");
	printf("  ??????????????       ??????         ??????         ????         ??????\n\n");
	printf("  ????                 ????           ??????         ??           ??????????\n\n");
	printf("  ??????????           ??????????     ??????         ??           ????????????\n\n");
	printf("  ????                 ??????????     ????           ??????????   ????(????????)\n\n");
	printf("  ????                 ????           ????????\n");
	printf("-----------------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* hobby(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t\t  < ???? >\n\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("  ????        ????       ????           ????          ????????????\n\n"); 
	printf("  ????        ??????     ????           ????????      ????????\n\n");
	printf("  ????        ????       ????           ????          ??????\n\n");
	printf("  ??????      ??????     ????           ????????      ??????????????\n\n");
	printf("  ????????    ????       ??????????     ??????????    ????????\n\n");
	printf("  ????????    ????       ????           ????          ??????\n\n");
	printf("  ??????      ????\n");
	printf("-------------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* interest(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t\t  < ?????? >\n\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("  ????       ????????     ????????????     ????????      ????\n\n");
	printf("  ????       ????         ??????           ??????        ????????\n\n");
	printf("  ??????     ????         ??????????       ??????????    ????\n\n");
	printf("  ????       ????         ????             ??????????    ????\n\n");
	printf("  ????????   ????????     ????????         ??????????    ????????\n\n");
	printf("  ??         ????         ????????         ????????      ????\n\n");
	printf("  ????       ????         ??????           ????          ????\n");
	printf("-------------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* alcohol(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t       < ?? >\n\n");
	printf("-------------------------------------\n");
	printf("  ????     ????     ????     ??????\n");
	printf("-------------------------------------\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* propensity(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t     < ???? >\n\n");
	printf("------------------------------------\n");
	printf("       ??????         ??????\n");
	printf("------------------------------------\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

char* season(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t    < ???? >\n\n");
	printf("---------------------------------\n");
	printf("  ??     ????     ????     ????\n");
	printf("---------------------------------\n");
	
	fflush(stdin);
	
	printf("????: ");
	gets(str);
	p = str;
	
	return p;
}

int item(Load_List *load, int num)
{
	int n;
	char *p;
	char str[20];
	
	switch(num)
	{
		case 1:
			p = hometown();
			strcpy(str, p);
			n = std_hometown(load, str);
			break;
		case 2:
			p = food();
			strcpy(str, p);
			n = std_food(load, str);
			break;
		case 3:
			p = music();
			strcpy(str, p);
			n = std_music(load, str);
			break;
		case 4:
			p = movie();
			strcpy(str, p);
			n = std_movie(load, str);
			break;
		case 5:
			p = exercise();
			strcpy(str, p);
			n = std_exercise(load, str);
			break;
		case 6:
			p = game();
			strcpy(str, p);
			n = std_game(load, str);
			break;
		case 7:
			p = drink();
			strcpy(str, p);
			n = std_drink(load, str);
			break;
		case 8:
			p = hobby();
			strcpy(str, p);
			n = std_hobby(load, str);
			break;
		case 9:
			p = interest();
			strcpy(str, p);
			n = std_interest(load, str);
			break;
		case 10:
			p = alcohol();
			strcpy(str, p);
			n = std_alcohol(load, str);
			break;
		case 11:
			p = propensity();
			strcpy(str, p);
			n = std_propensity(load, str);
			break;
		case 12:
			p = season();
			strcpy(str, p);
			n = std_season(load, str);
			break;
		default:
			printf("\n\n\n\n================================\n\n");
			printf("     - ?????? ?????????? -\n\n");
			printf("================================\n\n");
	}
	
	if(n >=0 && n <=12)
		return n;
}
