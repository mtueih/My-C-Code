#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>

#define IS_LEAP_YEAR(year) (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0)
#define DAY_NUM_OF_YEAR(year) (IS_LEAP_YEAR(year) ? 366 : 365)

void printMenu(void);
void calDateDif(void);
void calFinalDate(void);
// 计算某年的某个月份有多少天
uint_least8_t dayNumOfMouth(uint_least16_t year, uint_least8_t mouth);
// 计算一个日期是当年的第几天
uint_least16_t dayNumFromFirOfYear(uint_least16_t year, uint_least8_t mouth, uint8_t day);

int main(void) {
    int userChoice = 0;

    do {
        printMenu();
        printf("请输入你的选择：");
        while (scanf("%d", &userChoice) != 1) {
            while (getchar() != '\n');
            printf("输入错误！请重新输入！\n");
            printf("请输入你的选择：");
        }
        switch (userChoice) {
            case 1:  calDateDif();
                     break;
            case 2:  calFinalDate();
                     break;
            case 0:  printf("感谢使用，再见！\n");
                     break;
            default: printf("输入错误！请重新输入！\n");
                     break;
        }
    } while (userChoice);
}

void printMenu(void) {
    printf("=================================\n"
           "===========时间差计算器===========\n"
           "=================================\n"
           "【1】计算两个日期之间的相差多少天（阳历）；\n"
           "【2】计算一个日期之后（或之前，用负值表示之前）若干天的日期（阳历）；\n"
           "【0】退出程序。\n"
    );
}

void calDateDif(void) {
    // 存储两个日期的变量
    uint_least16_t year1 = 0, year2 = 0;
    uint_least8_t month1 = 0, month2 = 0; 
    uint_least8_t day1 = 0, day2 = 0;
    struct tm tm1 = { 0 }, tm2 = { 0 };
    time_t t1 = 0, t2 = 0;
    double dateDiffSeconds = 0.0;
    // 存储两个日期相差的天数
    intmax_t dateDif = 0;
    
    printf("【计算两个日期之间的相差多少天（阳历）】\n");
    
    printf("请输入第一个日期（年、月、日用空格分隔）：");
    while (scanf("%"SCNu16" %"SCNu8" %"SCNu8, &year1, &month1, &day1) != 3 
                || month1 > 12 || day1 > dayNumOfMouth(year1, month1)) {
        while (getchar() != '\n');
        printf("输入错误或输入日期不合法！请重新输入！\n");
        printf("请输入第一个日期（年、月、日用空格分隔）：");
    }
    printf("请输入第二个日期（年、月、日用空格分隔）：");
    while (scanf("%"SCNu16" %"SCNu8" %"SCNu8, &year2, &month2, &day2) != 3
                || month2 > 12 || day2 > dayNumOfMouth(year2, month2)) {
        while (getchar() != '\n');
        printf("输入错误或输入日期不合法！请重新输入！\n");
        printf("请输入第二个日期（年、月、日用空格分隔）：");
    }
    tm1.tm_year = year1 - 1900;
    tm1.tm_mon = month1 - 1;
    tm1.tm_mday = day1;
    tm1.tm_hour = 12;
    

    tm2.tm_year = year2 - 1900;
    tm2.tm_mon = month2 - 1;
    tm2.tm_mday = day2;
    tm2.tm_hour = 12;

    t1 = mktime(&tm1);
    t2 = mktime(&tm2);


    dateDiffSeconds = difftime(t2, t1);
    dateDif = (intmax_t)(dateDiffSeconds / (60 * 60 * 24));

    printf("两个日期之间的相差天数为：%jd\n", dateDif);
}

void calFinalDate(void) {
    // 存储两个日期的变量
    uint_least16_t year1 = 0, year2 = 0;
    uint_least8_t month1 = 0, month2 = 0; 
    uint_least8_t day1 = 0, day2 = 0;
    struct tm tm1 = { 0 }, tm2 = { 0 };
    time_t t1 = 0, t2 = 0;
    double dateDiffSeconds = 0.0;
    // 存储两个日期相差的天数
    intmax_t dateDif = 0;

    printf("【计算一个日期之后（或之前，用负值表示之前）若干天的日期（阳历）】\n");
    
    printf("请输入起始日期（年、月、日用空格分隔）：");
    while (scanf("%"SCNu16" %"SCNu8" %"SCNu8, &year1, &month1, &day1) != 3 
                || month1 > 12 || day1 > dayNumOfMouth(year1, month1)) {
        while (getchar() != '\n');
        printf("输入错误或输入日期不合法！请重新输入！\n");
        printf("请输入第一个日期（年、月、日用空格分隔）：");
    }

    printf("请输入相隔天数（正数表示之后，负数表示之前）：");
    while (scanf("%"SCNdMAX, &dateDif) != 1) {
        while (getchar() != '\n');
        printf("输入错误！请重新输入！\n");
        printf("请输入相隔天数（正数表示之后，负数表示之前）：");
    }

    tm1.tm_year = year1 - 1900;
    tm1.tm_mon = month1 - 1;
    tm1.tm_mday = day1;
    tm1.tm_hour = 12;

    t1 = mktime(&tm1);
    t2 = t1 + dateDif * 60 * 60 * 24;

    tm2 = *localtime(&t2);

    year2 = tm2.tm_year + 1900;
    month2 = tm2.tm_mon + 1;
    day2 = tm2.tm_mday;

    printf("相隔%jd天之后的日期是：%d-%d-%d\n", dateDif, year2, month2, day2);
}

uint_least8_t dayNumOfMouth(uint_least16_t year, uint_least8_t mouth) {
    switch (mouth) {
        case 2:  return IS_LEAP_YEAR(year) ? 29 : 28;
                 break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
                 break;
        case 4:
        case 6:
        case 9:
        case 11: return 30;
                 break;  
        default: return 0;
                 break;
    }

}

uint_least16_t dayNumFromFirOfYear(uint_least16_t year, uint_least8_t mouth, uint8_t day) {
    register uint_fast16_t i;
    uint_least16_t dayNum = 0;

    for (i = 1; i < mouth; ++i) {
        dayNum += dayNumOfMouth(year, i);
    }
    return dayNum + day;
}