/* Example to reverse a sentence entered by user without using strings. */

#include

void Reverse();

int main()

{

    printf("Enter a sentence: ");

    Reverse();

    return 0;

}

void Reverse()

{

    char c;

    scanf("%c",&c);

    if( c != '\n')

    {

        Reverse();

        printf("%c",c);

    }

}

结果输出：

Enter a sentence: margorp emosewa

awesome program
