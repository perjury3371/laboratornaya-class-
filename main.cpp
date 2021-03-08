#include <iostream>
#include <locale>
using namespace std;
/*
�������  �����  �  ������������  �  ��������������  ���������  �������  �  �����������  ���  ��� ������.
������ ����� ������ ���������,������ ��������� � �������� �������,����������� � �����������,  �����������  �����������,
����������,  ������  �����  �  ����������,  ���������  � ���������  ��������  �����,  ������  ����  ��������  ��  �����.
�  ������  ������  ������,  ������� ������������  �  ����������,  �������������  ����������  ������  ���������,  �����������  ��� ������.
��������  ���������  ���  ������������  ����  �������  ������,  �����  ������  ������ �������������� � ������� ����.
*/
/*
    �����  �������������  �����  (��).
    ����:  ���������,  �����������.
    ������:  ���������� ��������  ����������  ����  � float,
    ��������  ���������  �*�  ����  ��  �  ��  �  �����  ������,
    ��������� �� ��������� �==� ���� �� � �� � ����� ������.
*/
void cleaning() {
    cin.clear(); // ���������� ��� ���� ������, ������ ����� ���������� "�������"
    cin.sync();//������ ������ �� �������
}

 class RationalNumberClass {
    private:
        double nominator, denominator;
    public:


        //--------------------------------------------------------------------


        RationalNumberClass() {
            nominator = 1;
            denominator = 1;
            cout <<"����������� �� ���������"<<endl;
        };
        RationalNumberClass(const double &u_nominator, const double &u_denominator) : nominator(u_nominator), denominator(u_denominator) {
            cout <<"����������� � �����������"<< endl;
        };
        RationalNumberClass(const RationalNumberClass &rc) : nominator(rc.nominator), denominator(rc.denominator) {
            cout <<"����������� �����������"<< endl;

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
            cout << "����������� ����� ��������" << endl;
        }
        void setDenominator(int value) {
            denominator = value;
            cout << "����������� ����� ��������" << endl;
        }

        //--------------------------------------------------------------------
        friend ostream& operator<< (ostream &out, const RationalNumberClass &rc);
        friend istream& operator>> (istream &in, RationalNumberClass &rc);
        //--------------------------------------------------------------------

        RationalNumberClass operator * (const RationalNumberClass &rc) {
            cout <<"������������� �������� ��������� � ������ ������������ ������"<<endl;
            return RationalNumberClass(nominator * rc.nominator, denominator * rc.denominator);
        }
        RationalNumberClass operator * (const int &number) {
            cout <<"������������� �������� ��������� � ����� ������"<<endl;
            return RationalNumberClass(nominator * number, denominator);
        }
        operator float() {
            cout <<"������������� �������� ���������� ���� � float"<<endl;
            return (float)(nominator/denominator);
        }
        bool operator== (const int &number) {
            cout <<"������������� �������� ��������� � ����� ������"<<endl;
            return (float)(nominator/denominator) == number ;
        }
        bool operator== (const RationalNumberClass &rc) {
            cout <<"������������� �������� ��������� � ������ ������������ ������"<<endl;
            return nominator / denominator == rc.nominator / rc.denominator;
        }


        //--------------------------------------------------------------------


        ~RationalNumberClass() {
            cout<<"������ ����������"<< endl;
        }

};

ostream& operator<< (ostream &out, const RationalNumberClass &rc) {
    out <<"���������: " << rc.nominator << "\n" << "�����������: " << rc.denominator  << endl;
    return out;
}

