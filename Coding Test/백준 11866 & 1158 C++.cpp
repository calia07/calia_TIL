#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	deque <int> dq;
	vector <int> v;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	while (dq.size()!=0) {
		for (int i = 0; i < K-1; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		v.push_back(dq.front());
		dq.pop_front();
	}
	cout << "<";
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1)
			cout << v[i] << ", ";
		else
			cout << v[i];
	}
	cout << ">";
}
