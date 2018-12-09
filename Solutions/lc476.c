//0ms beats 100%
int findComplement(int num) {
    int mask = ~0;
    while(mask & num) mask <<= 1;
    return ~num ^ mask;
}