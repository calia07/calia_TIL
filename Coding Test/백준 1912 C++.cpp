/*
오늘은 다이나믹 프로그래밍에 대해 공부하면서 관련된 문제를 풀어봤어요!

다이나믹 프로그래밍은 메모리를 적절하게 사용해서 수행하는 시간의 효율성을 향상시키는 방법입니다.

for문을 이용해서 이전항을 더할 것인지 더하지 않을 것인지를 판별하기 위해 두 값 중 큰 값을 선택해서 arr배열에 

값을 넣도록 했습니다. 이 과정을 반복하고 마지막에는 arr 배열의 값 중 가장 큰 값을 출력하면 끝입니다!



다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
int arr[100001];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			arr[i] = v[i];
		}
		else {
			arr[i] = max(arr[i - 1] + v[i], v[i]);
		}
	}
	int max = -1000;
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	cout << max;
}
