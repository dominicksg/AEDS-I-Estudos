#include <iostream>
#include <string>

using namespace std;

class Clock
{
    int hora;
    int minuto;
    int segundo;

public:
    void setHora(int h, int m, int s)
    {
        hora = h;
        minuto = m;
        segundo = s;
    }

    void getHora(int &h, int &m, int &s)
    {
        h = hora;
        m = minuto;
        s = segundo;
    }

    void avancarSegundo()
    {
        segundo++;
        if (segundo >= 60)
        {
            segundo = 0;
            minuto++;
            if (minuto >= 60)
            {
                minuto = 0;
                hora++;
                if (hora >= 24)
                {
                    hora = 0;
                }
            }
        }
    }
};

int main()
{
    Clock relogio1;

    relogio1.setHora(23, 59, 58);

    int hora, minuto, segundo;
    relogio1.getHora(hora, minuto, segundo);
    cout << "A  e: " << hora << ":" << minuto << ":" << segundo << endl;

    relogio1.avancarSegundo();

    relogio1.getHora(hora, minuto, segundo);
    cout << "A  e: " << hora << ":" << minuto << ":" << segundo << endl;

    relogio1.avancarSegundo();

    relogio1.getHora(hora, minuto, segundo);
    cout << "A  e: " << hora << ":" << minuto << ":" << segundo << endl;
}
