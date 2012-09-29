#include "geometria.h"
#include <stdio.h>
#include <stdlib.h>
#define GLUT_DISABLE_ATEXIT_HACK 1
#include <GL/glut.h>
#include <math.h>
//implementações de geometria.h

//Converção indices das matrizes de 2D para 1D
int idx3(int i, int j){
    if (i == 0){
        return j;
    }else if (i == 1){
        return j+=3;
    }else if (i == 2){
        return j+=6;
    }else {
        printf("Erro: indice idx3 inválido");
        return 9;
    }
}

int idx4(int i, int j){
    if (i == 0){
        return j;
    }else if (i == 1){
        return j+=4;
    }else if (i == 2){
        return j+=8;
    }else if (i == 3){
        return j+=12;
    }else {
        printf("Erro: indice idx4 inválido");
        return 16;
    }
}

//Inicialização das estruturas
void crcInitializeV3 (vector3 v3){    // !!!! Alterar - vetor deve ser vetor nulo (esta assim só pros testes)
    crcVetorNuloV3(v3);
}

void crcInitializeV4 (vector4 v4){    // !!!! Alterar - vetor deve ser vetor nulo (esta assim só pros testes)
    crcVetorNuloV4(v4);
    v4[3] = 1;
}

void crcInitializeM3 (matrix3 m3){
    crcIdentityM3(m3);
}

void crcInitializeM4 (matrix4 m4){
   // crcIdentityM4(m4);
   unzar(m4);
}

//Inicialização facil dos vetores
void crcCriaV3 (vector3 v3, float x, float y, float z){
    crcInitializeV3(v3);
    v3[0] = x;
    v3[1] = y;
    v3[2] = z;
}


void crcCriaV4 (vector4 v4, float x, float y, float z){
    crcInitializeV4(v4);
    v4[0] = x;
    v4[1] = y;
    v4[2] = z;
    //v4[3] = h;
}

//Cria glVertex a partir dos vertex.vector/4 passado
void crcCriaGlVertexV3 (vector3 v3){
    glVertex3f(v3[0], v3[1], v3[2]);
}
void crcCriaGlVertexV4 (vector4 v4){
    glVertex3f(v4[0], v4[1], v4[2]);
}

//Imprime vetor ou matriz
void crcPrintV3 (vector3 v3){
    int i = 0;
    for(i=0;i < 3; i++)
        printf("%f\n",v3[i]);
    printf("\n");
}

void crcPrintV4 (vector4 v4){
    int i = 0;
    for(i=0;i < 4; i++)
        printf("%f\n",v4[i]);
    printf("\n");
}

void crcPrintM3 (matrix3 m3){
    int i = 0;
    int j = 0;
    for(i=0;i < 3; i++){
        for(j=0;j < 3; j++)
            printf("%f\t",m3[idx3(i,j)]);
         printf("\n");
    }
    printf("\n");
}

void crcPrintM4 (matrix4 m4){
    int i = 0;
    int j = 0;
    for(i=0;i < 4; i++){
        for(j=0;j < 4; j++)
            printf("%f\t",m4[idx4(i,j)]);
        printf("\n");
    }
    printf("\n");
}

//Converção de vetores
void crcConverterV3em4(vector3 v3, vector4 v4){
    v4[0] = v3[0];
    v4[1] = v3[1];
    v4[2] = v3[2];
    v4[3] = 1;
}

void crcConverterV4em3(vector4 v4, vector3 v3){
    v3[0] = v4[0];
    v3[1] = v4[1];
    v3[2] = v4[2];
}

//Converção de matrizes
void crcConverterM3em4(matrix3 m3, matrix4 m4){
    int i = 0;
    int j = 0;
    for(i=0;i < 3; i++){
        for(j=0;j < 3; j++)
            m4[idx4(i,j)] = m3[idx3(i,j)];
    }
    for(i=0;i<3;i++)
          m4[idx4(i,3)] = 0;
    for(j=0;j<3;j++)
          m4[idx4(3,j)] = 0;
    m4[idx4(3,3)] = 1;
}

