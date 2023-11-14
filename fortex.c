#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <inttypes.h>
typedef u_int32_t u32;
typedef u_int64_t u64;
const u32 N = 37;
const u32 L = 50;
const u32 T = 64;
const u32 B = 2;
u32 f[N][L] = {0};
u32 g[N][L] = {0};
u32 len[N] = {0};
u32 temp[L] = {0};
u32 p[T];
u32 c[T];
u32 d[T];
#include"shuffle.c"
#include"print.c"

//#include"matrix.c"
#include"encode.c"
//#include"encrypt.c"
#include"demo.c"
	
int main() {
	randomize_len();
	randomize_f();
	demo();
	// print_f();
	// randomize_p();
	// print_text(p);
	// encode();
	// printf("\n");
	// print_text(c);
	// decode();
	// printf("\n");
	// print_text(d);
	// check_decryption();


}
