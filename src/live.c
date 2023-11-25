void live_print_p(u32 p[T], u32 j) {

    //rgb(255,0,0);
    rgb(0,255,0);
    for (int i = 0 ; i < j ; i++) {
        cursor_to(N+3,5 + i);
        print_symbol_switch(p[i]);
    }
    for (int i = j ; i < T ; i++) printf(" ");
}
void live_print_c(u32 c[T], u32 j) {

    rgb(0,255,0);
    for (int i = 0 ; i < j ; i++) {
        cursor_to(N+4,5 + i);
        print_symbol_switch(c[i]);
    }
    for (int i = j ; i < T ; i++) printf(" ");
}
void live_encode(u32 c[T], u32 p[T], u32 key[N][L]) {
	for (u32 i = 0 ; i < T ; i++) {
        key[0][0] = stack_exclude_apex(key);
		c[i] = ( stack_exclude_apex(key) + p[i] )%B;
		spin_key_alt(key, c[i]+1);
		spin_central_column_exclude_apex(key, c[i] + 1);
        rgb(255,255,255);
        print_key(key);
        live_print_p(p, i);
        live_print_c(c,i);
	}
}

void live_encoding_demo() {
    u32 f[N][L] = {0};
	u32 p[T];//plain
	u32 c[T];//cipher
	u32 d[T];//decode
	u32 e[T];//diff vector
	u32 hue = 155;
	randomize_len();
	randomize_key(f);
    cls();
    rgb(255,255,255);
	rgb(hue,hue,hue);
	print_key(f);
	for (u32 i = 0; i < 200; i++) {
		randomize_text(p);
		live_encode(c,p,f);
		// check_text_equality(d,p);
		// record_difference(e,p,c);
		// rgb(255,255,255);printf("f(");rgb(255,0,0);print_text(p);rgb(255,255,255);
		// printf(") = ");rgb(255,255,0);print_text(c);printf("  ");rgb(hue,hue,hue);
        // if (B == 2) print_text(e);
        // printf("\n");
	}
}