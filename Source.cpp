#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
using namespace std;
using namespace System;

//variables peru
int filabuscada = -1;
int columnabuscada = -1;

//variables internacionales
int filabuscada_internacional = -1;
int columnabuscada_internacional = -1;

//variables colombia
int filabuscada_colombia = -1;
int columnabuscada_colombia = -1;

//matrices vuelos directos
bool vuelos_peru[9][9] = {
            { false, false, false, false, true, false, false, false, false},
            { false, false, false, false, true, false, false, false, false},
            { false, false, false, false, true, false, false, false, false},
            { false, false, false, false, true, false, false, false, false},
            { true, true, true, true, false, true, true, true, true},
            { false, false, false, false, true, false, true, false, false},
            { false, false, false, false, true, true, false, false, false},
            { false, false, false, false, true, false, false, false, false},
            { false, false, false, false, false, true, false, true, false}

};
bool internacional[25][25] = {
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	false,	true,	false,	false,	false,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	true,	false,	false,	false,	false,	true,	false,	true,	true,	false,	false,	true,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	true,	false,	false,	false,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	true,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	true,	false,	false,	false,	false,	true,	false,	false,	true,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	true,	false,	false,	false,	false,	true,	true,	true,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {true,	true,	true,	true,	true,	false,	false,	false,	false,	true,	true,	false,	false,	false,	true,	true,	true,	false,	false,	true,	true,	true,	true,	true,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	true,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {true,	false,	false,	false,	true,	false,	false,	true,	false,	false,	true,	false,	true,	true,	true,	false,	false,	true,	true,	true,	true,	false,	true,	false,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	false,	true,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	false,	false,	false,	true,	false,	false},
        {true,	false,	true,	false,	true,	false,	true,	true,	true,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	true,	false,	false,	true,	false,	false,	false,	false,	true},
        {false,false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true},
        {true, false, false, false, false, false, false, true, false, false, false, false, false, true, false, false, true, false, false, false, false, false, true, true, false},
};
bool colombia[25][25] = {
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	true,	true,	true,	false,	false,	false,	false,	false,	true,	true,	false,	false,	false,	false,	false,	true,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	true,	false,	false,	true,	true,	true,	true,	true,	true,	true},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	true,	true,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false,	true,	true,	false,	true,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	true,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
        {false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	false,	true,	false,	false,	false,	false,	false,	false,	false,	false},
};

//funcioes solo para peru
bool multiplicar_matrices_peru(bool matriz1[9][9], bool matriz2[9][9], bool resultado[9][9])
{
    //inicializamos la matriz resultado
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            resultado[i][j] = false;
        }
    }

    // Multiplicamos las matrices
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                resultado[i][j] = resultado[i][j] || (matriz1[i][k] && matriz2[k][j]);
            }
        }
    }
    return true;
}

void valida_vuelos_peru(string a, string b)
{
    //filas
    {
        if (a == "Piura" || a == "piura" || a == "PIURA")
        {
            filabuscada = 0;
        }
        if (a == "Chiclayo" || a == "chiclayo" || a == "CHICLAYO")
        {
            filabuscada = 1;
        }
        if (a == "Iquitos" || a == "iquitos" || a == "IQUITOS")
        {
            filabuscada = 2;
        }
        if (a == "TRUJILLO" || a == "Trujillo" || a == "trujillo")
        {
            filabuscada = 3;
        }
        if (a == "Lima" || a == "LIMA" || a == "lima")
        {
            filabuscada = 4;
        }
        if (a == "Cusco" || a == "cusco" || a == "CUSCO")
        {
            filabuscada = 5;
        }
        if (a == "Arequipa" || a == "arequipa" || a == "AREQUIPA")
        {
            filabuscada = 6;
        }
        if (a == "Juliaca" || a == "juliaca" || a == "JULIACA")
        {
            filabuscada = 7;
        }
        if (a == "Puerto_Maldonado" || a == "PUERTO_MALDONADO" || a == "puerto_maldonado")
        {
            filabuscada = 8;
        }
    }
    //columnas    
    {
        if (b == "Piura" || b == "piura" || b == "PIURA")
        {
            columnabuscada = 0;
        }
        if (b == "Chiclayo" || b == "chiclayo" || b == "CHICLAYO")
        {
            columnabuscada = 1;
        }
        if (b == "Iquitos" || b == "iquitos" || b == "IQUITOS")
        {
            columnabuscada = 2;
        }
        if (b == "TRUJILLO" || b == "Trujillo" || b == "trujillo")
        {
            columnabuscada = 3;
        }
        if (b == "Lima" || b == "LIMA" || b == "lima")
        {
            columnabuscada = 4;
        }
        if (b == "Cusco" || b == "cusco" || b == "CUSCO")
        {
            columnabuscada = 5;
        }
        if (b == "Arequipa" || b == "arequipa" || b == "AREQUIPA")
        {
            columnabuscada = 6;
        }
        if (b == "Juliaca" || b == "juliaca" || b == "JULIACA")
        {
            columnabuscada = 7;
        }
        if (b == "Puerto_Maldonado" || b == "PUERTO_MALDONADO" || b == "puerto_maldonado")
        {
            columnabuscada = 8;
        }
    }

}

