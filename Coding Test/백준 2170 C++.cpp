/*
오늘은 정렬에 관련된 문제인 선 긋기 문제를 풀었어요.

문제를 정리해보자면 주어진 값대로 선을 긋는데 겹치는 선은 하나로 취급해서 그어진 총 길이가 얼마인지 

구하는 문제였습니다.


저는 값을 모두 입력받아서 벡터에 넣고 정렬한 후에 max와 min값을 이용해서 for문을 이용해 비교해주는 방법을 사용했습니다. 

만약 min이 2고 max 가 7일 때 비교할 벡터의 값이 {5,8}이면 max 값을 8로 갱신해주고

비교할 벡터의 값이 {8,9}이면 max-min값을 sum에 더해준 다음에 새로운 min 값을 8, max값을 9로 설정해주고

마지막에 sum에 max-min값을 더해주었습니다.


이 문제에서 주의할 점은 선이 포함될 때를 고려하는 것이고 시간초과에 유의해야 합니다

처음에 코드를 짰을 때 선이 포함되는 것을 고려하지 않고 max값을 갱신해주어서 틀렸어요.

그리고 매일 cin.tie(0); 과 cin.sync_with_stdio(0);을 추가해주는 것을 잊어서 틀리네요....


다음은 코드 입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> v;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n; cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int min = v[0].first;
	int max = v[0].second;
	int sum = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].second < max) {
			continue;
		}//포함될 때 처리
		if (v[i].first > max) {
			sum += max - min;
			min = v[i].first;
			max = v[i].second;
		}//max보다 비교할 벡터의 요소의 first값이 더 큰 경우 처리
		else {
			max = v[i].second;
		}
	}
	sum += max - min;
	cout << sum;
	return 0;
}
