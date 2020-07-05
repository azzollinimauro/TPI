#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(tonosDeVozElevadosTEST, tonosDeVozElevadosValido){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {2, 6, 3, 8, 6, 10, 2, 12, 10, -15};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), {1});
}

TEST(tonosDeVozElevadosTEST, tonoDeVozElevadoAlComienzo){
    senial hablante1;
    senial hablante2;
    senial hablante3;
    senial hablante4;
    for(int i = 0; i < 44; i++){
        hablante1.push_back(i);
        hablante2.push_back(0);
        hablante3.push_back(1);
        hablante4.push_back(2);
    }
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2), make_pair(hablante4, 3)};

    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), {0});


}

TEST(tonosDeVozElevadosTEST, tonoDeVozElevadoEnElMedio){
    senial hablante1;
    senial hablante2;
    senial hablante3;
    senial hablante4;
    for (int i = 0; i < 44; i++) {
        hablante1.push_back(0);
        hablante2.push_back(1);
        hablante3.push_back(i);
        hablante4.push_back(2);
    }
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2),
                       make_pair(hablante4, 3)};

    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), {2});
}

TEST(tonosDeVozElevadosTEST, tonoDeVozElevadoAlFinal) {
    senial hablante1;
    senial hablante2;
    senial hablante3;
    senial hablante4;
    for (int i = 0; i < 44; i++) {
        hablante1.push_back(0);
        hablante2.push_back(1);
        hablante3.push_back(2);
        hablante4.push_back(i);
    }
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2),
                       make_pair(hablante4, 3)};

    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), {3});

}

TEST(tonosDeVozElevadosTEST, todosConTonoDeVozElevado){
    senial hablante1;
    senial hablante2;
    senial hablante3;
    senial hablante4;
    for (int i = 0; i < 44; i++) {
        hablante1.push_back(i);
        hablante2.push_back(i);
        hablante3.push_back(i);
        hablante4.push_back(i);
    }
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2),
                       make_pair(hablante4, 3)};

    int prof = 8;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), {0,1,2,3});
}

TEST(tonosDeVozElevadosTEST, ultimoHablanteConTonoDeVozElevado){
    senial hablante1;
    senial hablante2;
    senial hablante3;
    for(int i = -12; i < 51; i++){
        hablante1.push_back(i);
        hablante2.push_back(i + 4);
        hablante3.push_back((2*i));
    }

    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2)};
    int prof = 32;
    int freq = 10;

    ASSERT_HABLANTES_EQ(tonosDeVozElevados(reunion, prof, freq), {2});
}




