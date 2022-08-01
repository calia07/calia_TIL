#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}



int main(){
    vector <pair<int,int>> v;
    
    for (int i =1;i<=8;i++){
        int num;
        cin>>num;
        v.push_back(pair<int,int>(num,i));
        
    }
    sort(v.begin(),v.end(),compare);
    
    int sum =0;
    vector <int> answer;
    
    for(int i=3;i<8;i++){
        sum+=v[i].first;
        answer.push_back(v[i].second);
    }
    
    sort(answer.begin(),answer.end());
    
    cout << sum << '\n';
    for(int i =0;i<answer.size();i++){
        cout << answer[i]<<' ';
    }
}
