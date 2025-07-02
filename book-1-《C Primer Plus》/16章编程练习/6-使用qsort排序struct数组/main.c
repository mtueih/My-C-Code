#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyArrayPrinter.h"

// 宏定义 struct name 数组大小
#define NAME_ARR_SIZE 5

// 定义结构体，名字
struct Name
{
    char first_name[32];
    char last_name[32];
};

// // 打印 struct Name 数组的函数
// void printNameArr(struct Name *p_name, size_t ele_num);

// 用于打印单个 struct Name 变量的函数，用于 MyArrayPrinter 库
void printName(const void *p_name);

// 比较两个 struct Name 变量的函数，用于 qsort 排序
int nameComp(const void *name_1, const void *name_2);

int main(void)
{
    // 声明并显式初始化一个 struct Name 数组
    struct Name name_arr[NAME_ARR_SIZE] = {
        {"Carl", "Johnson"},
        {"Frank", "Tenpenny"},
        {"Big", "Smoke"},
        {"Cesar", "Vialpando"},
        {"Mike", "Toreno"}};

    // 打印排序前的数组
    printf("排序前：\n");
    // printNameArr(name_arr, NAME_ARR_SIZE);
    printGenericArray(name_arr, NAME_ARR_SIZE, sizeof(struct Name), printName);

    // 排序
    qsort(name_arr, NAME_ARR_SIZE, sizeof(struct Name), nameComp);

    // 打印排序后的数组
    printf("排序后：\n");
    // printNameArr(name_arr, NAME_ARR_SIZE);
    printGenericArray(name_arr, NAME_ARR_SIZE, sizeof(struct Name), printName);

    return 0;
}

// 打印 struct Name 数组的函数
// void printNameArr(struct Name *p_name, size_t ele_num)
// {
//     register size_t i;

//     for (i = 0; i < ele_num; ++i)
//     {
//         printf("%s %s\n", p_name[i].first_name, p_name[i].last_name);
//     }
// }

// 用于打印单个 struct Name 变量的函数，用于 MyArrayPrinter 库
void printName(const void *p_name)
{
    const struct Name *name = (const struct Name *)p_name;
    printf("“%s %s”\n", name->first_name, name->last_name);
}

// 比较两个 struct Name 变量的函数，用于 qsort 排序
int nameComp(const void *name_1, const void *name_2)
{
    // // 按照 first name 顺序排序
    // const char * last_name_1 = ((struct Name*)name_1)->first_name;
    // const char * last_name_2 = ((struct Name*)name_2)->first_name;

    // return strcmp(last_name_1, last_name_2);

    // 按照 last name 顺序排序
    // return strcmp(((struct Name*)name_1)->last_name, ((struct Name*)name_2)->last_name);

    // 按照 fitst name 逆序排序
    return -strcmp(((struct Name *)name_1)->first_name, ((struct Name *)name_2)->first_name);
}