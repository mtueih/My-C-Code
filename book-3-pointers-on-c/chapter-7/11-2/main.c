/**
 * @file     book-3-pointers-on-c/chapter-7/7-11-2/main.c
 * @author   mtueih
 * @date     2025-12-02 21:30
 * @brief    计算两数的最大公约数。
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n);

int main(void) {

    int m, n;

    printf("输入 m，n：");

    scanf("%d %d", &m, &n);

    printf("gcd(%d, %d) = %d\n", m, n, gcd(m, n));

    return EXIT_SUCCESS;
}

int gcd(int m, int n) {
	int r;

	if (m < 0 || n < 0) {
		goto end;
	}

	if (m % n == 0) {
		return n;
	} else if (r = m % n, r > 0) {
		return gcd(n, r);
	} 

end:
	return 0;	
}