void matriz_validad_peru(int filabuscada, int columnabuscada, bool matriznatural[9][9], bool matriz1escala[9][9], bool matriz2escalas[9][9], string llegada)
{
    if (filabuscada == -1 || columnabuscada == -1 || filabuscada > 8 || columnabuscada > 8 || (filabuscada < 9 && columnabuscada == -1) || (filabuscada == -1 && columnabuscada < 9))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo directo a " << llegada << endl;

        }
        if (matriz1escala[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo con 1 escala a " << llegada << endl;

        }
        if (matriz2escalas[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo con 2 escalas a " << llegada << endl;

        }
    }
}

void matriz_validad_lima_provincia(int filabuscada, int columnabuscada, bool matriznatural[9][9], bool matriz1escala[9][9], bool matriz2escalas[9][9], string llegada)
{
    if (filabuscada == -1 || columnabuscada == -1 || filabuscada > 8 || columnabuscada > 8 || (filabuscada < 9 && columnabuscada == -1) || (filabuscada == -1 && columnabuscada < 9))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo directo a " << llegada << endl;

        }
        if (matriz1escala[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo con 1 escala a " << llegada << endl;

        }
        if (matriz2escalas[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo con 2 escalas a " << llegada << endl;

        }
    }
}

void matriz_validad_nacional_alima(int filabuscada, int columnabuscada, bool matriznatural[9][9], bool matriz1escala[9][9], bool matriz2escalas[9][9])
{
    if ((filabuscada == -1 || columnabuscada == -1 || filabuscada > 8 || columnabuscada > 8 || (filabuscada < 9 && columnabuscada == -1) || (filabuscada == -1 && columnabuscada < 9)))
    {
        cout << "No existe vuelo disponible a lima" << endl;
    }
    else
    {
        if (matriznatural[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo directo a lima" << endl;
        }
        if (matriz1escala[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo con 1 escala a lima" << endl;
        }
        if (matriz2escalas[filabuscada][columnabuscada])
        {
            cout << "Existe vuelo con 2 escalas a lima" << endl;
        }
    }
}

//funciones para internacionales 
bool multiplicar_matrices_internacionales(bool matriz[25][25], bool matriz2[25][25], bool resultado[25][25])
{
    //inicializamos la matriz resultado
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            resultado[i][j] = false;
        }
    }
    //multiplicamos las matrices
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                resultado[i][j] = resultado[i][j] || (matriz[i][k] && matriz2[k][j]);
            }
        }
    }
    return true;
}

