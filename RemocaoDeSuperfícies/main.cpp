#include <GL/glut.h>

// Ângulo de rotação para simular a câmera girando
float angleY = 0.0f;

// Função de controle do teclado para rotação
void teclado(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) angleY -= 5.0f;
    else if (key == GLUT_KEY_RIGHT) angleY += 5.0f;
    glutPostRedisplay(); // Redesenha a cena
}

// Inicialização do OpenGL
void init() {
    glEnable(GL_DEPTH_TEST);     // Ativa o Z-buffer (profundidade)
    glEnable(GL_CULL_FACE);      // Ativa o culling (remoção de faces)
    glCullFace(GL_BACK);         // Remove as faces "de trás"
    glFrontFace(GL_CCW);         // Define frente como anti-horário
}

// Função de renderização
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa tela e profundidade
    glPushMatrix();
    glRotatef(angleY, 0, 1, 0); // Rotaciona a cena com base no ângulo

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

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Buffers duplo, RGB e profundidade
    glutInitWindowSize(600, 600);
    glutCreateWindow("Back-Face Culling - Multiple Faces");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(teclado); // Ativa rotação com setas
    glutMainLoop(); // Loop principal
    return 0;
}
