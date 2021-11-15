#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main() {
	using namespace UV::maths;

	UV::graphics::Window window("Ultra Violet", 960, 540);
	glClearColor(0.2f, 0.5f, 1, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	mat4 position = mat4::translation(vec3(2, 3, 4));

	while (!window.closed()) {
		window.clear();

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f,  0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}