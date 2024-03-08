<script setup>
import mySelect from './settingSelect.vue';
import { ref, unref, nextTick } from 'vue';
</script>

<template>
    <div @mouseover="over()" @mouseleave="leave()" >
        <slot></slot>
        <div v-show=settingVisible>
            <el-popover :width="220" :visible="popVisible" >
                <template #reference>
                    <img src="/setting.png" v-bind="$attrs" @click="clicked()" />
                </template>
                <div tabindex="0" ref="popoverDivRef" @focus="addFocus()" @blur="reduceFocus()" >
                    <el-scrollbar max-height="100px" >
                        <div tabindex="1"  v-for="item in menuItems" @focus="addFocus()" @blur="reduceFocus()" >
                            {{ item.name }}
                            <mySelect :item="item" @focus="addFocus()" @blur="reduceFocus()" @selectChange="selectChanged" />
                        </div>
                    </el-scrollbar>
                </div>
            </el-popover>
        </div>
    </div>
</template>

<script>
export default {
    data() {
        return {
            settingVisible : false,
            popVisible : false,
            isOver : false,
            numFocus : 0
        };
    },
    props : {
        menuItems : Array,
        popoverDivRef : ref()
    },
    methods: {
        over() {
            this.isOver=true;
            this.settingVisible=true;
        },
        leave() {
            this.isOver=false;
            setTimeout(() => {
                this.updateVisible();
            }, this.$Global.timeout);
        },
        updateVisible() {
            if(this.numFocus>0){
                this.popVisible=true;
            }
            else {
                this.popVisible=false;
            }
            setTimeout(() => {
                this.settingVisible=this.isOver || this.popVisible;
            }, this.$Global.timeout);
        },
        clicked() {
            this.popVisible=true;
            nextTick( () => {
                this.$refs.popoverDivRef.focus();
            })
        },
        addFocus() {
            this.numFocus++;
            this.updateVisible();
        },
        reduceFocus() {
            this.numFocus--;
            this.updateVisible();
        },
        selectChanged(itemId,optionId) {
            this.$emit("selectChange",itemId,optionId);
        }
    }
}
</script>

<style>
:focus-visible {
  outline: 0;
}
</style>