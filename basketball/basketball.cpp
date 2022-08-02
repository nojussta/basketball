#include <iostream>
#include <fstream>

using namespace std;

struct ballers
{
    string name;
    string surname;
    int height;
    int weight;
};

void read(int& count, ballers x[6])
{
    //setlocale(LC_ALL, "Lithuanian");
    ifstream file("krepsininkai.txt");
    file >> count;
    for (int i = 0; i < count; i++)
    {
        file >> x[i].name >> x[i].surname >> x[i].height >> x[i].weight;
    }
    file.close();
}

void sort(int& kiek, ballers x[6])
{
    for (int i = 0; i < kiek; i++)
    {
        for (int j = 0; j < kiek - 1; j++)
        {
            if (x[j].height > x[j + 1].height)
            {
                ballers laik = x[j];
                x[j] = x[j + 1];
                x[j + 1] = laik;
            }
        }
    }
}
int avg(int& kiek, ballers x[6])
{

    int suma = 0;
    for (int i = 0; i < kiek; i++)
    {
        suma = suma + x[i].height;
    }
    int vid = 0;
    vid = suma / kiek;
    return vid;
}
void print(int& kiek, ballers x[6])
{
    ofstream ats("atrinkti.txt");
    for (int i = 0; i < kiek; i++)
    {
        if (x[i].height > avg(kiek, x))
        {
            ats << x[i].name << " " << x[i].surname << " " << x[i].height << " " << x[i].weight << endl;
        }
    }
}

int main()
{

    ballers x[6];
    int kiek;
    int vid = 0;
    read(kiek, x);
    sort(kiek, x);
    avg(kiek, x);
    print(kiek, x);
    cout << "Pradiniai duomenys: " << endl;
    for (int i = 0; i < kiek; i++)
    {
        cout << x[i].name << " " << x[i].surname << " " << x[i].height << " " << x[i].weight << endl;
    }
    cout << "------------------------" << endl;
    cout << "Ûgiø vidurkis yra: " << avg(kiek, x) << endl;
    cout << "------------------------" << endl;
    return 0;
}
