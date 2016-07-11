# 解题报告

### L1 - 002

水题

### L1 - 006

遍历 2 - $\sqrt {n}$

### L1 - 010

水题

### L1 - 014

水题

### L1 - 018

水题，输出格式 `%02d`

### L1 - 022

水题

---

### L2 - 002

坑多，据说链表中间会断

用了一下 `set<int>`

### L2 - 006

后序遍历的末尾是子树的根

采用分治做法建树

使用bfs层序遍历

### L2 - 010

使用并查集维护朋友关系

使用邻接矩阵维护敌人关系

---

### L3 - 002

求的中位数是指

> 对于N个元素，若N是偶数，则中值定义为第N/2个最小元；若N是奇数，则中值定义为第(N+1)/2个最小元。

输入: 不能使用STL

数据结构: 使用两个map, 写数组作栈，同时维护两个map的实际大小

```c++
map<int, int, greater<int>> low;
int lowsize = 0;

map<int, int> high;
int highsize = 0;

int stk[100000];
int stkp = 0;
```

使用一个balance函数在每次修改后维护两个堆大小相差不超过1，并保证low的起始元素为要求的中位数

```c++
void balance(){
  if(lowsize - highsize >= 2){
    high[(*low.begin()).first]++;
    low[(*low.begin()).first]--;
    if(low[(*low.begin()).first] == 0) low.erase((*low.begin()).first);
    lowsize--;
    highsize++;
  }
  else if(highsize - lowsize >= 1){
    low[(*high.begin()).first]++;
    high[(*high.begin()).first]--;
    if(high[(*high.begin()).first] == 0) high.erase((*high.begin()).first);
    lowsize++;
    highsize--;
  }
  median = (*low.begin()).first;
}
```

push时，比中位数大插入high堆，否则插入low堆

### L3 - 006

![](http://sxb.moe/wp-content/uploads/2016/06/%E6%88%91%E5%A5%BD%E8%8F%9C%E5%95%8A.jpg)