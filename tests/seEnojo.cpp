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
    senial s = {9,3,-3,4,6,10,-2,-8,9,-15,7,1,3,-3,4,6,0,-2,6,5};
    int prof = 8;
    int freq = 10;
    int umbral = 5;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, seEnojoPorDebajoDelUmbral){
    senial s = {5,4,-3,4,2,1,-2,-1,-4,5,3,1,3,-3,4,6,0,-2,3,4};
    int prof = 8;
    int freq = 10;
    int umbral = 5;

    ASSERT_FALSE(seEnojo(s, umbral, prof, freq));
}

TEST(seEnojoTEST, seEnojoAlFinal){
    senial s = {1,-1,1,1,0,1,0,1,1,0,1,0,1,0,0,0,1,-1,-2,0,-2,-1,-4,9,8,-7,12,-13,6,9,0,-6,8,-9,16,12,10};
    int prof = 8;
    int freq = 10;
    int umbral = 5;

    ASSERT_TRUE(seEnojo(s, umbral, prof, freq));
}




