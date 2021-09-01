# ***Andrew practic code leaning***

### **leetcode** *使用，刷题总结

#### ~~部分内容需要重新编写~~
##


###### 
- tst01
- tst02
- tst03
+ tst04
1. yangbin
2. shengwanying
3. zhuangpengfei
4. cheshibuzhou
5. danyuanziji

####
yangbin | shengwanyin | shengguanglin | zhuangpengfei
---|:--:|--:|--:
98|99|100|200
98|99|100|200
98|99|100|200
98|99|100|200
98|99|100|200

####
```
st=>start: 开始
op=>operation: My Operation
cond=>condition: Yes or No?
e=>end
st->op->cond
cond(yes)->e
cond(no)->op
```

```flow
st=>start: 开始框
op=>operation: 处理框
cond=>condition: 判断框(是或否?)
sub1=>subroutine: 子流程
io=>inputoutput: 输入输出框
e=>end: 结束框
st->op->cond
cond(yes)->io->e
cond(no)->sub1(right)->op
```
# mk 表示 make Ketax
snippet mk "Math" wA
$${1}$`!p
if t[2] and t[2][0] not in [',', '.', '?', '-', ' ']:
    snip.rv = ' '
else:
    snip.rv = ''
`$2
endsnippet

# dm 表示 Display math
snippet dm "Math" wA
$$
${1:${VISUAL}}
$$ $0
endsnippet
