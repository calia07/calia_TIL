## computed
-> Vue.js의 템플릿 문법을 사용시 템플릿 안에서 복잡한 연산을 할 수는 있지만 코드의 이해와 유지보수가 어려워진다.

```html

<div class="sample">
  {{message.split(''}.reverse.join('')}}
</div>

```

<br>

-> 따라서 이렇게 사용하는 것이 바람직 하다.
```html
const message = ref('message')
const reverseMessage = computed(()=> this.message.split('').reverse.join(''))

<div class="sample">
  {{reverseMessage}}
</div>
```
<br>

## watch
-> 감시할 데이터를 지정해서 그 데이터가 바뀌면 콜백 함수를 실행하는 명령형 프로그래밍 방식
<br>
-> 데이터 변경의 응답으로 비동기식 계산이 필요한 경우나 시간이 많이 소요되는 계산을 할 떄 watch를 사용한다.(데이터 변경으로 API 호출하는 경우)
<br>

```javascript

data:{
  firstName:'Foo',
  lastName:'Bar',
  fullName:'Foo Bar'
},
watch:{
  firstName: function(val){
    this.fullName = val + ' ' + this.lastName
  },
  lastName: function(val){
    this.fullName = this.firstName+' '+val
  }
}


```


-> 또 하나의 특징이 있는데 cashing이 가능하다는 점이다. methods와의 큰 차이점이기도하다. <br>
-> 한 번 계산을 하면 종속 대상을 캐싱하기 떄문에 종속 대상이 변경시에만 함수를 호출한다.

<br>
<br>

## 명령형 프로그래밍과 선언형 프로그래밍
- 명령형 프로그래밍 : '어떻게' 즉 방법에 중점을 두는 프로그래밍으로 예를 들면 '여기에서 좌회전해서 직진하시면 됩니다'이다. ex) watch
- 선언형 프로그래밍 : '무엇을' 즉 목표에 중점을 두는 프로그래밍으로 예를 들면 '저는 서울시 강북구 OO로 갈 건데요'이다. ex) computed

