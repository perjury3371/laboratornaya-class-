#include <iostream>
#include <locale>
#include <cctype>

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
class RationalNumberClass {
    private:
        double nominator, denominator;
    public:


        //--------------------------------------------------------------------


        RationalNumberClass() {
            cout <<"����������� �� ��������� (��������� ���� � ����������)"<<endl;
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

        //--------------------------------------------------------------------
        friend ostream& operator<< (ostream &out, const RationalNumberClass &rc);
        friend istream& operator>> (istream &in, RationalNumberClass &rc);
        //--------------------------------------------------------------------

        RationalNumberClass operator * (const RationalNumberClass &rc) {
            nominator *= rc.nominator;
            denominator *= rc.denominator;
            cout <<"������������� �������� ��������� � ������ ������������ ������"<<endl;
            return *this;
        }
        RationalNumberClass operator * (const int &number) {
            nominator *= number;
            cout <<"������������� �������� ��������� � ����� ������"<<endl;
            return *this;
        }
        operator float() {
            cout <<"������������� �������� ���������� ���� � float"<<endl;
            return ((float)(nominator/denominator));
        }
        operator== (const double &number) {
            cout <<"������������� �������� ��������� � ����� ������"<<endl;
            return ( (float)(nominator/denominator) == number );
        }
        bool operator== (const RationalNumberClass &rc) {
            cout <<"������������� �������� ��������� � ������ ������������ ������"<<endl;
            return ( nominator / denominator == rc.nominator / rc.denominator );
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
    cout <<"������� ���������: " << endl;
    in >> rc.nominator;
    cout <<"������� �����������: " << endl;
    in >> rc.denominator;
    return in;
}

int main() {
    int menuPos = 0;
    int flag = 0;
    int u_nominator, u_denominator;
    setlocale( LC_ALL,"Russian" );
    RationalNumberClass *RationalNumber1 = new RationalNumberClass;
    cout <<"NOTE!!! �� ������� �������, �� ���������� �������."<< endl;
    cin >> *RationalNumber1;
    cout <<"������ ������ � ������� ������������ �� ���������\n\n\n"<< endl;
    RationalNumberClass *RationalNumber2 = new RationalNumberClass(16, 8);
    cout <<"������ ������ � ������� ������������ � ����������� (16, 8)\n\n\n"<< endl;
    RationalNumberClass *RationalNumber3 = new RationalNumberClass(*RationalNumber1);
    cout <<"������ ������ � ������� ������������ ����������� (���������� ���������� ������)\n\n\n"<< endl;
    do {
        cout
        << "1 - ������� ��������� ��1\n"
        << "2 - ������� ����������� ��1\n"
        << "3 - �������� ��1 �� ��2\n"
        << "4 - �������� ��1 �� ����� ����� (9)\n"
        << "5 - �������� ��1 � float\n"
        << "6 - �������� ��2 � ��3\n"
        << "7 - �������� ��2 � ����� ����� (2)\n"
        << "8 - �������� ��1 � ��3\n"
        << "9 - �������� ��1 � ����� ����� (2)\n"
        << "10 - ���������� ��3\n"
        << "11 - ������� ���������� � ��1\n"
        << "0 - �������� ���������\n\n\n"
        <<"NOTE!!! �� ������� �������, �� ���������� �������."
        << endl;
        cin >> menuPos;
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
                if (*RationalNumber2 == *RationalNumber3) { cout <<"��� �����"<< endl; }
                else {cout <<"��� �� �����"<< endl;}
                break;
            }
            case 7 : {
                if (*RationalNumber2 == 2) { cout <<"��� �����"<< endl; }
                else {cout <<"��� �� �����"<< endl;}
                break;
            }
            case 8 : {
                if (*RationalNumber1 == *RationalNumber3) { cout <<"��� �����"<< endl; }
                else {cout <<"��� �� �����"<< endl;}
                break;
            }
            case 9 : {
                if (*RationalNumber1 == 2) { cout <<"��� �����"<< endl; }
                else {cout <<"��� �� �����"<< endl;}
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
                cout << "�� ����� ������������ �������, ���������� �����." << endl;
                break;
            }
        }
    }  while (flag == 0);


    return 0;
}
