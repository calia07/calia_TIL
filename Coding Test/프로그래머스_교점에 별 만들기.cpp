// 이 문제는 자료형을 고려해야하는 문제 
// 자료형을 int => long long으로 바꿔야 통과

``` 
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair< long long, long long>a, pair< long long, long long>b){
    return a.second >b.second;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair< long long, long long>> v;
    
    for( int i =0;i<line.size();i++){
        for( int j=0;j<i;j++){
             long long a,b,e;
            a=line[i][0];
            b=line[i][1];
            e=line[i][2];
             long long c,d,f;
            c=line[j][0];
            d=line[j][1];
            f=line[j][2];
            
            if((a*d-b*c) !=0){
            double x=(double)(b*f-e*d)/(a*d-b*c);
            double y =(double) (e*c-a*f)/(a*d-b*c);
            if(x-(long long)x ==0 && y-(long long)y==0){
                
                v.push_back(pair< long long, long long>((long long)x,(long long)y));
            }    
            }
            
        }      
        
    }
    sort(v.begin(),v.end());
    long long  x_min=v[0].first;
    long long x_max=v[v.size()-1].first;

    sort(v.begin(),v.end(),compare);
     long long y_min=v[v.size()-1].second;
     long long y_max=v[0].second;

    
    
  v.erase(unique(v.begin(),v.end()),v.end());
     long long num_x=x_max-x_min;
    
     long long arr[10001][10001];
    
    for( int i =0;i<num_x+1;i++){
        for( int j=0;j<y_max-y_min+1;j++){
            arr[i][j]=0;
        }
    }
    
    for( int i=0;i<v.size();i++){
            arr[v[i].first-(x_min)][v[i].second-(y_min)]=1;
    }
    
    for( int i=y_max-y_min;i>=0;i--){
        string ans="";
        for( int j=0;j<=num_x;j++){
            if(arr[j][i]==1){
                ans+="*";
            }else{
                ans+=".";
            }
        }
        answer.push_back(ans);
        
    }
    
    return answer;
}
```
