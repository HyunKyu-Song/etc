#include <stdio.h>
#define MAX_DEGREE 10

typedef struct{
	int degree; //차수 
	float coef[MAX_DEGREE]; //계수 
}polynomial;

polynomial poly_add(polynomial A, polynomial B)
{
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0; //A, B, C 각각 배열의 위치 
	int degree_a = A.degree;
	int degree_b = B.degree;
	
	//A와 B를 비교해서 차수가 큰 것을 C에 차수로 씀 
	if(A.degree >= B.degree)
		C.degree = A.degree;
	else
		C.degree = B.degree;
	
	while(Apos <= A.degree && Bpos <= B.degree){ //A, B 모두 마지막 배열까지 가면 종료
		if(degree_a > degree_b){
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if(degree_a == degree_b){
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C; // A, B를 더한 값을 polynomial형으로 반환 
}

void print_poly(polynomial p)
{
	int i;
	
	for(i = p.degree; i > 0; i--){
		printf("%3.1f x^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f \n", p.coef[p.degree]);
}


int main(){
	polynomial a = { 5, { 3, 6, 0, 0, 0, 10 }}; //5는 차수, 나머지는 계수 
	polynomial b = { 4, { 7, 0, 5, 0, 1 }}; // 4는 차수, 나머지는 계수 
	polynomial c;
	
	print_poly(a);
	print_poly(b);
	c = poly_add(a, b);
	printf("--------------------------------------------------------\n");
	print_poly(c);
	
	return 0;
}
