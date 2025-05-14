#include <GL/glut.h>

// Ângulo da "câmera"
float angleY = 0.0f;

// Controle de rotação com teclas
void teclado(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) angleY -= 5.0f;
    else if (key == GLUT_KEY_RIGHT) angleY += 5.0f;
    glutPostRedisplay();
}

// Inicialização com Z-buffer
void init() {
    glEnable(GL_DEPTH_TEST); // Ativa profundidade
}

// Desenha cubo em posição (x, z) com cor RGB
void drawCube(float x, float z, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, 0.0f, z);
    glColor3f(r, g, b);
    glutSolidCube(0.8);
    glPopMatrix();
}

// Cena com três cubos em profundidades diferentes
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angleY, 0, 1, 0);

    drawCube(-1.0f, -3.0f, 1.0f, 0.0f, 0.0f); // Vermelho - fundo
    drawCube( 0.0f, -2.0f, 0.0f, 1.0f, 0.0f); // Verde - meio
    drawCube( 1.0f, -1.0f, 0.0f, 0.0f, 1.0f); // Azul - frente

    glPopMatrix();
    glutSwapBuffers();
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Profundidade ativada
    glutInitWindowSize(600, 600);
    glutCreateWindow("Z-Buffer - Multiple Objects");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(teclado);
    glutMainLoop();
    return 0;
}
