#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h>
#include <stdbool.h>

typedef struct MyStringADT {
	char * pStr;
} MyString;


// 创建、销毁
MyString* createMyString(void);
MyString* destroyMyString(MyString * pMyString);

MyString* createFromCStr(const char * pCStr);
MyString* createFromMyString(const MyString * pMyString);

// 获取信息
size_t getMyStringLength(const MyString * pMyString);
const char* getMyStringCStr(const MyString * pMyString);
bool isMyStringEmpty(const MyString * pMyString);

// 



#endif	/* MY_STRING_H */