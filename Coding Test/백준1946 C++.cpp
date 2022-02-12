/*
정렬에 관한 문제입니다! 


다음은 시간초과로 틀린 코드입니다.

정렬을 시킨 다음에 하나하나 다 비교를 해서 값을 구했더니 시간초과가 나왔어요.

코드를 짤 때부터 시간초과가 나올 것 같다고 예상은 하고 있었어요....
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n; cin >> n;
	while (n--) {
		vector <pair<int, int>> v;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(pair<int, int>(a, b));
		}
		sort(v.begin(), v.end());
		
		for (int i = 0; i < v.size(); i++) {
			int A = v[i].first; int B = v[i].second;
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j].first != 0 && v[j].second != 0) {
					if(v[j].first > A && v[j].second > B) {
					v[j].first = 0;
					v[j].first = 0;
				
					}
				}
			}
		}
		int answer = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first != 0) {
				answer++;
			}
		}
		cout << answer<<'\n';
	}
}
*/

/*

그래서 pair의 first 값을 기준으로 정렬 시키고 min값을 v[0]의 second값으로 초기화시킨 다음에

차례대로 second값과 min을 비교하면서 만약 min 값보다 더 높은 등수를 받았으면 answer에 1을 더해주고 

최솟값 min을 갱신해주는 과정으로 바꾸니까 훨씬 간단해졌고 코드 시간도 통과했습니다!

다음은 통과된 코드입니다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n; cin >> n;
	while (n--) {
		vector <pair<int, int>> v;
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(pair<int, int>(a, b));
		}
		sort(v.begin(), v.end());
		
		int min = v[0].second;
		int answer = 1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i].second < min) {
				answer++;
				min = v[i].second;
			}
		}
		cout << answer<<'\n';
	}
}
