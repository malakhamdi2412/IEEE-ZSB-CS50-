#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;

    // لوب عشان نضمن إن الرقم اللي يدخله المستخدم موجب أو صفر
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int coins = 0;

    // نحسب كام عملة من فئة 25 سنت
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }

    // نحسب كام عملة من فئة 10 سنتات
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }

    // نحسب كام عملة من فئة 5 سنتات
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }

    // نحسب كام عملة من فئة 1 سنت
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }

    // نطبع إجمالي عدد العملات في الآخر
    printf("%i\n", coins);
}