void validar_vuelos_internacionales(string a, string b)
{
    //filas
    {
        if (a == "Ciudad_de_Mexico" || a == "CIUDAD_DE_MEXICO" || a == "ciudad_de_mexico")
        {
            filabuscada_internacional = 0;
        }
        if (a == "La_Habana" || a == "LA_HABANA" || a == "la_habana")
        {
            filabuscada_internacional = 1;
        }
        if (a == "Cancun" || a == "CANCUN" || a == "cancun")
        {
            filabuscada_internacional = 2;
        }
        if (a == "Belice" || a == "BELICE" || a == "belice")
        {
            filabuscada_internacional = 3;
        }
        if (a == "Ciudad_de_Guatemala" || a == "CIUDAD_DE_GUATEMALA" || a == "ciudad_de_guatemala")
        {
            filabuscada_internacional = 4;
        }
        if (a == "Flores" || a == "FLORES" || a == "flores")
        {
            filabuscada_internacional = 5;
        }
        if (a == "Punta_Cana" || a == "PUNTA_CANA" || a == "punta_cana")
        {
            filabuscada_internacional = 6;
        }
        if (a == "Santo_Domingo" || a == "SANTO_DOMINGO" || a == "santo_domingo")
        {
            filabuscada_internacional = 7;
        }

        if (a == "San_Juan" || a == "SAN_JUAN" || a == "san_juan")
        {
            filabuscada_internacional = 8;
        }
        if (a == "Roatan" || a == "ROATAN" || a == "roatan")
        {
            filabuscada_internacional = 9;
        }
        if (a == "San_Pedro_de_Sula" || a == "SAN_PEDRO_DE_SULA" || a == "san_pedro_de_sula")
        {
            filabuscada_internacional = 10;
        }
        if (a == "La_ceiba" || a == "LA_CEIBA" || a == "la_ceiba")
        {
            filabuscada_internacional = 11;
        }
        if (a == "Tegucigalpa" || a == "TEGUCIGALPA" || a == "tegucigalpa")
        {
            filabuscada_internacional = 12;
        }
        if (a == "San_Salvador" || a == "SAN_SALVADOR" || a == "san_salvador")
        {
            filabuscada_internacional = 13;
        }
        if (a == "Managua" || a == "MANAGUA" || a == "managua")
        {
            filabuscada_internacional = 14;
        }
        if (a == "Liberia" || a == "LIBERIA" || a == "liberia")
        {
            filabuscada_internacional = 15;
        }
        if (a == "San_Jose_de_Costa_Rica" || a == "san_jose_de_costa_rica" || a == "SAN_JOSE_DE_COSTA_RICA")
        {
            filabuscada_internacional = 16;
        }
        if (a == "Ciudad_de_Panama" || a == "ciudad_de_panama" || a == "CIUDAD_DE_PANAMA")
        {
            filabuscada_internacional = 17;
        }
        if (a == "Caracas" || a == "caracas" || a == "CARACAS")
        {
            filabuscada_internacional = 18;
        }
        if (a == "Medellin" || a == "medellin" || a == "MEDELLIN")
        {
            filabuscada_internacional = 19;
        }
        if (a == "Bogota" || a == "bogota" || a == "BOGOTA")
        {
            filabuscada_internacional = 20;
        }
        if (a == "Cali" || a == "cali" || a == "CALI")
        {
            filabuscada_internacional = 21;
        }
        if (a == "Quito" || a == "quito" || a == "QUITO")
        {
            filabuscada_internacional = 22;
        }
        if (a == "Guayaquil" || a == "guayaquil" || a == "GUAYAQUIL")
        {
            filabuscada_internacional = 23;
        }
        if (a == "Lima" || a == "lima" || a == "LIMA")
        {
            filabuscada_internacional = 24;
        }
    }

    //columnas

    {
        if (b == "Ciudad_de_Mexico" || b == "CIUDAD_DE_MEXICO" || b == "ciudad_de_mexico")
        {
            columnabuscada_internacional = 0;
        }
        if (b == "La_Habana" || b == "LA_HABANA" || b == "la_habana")
        {
            columnabuscada_internacional = 1;
        }
        if (b == "Cancun" || b == "CANCUN" || b == "cancun")
        {
            columnabuscada_internacional = 2;
        }
        if (b == "Belice" || b == "BELICE" || b == "belice")
        {
            columnabuscada_internacional = 3;
        }
        if (b == "Ciudad_de_Guatemala" || b == "CIUDAD_DE_GUATEMALA" || b == "ciudad_de_guatemala")
        {
            columnabuscada_internacional = 4;
        }
        if (b == "Flores" || b == "FLORES" || b == "flores")
        {
            columnabuscada_internacional = 5;
        }
        if (b == "Punta_Cana" || b == "PUNTA_CANA" || b == "punta_cana")
        {
            columnabuscada_internacional = 6;
        }
        if (b == "Santo_Domingo" || b == "SANTO_DOMINGO" || b == "santo_domingo")
        {
            columnabuscada_internacional = 7;
        }
        if (b == "San_Juan" || b == "SAN_JUAN" || b == "san_juan")
        {
            columnabuscada_internacional = 8;
        }
        if (b == "Roatan" || b == "ROATAN" || b == "roatan")
        {
            columnabuscada_internacional = 9;
        }
        if (b == "San_Pedro_de_Sula" || b == "SAN_PEDRO_DE_SULA" || b == "san_pedro_de_sula")
        {
            columnabuscada_internacional = 10;
        }
        if (b == "La_ceiba" || b == "LA_CEIBA" || b == "la_ceiba")
        {
            columnabuscada_internacional = 11;
        }
        if (b == "Tegucigalpa" || b == "TEGUCIGALPA" || b == "tegucigalpa")
        {
            columnabuscada_internacional = 12;
        }
        if (b == "San_Salvador" || b == "SAN_SALVADOR" || b == "san_salvador")
        {
            columnabuscada_internacional = 13;
        }
        if (b == "Managua" || b == "MANAGUA" || b == "managua")
        {
            columnabuscada_internacional = 14;
        }
        if (b == "Liberia" || b == "LIBERIA" || b == "liberia")
        {
            columnabuscada_internacional = 15;
        }

        if (b == "San_Jose_de_costa_Rica" || b == "san_jose_de_costa_rica" || b == "SAN_JOSE_DE_COSTA_RICA")
        {
            columnabuscada_internacional = 16;
        }
        if (b == "Ciudad_de_Panama" || b == "ciudad_de_panama" || b == "CIUDAD_DE_PANAMA")
        {
            columnabuscada_internacional = 17;
        }
        if (b == "Caracas" || b == "caracas" || b == "CARACAS")
        {
            columnabuscada_internacional = 18;
        }
        if (b == "Medellin" || b == "medellin" || b == "MEDELLIN")
        {
            columnabuscada_internacional = 19;
        }
        if (b == "Bogota" || b == "bogota" || b == "BOGOTA")
        {
            columnabuscada_internacional = 20;
        }
        if (b == "Cali" || b == "cali" || b == "CALI")
        {
            columnabuscada_internacional = 21;
        }
        if (b == "Quito" || b == "quito" || b == "QUITO")
        {
            columnabuscada_internacional = 22;
        }
        if (b == "Guayaquil" || b == "guayaquil" || b == "GUAYAQUIL")
        {
            columnabuscada_internacional = 23;
        }
        if (b == "Lima" || b == "lima" || b == "LIMA")
        {
            columnabuscada_internacional = 24;
        }

    }
}

