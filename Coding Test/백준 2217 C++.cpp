/*
로프를 사용해서 최대로 버틸 수 있는 무게를 구하는 문제였습니다.

저는 로프를 다 사용하지 않아도 된다는 점에서 우선 정렬을 한 다음에 for문을 이용해서 하나를 사용했을 때,

두 개를 사용했을 때... n개를 사용했을 때 최대를 버틸 수 있는 무게를 비교해서 number라는 변수에 최댓값을 넣어주도록 했습니다.


다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n; cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(),compare);

	int number = 0;
	for (int i = 1; i <= n; i++) {
		if (number < v[i - 1] * i) {
			number = v[i - 1] * i;
		}

	}
	cout << number;
}
