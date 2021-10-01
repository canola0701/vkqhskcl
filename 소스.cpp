#include<stdio.h>
#define MAX(a,b)((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial addPoly(polynomial, polynomial);
polynomial multiplyPoly(polynomial, polynomial);
void printPoly(polynomial);

void main() {
	polynomial A = { 5,{4,7,1,0,2,5} };
	polynomial B = { 4,{8,3,5,2,1} };

	polynomial C,D;
	C = addPoly(A, B);
	D = multiplyPoly(A, B);

	printf("\n A(x) ="); printPoly(A);
	printf("\n B(x) ="); printPoly(B);
	printf("\n C(x) ="); printPoly(C);
	printf("\n D(x) ="); printPoly(D);

	getchar();
}

//�� ���׽��� ���ϴ� �Լ�
polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX (A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) {
		if(A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;

		}
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index];
			B_degree--;
		}
	}
	return C;
}

//�� ���׽��� ���ϴ� �Լ�
polynomial multiplyPoly(polynomial A, polynomial B) {
	int i, j;
	polynomial D;
	for (i = 0; i < A.degree + B.degree + 1; i++) {D.coef[i] = 0;}//�迭�ʱ�ȭ
		D.degree = A.degree + B.degree;

		for (i = 0; i < A.degree + 1; i++) {
			for (j = 0; j < B.degree + 1; j++) {
				D.coef[i + j] += A.coef[i] * B.coef[j];
			}
		}
		return D;
	

}

void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for(i = 0; i <= P.degree; i++) {
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree)printf(" +");

	}
	printf("\n");
	


}