void crcConverterM4em3(matrix4 m4, matrix3 m3){
    int i = 0;
    int j = 0;
    for(i=0;i < 3; i++){
        for(j=0;j < 3; j++)
            m3[idx3(i,j)] = m4[idx4(i,j)];
    }
}

//Operações de Vetores
    //V3
void crcAddV3(vector3 va,vector3 vb,vector3 vout){
    int i = 0;
    for (i=0; i<3; i++)
        vout[i] = va[i] + vb[i];
}

void crcSubV3(vector3 va,vector3 vb,vector3 vout){
    int i = 0;
    for (i=0; i<3; i++)
        vout[i] = va[i] - vb[i];
}

void crcMultV3(vector3 va,vector3 vb,vector3 vout){
    int i = 0;
    for (i=0; i<3; i++)
        vout[i] = va[i] * vb[i];
}

void crcScaleV3(vector3 v,float num,vector3 vout){
    int i = 0;
    for (i=0; i<3; i++)
        vout[i] = v[i] * num;
}

float crcDotProductV3(vector3 va,vector3 vb){
    int i = 0;
    float out = 0;
    vector3 vaux;
    crcMultV3(va,vb, vaux);

    for (i=0; i<3; i++)
        out += vaux[i];

    return out;
}

void crcVetorNuloV3(vector3 v){
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}

void crcCopyV3(vector3 v, vector3 vout){
    vout[0] = v[0];
    vout[1] = v[1];
    vout[2] = v[2];
}

void crcCrossProductV3(vector3 va, vector3 vb, vector3 vout){
    vout[0] = va[1]*vb[2] - va[2]*vb[1];
    vout[1] = va[2]*vb[0] - va[0]*vb[2];
    vout[2] = va[0]*vb[1] - va[1]*vb[0];
}

float crcNormV3(vector3 v){
    return v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
}

void crcNormalizeV3(vector3 v, vector3 vout){
    crcScaleV3(v,1/crcNormV3(v),vout);
}

    //V4
void crcAddV4(vector4 va,vector4 vb,vector4 vout){
    int i = 0;
    for (i=0; i<4; i++)
        vout[i] = va[i] + vb[i];
}

void crcSubV4(vector4 va,vector4 vb,vector4 vout){
    int i = 0;
    for (i=0; i<4; i++)
        vout[i] = va[i] - vb[i];
}

void crcMultV4(vector4 va,vector4 vb,vector4 vout){
    int i = 0;
    for (i=0; i<4; i++)
        vout[i] = va[i] * vb[i];
}

void crcScaleV4(vector4 v,float num,vector4 vout){
    int i = 0;
    for (i=0; i<4; i++)
        vout[i] = v[i] * num;
}

float crcDotProductV4(vector4 va,vector4 vb){
    int i = 0;
    float out = 0;
    vector4 vaux;
    crcMultV4(va,vb, vaux);

    for (i=0; i<4; i++)
        out += vaux[i];

    return out;
}

void crcVetorNuloV4(vector4 v){
//    v[0] = 0;
//    v[1] = 0;
//    v[2] = 0;
//    v[3] = 0;
}

void crcCopyV4(vector4 v, vector4 vout){
    vout[0] = v[0];
    vout[1] = v[1];
    vout[2] = v[2];
    vout[3] = v[3];
}

