#include<stdio.h>
#include<string.h>

int main() {

	char a[100][100];
	int n;
	int salary = 0;
	
	scanf_s("%d\n", &n);
	for (int i = 0; i < n;i++){
		gets_s(a[i]);
		//scanf_s("%s", a[i],sizeof(a[i]));
	}
	int salarycheck[100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < strlen(a[i]); j++) {
			if (a[i][j] >= '0' && a[i][j] <= '9') {
				salary = (salary + (a[i][j] - '0'))*10;
				if (!(a[i][j+1] >= '0' && a[i][j+1] <= '9')) {
					salary = salary / 10;
				}
			}
			
		}
		salarycheck[i] = salary;
		salary = 0;
		

	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (salarycheck[j-1] > salarycheck[j]) {
				int c;
				c = salarycheck[j-1];
				salarycheck[j-1] = salarycheck[j];
				salarycheck[j] = c;
				char cstr[100];
				strcpy_s(cstr, a[j-1]);
				strcpy_s(a[j - 1],a[j]);
				strcpy_s(a[j],cstr);
			}

		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s\n", a[i]);
	}
}
