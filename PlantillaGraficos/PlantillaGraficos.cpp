// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

using namespace std;

GLFWwindow* window;
float posXTriangulo = 0.0f, posYTriangulo = 0.0f;
float posXPiedra1 = -0.5f, posYPiedra1 = 0.5f;
float posXPiedra2 = -0.6f, posYPiedra2 = -0.4f;
float posXPiedra3 = 0.6f, posYPiedra3 = 0.0f;
//ESTRELLAS POS
float posXE = -0.85f, posYE =-0.85f;

float rotacionTriangulo = 0.0f;
double tiempoActual, tiempoAnterior;
double velocidadTriangulo = 0.8;
double velocidadRotacion = 1000;
float rojoTriangulo = 1.0f;

void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS || GLFW_REPEAT && key == GLFW_KEY_RIGHT) {
		posXTriangulo += 0.01;
	}

	if (action == GLFW_PRESS || GLFW_REPEAT && key == GLFW_KEY_LEFT) {
		posXTriangulo -= 0.01;
	}
	if (action == GLFW_PRESS || GLFW_REPEAT && key == GLFW_KEY_UP) {
		posYTriangulo += 0.01;
	}
	if (action == GLFW_PRESS || GLFW_REPEAT && key == GLFW_KEY_DOWN) {
		posYTriangulo -= 0.01;
	}
}

void actualizar() {
	tiempoActual = glfwGetTime();
	// Sacamos el DeltaTime
	double tiempoDiferencial = tiempoActual - tiempoAnterior;

	// Estados para cada tecla
	// Calcular el movimiento dependiendo del angulo de rotacion
	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		posYTriangulo += (velocidadTriangulo * sin((rotacionTriangulo + 90.0) * 3.1416 / 180)) * tiempoDiferencial;
		posXTriangulo += (velocidadTriangulo * cos((rotacionTriangulo + 90.0) * 3.1416 / 180)) * tiempoDiferencial;
	}

	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {
		posYTriangulo -= (velocidadTriangulo * sin((rotacionTriangulo + 90.0) * 3.1416 / 180)) * tiempoDiferencial;
		posXTriangulo -= (velocidadTriangulo * cos((rotacionTriangulo + 90.0) * 3.1416 / 180)) * tiempoDiferencial;
	}

	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		rotacionTriangulo += velocidadRotacion * tiempoDiferencial;
	}

	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		rotacionTriangulo -= velocidadRotacion * tiempoDiferencial;
	}

	// Reset angulo
	if (rotacionTriangulo >= 360) {
		rotacionTriangulo = 0;
	}

	if (rotacionTriangulo <= -360) {
		rotacionTriangulo = 0;
	}

	tiempoAnterior = tiempoActual;
}

