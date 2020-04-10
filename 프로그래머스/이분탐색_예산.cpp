#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int len, mb, found_mid;
vector<int> bgs;
int sum_so_far[100001];
void devide(int start, int end) {
    if (start == end) {
        found_mid = start;
        return;
    }
    int mid = (start+end)/2;
    if (sum_so_far[mid-1] + bgs[mid]*(len-mid) == mb) {
        found_mid = start; return;
    }
    else if (sum_so_far[mid-1] + bgs[mid]*(len-mid) < mb) {
        devide(mid+1, end);
    } else {
        devide(start, mid);
    }
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    len = budgets.size();
    bgs = budgets;
    mb=M;
    sort(bgs.begin(), bgs.end());
    sum_so_far[0] = bgs[0];
    for (int i=1; i<len; i++) {
        sum_so_far[i] = sum_so_far[i-1]+bgs[i];
    }
    
    devide(0, len-1);
    int tmp_lb;
    for (int i=bgs[found_mid]; i >= bgs[found_mid-1]; i--) {
        if (sum_so_far[found_mid-1] + i*(len-found_mid) <=M) {
            answer = i; break;
        }
    }
    cout << answer;
    return answer;
}