void crcCrossProductV4(vector4 va, vector4 vb, vector4 vout){
    // v = (w,x,y,z)       V = (W,X,Y,Z)
    //[ (xY-Xy)+(xZ-Xz)+(yZ-Yz), (Yz-yZ)+(yW-Yw)+(zW-Zw), (xZ-Xz)+(Xw-xW)+(zW-Zw), (Xy-xY)+(Xw-xW)+(Yw-yW) ]
    //http://www.mathpages.com/home/kmath069.htm
    vout[0] = (va[1]*vb[2] - vb[1]*va[2]) + (va[1]*vb[3] - vb[1]*va[3]) + (va[2]*vb[3] - vb[2]*va[3]);
    vout[1] = (va[3]*vb[2] - vb[3]*va[2]) + (va[2]*vb[0] - vb[2]*va[0]) + (va[3]*vb[0] - vb[3]*va[0]);
    vout[2] = (va[1]*vb[3] - vb[1]*va[3]) + (va[0]*vb[1] - vb[0]*va[1]) + (va[3]*vb[0] - vb[3]*va[0]);
    vout[3] = (va[2]*vb[1] - vb[2]*va[1]) + (va[0]*vb[1] - vb[0]*va[1]) + (va[0]*vb[2] - vb[0]*va[2]);
}

float crcNormV4(vector4 v){
    return v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3];
}

void crcNormalizeV4(vector4 v, vector4 vout){
    crcScaleV4(v,1/crcNormV4(v),vout);
}

//Operações de matrizes
    //M3
void crcAddM3(matrix3 ma,matrix3 mb,matrix3 mout){
    int i = 0;
    int j = 0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            mout[idx3(i,j)] = ma[idx3(i,j)] + mb[idx3(i,j)];
}

void crcSubM3(matrix3 ma,matrix3 mb,matrix3 mout){
    int i = 0;
    int j = 0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            mout[idx3(i,j)] = ma[idx3(i,j)] - mb[idx3(i,j)];
}

void crcMultM3(matrix3 ma,matrix3 mb,matrix3 mout){
    mout[idx3(0,0)] = ma[idx3(0,0)]*mb[idx3(0,0)] + ma[idx3(0,1)]*mb[idx3(1,0)] + ma[idx3(0,2)]*mb[idx3(2,0)];
    mout[idx3(0,1)] = ma[idx3(0,0)]*mb[idx3(0,1)] + ma[idx3(0,1)]*mb[idx3(1,1)] + ma[idx3(0,2)]*mb[idx3(2,1)];
    mout[idx3(0,2)] = ma[idx3(0,0)]*mb[idx3(0,2)] + ma[idx3(0,1)]*mb[idx3(1,2)] + ma[idx3(0,2)]*mb[idx3(2,2)];

    mout[idx3(1,0)] = ma[idx3(1,0)]*mb[idx3(0,0)] + ma[idx3(1,1)]*mb[idx3(1,0)] + ma[idx3(1,2)]*mb[idx3(2,0)];
    mout[idx3(1,1)] = ma[idx3(1,0)]*mb[idx3(0,1)] + ma[idx3(1,1)]*mb[idx3(1,1)] + ma[idx3(1,2)]*mb[idx3(2,1)];
    mout[idx3(1,2)] = ma[idx3(1,0)]*mb[idx3(0,2)] + ma[idx3(1,1)]*mb[idx3(1,2)] + ma[idx3(1,2)]*mb[idx3(2,2)];

    mout[idx3(2,0)] = ma[idx3(2,0)]*mb[idx3(0,0)] + ma[idx3(2,1)]*mb[idx3(1,0)] + ma[idx3(2,2)]*mb[idx3(2,0)];
    mout[idx3(2,1)] = ma[idx3(2,0)]*mb[idx3(0,1)] + ma[idx3(2,1)]*mb[idx3(1,1)] + ma[idx3(2,2)]*mb[idx3(2,1)];
    mout[idx3(2,2)] = ma[idx3(2,0)]*mb[idx3(0,2)] + ma[idx3(2,1)]*mb[idx3(1,2)] + ma[idx3(2,2)]*mb[idx3(2,2)];
}

void crcMultElementoM3(matrix3 ma,matrix3 mb,matrix3 mout){
    int i = 0;
    int j = 0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            mout[idx3(i,j)] = ma[idx3(i,j)] * mb[idx3(i,j)];
}

