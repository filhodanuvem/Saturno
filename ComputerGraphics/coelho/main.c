// main.c - Davi B. Rodrigues e Daniel L. A. Madeira
// Um programa OpenGL que exemplifica a visualização
// de malhas ply.

#define GLUT_DISABLE_ATEXIT_HACK 1
#include <GL/glut.h>
#include <math.h>
#include "geometria.h"
#include "processadorVertices.h";

#include"malha.h"


//criação e inicialização das variáveis
GLfloat angle, fAspect;
GLfloat olho [] = {0,0,0};
GLfloat cima [] = {0,1,0};
GLfloat angle_rot1 = 0, angle_rot2 = 0, angle_rot3 = 0;
float xm = 0, ym = 0, zm = 0;

int k, l, m, n;

void Desenha();
void Inicializa ();
void AlteraTamanhoJanela(GLsizei w, GLsizei h);
void GerenciaMouse(int button, int state, int x, int y);
void keyboard_callback_special(int key, int x, int y);



// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	crcLoadIdentity(PROJECTIONMATRIX);
	crcLoadIdentity(MODELMATRIX);
	crcLoadIdentity(VIEWMATRIX);

	crcPerspective(angle,fAspect,0.1,500);

	vector3 vCentro;
	crcInitializeV3(vCentro);
	vector3 vCima;
	crcInitializeV3(vCima);
	vCima[0] = cima[0];
	vCima[1] = cima[1];
	vCima[2] = cima[2];
	crcViewer(olho[0],olho[1],olho[2],vCentro, vCima);

    /////////////////////////////////////////////////////////
    /////Mostra o coelhinho do Davi

    crcRotateX(MODELMATRIX, angle_rot1);
    crcRotateY(MODELMATRIX, angle_rot2);
    crcRotateZ(MODELMATRIX, angle_rot3);

    crcTranslate(MODELMATRIX, -xm, -ym, -zm);

    glColor3f(0,0,1);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

  //desenha a Bounding Box

         vertex p1;
         crcPrintV4(p1.coord);
         crcCriaV4(p1.coord, minx, miny, minz);
         crcPrintV4(p1.coord);
         vertex p2;
         crcCriaV4(p2.coord, maxx, miny, minz);
         vertex p3;
         crcCriaV4(p3.coord, maxx, maxy, minz);
         vertex p4;
         crcCriaV4(p4.coord, minx, maxy, minz);

         vertex p5;
         crcCriaV4(p5.coord, maxx, maxy, maxz);
         vertex p6;
         crcCriaV4(p6.coord, maxx, maxy, minz);
         vertex p7;
         crcCriaV4(p7.coord, maxx, miny, minz);
         vertex p8;
         crcCriaV4(p8.coord, maxx, miny, maxz);

         vertex p9;
         crcCriaV4(p9.coord, maxx, maxy, maxz);
         vertex p10;
         crcCriaV4(p10.coord, minx, maxy, maxz);
         vertex p11;
         crcCriaV4(p11.coord, minx, maxy, minz);
         vertex p12;
         crcCriaV4(p12.coord, maxx, maxy, minz);

         vertex p13;
         crcCriaV4(p13.coord, minx, miny, minz);
         vertex p14;
         crcCriaV4(p14.coord, maxx, miny, minz);
         vertex p15;
         crcCriaV4(p15.coord, maxx, miny, maxz);
         vertex p16;
         crcCriaV4(p16.coord, minx, miny, maxz);

         vertex p17;
         crcCriaV4(p17.coord, maxx, maxy, maxz);
         vertex p18;
         crcCriaV4(p18.coord, minx, maxy, maxz);
         vertex p19;
         crcCriaV4(p19.coord, minx, miny, maxz);
         vertex p20;
         crcCriaV4(p20.coord, maxx, miny, maxz);

         vertex p21;
         crcCriaV4(p21.coord, minx, miny, minz);
         vertex p22;
         crcCriaV4(p22.coord, minx, miny, maxz);
         vertex p23;
         crcCriaV4(p23.coord, minx, maxy, maxz);
         vertex p24;
         crcCriaV4(p24.coord, minx, maxy, minz);


         crcPushVertex(&p1);
         crcPrintV4(p1.coord);
         crcPushVertex(&p2);
         crcPushVertex(&p3);
         crcPushVertex(&p4);
         crcPushVertex(&p5);
         crcPushVertex(&p6);
         crcPushVertex(&p7);
         crcPushVertex(&p8);
         crcPushVertex(&p9);
         crcPushVertex(&p10);
         crcPushVertex(&p11);
         crcPushVertex(&p12);
         crcPushVertex(&p13);
         crcPushVertex(&p14);
         crcPushVertex(&p15);
         crcPushVertex(&p16);
         crcPushVertex(&p17);
         crcPushVertex(&p18);
         crcPushVertex(&p19);
         crcPushVertex(&p20);
         crcPushVertex(&p21);
         crcPushVertex(&p22);
         crcPushVertex(&p23);
        // crcPrintV4(p7.coord);
         crcPushVertex(&p24);
        //crcPrintV4(p7.coord);

	glBegin(GL_QUADS);

         crcCriaGlVertexV3(p1.coord);
         crcCriaGlVertexV3(p2.coord);
         crcCriaGlVertexV3(p3.coord);
         crcCriaGlVertexV3(p4.coord);
         crcCriaGlVertexV3(p5.coord);
         crcCriaGlVertexV3(p6.coord);
         crcCriaGlVertexV3(p7.coord);
         crcCriaGlVertexV3(p8.coord);
         crcCriaGlVertexV3(p9.coord);
         crcCriaGlVertexV3(p10.coord);
         crcCriaGlVertexV3(p11.coord);
         crcCriaGlVertexV3(p12.coord);
         crcCriaGlVertexV3(p13.coord);
         crcCriaGlVertexV3(p14.coord);
         crcCriaGlVertexV3(p15.coord);
         crcCriaGlVertexV3(p16.coord);
         crcCriaGlVertexV3(p17.coord);
         crcCriaGlVertexV3(p18.coord);
         crcCriaGlVertexV3(p19.coord);
         crcCriaGlVertexV3(p20.coord);
         crcCriaGlVertexV3(p21.coord);
         crcCriaGlVertexV3(p22.coord);
         crcCriaGlVertexV3(p23.coord);
         crcCriaGlVertexV3(p24.coord);



	glEnd();


  // Desenha a malha
  glBegin(GL_TRIANGLES);
  {
    int t;
    for(t = 0; t < ntriangles; t++) {
      HE_EDGE* e = triangulos[t].edge;
      do {
          glColor3f((-minx+e->vert->x)/(maxx-minx), (-miny+e->vert->y)/(maxy-miny), (minz+e->vert->z)/(maxz-minz));
          vertex pe;
          crcInitializeV4(pe.coord);
          crcCriaV4(pe.coord, e->vert->x, e->vert->y, e->vert->z);
          crcCriaGlVertexV4(pe.coord);
          //printf("vamu lá");
          /*
          glColor3f((-minx+edge->vert->x)/(maxx-minx), (-miny+edge->vert->y)/(maxy-miny), (minz+edge->vert->z)/(maxz-minz));
          crcCriaV4(p1.coord, edge->vert->x, edge->vert->y, edge->vert->z);

          glColor3f((-minx+vert[triangulos[t].v2].x)/(maxx-minx), (-miny+vert[triangulos[t].v2].y)/(maxy-miny), (vert[triangulos[t].v2].z-minz)/(maxz-minz));
          crcCriaV4(p1.coord, vert[triangulos[t].v2].x, vert[triangulos[t].v2].y, vert[triangulos[t].v2].z);
          */
          e = e->next;
        } while (e != triangulos[t].edge);
    }
  }
  glEnd();
   // glPopMatrix();





    //////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////

    glBegin(GL_LINES);
      glColor3f(1,0,0);
      vertex l1;
      crcCriaV4(l1.coord, 0,0,0);
      crcCriaGlVertexV4(l1.coord);
      vertex l2;
      crcCriaV4(l2.coord, maxx - xm,0,0);
      crcCriaGlVertexV4(l2.coord);

      glColor3f(0,1,0);
      vertex l3;
      crcCriaV4(p3.coord, 0,0,0);
      crcCriaGlVertexV4(l3.coord);
      vertex l4;
      crcCriaV4(p4.coord, 0,maxy - ym,0);
      crcCriaGlVertexV4(l4.coord);

      glColor3f(0,0,1);
      vertex l5;
      crcCriaV4(p5.coord, 0,0,0);
      crcCriaGlVertexV4(l5.coord);
      vertex l6;
      crcCriaV4(p6.coord, 0,0,maxz - zm);
      crcCriaGlVertexV4(l6.coord);
   glEnd();
   ////////////////////////////////////////////////////////////////



    //////////////////////////////////////////////////////////////////

  // Executa os comandos OpenGL
	glutSwapBuffers();
 }

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    int dmax;
    int i, j;


    glShadeModel(GL_SMOOTH);
    /*
    for (i = 0; i <= nhalfedges; i++) {
      for (j = 0; j <= nhalfedges; j++) {
        if ((arestas[j].vert == arestas[i].next->vert) && (arestas[i].vert == arestas[j].next->vert)) {
          *(arestas[j].pair) = arestas[i];
          *(arestas[i].pair) = arestas[j];
          break;
        }
      }
    }*/

    xm = (maxx + minx)/2;
    ym = (maxy + miny)/2;
    zm = (maxz + minz)/2;

    if (fabs(maxx - minx) > fabs(maxy - miny)) dmax = fabs(maxx - minx);
    else dmax = fabs(maxy - miny);

    olho[2] = dmax/(2*tan(M_PI/8));

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle=45;
    glPolygonMode(GL_FRONT_AND_BACK,GL_POLYGON);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON){
    if (state == GLUT_DOWN) {
     k = x;
     l = y;
    }
    if (state == GLUT_UP) {
       if (x > k) angle_rot2 += (x - k);
       else if (x < k) angle_rot2 -= (k - x);
       if (y > l) angle_rot1 -= (y - l);
       else if (y < l) angle_rot1 += (l - y);
     }
    }


	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN) {
      m = x;
      n = y;
    }
    if (state == GLUT_UP) {
       if (x > m) angle_rot3 += (x - m);
       else if (x < m) angle_rot3 -= (m - x);
       if (y > n){
          olho[0] += olho[0]*0.1*(y-n)/10;
  		    olho[1] += olho[1]*0.1*(y-n)/10;
		      olho[2] += olho[2]*0.1*(y-n)/10;
        }
       else if (y < n){
          olho[0] -= olho[0]*0.1*(n-y)/10;
          olho[1] -= olho[1]*0.1*(n-y)/10;
          olho[2] -= olho[2]*0.1*(n-y)/10;
        }
     }
  }
  glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do teclado
void keyboard_callback_special(int key, int x, int y){

    switch(key){
        case 1:
            angle_rot1 -= 10;
            break;

        case 2:
            angle_rot1 += 10;
            break;

        case 3:
            angle_rot2 -= 10;
            break;

        case 4:
            angle_rot2 += 10;

            break;

        case 5:
            angle_rot3 -= 10;
            break;

        case 6:
            angle_rot3 += 10;
            break;
        default:
            break;
    }
    glutPostRedisplay();

    return;
}

// Programa Principal
int main(int argv, char** argc)
{
  int i;
  if (argv == 1) argc[1]="bunny.ply";
  CarregaMalhaPLY(argc);
    glutInit(&argv,argc);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutCreateWindow("Visualizacao de Malhas PLY");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutSpecialFunc(keyboard_callback_special);
	Inicializa();
	glutMainLoop();
	LiberaMalha();
}


