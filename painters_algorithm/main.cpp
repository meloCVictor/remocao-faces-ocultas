#include <GL/glut.h>

// Ângulo de rotação
float angleY = 0.0f;

// Controle de rotação com teclado
void teclado(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) angleY -= 5.0f;
    else if (key == GLUT_KEY_RIGHT) angleY += 5.0f;
    glutPostRedisplay();
}

// Inicialização: sem z-buffer, sem culling
void init() {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
}

// Função para desenhar um quadrado colorido em profundidade Z
void drawQuad(float z, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex3f(-0.5, -0.5, z);
    glVertex3f( 0.5, -0.5, z);
    glVertex3f( 0.5,  0.5, z);
    glVertex3f(-0.5,  0.5, z);
    glEnd();
}

// Desenha a cena com ordem manual dos polígonos
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angleY, 0, 1, 0); // Rotaciona a cena

    drawQuad(-1.0f, 0.0f, 0.0f, 1.0f); // Azul (mais longe)
    drawQuad(-0.8f, 0.0f, 1.0f, 0.0f); // Verde (meio)
    drawQuad(-0.6f, 1.0f, 0.0f, 0.0f); // Vermelho (mais próximo)

    glPopMatrix();
    glutSwapBuffers();
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Sem profundidade
    glutInitWindowSize(600, 600);
    glutCreateWindow("Painter's Algorithm - Manual Order");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(teclado);
    glutMainLoop();
    return 0;
}