void crcScaleM3(matrix3 m,float num,matrix3 mout){
    int i = 0;
    int j = 0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            mout[idx3(i,j)] = m[idx3(i,j)] * num;
}

float crcDeterminanteM3(matrix3 m){ // nao vale a pena procurar por zeros pois a chance de ter um eh bem baixa
        float determinante;
        determinante = m[idx3(0,0)]*(m[idx3(1,1)]*m[idx3(2,2)] - m[idx3(1,2)]*m[idx3(2,1)]);
        determinante += -m[idx3(1,0)]*(m[idx3(0,1)]*m[idx3(2,2)] - m[idx3(0,2)]*m[idx3(2,1)]);
        determinante += m[idx3(2,0)]*(m[idx3(0,1)]*m[idx3(1,2)] - m[idx3(0,2)]*m[idx3(1,2)]);
        return determinante;
}

void crcTransposeM3(matrix3 m, matrix3 mt){
    int i = 0;
    int j = 0;
    for (i=0; i<3; i++)
        for (j=0; j<3; j++)
            mt[idx3(i,j)] = m[idx3(j,i)];
}

void crcInverseM3(matrix3 m, matrix3 mi){
    matrix3 mt;
    crcTransposeM3(m,mt);
    float escalar = 1/crcDeterminanteM3(m);
    crcScaleM3(mt, escalar, mi); // matriz crcInversa eh 1/determinante da matriz vezes a crcTransposta dela
}

void crcMatrizNulaM3(matrix3 m){
    crcScaleM3(m,0,m);
}

void crcIdentityM3(matrix3 m3){
    int i = 0;
    int j = 0;
    for(i=0;i < 3; i++){
        for(j=0;j < 3; j++)
            if (i!=j) m3[idx3(i,j)] = 0;
            else m3[idx3(i,j)] = 1;
    }
}

void crcCopyM3(matrix3 m, matrix3 mout){
    int i,j;
    for (i=0; i<3; i++)
        for(j=0; j<3; j++)
            mout[idx3(i,j)] = m[idx3(i,j)];
}

    //M4
void crcAddM4(matrix4 ma,matrix4 mb,matrix4 mout){
    int i = 0;
    int j = 0;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            mout[idx4(i,j)] = ma[idx4(i,j)] + mb[idx4(i,j)];
}

void crcSubM4(matrix4 ma,matrix4 mb,matrix4 mout){
    int i = 0;
    int j = 0;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            mout[idx4(i,j)] = ma[idx4(i,j)] - mb[idx4(i,j)];
}

