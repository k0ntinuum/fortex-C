// void spin(u32 h[N][N], u32 d, u32 a) {
// 	for (u32 i = 0 ; i < N ; i++) {
// 		switch ((i + d )% 2) {
// 			case 0 : shift_row(h, i, h[i][i] + a + 1);break;
// 			case 1 : shift_col(h, i, h[i][i] + a + 1);break;
// 		}
// 	}
// }
// void auto_spin(u32 h[N][N], u32 j) {
// 	for (u32 i = 0 ; i < N ; i++) {
//         switch (h[i][j]) {
//             case 0 : shift_row(h, i, h[i][i] + 1);break;
//             case 1 : shift_col(h, i, h[i][i] + 1);break;
//         }
// 	}
// }

// void reverse(u32 t[T]) {
//     u32 temp[T] = {0};
//     for (u32 i = 0; i < T; i++) temp[T-i-1] = t[i];
//     for (u32 i = 0; i < T; i++) t[i] = temp[i];
// }
void reset_g() {
    for (u32 i = 0; i < N; i++) for (u32 j = 0; j < len[i]; j++) g[i][j] = f[i][j];
}
void encode() {
	reset_g();
	for (u32 i = 0 ; i < T ; i++) {
		c[i] = ( stack() + p[i] ) % B;
		spin_g(c[i]+1);
	}
    //reverse(c);
}
void decode() {
	reset_g();
    //reverse(c);
	for (u32 i = 0 ; i < T ; i++) {
		d[i] = (B*N + c[i] - stack())%B;
		spin_g(c[i]+1);
	}
}


