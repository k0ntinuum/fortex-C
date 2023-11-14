// void spin_row(u32 i) {
//     u32 tmp = g[i][0];
//     for (u32 j = 1 ; j < len[i] ; j++) g[i][j-1] = g[i][j];
//     g[i][len[i]-1] = tmp;
// }
void spin_key(u32 k[N][L], u32 a) {
    u32 temp;
    for (u32 t = 0; t < a ; t++) {
        for (u32 i = 0; i < N; i++) {
            temp = k[i][0];
            for (u32 j = 1 ; j < len[i] ; j++) k[i][j-1] = k[i][j];
            k[i][len[i]-1] = temp;
        }
    }
}
u32 stack(u32 key[N][L]) {
	u32 s = 0;
	for (u32 i = 0; i < N; i++) s += key[i][0];
	return s%B;
}