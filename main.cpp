#include <iostream>
#include "lib/gtest.h"
#include "src/solucion.h"
#include "src/auxiliares.h"
#include "src/definiciones.h"

using namespace std;
int main(int argc, char **argv) {
    std::cout << "Implementando TPI!!" << std::endl;
    vector<int> v = { 0, 1, 2, 3, 4, 5};
    escribirSenial(v, "nombre.txt");
    vector<int> a = leerSenial("nombre.txt");
    /*for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] ;
    }*/

    vector<pair<senial, hablante>> reunion;
    pair<senial, hablante> aa;
    aa.first = {0,1,2,3,4,5,6,7,8};
    aa.second = 1;
    reunion.push_back(aa);

    ralentizar(reunion, 2, 1);
    for (int i = 0; i < reunion.size(); ++i) {
        for (int j = 0; j < reunion[i].first.size(); ++j) {
            std::cout << reunion[i].first[j] << ' ' ;
        }
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
