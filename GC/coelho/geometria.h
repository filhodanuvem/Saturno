#ifndef GEOMETRIA_H_INCLUDED
#define GEOMETRIA_H_INCLUDED

//Definição dos tipos com indices 1D
typedef float vector3[3]; //ok
typedef float vector4[4]; //ok

typedef float matrix3[9]; //ok
typedef float matrix4[16]; //ok

//Converção indices das matrizes de 2D para 1D
int idx3(int i, int j); //ok
int idx4(int i, int j); //ok

//Inicialização das estruturas
void crcInitializeV3 (vector3 v3); //ok
void crcInitializeV4 (vector4 v4); //ok
void crcInitializeM3 (matrix3 m3); //ok
void crcInitializeM4 (matrix4 m4); //ok

//Inicialização facil dos vetores
void crcCriaV3 (vector3 v3, float x, float y, float z);
void crcCriaV4 (vector4 v4, float x, float y, float z);

//Cria glVertex a partir dos vertex.vector/4 passado
void crcCriaGlVertexV3 (vector3 v3);
void crcCriaGlVertexV4 (vector4 v4);

//Imprime vetor ou matriz
void crcPrintV3 (vector3 v3); //ok
void crcPrintV4 (vector4 v4); //ok
void crcPrintM3 (matrix3 m3); //ok
void crcPrintM4 (matrix4 m4); //ok

//Converção de vetores
void crcConverterV3em4(vector3 v3, vector4 v4); //ok     //Acresce 1 na dimenssão extra
void crcConverterV4em3(vector4 v4, vector3 v3); //ok     //Trunca a dimenssão

//Converção de matrizes
void crcConverterM3em4(matrix3 m3, matrix4 m4); //ok     //Acresce linha/coluna da crcIdentidade na dimenssão extra
void crcConverterM4em3(matrix4 m4, matrix3 m3); //ok     //Trunca a dimenssão

//Operações de Vetores
void crcAddV3(vector3 va,vector3 vb,vector3 vout); //ok
void crcSubV3(vector3 va,vector3 vb,vector3 vout); //ok
void crcMultV3(vector3 va,vector3 vb,vector3 vout); //ok       //obs: Não é produto escalar! (It is NOT a dot protuct!), mas usamos para calcula-lo
void crcScaleV3(vector3 v,float num,vector3 vout); //ok
float crcDotProductV3(vector3 va,vector3 vb);  //ok
void crcVetorNuloV3(vector3 v);  //ok
void crcCopyV3(vector3 v, vector3 vout);  //ok
void crcCrossProductV3(vector3 va, vector3 vb, vector3 vout); //ok
float crcNormV3(vector3 v); //ok
void crcNormalizeV3(vector3 v, vector3 vout); //ok

void crcAddV4(vector4 va,vector4 vb,vector4 vout); //ok
void crcSubV4(vector4 va,vector4 vb,vector4 vout); //ok
void crcMultV4(vector4 va,vector4 vb,vector4 vout); //ok        //obs: Não é produto escalar! (It is NOT a dot protuct!), mas usamos para calcula-lo
void crcScaleV4(vector4 v,float num,vector4 vout); //ok
float crcDotProductV4(vector4 va,vector4 vb);  //ok
void crcVetorNuloV4(vector4 v);  //ok
void crcCopyV4(vector4 v, vector4 vout);  //ok
void crcCrossProductV4(vector4 va, vector4 vb, vector4 vout); //ok
float crcNormV4(vector4 v); //ok
void crcNormalizeV4(vector4 v, vector4 vout); //ok

//Operações de matrizes
void crcAddM3(matrix3 ma,matrix3 mb,matrix3 mout);  //ok
void crcSubM3(matrix3 ma,matrix3 mb,matrix3 mout); //ok
void crcMultM3(matrix3 ma,matrix3 mb,matrix3 mout);
void crcMultElementoM3(matrix3 ma,matrix3 mb,matrix3 mout); //ok    //multiplica elemento a elemento da matrix  NÂO é a multiplicação de matriz tradicional
void crcScaleM3(matrix3 m,float num,matrix3 mout); //ok
float crcDeterminanteM3(matrix3 m);  //ok
void crcTransposeM3(matrix3 m, matrix3 mt); //ok
void crcInverseM3(matrix3 m, matrix3 mi);
void crcMatrizNulaM3(matrix3 m); //ok
void crcIdentityM3(matrix3 m);  //ok
void crcCopyM3(matrix3 m, matrix3 mout);  //ok

void crcAddM4(matrix4 ma,matrix4 mb,matrix4 mout);  //ok
void crcSubM4(matrix4 ma,matrix4 mb,matrix4 mout); //ok
void crcMultM4(matrix4 ma,matrix4 mb,matrix4 mout); //ok
void crcMultElementoM4(matrix4 ma,matrix4 mb,matrix4 mout); //ok    //multiplica elemento a elemento da matrix  NÂO é a multiplicação de matriz tradicional
void crcScaleM4(matrix4 m,float num,matrix4 mout); //ok
float crcDeterminanteM4(matrix4 m);  //ok
void crcSubMtx(matrix3 subMatrix, matrix4 m, int i);  //ok     //procura matriz 3x3 em matriz 4x4 para calcular o determinante de 4x4
void crcTransposeM4(matrix4 m, matrix4 mt); //ok
void crcInverseM4(matrix4 m, matrix4 mi);
void crcMatrizNulaM4(matrix4 m); //ok
void crcIdentityM4(matrix4 m);  //ok
void crcCopyM4(matrix4 m, matrix4 mout);  //ok

//Operações entre matizes e vetores
void crcMultM3V3(matrix3 m, vector3 v, vector3 vout); //ok
void crcMultM4V4(matrix4 m, vector4 v, vector4 vout); //ok
void crcMultV3tM3(vector3 vt, matrix3 m, vector3 vout); //ok
void crcMultV4tM4(vector4 vt, matrix4 m, vector4 vout); //ok

float crcDegreeToRadians(float anguloGraus);
#endif // GEOMETRIA_H_INCLUDED
