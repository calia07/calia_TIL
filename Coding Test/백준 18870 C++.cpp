/*이번에는 좌표 압축이라는 문제를 풀었어요!

좌표 압축은 오름차순으로 0부터 숫자를 배정하는 규칙을 가진 문제였어요!

저는 이 문제를 sort와 pair를 이용해서 풀었어요.

먼저 pair vector에 입력받은 숫자와 그 숫자의 순서를 저장해두고 입력받은 숫자를 기준으로 정렬을 

한 번 해줬어요.

그리고 first에 0부터 차례대로 숫자를 넣어주었고 마지막으로

그 숫자를 입력받은 순서를 기준으로 다시 정렬을 해주고 출력을 해주는 과정을 거쳐서 이 문제를 풀었습니다!

 다음은 코드입니다
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;

	vector <pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		pair<int,int> v1 = make_pair(num, i);
		v.push_back(v1);
	}
	sort(v.begin(), v.end());
	int number=-1;
	int same = 0;
	for (int i = 0; i < n; i++) {
		if (same != v[i].first) {
			same = v[i].first;
			number++;
			v[i].first = number;
		}
		else {
			v[i].first = number;
		}
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " ";
	}

}
