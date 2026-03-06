int largest_number(int a, int b, int c)
{
    int largest = a;

    if (b > largest)
        largest = b;
    if (c > largest)
        largest = c;

    return (largest);
}
