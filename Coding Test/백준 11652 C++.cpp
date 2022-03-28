/*
오늘은 정렬에 관련된 문제를 풀어봤습니다.

문제를 풀 때는 조건이 정말 중요하다는 점을 다시 한 번 알게 해준 문제였습니다.

수가 어마어마하게 크게 주어졌는데 이를 고려하지 않고 자료형을 int로 해가지고 틀렸습니다.....


우선 문제는 최빈값을 구하는 문제였습니다. 그래서 정렬을 시킨 후에 freq, count를 선언하고

for문으로 i번째 값과 i+1번째 값을 비교해서 같으면 count를 1 증가시켜주고 다르면 1로 초기화시킵니다.

그리고 freq보다 count가 더 크면 freq에 count의 값을 넣고 최빈값을 나타내는 mode에 i번째 값을 넣었습니다.

이 과정을 반복하고 마지막에 최빈값 mode를 출력시키면 끝입니다!


다음은 소스코드입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.sync_with_stdio(0);

	vector <long long> v;//자료형 조심

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long num; cin >> num;//자료형 조심
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int freq = 1;
	int count = 1; 
	long long mode=v[0];//자료형 조심

	for (int i = 0; i < n-1; i++) {
		if (v[i] == v[i + 1]) {
			count++;
		}
		else {
			count = 1;
		}
		if (count > freq) {
			freq = count;
			mode = v[i];
		}
	}
	cout << mode;
}
