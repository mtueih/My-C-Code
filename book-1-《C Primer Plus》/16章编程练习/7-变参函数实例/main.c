#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "MyArrayPrinter.h"

// 打印 double 数组函数
// void show_array(const double *arr, size_t ele_num);

// 变参函数，创建指定数量元素的 double 数组
double *new_double_arr(size_t ele_num, ...);

int main(void)
{

    double *p1;
    double *p2;

    p1 = new_double_arr(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_double_arr(4, 100.0, 20.00, 8.08, -1890.0);

    // show_array(p1, 5);
    // show_array(p2, 4);
    printArray(p1, 5);
    printArray(p2, 4);

    free(p1);
    free(p2);

    return 0;
}

// 打印 double 数组函数
// void show_array(const double *arr, size_t ele_num)
// {
//     register size_t i;

//     for (i = 0; i < ele_num; ++i)
//     {
//         printf("%g\t", arr[i]);
//         if ((i + 1) % 10 == 0)
//             putchar('\n');
//     }
//     putchar('\n');
// }

// 变参函数，创建指定数量元素的 double 数组
double *new_double_arr(size_t ele_num, ...)
{
    double *p_arr_0;
    va_list args;
    register size_t i;

    p_arr_0 = (double *)malloc(ele_num * sizeof(double));
    if (p_arr_0 == NULL)
    {
        fprintf(stderr, "内存分配失败！\n");
        return NULL;
    }

    va_start(args, ele_num);

    for (i = 0; i < ele_num; ++i)
    {
        p_arr_0[i] = va_arg(args, double);
    }

    va_end(args);
    return p_arr_0;
}