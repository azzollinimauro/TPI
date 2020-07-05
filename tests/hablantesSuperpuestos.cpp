#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestosValidos){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {2, 6, 3, 8, 6, 10, 2, 12, 10, -15};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, unicoHablantePorDebajoDelUmbral){
    senial hablante1;
    for(int i = -17; i < 30; i++){
        hablante1.push_back(i);
    }
    int prof = 32;
    int freq = 10;
    reunion reunion = {make_pair(hablante1, 0)};
    int umbral = 45678;

    ASSERT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, unicoHablantePorArribaDelUmbral){
    senial hablante1;
    for(int i = -17; i < 30; i++){
        hablante1.push_back(i);
    }
    int prof = 32;
    int freq = 10;
    reunion reunion = {make_pair(hablante1, 0)};
    int umbral = 1;

    ASSERT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}



TEST(hablantesSuperpuestosTEST, hablantesSeRespetan){
    senial hablante1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    senial hablante2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int prof = 8;
    int freq = 10;
    int umbral = 3;
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};


    ASSERT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}


TEST(hablantesSuperpuestosTEST, nadieRespetaNada){
    senial hablante1;
    senial hablante2;
    senial hablante3;
    senial hablante4;

    for(int i = -14; i < 86; i++){
        hablante1.push_back(100);
        hablante2.push_back(100);
        hablante3.push_back(100);
        hablante4.push_back(100);
    }

    int prof = 16;
    int freq = 10;
    int umbral = 1;
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2), make_pair(hablante4, 3)};


    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablanteRespetado){
    senial hablante1 = {4, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    senial hablante2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int prof = 8;
    int freq = 10;
    int umbral = 3;
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};


    ASSERT_FALSE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}

TEST(hablantesSuperpuestosTEST, hablantesSuperpuestosAlComienzo){
    senial hablante1 = {4, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    senial hablante2 = {4, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int prof = 8;
    int freq = 10;
    int umbral = 3;
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};


    ASSERT_TRUE(hablantesSuperpuestos(reunion, prof, freq, umbral));
}