void matriz_validad_internacional(int filabuscada_internacional, int columnabuscada_internacional, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25], string llegada)
{
    if ((filabuscada_internacional == -1 || columnabuscada_internacional == -1 || filabuscada_internacional > 24 || columnabuscada_internacional > 24 || (filabuscada_internacional < 25 && columnabuscada_internacional == -1) || (filabuscada_internacional == -1 && columnabuscada_internacional < 25)))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo directo a " << llegada << endl;
        }
        if (matriz_1_escala[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo con 1 escala a " << llegada << endl;
        }
        if (matriz_2_escalas[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo con 2 escalas a " << llegada << endl;
        }
    }
}

void matriz_validad_internacional_anacional(int filabuscada_internacional, int columnabuscada_internacional, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25])
{
    if ((filabuscada_internacional == -1 || columnabuscada_internacional == -1 || filabuscada_internacional > 24 || columnabuscada_internacional > 24 || (filabuscada_internacional < 25 && columnabuscada_internacional == -1) || (filabuscada_internacional == -1 && columnabuscada_internacional < 25)))
    {
        cout << "No existe vuelo disponible a lima" << endl;
    }
    else
    {
        if (matriznatural[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo directo a lima" << endl;
        }
        if (matriz_1_escala[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo con 1 escala a lima" << endl;
        }
        if (matriz_2_escalas[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo con 2 escalas a lima" << endl;
        }
    }
}

void matriz_validad_lima_aInternacional(int filabuscada_internacional, int columnabuscada_internacional, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25], string llegada)
{
    if ((filabuscada_internacional == -1 || columnabuscada_internacional == -1 || filabuscada_internacional > 24 || columnabuscada_internacional > 24 || (filabuscada_internacional < 25 && columnabuscada_internacional == -1) || (filabuscada_internacional == -1 && columnabuscada_internacional < 25)))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo directo a " << llegada << endl;
        }
        if (matriz_1_escala[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo con 1 escala a " << llegada << endl;
        }
        if (matriz_2_escalas[filabuscada_internacional][columnabuscada_internacional])
        {
            cout << "Existe vuelo con 2 escalas a " << llegada << endl;
        }
    }
}

//funciones para colombia 
bool multiplicar_matrices_colombia(bool matriz[25][25], bool matriz2[25][25], bool resultado[25][25])
{
    //inicializamos la matriz resultado
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            resultado[i][j] = false;
        }
    }
    //multiplicamos las matrices
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            for (int k = 0; k < 25; k++)
            {
                resultado[i][j] = resultado[i][j] || (matriz[i][k] && matriz2[k][j]);
            }
        }
    }
    return true;
}

