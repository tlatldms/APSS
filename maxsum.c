#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	// 8 -7 4 -3 6 3 -8 3 4
	int n,i;
	scanf("%d", &n);
	int* arr = malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d\n",betterMaxSum(arr, n));
	printf("%d\n", fastMaxSum(arr, 0, n-1));
	printf("%d\n", fastestMaxSum(arr, n));
}

int betterMaxSum(int* arr, int n) {
	int i, j,ret=-987654321;
	for (i = 0; i < n; i++) {
		int sum = 0;
		for (j = i; j < n; j++) {
			sum += arr[j];
			ret = max(ret,sum);
		}
	}
	return ret;
}

int fastMaxSum(int* arr, int low, int high) {
	if (low == high) return arr[low];
	int mid = (low + high) / 2;
	//�� �κп� �����ִ� �ִ� �� ���� ���ϱ�. 2���
	int left = -987654321, right = -987654321, sum = 0 , i;
	//���� 2���� ���ʹ迭
	for (i = mid; i >= low; i--) {
		sum += arr[i];
		left = max(left, sum);
	}
	//������
	sum = 0;
	for (i = mid+1; i <= high; i++) {
		sum += arr[i];
		right = max(right, sum);
	}
	//�����̳� �����ʿ��� ���Ѱ�쿡�� ��ͷ�
	int single = max(fastMaxSum(arr, low, mid), fastMaxSum(arr, mid + 1, high));

	//�� ��� �� �ִ�ġ ��ȯ
	return max(left + right, single);
}

int fastestMaxSum(int* arr, int n) {
	int ret = -987654321, psum = 0;
	for (int i = 0; i < n; i++) {
		psum = max(psum, 0) + arr[i];
		ret = max(psum, ret);
	}
	return ret;
}