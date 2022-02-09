//전체 합계 45에서 배열에 있는 숫자들을 뺴주는 함수


function solution(numbers) {
    var answer = 45;
    for(let i=0;i<numbers.length;i++){
        answer=answer-numbers[i];
    }
    return answer;
}
