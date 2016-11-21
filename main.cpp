#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <conio.h>
using namespace std;
void szansalos(int tab[])
{
    for(int i =0;i<7;i++)
    {
        tab[i]=rand()%10;
    }
}
void wypisz_szansa(int tab[])
{
    for(int i =0;i<7;i++)
    {
        cout << tab[i]<<setw(4);
    }
    cout << "\n";
}
int sprawdzanie_szansa(int tab1[], int tab2[])
{
    int licznik=0;
    for(int i=6;i>=6;i--)
    {
        if(tab1[i]==tab2[i])
            licznik++;
        else
            break;
    }
    return licznik;
}
void losuj6(int tab[])
{
    for(int i =0;i<6;i++)
    {
        tab[i]=0;
    }
    for(int i =0;i<6;i++)
    {
        tab[i]=rand()%49 +1;
        for(int j=0;j<6;j++)
        {
            if(j!=i)
            {
                if(tab[i]==tab[j])
                    i--;
            }
        }
    }
}
void wypisz(int tab[])
{
    for(int i =0;i<6;i++)
    {
        cout << tab[i]<<" ";
    }
    cout << "\n";
}
int sprawdzanie(int tab1[], int tab2[])
{
    int licznik=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(tab1[i]==tab2[j])
                licznik++;
        }
    }
    return licznik;
}
void wypelnij0(int tab[])
{
    for(int i=0;i<6;i++)
        tab[i]=0;
}
int main()
{
    srand(time(NULL));
    int wybor1;
    do
    {
        system("cls");
        cout<<"Witaj w swiecie Lotto!\n\nWybirz opcje.\n1.Lotto(zwykle/z plusem)\n2.Super szansa\n0.Wyjscie.\nOpcja:";
        cin>>wybor1;
        do
        {
            if(wybor1!=1 and wybor1!=2 and wybor1!=0)
            {
                system("cls");
                cout<<"Podano zly numer!\nWybirz opcje.\n1.Lotto(zwykle/z plusem)\n2.Super szansa\n0.Wyjscie.\nOpcja:";
                cin>>wybor1;
            }
        }
        while(wybor1!=1 and wybor1!=2 and wybor1!=0);
        if(wybor1==1)
        {
            int urzytkownik[6];
            int losowe[6];
            int intlosowan;
            system("cls");
            cout<<"1.Wybierz numery.\n2.\"Chybil trafil\"(wybrane przez komputer).\nOpcja:";
            int wybor2;
            cin>>wybor2;
            do
            {
                if(wybor2!=1 and wybor2!=2)
                {
                    system("cls");
                    cout<<"Podano zly numer!\n1.Wybierz numery.\n2.\"Chybil trafil\"(wybrane przez komputer).\nOpcja:";
                    cin>>wybor2;
                }
            }
            while(wybor2!=1 and wybor2!=2);
            if(wybor2==1)
            {
                char odp;
                do
                {
                    system("cls");
                    wypelnij0(urzytkownik);
                    for(int i=0;i<6;i++)
                    {
                        cout<<"Podaj liczbe ("<<i+1<<") :";
                        cin>>urzytkownik[i];
                        if(urzytkownik[i]>49 or urzytkownik[i]<1)
                        {
                            cout<<"Podano liczbe z poza zakresu!\n";
                            i--;
                        }
                        for(int j=0;j<6;j++)
                        {
                            if(j!=i)
                            {
                                if(urzytkownik[i]==urzytkownik[j])
                                {
                                    cout<<"Podana liczba juz zostala raz urzyta!\n";
                                    i--;
                                    break;
                                }
                            }
                        }
                    }
                    system("cls");
                    cout<<"Podano liczby: ";
                    wypisz(urzytkownik);
                    cout<<"\nCzy chcesz je zmienic?[T/N]";
                    cin>>odp;
                }
                while(odp=='T' or odp=='t');
            }
            if(wybor2==2)
            {
                system("cls");
                losuj6(urzytkownik);
            }
            system("cls");
            cout<<"Twoje liczby: ";
            wypisz(urzytkownik);
            do
            {

                cout<<"Podaj ilosc losowan (Max. 5): ";
                cin>>intlosowan;
                if(intlosowan>5 or intlosowan<1)
                {
                    cout << "Zla liczba losowan!";
                }
            }
            while(intlosowan>5 or intlosowan<1);
            char odpplus;

            do
            {

                cout<<"Losowanie z plusem? [T/N]\n";
                cin>>odpplus;
                if(odpplus!='T' and odpplus!='t' and
                odpplus!='N' and odpplus!='n')
                {
                        system("cls");
                        cout<<"Zla odpowiedz!\n";
                }
            }
            while(odpplus!='T' and odpplus!='t' and
                odpplus!='N' and odpplus!='n');
            if(odpplus=='t' or odpplus=='T')
            {
                system("cls");
                cout<<"Twoje liczby: ";
                wypisz(urzytkownik);
                int zplusem[6];
                for(int i=0;i<intlosowan;i++)
                {
                    losuj6(losowe);
                    losuj6(zplusem);
                    cout<<"\nLosowanie standardowe: ";
                    wypisz(losowe);
                    cout <<"Trafiles "<< sprawdzanie(urzytkownik, losowe);
                    if(sprawdzanie(urzytkownik, losowe)==0 or sprawdzanie(urzytkownik, losowe)==5 or sprawdzanie(urzytkownik, losowe)==6)
                        cout <<" liczb!";
                    else
                        cout<<" liczby!";
                    cout<<"\nLosownie Plus: ";
                    wypisz(zplusem);
                    cout <<"Trafiles "<< sprawdzanie(urzytkownik, zplusem);
                    if(sprawdzanie(urzytkownik, zplusem)==0 or sprawdzanie(urzytkownik, zplusem)==5 or sprawdzanie(urzytkownik, zplusem)==6)
                        cout <<" liczb!";
                    else if(sprawdzanie(urzytkownik, zplusem)==1)
                        cout<<" liczbe!";
                    else
                        cout<<" liczby!";

                }
                cout<<"\nPowrot do menu.";
                getch();
            }
            else
            {
                system("cls");
                cout<<"Twoje liczby: ";
                wypisz(urzytkownik);
                for(int i=0;i<intlosowan;i++)
                {
                    losuj6(losowe);
                    cout<<"\nLiczby wylosowane: ";
                    wypisz(losowe);
                    cout <<"Trafiles "<< sprawdzanie(urzytkownik, losowe);
                    if(sprawdzanie(urzytkownik, losowe)==0 or sprawdzanie(urzytkownik, losowe)==5 or sprawdzanie(urzytkownik, losowe)==6)
                        cout <<" liczb!";
                    else if(sprawdzanie(urzytkownik, losowe)==1)
                        cout<<" liczbe!";
                    else
                        cout<<" liczby!";
                }
                cout<<"\nPowrot do menu.";
                getch();
            }
        }
        if(wybor1==2)
        {
            system("cls");
            int szansaurz[7];
            int szansarand[7];
            szansalos(szansarand);
            szansalos(szansaurz);
            cout<<"Twoje liczby: "<<setw(5);
            wypisz_szansa(szansaurz);
            cout<<"Liczby komputera: ";
            wypisz_szansa(szansarand);
            if(sprawdzanie_szansa(szansarand, szansaurz)==0)
                cout<<"Nie wygrales nic.\n";
            if(sprawdzanie_szansa(szansarand, szansaurz)==1)
                cout<<"Wygrales 2 zl!.\n";
            if(sprawdzanie_szansa(szansarand, szansaurz)==2)
                cout<<"Wygrales 10 zl!\n";
            if(sprawdzanie_szansa(szansarand, szansaurz)==3)
                cout<<"Wygrales 100 zl!\n";
            if(sprawdzanie_szansa(szansarand, szansaurz)==4)
                cout<<"Wygrales 1 000 zl!\n";
            if(sprawdzanie_szansa(szansarand, szansaurz)==5)
                cout<<"Wygrales 10 000 zl!\n";
            if(sprawdzanie_szansa(szansarand, szansaurz)==6)
                cout<<"Wygrales 100 000 zl!\n";
            if(sprawdzanie_szansa(szansarand, szansaurz)==7)
                cout<<"Wygrales 2 000 000 zl!\n";
            cout<<"Powrot do menu.";
            getch();
        }
    }
    while(wybor1!=0);
    return 0;
}
