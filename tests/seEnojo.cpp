#include "../src/solucion.h"
#include "../src/auxiliares.h"
#include "../lib/gtest.h"


using namespace std;

TEST(seEnojoTEST, senialMenorADosSegundos){
    senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
    int prof = 8;
    int freq = 10;
    int umbral = 3;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, seEnojoValido){
    senial s = {9,3,-3,4,6,10,-2,-8,9,-15,7,1,3,-3,4,6,0,-2};
    int prof = 8;
    int freq = 9;
    int umbral = 5;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}


