#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"
#include <iostream>
#include <fstream>

bool duraMasDe(senial s, int freq, float seg);
bool esValida(senial s, int prof, int frec);
senial leerSenial(string nombreArchivo);
void escribirSenial(senial  s, string nombreArchivo);
bool gritando(senial s, int umbral);
senial ralentizarSenial(senial  senial1);
senial acelerarSenial(senial  senial1);
bool esMatriz(reunion r);
bool senialesValidas(reunion r,int prof,int freq);
bool hablantesDeReunionValidos(reunion r);
bool haySilencioQueLoContiene(senial s,int muestra,int freq,int umbral);
bool dureMenosDe(int inferior,int superior, int freq, double seg);
double tono(senial s);
bool esSilencio(int valor, int umbral);
int valorFiltrado(senial w, int i, int R);
void ASSERT_SENIAL_EQ(senial s1, senial s2);
void ASSERT_REUNION_EQ(reunion reunion1, reunion reunion2);
void ASSERT_HABLANTES_EQ(vector<hablante> s1, vector<hablante> s2);
void ASSERT_INTERVALOS_EQ(vector<intervalo> s1, vector<intervalo> s2);

#endif //REUNIONESREMOTAS_AUXILIARES_H
