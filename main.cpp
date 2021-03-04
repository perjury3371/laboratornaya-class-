#include <iostream>
#include <locale>
#include <cctype>
#include <cstdlib>
using namespace std;
/*
Îïèñàòü  êëàññ  â  ñîîòâåòñòâèè  ñ  èíäèâèäóàëüíûì  âàðèàíòîì  çàäàíèÿ  è  ðåàëèçîâàòü  âñå  åãî ìåòîäû.
Êàæäûé êëàññ äîëæåí ñîäåðæàòü,ïîìèìî óêàçàííûõ â âàðèàíòå ìåòîäîâ,êîíñòðóêòîð ñ ïàðàìåòðàìè,  êîíñòðóêòîð  êîïèðîâàíèÿ,
äåñòðóêòîð,  ìåòîäû  ââîäà  ñ  êëàâèàòóðû,  óñòàíîâêè  è ïîëó÷åíèÿ  çíà÷åíèé  ïîëåé,  âûâîäà  ýòèõ  çíà÷åíèé  íà  ýêðàí.
Â  êàæäîì  ìåòîäå  êëàññà,  âêëþ÷àÿ êîíñòðóêòîðû  è  äåñòðóêòîð,  ïðåäóñìîòðåòü  îòëàäî÷íóþ  ïå÷àòü  ñîîáùåíèÿ,  ñîäåðæàùåãî  èìÿ ìåòîäà.
Íàïèñàòü  ïðîãðàììó  äëÿ  òåñòèðîâàíèÿ  âñåõ  ìåòîäîâ  êëàññà,  âûáîð  ìåòîäà  äîëæåí îñóùåñòâëÿòüñÿ ñ ïîìîùüþ ìåíþ.
*/
/*
    Êëàññ  «Ðàöèîíàëüíîå  ÷èñëî»  (Ð×).
    Ïîëÿ:  ÷èñëèòåëü,  çíàìåíàòåëü.
    Ìåòîäû:  ïåðåãðóçêà îïåðàöèè  ïðèâåäåíèÿ  òèïà  ê float,
    îïåðàöèé  óìíîæåíèÿ  «*»  äâóõ  Ð×  è  Ð×  ñ  öåëûì  ÷èñëîì,
    ñðàâíåíèÿ íà ðàâåíñòâî «==» äâóõ Ð× è Ð× ñ öåëûì ÷èñëîì.
*/
void cleaning() {
    cin.clear(); 
    cin.sync();
}

 class RationalNumberClass {
    private:
        double nominator, denominator;
    public:


        //--------------------------------------------------------------------


        RationalNumberClass() {
            cout <<"Êîíñòðóêòîð ïî óìîë÷àíèþ"<<endl;
        };
        RationalNumberClass(const double &u_nominator, const double &u_denominator) : nominator(u_nominator), denominator(u_denominator) {
            cout <<"Êîíñòðóêòîð ñ ïàðàìåòðàìè"<< endl;
        };
        RationalNumberClass(const RationalNumberClass &rc) : nominator(rc.nominator), denominator(rc.denominator) {
            cout <<"Êîíñòðóêòîð êîïèðîâàíèÿ"<< endl;

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
            cout << "Óñòàíîâëåíî íîâîå çíà÷åíèå" << endl;
        }
        void setDenominator(int value) {
            denominator = value;
            cout << "Óñòàíîâëåíî íîâîå çíà÷åíèå" << endl;
        }

        //--------------------------------------------------------------------
        friend ostream& operator<< (ostream &out, const RationalNumberClass &rc);
        friend istream& operator>> (istream &in, RationalNumberClass &rc);
        //--------------------------------------------------------------------

        RationalNumberClass operator * (const RationalNumberClass &rc) {
            nominator *= rc.nominator;
            denominator *= rc.denominator;
            cout <<"Ïåðåãðóæåííûé îïåðàòîð óìíîæåíèÿ ñ äðóãèì ðàöèîíàëüíûì ÷èñëîì"<<endl;
            return *this;
        }
        RationalNumberClass operator * (const int &number) {
            nominator *= number;
            cout <<"Ïåðåãðóæåííûé îïåðàòîð óìíîæåíèÿ ñ öåëûì ÷èñëîì"<<endl;
            return *this;
        }
        operator float() {
            cout <<"Ïåðåãðóæåííûé îïåðàòîð ïðèâåäåíèÿ òèïà ê float"<<endl;
            return ((float)(nominator/denominator));
        }
        bool operator== (const int &number) {
            cout <<"Ïåðåãðóæåííûé îïåðàòîð ñðàâíåíèÿ ñ öåëûì ÷èñëîì"<<endl;
            return ( (float)(nominator/denominator) == number );
        }
        bool operator== (const RationalNumberClass &rc) {
            cout <<"Ïåðåãðóæåííûé îïåðàòîð ñðàâíåíèÿ ñ äðóãèì ðàöèîíàëüíûì ÷èñëîì"<<endl;
            return ( nominator / denominator == rc.nominator / rc.denominator );
        }


        //--------------------------------------------------------------------


        ~RationalNumberClass() {
            cout<<"Âûçâàí Äåñòðóêòîð"<< endl;
        }

};

