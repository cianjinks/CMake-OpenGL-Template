#include "imgui.h"
#include "imgui_internal.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <stb_image.h>

#include <iostream>

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        return -1;

    /* Vector Math */
    glm::vec3 v1(1.0, 2.0, 3.0);
    glm::vec3 v2(10.0, 11.0, 2.0);
    glm::vec3 v = v1 + v2;
    std::cout << "Vector Result: " << v.x << " " << v.y << " " << v.z << std::endl;

    /* Load an Image */
    int w, h, nrChannels;
    unsigned char *image = stbi_load("./resources/test_image.png", &w, &h, &nrChannels, STBI_default);
    if (!image)
        return -1;
    std::cout << "Width: " << w << " | Height: " << h << " | Channels: " << nrChannels << std::endl;

    /* Initialize ImGui */
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460 core");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* ImGui Frame */
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow();
        ImGui::Render();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

        /* ImGui Render */
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}