void dibujarFondo() {
	glBegin(GL_POLYGON);

	glColor3f(0.02352941f, 0.08627451f, 0.18823529f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glColor3f(0.09019608f, 0.49019608f, 0.44705882f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glEnd();


}

void dibujarEstrellas() {

	

	glPushMatrix();

	glTranslatef(-.8f,.5f,0.0f);
	glScalef(0.2f,0.2f,0.3f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//2
	glPushMatrix();

	glTranslatef(-.9f, -.5f, 0.0f);
	glScalef(0.2f, 0.2f, 0.3f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//3
	glPushMatrix();

	glTranslatef(.6f, -.8f, 0.0f);
	glScalef(0.2f, 0.2f, 0.3f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//4
	glPushMatrix();

	glTranslatef(-.8f, -.2f, 0.0f);
	glScalef(0.2f, 0.2f, 0.3f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//5
	glPushMatrix();

	glTranslatef(-.2f, .14f, 0.0f);
	glScalef(0.1f, 0.1f, 0.1f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//6
	glPushMatrix();

	glTranslatef(.6f, .8f, 0.0f);
	glScalef(0.15f, 0.15f, 0.15f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//7
	glPushMatrix();

	glTranslatef(.9f, .3f, 0.0f);
	glScalef(0.2f, 0.2f, 0.3f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//8
	glPushMatrix();

	glTranslatef(-.2f, .0f, 0.0f);
	glScalef(0.1f, 0.1f, 0.1f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();
//9
	glPushMatrix();

	glTranslatef(.2f, -.5f, 0.0f);
	glScalef(0.2f, 0.2f, 0.3f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//10
	glPushMatrix();

	glTranslatef(.8f, -.1f, 0.0f);
	glScalef(0.2f, 0.2f, 0.3f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//11
	glPushMatrix();

	glTranslatef(.0f, -.6f, 0.0f);
	glScalef(0.1f, 0.1f, 0.1f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//12
	glPushMatrix();

	glTranslatef(.5f, -.56f, 0.0f);
	glScalef(0.1f, 0.1f, 0.1f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//13
	glPushMatrix();

	glTranslatef(-.6f, -.8f, 0.0f);
	glScalef(0.18f, 0.18f, 0.18f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//14
	glPushMatrix();

	glTranslatef(.7f, .7f, 0.0f);
	glScalef(0.12f, 0.12f, 0.13f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();

	//15
	glPushMatrix();

	glTranslatef(-.85f, -.85f, 0.0f);
	glScalef(0.4f, 0.4f, 0.3f);

	glBegin(GL_POLYGON);

	glColor3f(0.96470588f, 0.59607843f, 0.60392157f);

	glVertex3f(0.0f, 0.3f, 0.0f);
	glVertex3f(0.08f, 0.09f, 0.5f);
	glColor3f(0.98431373f, 0.95686275f, 0.61176471f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.08f, 0.09f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.30588235f, 0.74117647f, 0.58039216f);

	glVertex3f(0.08f, 0.09f, 0.0f);
	glVertex3f(0.3f, 0.09f, 0.5f);
	glColor3f(0.98431373f, 0.95686275f, 0.61176471f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.98431373f, 0.95686275f, 0.61176471f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.12f, -0.05f, 0.0f);
	
	glColor3f(0.62529412f, 0.44313725f, 0.6941765f);
	glVertex3f(0.2f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.98431373f, 0.95686275f, 0.61176471f);

	glVertex3f(-0.12f, -0.05f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glColor3f(0.68235294f, 1.0f, 1.0f);
	glVertex3f(0.0f, -0.17f, 0.0f);
	glVertex3f(-0.2f, -0.3f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.98431373f, 0.95686275f, 0.61176471f);

	glVertex3f(-0.3f, 0.09f, 0.5f);
	glVertex3f(-0.08f, 0.09f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.12f, -0.05f, 0.0f);

	glEnd();

	glPopMatrix();


}

void checarColisiones() {

	if ((posXTriangulo + .10f >= posXPiedra1 - .10f && posXTriangulo - .15f <= posXPiedra1 + 0.10 && posYTriangulo + 0.10f >= posYPiedra1 - .15f && posYTriangulo - 0.10f <= posYPiedra1 + 0.10f)	||
		
		(posXTriangulo + .05f >= posXPiedra2 - .05f && posXTriangulo - .05f <= posXPiedra2 + 0.10 && posYTriangulo + 0.15f >= posYPiedra2 - .15f && posYTriangulo - 0.15f <= posYPiedra2 + 0.15f) || 
		(posXTriangulo + .15f >= posXPiedra3 - .15f && posXTriangulo - .15f <= posXPiedra3 + 0.15 && posYTriangulo + 0.20f >= posYPiedra3 - .20f && posYTriangulo - 0.20f <= posYPiedra3 + 0.20f) ||
		posXTriangulo + .05f>= posXE - .05f && posXTriangulo - .05f <= posXE + 0.05 && posYTriangulo + 0.05f >= posYE - .05f && posYTriangulo - .05f <= posYE + .05f) {
		rojoTriangulo = 0.5f;
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	else  {
		rojoTriangulo = 1.0f;

	}

	/*if (posXTriangulo + .05f >= posXPiedra2 - .05f && posXTriangulo - .05f <= posXPiedra2 + 0.10 && posYTriangulo + 0.15f >= posYPiedra2 - .15f && posYTriangulo - 0.15f <= posYPiedra2 + 0.15f) {
		rojoTriangulo = 0.0f;
		/*glfwDestroyWindow(window);
		glfwTerminate();
	}
	else {
		rojoTriangulo = 1.0f;
	}*/
}


void dibujarObstaculos() {

	glPushMatrix();

	glTranslatef(-0.5f,0.5f,0.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.63529412f,0.5333333f,0.458882353f);
	glVertex3f(-0.2f,0.0f,0.0f);
	glVertex3f(0.0f, 0.4f, 0.0f);
	glVertex3f(0.2f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	//glVertex3f(-0.2f, 0.2f, 0.0f);
	glEnd();

	glPopMatrix(); 

	glPushMatrix();

	glTranslatef(posXPiedra2, posYPiedra2, 0.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.63529412f, 0.5333333f, 0.458882353f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.4f, 0.0f);
	glVertex3f(-0.2f, 0.0f, 0.0f);
	
	glEnd();

	glPopMatrix();

	glPushMatrix();

	glTranslatef(posXPiedra3, posYPiedra3, 0.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.63529412f, 0.5333333f, 0.458882353f);
	glVertex3f(-0.2f, 0.4f, 0.0f);
	glVertex3f(0.2f, 0.45f, 0.0f);
	glVertex3f(0.1f, -0.3f, 0.0f);
	glVertex3f(0.0f, -0.3f, 0.0f);
	glVertex3f(-0.2f, 0.0f, 0.0f);

	glEnd();

	glPopMatrix();
}

void dibujar() {
	glPushMatrix();

	// Loopear al triangulo al llegar limite de la ventana
	if (posXTriangulo >= 1.15) {
		posXTriangulo = -1.1;
	}
	if (posXTriangulo <= -1.15) {
		posXTriangulo = 1.1;
	}

	if (posYTriangulo >= 1.15) {
		posYTriangulo = -1.1;
	}
	if (posYTriangulo <= -1.15) {
		posYTriangulo = 1.1;
	}

	glTranslatef(posXTriangulo, posYTriangulo, 0.0f);

	glRotatef(rotacionTriangulo, 0, 0, 1);  // rotate your object
	glScalef(0.4f, 0.7f, 0.0f);

	glBegin(GL_TRIANGLES);

	glColor3f(rojoTriangulo, 1.0f, 1.0f);

	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);

	glEnd();

	glPopMatrix();
}

int main()
{
 
	
	//si no se pudo inicializar glfw terminamos la ejecución

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	//Si se pudo inicial glfw, se inicia la ventana

	window = glfwCreateWindow(600,600, "ventana",NULL, NULL);

	// si no se pudo crear la ventana, terminamos la ejecución

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto, se activan las funciones modernas (gpu)
	glewExperimental = true;

	//Imprimir posibles errores

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version openGL" << versionGL;

	//ciclo de dibujo (Draw loop)

	while (!glfwWindowShouldClose(window))
	{
		//establecer la región de dibujo
		glViewport(0, 0, 600, 600);
		//establecemos el color de borrado, valores rgba, van de 0 a 1
		glClearColor(1,.21,.7,1);
		//Borrar!  Con el borrar solo se hace el swap der buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//Actualizar valores y dibujar
		actualizar();
		dibujarFondo();
		dibujarObstaculos();
		dibujarEstrellas();
		dibujar();
		checarColisiones();
		

		//pa poder usar el mouse
		glfwPollEvents();
		 
		glfwSwapBuffers(window);
	}

	//Despues del ciclo de dibujo eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();

}


