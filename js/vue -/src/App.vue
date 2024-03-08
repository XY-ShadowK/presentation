<script setup>
import styleSettings from './components/styleSettings.vue';
import { ref, unref, nextTick } from 'vue'
</script>

<template>
  <styleSettings width="18" height="18" :menuItems=menuItems @selectChange="selectChanged" >
    <img alt="Vue logo" class="logo" src="./assets/logo.svg" width="125" height="125" />
  </styleSettings>
</template>

<script>
export default {
  data() {
    return {
      menuItems : [
        {"id":"font","name":"字体","options":[{"id":"SimSun","name":"宋体"},{"id":"Microsoft Yahei","name":"微软雅黑"}],"defaultId":"SimSun"},
        {"id":"color","name":"颜色","options":[{"id":"#ffffff","name":"纯白"},{"id":"#000","name":"纯黑"}],"defaultId":"#ffffff"},
      ]
    };
  },
  methods: {
    selectChanged(itemId,optionId) {
        console.log(itemId,optionId)
    }
  }
};
</script>

<style scoped>
header {
  line-height: 1.5;
}

.logo {
  display: block;
  margin: 0 auto 2rem;
}

@media (min-width: 1024px) {
  header {
    display: flex;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }

  .logo {
    margin: 0 2rem 0 0;
  }

  header .wrapper {
    display: flex;
    place-items: flex-start;
    flex-wrap: wrap;
  }
}
</style>
