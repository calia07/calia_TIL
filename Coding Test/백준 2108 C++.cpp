/*

이 문제는 주어진 배열을 정렬해서 평균,중앙값, 최빈값, 최댓값과 최솟값의 차이를 출력하는 문제입니다.

평균과 중앙값, 최댓값과 최솟값의 차이를 출력하는 것은 간단하지만

최빈값에서 시간초과가 자꾸 발생해서 다시 시도를 하게 되었습니다.

그러다 찾은 방법으로는 값의 범위가 -4000~4000 이기 때문에 크기가 8001인 배열을 선언하고 

음수도 있기 때문에 값에 4000을 더한 값을 인덱스로 하여 1씩 더했습니다.

그리고 이 배열의 최댓값을 구해서 최댓값과 같은 값을 가지는 인덱스를 다른 벡터에 넣어 

벡터의 크기가 2 이상이면 2번째 요소를 출력하도록해서 해결했습니다!

*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.sync_with_stdio(0);

	int n; cin >> n;
	vector <int> v;
	bool Second = false;
	int ab[8001] = { 0 };
	int mode=0;
	float m=0;
	int c = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
		sum += num;
		if (num < 0) {
			ab[num+4000]++;
		}
		else {
			ab[num + 4000]++;
		}
	}
	m=(round((double)sum / n) == 0) ? 0 :  round((double)sum / n);

	cout << m << '\n';
	sort(v.begin(), v.end());
	cout << v[n / 2] << '\n';
	vector <int> GetMode;
	int max = *max_element(ab,ab+8001);
	for (int i = 0; i < 8001; i++) {
		if (ab[i] == max) {
			GetMode.push_back(i - 4000);
		}
	}
	


	if (GetMode.size() > 1) {
		cout << GetMode[1] << '\n';
	}
	else {
		cout << GetMode[0] << '\n';
	}
	
	
	cout << v[n - 1] - v[0];

}
