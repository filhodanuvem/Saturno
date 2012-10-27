// main.c - Davi B. Rodrigues e Daniel L. A. Madeira
// Um programa OpenGL que exemplifica a visualização
// de malhas ply.

#include <GL/glut.h>
#include <math.h>

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
  int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  // Especifica sistema de coordenadas de projeção
   glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
	gluPerspective(angle,fAspect,0.1,500);

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

    // Especifica posição do observador e do alvo
	gluLookAt(olho[0],olho[1],olho[2],0,0,0, cima[0],cima[1],cima[2]);




    /////////////////////////////////////////////////////////
    /////Mostra o coelhinho do Davi
    glRotatef(angle_rot1, 1, 0, 0);
    glRotatef(angle_rot2, 0, 1, 0);
    glRotatef(angle_rot3, 0, 0, 1);

    glPushMatrix();
    glTranslatef(-xm, -ym, -zm);

    glColor3f(0,0,1);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

  //desenha a Bounding Box
	glBegin(GL_QUADS);
         glVertex3f(minx, miny, minz);
         glVertex3f(maxx, miny, minz);
         glVertex3f(maxx, maxy, minz);
         glVertex3f(minx, maxy, minz);

         glVertex3f(maxx, maxy, maxz);
         glVertex3f(maxx, maxy, minz);
         glVertex3f(maxx, miny, minz);
         glVertex3f(maxx, miny, maxz);

         glVertex3f(maxx, maxy, maxz);
         glVertex3f(minx, maxy, maxz);
         glVertex3f(minx, maxy, minz);
         glVertex3f(maxx, maxy, minz);

         glVertex3f(minx, miny, minz);
         glVertex3f(maxx, miny, minz);
         glVertex3f(maxx, miny, maxz);
         glVertex3f(minx, miny, maxz);

         glVertex3f(maxx, maxy, maxz);
         glVertex3f(minx, maxy, maxz);
         glVertex3f(minx, miny, maxz);
         glVertex3f(maxx, miny, maxz);

         glVertex3f(minx, miny, minz);
         glVertex3f(minx, miny, maxz);
         glVertex3f(minx, maxy, maxz);
         glVertex3f(minx, maxy, minz);

	glEnd();


  // Desenha a malha
  glBegin(GL_TRIANGLES);
  {
    int t;
    for(t = 0; t < ntriangles; t++) {
      HE_EDGE* e = triangulos[t].edge;
      do {
          glColor3f((-minx+e->vert->x)/(maxx-minx), (-miny+e->vert->y)/(maxy-miny), (minz+e->vert->z)/(maxz-minz));
          glVertex3f(e->vert->x, e->vert->y, e->vert->z);
          /*
          glColor3f((-minx+edge->vert->x)/(maxx-minx), (-miny+edge->vert->y)/(maxy-miny), (minz+edge->vert->z)/(maxz-minz));
          glVertex3f(edge->vert->x, edge->vert->y, edge->vert->z);

          glColor3f((-minx+vert[triangulos[t].v2].x)/(maxx-minx), (-miny+vert[triangulos[t].v2].y)/(maxy-miny), (vert[triangulos[t].v2].z-minz)/(maxz-minz));
          glVertex3f(vert[triangulos[t].v2].x, vert[triangulos[t].v2].y, vert[triangulos[t].v2].z);
          */
          e = e->next;
        } while (e != triangulos[t].edge);
    }
  }
  glEnd();
    glPopMatrix();





    //////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////

    glBegin(GL_LINES);
      glColor3f(1,0,0);
      glVertex3f(0,0,0);
      glVertex3f(maxx - xm,0,0);

      glColor3f(0,1,0);
      glVertex3f(0,0,0);
      glVertex3f(0,maxy - ym,0);

      glColor3f(0,0,1);
      glVertex3f(0,0,0);
      glVertex3f(0,0,maxz - zm);
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