void valida_vuelos_colombianos(string a, string b)
{
    //filas
    {
        if (a == "San_Andres" || a == "SAN_ANDRES" || a == "san_andres")
        {
            filabuscada_colombia = 0;
        }
        if (a == "Cartagena" || a == "CARTAGENA" || a == "cartagena")
        {
            filabuscada_colombia = 1;
        }
        if (a == "Barranquilla" || a == "BARRANQUILLA" || a == "barranquilla")
        {
            filabuscada_colombia = 2;
        }
        if (a == "Santa_Marta" || a == "SANTA_MARTA" || a == "santa_marta")
        {
            filabuscada_colombia = 3;
        }
        if (a == "Riohacha" || a == "RIOHACHA" || a == "riohacha")
        {
            filabuscada_colombia = 4;
        }
        if (a == "Monteria" || a == "MONTERIA" || a == "monteria")
        {
            filabuscada_colombia = 5;
        }
        if (a == "Valledupar" || a == "VALLEDUPAR" || a == "valledupar")
        {
            filabuscada_colombia = 6;
        }
        if (a == "Medellin" || a == "MEDELLIN" || a == "medellin")
        {
            filabuscada_colombia = 7;
        }

        if (a == "Barrancabermeja" || a == "BARRANCABERMEJA" || a == "barrancabermeja")
        {
            filabuscada_colombia = 8;
        }
        if (a == "Bucaramanga" || a == "BUCARAMANGA" || a == "bucaramanga")
        {
            filabuscada_colombia = 9;
        }
        if (a == "Cucuta" || a == "CUCUTA" || a == "cucuta")
        {
            filabuscada_colombia = 10;
        }
        if (a == "Armenia" || a == "ARMENIA" || a == "armenia")
        {
            filabuscada_colombia = 11;
        }
        if (a == "Pereira" || a == "PEREIRA" || a == "pereira")
        {
            filabuscada_colombia = 12;
        }
        if (a == "Manizales" || a == "MANIZALES" || a == "manizales")
        {
            filabuscada_colombia = 13;
        }
        if (a == "Yopal" || a == "YOPAL" || a == "yopal")
        {
            filabuscada_colombia = 14;
        }
        if (a == "Ibague" || a == "IBAGUE" || a == "ibague")
        {
            filabuscada_colombia = 15;
        }
        if (a == "Bogota" || a == "bogota" || a == "BOGOTA")
        {
            filabuscada_colombia = 16;
        }
        if (a == "Tumaco" || a == "tumaco" || a == "TUMACO")
        {
            filabuscada_colombia = 17;
        }
        if (a == "Cali" || a == "cali" || a == "CALI")
        {
            filabuscada_colombia = 18;
        }
        if (a == "Pasto" || a == "pasto" || a == "PASTO")
        {
            filabuscada_colombia = 19;
        }
        if (a == "Popayan" || a == "popayan" || a == "POPAYAN")
        {
            filabuscada_colombia = 20;
        }
        if (a == "Neiva" || a == "neiva" || a == "NEIVA")
        {
            filabuscada_colombia = 21;
        }
        if (a == "Villavicencio" || a == "villavicencio" || a == "VILLAVICENCIO")
        {
            filabuscada_colombia = 22;
        }
        if (a == "Leticia" || a == "leticia" || a == "LETICIA")
        {
            filabuscada_colombia = 23;
        }
        if (a == "Florencia" || a == "florencia" || a == "FLORENCIA")
        {
            filabuscada_colombia = 24;
        }
    }

    //columnas    
    {
        if (b == "San_Andres" || b == "SAN_ANDRES" || b == "san_andres")
        {
            columnabuscada_colombia = 0;
        }
        if (b == "Cartagena" || b == "CARTAGENA" || b == "cartagena")
        {
            columnabuscada_colombia = 1;
        }
        if (b == "Barranquilla" || b == "BARRANQUILLA" || b == "barranquilla")
        {
            columnabuscada_colombia = 2;
        }
        if (b == "Santa_Marta" || b == "SANTA_MARTA" || b == "santa_marta")
        {
            columnabuscada_colombia = 3;
        }
        if (b == "Riohacha" || b == "RIOHACHA" || b == "riohacha")
        {
            columnabuscada_colombia = 4;
        }
        if (b == "Monteria" || b == "MONTERIA" || b == "monteria")
        {
            columnabuscada_colombia = 5;
        }
        if (b == "Valledupar" || b == "VALLEDUPAR" || b == "valledupar")
        {
            columnabuscada_colombia = 6;
        }
        if (b == "Medellin" || b == "MEDELLIN" || b == "medellin")
        {
            columnabuscada_colombia = 7;
        }
        if (b == "Barrancabermeja" || b == "BARRANCABERMEJA" || b == "barrancabermeja")
        {
            columnabuscada_colombia = 8;
        }
        if (b == "Bucaramanga" || b == "BUCARAMANGA" || b == "bucaramanga")
        {
            columnabuscada_colombia = 9;
        }
        if (b == "Cucuta" || b == "CUCUTA" || b == "cucuta")
        {
            columnabuscada_colombia = 10;
        }
        if (b == "Armenia" || b == "ARMENIA" || b == "armenia")
        {
            columnabuscada_colombia = 11;
        }
        if (b == "Pereira" || b == "PEREIRA" || b == "pereira")
        {
            columnabuscada_colombia = 12;
        }
        if (b == "Manizales" || b == "MANIZALES" || b == "manizales")
        {
            columnabuscada_colombia = 13;
        }
        if (b == "Yopal" || b == "YOPAL" || b == "yopal")
        {
            columnabuscada_colombia = 14;
        }
        if (b == "Ibague" || b == "IBAGUE" || b == "ibague")
        {
            columnabuscada_colombia = 15;
        }
        if (b == "Bogota" || b == "bogota" || b == "BOGOTA")
        {
            columnabuscada_colombia = 16;
        }
        if (b == "Tumaco" || b == "tumaco" || b == "TUMACO")
        {
            columnabuscada_colombia = 17;
        }
        if (b == "Cali" || b == "cali" || b == "CALI")
        {
            columnabuscada_colombia = 18;
        }
        if (b == "Pasto" || b == "pasto" || b == "PASTO")
        {
            columnabuscada_colombia = 19;
        }
        if (b == "Popayan" || b == "popayan" || b == "POPAYAN")
        {
            columnabuscada_colombia = 20;
        }
        if (b == "Neiva" || b == "neiva" || b == "NEIVA")
        {
            columnabuscada_colombia = 21;
        }
        if (b == "Villavicencio" || b == "villavicencio" || b == "VILLAVICENCIO")
        {
            columnabuscada_colombia = 22;
        }
        if (b == "Leticia" || b == "leticia" || b == "LETICIA")
        {
            columnabuscada_colombia = 23;
        }
        if (b == "Florencia" || b == "florencia" || b == "FLORENCIA")
        {
            columnabuscada_colombia = 24;
        }
    }


}

