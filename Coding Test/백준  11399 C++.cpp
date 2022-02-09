//탐욕법 예제

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int atm[1000];// 배열 선언
int main() {
	int n;
	cin >> n;//n 입력
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		atm[i] = num;//입력 받은 값을 배열에 넣기
	}
	sort(atm,atm+n);//algorithm STL을 사용하여 정렬
	
	int answer=0;//변수 선언

	for (int i = n; i > 0; i--) {
		answer = answer + (i * atm[n-i]);
	}//반복하여 값 더하기
	cout << answer;//더한 값 출력
}
