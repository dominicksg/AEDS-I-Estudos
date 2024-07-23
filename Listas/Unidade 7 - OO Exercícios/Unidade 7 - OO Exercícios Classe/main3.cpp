#include <iostream>
#include <string>

using namespace std;

class Car
{
    double tanque = 0;
    double consumo = 15;
    double distancia = 0;
    // const double capacidadeTanque = 50.0; // Capacidade máxima do tanque

public:
    // Car() : tanque(0), distancia(0) {}
    /*
    Car()
    {
        tanque=0;
        distancia=0;
    }
    */

    void abastecer(double gasolina)
    {
        if (gasolina <= 50 && gasolina > 0)
        {
            tanque = tanque + gasolina;
            // tanque = min(tanque + quantidade, capacidadeTanque);
        }
        else
        {
            cout << "Erro, tamanho invalido" << endl;
        }
    }

    void movecarro(double km)
    {
        double consumoTotal = km / consumo;
        if (consumoTotal <= tanque)
        {
            distancia += km;
            tanque -= consumoTotal;
        }
        else
        {
            cout << "Combustível insuficiente para percorrer essa distância!" << endl;
        }
    }

    double getdistancia() const
    {
        return distancia;
    }
    double gettanque() const { return tanque; }
};

int main()
{
    /*
        Car carro1;

        carro1.abastecer(40);
        carro1.movecarro(30);

        double tanq = carro1.gettanque();
        double dist = carro1.getdistancia();

        cout << "O tanque esta com: " << tanq << " litros" << endl;
        cout << "O carro percorreu: " << dist << " km" << endl;
        */

    Car carro1, carro2;

    carro1.abastecer(20); // Abastece o primeiro carro com 20 litros de gasolina
    carro2.abastecer(30); // Abastece o segundo carro com 30 litros de gasolina

    carro1.movecarro(200); // Move o primeiro carro por 200 km
    carro2.movecarro(400); // Move o segundo carro por 400 km

    // Obtém os detalhes do primeiro carro
    double tanqueCarro1 = carro1.gettanque();
    double distanciaCarro1 = carro1.getdistancia();

    // Obtém os detalhes do segundo carro
    double tanqueCarro2 = carro2.gettanque();
    double distanciaCarro2 = carro2.getdistancia();

    cout << "Carro 1 - Distância percorrida: " << distanciaCarro1 << " km, Combustível restante: " << tanqueCarro1 << " litros" << endl;
    cout << "Carro 2 - Distância percorrida: " << distanciaCarro2 << " km, Combustível restante: " << tanqueCarro2 << " litros" << endl;
}