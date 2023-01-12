#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <GL/glew.h>   // The GL Header File
#include <GL/gl.h>   // The GL Header File
#include <GLFW/glfw3.h> // The GLFW header
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

class GameObject
{
    private:
        int verticalPosition; // vertical position in grid system
        int horizontalPosition; // horizontal position in grid system
        glm::vec3 color;
        bool isScaling;
        bool isFalling;
        float scaleFactor;
        glm::mat4 TranslationMatrix;
        glm::mat4 RotationMatrix;

    public:
        GameObject(int, int, glm::vec3, float, glm::mat4, glm::mat4);
        void setVerticalPosition(int);
        void setHorizontalPosition(int);
        void setColor(glm::vec3);
        void setTranslationMatrix(glm::mat4);
        void setRotationMatrix(glm::mat4);
        void setScaleFactor(float);
        void setIsScaling(bool);

        int getVerticalPosition();
        int getHorizontalPosition();
        glm::vec3 getColor();
        float getScaleFactor();
        glm::mat4 getTranslationMatrix();
        glm::mat4 getRotationMatrix();
        glm::mat4 getModelMatrix();
        bool getIsScaling();

        void rotate();
        void scale();
};