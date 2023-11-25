void rgb(int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm",r,g,b);
}
void cls() {
    printf( "\x1b[2J");
}
void reverse_text() {
    printf("\x1b[7m");
}
void stop_reverse_text() {
    printf("\x1b[27m");
}
void hide_cursor() {
    printf("\x1b[?25l");
}
void show_cursor() {
    printf("\x1b[?25h");
}

void cursor_to(int r, int c) {
    printf("\x1b[%d;%dH",r,c);
}
void print_symbol_live(u32 i) {
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    rgb(0,arc4random_uniform(255),0 );
    //if (rev == 0) reverse_text();
    printf("%c", alph[i]);
    // if (i < 2) printf("%c", alph[i]);
    // else printf("\u2594");

    //if (rev == 0) stop_reverse_text();
}
void print_symbol(u32 i) {
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    //char alph[] = "O|23456789";
    //char alph[] = "abcdefghijklmnopqrstuvwxyz ";
   //u32 rev = arc4random_uniform(2500);
    //u32 h = arc4random_uniform(255);
    // u32 l = arc4random_uniform(255);
   // if (rev % 2 == 0 ) rgb(h,h,0); else rgb(h,h,h);
    //rgb(arc4random_uniform(255),arc4random_uniform(255),arc4random_uniform(255));
    //rgb(0,arc4random_uniform(255),0 );
    //if (rev == 0) reverse_text();
    printf("%c", alph[i]);
    // if (i < 2) printf("%c", alph[i]);
    // else printf("\u2594");

    //if (rev == 0) stop_reverse_text();
}
void print_symbol_switch(u32 i) {
    u32 h = arc4random_uniform(255);
    rgb(h,h,h);
    //rgb(0,arc4random_uniform(255),0 );
    switch (i) {
        case 0: printf("O");break;
        case 1: printf("|");break;
        case 2: printf("\u2594");break;
    }
}

void print_key(const u32 k[N][L]) {
	for (u32 i = 0; i < N; i++) {
        
		for (u32 j = 0; j < len[i]; j++) {
            //cursor_to(i+5, j + 15); 
            cursor_to(i+2, 5 + 2*len[N-1]/2 - 2*len[i]/2 + 2*j);
            //cursor_to(i+1, 5 + len[N-1]/2 - len[i]/2 + j);
            
            print_symbol_switch(k[i][j]);
            usleep(3100);
        }
        //"\u2588\u2588"); //"\u2591\u2591"
		printf("\n");
	}
    printf("\n");
}



void print_vec(u32* v, u32 l) {
	for (u32 j = 0; j < l; j++) printf("%d ", v[j]);
    printf("\n");
}
void print_text(u32 t[T]) {
	for (u32 i = 0; i < T; i++) print_symbol(t[i]);
}

	