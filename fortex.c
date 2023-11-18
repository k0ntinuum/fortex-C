#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <inttypes.h>
typedef u_int32_t u32;
typedef u_int64_t u64;
const u32 N = 29;
const u32 L = 200;
const u32 T = 32;
const u32 B = 2;
u32 len[N] = {0};
#include"shuffle.c"
#include"randomize.c"
#include"key.c"
#include"print.c"
#include"encode.c"
#include"encryption_demo.c"
#include"demo.c"
	
int main() {
	encoding_demo();
	//demo();

}
