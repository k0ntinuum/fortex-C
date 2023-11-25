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
void spin_key_alt(u32 k[N][L], u32 a) {
    u32 temp;
    for (u32 t = 0; t < a ; t++) {
        for (u32 i = 0; i < N; i++) {
            if (i %2 == 0 ) {
                temp = k[i][0];
                for (u32 j = 1 ; j < len[i] ; j++) k[i][j-1] = k[i][j];
                k[i][len[i]-1] = temp;
            } else {
                temp = k[i][len[i]-1];
                for (u32 j = len[i] - 1 ; j > 0  ; j--) k[i][j] = k[i][j-1];
                k[i][0] = temp;
            }
        }
    }
}

void spin_row(u32 k[N][L], u32 i) {
    u32 temp = k[i][0];
    for (u32 j = 1 ; j < len[i] ; j++) k[i][j-1] = k[i][j];
    k[i][len[i]-1] = temp;
}

u32 stack_exclude_apex(u32 key[N][L]) {
	u32 s = 0;
	for (u32 i = 1; i < N; i++) s += key[i][len[i]/2];
	return s%B;
}
u32 stack_include_apex(u32 key[N][L]) {
	u32 s = 0;
	for (u32 i = 0; i < N; i++) s += key[i][len[i]/2];
	return s%B;
}

u32 sum(u32 key[N][L]) {
	u32 s = 0;
	for (u32 i = 0; i < N; i++) s += key[i][0];
	return s;
}

void spin_central_column_exclude_apex(u32 f[N][L], u32 a) {
    u32 t[N] = {0};
    for (u32 i = 0; i < N-1; i++) t[i] = f[1 + ((i + a)%(N-1)) ][len[1 + ((i + a)%(N-1))]/2];
    for (u32 i = 0; i < N-1; i++) f[i+1][len[i+1]/2] = t[i];
}

void spin_central_column_include_apex(u32 f[N][L], u32 a) {
    u32 t[N] = {0};
    for (u32 i = 0; i < N; i++) t[i] = f[(i + a)%N][len[(i + a)%N]/2];
    for (u32 i = 0; i < N; i++) f[i][len[i]/2] = t[i];
}

void auto_spin(u32 f[N][L], u32 a) {
    for (int i = 0; i < a ; i++) {
        spin_central_column_include_apex(f,1);
        spin_key_alt(f,1);
    }
}