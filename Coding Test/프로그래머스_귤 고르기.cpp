

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int arr[10000001]={0};

//1번 방법
bool compare(int a, int b){
    return a>b;
}
int solution(int k,vector<int> tangerine){
    for(int i =0;i<tangerine.size();i++){
        arr[tangerine[i]]++;
    }
    sort(arr,arr+10000001,compare);

    int answer = 0;
    for(int i =0;i<10000001;i++){
        k=k-arr[i];
        answer++;
        if(k<=0){
            break;
        }
    }
    return answer;
}

//2번째 방법


bool compare(pair<int,int> v1, pair<int,int>v2){
    return v1.second>v2.second;
}
vector<pair<int,int>> v;
int solution(int k, vector<int> tangerine) {
    for(int i =0;i<10000001;i++){
        v.push_back(pair<int,int>(i,0));
    }
    for(int i =0;i<tangerine.size();i++){
        v[tangerine[i]].second++;
    }
    sort(v.begin(),v.end(),compare);
    int answer = 0;
    for(int i =0;i<10000001;i++){
        k=k-v[i].second;
        answer++;
        if(k<=0){
            break;
        }
    }
    return answer;
}
