#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, m=99999999;
int input[21][21];
int search() {
  int i,j, st, li;
  vector<int> tmp;
  for (i=0; i<N/2; i++) tmp.push_back(0);
  for (i=0; i<N/2; i++) tmp.push_back(1);
  do {
    vector<int> start, link;
    st=0, li=0;
    for (i=0; i<N; i++) {
      if (tmp[i]) start.push_back(i);
      else link.push_back(i);
    }
  
    for (auto a: start) {
      for (auto b: start) {
        if (a == b) continue;
        st += input[a][b];
      }
    }

    for (auto a: link) {
      for (auto b: link) {
        if (a == b) continue;
        li += input[a][b];
      }
    }
    m = min (m, abs(st - li));
    
  /*  
    cout<<"start : " << endl;
    for (auto a:start) cout<<a<<endl;
    cout << "link: " << endl;
    for (auto a: link) cout << a << endl;
    cout << "st: " << st << "li: " << li << endl;
    cout << "st-li: " << st-li << endl;
    */
  } while (next_permutation(tmp.begin(), tmp.end()));

  return m;
}

int main() {
  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> input[i][j];
  }
  cout << search();
  return 0;
}
