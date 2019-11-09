//트라이 자료구조 연습
//https://www.crocus.co.kr/1053 참고

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int t,n;

struct Trie {
  Trie * next[10];
  bool is_finish;
  bool is_next;
  Trie() {
    is_finish = is_next = false;
    fill(next, next+10, nullptr);
  }
  ~Trie() {
    for (int i=0; i<10; i++) {
      if (next[i]) delete(next[i]); 
    }
  }

  bool insert(char *key) {
    if (*key == '\0') { // 끝남
      is_finish = true;

      if (is_next) { //끝났는데 자식이 있음
        return 0;
      } else return 1;
    }

    int now_num = *key - '0';
    
    if (!next[now_num]) { //child가 없음
      next[now_num] = new Trie;
    }

    is_next = true;

    bool child_ret = next[now_num]->insert(key+1);
  //1. key가 끝난것도 아닌데 is_finish가 true면 일관성X 
  //2. child에서 일관성 없는 애가 나왔음
    return !is_finish && child_ret;
  }
};

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    Trie * root = new Trie;
    bool flag=1;
    for (int i=0; i<n; i++) {
      char now_phone[11]; 
      scanf("%s", now_phone);
      if (flag) {
        if (root->insert(now_phone)==0) {
          flag=0;
        }
      }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
    delete (root);
  }

  return 0;
}
