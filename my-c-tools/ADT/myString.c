#include "myString.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>


/***************  静态函数声明 *******************/
// 用于在堆内存上（使用动态内存分配）创建一个 MyString 变量并初始化
static MyString* innerCreateMyString(void);
// 用于将一个 MyString 变量初始化
static void innerInitMyString(MyString * pMyString);
// 用于释放一个 MyString 变量为存储字符串而分配的内存空间(char*)
static void innerFreeCStr(MyString * pMyString);


/***************  API 函数定义 *******************/
// 创建、销毁

MyString* createMyString(void) {
	return innerCreateMyString();
}


MyString* destroyMyString(MyString * pMyString) {
	if (!pMyString) {
		return NULL;
	}

	// 释放字符串内存
	innerFreeCStr(pMyString);

	// 释放 ADT 内存
	free(pMyString);
	
	return NULL;
}

MyString* createFromCStr(const char * pCStr) {
	// 声明变量
	MyString* pMyString = NULL;
	size_t cstrLen = 0;

	// 参数有效性检测
	if (!pCStr || !(cstrLen = strlen(pCStr))) {
		return NULL;
	}


	pMyString = innerCreateMyString();

	if (!pMyString) {
		return NULL;
	}


	char * pNewStr = (char*)malloc(cstrLen + 1);
	if (!pNewStr) {
		free(pMyString);
		return NULL;
	}

	strcpy(pNewStr, pCStr);
	pMyString->pStr = pNewStr;

	return pMyString;
}

MyString* createFromMyString(const MyString * pMyString) {
	MyString* pNewMyString = NULL;
	

}

// 获取信息
size_t getMyStringLength(const MyString * pMyString);
const char* getMyStringCStr(const MyString * pMyString);
bool isMyStringEmpty(const MyString * pMyString);




/***************  静态函数定义 *******************/
// 用于在堆内存上（使用动态内存分配）创建一个 MyString 变量并初始化

static MyString* innerCreateMyString(void) {
	MyString* pMyString = (MyString*)malloc(sizeof(MyString));

	if (pMyString) {
		innerInitMyString(pMyString);
	}

	return pMyString;
}

// 用于将一个 MyString 变量初始化
static void innerInitMyString(MyString * pMyString) {
	pMyString->pStr = NULL;
}

// 用于释放一个 MyString 变量为存储字符串而分配的内存空间(char*)
static void innerFreeCStr(MyString * pMyString) {
	if (pMyString->pStr) {
		free(pMyString->pStr);
	}
}