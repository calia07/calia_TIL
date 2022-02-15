/*
이 문제는 이진 탐색의 binary_search 함수를 사용하여 풀었습니다.


binary_search 함수는 algorithm 헤더가 필요하고 정렬이 되어있어야만 효과가 있습니다!

그리고 만약 binary_search(v.begin(),v.end(),number); 이라고 하면 

number를 벡터 v에서 찾으면 true를 반환하고 못 찾는다면 false를 반환합니다.


하나 더 주의할 점이 있다면 바로 시간 초과인데요!

cin.tie(0);과

cin.sync_with_stdio(0);을 추가하지 않으면 시간 초과에 걸린답니다.

저는 또 잊어버려가지고 시간초과가 나왔습니다...

다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m;
	cin >> n;
	
	vector <int> v;
	
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		if (binary_search(v.begin(), v.end(), num)) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
}
