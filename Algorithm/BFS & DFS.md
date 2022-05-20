# DFS(Depth-First Search) & BFS(Breadth-First Search)
## 1. 필수 개념
- ### 스택 : 후입선출의 형태를 가지는 자료구조

```cpp
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

inline void error( char* str ) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};


class ArrayStack
{
	int		data[MAX_STACK_SIZE];	// 요소의 배열
	int		top;					// 요소의 개수

public:
	ArrayStack() { top = -1; }
	~ArrayStack(){}				
	bool isEmpty() { return top == -1; }
	bool isFull()  { return top == MAX_STACK_SIZE-1; }

	void push ( int e ) {
		if( isFull() ) error ("스택 포화 에러");
		data[++top] = e;
	}

	int pop ( ) {	
		if( isEmpty() ) error ("스택 공백 에러");
		return data[top--];
	}

	int peek ( ){
		if( isEmpty() ) error ("스택 공백 에러");
		return data[top];
	}

	void display ( ) {
		printf("[스택 항목의 수 = %2d] ==> ", top+1) ;
		for (int i=0 ; i<=top ; i++ )
			printf("<%2d>", data[i]);
		printf("\n");
	}
};

void main()
{
	ArrayStack stack;
	for( int i=1 ; i<10 ; i++ )
		stack.push( i );

	stack.display();
	stack.pop(  );
	stack.pop(  );
	stack.pop(  );
	stack.display();
}
```

- ### 큐 : 선입선출의 형태를 가지는 자료구조

```cpp
#pragma once
#include <stdio.h>
#include <stdlib.h>

inline void error( char* str ) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE	100

class CircularQueue
{
protected:
	int	front;			
	int	rear;			
	int	data[MAX_QUEUE_SIZE];
public:
	CircularQueue()	{ front = rear = 0; }
	~CircularQueue() { }
	bool isEmpty()	{ return front == rear; }
	bool isFull()	{ return (rear+1)%MAX_QUEUE_SIZE == front; }
	void enqueue( int val ) {
		if( isFull() )
			error("  error: 큐가 포화상태입니다\n");
		else {
			rear = (rear+1) % MAX_QUEUE_SIZE;
			data[rear] = val;
		}
	}
	int dequeue( ) {	
		if( isEmpty() )
			error("  Error: 큐가 공백상태입니다\n");
		else {
			front = (front+1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek( ){	
		if( isEmpty() )
			error("  Error: 큐가 공백상태입니다\n");
		else 
			return data[(front+1) % MAX_QUEUE_SIZE];
	}
	void display( ) {	
		printf( "큐 내용 : ");
		int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
		for( int i = front+1 ; i<=maxi ; i++ )
			printf( "[%2d] ", data[i%MAX_QUEUE_SIZE]);
		printf( "\n");
	}
};

void main()
{
	CircularQueue que;
	for( int i=1 ; i<10 ; i++ )
	    que.enqueue( i );
	que.display();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.display();
}
```
- ### 재귀 함수 :  자기 자신을 다시 호출하는 함수

```cpp
#include <iostream>

using namespace std;

int factorial(int n){
  if(n<=1)
    return 1;
  return n* factorial(n-1);
}

cout << factorial(5);
```

## 2. DFS & BFS란?
- ### DFS (깊이 우선 탐색) : 그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘

![010](https://user-images.githubusercontent.com/71044190/152720722-0f827b5e-1979-4096-ac30-f2699ae6d014.png)

```cpp
#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector <int> graph[9];

void dfs(int x){
	visited[x] = true;
	cout << x <<' ';
	for(int i =0;i<graph[x].size();i++){
		int y = graph[x][i];
		if(!visited[y]) dfs(y);
	}
}

int main(){
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(4);
	
	dfs(1);
}
```

- ### BFS (너비 우선 탐색) : 가까운 노드부터 탐색하는 알고리즘


![011](https://user-images.githubusercontent.com/71044190/152720732-8d32347e-ac48-4fd0-b92f-c3bb3cc595c5.png)

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[9];
vector <int> graph[9];

void bfs(int start){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x<<' ';
		for(int i =0;i<graph[x].size();i++){
			int y = graph[x][i];
			if(!visited[y]){
				q.push(y);
				visited[y] = true;
			}
		}
	}

int main(){

graph[1].push_back(2);
graph[1].push_back(3);
graph[1].push_back(4);

bfs(1);

}

```

출처 : 이것이 취업을 위한 코딩 테스트다(with python) - 나동빈
