/** 
-과제 진행하기

- 해결방법
  1. startTime과 playTime을 forEach문을 이용해 string에서 int형으로 변환해준다.
  2. 세가지 변수를 선언해준다.
    - return할 answer
    - 시간내에 해결하지 못한 과제를 담을 배열 keep
    - 현재 시간 time
  3. 각각의 경우를 나누어 알고리즘 짜기
    (1) 다음 과제 시작 시간까지 현재 과제를 완료한 경우
      - keep 배열에서 최근 과제를 pop하여 비교
    (2) 다음 과제 시작 시간과 현재 과제 완료 시점이 같은 경우
      - 바로 다음 과제 시작
    (3) 다음 과제 시작 시간 전에 현재 과제를 완료하지 못한 경우
      - 현재 과제를 남은 시간과 함께 keep 배열에 저장

- 오답 요인
  1. keep 배열을 이용해서 for문을 돌릴 때 keep.length를 기준으로 돌렸는데 keep은 계속 pop해서 length가 줄어들었기 때문에 오답 발생
  2. 다음 과제 시작 시간과 현재 과제 완료 시점이 같은 경우에 현재 시간에 값을 잘못 넣음
**/

function solution(plans) {
    plans.forEach((el)=> {
        el[1]=parseInt(el[1].slice(0,2))*60+parseInt(el[1].slice(3));
        el[2]=parseInt(el[2])
    } )
    plans.sort((a,b)=>a[1]-b[1])

    let answer = [];
    let keep = [];
    let time=plans[0][1];
    
    for(let i =0;i<plans.length;i++){
        
        // 마지막 과제일 경우
        if(i==plans.length-1){
            answer.push(plans[i][0]);
            keep.reverse().forEach((el)=>answer.push(el[0]));
            return answer;
        }
      
        //  다음 과제 시작 시간까지 현재 과제를 완료한 경우
        if(time+plans[i][2]<plans[i+1][1]){
            answer.push(plans[i][0]);
            time+=plans[i][2];
            let length = keep.length
            for(let j=0;j<length;j++){
                let arr = keep.pop();
                if(time+arr[1]<plans[i+1][1]){
                    answer.push(arr[0]);
                    time+=arr[1];
                }else if(time+arr[1]==plans[i+1][1]){
                    answer.push(arr[0]);
                    time+=arr[1];
                    break;
                }else{
                    keep.push([arr[0],arr[1]-(plans[i+1][1]-time)]);
                    time=plans[i+1][1];
                    break;
                }
            } 
            if(keep.length===0) {
                time=plans[i+1][1];
            }
        // 다음 과제 시작 시간과 현재 과제 완료 시점이 같은 경우
        }else if(time+plans[i][2]==plans[i+1][1]){
            answer.push(plans[i][0]);
            time=plans[i+1][1];
        // 다음 과제 시작 시간 전에 현재 과제를 완료하지 못한 경우
        }else{
            time=plans[i+1][1];
            keep.push([plans[i][0],plans[i][2]-(plans[i+1][1]-plans[i][1])])
        }
    }


}
