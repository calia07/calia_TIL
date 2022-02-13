/*

각 단계 별로 차례때로 하나씩 처리를 해주면 되는 문제였습니다.

저는 제거하는 방법 중에서 간단하게 처리할 수 있는 방법이 떠오르지 않아서 그냥 공백으로 바꾸고

erase와 remove함수를 이용해서 공백 제거를 단계마다 반복해줬습니다.


각 단계는 아래 코드에 주석으로 표시해놓았습니다.

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
   for(int i =0;i<new_id.size();i++){// 1단계, 2단계 실행
       if(new_id[i]>='A' && new_id[i]<='Z'){
           new_id[i]= tolower(new_id[i]);
       }else if(new_id[i]>='a'&& new_id[i]<='z'){
           continue;
       }else if(new_id[i]>='0' && new_id[i]<='9'){
           continue;
       }else if(new_id[i]=='-' || new_id[i]=='_'||new_id[i]=='.'){
           continue;
       }else{
           new_id[i]=' ';
       }
   }
     new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());//공백 제거

    for(int i =0;i<new_id.size()-1;i++){//3단계 실행
        if(new_id[i]=='.'&&new_id[i+1]=='.'){
            new_id[i]=' ';
        }
    }
   
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());//공백 제거
    if(new_id[0]=='.'){//4_1단계
        new_id[0]=' ';
    }
    if(new_id[new_id.size()-1]=='.'){//4_2단계
        new_id[new_id.size()-1]=' ';
    }
     new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());//공백 제거
    if(new_id.size()==0)//5단계 실행
        new_id+='a';
    if(new_id.size()>15){//6단계 실행
        if(new_id[14]=='.'){
            new_id[14]=' ';
        }
        for(int i =15;i<new_id.size();i++){
            new_id[i]=' ';
        }
    }
     new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());//공백 제거
    if(new_id.size()<3){//7단계 실행
        while(new_id.size()!=3){
            new_id+=new_id[new_id.size()-1];
        }
    }
    return new_id;//결과 반환
}
