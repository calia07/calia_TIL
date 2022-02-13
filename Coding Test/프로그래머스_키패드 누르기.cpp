/*

키패드를 오른손으로 누르는지 왼손으로 누르는지를 문자열에 이어서 붙여주면 되는 문제였습니다.

1, 4, 7은 무조건 왼손으로 누르고 3, 6, 9는 무조건 오른손으로 누르기 때문에 2, 5, 8, 0을 어떤 손으로 누를지에 관해 알아내는 것이 중요한 문제어요!

저는 우선 pair를 이용해서 키패드를 좌표로 생각했을 때 왼손과 오른손의 위치를 넣어주었습니다.

그리고 2, 5, 8, 0이 나오면 이 숫자들의 좌표와 왼손과 오른손의 좌표의 거리를 구해줘서 더 차이가 적은 쪽 손으로 누르도록 했습니다. 

키패드를 누르면 누른 손은 숫자의 위치로 옮겨주는 과정을 반복했습니다.

*/

#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer ="";
    pair<int,int> left = pair<int,int>(3,0);
    pair<int,int> right = pair<int,int>(3,2);
    pair<int,int> v1;
    for(int i =0;i<numbers.size();i++){
        if(numbers[i]==0 || numbers[i]==2 || numbers[i]==5 || numbers[i]==8){
            if(numbers[i]==0){
                v1 = pair<int,int>(3,1);
            }else if(numbers[i]==2){
                v1 = pair<int,int>(0,1);
            }else if(numbers[i]==5){
                v1 = pair<int,int>(1,1);
            }else if(numbers[i]==8){
                v1 = pair<int,int>(2,1);
            }
            
            int a = abs(left.first-v1.first)+abs(left.second-v1.second);
            int b = abs(right.first-v1.first)+abs(right.second-v1.second);
           
            if(a>b){
                answer.append("R");
                right=v1;
            }else if(a<b){
                answer.append("L");
                left = v1;
            }else{
                if(hand=="left"){
                    answer.append("L");
                    left = v1;
                }else{
                    answer.append("R");
                    right = v1;
                }
            }
        }else if(numbers[i]==1 ||numbers[i]==4 || numbers[i] == 7){
            if(numbers[i]==1){
                left = pair<int,int>(0,0);
            }else if(numbers[i]==4){
                left = pair<int,int>(1,0);
            }else if(numbers[i]==7){
                left = pair<int,int>(2,0);
            }
            answer.append("L");
        }else if(numbers[i]==3 ||numbers[i]==6 || numbers[i] == 9){
            if(numbers[i]==3){
                right = pair<int,int>(0,2);
            }else if(numbers[i]==6){
                right = pair<int,int>(1,2);
            }else if(numbers[i]==9){
                right = pair<int,int>(2,2);
            }
            answer.append("R");
        }
    }
    return answer;
}
