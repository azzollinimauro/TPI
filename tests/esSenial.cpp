#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"

using namespace std;

TEST(esSenialTEST, frecuenciaValida){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, casoNulo){
    senial s = {};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}


TEST(esSenialTEST, profundidadInvalida){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 13;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, frecuenciaInvalida){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 16;
    int freq = 100;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, duraMenosQueLoValido){
    senial s = {1,3,-3,4,6,0,-2,-8,7};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, duracionCasoBorde){
    senial s = {1,3,-3,4,6,0,-2,-8,7,-23};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, noEstaEnRango){
    senial s = {1,3,-3,4,6,0,-2,-8,7,4,500};
    int prof = 8;
    int freq = 10;

    ASSERT_FALSE(esSenial(s, prof, freq));
}

TEST(esSenialTEST, estaEnRangoCasoBorde){
    senial s = {1,-128,-3,4,6,0,-2,-8,7,4,127};
    int prof = 8;
    int freq = 10;

    ASSERT_TRUE(esSenial(s, prof, freq));
}




