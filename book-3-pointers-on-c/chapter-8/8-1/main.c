/**
 * @file     book-3-pointers-on-c/chapter-8/8-1/main.c
 * @author   mtueih
 * @date     2025-12-05 21:13
 * @brief    对数组特定元素初始化。
 */

#include <stdio.h>
#include <stdlib.h>

#define A 3
#define B 6
#define C 4
#define D 5

int main(void)
{

	// 1、使用嵌套花括号
	char char_value[A][B][C][D] = {// [0]
				       {},
				       // [1]
				       {// [1][0]
					{},
					// [1][1]
					{// [1][1][0]
					 {},
					 // [1][1][1]
					 {// [1][1][1][0]
					  0,
					  // [1][1][1][1]
					  ' '}},
					// [1][2]
					{// [1][2][0]
					 {},
					 // [1][2][1]
					 {},
					 // [1][2][2]
					 {// [1][2][2][0]
					  0,
					  // [1][2][2][1]
					  0,
					  // [1][2][2][2]
					  0,
					  // [1][2][2][3]
					  'A'},
					 {0, 0, 0, 0, 'x'}},
					// [1][3]
					{{},
					 {},
					 // [1][3][2]
					 {0, 0,
					  // [1][3][2][2]
					  0xf3}

					},
					// [1][4]
					{{},
					 {},
					 // [1][4][2]
					 {0, 0, 0,
					  // [1][4][2][3]
					  '\n'}}},
				       // [2]
				       {{},
					// [2][1]
					{{},
					 // [2][1][1]
					 {0, '0',
					  // [2][1][1][2]
					  0320}},
					// [2][2]
					{{},
					 {},
					 // [2][2][2]
					 {0, 0,
					  // [2][2][2][2]
					  '\''},
					 {0,
					  // [2][2][3][1]
					  '\121'}},
					{},
					// [2][4]
					{
					    {},
					    {},
					    {},
					    // [2][4][3]
					    {0, 0,
					     // [2][4][3][2]
					     '3',
					     // [2][4][3][3]
					     3},
					},
					// [2][5]
					{{},
					 {},
					 {},
					 // [2][5][3]
					 {0, 0, 0, 0,
					  // [2][5][3][4]
					  125}}}};

	int a, b, c, d;

	for (a = 0; a < A; a++)
	{
		for (b = 0; b < B; b++)
		{
			for (c = 0; c < C; c++)
			{
				for (d = 0; d < D; d++)
				{
					if (char_value[a][b][c][d])
					{
						printf("char_value[%d][%d][%d][%d]：%d\t", a, b, c, d,
						       char_value[a][b][c][d]);

						switch (char_value[a][b][c][d])
						{
						case 'A':
							printf("\'A\'");
							break;
						case ' ':
							printf("\' \'");
							break;
						case 0xf3:
							printf("0xf3");
							break;
						case '3':
							printf("\'3\'");
							break;
						case '\n':
							printf("\'\\n\'");
							break;
						case '\121':
							printf("\'\\121\'");
							break;
						case 3:
							printf("3");
							break;
						case 125:
							printf("125");
							break;
						case 'x':
							printf("\'x\'");
							break;
						case 0320:
							printf("0320");
							break;
						case '\'':
							printf("\'\\\'\'");
							break;
						case '0':
							printf("\'0\'");
							break;
						default:
							break;
						}

						printf("\n");
					}
				}
				// printf("\n");
			}
			// printf("----------------------------------\n");
		}
		// printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	}

	return EXIT_SUCCESS;
}
