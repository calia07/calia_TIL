## router (라우터)
### routing이란? 
- 페이지 이동시 서버에 요청해 갱신하는 것이 아니라 미리 해당 페이지를 구성해놓고 라우팅을 이용해 화면 갱신
- SPA( Single Page Application) => 매끄러운 화면 전화 가능

### vue-router
- 설치 방법
```
npm install vue-router
```
<br>

- router-view: 페이지 표시, 해당 컴포넌트를 뿌려주는 영역
<br>

- 사용 방법
    - Vue 및 Vue Router import 하기
    ```typescript
    import Vue from 'vue'
    import {createRouter,createWebHistory} from 'vue-router'
    ```
    
    - views 폴더에 컴포넌트 정의하기
    ```typescript
    import Home from './views/Home.vue'
    import About from '../views/About.vue'
    ```
    - routes 정의
    ```typescript
    const routes= [
        {
            path:'/about',
            name:'About',
            component:About,
        },
    ]
    ```
    
    - router 인스턴스 정의
    ```typescript
    const router = createRouter({
       history: createWebHistory(),
        routes,

    })
    ```
    
    - 루트 인스턴스를 만들어 mount하기
    ```typescript
    import router from './router'

    createApp(App).use(router).mount('#app')
    ```
    
