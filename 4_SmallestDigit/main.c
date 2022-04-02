#include "smallest_digit.h"
#include "stdio.h"

int main()
{
    int count = 0;
    scanf("%d", &count);

    for (size_t i = 0; i < count; i++)
    {
        int InputNumber;
        scanf("%d", &InputNumber);

        int out = FindSmallest(InputNumber);
        printf("%d\n", out);
    }

    return 0;
}
