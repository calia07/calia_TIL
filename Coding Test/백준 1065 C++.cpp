/*
오늘은 함수 관련된 문제를 풀어봤습니다.

한수란 각 자리의 수가 등차수열을 이루는 수를 뜻합니다.

저는  정수값을 매개변수로 받아서 정수를  반환하는 method 라는 함수를 선언했습니다.

만약 매개변수로 받은 값이 두자리수 이하이면 무조건 등차수열을 이루기 때문에 그 값을 반환해줍니다.

세자리일 때는 반복문으로 각 자리의 수를 매개변수 a,b,c에 넣어서 등차수열인지 확인한 후 한수이면 answer에 1을 더해주도록 해서 이 answer값을 반환해주도록 했습니다.

마지막으로 1000을 매개변수로 받으면 이는 999일때의 값과 같기 때문에 999일 때의 값을 구해서 return 해주었습니다.



아래는 소스코드입니다.
*/


#include <iostream>

using namespace std;

int method(int x) {
	
	if (x < 100) {
		return x;
	}
	else if (x < 1000) {
		int answer = 99;
		int a, b, c;
		for (int i = 100; i <= x; i++) {
			a = i / 100;
			b = (i%100)/10;
			c = i % 10;
			if ((a - b) == (b - c)) {
				answer++;
			}
		}
		return answer;
	}
	else {
		int answer = 99;
		int a, b, c;
		for (int i = 100; i <= x-1; i++) {
			a = i / 100;
			b = (i % 100) / 10;
			c = i % 10;
			if (a - b == b - c) {
				answer++;
			}
		}
		return answer;
	}
}

int main() {
	int num; cin >> num;
	cout << method(num);
}
