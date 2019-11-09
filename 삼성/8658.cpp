#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fun(int tc, vector<int> nums) {
  int _max = -1;
  int _min = 1000001;

  for (auto a: nums) {
    int sum=0;
    while (a != 0) {
      sum += a%10;
      a /= 10;
    }
    _max = max(_max, sum);
    _min = min(_min, sum);
  }
  cout<<tc<<" "<<_max<<" "<<_min<<endl;
  return;
}

int main() {
  int T, i, j,a;
  cin >> T;
  for (i=0; i<T; i++) {
    vector<int> nums;
    for (j=0; j<10; j++) {
      cin >> a;
      nums.push_back(a);
    }
    fun(i+1, nums);
  }

  return 0;
}