void crcMultM4(matrix4 ma, matrix4 mb,matrix4 mout){

    mout[idx4(0,0)] = ma[idx4(0,0)]*mb[idx4(0,0)] + ma[idx4(0,1)]*mb[idx4(1,0)] + ma[idx4(0,2)]*mb[idx4(2,0)] + ma[idx4(0,3)]*mb[idx4(3,0)];
    mout[idx4(0,1)] = ma[idx4(0,0)]*mb[idx4(0,1)] + ma[idx4(0,1)]*mb[idx4(1,1)] + ma[idx4(0,2)]*mb[idx4(2,1)] + ma[idx4(0,3)]*mb[idx4(3,1)];
    mout[idx4(0,2)] = ma[idx4(0,0)]*mb[idx4(0,2)] + ma[idx4(0,1)]*mb[idx4(1,2)] + ma[idx4(0,2)]*mb[idx4(2,2)] + ma[idx4(0,3)]*mb[idx4(3,2)];
    mout[idx4(0,3)] = ma[idx4(0,0)]*mb[idx4(0,3)] + ma[idx4(0,1)]*mb[idx4(1,3)] + ma[idx4(0,2)]*mb[idx4(2,3)] + ma[idx4(0,3)]*mb[idx4(3,3)];

    mout[idx4(1,0)] = ma[idx4(1,0)]*mb[idx4(0,0)] + ma[idx4(1,1)]*mb[idx4(1,0)] + ma[idx4(1,2)]*mb[idx4(2,0)] + ma[idx4(1,3)]*mb[idx4(3,0)];
    mout[idx4(1,1)] = ma[idx4(1,0)]*mb[idx4(0,1)] + ma[idx4(1,1)]*mb[idx4(1,1)] + ma[idx4(1,2)]*mb[idx4(2,1)] + ma[idx4(1,3)]*mb[idx4(3,1)];
    mout[idx4(1,2)] = ma[idx4(1,0)]*mb[idx4(0,2)] + ma[idx4(1,1)]*mb[idx4(1,2)] + ma[idx4(1,2)]*mb[idx4(2,2)] + ma[idx4(1,3)]*mb[idx4(3,2)];
    mout[idx4(1,3)] = ma[idx4(1,0)]*mb[idx4(0,3)] + ma[idx4(1,1)]*mb[idx4(1,3)] + ma[idx4(1,2)]*mb[idx4(2,3)] + ma[idx4(1,3)]*mb[idx4(3,3)];

    mout[idx4(2,0)] = ma[idx4(2,0)]*mb[idx4(0,0)] + ma[idx4(2,1)]*mb[idx4(1,0)] + ma[idx4(2,2)]*mb[idx4(2,0)] + ma[idx4(2,3)]*mb[idx4(3,0)];
    mout[idx4(2,1)] = ma[idx4(2,0)]*mb[idx4(0,1)] + ma[idx4(2,1)]*mb[idx4(1,1)] + ma[idx4(2,2)]*mb[idx4(2,1)] + ma[idx4(2,3)]*mb[idx4(3,1)];
    mout[idx4(2,2)] = ma[idx4(2,0)]*mb[idx4(0,2)] + ma[idx4(2,1)]*mb[idx4(1,2)] + ma[idx4(2,2)]*mb[idx4(2,2)] + ma[idx4(2,3)]*mb[idx4(3,2)];
    mout[idx4(2,3)] = ma[idx4(2,0)]*mb[idx4(0,3)] + ma[idx4(2,1)]*mb[idx4(1,3)] + ma[idx4(2,2)]*mb[idx4(2,3)] + ma[idx4(2,3)]*mb[idx4(3,3)];

    mout[idx4(3,0)] = ma[idx4(3,0)]*mb[idx4(0,0)] + ma[idx4(3,1)]*mb[idx4(1,0)] + ma[idx4(3,2)]*mb[idx4(2,0)] + ma[idx4(3,3)]*mb[idx4(3,0)];
    mout[idx4(3,1)] = ma[idx4(3,0)]*mb[idx4(0,1)] + ma[idx4(3,1)]*mb[idx4(1,1)] + ma[idx4(3,2)]*mb[idx4(2,1)] + ma[idx4(3,3)]*mb[idx4(3,1)];
    mout[idx4(3,2)] = ma[idx4(3,0)]*mb[idx4(0,2)] + ma[idx4(3,1)]*mb[idx4(1,2)] + ma[idx4(3,2)]*mb[idx4(2,2)] + ma[idx4(3,3)]*mb[idx4(3,2)];
    mout[idx4(3,3)] = ma[idx4(3,0)]*mb[idx4(0,3)] + ma[idx4(3,1)]*mb[idx4(1,3)] + ma[idx4(3,2)]*mb[idx4(2,3)] + ma[idx4(3,3)]*mb[idx4(3,3)];


}

void crcMultElementoM4(matrix4 ma,matrix4 mb,matrix4 mout){
    int i = 0;
    int j = 0;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            mout[idx4(i,j)] = ma[idx4(i,j)] * mb[idx4(i,j)];
}

void crcScaleM4(matrix4 m,float num,matrix4 mout){
    int i = 0;
    int j = 0;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            mout[idx4(i,j)] = m[idx4(i,j)] * num;
}