istream& operator>>(std::istream &in, RationalNumberClass &rc) {
    cout <<"������� ���������: ";
    while (!(in >> rc.nominator) || in.get() != '\n') {
        cout << "��������� ������ �����!" << endl;
        cleaning();
        cout <<"������� ���������: ";
    }
    cout <<"������� �����������: ";
    while (!(in >> rc.denominator) || in.get() != '\n') {
        cout << "��������� ������ �����!" << endl;
        cleaning();
        cout <<"������� �����������: ";
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
    cout <<"NOTE!!! �� ������� �������, �� ���������� �������."<< endl;
    cin >> *RationalNumber1;
    cout <<"������ ������ � ������� ������������ �� ���������\n\n"<< endl;
    RationalNumberClass *RationalNumber2 = new RationalNumberClass(16, 8);
    cout <<"������ ������ � ������� ������������ � ����������� (16, 8)\n\n"<< endl;
    RationalNumberClass *RationalNumber3 = new RationalNumberClass(*RationalNumber1);
    cout <<"������ ������ � ������� ������������ ����������� (���������� ���������� ������)\n\n"<< endl;
    do {
        cout
        << "1 - ������� ��������� ��1\n"
        << "2 - ������� ����������� ��1\n"
        << "3 - ���������� ����� �������� ��������� ��� ��1\n"
        << "4 - ���������� ����� �������� ����������� ��� ��1\n"
        << "5 - �������� ��1 �� ��2 � ������� ���������\n"
        << "6 - �������� ��1 �� ����� ����� � ������� ��������� (9)\n"
        << "7 - �������� ��1 � float\n"
        << "8 - �������� ��2 � ��3\n"
        << "9 - �������� ��2 � ����� ����� (2)\n"
        << "10 - �������� ��1 � ��3\n"
        << "11 - �������� ��1 � ����� ����� (2)\n"
        << "12 - ���������� ��3\n"
        << "13 - ������� ���������� �� ��������� ��\n"
        << "0 - �������� ���������\n\n\n"
        <<"NOTE!!! �� ������� �������, �� ���������� �������."
        << endl;
        cout <<"������� ����� ����: ";
        while (!(cin >> menuPos) || cin.get() != '\n') {
            cout << "��������� ������ �����!" << endl;
            cleaning();
            cout <<"������� ����� ����: ";
        }
        system("CLS");
        switch (menuPos){
            case 0 : {
                exit(0);
            }
            case 1 : {
                cout << "���������: " << RationalNumber1->getNominator() << endl;
                break;
            }
            case 2 : {
                cout << "�����������: " << RationalNumber1->getDenominator() << endl;
                break;
            }
            case 3 : {
                int number;
                cout <<"������� ��������, ������� �� ������ ����������: ";
                while (!(cin >> number) || cin.get() != '\n') {
                    cout << "��������� ������ �����!" << endl;
                    cleaning();
                    cout <<"������� ����� ����: ";
                }
                RationalNumber1->setNominator(number);
                break;
            }
            case 4 : {
                int number;
                cout <<"������� ��������, ������� �� ������ ����������: ";
                while (!(cin >> number) || cin.get() != '\n') {
                    cout << "��������� ������ �����!" << endl;
                    cleaning();
                    cout <<"������� ����� ����: ";
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
                if (*RationalNumber2 == *RationalNumber3) { cout <<"��� �����"<< endl; }
                else {cout <<"��� �� �����"<< endl;}
                break;
            }
            case 9 : {
                if (*RationalNumber2 == 2) { cout <<"��� �����"<< endl; }
                else {cout <<"��� �� �����"<< endl;}
                break;
            }
            case 10 : {
                if (*RationalNumber1 == *RationalNumber3) { cout <<"��� �����"<< endl; }
                else {cout <<"��� �� �����"<< endl;}
                break;
            }
            case 11 : {
                if (*RationalNumber1 == 2) { cout <<"��� �����"<< endl; }
                else {cout <<"��� �� �����"<< endl;}
                break;
            }
            case 12 : {
                delete RationalNumber3;
                RationalNumber3 = 0;
                break;
            }
            case 13 : {
                if (RationalNumber1 != NULL) {
                    cout << "��1: " << *RationalNumber1 << endl;
                }
                if (RationalNumber2 != NULL) {
                    cout << "��2: " << *RationalNumber2 << endl;
                }
                if (RationalNumber3 != NULL) {
                    cout << "��3: " << *RationalNumber3 << endl;
                }
                if (RationalNumber4 != NULL) {
                    cout << "��4: " << *RationalNumber4 << endl;
                }
                break;
            }
            default : {
                cout << "�� ������� �������������� �������, ���������� �����." << endl;
                break;
            }
        }
    }  while (flag == 0);


    return 0;
}


