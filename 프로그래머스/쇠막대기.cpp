#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> st;

int solution(string arrangement) {
    int answer = 0;
    
    for (int i=0; i<arrangement.size(); i++) {
        if (arrangement[i] == '(') {
            st.push(0);
        }
        else {
            if (st.top() == 0) { //레이저면
                st.pop();
                if (!st.empty()) st.top()+=1;
            } else {
                int upper = st.top();
                st.pop();
                answer += (upper+1); 
                if (!st.empty()) st.top() += upper;
            }
        }
    }
    return answer;
}