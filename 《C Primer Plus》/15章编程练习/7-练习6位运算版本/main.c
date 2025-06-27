/*
    使用一个 unsigned long 变量存储一下信息
    0~7 : 字体 ID（0-127）
    8~14 : 字体大小（0-255）
    15 : 下划线
    16~17 : 对齐
    18 : 粗体
    19 : 斜体
*/

#include <stdio.h>

// 宏定义每块数据的起始位置（INDEX）
#define FONT_ID_START_INDEX 0U
#define FONT_SIZE_START_INDEX 8U
#define FONT_ALIGN_START_INDEX 16U
#define FONT_BOLD_START_INDEX 18U
#define FONT_ITALIC_START_INDEX 19U
#define FONT_UNDERLINE_START_INDEX 15U

// 宏定义每块数据的置位掩码（Set Mask）
#define FONT_ID_SET_MASK (0xfful << FONT_ID_START_INDEX)
#define FONT_SIZE_SET_MASK (0x7ful << FONT_SIZE_START_INDEX)
#define FONT_ALIGN_SET_MASK (0x3ul << FONT_ALIGN_START_INDEX)
#define FONT_BOLD_SET_MASK (0x1ul << FONT_BOLD_START_INDEX)
#define FONT_ITALIC_SET_MASK (0x1ul << FONT_ITALIC_START_INDEX)
#define FONT_UNDERLINE_SET_MASK (0x1ul << FONT_UNDERLINE_START_INDEX)

// 宏定义每块数据的复位掩码（Reset Mask）
#define FONT_ID_RESET_MASK (~FONT_ID_SET_MASK)
#define FONT_SIZE_RESET_MASK (~FONT_SIZE_SET_MASK)
#define FONT_ALIGN_RESET_MASK (~FONT_ALIGN_SET_MASK)
#define FONT_BOLD_RESET_MASK (~FONT_BOLD_SET_MASK)
#define FONT_ITALIC_RESET_MASK (~FONT_ITALIC_SET_MASK)
#define FONT_UNDERLINE_RESET_MASK (~FONT_UNDERLINE_SET_MASK)


// 文字对齐枚举
enum FontAlignment {
    None,   // 0 对应二进制 00
    Right,  // 1 对应二进制 01
    Left,   // 2 对应二进制 10
    Center  // 3 对应二进制 11
};

// 用于修改各块数据的函数
void setFontID(unsigned long * p_font_info, unsigned long font_id);
void setFontSize(unsigned long * p_font_info, unsigned long font_size);
void setFontAlign(unsigned long * p_font_info, enum FontAlignment font_align);
void toggleFontBold(unsigned long * p_font_info);
void toggleFontItalic(unsigned long * p_font_info);
void toggleFontUnderline(unsigned long * p_font_info);

// 用于打印字体信息的函数
void printFontInfo(unsigned long font_info);

// 用于根据枚举值获取文字对齐字符串的函数
const char* getFontAlignStr(enum FontAlignment font_align);

