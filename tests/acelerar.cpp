#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(acelerarTEST, aceleracionValida){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9};
    senial hablante2Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9};
    reunion reunionAcelerada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}


TEST(acelerarTEST, diferentesSeniales){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {6, 7, -15, 9, 2, 3, -7, 8, 4, 0, 3, -2, 4, -3, 5, 1, 3, 0, -2, 6, 0};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9};
    senial hablante2Acelerado = {7, 9, 3, 8, 0, -2, -3, 1, 0, 6};
    reunion reunionAcelerada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, senialesPares){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 6};
    senial hablante2 = {6, 7, -15, 9, 2, 3, -7, 8, 4, 0, 3, -2, 4, -3, 5, 1, 3, 0, -2, 6, 0, 1};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9, 6};
    senial hablante2Acelerado = {7, 9, 3, 8, 0, -2, -3, 1, 0, 6, 1};
    reunion reunionAcelerada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}

TEST(acelerarTEST, resultanteIgualAFreq){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15, 7, 1, 3, -3, 4, 6, 0, -2, -8, 9};
    senial hablante2 = {6, 7, -15, 9, 2, 3, -7, 8, 4, 0, 3, -2, 4, -3, 5, 1, 3, 0, -2, 6};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {3, 4, 0, -8, -15, 1, -3, 6, -2, 9};
    senial hablante2Acelerado = {7, 9, 3, 8, 0, -2, -3, 1, 0, 6};
    reunion reunionAcelerada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    acelerar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionAcelerada);
}