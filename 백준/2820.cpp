#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int salary[500001];
vector<bool> visited(500001);
vector <vector<int> > subord (500001);
int N, M;


void change_sal(int superv, int increase) {
	for (int a : subord[superv]) {
		if (!visited[a]) {
			visited[a] = true;
			salary[a] += increase;
			change_sal(a, increase);
		}
	}
}


int main() {
	cin >> N >> M >> salary[1];
	int i, tmp_super, tmp_increase, tmp_print, a;
	char tmp;

	for (i = 2; i <= N; i++) {
		subord[1].push_back(i);
		cin >> salary[i] >> a;
		subord[a].push_back(i);
	}

	for (i = 0; i < M; i++) {
		cin >> tmp;
		//cout << "tmp: " << tmp << endl;
		if (tmp == 'p') {
			//cout << "in p" << endl;
			visited = vector<bool> (500001);
			cin >> tmp_super >> tmp_increase;
			change_sal(tmp_super, tmp_increase);
		}
		else if (tmp=='u') {
			//cout << "in u" << endl;
			cin >> tmp_print;
			cout << salary[tmp_print]<<endl;
		}
	}
	return 0;
}