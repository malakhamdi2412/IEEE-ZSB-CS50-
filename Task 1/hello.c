#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    
    // لوب عشان نضمن إن المستخدم يدخل رقم بين 1 و 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // الـ Loop الرئيسي لطباعة السطور
    for (int i = 0; i < height; i++)
    {
        // لوب لطباعة المسافات عشان الهرم يروح يمين
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        
        // لوب لطباعة علامات الشباك (#)
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        
        // ننزل سطر جديد بعد ما السطر يخلص
        printf("\n");
    }
}
