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

void print_symbol(u32 i) {
    switch (i) {
        case 0 : printf("O");break;
        case 1 : printf("|");break;
        case 2 : printf("2");break;
        default : printf("\u2591");break;
    }
}
// void print_symbol(u32 i) {
//     switch (i) {
//         case 0 : printf("O");break;
//         case 1 : printf("\u2588");break;
//         case 2 : printf("|");break;
//         default : printf("\u2591");break;
//     }
// }
void print_key(const u32 k[N][L]) {
	for (u32 i = 0; i < N; i++) {
		for (u32 j = 0; j < len[i]; j++) print_symbol(k[i][j]);
        //"\u2588\u2588"); //"\u2591\u2591"
		printf("\n");
	}
    printf("\n");
}
void print_cone(u32 key[N][L]) {
    key[0][0] = stack(key);
	for (u32 i = 0; i < N; i++) {
        //cursor_to(N -1 - i+5, 5 + len[N-1]/2 - len[i]/2);
        cursor_to(i+5, 15 + len[N-1]/2 - len[i]/2);
		for (u32 j = 0; j < len[i]; j++) {
            //if (i == 0 ) reverse_text();
            //if (j == len[i]/2 ) reverse_text();
            if (i == 0) printf("%s", stack(key) == 0 ? " " : "\u2588");
            else printf("%s", key[i][j] == 0 ? " " : "\u2588");
            //printf("%s", key[i][j] == 0 ? "O" : "|"); //"\u2591\u2591"\u2588
            //if (j == len[i]/2 ) stop_reverse_text();
            //if (i == 0 ) stop_reverse_text();
        }
		printf("\n");
	}
    // cursor_to()
    // printf("%s", key[i][j] == 0 ? "O" : "|");
    //printf("\n");
}


void print_vec(u32* v, u32 l) {
	for (u32 j = 0; j < l; j++) printf("%d ", v[j]);
    printf("\n");
}
void print_text(u32 t[T]) {
	for (u32 i = 0; i < T; i++) print_symbol(t[i]);
}

	