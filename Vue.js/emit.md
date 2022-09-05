## Emit
emit은 부모 컴포넌트로 변경값을 보내는 것으로 아래 예시는 vue3 setup language를 사용한 emit이다.

- #### 자식 컴포넌트 예시// HelloWorld.vue
```typescript
<script lang="ts" setup>

  const props = defineProps({
      name: String,
  })
 const emit = defineEmits(['delete-something'])
 
 const emitSomething = () =>{
  emit("delete-something")
 }
 
</script>

<template>
  <div @click="emitSomething">
    <h3>Hello World</h3>
  </div>
</template>
```
<br><br>

- #### 부모 컴포넌트 예시 //App.vue
```typescript
<script lang="ts" setup>
import HelloWorld from './components/HelloWorld.vue'

const onDelete = () => {
  console.log('Delete')
}

</script>

<template>
  <HelloWorld @emitSomething="onDelete" name="HowtoEmitSomething"/>  
</template>

```
