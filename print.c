void rgb(int r, int g, int b) {
    printf("\x1b[38;2;%d;%d;%dm",r,g,b);
}
void cls() {
    printf( "\x1b[2J");
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
	printf("%s", i == 0 ? "O" : "|");
}
void print_f() {
	for (u32 i = 0; i < N; i++) {
		for (u32 j = 0; j < len[i]; j++) printf("%c", f[i][j] == 0 ? 'O' : '|');
		printf("\n");
	}
    printf("\n");
}
void print_g() {
	for (u32 i = 0; i < N; i++) {
		for (u32 j = 0; j < len[i]; j++) printf("%s", g[i][j] == 0 ? "  " : "\u2588\u2588"); //"\u2591\u2591"
		printf("\n");
	}
    printf("\n");
}

void print_u32_vec(u32* v, u32 l) {
	for (u32 j = 0; j < l; j++) printf("%d ", v[j]);
    printf("\n");
}
void print_text(u32 t[T]) {
	for (u32 j = 0; j < T; j++) printf("%s", t[j] == 0 ? "O" : "|");
}

// void print_status() {
//         printf("p = ");print_text(p);printf("\n");
//         printf("c = ");print_text(c);printf("\n");
//         printf("d = ");print_text(d);printf("\n\n");
// }
// void print_f_color() {
//     u32 hue = 90;
//     u32 hue_2 = 20;
// 	for (u32 i = 0; i < 1; i++) {
//         printf("            ");
// 		for (u32 j = 0; j < 1; j++) {
//             //h[i][j] == 0 ? rgb(255,0,0) : rgb(255,255,0);
//             h[i][j] == 0 ? rgb(hue,hue,hue) : rgb(hue_2,hue_2,hue_2);
//             //printf("%s", h[i][j] == 0 ? "O " : "| ");
//             printf("%s", f[i][j] == 0 ? "O " : "\u2588\u2588");
//         }
// 		printf("\n");
// 	}
// }
	