#ifndef _MALHA_H_
#define _MALHA_H_
#include <stdio.h>
#include "rply.h"
#include <math.h>

// Half-Edge
typedef struct he_edge {
    struct he_vert* vert;   // um vértice pertencente à half-edge
    struct he_edge* pair;   // half-edge oposta 
    struct he_face* face;   // face que a half-edge participa do bordo
    struct he_edge* next;   // próxima half-edge na face
} HE_EDGE;

// Vértice
typedef struct he_vert {
        float x;
        float y;
        float z;

        struct he_edge* edge;  // uma das half-edges que emanam do vértice     
} HE_VERT;

// Face (Triângulo)
typedef struct he_face {

        struct he_edge* edge;  // uma das half-edges que fazem parte do bordo da face

}HE_FACE;



extern float maxx, maxy, maxz, minx, miny, minz;
extern int nvertices, ntriangles, nhalfedges;
extern HE_VERT *vert;
extern HE_EDGE *arestas;
extern HE_FACE *triangulos;


//criação e inicialização das variáveis
//protótipos das funções
int CarregaMalhaPLY(char** argc);
void LiberaMalha();

#endif

