# Changes since the latest lesson

## 2020.3.18

### o 添加的部分

1. 3月17日”栈和队列“的课堂示例。

2. 利用栈的表达式求职。根据教材上的例子修改而成。位置：`chap03-stackNqueue/stack/expreval`。

3. 在`DS/ppt/链表操作.pptx`中添加了在链表尾部插入节点的动画。

   

## **2020.3.12**

-----

### **o 修改的部分**

1. 在`seqlist`和`linklist`中，删除了`list_interface.h`，将其内容合并到`list.h`中。
2. 修改了`demo/chap02-linearlist/linklist-C++/list.h`中的`list`类模板。

-----

### **o 添加的部分**

1. 在`demo/chap02-linearlist/linklist-C++/list.h`中的`list`类模板中补齐了所需要的的成员函数。

<br /><br /><br /><br />

## **2020.3.11**

-----

### **o 修改的部分**

1. 修改了`demo/chap02-linearlist/clinklist/list.c`中的`InsList()`函数，使之能找到正确的插入位置。插入位置在找到的节点之后。
2. 修改了`demo/chap02-linearlist/dlinklist/list.c`中的`InsList()`函数，使之能找到正确的插入位置。插入位置在找到的节点之后。

-----

### **o 添加的部分**

1. 在`ppt/链表操作.pptx`中，增加了一元多项式的相加运算的动画图解。  
2. 为了方便正在学习C++的同学，增加了`linklist-C++`和`dlinklist-C++`文件夹。其中，`dlinklist-C++`里面的内容比较复杂。如果阅读有困难，请联系我。

<br /><br /><br /><br />

## **2020.3.4**

-----

### **o 已知的错误**

1. 顺序表发现一处初始化错误：

```C
    L->last = 0;
```

   实际上，last的值应该初始化为-1，即：

```C
    L->last = -1;
```

2. 根据第一条，遍历操作traverse的for循环中，循环条件`i < L->last`应该修改为：

```C
    for (int i = 0; i <= L->last; ++i)
```

-----

### **o 添加的部分**

1. 在`main()`函数中添加了一个指向列表`list`的指针`L`，并在其后使用它。
2. 在`main()`函数中，遍历函数之后添加了一条打印函数，用于输出一个换行。
3. 为`linklist`添加了`list.c`文件

-----

### **o 修改的部分**

1. 根据教材，链表采用了头结点模式。因此，`InitList()`函数的参数必须是指针的指针：

```C
    void InitList(LListPtr *L)
    {
        (*L) = (NodePtr)malloc(sizeof(Node)); //生成头结点
        (*L)->next = NULL; //头结点的指针域为空
    }
```

2. 根据上条，`list_interface.h`中关于`InitList()`函数的原型声明也应该改为：

```C
    extern void InitList(LListPtr *L);
```

3. 为了保持顺序表和链表在接口函数方面的一致性，顺序表的`InitList()`函数也应作出相应的修改：

```C
    void InitList(LListPtr *L)
    {
        (*L)->last = -1;
    }
```