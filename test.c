#include <stdio.h>
#include <string.h>

int main(void) {
	printf("你好，世界！\n");

	char str[5] = { [4] = '6' };

	size_t i;

	strncpy(str, "he", 4);

	for (i = 0; i < 5; ++i) {
		printf("[%zu]: \'%c\'\n", i, str[i] == '\0' ? '0' : str[i]);
	}

	return 0;
}