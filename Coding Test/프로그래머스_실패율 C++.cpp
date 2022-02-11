/*
정렬에 관한 level 1문제 입니다. 


sort STL을 사용해주었고 compare 함수를 이용해 정렬을 어떻게 할지에 대해 구현해주었습니다.

for문을 이용해서 탐색하면서 스테이즈 숫자 보다 stages벡터에 들어있는 값이 크거나 같으면 cplayer에 1을 더해주고 같으면 nplayer에 1을 더해주고 nplayer/cplayer로 실패율을 구해서 스테이지 숫자와 함께 pair로 벡터에 넣어주고 정렬시킨다음에 스테이지 숫자만 answer 벡터에 차례대로 넣어서 반환하도록했어요.


주의할 점은 여기서 나누기 연산자 /를 사용할 때 소숫점 숫자가 나오려면 int 인 두 요소 중 하나를 double로 변환해줘야 합니다.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<double,int> A, pair<double,int> B){
    if(A.first>B.first){
        return true;
    }
    else if(A.first<B.first){
        return false;
    }else{
        if(A.second<B.second){
            return true;
        }else{
            return false;
        }
    }
    
}

vector<int> solution(int N, vector<int> stages) {
    vector <pair<double, int>> v;
    sort(stages.begin(),stages.end());
    for(int i =1;i<=N;i++){
        int nplayer =0;
        int cplayer =0;
        double a=0;
        for(int j= 0;j<stages.size();j++){
            if(i<=stages[j]){
                cplayer++;
                if(i==stages[j]){
                    nplayer++;
                }
            }
        }
        if(cplayer!=0){
             a = nplayer/(double)cplayer;
        }
  
        v.push_back(pair<double,int>(a,i));
    }
    sort(v.begin(),v.end(),compare);
    vector <int> answer;
    for(int i =0;i<v.size();i++){
        answer.push_back(v[i].second);
    }
    
    
    return answer;
}
