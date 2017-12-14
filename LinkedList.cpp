//
// Created by tonggege on 17-11-6.
//

#include <malloc.h>
#include "LinkedList.h"

/**
 * func:初始化链表
 * @param L 链式线性表的指针
 * @return 状态码
 */
Status InitList(LinkedList * L){
    L->length = 0;
    //初始化失败返回错误状态吗
    if((L->tail=L->head = (node * )malloc(sizeof(node))) == NULL) return ERROR;
    L->head->next = NULL;//为新产生的表头节点赋初值
    return OK;
}

/**
 * func： 销毁线性表
 * @param L
 * @return 状态码
 */
Status DeleteList(LinkedList * L){
    if(!L||L->head == NULL) return ERROR;//处理表指针为空情况
    node * head = L->head;
    node * tmp = NULL;//用于删除的中间变量
    while(head!=NULL){
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(L);
    return OK;
}

/**
 * func：清空列表
 * @param L 表指针
 * @return 状态码
 */
Status ClearList(LinkedList*L){
    if(!L) return  ERROR;
    node * p = L->head->next;//p指向第一个节点
    while(p){
        node * tmp = p->next;
        free(p);//释放节点
        p = tmp;
    }
    L->length = 0;//长度设置为0
    L->tail = L->head;//修改表尾指针
    return OK;
}

/**
 * func:判断列表是否为空
 * @param L
 * @return 是，返回true，否则false
 */
bool ListEmpty(LinkedList * L){
    if(!L) return TRUE;
    if(L->length==0|| L->head == L->tail) return TRUE;//空表或者表不存在视为空
    return FALSE;
}

/**
 * func:获取线性表的长度
 * @param L 线性表
 * @return 长度
 */
int ListLength(LinkedList L){
    return L.length;
}

/**
 * func:获得第i个元素
 * @param L 链表
 * @param i 序号
 * @param e 保存元素的指针
 * @return 状态码
 */
Status GetElem(LinkedList L,int i,ElemType * e){
    if(i<=0 && i>ListLength(L)) return ERROR;//序号不正确返回错误状态码
    node * p = L.head->next;//p循环对比
    for(int j = 1;j<=ListLength(L);j++,p = p->next){
        if(i==j){ //如果序号正确则返回
            if(e!=NULL) *e = p->data;
            break;
        }
    }
    return OK;
}
/**
 * func:获得与e元素相等的元素的序位
 * @param L 链表
 * @param e 欲对比的元素
 * @param compare 比较函数，=0时相等，<0时右边大，>0时左边大
 * @return 元素序位
 */
int LocateElem(LinkedList L,ElemType e,void * compare){
    //将比较函数转换成合适的格式
    int (*com)(ElemType,ElemType) = (int (*)(ElemType,ElemType))compare;
    node * p = L.head->next;
    int i;//循环变量
    for(i = 1;i<=ListLength(L)||p;i++,p = p->next){
        if(com(p->data,e)==0){
            return i;
        }
    }
    return 0;
}

/**
 * func  获取前驱节点数据
 * @param L 链表
 * @param cur_e 查询节点
 * @param pre_e 获取指针
 * @return 状态码
 */
Status PriorEiem(LinkedList L,ElemType cur_e,ElemType * pre_e){
    if(L.head->next==NULL) return ERROR;//如果线性表不存在，则报错
    if(L.head->next->data==cur_e) return ERROR;//第一个节点不存在前驱
    //q来配对,p来获得前驱
    node * p = L.head;
    node * q = L.head->next;
    while(q&&p){
        if(q->data==cur_e){
            if(pre_e!=NULL) *pre_e=p->data;
            return OK;
        }
        p = p->next;q = q->next;
    }
    return ERROR;
}

/**
 * func 获取后继节点
 * @param L 线性表
 * @param cur_e 当前待比较节点
 * @param next_e 后继节点指针
 * @return 状态码
 */
Status NextElem(LinkedList L,ElemType cur_e,ElemType * next_e){
    if(L.head->next==NULL) return ERROR;
    if(L.tail->data==cur_e) return ERROR;//尾节点没有后继
    //p来配对，q来获取节点
    node * p = L.head->next;
    node * q = p->next;
    while(p&&q){
        if(p->data==cur_e){
            if(next_e!=NULL) *next_e=q->data;
            return OK;
        }
        p = p->next;q = q->next;
    }
    return ERROR;//不存在cur_e
}

/**
 * func : 将e节点插入到位置i中，1<=i<=length+1
 * @param L 线性表指针
 * @param i 位序
 * @param e 元素
 * @return 状态码
 */
Status ListInsert(LinkedList *L,int i,ElemType e){
    if(!L) return ERROR;//线性表不存在
    if(i<=0 && i> ListLength(*L)) return ERROR;//序号不合法
    //三部曲——产生节点
    node * f = NULL;
    if(!f=(node*)malloc(sizeof(node))) return ERROR;
    f->data = e;
    f->next = NULL;
    node * p = L->head;
    node * q = L->head->next;
    for(int j = 1;j<=ListLength(*L);j++,p = p->next,q = q->next){
        //插入到1-length位置
        if(j==i){
            f->next = q;
            p->next = f;
            L->length++;
            return OK;
        }
    }
    //如果插入到尾部，则需要修改尾指针
    p->next = f;
    L->tail = f;
    L->length++;
    return OK;
}

/**
 * func ：删除第i个元素并用e返回
 * @param L 线性表L
 * @param i 位序i
 * @param e 返回元素的指针
 * @return 状态码
 */
Status ListDelete(LinkedList *L,int i,ElemType *e){
    if(i<=0 || i>ListLength(*L)) return ERROR;
    node * p = L->head;//q指向被删除的元素的前一个
    node * q = L->head->next;//p指向被删除的元素
    for(int j = 1;i<=ListLength(*L);j++,p = p->next,q = q->next){
        if(j == i){
            p->next = q->next;
            if(e) *e = q->data;//赋值返回
            free(q);
            if(j==ListLength(*L)){//如果删除最后一个元素，则需要修改尾指针
                L->tail = p;
            }
            return OK;
        }
    }
}

/**
 * func:遍历列表
 * @param L 线性表
 * @param visit 访问函数
 * @return 状态码
 */
Status ListTraverse(LinkedList L,void * visit){
    if(L.head->next==NULL) return ERROR;
    void (*vst)(node * );
    vst = (void (*)(node *)) visit;
    node * p = L.head->next;
    while(p){
        vst(p);
        p = p->next;
    }
    return OK;
}











































