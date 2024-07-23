#include <iostream>
#include <exception>

using namespace std;

int main()
{
    int resultado;
    cout << "Digite o numero do dado" << endl;
    cin >> resultado;

    try
    {
        if (resultado < 1 || resultado > 6)
        {
            throw exception();
        }
        else
        {
            cout << "O valor do dado foi: " << resultado << endl;
        }
    }
    catch (exception &ex)
    {
        cout << "Erro, número inválido: " << ex.what() << endl;
    }

    return 0;
}
