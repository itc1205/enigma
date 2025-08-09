#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdint.h>
#include <cstring>

#undef ENIGMA_LOG_INFO

#include <log.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);
void register_callbacks();
void close_window();


typedef struct {
	char title[256];
	int16_t height;
	int16_t width;
	void (*keymappings[GLFW_KEY_LAST])(void);
	GLFWwindow* window_handle;
} enigma_storage_t;

enigma_storage_t enigma_storage;

int main() {
	strcpy(&enigma_storage.title[0], "Hello, there, again.");
	enigma_storage.height = 800;
	enigma_storage.width = 600;

	register_callbacks();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	enigma_storage.window_handle = glfwCreateWindow(enigma_storage.width, enigma_storage.height, enigma_storage.title, NULL, NULL);
	if (enigma_storage.window_handle == NULL) {
		printf("Could not open window.\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(enigma_storage.window_handle);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		printf("Could not initialize GLAD.\n");
		return 2;
	}


	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(enigma_storage.window_handle, framebuffer_size_callback);

	while (!glfwWindowShouldClose(enigma_storage.window_handle)) {
		process_input(enigma_storage.window_handle);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(enigma_storage.window_handle);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}

void register_callbacks() {
	enigma_storage.keymappings[GLFW_KEY_ESCAPE] = close_window; 
}

void close_window() {
	log_info("closing window");
}

void process_input(GLFWwindow* window) {
	if (glfwGetKey(enigma_storage.window_handle, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(enigma_storage.window_handle, true);
		enigma_storage.keymappings[GLFW_KEY_ESCAPE]();
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	// printf("[LOG]: changing size of window into %dx%d\n", width, height);
	glViewport(0, 0, width, height);
}
