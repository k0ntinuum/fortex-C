void _encrypt() {
    for (u32 i = 0 ; i < N ; i++) {
        copy_key(f,F);
        auto_spin(f,i);
        encode();
        copy_text(p,c);
    }
}

void _decrypt() {
    for (u32 i = 0 ; i < N ; i++) {
        copy_key(f,F);
        auto_spin(f, N - 1 - i);
        decode();
        copy_text(c,d);
    }
}