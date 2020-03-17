#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;
int total_cnt;

struct trie {
    trie * next[26];
    int count=1;

};

void dfs(trie * t) {
    if (t->count == 1) {
        total_cnt++;
        return;
    } else {
        total_cnt += t->count;
    }

    for (int i=0; i<26; i++) {
        if (t->next[i] == NULL) continue;
        dfs(t->next[i]);
        
    }
    
}


void find(const char * str, trie * t) {
    if (*str == '\0') return;
    int alpha_num = (*str)-'a';
    if (t->next[alpha_num]->count == 1) {
        total_cnt++;  
        return;
    }
    else {
       total_cnt++;

       find(str+1, t->next[alpha_num]);
    }
}



void make(const char * str, trie * t) {
    if (*str == '\0') {
        return;
    }
    int alpha_num = (*str)-'a';
    trie * node;
    trie * next_node = t->next[alpha_num];
    if (next_node == NULL) {
        node = new trie();
        t->next[alpha_num] = node;
    } else {
        node = next_node;
        (node->count)++;
    }
 
    make(str+1, node);
}

int solution(vector<string> words) {
    int answer = 0;
    trie * root = new trie();
    root->count = 0;
    for (auto s: words) {
        make(s.c_str(), root);
       
    }
    
    
    //dfs(root);

    for (auto s: words) {
        find(s.c_str(), root);
    }
    
 
 
    answer =  total_cnt;
    return answer;
}