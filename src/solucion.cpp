#include "solucion.h"
#include "auxiliares.h"

// Ejercicios

bool esSenial(vector<int> s, int prof, int freq) {
    bool resp = false;
    // Implementacion
    return resp;
}

bool seEnojo(senial s, int umbral, int prof, int freq) {
    bool resp = false;
    // Implementacion
    return resp;
}

bool esReunionValida(reunion r, int prof, int freq) {
    bool resp = false;
    // Implementacion
    resp = r.size() > 0 && esMatriz(r) && senialesValidas(r,prof,freq) && hablantesDeReunionValidos(r);
    return resp;
}

void acelerar(reunion& r, int prof, int freq) {
    for (int i = 0; i < r.size(); ++i) {
        r[i].first = acelerarSenial(r[i].first);
    }
}

void ralentizar(reunion& r, int prof, int freq) {
    for (int i = 0; i < r.size(); ++i) {
        r[i].first = ralentizarSenial(r[i].first);
    }
}

vector<hablante> tonosDeVozElevados(reunion r, int freq, int prof) {
    vector<hablante> maximos;
    // Implementacion
    double maximoTono = tono(r[0].first);
    for(int i = 0; i < r.size(); i++){
        double tonoActual = tono(r[i].first);
        if( tonoActual > maximoTono ){
            maximos.clear();
            maximoTono = tonoActual;
        }
        if( tonoActual == maximoTono ){
            maximos.push_back(r[i].second);
        }
    }
    return maximos;
}

void ordenar(reunion& r, int freq, int prof) {
    // Implementacion
    return;
}

vector<intervalo > silencios(senial s, int prof, int freq, int umbral) {
    vector<pair<int,int> > intervalos;
    // Implementacion
    return intervalos;
}


bool hablantesSuperpuestos(reunion r, int prof, int freq, int umbral) {
    bool resp = false;
    // Implementacion
    for(int i = 0; i < r[0].first.size(); i++){
        int personasHablando = 0;
        for(int h = 0; h < r.size(); h++){
            if(!haySilencioQueLoContiene(r[h].first,i,freq,umbral)){
                personasHablando++;
            }
        }
        if(personasHablando > 1){
            resp = true;
        }
    }
    return resp;
}

senial reconstruir(senial s, int prof, int freq) {
    senial senalReconstruida;
    // Implementacion
    return senalReconstruida;
}

void filtradoMediana(senial& s, int R, int prof, int freq){
    // Implementacion
    return;
}



