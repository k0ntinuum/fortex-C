void copy_key(u32 d[N][L],u32 s[N][L]) {
    for (u32 i = 0; i < N; i++) for (u32 j = 0; j < len[i]; j++) d[i][j] = s[i][j];
}
void encode(u32 c[T], u32 p[T], u32 key[N][L]) {
	for (u32 i = 0 ; i < T ; i++) {
		c[i] = ( stack(key) + p[i] )%B;
		spin_key(key, c[i]+1);
	}
}
void decode(u32 d[T],  u32 c[T], u32 key[N][L]) {
	for (u32 i = 0 ; i < T ; i++) {
		d[i] = (B*N + c[i] - stack(key))%B;
		spin_key(key, c[i]+1);
	}
}
void reverse(u32 t[T]) {
    u32 temp[T];
    for (u32 i = 0; i < T; i++) temp[i] = t[i];
    for (u32 i = 0; i < T; i++) t[i] = temp[T - 1 - i];
}

void fortex_encrypt(u32 c[T], u32 p[T], u32 k[N][L]) {
	u32 f[N][L] = {0};
	u32 u[T] = {0};
	u32 v[T] = {0};
	copy_text(v,p);
	for (u32 r = 0 ; r < N ; r++) {
		copy_key(f,k);
		spin_key( f , r);
		copy_text(u,v);
		encode(v,u,f);
		reverse(v);
	}
	copy_text(c,v);
}
void fortex_decrypt(u32 d[T], u32 c[T], u32 k[N][L]) {
	u32 f[N][L] = {0};
	u32 u[T] = {0};
	u32 v[T] = {0};
	copy_text(v,c);
	for (u32 r = 0 ; r < N ; r++) {
		copy_key(f,k);
		spin_key(f, N - 1 - r);
		copy_text(u,v);
		reverse(u);
		decode(v,u,f);	
	}
	copy_text(d,v);
}


