#include <iostream>
#include <locale>
#include <cctype>

using namespace std;
/*
Описать  класс  в  соответствии  с  индивидуальным  вариантом  задания  и  реализовать  все  его методы.
Каждый класс должен содержать,помимо указанных в варианте методов,конструктор с параметрами,  конструктор  копирования,
деструктор,  методы  ввода  с  клавиатуры,  установки  и получения  значений  полей,  вывода  этих  значений  на  экран.
В  каждом  методе  класса,  включая конструкторы  и  деструктор,  предусмотреть  отладочную  печать  сообщения,  содержащего  имя метода.
Написать  программу  для  тестирования  всех  методов  класса,  выбор  метода  должен осуществляться с помощью меню.
*/
/*
    Класс  «Рациональное  число»  (РЧ).
    Поля:  числитель,  знаменатель.
    Методы:  перегрузка операции  приведения  типа  к float,
    операций  умножения  «*»  двух  РЧ  и  РЧ  с  целым  числом,
    сравнения на равенство «==» двух РЧ и РЧ с целым числом.
*/
class RationalNumberClass {
    private:
        double nominator, denominator;
    public:


        //--------------------------------------------------------------------


        RationalNumberClass() {
            cout <<"Конструктор по умолчанию (используя ввод с клавиатуры)"<<endl;
            inputRationalNumber();
        };
        RationalNumberClass(double u_nominator, double u_denominator) {
            cout <<"Конструктор с параметрами"<< endl;
            setRationalNumber(u_nominator, u_denominator);
        };
        RationalNumberClass(RationalNumberClass &rc) {
            cout <<"Конструктор копирования"<< endl;
            nominator = rc.nominator;
            denominator = rc.denominator;
        }

        //--------------------------------------------------------------------


        void setRationalNumber(double u_nominator, double u_denominator) {
            nominator = u_nominator;
            denominator = u_denominator;
            cout <<"Установлены значения числителя и знаменталя"<< endl;
        };
        void inputRationalNumber() {
            cout <<"Метод ввода с клавиатуры"<< endl;
            int u_nominator, u_denominator;
            cout <<"Введите числитель"<< endl;
            cin >> u_nominator;
            cout <<"Введите знаменатель"<< endl;
            cin >> u_denominator;
            setRationalNumber(u_nominator, u_denominator);
        }
        double getNominator() {
            cout <<"Получен числитель"<< endl;
            return nominator;
        }
        double getDenominator() {
            cout <<"Получен знаменатель"<< endl;
            return denominator;
        }


        //--------------------------------------------------------------------

        double operator * (const RationalNumberClass &rc) {
            double u_nominator = nominator, u_denominator = denominator;
            u_nominator *= rc.nominator;
            u_denominator *= rc.denominator;
            cout <<"Перегруженный оператор умножения с другим рациональным числом"<<endl;
            return ((double)(u_nominator / u_denominator));
        }
        double operator * (const int &number) {
            double u_nominator = nominator, u_denominator = denominator;
            cout <<"Перегруженный оператор умножения с целым числом"<<endl;
            return (u_nominator * number / denominator);
        }
        operator float() {
            cout <<"Перегруженный оператор приведения типа к float"<<endl;
            return ((float)(nominator/denominator));
        }
        bool operator== (const double number) {
            cout <<"Перегруженный оператор сравнения с целым числом"<<endl;
            return ( (float)(nominator/denominator) == number );
        }
        bool operator== (const RationalNumberClass &rc) {
            cout <<"Перегруженный оператор сравнения с другим рациональным числом"<<endl;
            return ( nominator == rc.nominator && denominator == rc.denominator );
        }


        //--------------------------------------------------------------------


        ~RationalNumberClass() {
            cout<<"Вызван Деструктор"<< endl;
        }

};

int main() {
    int menuPos = 0;
    int flag = 0;
    int u_nominator, u_denominator;
    setlocale( LC_ALL,"Russian" );
    cout <<"NOTE!!! Не вводите символы, не являющиеся цифрами."<< endl;
    RationalNumberClass *RationalNumber1 = new RationalNumberClass;
    cout <<"Создан объект с помощью конструктора по умолчанию\n\n\n"<< endl;
    RationalNumberClass *RationalNumber2 = new RationalNumberClass(16, 8);
    cout <<"Создан объект с помощью конструктора с параметрами (16, 8)\n\n\n"<< endl;
    RationalNumberClass *RationalNumber3 = RationalNumber1;
    cout <<"Создан объект с помощью конструктора копирования (скопирован предыдущий объект)\n\n\n"<< endl;
    do {
        cout
        << "1 - вывести числитель РЧ1\n"
        << "2 - вывести знаменатель РЧ1\n"
        << "3 - умножить РЧ1 на РЧ2 и привести к float\n"
        << "4 - умножить РЧ1 на целое число (9) и привести к float\n"
        << "5 - привести РЧ1 к float\n"
        << "6 - Сравнить РЧ2 и РЧ3\n"
        << "7 - Сравнить РЧ2 и целое число (2)\n"
        << "8 - сравнить РЧ1 и РЧ3\n"
        << "9 - сравнить РЧ1 и целое число (2)\n"
        << "10 - уничтожить РЧ3\n"
        << "0 - покинуть программу\n\n\n"
        <<"NOTE!!! Не вводите символы, не являющиеся цифрами."
        << endl;
        cin >> menuPos;
        system("CLS");
        switch (menuPos){
            case 0 : {
                exit(0);
            }
            case 1 : {
                cout << RationalNumber1->getNominator() << endl;
                break;
            }
            case 2 : {
                cout << RationalNumber1->getDenominator() << endl;
                break;
            }
            case 3 : {
                cout << (float)(*RationalNumber1 * *RationalNumber2) << endl;
                break;
            }
            case 4 : {
                cout << (*RationalNumber1 * 9) << endl;
                break;
            }
            case 5 : {
                cout << (float)*RationalNumber1 << endl;
                break;
            }
            case 6 : {
                if (*RationalNumber2 == *RationalNumber3) { cout <<"Они равны"<< endl; }
                else {cout <<"Они не равны"<< endl;}
                break;
            }
            case 7 : {
                if (*RationalNumber2 == 2) { cout <<"Они равны"<< endl; }
                else {cout <<"Они не равны"<< endl;}
                break;
            }
            case 8 : {
                if (*RationalNumber1 == *RationalNumber3) { cout <<"Они равны"<< endl; }
                else {cout <<"Они не равны"<< endl;}
                break;
            }
            case 9 : {
                if (*RationalNumber1 == 2) { cout <<"Они равны"<< endl; }
                else {cout <<"Они не равны"<< endl;}
                break;
            }
            case 10 : {
                delete RationalNumber3;
                break;
            }
            default : {
                cout << "Вы ввели неправильную команду, попробуйте снова." << endl;
                break;
            }
        }
    }  while (flag == 0);


    return 0;
}
