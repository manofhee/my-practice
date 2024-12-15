void* my_memcpy(void* dst, const void* src, size_t n) {
    unsigned char* d = (unsigned char*)dst;
    const unsigned char* s = (const unsigned char*)src;
    while (n>0) {
        *d++ = *s++;
        n--;
    }
    return dst;
}