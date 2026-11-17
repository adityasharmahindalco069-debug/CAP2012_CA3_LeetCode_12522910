int subtractProductAndSum(int n) {
    int mul;
    int add;

    mul = 1;
    add = 0;
    if(!n || n == 0)
    return (0);
    while(n)
    {
        mul *= (n % 10);
        add += n % 10;
        n /= 10;
    }
    return (mul - add);
}
