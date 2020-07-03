#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(silenciosTEST, silenciosValidos){
    senial hablante = {1, 3, -3, 4, 6, 0, -2, -8, 9, -15};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    vector<intervalo> intervalos = {make_pair(5,6)};

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, silenciosValidosCasoBorde){
    senial hablante = {1, 1, -3, 4, 6, 0, 78, -2, 0, -2};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    vector<intervalo> intervalos = {make_pair(0,1), make_pair(7,9)};

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, muestrasSilenciosQueNoDuranMasDelTiempoMinimo){
    senial hablante = {1, 44, -3, 100, 1, -34, 2, -7, 4, -19};
    int prof = 8;
    int freq = 10;
    int umbral = 5;

    vector<intervalo> intervalos = {};

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}

TEST(silenciosTEST, silenciosEnTodasLasMuestras){
    senial hablante = {1, 1, -3, 0, -4, -2, 1, -2, 4, 3};
    int prof = 8;
    int freq = 10;
    int umbral = 5;

    vector<intervalo> intervalos = {make_pair(0,9)};

    ASSERT_INTERVALOS_EQ(silencios(hablante, prof, freq, umbral), intervalos);
}



