void shuffle(u32* v, u32 len) {
    u32 j = 0;
    u32 temp = 0;
    for (u32 i = len - 1; i > 0; i -= 1) {
        j = arc4random_uniform(i+1);
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void randomize_len() {
	for (u32 i = 0; i < N; i++) len[i] = i+1;
	//shuffle(len, N);
}

void randomize_f() {
    for (u32 i = 0; i < N; i++) 
        for (u32 j = 0; j < len[i]; j++)
            f[i][j] = arc4random_uniform(B);
}
void randomize_p() {
	for (u32 i = 0; i < T; i++) p[i] = arc4random_uniform(B);
}
void circshift(u32* v, u32 l, u32 a) {
    for (u32 i = 0; i < l; i++) temp[i] = v[(i + a)%l];
    for (u32 i = 0; i < l; i++) v[i] = temp[i];
}

void spin_row(u32 i) {
    u32 tmp = g[i][0];
    for (u32 j = 1 ; j < len[i] ; j++) g[i][j-1] = g[i][j];
    g[i][len[i]-1] = tmp;
}
void spin_g(u32 a) {
    for (u32 j = 0; j < a ; j++) for (u32 i = 0; i < N; i++) spin_row(i);
}
u32 stack() {
	u32 s = 0;
	for (u32 i = 0; i < N; i++) s += g[i][0];
	return s;
}
void check_decryption() {
	for (u32 i = 0; i < T; i++) if (p[i] != d[i]) printf("recovery failure at bit %d \n",i);
}