
// void encrypt_demo() {
//     u32 h = 200;
//     u32 eh = 100;
//     randomize_key(F);
//     copy_key(f,F);
//     printf("\n\n\n\n");
// 	print_f(f);
//     printf("\n\n");
//     for (int i = 0; i < 10; i++) {
//         randomize_p();
//         copy_text(check_p,p);
//         rgb(255,255,255);
//         printf("f( ");
//         rgb(h,0,0);
//         print_text(p);
//         rgb(255,255,255);
//         printf(" ) = ");
//         _encrypt();
//         rgb(h,h,0);
//         print_text(c);
//         update_e();
//         printf("   ");
//         rgb(eh,eh,eh);
//         print_text(e);
//         _decrypt();
//         check_decryption();
//         printf("\n");
//     }
// }


void demo() {
    u32 f[N][L] = {0};
    cls();
    hide_cursor();
    randomize_len();
    randomize_key(f);
    printf("\n\n\n\n");
    for (u32 i = 0; i < 1000000 ; i++) {
        //cursor_to(2,0);
        f[0][0] = stack_include_apex(f);
        print_key(f);
        //print_cone(f);
        //spin_key(f,1);
        spin_key_alt(f,1);
        spin_central_column_exclude_apex(f,1);
        //for (u32 a = 0; a < stack(f) + 1; a++ ) spin_row(f,i%N);
        //for (u32 a = 0; a < stack(f) + 1; a++ ) spin_row(f,i%N);
        //usleep(200000);
    }
    show_cursor();
	
}