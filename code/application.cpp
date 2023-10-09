#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */

    if (!glfwInit())
        return -1;



    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "xx1";
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewInit();

    
    if (glewInit() != GLEW_OK) {
        std::cout << "Error£¡" << std::endl;
   
    };
    //std::cout << glGetString(GL_VERSION) << std::endl;


    float position[6] = {
        -0.1f, -0.1f,
        0.0f, 0.1f,
        0.1f, -0.1f
    };


    //opengl is a state machine

    unsigned int buffer;
    //generate buffer && assign an id
    glGenBuffers(1,&buffer); 
    //use buffer 
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    //put data into buffer
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float),position,GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);

    //remember: buffer has so many vertex  ,vertex has so many tools 
    //so tell opengl the attribute of every tool in one vertex,
    //   then it know the layout of our buffer 

    //index:tool index,
    //size:how many element this tool use,
    //type:the attribute of every element, 
    //normalize:
    //stride:the number of how many bytes vertex use 
    //pointer:the position of this tool in one vertex
    glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE,sizeof(float)*2,0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);


   ///*     glBegin(GL_TRIANGLES);

   //     for (auto i : v) {
   //         glVertex2f(i[0]+0.1, i[1]+0.1);
   //     }
   //     glEnd();*/

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

