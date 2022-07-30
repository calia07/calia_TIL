/*
오늘은 정렬 문제를 풀어봤습니다!

빈도가 높은 수부터 나열하되 빈도가 같을 때는 먼저 나온 수가 앞에 가도록 하는 것이 문제였는데요.

저는 우선 모든 수를 1과 pair로 vector v에 넣었습니다. 

그리고 vector의 뒤에서부터 탐색을 해서 앞에 요소 중 중복인 수가 있으면 그 요소의 second 값을 1증가시키고 뒤의 요소를 지우는 반복문을 사용했습니다.

그리고 stable_sort를 사용했는데요!

stable_sort는 하나의 요소를 기준으로 정렬했을 때 나머지 요소들의 순서는 그대로 남아 있도록 정렬하는 기능을 가지고 있습니다. 

이 때 compare 함수를 사용하지 않으면 원하는 값이 나오지 않기 때문에 compare 함수를 사용해서 기준을 정해주었습니다.

그리고 출력은 중첩반복문을 이용해서 마무리해주었습니다. 

아래는 코드입니다!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> v1, pair<int, int>v2) {
	return v1.second > v2.second;
}

int main() {
	vector <pair<int, int>> v;

	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {

		int num; cin >> num;
		v.push_back(pair<int, int>(num, 1));//모든 요소 vector v에 넣기
	}

	for (int i = v.size() - 1; i >= 0; i--) {//중복 제거 반복문
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first == v[i].first && j != i) {
				v[j].second++;
				v.erase(v.begin() + i);
				break;
			}
		}
	}

	stable_sort(v.begin(), v.end(), compare);//정렬

	for (int i = 0; i < v.size(); i++) {//출력
		for (int j = 0; j < v[i].second; j++) {
			cout << v[i].first << " ";
		}
	}


}