int main(void) {
    unsigned long font_info = 0x0ul;
    int user_choice = 0, user_choice_align;
    unsigned long temp;

    // 初始化
    // 字体 ID ：1
    setFontID(&font_info, 1ul);
    // 字体大小 ：12
    setFontSize(&font_info, 12ul);
    // 文字对齐
    setFontAlign(&font_info, Left);
    // 文字加粗，斜体，下划线默认 0 （False）

    do {
        // 打印字体信息
        printFontInfo(font_info);
        // 提示信息，获取用户输入
        printf("f)change font\ts)change size  \ta)change alignment\n"
               "b)toggle bold\ti)toggle italic\tu)toggle underline\n"
               "q)quit\n");
        
        printf("Enter your choice: ");
        user_choice = getchar();

        while (getchar() != '\n') 
            continue;
        // 处理输入
        switch (user_choice) {
            case 'f':
                printf("Enter the font id (0 ~ 255): ");
                scanf("%lu", &temp);
                while (getchar() != '\n') 
                    continue;
                setFontID(&font_info, temp);
                break;
            case 's':
                printf("Enter the font size (0 ~ 127): ");
                scanf("%lu", &temp);
                while (getchar() != '\n') 
                    continue;
                setFontSize(&font_info, temp);
                break;
            case 'a':
                printf("Select alignment:\n\tl)left\tc)center\tr)right\n");
                user_choice_align = getchar();
                while (getchar() != '\n') 
                    continue;
                switch (user_choice_align) {
                    case 'l':
                        setFontAlign(&font_info, Left);
                        break;
                    case 'c':
                        setFontAlign(&font_info, Center);
                        break;
                    case 'r':
                        setFontAlign(&font_info, Right);
                        break;
                    default:
                        printf("\'%c\', unknown selection, notiong changed.\n", 
                            user_choice_align);
                        break;
                }
                break;
            case 'b':
                toggleFontBold(&font_info);
                break;
            case 'i':
                toggleFontItalic(&font_info);
                break;
            case 'u':
                toggleFontUnderline(&font_info);
                break;
            case 'q':
                break;
            default:
                printf("Unknown selection.\n");
                break;
        }
        

    } while (user_choice != 'q');

    printf("Bye!\n");

    return 0;
}

// 用于修改各块数据的函数
void setFontID(unsigned long * p_font_info, unsigned long font_id) {
    *p_font_info &= FONT_ID_RESET_MASK;
    *p_font_info |= (font_id << FONT_ID_START_INDEX) & FONT_ID_SET_MASK; 
}

void setFontSize(unsigned long * p_font_info, unsigned long font_size) {
    *p_font_info &= FONT_SIZE_RESET_MASK;
    *p_font_info |= (font_size << FONT_SIZE_START_INDEX) & FONT_SIZE_SET_MASK; 
}

void setFontAlign(unsigned long * p_font_info, enum FontAlignment font_align) {
    *p_font_info &= FONT_ALIGN_RESET_MASK;
    *p_font_info |= (font_align << FONT_ALIGN_START_INDEX) & FONT_ALIGN_SET_MASK; 
}

void toggleFontBold(unsigned long * p_font_info) {
    *p_font_info ^= FONT_BOLD_SET_MASK;
}

void toggleFontItalic(unsigned long * p_font_info) {
    *p_font_info ^= FONT_ITALIC_SET_MASK;
}

void toggleFontUnderline(unsigned long * p_font_info) {
    *p_font_info ^= FONT_UNDERLINE_SET_MASK;
}


void printFontInfo(unsigned long font_info) {
    printf("\t-> FONT INFO <-\t\n");
    printf("\tID \tSize\tAlignment\tBold \tItalic\tUnderline\n");
    // 字体 ID
    printf("\t%-3lu", (font_info & FONT_ID_SET_MASK) >> FONT_ID_START_INDEX);
    // 字体大小
    printf("\t%-4lu", (font_info & FONT_SIZE_SET_MASK) >> FONT_SIZE_START_INDEX);
    // 文字对齐
    printf("\t%-9s", getFontAlignStr((font_info & FONT_ALIGN_SET_MASK) 
                                        >> FONT_ALIGN_START_INDEX));
    // 字体加粗
    printf("\t%-5s", ((font_info & FONT_BOLD_SET_MASK) 
                        >> FONT_BOLD_START_INDEX)
                        ? "True" : "False");
    // 字体斜体
    printf("\t%-6s", ((font_info & FONT_ITALIC_SET_MASK) 
                        >> FONT_ITALIC_START_INDEX)
                        ? "True" : "False");
    // 字体下划线
    printf("\t%-9s", ((font_info & FONT_UNDERLINE_SET_MASK) 
                        >> FONT_UNDERLINE_START_INDEX)
                        ? "True" : "False");

    putchar('\n');
}

const char* getFontAlignStr(enum FontAlignment font_align) {
    switch (font_align) {
        case Right: 
            return "Right";
            break;
        case Left: 
            return "Left";
            break;
        case Center: 
            return "Center";
            break;
        case None: 
        default:
            return "None";
            break;
    }
}