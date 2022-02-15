/*
오늘은 이진 탐색에 대해 공부하면서 관련된 문제를 풀어봤습니다.

이진 탐색은 범위 내에서 찾으려는 데이터와 중간지점의 데이터를 비교하면서 원하는 데이터를 찾는 방법입니다.


이 문제에서는 0과 입력받은 m사이에서 중간지점을 상한액으로 정하여 예산을 계산한 뒤에 

만약 예산이 가능한 예산보다 크면 그 왼쪽을 탐색하고 예산이 가능한 예산보다 작으면 오른쪽을 탐색하는 과정을 start 와 end가 같아질 때까지 반복하면 끝입니다!

다음은 코드입니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	cin >> m;

	int start = 0;
	int end = v[v.size() - 1];
	
	int result = 0;

	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			if (v[i] >= mid) {
				total += mid;
			}
			else {
				total += v[i];
			}
		}
		if (total > m) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}
	cout << result;

}
