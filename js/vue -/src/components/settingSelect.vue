<template>
  <el-select
    v-model="value"
    class="m-2"
    style="width: 150px"
    @change="changed"
  >
    <el-option
        v-for="option in item.options"
        :key="option.id"
        :label="option.name"
        :value="option.id"
    />
  </el-select>
</template>

<script>
export default {
  data() {
    return {
      value : this.item.defaultId
    };
  },
  props: {
    item : Object
  },
  methods: {
    changed(data) {
      this.$emit("selectChange",this.item.id,this.value);
    }
  }
}
</script>