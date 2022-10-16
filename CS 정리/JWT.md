# JWT ( JSON Web Token) 및 Access Token & Refresh Token

### 1. JWT란?
- #### 인증에 필요한 정보들을 암호화시킨 JSON 토큰으로 HTTP 헤더에 같이 실어서 서버가 클라이언트를 식별
- JSON 데이터를 Base64 URL-safe Encode를 통해 인코딩하여 직렬화한 것
- 위변조 방지를 위해 개인키를 통한 전자서명 존재
- 발급 후 삭제가 불가능하기 때문에 토큰에 유효시간 부여해야 함

<br>

### 2. JWT 구조
#### 1) Header(헤더) : JWT에서 사용 타입과 해시 알고리즘의 종류
#### 2) Payload(내용) : 서버에서 첨부한 사용자 권한 정보 및 데이터
#### 3) Signature(서명) : Header, Payload를 인코딩한 이후 해시함수를 적용하고 개인키로 서명한 전자서명 포함
<br>

### 3. JWT 장단점
#### 장점
- 인증을 위한 별도 저장소가 필요하지 않음
- 별도의 I/O 작업 없이 빠르게 인증을 처리 가능
- 확장성이 우수
- 데이터 위변조를 막을 수 있음
- 토큰 기반으로 다른 로그인 시스템에 접근 및 권한 공유 가능
- 모바일 어플리케이션에서 사용 가능

#### 단점
- 토큰의 길이에 따른 네트워크 부하 발생 가능성
- 특정 토큰을 강제 만료시키기 어려움
- 발급한 후 삭제가 불가능

<br>

### 4. Refresh Token
- Access Token만을 사용하면 제 3자에게 탈취당할 경우 보안에 취약(토큰 만료 전까지 누구나 권한 접근 가능)
- 따라서 접근에 관여하는 Access Token과 재발급에 관여하는 Refresh Token을 동시에 사용

<br><br><br>

### 참고
<hr>
https://inpa.tistory.com/m/entry/WEB-%F0%9F%93%9A-JWTjson-web-token-%EB%9E%80-%F0%9F%92%AF-%EC%A0%95%EB%A6%AC <br>
https://inpa.tistory.com/m/entry/WEB-%F0%9F%93%9A-Access-Token-Refresh-Token-%EC%9B%90%EB%A6%AC-feat-JWT
