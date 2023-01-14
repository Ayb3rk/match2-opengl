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
        static std::vector<glm::vec3> colors;
        int verticalPosition; // vertical position in grid system
        int horizontalPosition; // horizontal position in grid system
        float currentVerticalPosition; // current vertical position in world system
        int numberOfColumns;
        int numberOfRows;
        glm::vec3 color;
        bool isScaling;
        bool isFalling;
        float scaleFactor;
        float startingScaleFactor;
        float angle;
        glm::mat4 TranslationMatrix;

    public:
        GameObject(int, int, int, int, float);

        void setVerticalPosition(int);
        void setHorizontalPosition(int);
        void setColor(glm::vec3);
        void setTranslationMatrix(glm::mat4);
        void setScaleFactor(float);
        void setIsScaling(bool);
        void setIsFalling(bool);
        void setCurrentVerticalPosition(float);

        int getVerticalPosition();
        int getHorizontalPosition();
        float getScaleFactor();
        bool getIsScaling();
        bool getIsFalling();
        glm::mat4 getTranslationMatrix();
        glm::mat4 getModelMatrix();
        glm::vec3 getColor();

        void rotate();
        void scale();
        void reset();
        void gameReset();
};