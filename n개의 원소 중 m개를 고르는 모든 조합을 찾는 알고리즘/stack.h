/*
   이 코드를 보기 전에 먼저 common.h의 주석을 읽고 오는걸 추천해!
   거기에 #ifndef, #endif, #define에 대한 설명이 있을거야.

   이건 array로 stack을 구현한 소스 코드야.
   오히려 구현의 이해는 queue보다는 쉬울거야.
   먼저 top이 현재 stack의 원소 갯수를 저장한 변수야.
   stack에 데이터를 push하면 top이 하나 올라가는거고,
   반대로 pop하면 top이 하나 줄어드는거지.
 
   이 구현도 queue와 마찬가지로 예외 처리가 되어있지 않아.
   그러니깐 함수를 잘 사용하는게 중요해!
   이 구현 역시 어렵지 않으니 잘 익혀서 유용하게 썼으면 좋겠다!
*/

#ifndef __STACK_H__
#define __STACK_H__

#include "common.h"

int top = 0;
int stack[SIZE + 1];

void s_push(int val) {
	stack[top ++] = val;
}

int s_pop() {
	return stack[-- top];
}

bool s_is_empty() {
	return top == 0 ? true : false;
}

#endif//__STACK_H__
