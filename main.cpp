
#include <iostream>
#include <iomanip>
using namespace std;

const double CIJENA_ULAZNICE = 5.0;
const int PRAG_POPUSTA = 5;
const double STOPA_POPUSTA = 0.10;

int ukupnoUlaznica = 0;
double ukupniPrihod = 0.0;

bool ispravanUnos(int kolicina);
double izracunajIznos(int kolicina);
void evidentirajKupnju(int kolicina, double iznos);
void ispisiKupnju(int redniBroj, double iznos);
void ispisiSazetak();

int main()
{
    int redniBroj;
    int kolicina;
    double iznos;

    for (redniBroj = 1; redniBroj <= 3; redniBroj++)
    {
        cout << "Kupnja " << redniBroj
             << " - unesi broj ulaznica (1-30): ";
        cin >> kolicina;

        while (!ispravanUnos(kolicina))
        {
            cout << "Unesi broj od 1 do 30: ";
            cin >> kolicina;
        }

        iznos = izracunajIznos(kolicina);
        evidentirajKupnju(kolicina, iznos);
        ispisiKupnju(redniBroj, iznos);
    }

    ispisiSazetak();

    return 0;
}

bool ispravanUnos(int kolicina)
{
    return kolicina >= 1 && kolicina <= 30;
}

double izracunajIznos(int kolicina)
{
    double osnovniIznos = kolicina * CIJENA_ULAZNICE;
    double konacniIznos = osnovniIznos;

    if (kolicina >= PRAG_POPUSTA)
    {
        konacniIznos = osnovniIznos * (1 - STOPA_POPUSTA);
    }

    return konacniIznos;
}

void evidentirajKupnju(int kolicina, double iznos)
{
    ukupnoUlaznica += kolicina;
    ukupniPrihod += iznos;
}

void ispisiKupnju(int redniBroj, double iznos)
{
    cout << fixed << setprecision(2);
    cout << "Kupnja " << redniBroj << ": "
         << iznos << " EUR" << endl;
}

void ispisiSazetak()
{
    cout << "Ukupno prodanih ulaznica: "
         << ukupnoUlaznica << endl;

    cout << fixed << setprecision(2);
    cout << "Ukupni prihod: "
         << ukupniPrihod << " EUR" << endl;
}
