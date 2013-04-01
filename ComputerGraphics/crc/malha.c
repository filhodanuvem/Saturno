#ifndef _PLY_H_
#define _PLY_H_
#include <stdio.h>
#include "rply.h"
#include <math.h>

#include"malha.h"

//criação e inicialização das variáveis
int index_vert = 0;
int index_edge = 0;
int index_face = 0;
int nvertices, ntriangles, nhalfedges;
float maxx, minx, maxy, miny, maxz, minz;

// Listas encadeadas de vértices, half-edges e triangulos
HE_VERT     *vert       = NULL;
HE_EDGE     *arestas    = NULL;
HE_FACE     *triangulos = NULL;

//protótipos das funções
int CarregaMalhaPLY(char** argc);
void LiberaMalha();

static int vertex_cb_x(p_ply_argument argument);
static int vertex_cb_y(p_ply_argument argument);
static int vertex_cb_z(p_ply_argument argument);
static int face_cb(p_ply_argument argument);



//função abrir_ply
int CarregaMalhaPLY(char** argc) {
    // libera malha
    vert       = NULL;
    arestas    = NULL;
    triangulos = NULL;
    nhalfedges = 0;
    index_vert = 0;
        
    p_ply ply = ply_open(argc[1], NULL);
    if (!ply) return 1;
    
    if (!ply_read_header(ply)) return 1;
    
    nvertices = ply_set_read_cb(ply, "vertex", "x", vertex_cb_x, NULL, 0);
    ply_set_read_cb(ply, "vertex", "y", vertex_cb_y, NULL, 0);
    ply_set_read_cb(ply, "vertex", "z", vertex_cb_z, NULL, 0);
    ntriangles = ply_set_read_cb(ply, "face", "vertex_indices", face_cb, NULL, 0);
    nhalfedges = 3*ntriangles;
    
    vert        = (HE_VERT*) malloc(nvertices  * sizeof(HE_VERT));
    triangulos  = (HE_FACE*) malloc(ntriangles * sizeof(HE_FACE));
    arestas     = (HE_EDGE*) malloc(nhalfedges * sizeof(HE_EDGE));
    if (!ply_read(ply)) return 1;
}

void LiberaMalha() {
  free (vert);
  free (triangulos);
  free (arestas);
}

//função callback para elemento x do vértice
static int vertex_cb_x(p_ply_argument argument) {
    long   eol;
    float  temp;
    static int nprimeiro = 0;
    
    ply_get_argument_user_data(argument, NULL, &eol);
    
    vert[index_vert].x = temp = ply_get_argument_value(argument);
    
    if (nprimeiro) {
      if (temp > maxx) maxx = temp;
      if (temp < minx) minx = temp;
    }
    else {
      maxx = temp;
      minx = temp;
      nprimeiro = 1;
    }      
    return 1;
}

//função callback para elemento y do vértice
static int vertex_cb_y(p_ply_argument argument) {
    long   eol;
    float  temp;
    static int nprimeiro = 0;
    
    ply_get_argument_user_data(argument, NULL, &eol);
    
    vert[index_vert].y = temp = ply_get_argument_value(argument);
    if (nprimeiro) {
      if (temp > maxy) maxy = temp;
      if (temp < miny) miny = temp;
    }
    else {
      maxy = temp;
      miny = temp;
      nprimeiro = 1;
    }
    return 1;
}

//função callback para elemento z do vértice
static int vertex_cb_z(p_ply_argument argument) {
    long   eol;
    float  temp;
    static int nprimeiro = 0;
    
    ply_get_argument_user_data(argument, NULL, &eol);
    vert[index_vert].z = temp = ply_get_argument_value(argument);
    if (nprimeiro) {
      if (temp > maxz) maxz = temp;
      if (temp < minz) minz = temp;
    }
    else {
      maxz = temp;
      minz = temp;
      nprimeiro = 1;
    }
    vert[index_vert].edge = NULL;
    index_vert++;
    
    return 1;
}


// Insere um vértice na lista de vértices SE NAO EXISTIR
HE_FACE* InsereTriangulo(int v0, int v1, int v2) {
     HE_EDGE *a, *b, *c;     
     HE_FACE *t;
    
     a = (HE_EDGE*) malloc(sizeof(HE_EDGE));
     b = (HE_EDGE*) malloc(sizeof(HE_EDGE));
     c = (HE_EDGE*) malloc(sizeof(HE_EDGE));
     t = (HE_FACE*) malloc(sizeof(HE_FACE));
            if(t && a && b && c) {
                t->edge = a;
              
                //Inserindo o atributo vert da primeira half-edge
                a->vert     = (HE_VERT*) malloc(sizeof(HE_VERT));
                a->vert->x  = vert[v0].x;
                a->vert->y  = vert[v0].y;
                a->vert->z  = vert[v0].z;
                
                if(!vert[v0].edge) {
                  vert[v0].edge = a;
                  a->vert->edge = a;
                }
                else a->vert->edge = vert[v0].edge;
                
                
                //Inserindo o atributo vert da segunda half-edge
                b->vert     = (HE_VERT*) malloc(sizeof(HE_VERT));
                b->vert->x  = vert[v1].x;
                b->vert->y  = vert[v1].y;
                b->vert->z  = vert[v1].z;
                
                if(!vert[v1].edge) {
                  vert[v1].edge = b;
                  b->vert->edge = b;
                }
                else b->vert->edge = vert[v1].edge;
                
                
                //Inserindo o atributo vert da terceira half-edge
                c->vert     = (HE_VERT*) malloc(sizeof(HE_VERT));
                c->vert->x  = vert[v2].x;
                c->vert->y  = vert[v2].y;
                c->vert->z  = vert[v2].z;
                
                if(!vert[v2].edge) {
                  vert[v2].edge = c;
                  c->vert->edge = c;
                }
                else c->vert->edge = vert[v2].edge;
                
                
                
                a->pair = NULL;
                b->pair = NULL;
                c->pair = NULL;
                
                a->face = t;
                b->face = t;
                c->face = t;
                
                a->next = b;
                b->next = c;
                c->next = a;
                
                                
                arestas[index_edge] = *a;
                index_edge++;
                arestas[index_edge] = *b;
                index_edge++;
                arestas[index_edge] = *c;
                index_edge++;
                
                triangulos[index_face] = *t;
            }
          
     return t;
}


//função callback para triângulo
static int face_cb(p_ply_argument argument) {
    long length, value_index;
    static int  v0, v1, v2;
    HE_FACE  *t;
    
    ply_get_argument_property(argument, NULL, &length, &value_index);
    switch (value_index) {
        case 0:
            v0 = ply_get_argument_value(argument);            
            break;
        case 1: 
            v1 = ply_get_argument_value(argument);
            break;
        case 2:
            v2 = ply_get_argument_value(argument);
                        
            t = InsereTriangulo(v0, v1, v2);
            
            index_face++;
            break;
        default: 
            break;
    }
    return 1;
}
#endif

