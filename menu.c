#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);


}

int canEverybodyEat(int* menu) {
}

int selectMenu(int* menu, int foodNo) {
	int frnd_n, pos_fdn,i,j,tmp;
	scanf("%d", &frnd_n);
	scanf("%d", &pos_fdn);

	char** names = (char**)malloc(sizeof(char*)*frnd_n);
	for (i = 0; i < frnd_n; i++) 
		names[i] = (char *)malloc(sizeof(char) * 11);
	for (i = 0; i < frnd_n; i++) {
		gets(names[i]);
	}
	
	char** p_menu = (char**)malloc(sizeof(char*)*pos_fdn);
	for (i = 0; i < pos_fdn; i++) {
		scanf("%d", tmp);
		p_menu[i] = (char*)malloc(sizeof(char)*);
	}
}