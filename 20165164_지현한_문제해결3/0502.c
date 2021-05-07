#include <stdio.h>
#include "fun.h"

struct subject {
	char name[10];
	float avg;
};

struct student {
	char name[10];
	int kor;
	int eng;
	int math;
	int sum;
	float avg;
	char grade;
};

void line(void) {
	printf("---------------------------------------------------------------\n");

}

void exam0502(void) {
	struct student s[5];
	struct subject sb[3] = {
		{"국어",0},
		{"영어",0},
		{"수학",0}
	};
	int korsum = 0;
	int engsum = 0;
	int mathsum = 0;

	for (int i = 0; i < 5; i++) {	//입력
		printf("이름 국어점수 영어점수 수학점수 입력 :");
		scanf("%s%d%d%d", s[i].name, &s[i].kor, &s[i].eng, &s[i].math);
	}

	for (int i = 0; i < 5; i++) {
		s[i].sum = s[i].kor + s[i].eng + s[i].math;	//총점계산

		s[i].avg = (float)s[i].sum / 3;	//평균계산

		if (s[i].avg >= 90) {		//학점계산
			s[i].grade = 'A';
		}
		else if (s[i].avg >= 80) {
			s[i].grade = 'B';
		}
		else if (s[i].avg >= 70) {
			s[i].grade = 'C';
		}
		else if (s[i].avg >= 60) {
			s[i].grade = 'D';
		}
		else {
			s[i].grade = 'F';
		}

		korsum += s[i].kor;			//과목별 평균을위한 합
		engsum += s[i].eng;
		mathsum += s[i].math;
	}

	sb[0].avg = (float)korsum / 5;	//과목별 평균
	sb[1].avg = (float)engsum / 5;
	sb[2].avg = (float)mathsum / 5;


	//출력
	line();
	printf("번호\t이름\t국어\t영어\t수학\t총점\t평균\t학점\n");
	line();
	for (int i = 0; i < 5; i++) {
		printf("  %d\t%s\t%3d\t%3d\t%3d\t%3d\t%.2f\t  %c\n", i + 1, s[i].name, s[i].kor, s[i].eng, s[i].math, s[i].sum, s[i].avg, s[i].grade);
		line();
	}

	for (int i = 0; i < 3; i++) {
		printf("%d) %s 평균 점수 : ", i + 1, sb[i].name);
		for (int j = 0; j < (int)(sb[i].avg / 10); j++) {
			printf("■");
		}
		printf(" (%f)\n", sb[i].avg);
	}
}