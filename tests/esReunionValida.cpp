#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(esResunionValidaTEST, reunionValida){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValida, hablanteSolitario){
    senial hablante = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12};
    reunion reunion = {make_pair(hablante, 0)};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValidaTEST, reunionVacia){
    reunion reunion = {};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValida, noEsMatriz){
    senial hablante1 = {-6, -3, -1, 0, 33, 14, 15, 4, 8, 10, 20, 12, 13};
    senial hablante2 = {20, 12, 11, 5, 0, -8, -88, -89, -90, -91, -92, -93, -94};
    senial hablante3 = {1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 0, 0, 0, 0, 0};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2)};
    int prof = 16;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValida, senialesEscalonadas){
    senial hablante1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    senial hablante2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    senial hablante3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2)};
    int prof = 16;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}


TEST(esReunionValida, senialesInvalidas){
    senial hablante1 = {1,2,3};
    senial hablante2 = {100000, 2000, 30000, 400000, -100000};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValida, casoNulo){
    reunion reunion = {};
    int prof = 0;
    int freq = 0;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValida, hablanteFueraDeRango){
    senial hablante1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    senial hablante2 = {0, -1, -2, -3, -4, -5 , -6, -7, -8, -9};
    senial hablanteX = {100, 99, 98, 97, 96, 05, 94, 93, 92, 91};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablanteX, 74)};
    int prof = 32;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

TEST(esReunionValida, hablantesRepetidos){
    senial hablante1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    senial hablante2 = {0, -1, -2, -3, -4, -5 , -6, -7, -8, -9};
    senial hablanteX = {100, 99, 98, 97, 96, 05, 94, 93, 92, 91};
    reunion reunion = {make_pair(hablante1, 0), make_pair(hablante2, 0), make_pair(hablanteX, 0)};
    int prof = 32;
    int freq = 10;

    ASSERT_FALSE(esReunionValida(reunion, prof, freq));
}

















