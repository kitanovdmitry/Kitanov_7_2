/*
Автор: Китанов Дмитрий
Группа: СБС-001-О-01, подгруппа 2
Задача №7, вариант 2
Цель: Вычисление синуса суммой ряда с помощью классов и объектов
*/

#include <iostream>
#include <climits>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

class SinCalc
{
private:
    int row_border;
    long double factorial(int number)
{
    if (number == 0)
    {
        return 1;
    }
    else
        {
            return number * factorial(number - 1);
        }
};

public:
    static int stat_row_border;
    long double x;
    long double calc()
    {
        SinCalc InternObj;
        InternObj.row_border = 200;
        long double sin_x = 0.0;
        bool angle_180_degrees = (x == M_PI);


        for (int n = 0; n < InternObj.row_border; n++)
        {
            if (angle_180_degrees) //because when calculated by the formula, the result will be very close to zero: sin(x) = 1.227e-16//
            {
                sin_x = 0.0;
                break;
            }

            sin_x = sin_x + (pow(-1, n) * pow(x, 2*n+1)) / factorial(2*n+1);
        }
        return sin_x;
    }

    long double stat_calc()
    {
        SinCalc::stat_row_border = 200;
        long double sin_x = 0.0;
        bool angle_180_degrees = (x == M_PI);


        for (int n = 0; n < stat_row_border; n++)
        {
            if (angle_180_degrees) //because when calculated by the formula, the result will be very close to zero: sin(x) = 1.227e-16//
            {
                sin_x = 0.0;
                break;
            }

            sin_x = sin_x + (pow(-1, n) * pow(x, 2*n+1)) / factorial(2*n+1);
        }
        return sin_x;
    }
};

int SinCalc::stat_row_border;

int main()
{
    long double x_ang = 0.0;
    bool typeFail;

    do
    {
    cout << "Enter argument 'x'(type long double, x in degrees) for sin(x)\n";
    cin >> x_ang;

    typeFail = cin.fail();
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    }
    while (typeFail);

    cout << "x in degrees = " << x_ang << "\n";
    x_ang = x_ang * M_PI / 180.0;
    cout << "x in radians = " << x_ang << "\n";

    int k = x_ang / (2*M_PI);
    x_ang = x_ang - 2*M_PI * k; // sin(x + 2*pi*k) = sin(x)//

    SinCalc::stat_row_border = 200;
    SinCalc WorkObj;
    WorkObj.x = x_ang;

    cout.precision(15);
    cout << "Sin(x)(no static) = " << WorkObj.calc() << "\n";
    cout << "Sin(x)(with static) = " << WorkObj.stat_calc() << "\n";

    return 0;
}
