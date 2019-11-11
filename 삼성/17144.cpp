#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int before[52][52];
int after[52][52];
int fin[52][52];
int R, C, T, upper, lower, cnt_pos, answer = 0;
int dir[4][2] = { {-1,0}, {1,0},{0,-1},{0,1} };
void diffuse() {
	int i, j,k, target_x, target_y;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			cnt_pos = 0;
			for (k = 0; k < 4; k++) {
				target_x = i + dir[k][0];
				target_y = j + dir[k][1];
				if (target_x > 0 && target_x <= R &&
					target_y > 0 && target_y <= C &&
					!((target_x == upper && target_y == 1) || (target_x == lower && target_y == 1))) {
					after[target_x][target_y] += before[i][j] / 5;
					cnt_pos++;
				}

			}
			after[i][j] += before[i][j] - ((before[i][j] / 5) * cnt_pos);
		}
	}
}

void wind() {
	int i,j;
	copy(&after[0][0], &after[0][0] + 52 * 52, &fin[0][0]);
	//À§
	fin[upper][2] = 0;
	for (j = 3; j <= C; j++) {
		fin[upper][j] = after[upper][j - 1];
	}
	for (i = upper-1; i >= 1; i--) {
		fin[i][C] = after[i + 1][C];
	}

	for (j = C-1; j >=1; j--) {
		fin[1][j] = after[1][j + 1];
	}
	for (i = 2; i <= upper-1; i++) {
		fin[i][1] = after[i -1][1];
	}

	//¾Æ·¡
	fin[lower][2] = 0;
	for (j = 3; j <= C; j++) {
		fin[lower][j] = after[lower][j - 1];
	}

	for (i = lower+1; i <= R; i++) {
		fin[i][C] = after[i - 1][C];
	}


	for (j = C - 1; j >= 1; j--) {
		fin[R][j] = after[R][j + 1];
	}

	for (i = R - 1; i >= lower+1; i--) {
		fin[i][1] = after[i + 1][1];
	}



}

void print_before() {
	int i, j;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			cout << before[i][j]<<" ";
		}
		cout << "\n";
	}
}
void print_after() {
	int i, j;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			cout << after[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void print_fin() {
	int i, j;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			cout << fin[i][j] << " ";
		}
		cout << "\n";
	}
}

int sol(int n) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		diffuse();
		wind();
		copy(&fin[0][0], &fin[0][0] + 52 * 52, &before[0][0]);
		memset(after, 0, sizeof(after));
		memset(fin, 0, sizeof(fin));
	}

	diffuse();
	wind();

	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			answer += fin[i][j];
		}
	}

	return answer + 2;
}
int main() {
	cin >> R >> C >> T;
	int i, j;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++) {
			cin >> before[i][j];
		}
	}
	for (i = 3; i <= R - 2; i++) {
		if (before[i][1] == -1) {
			upper = i;
			lower = i + 1;
			break;
		}
	}

	/*
	cout << "print before" << endl;
	print_before();
	diffuse();
	cout << "print after" << endl;
	print_after();
	wind();
	cout << "print fin" << endl;
	print_fin();
	*/

	cout << sol(T);
	return 0;
}
