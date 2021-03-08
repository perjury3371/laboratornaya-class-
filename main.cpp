#include <iostream>
#include <locale>
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
void cleaning() {
    cin.clear(); // сбрасывает все биты потока, тоесть поток становится "хорошим"
    cin.sync();//Удалим данные из буффера
}

 class RationalNumberClass {
    private:
        double nominator, denominator;
    public:


        //--------------------------------------------------------------------


        RationalNumberClass() {
            nominator = 1;
            denominator = 1;
            cout <<"Конструктор по умолчанию"<<endl;
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
        void setNominator(int value) {
            nominator = value;
            cout << "Установлено новое значение" << endl;
        }
        void setDenominator(int value) {
            denominator = value;
            cout << "Установлено новое значение" << endl;
        }

        //--------------------------------------------------------------------
        friend ostream& operator<< (ostream &out, const RationalNumberClass &rc);
        friend istream& operator>> (istream &in, RationalNumberClass &rc);
        //--------------------------------------------------------------------

        RationalNumberClass operator * (const RationalNumberClass &rc) {
            cout <<"Перегруженный оператор умножения с другим рациональным числом"<<endl;
            return RationalNumberClass(nominator * rc.nominator, denominator * rc.denominator);
        }
        RationalNumberClass operator * (const int &number) {
            cout <<"Перегруженный оператор умножения с целым числом"<<endl;
            return RationalNumberClass(nominator * number, denominator);
        }
        operator float() {
            cout <<"Перегруженный оператор приведения типа к float"<<endl;
            return (float)(nominator/denominator);
        }
        bool operator== (const int &number) {
            cout <<"Перегруженный оператор сравнения с целым числом"<<endl;
            return (float)(nominator/denominator) == number ;
        }
        bool operator== (const RationalNumberClass &rc) {
            cout <<"Перегруженный оператор сравнения с другим рациональным числом"<<endl;
            return nominator / denominator == rc.nominator / rc.denominator;
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
    cout <<"Введите числитель: ";
    while (!(in >> rc.nominator) || in.get() != '\n') {
        cout << "Разрешены только цифры!" << endl;
        cleaning();
        cout <<"Введите числитель: ";
    }
    cout <<"Введите знаменатель: ";
    while (!(in >> rc.denominator) || in.get() != '\n') {
        cout << "Разрешены только цифры!" << endl;
        cleaning();
        cout <<"Введите знаменатель: ";
    }
    return in;
}

int main() {
    int menuPos = 0;
    int flag = 0;
    system("color F0");
    setlocale( LC_ALL,"Russian" );
    RationalNumberClass *RationalNumber4 = new RationalNumberClass;
    RationalNumberClass *RationalNumber1 = new RationalNumberClass;
    cout <<"NOTE!!! Не вводите символы, не являющиеся цифрами."<< endl;
    cin >> *RationalNumber1;
    cout <<"Создан объект с помощью конструктора по умолчанию\n\n"<< endl;
    RationalNumberClass *RationalNumber2 = new RationalNumberClass(16, 8);
    cout <<"Создан объект с помощью конструктора с параметрами (16, 8)\n\n"<< endl;
    RationalNumberClass *RationalNumber3 = new RationalNumberClass(*RationalNumber1);
    cout <<"Создан объект с помощью конструктора копирования (скопирован предыдущий объект)\n\n"<< endl;
    do {
        cout
        << "1 - вывести числитель РЧ1\n"
        << "2 - вывести знаменатель РЧ1\n"
        << "3 - установить новое значение числителя для РЧ1\n"
        << "4 - установить новое значение знаменателя для РЧ1\n"
        << "5 - умножить РЧ1 на РЧ2 и вывести результат\n"
        << "6 - умножить РЧ1 на целое число и вывести результат (9)\n"
        << "7 - привести РЧ1 к float\n"
        << "8 - Сравнить РЧ2 и РЧ3\n"
        << "9 - Сравнить РЧ2 и целое число (2)\n"
        << "10 - сравнить РЧ1 и РЧ3\n"
        << "11 - сравнить РЧ1 и целое число (2)\n"
        << "12 - уничтожить РЧ3\n"
        << "13 - вывести информацию об имеющихся РЧ\n"
        << "0 - покинуть программу\n\n\n"
        <<"NOTE!!! Не вводите символы, не являющиеся цифрами."
        << endl;
        cout <<"Введите пункт меню: ";
        while (!(cin >> menuPos) || cin.get() != '\n') {
            cout << "Разрешены только цифры!" << endl;
            cleaning();
            cout <<"Введите пункт меню: ";
        }
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
                int number;
                cout <<"Введите значение, которые вы хотите установить: ";
                while (!(cin >> number) || cin.get() != '\n') {
                    cout << "Разрешены только цифры!" << endl;
                    cleaning();
                    cout <<"Введите пункт меню: ";
                }
                RationalNumber1->setNominator(number);
                break;
            }
            case 4 : {
                int number;
                cout <<"Введите значение, которые вы хотите установить: ";
                while (!(cin >> number) || cin.get() != '\n') {
                    cout << "Разрешены только цифры!" << endl;
                    cleaning();
                    cout <<"Введите пункт меню: ";
                }
                RationalNumber1->setDenominator(number);
                break;
            }
            case 5 : {
                *RationalNumber4 = *RationalNumber1 * *RationalNumber2;
                cout << *RationalNumber4 << endl;
                break;
            }
            case 6 : {
                *RationalNumber4 = *RationalNumber1 * 9;
                cout << *RationalNumber4 << endl;
                break;
            }
            case 7 : {
                cout << (float)*RationalNumber1 << endl;
                break;
            }
            case 8 : {
                if (*RationalNumber2 == *RationalNumber3) { cout <<"Они равны"<< endl; }
                else {cout <<"Они не равны"<< endl;}
                break;
            }
            case 9 : {
                if (*RationalNumber2 == 2) { cout <<"Они равны"<< endl; }
                else {cout <<"Они не равны"<< endl;}
                break;
            }
            case 10 : {
                if (*RationalNumber1 == *RationalNumber3) { cout <<"Они равны"<< endl; }
                else {cout <<"Они не равны"<< endl;}
                break;
            }
            case 11 : {
                if (*RationalNumber1 == 2) { cout <<"Они равны"<< endl; }
                else {cout <<"Они не равны"<< endl;}
                break;
            }
            case 12 : {
                delete RationalNumber3;
                RationalNumber3 = 0;
                break;
            }
            case 13 : {
                if (RationalNumber1 != NULL) {
                    cout << "РЧ1: " << *RationalNumber1 << endl;
                }
                if (RationalNumber2 != NULL) {
                    cout << "РЧ2: " << *RationalNumber2 << endl;
                }
                if (RationalNumber3 != NULL) {
                    cout << "РЧ3: " << *RationalNumber3 << endl;
                }
                if (RationalNumber4 != NULL) {
                    cout << "РЧ4: " << *RationalNumber4 << endl;
                }
                break;
            }
            default : {
                cout << "Вы выбрали несуществующую команду, попробуйте снова." << endl;
                break;
            }
        }
    }  while (flag == 0);


    return 0;
}


