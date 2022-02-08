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




