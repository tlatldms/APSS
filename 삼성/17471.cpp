#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int popul[11];
vector<vector<int>> input(11);
int n;
bool visit[11];
int sep[11];
int cnt_first, cnt_second;
int m = 9999999;

void check_first(int p) {
	visit[p] = true;
	cnt_first++;
	for (int x : input[p]) {
		if (!visit[x] && sep[x]==1) check_first(x);
	}
}

void check_second(int p) {
	visit[p] = true;
	cnt_second++;
	for (int x : input[p]) {
		if (!visit[x] && sep[x]==2) check_second(x);
	}
}

void fun(int x) {
	vector<int> tmp;
	for (int i = 0; i < n-x; i++) {
		tmp.push_back(0);
	}
	for (int i = 0; i < x; i++) {
		tmp.push_back(1);
	}
 	do {
		vector<int> first, second;
		memset(visit, false, sizeof(visit));
		memset(sep, 0, sizeof(sep));
		cnt_first = 0;
		cnt_second = 0;
		for (int i = 0; i < n; i++) {
			if (tmp[i]) {
				sep[i + 1] = 1;
				first.push_back(i + 1);
			}
			else {
				sep[i + 1] = 2;
				second.push_back(i + 1);
			}
		}
		
		check_first(first[0]);
		check_second(second[0]);
		
		if ((int)(first.size()) == cnt_first && (int)(second.size()) == cnt_second) {
			int sum_f = 0, sum_s = 0;
			//cout << "first : ";
			for (int f : first) {
				sum_f += popul[f];
				//cout << f << " ";
			}
			//cout << "\nsecond: ";
			for (int s : second) {
				sum_s += popul[s];
				//cout << s << " ";
			}

			m = min(m, abs(sum_f - sum_s));

			//cout << "\n �α� ����: " <<abs(sum_f - sum_s) <<"\n\n\n";
		}

	} while (next_permutation(tmp.begin(), tmp.end()));
}


void print() {
	for (int i = 1; i <= n; i++) {
		for (auto x : input[i]) cout << x << " ";
		cout << "\n";
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> popul[i];
	}

	int c, a;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		for (int j = 0; j < c; j++) {
			cin >> a;
			input[i].push_back(a);
		}
	}

	for (int i = 1; i < n; i++) {
		fun(i);
	}
	if (m == 9999999) cout << -1;
	else cout << m;
	return 0;
}