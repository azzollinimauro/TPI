#include "../lib/gtest.h"
#include "definiciones.h"
#include "auxiliares.h"

bool frecValida(int freq) {
    return freq == 10;
}

bool profValida(int prof) {
    return (prof == 8) || (prof == 16) || (prof == 32);
}

bool valorEnRango(int x, int prof) {
    return (pow(-2,prof-1) <= x) && (x <= (pow(2,prof-1) - 1));
}

bool enRango(senial s, int prof) {
    bool resp = true;
    int i = 0;

    for(i=0; i < s.size(); i++) {
        if(!valorEnRango(s[i], prof)) {
            resp = false;
        }
    }

    return resp;
}

bool duraMasDe(senial s, int freq, float seg) {
    return s.size() >= freq * seg;
}

bool esValida(senial s, int prof, int frec) {
    return frecValida(frec) && profValida(prof) && enRango(s, prof) && duraMasDe(s, frec, 1);
}

void escribirSenial(senial  s, string nombreArchivo){
    std::ofstream archivo;
    archivo.open(nombreArchivo);
    for (int i = 0; i < s.size(); ++i) {
        archivo << ' ' << s[i];
    }

    archivo.close();
}


senial leerSenial(string nombreArchivo){
    senial s;
    int muestra;
    std::ifstream archivo;
    archivo.open(nombreArchivo);

    while(!archivo.eof()) {
        archivo >> muestra;
        s.push_back(muestra);
    }

    archivo.close();

    return s;
}


bool gritando(senial s, int freq, int umbral) {
    int j =(freq * 2) - 1;
    int k = 0;
    senial subSenial;
    while(k <= j){
        subSenial.push_back(s[k]);
        k++;
    }
    while(j < s.size() - 1 && tono(subSenial) <= umbral){ // el tiempo de ejecucion queda s + freq
        j++;
        subSenial.erase(subSenial.begin());
        subSenial.push_back(s[j]);
    }
    bool respuesta = tono(subSenial) > umbral;
    return respuesta;
}

senial ralentizarSenial(senial senial1){
    senial s;

    for (int j = 0; j < (senial1.size()) - 1; ++j) {
        s.push_back(senial1[j]);
        s.push_back((senial1[j] + senial1[j + 1]) / 2);
    }

    s.push_back(senial1[senial1.size() -1]);

    return s;
}

senial acelerarSenial(senial senial1){
    senial s;

    for (int j = 0; j < (senial1.size() / 2); ++j) {
        s.push_back(senial1[(2*j)+1]);
    }

    return s;
}

bool esMatriz(reunion r){
    for(int i = 0; i < r.size(); i++){
        if(r[i].first.size() != r[0].first.size()) {
            return false;
        }
    }
    return true;
}

bool senialesValidas(reunion r,int prof,int freq) {
    for(int i = 0; i < r.size(); i++){
        if( !esValida(r[i].first,prof,freq) ){
            return false;
        }
    }
    return true;
}

int maximo(reunion &r, int desde, int hasta){
    int max = desde;
    for(int i = desde + 1; i < hasta; i++){
        if( tono ( r[max].first ) < tono (  r[i].first ) ){
            max = i;
        }
    }
    return max;
}


// i,j deben estar en el rango de la secuencia r

void intercambia(reunion &r, int i, int j){
    pair<senial,hablante>  x;
    x = r[i];
    r[i] = r[j];
    r[j] = x;
}


bool hablantesDeReunionValidos(reunion r) {
    set<int> hablantesEsperados;
    for(int i = 0; i < r.size(); i++) {
        hablantesEsperados.insert(i);
    }
    for(int i = 0; i < r.size(); i++) {
        if(hablantesEsperados.find(r[i].second) != hablantesEsperados.end()){
            hablantesEsperados.erase(r[i].second);
        }
        else{
            return false;
        }
    }
    return true;
}

bool haySilencioQueLoContiene(senial s,int muestra,int freq,int umbral) {
    if(abs(s[muestra]) >= umbral){
        return false;
    }
    int inferior = muestra;
    int superior = muestra;

    while(dureMenosDe(inferior,superior,freq,0.2)){
        if(inferior > 0 && abs(s[inferior-1]) < umbral) {
            inferior--;
        }
        else if(superior < s.size()-1 && abs(s[superior+1]) < umbral) {
            superior++;
        }
        else {
            return false;
        }
    }
    return true;
}

bool dureMenosDe(int inferior,int superior, int freq, double seg) {
    return superior-inferior+1 < freq * seg;
}

double tono(senial s) {
    double res = 0;
    for(int i = 0; i < s.size(); i++){
        res = res + abs( (double)s[i] / (double)s.size() );
    }
    return res;
}

bool senialesOrdenadasIguales(senial s1, senial s2){
    if(s1.size() != s2.size())
        return false;

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

bool reunionesIguales(reunion reunion1, reunion reunion2){
    if(reunion1.size() != reunion2.size())
        return false;

    for (int i = 0; i < reunion1.size(); ++i) {
        if(reunion1[i].second != reunion2[i].second)
            return false;

        if(reunion1[i].first.size() != reunion2[i].first.size())
            return false;

        if(!senialesOrdenadasIguales(reunion1[i].first, reunion2[i].first))
            return false;
    }

    return true;
}

bool hablantesOrdenadosIguales(vector<hablante> s1, vector<hablante> s2){
    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

bool intervalosOrdenadosIguales(vector<intervalo> s1, vector<intervalo> s2){
    if(s1.size() != s2.size())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] != s2[i]){return false;}

    return true;
}

bool esPasajePorCero(senial s, int i){
    return s[i-1] * s[i+1] == -1;
}

int muestraArmada(int x, int y){
    return (x + y) / 2;
}

int anteriorNoNulo(senial s, int i){
    while(s[i - 1] == 0){
        i--;
    }
    return s[i - 1];
}

int siguienteNoNulo(senial s, int i){
    while(s[i + 1] == 0){
        i++;
    }
    return s[i + 1];
}

bool esSilencio(int valor, int umbral) {
    int valorAbs = valor;
    if(valorAbs < 0) valorAbs = -valorAbs; //Ver si no hay funcion pa' esto

    return valorAbs < umbral;
}

int valorFiltrado(senial w, int i, int R) {
    for(int j=i-R; j<i+R+1; j++) {
        int min = j;
        for(int k=j+1; k<i+R+1; k++) {
            if (w[k] < w[min]) {
                min = k;
            }
        }
        swap(w[j], w[min]);
    }

    return w[i];
}

void ASSERT_SENIAL_EQ(senial s1, senial s2) {
    ASSERT_TRUE(senialesOrdenadasIguales(s1, s2));
}

void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2) {
    ASSERT_TRUE(reunionesIguales(reunion1, reunion2));
}

void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2) {
    ASSERT_TRUE(hablantesOrdenadosIguales(s1, s2));
}

void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2) {
    ASSERT_TRUE(intervalosOrdenadosIguales(s1, s2));
}