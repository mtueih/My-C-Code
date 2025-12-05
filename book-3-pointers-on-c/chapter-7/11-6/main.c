/**
 * @file     book-3-pointers-on-c/chapter-7/11-6/main.c
 * @author   mtueih
 * @date     2025-12-03 11:12
 * @brief    将无符号整数值转换为单词形式。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define STR_BUFFER_MAX 4096u
#define NUM_ONE_WORD_NUM 19u
#define NUM_TEN_WORD_NUM 10u
#define NUM_UNIT_WORD_NUM 4u
#define NUM_UINT_BASE 1000u
#define NUM_UNIT_HUNDRED 100u
#define NUM_UNIT_TEN 10u

const char *const Num_One_Word_Strs[NUM_ONE_WORD_NUM] = {
    "ONE",     "TWO",	  "THREE",     "FOUR",	   "FIVE",    "SIX",	  "SEVEN",
    "EIGHT",   "NINE",	  "TEN",       "ELEVEN",   "TWELVE",  "THIRTEEN", "FOURTEEN",
    "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
const char *const Num_Ten_Word_Strs[NUM_TEN_WORD_NUM] = {
    "TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY", "HUNDRED"};

const char *const Num_Unit_Word_Strs[NUM_UNIT_WORD_NUM] = {"THOUSAND", "MILLION", "BILLION",
							   "TRILLION"};

void written_amount(uintmax_t amount, char *buffer);

int main(void) {
	sizeof(unsigned long);
	uintmax_t num;
	char str[STR_BUFFER_MAX];

	str[0] = '\0';

	printf("输入 num：");
	scanf("%ju", &num);

	written_amount(num, str);

	printf("num：[%ju] 转为单词形式：\n", num);
	fputs(str, stdout);

	return EXIT_SUCCESS;
}

void written_amount(uintmax_t amount, char *buffer) {
	uintmax_t merchant, remainder;
	static unsigned unit_level = 0;

	merchant = amount / NUM_UINT_BASE;
	remainder = amount % NUM_UINT_BASE;

	if (merchant) {
		++unit_level;
		written_amount(merchant, buffer);
	}

	if (!remainder)
		return;

	if (remainder / NUM_UNIT_HUNDRED) {
		// [n] (hundred)
		strcat(buffer, Num_One_Word_Strs[remainder / NUM_UNIT_HUNDRED - 1]);
		strcat(buffer, " ");
		// [hundred]
		strcat(buffer, Num_Ten_Word_Strs[NUM_TEN_WORD_NUM - 1]);
		strcat(buffer, " ");
	}
	if (remainder % NUM_UNIT_HUNDRED) {
		// 1 - 19
		if (remainder % NUM_UNIT_HUNDRED <= NUM_ONE_WORD_NUM) {
			strcat(buffer, Num_One_Word_Strs[remainder % NUM_UNIT_HUNDRED - 1]);
			strcat(buffer, " ");
		} else { //  > 19
			if (remainder % NUM_UNIT_HUNDRED / NUM_UNIT_TEN) {
				strcat(
				    buffer,
				    Num_Ten_Word_Strs[remainder % NUM_UNIT_HUNDRED / NUM_UNIT_TEN -
						      1]);
				strcat(buffer, " ");
			}
			if (remainder % NUM_UNIT_HUNDRED % NUM_UNIT_TEN) {
				strcat(
				    buffer,
				    Num_One_Word_Strs[remainder % NUM_UNIT_HUNDRED % NUM_UNIT_TEN -
						      1]);
				strcat(buffer, " ");
			}
		}
	}
	if (unit_level) {
		strcat(buffer, Num_Unit_Word_Strs[unit_level % NUM_UNIT_WORD_NUM - 1]);
		strcat(buffer, " ");
		--unit_level;
	}
}
