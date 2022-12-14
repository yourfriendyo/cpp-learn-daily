#define _CRT_SECURE_NO_WARNINGS 1
#include "SingleList.h"

//单链表创建结点
SLTNode* SListNewNode(SLTDataType x) {
	//申请新结点
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL) {
		perror("newNode::malloc");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//单链表打印
void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


//单链表尾插
void SListPushBack(SLTNode*& phead, SLTDataType x) {
	SLTNode* newNode = SListNewNode(x);
	//无结点
	if (phead == NULL) {
		phead = newNode;
	}
	//有结点
	else {
		//找尾结点
		SLTNode* tail = phead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//修改尾结点指针域
		tail->next = newNode;
	}
}


//单链表尾删
void SListPopBack(SLTNode*& phead) {
	//链表判空
	assert(phead);
	//结点个数为1
	if (phead->next == NULL) {
		free(phead);
		phead = NULL;
	}
	else {
		//找尾结点
		SLTNode* tail = phead;
		//1.
		////前驱指针 
		SLTNode* prev = NULL;
		//while (tail->next != NULL) {
		//	prev = tail;
		//	tail = tail->next;
		//}
		////释放尾结点
		//free(tail);
		//tail = NULL;
		////置空前驱结点指针域
		//prev->next = NULL;
		
		//2.
		while (prev->next->next) {
			prev = prev->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}


//单链表头插
void SListPushFront(SLTNode*& phead, SLTDataType x) {
	assert(phead);
	SLTNode* newNode = SListNewNode(x);
	newNode->next = phead;
	phead = newNode;
}


//单链表头删
void SListPopFront(SLTNode*& phead) {
	//0个结点
	assert(phead);
	//1个及其以上结点
	SLTNode* tmp = phead->next;
	free(phead);
	phead = tmp;
	//*pphead = (*pphead)->next//Err

}
 

//单链表查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	assert(phead);
	while (phead != NULL) {
		//判断
		if (phead->data == x) {
			return phead;
		}
		phead = phead->next;
	}
	//无该元素
	return NULL;
}


//单链表随机前插
void SListInsertForward(SLTNode*& phead, SLTNode* pos, SLTDataType x) {
	assert(phead && pos);
	SLTNode* newNode = SListNewNode(x);
	//头插时
	if (pos == phead) {
		newNode->next = phead;
		phead = newNode;
	}
	else {
		//找前驱结点
		SLTNode* prev = phead;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = newNode;
		newNode->next = pos;
	}
}


//单链表随机后插
void SListInsertAfter(SLTNode* pos, SLTDataType x) {
	assert(pos);
	SLTNode* newNode = SListNewNode(x);
	//0个结点时
	if (pos == NULL) {
		pos = newNode;
	}
	//
	else {
		newNode->next = pos->next;
		pos->next = newNode;
	}
}


//单链表随机删除（删除pos结点）
void SListErase(SLTNode*& phead, SLTNode* pos) {
	//链表为空
	assert(pos);
	//if (pos->next == NULL) {
	//}
	//仅判断1个结点的情况，不如判断操作首结点的情况
	//首结点时
	if (phead == pos) {
		phead = pos->next;
		free(pos);
	}
	else {
		SLTNode* prev = phead;
		while (prev->next != pos) {
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
	}

	//删除pos结点，需要改变上个结点，就要遍历找前驱
	//只要找上一个结点，就要考虑结点数为1的情况。
}


//单链表随机后删（删除pos的下一个结点）
void SListEraseAfter(SLTNode* pos) {
	//1个结点（pos后无结点）
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}


//单链表释放
void SListDestroy(SLTNode*& phead) {
	assert(phead);
	SLTNode* cur = phead;
	while (cur) {
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead = NULL;
}

