#ifndef PROCESSADORVERTICES_H_INCLUDED
#define PROCESSADORVERTICES_H_INCLUDED

#include "geometria.h"

#define MODELMATRIX 0
#define VIEWMATRIX 1
#define PROJECTIONMATRIX 2
#define TEXTUREMATRIX 3



typedef struct _vertex {
    vector4 coord;
    vector3 normal;
    vector4 color;
    vector4 texcoord1;
} vertex;

typedef struct _internalvertex {
    vector4 normcoord;
    vector3 normal;

    vector4 color;
    vector4 colorlight;
    vector4 texcoord;
    char clipcode;
} internalvertex;

void crcPushVertex(vertex *v);
void crcTransformGeometry(internalvertex *input, internalvertex *output);       //Não feito

void crcLoadIdentity(int index);
void crcScale(int index, float sx, float sy, float sz);
void crcTranslate(int index, float tx, float ty, float tz);
void crcCizalhamentoZ(int index, float a, float b);
void crcCizalhamentoX(int index, float b, float c);
void crcCizalhamentoY(int index, float a, float c);
void crcRotateX( int index, float theta);
void crcRotateY( int index, float theta);
void crcRotateZ( int index, float theta);
void crcMultMatrix(int index, matrix4 md, matrix3 mi);
void crcLoadMatrix(int index, matrix4 md, matrix4 mi);
void crcGetMatrix(int index, matrix4 md, matrix4 mi);

void crcOrthogonal(float l, float r, float t, float b, float n, float f);
void crcFrustum(float l, float r, float t, float b, float n, float f);          //Duvida
void crcPerspective(float fovh, float aspectratio, float near, float far);      //Não feito
void crcViewer(float ox, float oy, float oz, vector3 direction, vector3 up);    //Não feito

void crcMultMatrix(int index, matrix4 md, matrix3 mi);
void crcLoadMatrix(int index, matrix4 md, matrix3 mi);
void crcGetMatrix(int index, matrix4 md, matrix3 mi);

#endif // PROCESSADORVERTICES_H_INCLUDED
