#include "solucion.h"
#include "auxiliares.h"

// Ejercicios

bool esSenial(vector<int> s, int prof, int freq) {
    bool resp = false;
    
    if(esValida(s,prof, freq)) {
        resp = true;
    }

    return resp;
}

bool seEnojo(senial s, int umbral, int prof, int freq) {
    bool resp = false;

    if(duraMasDe(s, freq, 2)){
        resp = gritando(s, freq, umbral);
    }

    return resp;
}

bool esReunionValida(reunion r, int prof, int freq) {
    bool resp = false;
    
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
      for(int i = 0; i < r.size() - 1; i++){
        int max = maximo(r, i, r.size());
        intercambia(r,i, max);
    }

}

vector<intervalo > silencios(senial s, int prof, int freq, int umbral) {
    vector<pair<int,int> > intervalos;
    int i = 0;

    int silencioInicial = -1;
    int silencioFinal = -1;
    senial intervaloSilencio = {};

    while(i < s.size()) {
        while (esSilencio(s[i], umbral)) {
            if(silencioInicial == -1) {
                silencioInicial = i;
            } else {
                silencioFinal = i;
            }

            intervaloSilencio.push_back(s[i]);
            i++;
        }

        if(silencioInicial != -1) {
            if(duraMasDe(intervaloSilencio, freq, 0.2)) {
                intervalos.push_back(make_pair(silencioInicial, silencioFinal));
            }
            silencioInicial = -1;
            silencioFinal = -1;
            intervaloSilencio = {};
        }

        i++;
    }

    return intervalos;
}


bool hablantesSuperpuestos(reunion r, int prof, int freq, int umbral) {
    bool resp = false;

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
    senalReconstruida.push_back(s[0]);

    for(int i = 1; i < s.size() - 1; i++){
        if(s[i] != 0 || esPasajePorCero(s,i)){
            senalReconstruida.push_back(s[i]);
        }
        else{
          senalReconstruida.push_back(muestraArmada(anteriorNoNulo(s, i), siguienteNoNulo(s, i)));
        }
    }

    senalReconstruida.push_back(s[s.size() - 1]);

    return senalReconstruida;
}

void filtradoMediana(senial& s, int R, int prof, int freq){
    
    senial w = s;

    for(int i=R; i<s.size()-R;i++) {
        s[i] = valorFiltrado(w, i, R);
    }

    return;
}



