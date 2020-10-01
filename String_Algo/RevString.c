#include <stdio.h>
int main()
{
    char A[] = "python";
    int i, j;
    char temp;
    for (i = 0, j = 5; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    printf("%s", A);
    return 0;
}

// output : nohtyp
// linear time - O(n)
// Constant Space - O(1)