ostream& operator<< (ostream &out, const RationalNumberClass &rc) {
    out <<"×èñëèòåëü: " << rc.nominator << "\n" << "Çíàìåíàòåëü: " << rc.denominator  << endl;
    return out;
}

istream& operator>>(std::istream &in, RationalNumberClass &rc) {
    int i = 0;
    cout <<"Ââåäèòå ÷èñëèòåëü: ";
    while (!(in >> rc.nominator) || in.get() != '\n') {
        cout << "Ðàçðåøåíû òîëüêî öèôðû!" << endl;
        cleaning();
        cout <<"Ââåäèòå ÷èñëèòåëü: ";
    }
    cout <<"Ââåäèòå çíàìåíàòåëü: ";
    while (!(in >> rc.denominator) || in.get() != '\n') {
        cout << "Ðàçðåøåíû òîëüêî öèôðû!" << endl;
        cleaning();
        cout <<"Ââåäèòå çíàìåíàòåëü: ";
    }
    return in;
}

int main() {
    int menuPos = 0;
    int flag = 0;
    int u_nominator, u_denominator;
    system("color F0");
    setlocale( LC_ALL,"Russian" );
    RationalNumberClass *RationalNumber1 = new RationalNumberClass;
    cout <<"NOTE!!! Íå ââîäèòå ñèìâîëû, íå ÿâëÿþùèåñÿ öèôðàìè."<< endl;
    cin >> *RationalNumber1;
    cout <<"Ñîçäàí îáúåêò ñ ïîìîùüþ êîíñòðóêòîðà ïî óìîë÷àíèþ\n\n"<< endl;
    RationalNumberClass *RationalNumber2 = new RationalNumberClass(16, 8);
    cout <<"Ñîçäàí îáúåêò ñ ïîìîùüþ êîíñòðóêòîðà ñ ïàðàìåòðàìè (16, 8)\n\n"<< endl;
    RationalNumberClass *RationalNumber3 = new RationalNumberClass(*RationalNumber1);
    cout <<"Ñîçäàí îáúåêò ñ ïîìîùüþ êîíñòðóêòîðà êîïèðîâàíèÿ (ñêîïèðîâàí ïðåäûäóùèé îáúåêò)\n\n"<< endl;
    do {
        cout
        << "1 - âûâåñòè ÷èñëèòåëü Ð×1\n"
        << "2 - âûâåñòè çíàìåíàòåëü Ð×1\n"
        << "3 - óñòàíîâèòü íîâîå çíà÷åíèå ÷èñëèòåëÿ äëÿ Ð×1\n"
        << "4 - óñòàíîâèòü íîâîå çíà÷åíèå çíàìåíàòåëÿ äëÿ Ð×1\n"
        << "5 - óìíîæèòü Ð×1 íà Ð×2\n"
        << "6 - óìíîæèòü Ð×1 íà öåëîå ÷èñëî (9)\n"
        << "7 - ïðèâåñòè Ð×1 ê float\n"
        << "8 - Ñðàâíèòü Ð×2 è Ð×3\n"
        << "9 - Ñðàâíèòü Ð×2 è öåëîå ÷èñëî (2)\n"
        << "10 - ñðàâíèòü Ð×1 è Ð×3\n"
        << "11 - ñðàâíèòü Ð×1 è öåëîå ÷èñëî (2)\n"
        << "12 - óíè÷òîæèòü Ð×3\n"
        << "13 - âûâåñòè èíôîðìàöèþ îá èìåþùèõñÿ Ð×\n"
        << "0 - ïîêèíóòü ïðîãðàììó\n\n\n"
        <<"NOTE!!! Íå ââîäèòå ñèìâîëû, íå ÿâëÿþùèåñÿ öèôðàìè."
        << endl;
        cout <<"Ââåäèòå ïóíêò ìåíþ: ";
        while (!(cin >> menuPos) || cin.get() != '\n') {
            cout << "Ðàçðåøåíû òîëüêî öèôðû!" << endl;
            cleaning();
            cout <<"Ââåäèòå ïóíêò ìåíþ: ";
        }
        system("CLS");
        switch (menuPos){
            case 0 : {
                exit(0);
            }
            case 1 : {
                cout << "×èñëèòåëü: " << RationalNumber1->getNominator() << endl;
                break;
            }
            case 2 : {
                cout << "Çíàìåíàòåëü: " << RationalNumber1->getDenominator() << endl;
                break;
            }
            case 3 : {
                int number;
                cout <<"Ââåäèòå çíà÷åíèå, êîòîðûå âû õîòèòå óñòàíîâèòü: ";
                while (!(cin >> number) || cin.get() != '\n') {
                    cout << "Ðàçðåøåíû òîëüêî öèôðû!" << endl;
                    cleaning();
                    cout <<"Ââåäèòå ïóíêò ìåíþ: ";
                }
                RationalNumber1->setNominator(number);
                break;
            }
            case 4 : {
                int number;
                cout <<"Ââåäèòå çíà÷åíèå, êîòîðûå âû õîòèòå óñòàíîâèòü: ";
                while (!(cin >> number) || cin.get() != '\n') {
                    cout << "Ðàçðåøåíû òîëüêî öèôðû!" << endl;
                    cleaning();
                    cout <<"Ââåäèòå ïóíêò ìåíþ: ";
                }
                RationalNumber1->setDenominator(number);
                break;
            }
            case 5 : {
                cout << (*RationalNumber1 * *RationalNumber2) << endl;
                break;
            }
            case 6 : {
                cout << (*RationalNumber1 * 9) << endl;
                break;
            }
            case 7 : {
                cout << (float)*RationalNumber1 << endl;
                break;
            }
            case 8 : {
                if (*RationalNumber2 == *RationalNumber3) { cout <<"Îíè ðàâíû"<< endl; }
                else {cout <<"Îíè íå ðàâíû"<< endl;}
                break;
            }
            case 9 : {
                if (*RationalNumber2 == 2) { cout <<"Îíè ðàâíû"<< endl; }
                else {cout <<"Îíè íå ðàâíû"<< endl;}
                break;
            }
            case 10 : {
                if (*RationalNumber1 == *RationalNumber3) { cout <<"Îíè ðàâíû"<< endl; }
                else {cout <<"Îíè íå ðàâíû"<< endl;}
                break;
            }
            case 11 : {
                if (*RationalNumber1 == 2) { cout <<"Îíè ðàâíû"<< endl; }
                else {cout <<"Îíè íå ðàâíû"<< endl;}
                break;
            }
            case 12 : {
                delete RationalNumber3;
                RationalNumber3 = 0;
                break;
            }
            case 13 : {
                if (RationalNumber1 != NULL) {
                    cout << "Ð×1: " << *RationalNumber1 << endl;
                }
                if (RationalNumber2 != NULL) {
                    cout << "Ð×2: " << *RationalNumber2 << endl;
                }
                if (RationalNumber3 != NULL) {
                    cout << "Ð×3: " << *RationalNumber3 << endl;
                }
                break;
            }
            default : {
                cout << "Âû âûáðàëè íåñóùåñòâóþùóþ êîìàíäó, ïîïðîáóéòå ñíîâà." << endl;
                break;
            }
        }
    }  while (flag == 0);


    return 0;
}


