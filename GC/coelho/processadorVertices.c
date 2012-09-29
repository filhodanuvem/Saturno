#include "processadorVertices.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

matrix4 direct[4];
matrix4 inverse[4];

float crcangle_rot1 = 0, crcangle_rot2 = 0, crcangle_rot3 = 0;
float crcxm = 0, crcym = 0, crczm = 0;

void crcPushVertex(vertex *v){
    internalvertex input;
    internalvertex output;

    crcCopyV4(v->coord, input.normcoord);
    crcCopyV3(v->normal, input.normal);

    crcCopyV4(v->color, input.color);
    crcInitializeV4(input.colorlight);
    crcCopyV4(v->texcoord1, input.texcoord);
    input.clipcode = ' ';
    printf("\nhelp\n");
    crcPrintV4(input.normcoord);

    crcTransformGeometry(&input, &output);
    crcPrintV4(output.normcoord);

    crcCopyV4(output.normcoord, v->coord);
    crcCopyV3(output.normal, v->normal);

    crcCopyV4(output.color, v->color);
    //colorlight
    crcCopyV4(output.texcoord, v->texcoord1);
    //clipcode

}

void unzar(matrix4 m){
    int i, j;
    for(i=0; i<4;i++){
        for(j=0;j<4;j++){
            m[idx4(i,j)] = 1.0f;
        }
    }
}

void unzar3(matrix3 m){
    int i, j;
    for(i=0; i<3;i++){
        for(j=0;j<3;j++){
            m[idx3(i,j)] = 1.0f;
        }
    }
}

void crcTransformGeometry(internalvertex *input, internalvertex *output){
//    unzar(direct[MODELMATRIX]);
//    unzar(direct[VIEWMATRIX]);
//    unzar(direct[PROJECTIONMATRIX]);

    crcMultM4V4(direct[MODELMATRIX], input->normcoord, output->normcoord);
    crcMultM4V4(direct[VIEWMATRIX], output->normcoord, output->normcoord);
    crcMultM4V4(direct[PROJECTIONMATRIX], output->normcoord, output->normcoord);

}

void crcLoadIdentity(int index){
    crcIdentityM4(direct[index]);
}

void crcScale(int index, float sx, float sy, float sz){
    if( sx == 0){
        return;
    }
    matrix4 m4;
    crcInitializeM4(m4);
    m4[idx4(0,0)]  = sx;
    m4[idx4(1,1)]  = sy;
    m4[idx4(2,2)]  = sz;
    crcMultM4(direct[index], m4, direct[index]);
    crcInverseM4(direct[index], inverse[index]);
}

void crcTranslate(int index, float tx, float ty, float tz){
    matrix4 m4;
    crcInitializeM4(m4);
    m4[idx4(0,3)]  = tx;
    m4[idx4(1,3)]  = ty;
    m4[idx4(2,3)]  = tz;
    crcMultM4(direct[index], m4, direct[index]);
    crcInverseM4(direct[index], inverse[index]);
}

//void crcCizalhamentoZ(int index, float a, float b){
//    direct[index][idx4(0,2)]  += a;
//    direct[index][idx4(1,2)]  += b;
//}
//
//void crcCizalhamentoX(int index, float b, float c){
//    direct[index][idx4(1,0)]  += b;
//    direct[index][idx4(2,0)]  += c;
//}
//
//void crcCizalhamentoY(int index, float a, float c){
//    direct[index][idx4(0,1)]  += a;
//    direct[index][idx4(2,1)]  += c;
//}

void crcRotateX(int index, float theta){
    float thetaR = crcDegreeToRadians(theta);
    float s = sinf(thetaR);
    float c = cosf(thetaR);
    matrix4 m4;
    crcInitializeM4(m4);
    m4[idx4(1,1)]  = c;
    m4[idx4(1,2)]  = -s;
    m4[idx4(2,1)]  = s;
    m4[idx4(2,2)]  = c;
    crcMultM4(direct[index], m4, direct[index]);
    crcInverseM4(direct[index], inverse[index]);
}

void crcRotateY(int index, float theta){
    float thetaR = crcDegreeToRadians(theta);
    float s = sinf(thetaR);
    float c = cosf(thetaR);
    matrix4 m4;
    crcInitializeM4(m4);
    m4[idx4(0,0)]  = c;
    m4[idx4(0,2)]  = s;
    m4[idx4(2,0)]  = -c;
    m4[idx4(2,2)]  = c;
    crcMultM4(direct[index], m4, direct[index]);
    crcInverseM4(direct[index], inverse[index]);
}

void crcRotateZ(int index, float theta){
    float thetaR = crcDegreeToRadians(theta);
    float s = sinf(thetaR);
    float c = cosf(thetaR);
    matrix4 m4;
    crcInitializeM4(m4);
    m4[idx4(0,0)]  = c;
    m4[idx4(0,1)]  = -s;
    m4[idx4(1,0)]  = s;
    m4[idx4(1,1)]  = c;
    crcMultM4(direct[index], m4, direct[index]);
    crcInverseM4(direct[index], inverse[index]);
}

void crcOrthogonal(float l, float r, float t, float b, float n, float f){
    crcIdentityM4(direct[PROJECTIONMATRIX]);

    direct[PROJECTIONMATRIX][idx4(0,0)] = 2/(r-l);
    direct[PROJECTIONMATRIX][idx4(1,1)] = 2/(t-b);
    direct[PROJECTIONMATRIX][idx4(2,2)] = -2/(f-n);

    direct[PROJECTIONMATRIX][idx4(0,3)] = -(r+l)/(r-l);
    direct[PROJECTIONMATRIX][idx4(1,3)] = -(t+b)/(t-b);
    direct[PROJECTIONMATRIX][idx4(2,3)] = -(f+n)/(f-n);
}

