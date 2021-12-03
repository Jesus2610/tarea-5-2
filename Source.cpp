#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <cstring>
#include <sstream>

using namespace std;
struct patron
{
    long key;
    string mes, hora, ip, concepto;
    int dia;

    bool operator<(const patron& atr) const
    {
        return (key < atr.key);
    }
};
struct DatosPersonales
{
    string Algo;
    char* Ip;
};

//Devuelve el valor numérico de hash en base al tamaño de la tabla de hash
int ValorTabla(char* textoHash, int tamanioTabla)
{
    int valorHash = 1;

    for (int j = 1; j < sizeof(textoHash); j++)
    {
        valorHash += (int)textoHash[j];
    }

    return(valorHash % tamanioTabla);
}



int busquedaBinaria(int lista[], int n, int val) {
    int central, bajo = 0, alto = n - 1, valorCentral;
    while (bajo <= alto) {
        central = (bajo + alto) / 2;
        valorCentral = lista[central];
        if (val == valorCentral) {
            if (val == lista[0]) {
                val = lista[0] + 1;
            }
            cout << lista[central - 1] << val - 1;
            while (lista[central - 1] != val - 1) {
                central = central - 1;
            }
            return central;
        }
        else if (val < valorCentral)
            alto = central - 1;
        else
            bajo = central + 1;

    }
    int index2 = -1;
    val = val + 1;

    return index2 = busquedaBinaria(lista, n, val);
}
//hacemos una segunda busqueda binaria para el mayor de los numeros
int busquedaBinaria2(int lista[], int n, int val) {
    int central, bajo = 0, alto = n - 1, valorCentral;
    while (bajo <= alto) {
        central = (bajo + alto) / 2;
        valorCentral = lista[central];
        if (val == valorCentral && lista[central] + 1 == val + 1) {
            if (val == 1030) {
                val = 1029;
            }
            while (lista[central + 1] != val + 1) {
                central = central + 1;
            }
            return central;
        }
        else if (val < valorCentral)
            alto = central - 1;
        else
            bajo = central + 1;
    }
    int index3 = -1;
    val = val - 1;
    return index3 = busquedaBinaria2(lista, n, val);
}

void unir(vector<int>& vec, vector<string>& vecm, vector<int>& vecd, vector<string>& vech, vector<string>& veci, vector<string>& vecc, vector<int>& aux, vector<string>& auxm, vector<int>& auxd, vector<string>& auxh, vector<string>& auxi, vector<string>& auxc, int ini, int fin) {
    int m = (ini + fin) / 2;
    int i = ini, j = m + 1, k = ini; // k un puntero en el vector aux
    while (i <= m && j <= fin) {
        // copiar uno a uno elementos de vec y ponerlos en aux
        if (vec[i] <= vec[j]) {
            auxm[k] = vecm[i];
            auxd[k] = vecd[i];
            auxh[k] = vech[i];
            auxi[k] = veci[i];
            auxc[k] = vecc[i];
            aux[k++] = vec[i++];


            // aux[k] = vec[i];
            // k++;
            // i++;
        }
        else {
            auxm[k] = vecm[j];
            auxd[k] = vecd[j];
            auxh[k] = vech[j];
            auxi[k] = veci[j];
            auxc[k] = vecc[j];
            aux[k++] = vec[j++];

        }
    }

    // Si hay elementos pendientes en la primera mitad

    while (i <= m) {
        auxm[k] = vecm[i];
        auxd[k] = vecd[i];
        auxh[k] = vech[i];
        auxi[k] = veci[i];
        auxc[k] = vecc[i];
        aux[k++] = vec[i++];

    }

    // if hay elementos pendientes en la segunda mitad
    while (j <= fin) {
        auxm[k] = vecm[j];
        auxd[k] = vecd[j];
        auxh[k] = vech[j];
        auxi[k] = veci[j];
        auxc[k] = vecc[j];
        aux[k++] = vec[j++];
    }

    // Copia de aux a vec en las posiciones correspondientes
    for (int z = ini; z <= fin; z++) {
        vec[z] = aux[z];
        vecm[z] = auxm[z];
        vecd[z] = auxd[z];
        vech[z] = auxh[z];
        veci[z] = auxi[z];
        vecc[z] = auxc[z];
    }
}

void merge(vector<int>& vec, vector<string>& vecm, vector<int>& vecd, vector<string>& vech, vector<string>& veci, vector<string>& vecc, vector<int>& aux, vector<string>& auxm, vector<int>& auxd, vector<string>& auxh, vector<string>& auxi, vector<string>& auxc, int ini, int fin) {
    if (ini < fin) {
        // caso general
        int m = (ini + fin) / 2;
        merge(vec, vecm, vecd, vech, veci, vecc, aux, auxm, auxd, auxh, auxi, auxc, ini, m);
        merge(vec, vecm, vecd, vech, veci, vecc, aux, auxm, auxd, auxh, auxi, auxc, m + 1, fin);
        unir(vec, vecm, vecd, vech, veci, vecc, aux, auxm, auxd, auxh, auxi, auxc, ini, fin);

    }
    // else{
    //     // caso base
    // }
}

