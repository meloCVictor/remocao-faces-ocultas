#include <GL/glut.h>

// �ngulo de rota��o para simular a c�mera girando
float angleY = 0.0f;

// Fun��o de controle do teclado para rota��o
void teclado(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) angleY -= 5.0f;
    else if (key == GLUT_KEY_RIGHT) angleY += 5.0f;
    glutPostRedisplay(); // Redesenha a cena
}

// Inicializa��o do OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);     // Ativa o Z-buffer (profundidade)
    glEnable(GL_CULL_FACE);      // Ativa o culling (remo��o de faces)
    glCullFace(GL_BACK);         // Remove as faces "de tr�s"
    glFrontFace(GL_CCW);         // Define frente como anti-hor�rio
}

// Fun��o de renderiza��o
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa tela e profundidade
    glPushMatrix();
    glRotatef(angleY, 0, 1, 0); // Rotaciona a cena com base no �ngulo

    // Cubo principal
    glColor3f(0.2, 0.6, 0.8);
    glutSolidCube(1.0);

    // Segundo cubo ao lado
    glTranslatef(1.5, 0, 0);
    glColor3f(0.8, 0.3, 0.3);
    glutSolidCube(0.5);

    glPopMatrix();
    glutSwapBuffers(); // Exibe a cena
}

// Fun��o principal
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Buffers duplo, RGB e profundidade
    glutInitWindowSize(600, 600);
    glutCreateWindow("Back-Face Culling - Multiple Faces");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(teclado); // Ativa rota��o com setas
    glutMainLoop(); // Loop principal
    return 0;
}
