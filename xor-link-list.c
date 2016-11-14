#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

typedef struct XorLinkList XorLinkList;
struct XorLinkList
{
	int val;
	XorLinkList *XorPointer;
};

XorLinkList Head = { 0 };
XorLinkList *pTail = &Head;
XorLinkList *pForword = NULL;
XorLinkList *pBackWord = NULL;

int insert(int a)
{
	XorLinkList *pNew = (XorLinkList*)malloc(sizeof(XorLinkList));
	memset(pNew, 0, sizeof(XorLinkList));
	pNew->val = a;
	pNew->XorPointer = (XorLinkList *)(((uintptr_t)pTail) ^ ((uintptr_t)pBackWord));
	pTail->XorPointer = (XorLinkList *)(((uintptr_t)pForword) ^ ((uintptr_t)pNew));
	pForword = pTail;
	pTail = pNew;
	return 0;
}

int iterateForward()
{
	XorLinkList *pBegin = &Head;
	XorLinkList *pNext = Head.XorPointer;
	XorLinkList *pTmp = NULL;
	pNext = (XorLinkList *)(((uintptr_t)NULL) ^ ((uintptr_t)Head.XorPointer));
	while (NULL != pNext)
	{
		printf("%d ", pNext->val);
		pTmp = pNext;
		pNext = (XorLinkList *)(((uintptr_t)pBegin) ^ ((uintptr_t)pNext->XorPointer));
		pBegin = pTmp;
	}
	return 0;
}

int iterateBackward()
{
	XorLinkList *pTmp = NULL;
	XorLinkList *pNext = pTail->XorPointer;
	printf("%d ", pTail->val);
	XorLinkList *pBegin = pTail;
	pNext = (XorLinkList *)(((uintptr_t)NULL) ^ ((uintptr_t)pTail->XorPointer));
	while (NULL != pNext && (&Head) != pNext )
	{
		printf("%d ", pNext->val);
		pTmp = pNext;
		pNext = (XorLinkList *)(((uintptr_t)pBegin) ^ ((uintptr_t)pNext->XorPointer));
		pBegin = pTmp;
	}
	return 0;
}

int main(int argc,char *argv[])
{
	for (int i = 0; i < 20; i++)
	{
		insert(i);
	}
	iterateForward();
	printf("\n\n");
	iterateBackward();
	return 0;
}