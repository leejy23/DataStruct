#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main() {
	FILE* fin, * fout;
	typedef struct {
		int no;
		char name[10];
		int sc1;
		int sc2;
	} student;
	int cno, csc1, csc2;
	char cname[10];
	char ch = ' ';
	student st[3] = { {1,"kim",87,92},{2,"lee",96,78},{3,"cho",77,82} };
	fopen_s(&fout, "studentf.txt", "w");
	for (int i = 0; i < 3; i++) {
		fprintf_s(fout, "%d %s %d %d %c\n", st[i].no, st[i].name, st[i].sc1, st[i].sc2, ch);
	}
	fclose(fout);
	printf("********OUTPUT********\n");
	fopen_s(&fin, "studentf.txt", "r");
	for (int i = 0; i < 3; i++) {
		fscanf(fin, "%d %s %d %d", &cno, cname, &csc1, &csc2);
		printf("%d %s %d %d\n", cno, cname, csc1, csc2);
		}
	fclose(fin);
	
}