void matriz_validad_colombia(int filabuscada_colombia, int columnabuscada_colombia, bool matriznatural[25][25], bool matriz_1_escala[25][25], bool matriz_2_escalas[25][25], string llegada)
{
    if ((filabuscada_colombia == -1 || columnabuscada_colombia == -1 || filabuscada_colombia > 24 || columnabuscada_colombia > 24 || (filabuscada_colombia < 25 && columnabuscada_colombia == -1) || (filabuscada_colombia == -1 && columnabuscada_colombia < 25)))
    {
        cout << "No existe vuelo disponible a " << llegada << endl;
    }
    else
    {
        if (matriznatural[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "Existe vuelo directo a " << llegada << endl;
        }
        if (matriz_1_escala[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "Existe vuelo con 1 escala a " << llegada << endl;
        }
        if (matriz_2_escalas[filabuscada_colombia][columnabuscada_colombia])
        {
            cout << "Existe vuelo con 2 escalas a " << llegada << endl;
        }
    }
}

void peru() {
    int opcion = 0;
    int opcion_vuelos_internacionales = 0;
    string salida;
    string llegada;
    bool matriz1escala_peru[9][9];
    bool matriz2escala_peru[9][9];
    //vuelos con 1 escala
    multiplicar_matrices_peru(vuelos_peru, vuelos_peru, matriz1escala_peru);
    //vuelos con dos escala
    multiplicar_matrices_peru(matriz1escala_peru, vuelos_peru, matriz2escala_peru);
    //fin de matrices relacionadas con peru

    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;
    valida_vuelos_peru(salida, llegada);
    matriz_validad_peru(filabuscada, columnabuscada, vuelos_peru, matriz1escala_peru, matriz2escala_peru, llegada);
    getch();
}

void vuelos_intenacionales_op1() {
    int opcion = 0;
    int opcion_vuelos_internacionales = 0;
    string salida, llegada;

    bool matriz1escalainternacional[25][25];
    bool matriz2escalainternacional[25][25];
    multiplicar_matrices_internacionales(internacional, internacional, matriz1escalainternacional);
    multiplicar_matrices_internacionales(matriz1escalainternacional, internacional, matriz2escalainternacional);

    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;
    validar_vuelos_internacionales(salida, llegada);
    matriz_validad_internacional(filabuscada_internacional, columnabuscada_internacional, internacional, matriz1escalainternacional, matriz2escalainternacional, llegada);
    getch();

}
void vuelos_intenacionales_op2() {
    int opcion = 0;
    int opcion_vuelos_internacionales = 0;
    string salida, llegada;
    bool matriz1escala_peru[9][9];
    bool matriz2escala_peru[9][9];
    //vuelos con 1 escala
    multiplicar_matrices_peru(vuelos_peru, vuelos_peru, matriz1escala_peru);
    //vuelos con dos escala
    multiplicar_matrices_peru(matriz1escala_peru, vuelos_peru, matriz2escala_peru);
    //fin de matrices relacionadas con peru

    bool matriz1escalainternacional[25][25];
    bool matriz2escalainternacional[25][25];
    multiplicar_matrices_internacionales(internacional, internacional, matriz1escalainternacional);
    multiplicar_matrices_internacionales(matriz1escalainternacional, internacional, matriz2escalainternacional);
    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;
    validar_vuelos_internacionales(salida, llegada);
    valida_vuelos_peru(salida, llegada);
    if (internacional[filabuscada_internacional][24] == true || matriz1escalainternacional[filabuscada_internacional][24] == true || matriz2escalainternacional[filabuscada_internacional][24] == true)
    {
        cout << "Usted debe ir primero a lima y estas son las opciones: " << endl;
        matriz_validad_internacional_anacional(filabuscada_internacional, 24, internacional, matriz1escalainternacional, matriz2escalainternacional);
        cout << "\n Las opciones de vuelo Lima a " << llegada << " son:" << endl;
        matriz_validad_lima_provincia(4, columnabuscada, vuelos_peru, matriz1escala_peru, matriz2escala_peru, llegada);
    }
    else if (vuelos_peru[filabuscada][4] == true || matriz1escala_peru[filabuscada][4] == true || matriz2escala_peru[filabuscada][4] == true)
    {
        cout << "Usted debe ir primero a lima y estas son las opciones: " << endl;
        matriz_validad_nacional_alima(filabuscada, 4, vuelos_peru, matriz1escala_peru, matriz2escala_peru);
        cout << "\nLas opciones de vuelo Lima a " << llegada << " son:" << endl;
        matriz_validad_lima_aInternacional(24, columnabuscada_internacional, internacional, matriz1escalainternacional, matriz2escalainternacional, llegada);
    }
    getch();
}

void vuelos_colombia()
{
    int opcion = 0;
    int opcion_vuelos_colombia = 0;
    string salida, llegada;
    bool matriz1escala_colombia[25][25];
    bool matriz2escalas_colombia[25][25];

    multiplicar_matrices_colombia(colombia, colombia, matriz1escala_colombia);
    multiplicar_matrices_colombia(matriz1escala_colombia, colombia, matriz2escalas_colombia);

    cout << "Lugar de salida: ";
    cin >> salida;
    cout << "Lugar de llegada: ";
    cin >> llegada;

    valida_vuelos_colombianos(salida, llegada);
    matriz_validad_colombia(filabuscada_colombia, columnabuscada_colombia, colombia, matriz1escala_colombia, matriz2escalas_colombia, llegada);
    getch();
}
void creditos() {
    setlocale(LC_ALL, "");
    int tecla;

    Console::BackgroundColor = ConsoleColor::White;
    Console::ForegroundColor = ConsoleColor::Black;
    cout << "                                                ___                    _     _                                          " << endl;
    cout << "                                               (  _`\\                 ( ) _ ( )_                                        " << endl;
    cout << "                                               | ( (_) _ __   __     _| |(_)| ,_)   _     ___                           " << endl;
    cout << "                                               | |  _ ( '__)/'__`\\ /'_` || || |   /'_`\\ /',__)                          " << endl;
    cout << "                                               | (_( )| |  (  ___/( (_| || || |_ ( (_) )\\__, \\                          " << endl;
    cout << "                                               (____/'(_)  `\\____)`\\__,_)(_)`\\__)`\\___/'(____/                          " << endl;
    cout << "                                                                                                                        " << endl;
    cout << "                                                                                                                        " << endl;
    short x = 0, y = 7;

    for (y; y <= 20; y++) {
        Console::BackgroundColor = ConsoleColor::White;
        Console::ForegroundColor = ConsoleColor::Black;
        Console::SetCursorPosition(x, y);
        switch (y) {
        case 8:  cout << "                         __                                                                              "
            << "                                                                                                                  "; break;
        case 9: cout << "                       .'  '.                                                                            "
            << "                                                                                                                  "; break;
        case 10: cout << "                    .-'/  | 0|                                                                           "
            << "                                                                                                                  "; break;
        case 11: cout << "       ,       _.-'  ,|  /    `.                                                                         "
            << "                                                                                                                  "; break;
        case 12: cout << "      /|    .-'       `--''-._.'=================================-,                                      "
            << "                                                                                                                  "; break;
        case 13: cout << "      | '-'`        .___.--._)===================================|                                      "
            << "                                                                                                                  "; break;
        case 14: cout << "       |            .'      |          Integrantes               |                                      "
            << "                                                                                                                  "; break;
        case 15: cout << "        |     /,_.-'        |  Arroyo Ormeño, André Alonso       | "
            << "                                                                                                                  "; break;
        case 16: cout << "      _/   _.' (            |  Del Carpio Flores, Ariana Ileen   |                                      "
            << "                                                                                                                  "; break;
        case 17: cout << "     /  ,-' |  |            |  Diaz Espinoza, Carlos Gabriel     |                                      "
            << "                                                                                                                  "; break;
        case 18: cout << "     |  |    `-'            |  Ramirez Rodriguez, Diego          |                                      "
            << "                                                                                                                  "; break;
        case 19: cout << "      `-'                   '------------------------------------'                                      "
            << "                                                                                                                  ";
        case 20: Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(0, 20);
            cout << "........................................................................................................"
                << "............................................................................................................."; break;
        }
        Console::BackgroundColor = ConsoleColor::Black;
        (y == 20 ? ++x, y = 4 : x += 0);
        (x == 60 ? ++x, x = 2 : x += 0);
        _sleep(10);

    }
}

void menu_intenacional() {
    setlocale(LC_ALL, "");
    system("cls");
    int opcion;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\nAEROLÍNEA AVIANCA\n" << endl;
        cout << "1. Si usted sale desde o llega a cualquier lugar del mundo" << endl;
        cout << "2. Si su destino o lugar de salida es una ciudad del Peru (distinta a Lima)" << endl;
        cout << "3. VOLVER" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            system("cls");
            vuelos_intenacionales_op1();

            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            system("cls");
            vuelos_intenacionales_op2();
            break;
        case 3:
            break;



        }
    } while (opcion != 3);



}

