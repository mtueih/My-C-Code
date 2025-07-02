#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "mydefs.h"

int main(int argc, char **argv)
{
    register unsigned char i;
    FILE *p_file_0;
    int ch;

    if (argc < 2)
    {
        fprintf(stderr, "\n\t:Usage: touch <file1> [file2] ...\t\n");
        return EXIT_FAILURE;
    }

    for (i = 1; i < MIN(argc, UCHAR_MAX); ++i)
    {
        // 尝试打开文件——用于检查文件是否已存在
        p_file_0 = fopen(argv[i], "r");
        if (p_file_0 != NULL)
        {
            fclose(p_file_0);

            printf("文件“%s”已存在，是否覆盖？[y/N]", argv[i]);

            ch = getchar();
            if (ch != '\n')
                while (getchar() != '\n')
                    continue;
            if (ch != 'y' && ch != 'Y')
            {
                continue;
            }
        }

        p_file_0 = fopen(argv[i], "w");
        if (p_file_0 == NULL)
        {
            fprintf(stderr, "文件“%s”创建失败！\n", argv[i]);
        }
        else
        {
            fclose(p_file_0);
            printf("文件“%s”创建成功！\n", argv[i]);
        }
    }

    return EXIT_SUCCESS;
}
