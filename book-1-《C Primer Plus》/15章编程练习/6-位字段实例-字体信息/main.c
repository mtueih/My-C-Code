#include <stdio.h>
#include <string.h>

#define FONT_ALIGN_LEFT 0x2u
#define FONT_ALIGN_RIGHT 0x1u
#define FONT_ALIGN_CENTER (FONT_ALIGN_LEFT | FONT_ALIGN_RIGHT)

#define TRUE 1
#define FALSE 0

// 位字段-字体信息
struct FontInfo
{
    unsigned font_id : 8;
    unsigned font_size : 7;
    unsigned : 1;
    unsigned font_align : 2;
    _Bool font_bold : 1;
    _Bool font_italic : 1;
    _Bool font_underline : 1;
};

// 打印字体信息
void printFontInfo(const struct FontInfo *p_font_info);

int main(void)
{
    struct FontInfo font_info_0 = {
        1, 12, FONT_ALIGN_LEFT, FALSE, FALSE, FALSE};

    int choice, choice_align;
    unsigned temp;

    do
    {
        // 打印字体数据
        printFontInfo(&font_info_0);
        // 提示信息，获取用户输入
        printf("f)change font\ts)change size  \ta)change alignment\n"
               "b)toggle bold\ti)toggle italic\tu)toggle underline\n"
               "q)quit\n");

        printf("Enter your choice: ");
        choice = getchar();
        while (getchar() != '\n')
            continue;
        // 处理输入
        switch (choice)
        {
        case 'f':
            printf("Enter the font id (0 ~ 255): ");
            scanf("%u", &temp);
            font_info_0.font_id = temp & 0xffu;
            break;
        case 's':
            printf("Enter the font id (0 ~ 127): ");
            scanf("%u", &temp);
            font_info_0.font_size = temp & 0x7fu;
            break;
        case 'a':
            printf("Select alignment:\n\tl)left\tc)center\tr)right\n");
            choice_align = getchar();
            while (getchar() != '\n')
                continue;
            switch (choice_align)
            {
            case 'l':
                font_info_0.font_align = FONT_ALIGN_LEFT;
                break;
            case 'c':
                font_info_0.font_align = FONT_ALIGN_CENTER;
                break;
            case 'r':
                font_info_0.font_align = FONT_ALIGN_RIGHT;
                break;
            default:
                printf("\'%c\', unknown selection, notiong changed.\n", choice_align);
                break;
            }
            break;
        case 'b':
            font_info_0.font_bold ^= 0x1u;
            break;
        case 'i':
            font_info_0.font_italic ^= 0x1u;
            break;
        case 'u':
            font_info_0.font_underline ^= 0x1u;
            break;
        case 'q':
            break;
        default:
            printf("Unknown selection.\n");
            break;
        }

    } while (choice != 'q');

    printf("\n再见👋\n");
    return 0;
}

// 打印字体信息
void printFontInfo(const struct FontInfo *p_font_info)
{
    printf("\n\t\t➡️FONT INFO⬅️\n"
           "\tID \tSize\tAlignment\tBold\tItalic\tUnderline\n"
           "\t%-3u\t%-4u\t%-9s\t%-5s\t%-6s\t%-9s\n",
           p_font_info->font_id,
           p_font_info->font_size,
           p_font_info->font_align == FONT_ALIGN_LEFT
               ? "left"
           : p_font_info->font_align == FONT_ALIGN_CENTER
               ? "center"
           : p_font_info->font_align == FONT_ALIGN_RIGHT
               ? "right"
               : "none",
           p_font_info->font_bold == TRUE
               ? "true"
               : "false",
           p_font_info->font_italic == TRUE
               ? "true"
               : "false",
           p_font_info->font_underline == TRUE
               ? "true"
               : "false");
}