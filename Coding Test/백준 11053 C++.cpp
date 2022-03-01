/*
다이나믹 프로그래밍 문제를 복습하면서 관련된 문제를 풀어봤습니다!

이 문제는 이중 중첩 for문을 돌리면서 자기보다 앞에 있는 수 중 자기보다 작은 값이 있으면 그 값의 인덱스로 접근해서 1을 증가시키거나 자기 자신의 인덱스의 배열 값이 더 크면 유지하거나 둘 중 하나를 선택하는 과정을 반복하면 끝입니다.


즉 10 20 30 이라는 수열이 있을 때 먼저 d 배열에는 수열의 크기만큼 1이라는 값을 넣어주고 시작합니다.

만약 20을 예로 든다면 앞에 있는 10이 20보다 작고 2인 d[0]+1의 값이 1인 d[1]의 값보다 크기 때문에 d[1]에는 2라는 값을 넣어주게 됩니다. 이 과정을 수열의 끝까지 반복하면 됩니다!


다음은 코드입니다. 
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
		for (int j =0; j <i; j++) {
			if (v[i] > v[j]) {
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
