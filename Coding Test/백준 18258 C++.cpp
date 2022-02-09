//큐2 문제이므로 queue STL 이용

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);//시간 초과를 막기 위한 장치

	int n; cin >> n;
	queue <int> q;//큐 선언
	while (n--) {
		string s;
		cin >> s;
		if (s == "push")//문자열 비교 후 명령 처리
		{
			int num; cin >> num;
			q.push(num);
		}
		else if (s == "pop") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s == "size") {
			cout << q.size() << '\n';
		}
		else if (s == "empty") {
			cout << q.empty() << '\n';
		}
		else if (s == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}
}
