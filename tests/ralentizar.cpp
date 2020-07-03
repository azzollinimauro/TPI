#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(ralentizarTEST, ralentizacionValida){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15};
    senial hablante2Acelerado = {1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15};
    reunion reunionRalentizada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizarDiferentesSeniales){
    senial hablante1 = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    senial hablante2 = {4, -2, 1, 0, 3, 4, 4, 2, 1, -13};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {1, 2, 3, 0, -3, 0, 4, 5, 6, 3, 0, -1, -2, -5, -8, 0, 9, -3, -15};
    senial hablante2Acelerado = {4, 1, -2, 0, 1, 0, 0, 1, 3, 3, 4, 4, 4, 3, 2, 1, 1, -6, -13};
    reunion reunionRalentizada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1)};

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}

TEST(ralentizarTEST, ralentizarSenial0){
    senial hablante1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    senial hablante2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    senial hablante3 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    reunion reunionOriginal = {make_pair(hablante1, 0), make_pair(hablante2, 1), make_pair(hablante3, 2)};
    int prof = 8;
    int freq = 10;

    senial hablante1Acelerado = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    senial hablante2Acelerado = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    senial hablante3Acelerado = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    reunion reunionRalentizada = {make_pair(hablante1Acelerado, 0), make_pair(hablante2Acelerado, 1),
                                    make_pair(hablante3Acelerado, 2)};

    ralentizar(reunionOriginal, prof, freq);

    ASSERT_REUNION_EQ(reunionOriginal, reunionRalentizada);
}