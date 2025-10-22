#ifndef _WIN32
	#error "This program is only for Windows"
#endif

#include <stdio.h>
#include <stdlib.h>


const char * const Aria2_Path = ".\\aria2c.exe";


int main(void) {
	system("chcp 65001 > nul");

	printf("测试 aria2 下载。\n");

	system(Aria2_Path);

	return 0;
}