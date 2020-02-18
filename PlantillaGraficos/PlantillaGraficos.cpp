// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

using namespace std;

void dibujarPoligonos() {

	glBegin(GL_POLYGON);

	glColor3f(0.7f, 0.5f, 1.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.5f);
	glVertex3f(0.2f, 0.3f, 0.0f);
	glVertex3f(0.2f, -0.4f, 0.0f);
	glVertex3f(0.4f, -0.6f, 0.0f);

	glEnd();
}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.2f, 0.0f, 0.0f);

	glColor3f(0.3f, 0.7f, 1.0f);
	glVertex3f(0.2f, 0.15f, 0.0f);


	glEnd();
}

void dibujarLineaContinua() {
	glBegin(GL_LINE_STRIP);
	glColor3f(0.1f,0.3f,0.75f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.2f, 0.0f);

	glVertex3f(0.2f, 0.0f, 0.0f);

	glVertex3f(0.2f, 0.4f, 0.0f);

	glEnd();
}

void dibujarLineas() {
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.4f, 0.6f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, -0.4f, 0.0f);

	glVertex3f(-0.3f, 0.1f, 0.0f);
	glVertex3f(-0.3f, 0.4f, 0.0f);

	glEnd();
}

void dibujarTriangulos(){
		// establecems tipo de primitiva
	glBegin(GL_TRIANGLES);
	//establecemos el color
	glColor3f(0.3f, 0.7f, 1.0f);
	//enviar vértices
	glVertex3f(0.0f, 0.7f, 0.0f);
	glColor3f(0.7f, 0.1f, 7.0f);
	glVertex3f(-0.7f, -0.7f, 0.0f);
	glColor3f(1.0f, 0.1f, 7.0f);
	glVertex3f(0.7f, -0.7f, 0.0f);

	glColor3f(0.0f, 0.7f, 0.8f);
	glVertex3f(-0.8f, 0.8f, 0.0f);
	glVertex3f(-0.3f, 0.3f, 0.0f);
	glVertex3f(-0.8f, 0.3f, 0.0f);

	glVertex3f(-0.3f, 0.8f, 0.0f);
	glVertex3f(-0.3f, 0.3f, 0.0f);
	glVertex3f(-0.8f, 0.8f, 0.0f);

	//Especificar que dejaremos de dibujar
	glEnd();
}

//la rutina del dibujo
void dibujar() {
	dibujarPoligonos();
}

int main()
{
   //Declarar una vetana
	GLFWwindow* window;
	
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
		dibujar();
		//pa poder usar el mouse
		glfwPollEvents();
		 
		glfwSwapBuffers(window);
	}

	//Despues del ciclo de dibujo eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();

}