void menu_destinos() {
    setlocale(LC_ALL, "");
    system("cls");
    int opcion;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\nAEROLÍNEA AVIANCA\n" << endl;
        cout << "1. VUELOS PERÚ" << endl;
        cout << "2. VUELOS INTERNACIONALES" << endl;
        cout << "3. VUELOS COLOMBIA" << endl;
        cout << "4. VOLVER AL MENÚ DE OPCIONES" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:

            system("cls");
            peru();
            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            system("cls");
            menu_intenacional();
            break;
        case 3:
            system("cls");
            vuelos_colombia();
            break;
        case 4:
            break;
        }
    } while (opcion != 4);


    getch();
    system("cls");
}
void menu() {
    system("cls");
    int opcion;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. VIAJES" << endl;
        cout << "2. CREDITOS" << endl;
        cout << "3. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Lista de instrucciones de la opción 1        
            system("cls");
            menu_destinos();
            break;

        case 2:
            // Lista de instrucciones de la opción 2                
            system("cls");
            creditos();
            break;
        case 3:
            exit(0);
            break;
        }
    } while (true);


}

void pantalla_inicio() {

    char tecla;

    cout << " .    .   .       .       .       .       .       .       .       .       .       .          .  .  " << endl;
    cout << "    .   .   .  .    .  .    .  .    .  .    .  .    .  .    .  .    .  .    .  .    .  .  .   .   ." << endl;
    cout << " .    .      .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .  .   .  " << endl;
    cout << "  ""   __________  __  ______  ____     ___ _    _________    _   ___________    .   .   .   . :;S@@8@St.          . ." << endl;
    cout << " .""  / ____/ __ \\/ / / / __ \\/ __ \\   /   | |  / /  _/   |  / | / / ____/   |     .      .:%@88@X@X;%8; 8:::. .  ." << endl;
    cout << "  "" / / __/ /_/ / / / / /_/ / / / /  / /| | | / // // /| | /  |/ / /   / /| |. .     . .t888888@XS8X8X@.%@X88% .  " << endl;
    cout << " .""/ /_/ / _, _/ /_/ / ____/ /_/ /  / ___ | |/ // // ___ |/ /|  / /___/ ___ |    . .:%@888888@X@t SSX:XX@XXSt%;   " << endl;
    cout << "  ""\\____/_/ |_|\\____/_/    \\____/  /_/  |_|___/___/_/  |_/_/ |_/\\____/_/  |_|. .:%@888888;X.XXXXX;%XXXXXSt:.tX   ." << endl;
    cout << ".    .   .       . .          .         . .     . .     . .     . .     . .   .;8@88@88XX@88@XX@XXXXX@XXt:.:%t  .   ." << endl;
    cout << "   .   .   .  .      .  . . .    . .  .     .       .       .       .      :%@8888888:.SXX:%;@XXX@XXXSt:..t8;     .  " << endl;
    cout << ".    .      .   .  .           .     .t:  .   . .     . .     . .     .:%@888888%@;XX%X:XXXXXXX@XXS%:..:S@:.  .:t    " << endl;
    cout << ".    .   .       .   . .  .  .    . %X88%         .  .    .  .    . .;@@@8@@88XX @ 8XX@XX@X@XXXXXt..:.t8.     %X.8. ." << endl;
    cout << "   .   .   .  .    .       .   .   @88888%t .  .   .    .   .   ..t@8888888%88SXS:%XXXX@XXXXXXS;:.::%8;     . %88;X  " << endl;
    cout << ".    .      .   .  .;. . .       . :888%888:%    .    .   .  .t@888888@t;SX%@%SSSSX@XXXXXXX%t:.:. ;@888St888;S8t88S;." << endl;
    cout << ".    .   .       . S@8      . .     t8888%X88S.     .      :X8@@@X8X%t:S888@S8t@8SS@XX@XX%:..:.:88:8@8@888.;;8:8%@@  " << endl;
    cout << "   .   .   .  .    88;X.  .     .    S8SS8;8t8@8SSX8888XX:888XX8X@@S@@888888:8.8%%;XXX%t:.:..888%tS8tt8;X8;:.88tX. . " << endl;
    cout << ".    .      .   .  @88:8.SSS%XtX.8X88888;88.88:88 8 88.88.888.88X%t : 8%8..8;: t8tS%;:.: ;@S8.8;;%t8 t.8;8@t:.::.    " << endl;
    cout << ".    .   .       . %.8888.88.888888888%8::8:8;8;8:8:8t8;8:8%8@ t S 8.X:8X8:8 8;St;.... 8%88;8:%ttttt8. StS. : ..  .  " << endl;
    cout << "   .   .   .  .    %8ttt:8S8:.::::...8:8.8;8;8:8;8:8;8:8:8;88:t%%%%SX:  ;. .t;t:..:t88@@8%t@ tttttt%S88@X. ... .    ." << endl;
    cout << ".    .      .   .  :       .;;;ttt%%;:t;%@S88X@ :X.@@XXXXXXXSttttttt%@88@:%;:.:t88;...  .  8tttttttt .8t     .  .    " << endl;
    cout << ".    .   .       . .   .   .  .  .   . . @8;SSSXSS8%.@XXXX%ttttttttt%%t ...:8@:..  .      .X;tttt X% .  .    .   .  ." << endl;
    cout << "   .   .   .  .  . .  .     .  .  .  .  .S%:S;8%XXSX8.XXXX@X: %tttt;   .;%8@t:        .  .  .;X@X%:  .    . .   .   ." << endl;
    cout << ".    .      .   .     .   X888@S%8S88X88.8.::8%8%X@XS8%XX@XXXS%;:..:tX8%:..   . . .  .    .            .      .   .  " << endl;
    cout << ".    .   .       . .  .  888.t;;:%8888:8.8;:88%SXXXXX%XXXXXS%;..:S8t.               .  .     .  .  .  .  .  .        " << endl;
    cout << "   .   .   .  .         .:%S8S8S@S88X8@X8S%8@8888888X8X8S@XX@88%;.    .   . .  .  .      .     .    .          . .  ." << endl;
    cout << ".    .      .   .   .   .    .      .  .. .......::..... .  ..    . .   .            .     . .   .     .  .  .       " << endl;
    cout << ".    .   .       .     ..    .   .                     .        .          . . .  .    . .         .  .    .    . .  " << endl;
    cout << "   .   .   .  .      .     .   .   .     .    .  .  .    .    .    . . . .          .      .  . .   .   .    .       " << endl;
    cout << ".    .      .   .  .    .           Persione <<Espacio> para empezar a viajar     .  . .   .  .      . .   .   .  .  " << endl;
    cout << ".    .   .       .    .  .   .   .     .      . .   .   .    .     .  .  .         .   .  . . .      . .    .        " << endl;
    do
    {


        if (_kbhit())
        {
            tecla = getch();
            if (tecla == 32)
            {
                menu();
            }
        }
    } while (true);
}


int main()
{
    pantalla_inicio();
    getch();
    return 0;

}