#include <iostream>
#include <algorithm>

using namespace std;

struct cvor
{
    int vrednost;
    cvor *levo, *desno;
};

cvor *napravi_cvor(int x, cvor *levo = nullptr, cvor *desno = nullptr)
{
    cvor *novi = new cvor();
    novi->vrednost = x;
    novi->levo = levo;
    novi->desno = desno;
    return novi;
}

cvor *ucitaj()
{
    char c;
    cin >> c;
    if (c == '-')
        return nullptr;
    else
    {
        // ucitali smo [
        int vrednost;
        cin >> vrednost >> ws;
        cvor *levo = ucitaj();
        cin >> ws;
        cvor *desno = ucitaj();
        cin >> ws;
        // ucitavamo ]
        cin >> c;
        return napravi_cvor(vrednost, levo, desno);
    }
}

void obrisi(cvor *koren)
{
    if (koren != nullptr)
    {
        obrisi(koren->levo);
        obrisi(koren->desno);
        delete koren;
    }
}

void dijametar_i_visina(cvor *koren, int &dijametar, int &visina)
{
    if (koren == nullptr)
    {
        dijametar = 0;
        visina = 0;
    }
    else
    {
        int dijametar_levo, visina_levo;
        dijametar_i_visina(koren->levo, dijametar_levo, visina_levo);
        int dijametar_desno, visina_desno;
        dijametar_i_visina(koren->desno, dijametar_desno, visina_desno);
        dijametar = max({dijametar_levo, dijametar_desno, 1 + visina_levo + visina_desno});
        visina = 1 + max(visina_levo, visina_desno);
    }
}
int visina(cvor *koren)
{
    if (koren == nullptr)
        return 0;
    return 1 + max(visina(koren->levo), visina(koren->desno));
}

int dijametarRek(cvor *koren)
{
    if (koren == nullptr)
        return 0;
    int dijametar_levo = dijametarRek(koren->levo);
    int dijametar_desno = dijametarRek(koren->desno);
    return max({dijametar_levo, dijametar_desno, 1 + visina(koren->levo) + visina(koren->desno)});
}
int dijametar(cvor *koren)
{
    int d, v;
    dijametar_i_visina(koren, d, v);
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cvor *koren = ucitaj();
    cout << dijametar(koren) << endl;
    obrisi(koren);
    return 0;
}