void crcFrustum(float l, float r, float t, float b, float n, float f){
    crcIdentityM4(direct[PROJECTIONMATRIX]);
    matrix4 m4;
    crcInitializeM4(m4);
    m4[idx4(0,0)] = (2*n)/(r-l);
    m4[idx4(1,1)] = (2*n)/(t-b);
    m4[idx4(2,2)] = (f+n)/(n-f);
    m4[idx4(3,3)] = 0;

    m4[idx4(0,2)] = (r+l)/(r-l);
    m4[idx4(1,2)] = (t+b)/(t-b);
    m4[idx4(2,3)] = (2*n*f)/(n-f);
    m4[idx4(3,2)] = -1;

    crcMultM4(direct[PROJECTIONMATRIX],m4,direct[PROJECTIONMATRIX]);
    matrix4 m4i;
    crcInverseM4(m4,m4i);
    crcMultM4(m4i,inverse[PROJECTIONMATRIX],inverse[PROJECTIONMATRIX]);
}
void crcPerspective(float fovh, float aspectratio, float near, float far){
//    float ymax, xmax;
//    ymax = near * tanf(fovh * M_PI / 360.0);
//    xmax = ymax * aspectratio;
//    crcFrustum(-xmax, xmax, ymax, -ymax, near, far);

    fovh = crcDegreeToRadians(fovh);
    if((tan(fovh/2) != 0) && (aspectratio != 0) && ((near - far) != 0)){
        float cotg = (1/tan(fovh/2));
        matrix4 m4;
        crcInitializeM4(m4);
        m4[idx4(0,0)] = (float)(cotg/aspectratio);
        m4[idx4(1,1)] = cotg;
        m4[idx4(2,1)] = (float)((far+near)/(near-far));
        m4[idx4(2,2)] = (float)((2*far*near)/(near-far));
        m4[idx4(3,1)] = -1;
        m4[idx4(3,3)] = 0;
        crcMultM4(direct[PROJECTIONMATRIX],m4,direct[PROJECTIONMATRIX]);
        matrix4 m4i;
        crcInverseM4(m4,m4i);
        crcMultM4(m4i,inverse[PROJECTIONMATRIX],inverse[PROJECTIONMATRIX]);
    }

}


void crcViewer(float ox, float oy, float oz, vector3 direction, vector3 up){
    crcLoadIdentity(VIEWMATRIX);

    vector3 observador;
    observador[0] = ox;
    observador[1] = oy;
    observador[2] = oz;

    vector3 v3a;
    crcSubV3(direction, observador,v3a);
    crcNormalizeV3(v3a,v3a);

    vector3 v3b;
    crcCopyV3(up, v3b);
    crcNormalizeV3(v3b, v3b);

    vector3 v3c;
    crcCrossProductV3(v3a, v3b, v3c);

    crcCrossProductV3(v3a,v3c,v3b);

    matrix4 m4;
    crcInitializeM4(m4);
    m4[idx4(0,0)] = v3c[0];
    m4[idx4(0,1)] = v3c[1];
    m4[idx4(0,2)] = v3c[2];
    m4[idx4(1,0)] = v3b[0];
    m4[idx4(1,1)] = v3b[1];
    m4[idx4(1,2)] = v3b[2];
    m4[idx4(2,0)] = -v3a[0];
    m4[idx4(2,1)] = -v3a[1];
    m4[idx4(2,2)] = -v3a[2];

    crcMultM4(direct[VIEWMATRIX], m4, direct[VIEWMATRIX]);
    crcTranslate(VIEWMATRIX, -ox, -oy, -oz);

    matrix4 m4i;
    crcInverseM4(m4, m4i);
    crcMultM4(m4i, inverse[VIEWMATRIX], inverse[VIEWMATRIX]);


//    //translada direct para origem;
//    matrix4 m4;
//    crcInitializeM4(m4);
//    m4[idx4(0,3)] = -ox;
//    m4[idx4(1,3)] = -oy;
//    m4[idx4(2,3)] = -oz;
//    crcMultM4(direct[PROJECTIONMATRIX], m4, direct[PROJECTIONMATRIX]);
//    //alinha direction com -z
//    direction[0] = 0;
//    direction[1] = 0;
//    direction[2] = -1;
//    //alinha up com y
//    up[0] = 0;
//    up[1] = 1;
//    up[2] = 0;
}

void crcMultMatrix(int index, matrix4 md, matrix4 mi){  //mi era para ser matrix3 segundo o roteiro, consideramos isto um erro tipografico
    if(md != NULL){
        crcMultM4(direct[index],md,direct[index]);  //multiplica direct por md
    }else{
        crcInverseM4(mi, md);
        crcInverseM4(direct[index],direct[index]);
    }

    if(mi != NULL){
        crcInverseM4(md, mi);
        crcMultM4(inverse[index],mi,inverse[index]);
    }else{

    }
}

void crcLoadMatrix(int index, matrix4 md, matrix4 mi){  //mi era para ser matrix3 segundo o roteiro, consideramos isto um erro tipografico
    if(md != NULL){
        crcCopyM4(direct[index], md);
    }else{
        crcInverseM4(mi, md);
        crcCopyM4(direct[index], md);
    }

    if(mi != NULL){
        crcCopyM4(inverse[index], mi);
    }else{
        crcInverseM4(md, mi);
        crcCopyM4(inverse[index], mi);
    }
}

void crcGetMatrix(int index, matrix4 md, matrix4 mi){
    crcCopyM4(direct[index], md);
    crcCopyM4(inverse[index], mi);
}
