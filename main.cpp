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
        };
        RationalNumberClass(const double &u_nominator, const double &u_denominator) : nominator(u_nominator), denominator(u_denominator) {
            cout <<"Конструктор с параметрами"<< endl;
        };
        RationalNumberClass(const RationalNumberClass &rc) : nominator(rc.nominator), denominator(rc.denominator) {
            cout <<"Конструктор копирования"<< endl;

        }

        //--------------------------------------------------------------------

        double getNominator() {
            return nominator;
        }
        double getDenominator() {
            return denominator;
        }

        //--------------------------------------------------------------------
        friend ostream& operator<< (ostream &out, const RationalNumberClass &rc);
        friend istream& operator>> (istream &in, RationalNumberClass &rc);
        //--------------------------------------------------------------------

        RationalNumberClass operator * (const RationalNumberClass &rc) {
            nominator *= rc.nominator;
            denominator *= rc.denominator;
            cout <<"Перегруженный оператор умножения с другим рациональным числом"<<endl;
            return *this;
        }
        RationalNumberClass operator * (const int &number) {
            nominator *= number;
            cout <<"Перегруженный оператор умножения с целым числом"<<endl;
            return *this;
        }
        operator float() {
            cout <<"Перегруженный оператор приведения типа к float"<<endl;
            return ((float)(nominator/denominator));
        }
        operator== (const double &number) {
            cout <<"Перегруженный оператор сравнения с целым числом"<<endl;
            return ( (float)(nominator/denominator) == number );
        }
        bool operator== (const RationalNumberClass &rc) {
            cout <<"Перегруженный оператор сравнения с другим рациональным числом"<<endl;
            return ( nominator / denominator == rc.nominator / rc.denominator );
        }


        //--------------------------------------------------------------------


        ~RationalNumberClass() {
            cout<<"Вызван Деструктор"<< endl;
        }

};

ostream& operator<< (ostream &out, const RationalNumberClass &rc) {
    out <<"Числитель: " << rc.nominator << "\n" << "Знаменатель: " << rc.denominator  << endl;
    return out;
}

istream& operator>>(std::istream &in, RationalNumberClass &rc) {
    cout <<"Введите числитель: " << endl;
    in >> rc.nominator;
    cout <<"Введите знаменатель: " << endl;
    in >> rc.denominator;
    return in;
}

int main() {
    int menuPos = 0;
    int flag = 0;
    int u_nominator, u_denominator;
    setlocale( LC_ALL,"Russian" );
    RationalNumberClass *RationalNumber1 = new RationalNumberClass;
    cout <<"NOTE!!! Не вводите символы, не являющиеся цифрами."<< endl;
    cin >> *RationalNumber1;
    cout <<"Создан объект с помощью конструктора по умолчанию\n\n\n"<< endl;
    RationalNumberClass *RationalNumber2 = new RationalNumberClass(16, 8);
    cout <<"Создан объект с помощью конструктора с параметрами (16, 8)\n\n\n"<< endl;
    RationalNumberClass *RationalNumber3 = new RationalNumberClass(*RationalNumber1);
    cout <<"Создан объект с помощью конструктора копирования (скопирован предыдущий объект)\n\n\n"<< endl;
    do {
        cout
        << "1 - вывести числитель РЧ1\n"
        << "2 - вывести знаменатель РЧ1\n"
        << "3 - умножить РЧ1 на РЧ2\n"
        << "4 - умножить РЧ1 на целое число (9)\n"
        << "5 - привести РЧ1 к float\n"
        << "6 - Сравнить РЧ2 и РЧ3\n"
        << "7 - Сравнить РЧ2 и целое число (2)\n"
        << "8 - сравнить РЧ1 и РЧ3\n"
        << "9 - сравнить РЧ1 и целое число (2)\n"
        << "10 - уничтожить РЧ3\n"
        << "11 - вывести информацию о РЧ1\n"
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
                cout << "Числитель: " << RationalNumber1->getNominator() << endl;
                break;
            }
            case 2 : {
                cout << "Знаменатель: " << RationalNumber1->getDenominator() << endl;
                break;
            }
            case 3 : {
                cout << (*RationalNumber1 * *RationalNumber2) << endl;
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
            case 11 : {
                cout << *RationalNumber1 << endl;
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
