/*
저는 처음에 이 문제를 벡터로 풀어서 시간초과가 나왔습니다. cin.tie(0)같은 처리도 모두 해줬는데 왜 틀렸을까 생각을 해봤고 문제를 다시 읽어봤어요. 

문제에서 나오는 숫자는 20까지로 주어져 있더라고요. 

그러면 bool 배열을 사용해서 존재하는지 안하는지만 판별해야겠다는 힌트를 얻었어요. 

문제에 나온 조건 처럼 add가 나오면 추가하고 remove는 삭제하는 등등 조건을 모두 구현하고 제출하니까 

그제야 맞더라고요!


아래는 처음에 vector를 이용해 풀어서 시간초과로 틀린 코드입니다.
*/

/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <int> v;
vector <int> a;

bool Find(int num) {
	
	for (int i = 0; i < v.size(); i++) {
		if (num == v[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
    cout.tie(0);

	for (int i = 1; i <= 20; i++) {
		a.push_back(i);
	}
	int n; cin >> n;
	while (n--) {
		
		string s; cin >> s;
		if (s == "add") {
			int num; cin >> num;
			if (!Find(num)){
				v.push_back(num);
			}
		}
		else if (s == "remove") {
			int num; cin >> num;
			for (int i = 0; i < v.size(); i++) {
				if (num == v[i]) {
					v[i] = 0;
				}
			}
		}
		else if (s == "check") {
			int num; cin >> num;
			if (Find(num)) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (s == "toggle") {
			int num; cin >> num;
			if (!Find(num)) {
				v.push_back(num);
			}
			else {
				for (int i = 0; i < v.size(); i++) {
					if (num == v[i]) {
						v[i] = 0;
					}
				}
			}
		}
		else if (s == "all") {
			
			v = a;
		}
		else {
			v.clear();
		}
	}
}
 */

//아래는 bool 배열로 존재하는지 안하는지 판별해서 푼 코드입니다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool set[21];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cout.tie(0);

	int n; cin >> n;
	while (n--) {
		
		string s; cin >> s;
		if (s == "add") {
			int num; cin >> num;
			set[num] = true;
		}
		else if (s == "remove") {
			int num; cin >> num;
			set[num] = false;
		}
		else if (s == "check") {
			int num; cin >> num;
			if (set[num] == true) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (s == "toggle") {
			int num; cin >> num;
			if (set[num]) {
				set[num] = false;
			}
			else {
				set[num] = true;
			}
		}
		else if (s == "all") {
			for (int i = 1; i < 21; i++) {
				set[i] = true;
			}
		}
		else {
			for (int i = 1; i < 21; i++) {
				set[i] = false;
			}
		}
	}
}
