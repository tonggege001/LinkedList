//
// Created by tonggege on 17-11-6.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#endif //LINKEDLIST_LINKEDLIST_H

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef OK
#define OK 1
#endif

#ifndef ERROR
#define ERROR 0
#endif

#ifndef INFEASIBLE
#define INFEASIBLE -1
#endif

#ifndef OVERFLOW
#define OVERFLOW -2
#endif

typedef unsigned short bool;

typedef int Status; //函数的状态码

typedef int ElemType;//基础数据类型


typedef struct{
    struct node * head;//头指针，指向表头节点
    struct node * tail;//尾指针，指向表尾节点
    int length;       //当前表长度，不包括表头节点
}LinkedList;

typedef struct node{
    ElemType data;  //数据域
    struct node * next;//节点域
}node;




