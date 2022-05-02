### 오늘 일어난 ReactNative 오류 해결

​

#### 1. template downloading이 안되서 계속 빈 파일이 됨

=> node.js 버전 때문에 일어난 오류

​

#### 2. node.js 버전 때문에 난 오류

=>node.js를 최신 버전으로 다시 설치해줌

​

#### 3. JDK 버전 오류

=> JDK를 최신 버전으로 다시 설치

=> 관리자권한으로 powershell 열어서 하단 명령어 해줌(chocolatey가 설치되어 있어야 함)

```
choco install -y openjdk11
````

#### 4. Emulator SDK 설정 오류

=> SDK버전 맞춰서 새로운 emulator 만들어서 연결

