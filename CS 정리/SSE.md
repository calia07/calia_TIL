# SSE ( Server Sent Event )

### 1. SSE란?
- #### 서버의 데이터를 실시간으로 받는 기술 ( 기존에는 서버의 변경된 데이터를 가져오기 위해서는 지속적인 request가 필요했으나 websocket이나 sse 사용 가능)
- 기존 HTTP 웹 서버에서 HTTP API 만으로 동작이 가능하고 구현이 WebSocket보다 간단함.
- Websocket은 양방향 연결이지만 SSE는 서버에서 클라이언트 방향으로만 보낼 수 있음.
- HTML5의 표준안으로 웹 소케보다 가벼움.
- 양방향이 아니므로 ajax로 쉽게 이용 가능

<br>

### 2. SSE 사용
- SSE는 첫 연결시에 데이터를 주고받은 뒤 연결된 상태를 유지하고 서버가 일방적으로 데이터 전송
- 사용할 수 있는 Server-Sent Event API가 EventSource 인터페이스에 존재
```javascript
/** 이벤트 생성 스크립트가 다른 도메인에 존재할 경우 URI와 옵션 딕셔너리 지정하여 새로운 EventSource 객체 생성 */
const evtSource = new EventSource("//api.example.com/ssedemo.php", { withCredentials: true } );

/** message 이벤트에 대한 핸들러를 등록하여 서버로부터의 메시지 수신을 시작 */
evtSource.onmessage = (event) => {
  const newElement = document.createElement("li");
  const eventList = document.getElementById("list");

  newElement.textContent = `message: ${event.data}`;
  eventList.appendChild(newElement);
}

/** 에러 핸들링 */
evtSource.onerror = function(e) {
  alert("EventSource failed.");
};

/** 이벤트 스트림 닫기 */
evtSource.close();
```
<br>

### 3. 서버의 Event를 클라이너트로 보내는 다른 방법 비교
#### 1) Polling : 클라이언트가 HTTP request를 서버로 계속 날려서 이벤트 내용을 전달받는 방식
- 클라이언트가 많아지면 서버의 부담이 많아지며 빠른 응답을 기대하기 어려움
- http 오버헤드 발생 (정보 신뢰성 판단을 위한 헤더 같은 정보로 인해 데이터량이나 처리시간이 증가)
- 일정하게 갱신되는 서버 데이터의 경우 사용

#### 2) websocket : 웹소켓 포트에 접속한 모든 클라이언트에게 이벤트 방식으로 응답하며 양방향 통신이 가능
- websocket 프로토콜 처리를 위한 전이중 연결과 새로운 웹소켓 서버가 필요
- 서버와 클라이언트 간의 Socket 연결 필요

### 참고
<hr>
https://inpa.tistory.com/m/entry/WEB-%F0%9F%93%9A-Polling-Long-Polling-Server-Sent-Event-WebSocket-%EC%9A%94%EC%95%BD-%EC%A0%95%EB%A6%AC <br>
https://developer.mozilla.org/en-US/docs/Web/API/Server-sent_events/Using_server-sent_events
