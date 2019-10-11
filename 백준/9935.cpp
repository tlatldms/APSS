#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string str, exp;
	cin >> str >> exp;
	int idx=0, flag, tmp;
	char t2, e0;
	e0 = exp[0];
	size_t b = exp.length();

	while (t2 = str[idx]) {
		cout << t2<<endl;
		if (t2 == e0) {
			//cout << "here idx: " << idx << endl;
			//cout << str << endl;
			tmp = 0;
			flag = 1;
			for (int i = 0; i < b; i++) {
				if (str[idx + i] != exp[tmp++]) {
					flag = 0;
					break;
				}
			}

			if (flag) {
				str.replace(idx, b, "");
				idx = max(-1, int(idx - b));
			}
		}
		idx++;
	}

	if (str.empty()) cout << "FRULA";
	else cout << str;
	
	return 0;
}