void printVector(vector<int> a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ",";
    }
    cout << a[n - 1] << endl;
}
void printVectorst(vector<string> a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << endl;
    }
    cout << a[n - 1] << endl;
}


// Función para crear la llave unica para cada entrada en la bitacora
long fechaANumero(string mes, int diab)
{
    int nums[] = { 100,200,300,400,500,600,700,800,900,1000,1100,1200 };
    int mesnum = 0;
    mes[0] = tolower(mes[0]);
    if (mes == "jan")
    {
        mesnum = nums[0];
    }
    if (mes == "feb")
    {
        mesnum = nums[1];
    }
    if (mes == "mar")
    {
        mesnum = nums[2];
    }
    if (mes == "abr")
    {
        mesnum = nums[3];
    }
    if (mes == "may")
    {
        mesnum = nums[4];
    }
    if (mes == "jun")
    {
        mesnum = nums[5];
    }
    if (mes == "jul")
    {
        mesnum = nums[6];
    }
    if (mes == "aug")
    {
        mesnum = nums[7];
    }
    if (mes == "sep")
    {
        mesnum = nums[8];
    }
    if (mes == "oct")
    {
        mesnum = nums[9];
    }
    if (mes == "nov")
    {
        mesnum = nums[10];
    }
    if (mes == "dic")
    {
        mesnum = nums[11];
    }

    // ! Tip: Es posible asignar un número a cada mes y después sumar el valor del día. 
    // ! De seguirse este enfoque, cuidar que el número para representar a los meses NO GENERE COLISIONES.
    long representacion = 0;
    representacion = mesnum + diab;
    return representacion;
}



//Hash table

class HashTable {
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups]; //List 1, Index 0, List 2, Index 1...

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty()const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; //Key: 905, in return, this function will spit out 5.
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING]Key exists. Value replaced." << endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            cell.erase(bItr);
            cout << "[INFO] Item removed." << endl;
            break;
        }
    }

    if (!keyExists) {
        cout << "[WARNING] Key not found. Pair not remove" << endl;
    }

    return;
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Key: " << bItr->first << "Value: " << bItr->second << endl;
        }
    }
    return;
}

int main() {
    vector<patron> atributos;
    string mes, mesBusqueda1, mesBusqueda2, hora, ip, descripcion;
    int diab, diabus1, diabus2;
    long key1, key2;

    // 1. Leyendo archivo de entrada
    ifstream inputBitacora("bitacora-5_2.txt");
    // Mientras se pueda leer cada atributo (excepto descripción)

    while (inputBitacora >> mes >> diab >> hora >> ip)
    {
        // leer atributo
        getline(inputBitacora, descripcion);

        // crear la estructura
        patron atr;
        atr.mes = mes;
        atr.dia = diab;
        atr.hora = hora;
        atr.ip = ip;
        atr.concepto = descripcion;
        atr.key = fechaANumero(mes, diab);

        // almacenarla en vector
        atributos.push_back(atr);
    }


    // TODO: 2. Ordenar bitacora en memoria
    //Complejidad: O(nlog n)

    vector<int> vec;
    vector<string> vecm;
    vector<int> vecd;
    vector<string> vech;
    vector<string> veci;
    vector<string> vecc;

    for (int i = 0; i < atributos.size(); i++)
    {
        vec.push_back(atributos[i].key);
        vecm.push_back(atributos[i].mes);
        vecd.push_back(atributos[i].dia);
        vech.push_back(atributos[i].hora);
        veci.push_back(atributos[i].ip);
        vecc.push_back(atributos[i].concepto);
    }

    cout << "algo";

    int n = vec.size();
    //cout << vec.size() << " " << vecm.size() << " " << vecd.size() << " " << vech.size() << " " << veci.size() << " " << vecc.size() << " " << endl;
    vector<int> vecAux(n);
    vector<string> vecmAux(n);
    vector<int> vecdAux(n);
    vector<string> vechAux(n);
    vector<string> veciAux(n);
    vector<string> veccAux(n);
    vector<string> vecIpCmp(1);
    //printVector(vec);
    merge(vec, vecm, vecd, vech, veci, vecc, vecAux, vecmAux, vecdAux, vechAux, veciAux, veccAux, 0, n - 1);
    //printVector(vec);

    HashTable HT;

    if (HT.isEmpty()) {
        cout << "correcto";
    }
    else {
        cout << "error" << endl;
    }
    cout << veci.size() << endl;

    for (int i = 1; i <= veci.size(); i++)
    {
        
        HT.insertItem(i, veci[i]);
    }
    cout << "jola" << endl;

    HT.printTable();



    if (HT.isEmpty()) {
        cout << "Oh oh. We need to check out code!";
    }
    else {
        cout << "Correct answer! Good Job!" << endl;
    }
}
