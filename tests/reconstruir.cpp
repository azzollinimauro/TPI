#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(reconstruirTEST, reconstruirValidos){
    senial hablante1 = {1, 3, -3, 4, 6, 0, 0, -8, 9, -15};
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = {1, 3, -3, 4, 6, -1, -1, -8, 9, -15};

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, senialConCerosValidos){
    senial hablante1 = {1, 0, -1, 4, 1, 0, -1, -8, 9, -15};
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = {1, 0, -1, 4, 1, 0, -1, -8, 9, -15};

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

TEST(reconstruirTEST, maximaCantidadDeCeros){
    senial hablante1 = {1, 0, -3, 4, 0, 0, -1, -8, 0, 15};
    int prof = 8;
    int freq = 10;

    senial hablante1Reconstruido = {1, -1, -3, 4, 1, 1, -1, -8, 3, 15};

    senial hablanteObtenido = reconstruir(hablante1, prof, freq);

    ASSERT_HABLANTES_EQ(hablanteObtenido, hablante1Reconstruido);
}

