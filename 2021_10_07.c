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
		
		printf("선택: ");
		scanf("%d", &select);
		
		system("cls");
		
		switch(select)
		{
			case 0:
				if(password())
				{
					admin();
					
					printf("\n선택: ");
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
				printf(" - 프로그램이 종료되었습니다 -\n\n");
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
	printf("  < 학생 정보 >\n");
	printf("\n  학번: ");
	scanf("%d", &list->arr[list->cnt].num); 
	
	fflush(stdin);
	
	printf("  이름: ");
	gets(s);
	strcpy(list->arr[list->cnt].name, s);
	fflush(stdin);
	
	printf("  고향: ");
	gets(s);
	strcpy(list->arr[list->cnt].hometown, s);
	
	fflush(stdin);
	
	printf("  음식: ");
	gets(s);
	strcpy(list->arr[list->cnt].food, s);
	
	fflush(stdin);
	
	printf("  음악: ");
	gets(s);
	strcpy(list->arr[list->cnt].music, s);
	
	fflush(stdin);
	
	printf("  영화: ");
	gets(s);
	strcpy(list->arr[list->cnt].movie, s);
	
	fflush(stdin);
	
	printf("  운동: ");
	gets(s);
	strcpy(list->arr[list->cnt].exercise, s);
	
	fflush(stdin);
	
	printf("  게임: ");
	gets(s);
	strcpy(list->arr[list->cnt].game, s);
	
	fflush(stdin);
	
	printf("  음료: ");
	gets(s);
	strcpy(list->arr[list->cnt].drink, s);
	
	fflush(stdin);
	
	printf("  취미: ");
	gets(s);
	strcpy(list->arr[list->cnt].hobby, s);
	
	fflush(stdin);
	
	printf("  관심사: ");
	gets(s);
	strcpy(list->arr[list->cnt].interest, s);
	
	fflush(stdin);
	
	printf("  술: ");
	gets(s);
	strcpy(list->arr[list->cnt].alcohol, s);
	
	fflush(stdin);
	
	printf("  성향: ");
	gets(s);
	strcpy(list->arr[list->cnt].propensity, s);
	
	fflush(stdin);
	
	printf("  계절: ");
	gets(s);
	strcpy(list->arr[list->cnt].season, s);
	
	printf("  밸런스 게임: ");
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
	printf("     - 잘못된 입력입니다 -\n\n");
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
	printf("       【 정보 Loading 완료 】\n\n");
	printf("=======================================\n");
}

void Load_Print(Load_List *load)
{
	int i, j;
	
	for(i = 1; i <= STD_NUM; i++)
	{
		printf("\n\n=========================================\n");
		printf("\n\t< 학생 정보 >\n\n");
		printf("=========================================\n");
		printf("【이름】   %s\n", load->arr[i].name);
		printf("----------------------------------------\n");
		printf("【학번】   %d\n", load->arr[i].num);
		printf("----------------------------------------\n");
		printf("【고향】   %s\n", load->arr[i].hometown);
		printf("----------------------------------------\n");
		printf("【음식】   %s\n", load->arr[i].food);
		printf("----------------------------------------\n");
		printf("【음악】   %s\n", load->arr[i].music);
		printf("----------------------------------------\n");
		printf("【영화】   %s\n", load->arr[i].movie);
		printf("----------------------------------------\n");
		printf("【운동】   %s\n", load->arr[i].exercise);
		printf("----------------------------------------\n");
		printf("【게임】   %s\n", load->arr[i].game);
		printf("----------------------------------------\n");
		printf("【음료】   %s\n", load->arr[i].drink);
		printf("----------------------------------------\n");
		printf("【취미】   %s\n", load->arr[i].hobby);
		printf("----------------------------------------\n");
		printf("【관심사】 %s\n", load->arr[i].interest);
		printf("----------------------------------------\n");
		printf("【술】     %s\n", load->arr[i].alcohol);
		printf("----------------------------------------\n");
		printf("【성향】   %s\n", load->arr[i].propensity);
		printf("----------------------------------------\n");
		printf("【계절】   %s\n", load->arr[i].season);
		printf("----------------------------------------\n");
		printf("【밸런스】 ");
		for(j = 0; j < 6; j++)
			printf("%d ", load->arr[i].balance[j]);
		printf("\n=========================================\n\n");
	}
}

void admin(void)
{
	printf("\n -------------------------------\n");
	printf("|                               |\n"); 
	printf("|   < 관리자 전용 >             |\n");
	printf("|                               |\n");
	printf("|                               |\n");  
	printf("| [1] 전체 학생 정보            |\n");
	printf("|                               |\n");
	printf("| [2] 학생 정보 입력            |\n");
	printf("|                               |\n");
	printf("| [3] 정보 Load (정보 불러오기) |\n");
	printf("|                               |\n");
	printf(" -------------------------------\n");
}

void menu(void)
{
	printf("\n");
	printf("==================================\n");
	now();
	printf("==================================\n");
	
	printf("\n\n  『 친해지길 바래~ 』\n\n");
	printf("  나와 맞는 사람은 누구일까?\n\n");
	printf("----------------------------------\n");
	printf("|   < 관리자 전용 >              |\n");
	printf("|                                |\n"); 
	printf("| [0] 관리자 모드                |\n");
	printf("----------------------------------\n");
	printf("|                                |\n");
	printf("|   < 사용자 전용 >              |\n");
	printf("|                                |\n");
	printf("| [1] Category 찾기              |\n");
	printf("|                                |\n");
	printf("| [2] 이름으로 찾기              |\n");
	printf("|                                |\n");
	printf("| [3] 랜덤 매칭                  |\n");
	printf("|                                |\n");
	printf("| [4] 학생 현황                  |\n");
	printf("|                                |\n");
	printf("| [5] 프로그램 설명 및 사용법    |\n");
	printf("|                                |\n");
	printf("| [6] 프로그램 종료              |\n");
	printf("----------------------------------\n\n");
}

void now(void)
{
	struct tm *t;
	char *day[7] = {"일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일"}; //포인터 배열 
	
	time_t timer;
	
	timer = time(NULL);
	t = localtime(&timer);
	
	printf("     %d년 %d월 %d일 %s\n\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, day[t->tm_wday]);
	printf("     현재시각: %d시 %d분 %d초\n", t->tm_hour, t->tm_min, t->tm_sec);
}

int catagory(void)
{
	int n;
	system("cls");
	
	printf("\n	     < Category 찾기 >\n\n");
	printf("---------------------------------------------\n");
	printf("[1]  고향	");
	printf("[2]  음식	");
	printf("[3]  음악   |\n");
	printf("                                            |\n");
	printf("[4]  영화	");
	printf("[5]  운동	");
	printf("[6]  게임   |\n");
	printf("                                            |\n");
	printf("[7]  음료	");
	printf("[8]  취미	");
	printf("[9]  관심사 |\n");
	printf("                                            |\n");
	printf("[10] 술		");
	printf("[11] 성향	");
	printf("[12] 계절   |\n");
	printf("---------------------------------------------\n\n");
	
	printf("선택: ");
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
		printf("\n\n【 접속불가 】\n\n");
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
		printf("\n\t< 학생 정보 >\n\n");
		printf("=========================================\n");
		printf("【이름】   %s\n", load->arr[n].name);
		printf("----------------------------------------\n");
		printf("【학번】   %d\n", load->arr[n].num);
		printf("----------------------------------------\n");
		printf("【고향】   %s\n", load->arr[n].hometown);
		printf("----------------------------------------\n");
		printf("【음식】   %s\n", load->arr[n].food);
		printf("----------------------------------------\n");
		printf("【음악】   %s\n", load->arr[n].music);
		printf("----------------------------------------\n");
		printf("【영화】   %s\n", load->arr[n].movie);
		printf("----------------------------------------\n");
		printf("【운동】   %s\n", load->arr[n].exercise);
		printf("----------------------------------------\n");
		printf("【게임】   %s\n", load->arr[n].game);
		printf("----------------------------------------\n");
		printf("【음료】   %s\n", load->arr[n].drink);
		printf("----------------------------------------\n");
		printf("【취미】   %s\n", load->arr[n].hobby);
		printf("----------------------------------------\n");
		printf("【관심사】 %s\n", load->arr[n].interest);
		printf("----------------------------------------\n");
		printf("【술】     %s\n", load->arr[n].alcohol);
		printf("----------------------------------------\n");
		printf("【성향】   %s\n", load->arr[n].propensity);
		printf("----------------------------------------\n");
		printf("【계절】   %s\n", load->arr[n].season);
		printf("=========================================\n\n");
	}
	else
		printf("\n\n성향이 다르네요...\n\n");
}

void manual(void)
{
	printf("\n==============[Manual]==================\n\n");
	printf("  < 프로그램 설명 및 사용법 >\n\n\n");
	printf("【설명】\n\n");
	printf(" 프로그램명은 '친해지길 바래~'입니다.\n\n");
	printf(" 이름과 같이 친해지고 싶은 학생의 정보를 미리 알아보고\n\n");
	printf(" 실제로 만났을 때 좀 더 쉽게 다가갈 수 있게 하기 위함을\n\n");
	printf(" 목적으로 만들었습니다.\n\n\n");
	printf("【사용법】\n\n");
	printf("-------------------------------------------\n");
	printf("『 프로그램은 Setting 후 사용 가능\n\n");
	printf("   Setting: '관리자 모드' -> '정보 Load' 』\n\n");
	printf("   [사용자 모드]는 바로 사용 가능\n");
	printf("-------------------------------------------\n\n");
	printf(" 1. 메인화면에 나온 다양한 기능 중 원하는 것을 정한다.\n\n");
	printf(" 2. 기능에 해당하는 번호를 입력한다.\n\n");
	printf(" 3. 이제부터 화면에 나온 설명을 따라 진행하면 된다.\n\n\n");
	printf("===========================================================\n"); 
	printf(" ※프로그램에서 얻은 정보를 상업적, 불법적 이용을 금한다.\n");
	printf("===========================================================\n");
}

void ex(void)
{
	system("cls");
	
	printf("\n----------------- < 밸런스 게임 > -----------------\n\n");
	printf("   2 가지 선택지 중 자신이 원하는 것을 선택\n\n");
	printf("   6개 중 선택된 학생과 3개 이상 같다면\n\n");
	printf("   선택된 학생에 대한 정보를 얻을 수 있습니다.\n\n");
	printf("   하지만, 결과가 3개 미만이면 인연은 여기까지...\n");
	printf("\n---------------------------------------------------\n\n\n");
}

int balance(int arr[])
{
	int select=0, cnt=0, i=0;
	
	system("cls");
	printf("\n이제 선택된 학생과 얼마나 잘 맞는지 알아보는 간단한 게임을 하겠습니다.\n");
	printf("\nEnter를 누르시면 게임이 시작됩니다. ");
	getch(); 
	
	ex();
	printf("--------------------\n");
	printf("[1] 삼성\n");
	printf("--------------------\n");
	printf("[2] 애플\n");
	printf("--------------------\n");
	printf("입력: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;
	
	ex();
	printf("--------------------\n");
	printf("[1] 콜라\n");
	printf("--------------------\n");
	printf("[2] 사이다\n");
	printf("--------------------\n");
	printf("입력: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;
	
	ex();
	printf("----------------------\n");
	printf("[1] 아이스 아메리카노\n");
	printf("----------------------\n");
	printf("[2] 따뜻한 아메리카노\n");
	printf("----------------------\n");
	printf("입력: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;

	ex();
	printf("----------------------\n");
	printf("[1] 과대 1년 하기\n");
	printf("----------------------\n");
	printf("[2] 부과대 4년 하기\n");
	printf("----------------------\n");
	printf("입력: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;

	ex();
	printf("--------------------\n");
	printf("[1] 양념 치킨\n");
	printf("--------------------\n");
	printf("[2] 후라이드 치킨\n");
	printf("--------------------\n");
	printf("입력: ");
	scanf("%d", &select);
	
	if(select == arr[i])
		cnt++;
	i++;
	
	ex();
	printf("----------------------------------\n");
	printf("[1] 수업은 비대면하고 시험만 대면\n");
	printf("----------------------------------\n");
	printf("[2] 수업은 대면하고 시험만 비대면\n");
	printf("----------------------------------\n");
	printf("입력: ");
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
	printf("  < 랜덤 매칭 >\n\n");
	printf("Enter를 누르시면 랜덤으로 매칭됩니다. ");
	fflush(stdin);
	getchar();
	
	srand((unsigned)time(NULL));
	
	n = 1+rand()%STD_NUM;
	printf("\n매칭된 학생: [ %s ]\n\n\n", load->arr[n].name);
	
	printf("--------------------------\n");
	printf("[1] 매칭된 학생 정보 확인\n");
	printf("--------------------------\n");
	printf("[2] 메인화면으로 돌아가기\n");   
	printf("--------------------------\n");
	printf("입력: ");
	scanf("%d", &select);
	
	if(select == 1)
	{
		res = balance(load->arr[n].balance);
	    system("cls");
	
		if(res >= 3)
		{
			printf("\n\n=========================================\n");
			printf("\n\t< 학생 정보 >\n\n");
			printf("=========================================\n");
			printf("【이름】   %s\n", load->arr[n].name);
			printf("----------------------------------------\n");
			printf("【학번】   %d\n", load->arr[n].num);
			printf("----------------------------------------\n");
			printf("【고향】   %s\n", load->arr[n].hometown);
			printf("----------------------------------------\n");
			printf("【음식】   %s\n", load->arr[n].food);
			printf("----------------------------------------\n");
			printf("【음악】   %s\n", load->arr[n].music);
			printf("----------------------------------------\n");
			printf("【영화】   %s\n", load->arr[n].movie);
			printf("----------------------------------------\n");
			printf("【운동】   %s\n", load->arr[n].exercise);
			printf("----------------------------------------\n");
			printf("【게임】   %s\n", load->arr[n].game);
			printf("----------------------------------------\n");
			printf("【음료】   %s\n", load->arr[n].drink);
			printf("----------------------------------------\n");
			printf("【취미】   %s\n", load->arr[n].hobby);
			printf("----------------------------------------\n");
			printf("【관심사】 %s\n", load->arr[n].interest);
			printf("----------------------------------------\n");
			printf("【술】     %s\n", load->arr[n].alcohol);
			printf("----------------------------------------\n");
			printf("【성향】   %s\n", load->arr[n].propensity);
			printf("----------------------------------------\n");
			printf("【계절】   %s\n", load->arr[n].season);
			printf("=========================================\n\n");
		}
		else
			printf("\n\n성향이 다르네요...\n\n");
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
	printf("          [학생 현황]\n");
	printf("===================================\n");
	printf("\n 총 학생 수: [ %d 명] ", STD_NUM);
	
	printf("\n\n-----------------------------------------------------\n\n"); 
	printf(" 1학년 (21 학번): ");
	for(i = 0; i < first_grader; i++)
		printf("■");
	printf(" [ %d 명]", first_grader);
	printf("\n\n-----------------------------------------------------\n\n"); 
	
	printf(" 2학년 (20 학번): ");
	for(i = 0; i < second_grader; i++)
		printf("■");
	printf(" [ %d 명]", second_grader);
	printf("\n\n-----------------------------------------------------\n\n"); 
	
	printf(" 3학년 (19 학번): ");
	for(i = 0; i < third_grader; i++)
		printf("■");
	printf(" [ %d 명]", third_grader);
	printf("\n\n-----------------------------------------------------\n\n"); 
	
	printf(" 4학년 (18 학번): ");
	for(i = 0; i < fourth_grader; i++)
		printf("■");
	printf(" [ %d 명]", fourth_grader);
	printf("\n\n-----------------------------------------------------\n\n"); 
	printf(" 17학번, 16 학번: ");
	for(i = 0; i < others_grader; i++)
		printf("■");
	printf(" [ %d 명]", others_grader);
	printf("\n\n-----------------------------------------------------\n"); 
	printf("\n\n");
} 

int Search(Load_List *load)
{
	char name[20];
	char i;
	
	system("cls");
	
	printf("\n==============[Search]==================\n\n");
	printf("  < 이름으로 찾기 >\n\n");
	
	fflush(stdin);
	
	printf("친해지고 싶은 학생 입력: ");
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
		printf("  - 등록되지 않은 학생 입니다 -\n\n");
		printf("===================================\n\n");
	}
	else
	{
		res = balance(load->arr[n].balance);
		system("cls");
		
		if(res >= 3)
		{
			printf("\n\n=========================================\n");
			printf("\n\t< 학생 정보 >\n\n");
			printf("=========================================\n");
			printf("【이름】   %s\n", load->arr[n].name);
			printf("----------------------------------------\n");
			printf("【학번】   %d\n", load->arr[n].num);
			printf("----------------------------------------\n");
			printf("【고향】   %s\n", load->arr[n].hometown);
			printf("----------------------------------------\n");
			printf("【음식】   %s\n", load->arr[n].food);
			printf("----------------------------------------\n");
			printf("【음악】   %s\n", load->arr[n].music);
			printf("----------------------------------------\n");
			printf("【영화】   %s\n", load->arr[n].movie);
			printf("----------------------------------------\n");
			printf("【운동】   %s\n", load->arr[n].exercise);
			printf("----------------------------------------\n");
			printf("【게임】   %s\n", load->arr[n].game);
			printf("----------------------------------------\n");
			printf("【음료】   %s\n", load->arr[n].drink);
			printf("----------------------------------------\n");
			printf("【취미】   %s\n", load->arr[n].hobby);
			printf("----------------------------------------\n");
			printf("【관심사】 %s\n", load->arr[n].interest);
			printf("----------------------------------------\n");
			printf("【술】     %s\n", load->arr[n].alcohol);
			printf("----------------------------------------\n");
			printf("【성향】   %s\n", load->arr[n].propensity);
			printf("----------------------------------------\n");
			printf("【계절】   %s\n", load->arr[n].season);
			printf("=========================================\n\n");
		}
		else
			printf("\n\n성향이 다르네요...\n\n");
	}
}

int std_hometown(Load_List *load, char str[])
{
	int select, len, i, j, k, m;
	int result=1, many=0, num=1, cnt=1, n=0;
	int s_num[50] = {0, };
	char string[10000], name[10000];
	
	system("cls");
	printf("\n\n【고향이 '%s'인 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【'%s'을(를) 좋아하는 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【음악 취향이 '%s'인 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【영화 취향이 '%s'인 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【'%s'을(를) 좋아하는 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【'%s'을(를) 좋아하는 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【'%s'을(를) 좋아하는 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("---------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【취미가 '%s'인 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【요즘 관심사가 '%s'인 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【'%s'가(이) 취향인 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【'%s'인 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
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
	printf("\n\n【'%s'을(를) 좋아하는 학생】\n\n", str);
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
	printf("  0. 메인화면  |\n");
	printf("-----------------\n");
	printf("================\n");
	printf("【 총 %3d 명 】|\n", cnt-1);
	printf("================\n\n");
	
	printf("더 알고 싶은 학생이 있다면\n");
	printf("학생 번호 입력: ");
	scanf("%d", &select);
	
	select = s_num[select];
	
	return select;
}

char* hometown(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n	       < 고향 >\n\n");
	printf("------------------------------------------\n");
	printf("    광주     순천     여수     제주도\n\n");
	printf("    대전     일산     청주     서울\n\n");
	printf("    보성     광양     목포     인천\n\n");
	printf("    전주     고흥     세종     김해\n\n");
	printf("------------------------------------------\n\n");
	
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* food(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t< 음식 >\n\n");
	printf(" 【한식】\n");
	printf("=======================================================\n");
	printf("  갈비찜     추어탕     냉모밀     국밥     간장게장\n\n");
	printf("  한식       감자탕     닭볶음탕\n");
	printf("=======================================================\n\n");
	printf(" 【양식】\n");
	printf("=======================================================\n");
	printf("  피자     파스타     빵     햄버거     양고기\n");
	printf("=======================================================\n\n");
	printf(" 【일식】\n");
	printf("=======================================================\n");
	printf("  돈까스     메밀소바     사케동     우동     덮밥\n\n");
	printf("  욕회       초밥         회         일식     연어덮밥\n\n");
	printf("  연어\n");
	printf("=======================================================\n\n");
	printf(" 【중식】\n");
	printf("=======================================================\n");
	printf("  짜장면     볶음밥\n");
	printf("=======================================================\n\n");
	printf(" 【기타】\n");
	printf("=======================================================\n");
	printf("  고기     닭발     떡볶이     마라탕     치킨\n\n");
	printf("  버블티   카레     닭요리     면요리     새우요리\n\n");
	printf("  라면     음료수   딸기       족발       장어\n\n");
	printf("  삼겹살   냉면     돼지갈비   닭발       보쌈\n");
	printf("=======================================================\n\n");
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* music(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t          < 음악 >\n\n");
	printf("----------------------------------------------\n");
	printf("  발라드      클래식      댄스      락\n\n");
	printf("  인디        알앤비      팝        밴드\n\n");
	printf("  힙합        싱잉랩      랩        케이팝\n\n");
	printf("  ost         재즈        없음\n");
	printf("----------------------------------------------\n");
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* movie(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t        < 영화 >\n\n");
	printf("----------------------------------------------------------------------------\n");
	printf("  스릴러           액션           로맨스           드라마          SF\n\n");
	printf("  로맨스코미디     코미디         멜로             범죄            공포\n\n");
	printf("  판타지           추리           애니메이션       느와르          공포빼고\n\n");
	printf("  히어로물         없음\n"); 
	printf("----------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* exercise(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t        < 운동 >\n\n");
	printf("------------------------------------------------------------------------------\n");
	printf("  달리기           자전거          스키            헬스             맨몸운동\n\n");
	printf("  수영             산책            요가            플라잉요가       필라테스\n\n");
	printf("  야구             축구            복싱            볼링             당구\n\n");
	printf("  태권도           자전거          숨쉬기          뒹굴기           스트레칭\n\n");
	printf("  피구             배드민턴        탁구            손목움직이기     걷기\n\n");
	printf("  농구             배구            등산\n"); 
	printf("------------------------------------------------------------------------------\n");
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* game(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t        < 게임 >\n\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("  서든어택       오버워치     롤            칼바람            배틀그라운드\n\n");
	printf("  가위바위보     스도쿠       루미큐브      클루              발로란트\n\n");
	printf("  눈싸움         술게임       오목          스타크래프트1     레인보우식스시즈\n\n");
	printf("  FPS            메이플       열불춤        RPG               할리갈리\n\n");
	printf("  밸런스게임     이터널리턴   운동게임      바니바니\n");
	printf("--------------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* drink(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t\t    < 음료 >\n\n");
	printf("-----------------------------------------------------------------------------------\n");
	printf("  아이스바닐라라떼     바닐라라떼     토피넛라떼     딸기라떼     녹차프라푸치노\n\n");
	printf("  아이스아메리카노     페퍼민트차     유자민트티     카프리썬     딸기요거트스무디\n\n");
	printf("  복숭아아이스티       밀키스         탄산수         주스         쉐이크\n\n");
	printf("  커피                 콜라           사이다         차           갈아만든배\n\n");
	printf("  다크초콜릿           초코맛음료     이프로         물           포카리스웨트\n\n");
	printf("  식혜                 망고스무디     탄산           아메리카노   앤톡(복숭아향)\n\n");
	printf("  두유                 우유           초코우유\n");
	printf("-----------------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* hobby(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t\t  < 취미 >\n\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("  낚시        게임       독서           마술          혼자카페가기\n\n"); 
	printf("  영화        숨쉬기     웹툰           책방가기      맛집탐방\n\n");
	printf("  수영        요가       운동           축구          헬스장\n\n");
	printf("  드라마      유튜브     왓챠           넷플릭스      스포츠경기보기\n\n");
	printf("  음악감상    노래       노래방가기     피아노연주    명곡찾기\n\n");
	printf("  카페탐방    캠핑       낙서           산책          베이킹\n\n");
	printf("  인스타      눕기\n");
	printf("-------------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* interest(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t\t\t\t  < 관심사 >\n\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("  공부       경제공부     영어문장독해     미적분학      임용\n\n");
	printf("  취업       영화         숨쉬기           드라마        졸업작품\n\n");
	printf("  칵테일     낚시         고기굽는법       아이돌컴백    노래\n\n");
	printf("  헬스       요가         운동             웨이트운동    건강\n\n");
	printf("  애플워치   이성친구     다이어트         명탐정코난    포켓캠프\n\n");
	printf("  돈         음악         여자친구         넷플릭스      독서\n\n");
	printf("  캠핑       게임         유튜브           알바          전공\n");
	printf("-------------------------------------------------------------------------------\n");
	
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* alcohol(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t       < 술 >\n\n");
	printf("-------------------------------------\n");
	printf("  소주     맥주     소맥     막걸리\n");
	printf("-------------------------------------\n");
	
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* propensity(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t     < 성향 >\n\n");
	printf("------------------------------------\n");
	printf("       외향적         내향적\n");
	printf("------------------------------------\n");
	
	fflush(stdin);
	
	printf("입력: ");
	gets(str);
	p = str;
	
	return p;
}

char* season(void)
{
	char str[20];
	char *p;
	
	system("cls");
	
	printf("\n\t    < 계절 >\n\n");
	printf("---------------------------------\n");
	printf("  봄     여름     가을     겨울\n");
	printf("---------------------------------\n");
	
	fflush(stdin);
	
	printf("입력: ");
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
			printf("     - 잘못된 입력입니다 -\n\n");
			printf("================================\n\n");
	}
	
	if(n >=0 && n <=12)
		return n;
}
