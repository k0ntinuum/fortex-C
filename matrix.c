

void shift_row(u32 h[N][N], u32 r, u32 s) {
    for (u32 i = 0; i < N; i++) temp[i] = h[r][(i + s)%N];
    for (u32 i = 0; i < N; i++) h[r][i] = temp[i];
}
void shift_col(u32 h[N][N], u32 c, u32 s) {
    for (u32 i = 0; i < N; i++) temp[i] = h[(i + s)%N][c];
    for (u32 i = 0; i < N; i++) h[i][c] = temp[i];
}
u32 random_bit() { 
	return arc4random_uniform(2);
}
void randomize_key(u32 h[N][N]) {
	for (u32 i = 0; i < N; i++) for (u32 j = 0; j < N; j++) h[i][j] = random_bit();
}
void reset_g() {
    for (u32 i = 0; i < N; i++) for (u32 j = 0; j < N; j++) g[i][j] = f[i][j];
}
void copy_key(u32 t[N][N],u32 s[N][N]) {
    for (u32 i = 0; i < N; i++) for (u32 j = 0; j < N; j++) t[i][j] = s[i][j];
}
void randomize_p() {
	for (u32 i = 0; i < T; i++) p[i] = random_bit();
}
void copy_text(u32 t[T] , u32 s[T]) {
	for (u32 i = 0; i < T; i++) t[i] = s[i];
}
void check_decryption() {
	for (u32 i = 0; i < T; i++) if (check_p[i] != d[i]) printf("recovery failure at bit %d \n",i);
}
void update_e() {
	for (u32 i = 0; i < T; i++) {if (check_p[i] == c[i]) e[i] = 0; else e[i] = 1;}
}
u32 trace(u32 h[N][N]) {
	u32 s = 0;
	for (u32 i = 0; i < N; i++) s += h[i][i];
	return s;
}
