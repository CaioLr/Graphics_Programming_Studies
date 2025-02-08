#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main ()
{
    if (!glfwInit()){
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640,480,"Test",NULL,NULL);

    if (!window){
        std::cout << "Failed to create window" << std::endl; 
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
    
    if (!gladLoadGL()){
        glfwTerminate();
        return -1;
    }

    const char* vertexShaderSrc =
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main(){\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
        "}\0";

    const char* fragmentShaderSrc =
        "#version 330 core\n"
        "out vec4 fragColor;\n"
        "void main(){\n"
        "   fragColor = vec4(0.0f, 1.0f, 1.0f, 1.0f);\n"
        "}\0";


    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSrc,0);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, 0, infoLog);
        std::cout << "ERR: " << infoLog << std::endl;
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1 , &fragmentShaderSrc, 0);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, 0, infoLog);
        std::cout << "ERR: " << infoLog << std::endl;
    }

    while (!glfwWindowShouldClose(window)){

        processInput(window);

        glClearColor(0.2f,0.4f,0.5f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window){

    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){

    glViewport(0,0,width,height);
}