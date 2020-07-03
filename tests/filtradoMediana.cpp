#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(filtradoMedianaTEST, filtradoMedianaValidos){
    senial hablante = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};

    int prof = 8;
    int freq = 10;
    int R = 4;

    senial hablanteResultante = {1, 3, -3, 4, 1, 0, -2, -8, 9, -15};

    filtradoMediana(hablante, R, prof, freq);

    ASSERT_SENIAL_EQ(hablante, hablanteResultante);
}

TEST(filtradoMedianaTEST, filtradoMedianoValidoConRmenor){
    senial hablante = {2, -5, 3, 3, -10, 11, 12, -34, -50, 20};

    int prof = 8;
    int freq = 10;
    int R = 2;

    senial hablanteResultante = {2, -5, 2, 3, 3, 3, -10, 11, -50, 20};

    filtradoMediana(hablante, R, prof, freq);

    ASSERT_SENIAL_EQ(hablante, hablanteResultante);
}

TEST(filtradoMedianaTEST, filtradoMedianaResultadoIgual){
    senial hablante = {2,77,3,3,3,3,3,3,3,3,3,3,3,3,3,3,87,1};

    int prof = 8;
    int freq = 10;
    int R = 2;

    senial hablanteResultante = {2,77,3,3,3,3,3,3,3,3,3,3,3,3,3,3,87,1};

    filtradoMediana(hablante, R, prof, freq);

    ASSERT_SENIAL_EQ(hablante, hablanteResultante);
}



