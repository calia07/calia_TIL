# Node.js 기본
## 1. 전역 변수
- #### 전역 변수 : 아무런 제약 없이 모든 곳에서 사용할 수 있는 변수
|변수|설명|
|:---:|:---:|
|__filename|현재 실행 중인 코드의 파일 경로|
|__dirname| 현재 실행 중인 폴더의 경로|

```javascript
console.log(__filename);
console.log(__dirname);
```
<br>

## 2. process 객체의 속성과 이벤트
#### 프로세스 정보를 제공하며 제어할 수 있게 하는 객체
- #### 속성

|속성|설명|
|:---:|:---:|
|env|컴퓨터 환경 정보|
|version|Node.js 버전|
|versions|Node.js와 종속된 프로그램 버전|
|arch|프로세서의 아키테처|
|platform|플랫폼|

- #### 메소드

|메소드|설명|
|:---:|:---:|
|exit([exitCode=0])|프로그램 종료|
|memoryUsage()|메모리 사용 정보 객체 반환|
|uptime()|현재 프로그램이 실행된 시간 반환|

```javascript
console.log(process.arch);
console.log(process.platform);
console.log(process.uptime());
...
```
<br>

## 3. process 객체와 이벤트
- #### 이벤트 연결 메소드
|메소드|설명|
|:---:|:---:|
|on(<이벤트 이름>,<이벤트 핸들러(함수)>)|이벤트 연결|

- #### 객체의 이벤트
|이벤트|설명|
|:---:|:---:|
|exit|프로세스가 종료될 때 발생|
|uncaughtException|예외 일어날 때 발생|

```javascript
process.on('exit',() => {console.log('프로세스 종료')});
process.on('uncaughtException',() => {console.log('예외 발생')});
error.error.error();
```

<br>

## 4. os 모듈
#### require() 함수의 매개변수로 문자열 os를 입력해 모듈을 추출하고 사용

- #### 모듈 추출
```javascript
const os = require('os');
```

- #### 메소드
|메소드|설명|
|:---:|:---:|
|hostname()|운영체제의 호스트 이름을 리턴|
|type()|운영체제의 이름을 리턴|
|platform()|운영체젲의 플랫폼을 리턴|
|arch()|운영체제의 아키텍처를 리턴|
|release()|운영체제의 버전을 리턴|
|uptime()|운영체제 실행된 시간 리턴|
|loadavg()|로드 에버리지 정보를 담은 배열 리턴|
|totalmem()|시스템의 총 메모리 리턴|
|freemem()|시스템의 사용 가능한 메모리를 리턴|
|cpus()|CPU의 정보를 담은 객체를 리턴|
|getNetworkInterfaces()|네트워크 인터페이스의 정보를 담은 배열을 리턴|

```javascript
const os=require('os');

console.log(os.hostname());
console.log(os.type());
console.log(os.platform());
...
```
<br>

## 5. url 모듈

- #### 메소드
|메소드|설명|
|:---:|:---:|
|parse(urlStr [,parseQuery = false, slashesDenoteHost =false])|URL 문자열을 URL 객체로 변환해서 리턴|
|format(urlObj)|URL 객체를 URL 문자열로 변환해 리턴|
|resolve(from,to)|매개 변수를 조합하여 완전한 URL 문자열을 생성해 리턴|

```javascript
const url = require('url');

const parsedObject = url.parse('http://www.abcdefg.co.kr/store?code=dfie2332ksafj');
console.log(parsedObject);
```
<br>

## 6. File System 모듈

- ### 1) 파일 읽기
|파일 읽기 메소드|설명|
|:---:|:---:|
|fs.readFileSync(<파일 이름>)|동기적으로 파일을 읽어들임|
|fs.readFile(<파일 이름>,<콜백 함수>)|비동기적으로 파일을 읽어들임|

- 동기적으로 파일 읽어 들이기 : 파일을 읽어들일 때까지 코드가 정지 => thread 사용
```javascript
const fs = require('fs');/1번 실행

const file = fs.readFileSync('textfile.txt');//2번 실행, 동기적
console.log(file);//3번 실행
console.log(file.toString());//4번 실행
//5번 종료
```

- 비동기적으로 파일 읽어 들이기 : 시간 단축, 이벤트만 등록하고 곧바로 코드 진행 => 개발 속도 및 유지 보수성이 좋음
```javascript
const fs = require('fs');//1번 실행

const file = fs.readFile('textfile.txt',(error,file) => {//2번 실행
  console.log(file); //4번 실행
  console.log(file.toString());//5번 실행
  //6번 종료
});
//3번 종료
```
```javascript
const fs = require('fs');
const async = require('async');

async.parallel([
  (callback) => {fs.readFile('a.txt',callback); },
  (callback) => {fs.readFIle('b.txt',callback); },
  (callback) => {fs.readFile('c.txt',callback); },
], (error,results) => {
  console.log(results);
});
//병렬적으로 파일을 읽어 들이기때문에 시간 단축
```

- ### 2) 파일 쓰기
|파일 쓰기 메소드|설명|
:---:|:---:
|fs.writeFileSync(<파일 이름>,<문자열>)|동기적으로 파일을 작성|
|fs.writeFile(<파일 이름>,<문자열>,<콜백 함수>)|비동기적으로 파일을 작성|

- 동기적으로 파일 쓰기
```javascript
const fs = require('fs');

fs.writeFileSync('output.txt','안녕!!');
console.log('파일 쓰기 완료');

```

- 비동기적으로 파일 쓰기
```javascript
const fs = require('fs');

fs.writeFile('output.txt','안녕!!',(error) => {
  console.log('파일 쓰기 완료');
});
```
- ### 3) 파일 처리와 예외 처리
동기적 코드를 예외처리할 떄에는 try catch 구문 활용<br>
비동기적 코드를 예외처리할 때에는 콜백 함수로 전달된 첫 번째 매개 변수 error 활용

- 동기 코드 예외 처리
```javascript
const fs = require('fs');

try{
  const file = fs.readFileSync('none.txt');
  console.log(file);
  console.log(file.toString());
}catch(exception){
  console.log('문제 발생');
  console.log(exception);
}
```

- 비동기 코드 예외 처리
```javascript
const fs = require('fs');

fs.readFile('none.txt',(error,file) => {
  if(error){
    console.log('문제 발생');
    console.log(error);
  }
  else{
    console.log(file);
    console.log(file.toString());
  }

});
```
<br>

## 7. 노드 패키지 매니저
#### 외부 모듈 : 개인 개발자가 내부 모듈을 조합해 사용하기 쉬운 형태로 만들거나 새로운 기능을 구현해서 제공하는 것
#### 내부 모듈 : 프로그래밍 플랫폼이 기본적으로 제공하는 모듈
```nodejs
npm install <모듈 이름>@<버전>
```
<br>

## 8. request 모듈
#### 웹 요청을 쉽게 만들어 주는 모듈(외부 모듈)
```javascript
const request = require('request');

const url = 'http://www.abcd.co.kr/store_list.html';
request(urll,(error, response, body) =>{
  console.log(body);
});

```
<br>

## 9. cheerio 모듈
#### 웹 페이지의 특정 위치에서 손쉽게 데이터를 추출할 수 있는 모듈(외부 모듈)
<br>다양한 정보를 손쉽게 가져올 수 있다는 장점이 있음

<br>

## 10. async 모듈
#### 실행 순서를 정의하기 어렵고, 둘어쓰기가 많은 데 이 문제를 해결해 줄 수 있는 모듈

<hr>

#### [출처 : 자바스크립트 프로그래밍 입문(한빛 아카데미) - 윤인성 지음]
