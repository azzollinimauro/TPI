#include "../lib/gtest.h"
#include "definiciones.h"
#include "auxiliares.h"

void escribirSenial(senial  s, string nombreArchivo){
    std::ofstream archivo;
    archivo.open(nombreArchivo);
    for (int i = 0; i < s.size(); ++i) {
        archivo << ' ' << s[i];
    }

    archivo.close();
}


senial leerSenial(string nombreArchivo){
    senial s;
    int muestra;
    std::ifstream archivo;
    archivo.open(nombreArchivo);

    while(!archivo.eof()) {
        archivo >> muestra;
        s.push_back(muestra);
    }

    archivo.close();

    return s;
}

senial ralentizarSenial(senial senial1){
    senial s;

    for (int j = 0; j < (senial1.size()) - 1; ++j) {
        s.push_back(senial1[j]);
        s.push_back((senial1[j] + senial1[j + 1]) / 2);
    }

    s.push_back(senial1[senial1.size() -1]);

    return s;
}

senial acelerarSenial(senial senial1){
    senial s;

    for (int j = 0; j < (senial1.size() / 2); ++j) {
        s.push_back(senial1[(2*j)+1]);
    }

    return s;
}

bool senialesOrdenadasIguales(senial s1, senial s2){
    if(s1.size() != s2.size())
        return false;

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

bool reunionesIguales(reunion reunion1, reunion reunion2){
    if(reunion1.size() != reunion2.size())
        return false;

    for (int i = 0; i < reunion1.size(); ++i) {
        if(reunion1[i].second != reunion2[i].second)
            return false;

        if(reunion1[i].first.size() != reunion2[i].first.size())
            return false;

        sort(reunion1[i].first.begin(), reunion1[i].first.end());
        sort(reunion2[i].first.begin(), reunion2[i].first.end());

        if(!senialesOrdenadasIguales(reunion1[i].first, reunion2[i].first))
            return false;
    }

    return true;
}

bool hablantesOrdenadosIguales(vector<hablante> s1, vector<hablante> s2){
    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

bool intervalosOrdenadosIguales(vector<intervalo> s1, vector<intervalo> s2){
    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

void ASSERT_SENIAL_EQ(senial s1, senial s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    ASSERT_TRUE(senialesOrdenadasIguales(s1, s2));
}

void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2) {
    ASSERT_TRUE(reunionesIguales(reunion1, reunion2));
}

void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2) {
    ASSERT_TRUE(hablantesOrdenadosIguales(s1, s2));
}

void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2) {
    ASSERT_TRUE(intervalosOrdenadosIguales(s1, s2));
}