#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int N;
bool again(string s, char new_c) {
	string ss = s + new_c;
	for (int i = 1; i <= ss.size()/2; i++) {
		string endd = ss.substr(ss.size() - i);
		string frontt = ss.substr(ss.size() - 2 * i, i);
		//cout << "ss: " << ss << "front: " << front << " , end :" << end << endl;
		if (endd.compare(frontt) == 0) return false;
	}

	return true;
}

void dfs(string s) {
	if (s.size() == N) {
		cout << s;
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		char temp = '0' + i;
		if (again(s,temp)) {
			//cout << "i: " << i << ", s: " << s << endl;
			dfs(s + temp);
		}
	}
}

int main() {
	cin >> N;
	dfs("1");
	return 0;
}