float crcDeterminanteM4(matrix4 m){ //tambem nao vale a pena procurar por zeros
    float determinante = 0;
    int i;
    matrix3 subMatrix;
    for(i=0;i<4;i++)
    {
       crcSubMtx(subMatrix,m,i);
       if(i/2 == 0)
       determinante += m[idx4(i,0)]*crcDeterminanteM3(subMatrix);
       else // (i/2 == 1)
       determinante += -m[idx4(i,0)]*crcDeterminanteM3(subMatrix);
    }
    return determinante;
}

void crcSubMtx(matrix3 subMatrix, matrix4 m, int i)
{
    int posicaoM3 = 0; //, posicao na m3 usando ela como se fosse 1d
    int posicaoM4 = 0; // mesma coisa com a matrix4
    while(posicaoM4 < 16)
    {
        if(posicaoM4/4 != i && posicaoM4%4 != 0) // retirando a linha i e a primeira coluna para passar o resto para a submatrix
        {
            subMatrix[posicaoM3] =  m[posicaoM4];
            posicaoM3 += 1;
        }
        posicaoM4 += 1;
    }
}

void crcTransposeM4(matrix4 m, matrix4 mt){
    int i = 0;
    int j = 0;
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            mt[idx4(i,j)] = m[idx4(j,i)];
}

void crcInverseM4(matrix4 m, matrix4 mi){
        matrix4 mt;
        crcTransposeM4(m, mt);
        float invDeterminante = 1/(crcDeterminanteM4(m));
        crcScaleM4(mt, invDeterminante, mi);
}

void crcMatrizNulaM4(matrix4 m){
    crcScaleM4(m,0,m);
}

void crcIdentityM4(matrix4 m4){
    int i = 0;
    int j = 0;
    for(i=0;i < 4; i++){
        for(j=0;j < 4; j++)
            if (i!=j) m4[idx4(i,j)] = 0;
            else m4[idx4(i,j)] = 1;
    }
}

void crcCopyM4(matrix4 m, matrix4 mout){
    int i,j;
    for (i=0; i<4; i++)
        for(j=0; j<4; j++)
            mout[idx4(i,j)] = m[idx4(i,j)];
}

//Operações entre matizes e vetores
void crcMultM3V3(matrix3 m, vector3 v, vector3 vout){
    int i,j;
    //crcVetorNuloV3(vout);
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            vout[i] += m[idx3(i,j)]*v[i];
        }
    }
}
void crcMultM4V4(matrix4 m, vector4 v, vector4 vout){
    int i,j;

    vout[0] = v[0] * m[idx4(0,0)] + v[1] * m[idx4(1,0)] + v[2] * m[idx4(2,0)] + v[3] * m[idx4(3,0)];
    vout[1] = v[0] * m[idx4(0,1)] + v[1] * m[idx4(1,1)] + v[2] * m[idx4(2,1)] + v[3] * m[idx4(3,1)];
    vout[2] = v[0] * m[idx4(0,2)] + v[1] * m[idx4(1,2)] + v[2] * m[idx4(2,2)] + v[3] * m[idx4(3,2)];
    vout[3] = v[0] * m[idx4(0,3)] + v[1] * m[idx4(1,3)] + v[2] * m[idx4(2,3)] + v[3] * m[idx4(3,3)];


//    for (i=0;i<4;i++){
//        for(j=0;j<4;j++){
//            vout[i] += m[idx4(i,j)]*v[i];
//        }
//    }
}
void crcMultV3tM3(vector3 vt, matrix3 m, vector3 vout){
    crcMultM3V3(m,vt,vout);     //no nosso programa não há distinção entre vetor linha e vetor coluna
}
void crcMultV4tM4(vector4 vt, matrix4 m, vector4 vout){
    crcMultM4V4(m,vt,vout);     //no nosso programa não há distinção entre vetor linha e vetor coluna
}

float crcDegreeToRadians(float anguloGraus){
    return ((anguloGraus * M_PI) / 180);
}
