#ifndef _PLY_H_
#define _PLY_H_
#include <stdio.h>
#include "rply.h"
#include <math.h>

//criação das estruturas de dados de vértices, arestas e triângulos
typedef struct vertex {
    float x;      //elemento x do vértice
    float y;      //elemento y do vértice
    float z;      //elemento z do vértice
    int v;        //índice do vértice
    int e[20];     //índices das arestas compostas pelo vértice
    int tam_e;    //tamanho do vetor de arestas
    int t[12];     //índices dos triângulos compostos pelo vértice
    int tam_t;    //tamanho do vetor de triângulos
} VERTEX;

typedef struct edge {
    int v0;       //vértice que compõe a aresta
    int v1;       //vértice que compõe a aresta
    int t[2];     //índices dos triângulos compostos pela aresta
    int tam_t;    //tamanho do vetor de triângulos
    int e;        //índice da aresta
    float w;      //peso da aresta
} EDGE;

typedef struct triangle {
    int v0;       //vértice que compõe o triângulo
    int v1;       //vértice que compõe o triângulo
    int v2;       //vértice que compõe o triângulo
    int t;        //índice do triângulo
} TRIANGLE;



//criação e inicialização das variáveis
int index_vert = 0;
int index_edge = 0;
int index_tria = 0;
int nvertices, ntriangles, nedges;
float maxx, minx, maxy, miny, maxz, minz;
int gen1 = 0, gen2 = 0, gen3 = 0;
VERTEX* vert;
EDGE* edge;
TRIANGLE* tria;

//protótipos das funções
int abrir_ply(char** argc);
static int vertex_cb_x(p_ply_argument argument);
static int vertex_cb_y(p_ply_argument argument);
static int vertex_cb_z(p_ply_argument argument);
static int face_cb(p_ply_argument argument);

//função abrir_ply
int abrir_ply(char** argc) {
    p_ply ply = ply_open(argc[1], NULL);
    if (!ply) return 1;
    if (!ply_read_header(ply)) return 1;
    nvertices = ply_set_read_cb(ply, "vertex", "x", vertex_cb_x, NULL, 0);
    ply_set_read_cb(ply, "vertex", "y", vertex_cb_y, NULL, 0);
    ply_set_read_cb(ply, "vertex", "z", vertex_cb_z, NULL, 0);
    ntriangles = ply_set_read_cb(ply, "face", "vertex_indices", face_cb, NULL, 0);
    nedges = 3*ntriangles;
    vert = (VERTEX*)malloc(nvertices * sizeof(VERTEX));
    edge = (EDGE*)malloc(nedges * sizeof(EDGE));
    tria = (TRIANGLE*)malloc(ntriangles * sizeof(TRIANGLE));
    if (!ply_read(ply)) return 1;
}

//função callback para elemento x do vértice
static int vertex_cb_x(p_ply_argument argument) {
    long eol;
    int i;
    ply_get_argument_user_data(argument, NULL, &eol);
    vert[index_vert].x = ply_get_argument_value(argument);
    if (gen1 != 0) {
      if (vert[index_vert].x > maxx) maxx = vert[index_vert].x;
      if (vert[index_vert].x < minx) minx = vert[index_vert].x;
    }
    else {
      maxx = vert[index_vert].x;
      minx = vert[index_vert].x;
      gen1 = 1;
    }      
    return 1;
}

//função callback para elemento y do vértice
static int vertex_cb_y(p_ply_argument argument) {
    long eol;
    ply_get_argument_user_data(argument, NULL, &eol);
    vert[index_vert].y = ply_get_argument_value(argument);
    if (gen2 != 0) {
      if (vert[index_vert].y > maxy) maxy = vert[index_vert].y;
      if (vert[index_vert].y < miny) miny = vert[index_vert].y;
    }
    else {
      maxy = vert[index_vert].y;
      miny = vert[index_vert].y;
      gen2 = 1;
    }
    return 1;
}

//função callback para elemento z do vértice
static int vertex_cb_z(p_ply_argument argument) {
    long eol;
    ply_get_argument_user_data(argument, NULL, &eol);
    vert[index_vert].z = ply_get_argument_value(argument);
    if (gen3 != 0) {
      if (vert[index_vert].z > maxz) maxz = vert[index_vert].z;
      if (vert[index_vert].z < minz) minz = vert[index_vert].z;
    }
    else {
      maxz = vert[index_vert].z;
      minz = vert[index_vert].z;
      gen3 = 1;
    }
    vert[index_vert].v = index_vert;
    vert[index_vert].tam_e = 0;
    vert[index_vert].tam_t = 0;
    index_vert++;
    return 1;
}

//função callback para triângulo
static int face_cb(p_ply_argument argument) {
    long length, value_index;
    int i, existe_aresta;
    ply_get_argument_property(argument, NULL, &length, &value_index);
    switch (value_index) {
        case 0:
            tria[index_tria].v0 = ply_get_argument_value(argument);
            break;
        case 1: 
            tria[index_tria].v1 = ply_get_argument_value(argument);
            break;
        case 2:
            tria[index_tria].v2 = ply_get_argument_value(argument);
            
            
              edge[index_edge].e = index_edge;
              edge[index_edge].v0 = tria[index_tria].v0;
              edge[index_edge].v1 = tria[index_tria].v1;
              edge[index_edge].t[edge[index_edge].tam_t] = index_tria;
              edge[index_edge].tam_t++;
              
            
              vert[edge[index_edge].v0].e[vert[edge[index_edge].v0].tam_e] = index_edge;
              vert[edge[index_edge].v1].e[vert[edge[index_edge].v1].tam_e] = index_edge;
              vert[edge[index_edge].v0].tam_e++;
              vert[edge[index_edge].v1].tam_e++;
              index_edge++;
            
              edge[index_edge].e = index_edge;
              edge[index_edge].v0 = tria[index_tria].v0;
              edge[index_edge].v1 = tria[index_tria].v2;
              edge[index_edge].t[edge[index_edge].tam_t] = index_tria;
              edge[index_edge].tam_t++;
            
              vert[edge[index_edge].v0].e[vert[edge[index_edge].v0].tam_e] = index_edge;
              vert[edge[index_edge].v1].e[vert[edge[index_edge].v1].tam_e] = index_edge;
              vert[edge[index_edge].v0].tam_e++;
              vert[edge[index_edge].v1].tam_e++;
              index_edge++;
            
              edge[index_edge].e = index_edge;
              edge[index_edge].v0 = tria[index_tria].v1;
              edge[index_edge].v1 = tria[index_tria].v2;
              edge[index_edge].t[edge[index_edge].tam_t] = index_tria;
              edge[index_edge].tam_t++;
              
              vert[edge[index_edge].v0].e[vert[edge[index_edge].v0].tam_e] = index_edge;
              vert[edge[index_edge].v1].e[vert[edge[index_edge].v1].tam_e] = index_edge;
              vert[edge[index_edge].v0].tam_e++;
              vert[edge[index_edge].v1].tam_e++;
              index_edge++;
                
            tria[index_tria].t = index_tria;
            
            vert[tria[index_tria].v0].t[vert[tria[index_tria].v0].tam_t] = index_tria;
            vert[tria[index_tria].v1].t[vert[tria[index_tria].v1].tam_t] = index_tria;
            vert[tria[index_tria].v2].t[vert[tria[index_tria].v2].tam_t] = index_tria;
            vert[tria[index_tria].v0].tam_t++;
            vert[tria[index_tria].v1].tam_t++;
            vert[tria[index_tria].v2].tam_t++;
            index_tria++;
            break;
        default: 
            break;
    }
    return 1;
}
#endif
