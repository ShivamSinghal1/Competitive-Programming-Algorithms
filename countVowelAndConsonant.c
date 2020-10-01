
#include <stdio.h>
int main()
{
    char A[] = "vowels and consonants";
    int vowels = 0, consonants = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
            vowels++;
        else if (A[i] >= 'a' && A[i] <= 'z')
            consonants++;
    }
    printf("vowels : %d\n", vowels);
    printf("consonants : %d\n", consonants);
    return 0;
}

// output :
// vowels : 6
// consonants : 13

// linear time - O(n)
// constant Space - O(1)
