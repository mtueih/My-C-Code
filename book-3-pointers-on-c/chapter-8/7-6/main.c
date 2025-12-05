/**
 * @file     book-3-pointers-on-c/chapter-8/main.c
 * @author   mtueih
 * @date     2025-12-05 10:11
 * @brief    测试汇编代码的紧凑程度。
 */

#define SIZE 50
int x[SIZE];
int y[SIZE];
int i;
int *p1, *p2;

// void try1(void) {
// 	for (i = 0; i < SIZE; i++)
// 		x[i] = y[i];
// }

// void try2(void) {
// 	for (p1 = x, p2 = y; p1 - x < SIZE;)
// 		*p1++ = *p2++;
// }

// void try3(void) {
// 	for (i = 0, p1 = x, p2 = y; i < SIZE; i++)
// 		*p1++ = *p2++;
// }

// void try4(void) {
// 	register int *p1, *p2;
// 	register int i;

// 	for (i = 0, p1 = x, p2 = y; i < SIZE; i++)
// 		*p1++ = *p2++;
// }

void try5(void) {
	register int *p1, *p2;

	for (p1 = x, p2 = y; p1 < &x[SIZE];)
		*p1++ = *p2++;
}