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
            inputRationalNumber();
        };
        RationalNumberClass(double u_nominator, double u_denominator) {
            cout <<"����������� � �����������"<< endl;
            setRationalNumber(u_nominator, u_denominator);
        };
        RationalNumberClass(RationalNumberClass &rc) {
            cout <<"����������� �����������"<< endl;
            nominator = rc.nominator;
            denominator = rc.denominator;
        }

        //--------------------------------------------------------------------


        void setRationalNumber(double u_nominator, double u_denominator) {
            nominator = u_nominator;
            denominator = u_denominator;
            cout <<"����������� �������� ��������� � ����������"<< endl;
        };
        void inputRationalNumber() {
            cout <<"����� ����� � ����������"<< endl;
            int u_nominator, u_denominator;
            cout <<"������� ���������"<< endl;
            cin >> u_nominator;
            cout <<"������� �����������"<< endl;
            cin >> u_denominator;
            setRationalNumber(u_nominator, u_denominator);
        }
        double getNominator() {
            cout <<"������� ���������"<< endl;
            return nominator;
        }
        double getDenominator() {
            cout <<"������� �����������"<< endl;
            return denominator;
        }


        //--------------------------------------------------------------------

        double operator * (const RationalNumberClass &rc) {
            double u_nominator = nominator, u_denominator = denominator;
            u_nominator *= rc.nominator;
            u_denominator *= rc.denominator;
            cout <<"������������� �������� ��������� � ������ ������������ ������"<<endl;
            return ((double)(u_nominator / u_denominator));
        }
        double operator * (const int &number) {
            double u_nominator = nominator, u_denominator = denominator;
            cout <<"������������� �������� ��������� � ����� ������"<<endl;
            return (u_nominator * number / denominator);
        }
        operator float() {
            cout <<"������������� �������� ���������� ���� � float"<<endl;
            return ((float)(nominator/denominator));
        }
        bool operator== (const double number) {
            cout <<"������������� �������� ��������� � ����� ������"<<endl;
            return ( (float)(nominator/denominator) == number );
        }
        bool operator== (const RationalNumberClass &rc) {
            cout <<"������������� �������� ��������� � ������ ������������ ������"<<endl;
            return ( nominator == rc.nominator && denominator == rc.denominator );
        }


        //--------------------------------------------------------------------


        ~RationalNumberClass() {
            cout<<"������ ����������"<< endl;
        }

};

int main() {
    int menuPos = 0;
    int flag = 0;
    int u_nominator, u_denominator;
    setlocale( LC_ALL,"Russian" );
    cout <<"NOTE!!! �� ������� �������, �� ���������� �������."<< endl;
    RationalNumberClass *RationalNumber1 = new RationalNumberClass;
    cout <<"������ ������ � ������� ������������ �� ���������\n\n\n"<< endl;
    RationalNumberClass *RationalNumber2 = new RationalNumberClass(16, 8);
    cout <<"������ ������ � ������� ������������ � ����������� (16, 8)\n\n\n"<< endl;
    RationalNumberClass *RationalNumber3 = RationalNumber1;
    cout <<"������ ������ � ������� ������������ ����������� (���������� ���������� ������)\n\n\n"<< endl;
    do {
        cout
        << "1 - ������� ��������� ��1\n"
        << "2 - ������� ����������� ��1\n"
        << "3 - �������� ��1 �� ��2 � �������� � float\n"
        << "4 - �������� ��1 �� ����� ����� (9) � �������� � float\n"
        << "5 - �������� ��1 � float\n"
        << "6 - �������� ��2 � ��3\n"
        << "7 - �������� ��2 � ����� ����� (2)\n"
        << "8 - �������� ��1 � ��3\n"
        << "9 - �������� ��1 � ����� ����� (2)\n"
        << "10 - ���������� ��3\n"
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
            default : {
                cout << "�� ����� ������������ �������, ���������� �����." << endl;
                break;
            }
        }
    }  while (flag == 0);


    return 0;
}
