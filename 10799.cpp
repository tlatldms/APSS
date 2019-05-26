#include <iostream>
#include <stack>

using namespace std;

int main () {
  char input[100000];
  cin >> input;
  stack<char> st;
  int i=0, ret=0;

  while (input[i] != '\0') {
   
    if (input[i] == '(') {
      st.push(input[i]);
    } else {
      st.pop();
      if ( input[i-1] == '(' ) {
        ret += st.size();
      } else {
        ret++;
      }

    }
    i++;
  }
  cout << ret;
  return 0;
}
