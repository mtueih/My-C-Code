#include "mydefs.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char * const codePath = "code";

int main(int argc, char **argv)

{
    register unsigned char i;   // 用于循环计数
    FILE *p_file_0;           // 文件指针
    int ch;                    // 用于存储用户输入的字符
    char * openCommand;        // 用于存储打开文件的命令

    if (argc < 2) {
        fprintf(stderr, "\n\t:Usage: touchaowc <file1> [file2] ...\t\n");
        return EXIT_FAILURE;
    }

    for (i = 1; i < MIN(argc, UCHAR_MAX); ++i) {
        // 尝试打开文件——用于检查文件是否已存在
        p_file_0 = fopen(argv[i], "r");
        if (p_file_0 != NULL) {
            fclose(p_file_0);

            printf("文件“%s”已存在，是否覆盖？[y/N]", argv[i]);

            ch = getchar();
            if (ch != '\n')
                while (getchar() != '\n')   // 读取并丢弃多余的输入字符
                    continue;
            if (ch != 'y' && ch != 'Y') {
                continue;
            }
        }

        p_file_0 = fopen(argv[i], "w");
        if (p_file_0 == NULL) {
            fprintf(stderr, "文件“%s”创建失败！\n", argv[i]);
        } else {
            fclose(p_file_0);
            printf("文件“%s”创建成功！\n", argv[i]);
            // 构建打开文件的命令字符串
            openCommand = (char *)malloc(strlen(codePath) + strlen(argv[i]) + 2);
            if (openCommand != NULL) {
                sprintf(openCommand, "%s %s", codePath, argv[i]);
                system(openCommand);  // 使用系统命令打开文件
                free(openCommand);    // 释放分配的内存
            } else {
                fprintf(stderr, "内存分配失败，无法打开文件“%s”！\n", argv[i]);
            }
        }
    }

    return EXIT_SUCCESS;
}
