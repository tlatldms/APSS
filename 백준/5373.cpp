#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
enum DIR { U, D, F, B, L, R };
int cube[6][3][3]; // 전개도상 번호 저장
char arr[55]; // arr의 index : cube 배열의 값 => color
char colors[6] = { 'w', 'y', 'r','o', 'g', 'b' }; // 0U 1D 2F 3B 4L 5R
int conv[256];

/*           U
		  0  1  2
		  3  4  5
		  6  7  8
   L      ---F----      R        B
36 37 38  18 19 20  45 46 47  27 28 29
39 40 41  21 22 23  48 49 50  30 31 32
42 43 44  24 25 26  51 52 53  33 34 35
		  --------
		  9  10 11
		  12 13 14
		  15 16 17
			 D
*/

int near[6][12] = {
  {18,19,20,36,37,38,27,28,29,45,46,47}, // U: F L B R
  {24,25,26,51,52,53,33,34,35,42,43,44}, // D: F R B L
  {6,7,8,45,48,51,11,10,9,44,41,38}, // F: U R D L
  {2,1,0,36,39,42,15,16,17,53,50,47}, //B: U L D R
  {0,3,6, 18,21,24,9,12,15,35,32,29}, //L: U F D B
  {8,5,2,27,30,33,17,14,11,26,23,20} //R: U B D F
};


void pr() {
	int i, j, k;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				cout << cube[i][j][k];
			}
		}
	}
}

void rotate(DIR d, int cnt) {
	char buf[12]; int i, j; char tmp[3][3];
	while (cnt--) {

		for (i = 0; i < 12; i++) 
			buf[i] = arr[near[d][i]];

		for (i = 0; i < 12; i++) 
			arr[near[d][i]] = buf[(i + 3) % 12];

		for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) tmp[i][j] = arr[cube[d][i][j]];

		//돌린거 복사하기
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) 
				arr[cube[d][2-j][i]] = tmp[i][j];
		}
	}
}



int main() {

	conv['-'] = 1;
	conv['+'] = 3;
	conv['U'] = U;
	conv['D'] = D;
	conv['F'] = F;
	conv['B'] = B;
	conv['L'] = L;
	conv['R'] = R;


	int i, j, k, h, T;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++) cube[i][j][k] = i * 9 + j * 3 + k; //큐브에 번호 주고, 이 번호는 arr[index]의 인덱스로 쓰일것

	string a;
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> n;
		for (j = 0; j < 6; j++) memset(arr + j * 9, colors[j], 9); //초기화
		for (j = 0; j < n; j++) {
			cin >> a;
			int d = conv[a[0]], cnt = conv[a[1]]; //enum 사용, -면 1번 +면 3번
			rotate((DIR)d, cnt);
			/*
			cout << j << "번째 회전: " << endl;
			for (k = 0; k < 3; k++) {
				for (h = 0; h < 3; h++)
					cout << arr[cube[0][k][h]];
				cout << endl;
			}
			cout << endl;
			*/
		}
		for (k = 0; k < 3; k++) {
			for (h = 0; h < 3; h++)
				cout << arr[cube[0][k][h]];
			cout << endl;
		}
	}
	return 0;
}


