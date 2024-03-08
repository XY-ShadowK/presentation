import './assets/main.css'

import { createApp } from 'vue'
import App from './App.vue'

// 引入element-plus
import ElementPlus from 'element-plus'
import 'element-plus/dist/index.css'

const app = createApp(App)

// 引入全局变量
import global from './components/global.vue'
app.config.globalProperties.$Global = global

app.use(ElementPlus)

app.mount('#app')
