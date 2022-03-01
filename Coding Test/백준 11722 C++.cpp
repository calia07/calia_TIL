/*
이 문제는 위의 문제와 거의 동일합니다. 위의 코드에서 한 곳만 바꿔주면 끝입니다.

비교 연산자만 수정해주면 감소하는 수열이 됩니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[1001] = { 1 };
vector <int> v;

int main() {
	int x; cin >> x;
	for (int i = 0; i < x; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i < x; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] < v[j]) {//비교 연산자 수정
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < x; i++) {
		if (d[i] > answer) {
			answer = d[i];
		}
	}
	cout << answer;
}

