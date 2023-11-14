void encoding_demo(){
    u32 f[N][L] = {0};
	u32 g[N][L] = {0};
	u32 p[T];//plain
	u32 c[T];//cipher
	u32 d[T];//decode
	u32 e[T];//diff vector
	u32 hue = 155;
	randomize_len();
	randomize_key(f);
    cls();
    rgb(255,255,255);
    printf("f = \n\n");
	rgb(hue,hue,hue);
	print_key(f);
	for (u32 i = 0; i < 27; i++) {
		randomize_text(p);
		//copy_key(g,f);
		fortex_encrypt(c,p,f);
        fortex_decrypt(d,c,f);
		//copy_key(g,f);
		//decode(d,c,g);
		check_text_equality(d,p);
		record_difference(e,p,c);
		rgb(255,255,255);printf("f(");rgb(255,0,0);print_text(p);rgb(255,255,255);
		printf(") = ");rgb(255,255,0);print_text(c);printf("  ");rgb(hue,hue,hue);
		//print_text(e);
        printf("\n");
	}
}

        