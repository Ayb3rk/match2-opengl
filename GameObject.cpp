#include "GameObject.h"

GameObject::GameObject(int verticalPosition, int horizontalPosition, int numberOfColumns, int numberOfRows, float scaleFactor)
{
    this->verticalPosition = verticalPosition;
    this->horizontalPosition = horizontalPosition;
    this->numberOfColumns = numberOfColumns;
    this->numberOfRows = numberOfRows;
    this->color = colors[rand() % colors.size()];
    this->scaleFactor = scaleFactor;
    this->startingScaleFactor = scaleFactor;
    this->angle = 0.0f;
    this->isFalling = false;
    this->isScaling = false;
    this->currentVerticalPosition = -(verticalPosition+0.5f) * (20.f / numberOfRows);
    this->isExploded = false;
}

void GameObject::setVerticalPosition(int verticalPosition)
{
    this->verticalPosition = verticalPosition;
}

void GameObject::setHorizontalPosition(int horizontalPosition)
{
    this->horizontalPosition = horizontalPosition;
}

void GameObject::setColor(glm::vec3 color)
{
    this->color = color;
}

void GameObject::setTranslationMatrix(glm::mat4 TranslationMatrix)
{
    this->TranslationMatrix = TranslationMatrix;
}

int GameObject::getVerticalPosition()
{
    return this->verticalPosition;
}

int GameObject::getHorizontalPosition()
{
    return this->horizontalPosition;
}

glm::vec3 GameObject::getColor()
{
    return this->color;
}

glm::mat4 GameObject::getTranslationMatrix()
{
    return this->TranslationMatrix;
}

glm::mat4 GameObject::getModelMatrix()
{
    if(this->isScaling)
    {
        this->scale();
    }

    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1.f), glm::vec3(-10.0f, 10.0f, 0.f));
    glm::mat4 ScaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(this->scaleFactor, this->scaleFactor, this->scaleFactor));
    glm::mat4 RotationMatrix = glm::rotate(glm::mat4(1.f), glm::radians(this->angle), glm::vec3(0, 1, 0));

    float verticalPos = -(verticalPosition+0.5f) * (20.f / numberOfRows);
    if(this->isFalling)
    {
        if(verticalPos > this->currentVerticalPosition) { // end of the fall
            this->isFalling = false;
            this->currentVerticalPosition = -(verticalPosition+0.5f) * (20.f / numberOfRows);
        }
        else { // still falling
            verticalPos = this->currentVerticalPosition;
            this->currentVerticalPosition -= 0.05f;
        }
    }

    TranslationMatrix *= glm::translate(glm::mat4(1.f), glm::vec3((horizontalPosition+0.5f) * (20.f / numberOfColumns), verticalPos, 0.f));
    
    return TranslationMatrix * RotationMatrix * ScaleMatrix;
}

void GameObject::rotate()
{
    this->angle += 0.5f;
}

void GameObject::scale()
{
    this->scaleFactor *= 1.01f;
}

void GameObject::setIsScaling(bool isScaling, bool isMouseClick)
{
    this->isScaling = isScaling;
    if(isMouseClick)
    {
        moves++;
    }
    else{
        score++;
    }
}

bool GameObject::getIsScaling()
{
    return this->isScaling;
}

float GameObject::getScaleFactor()
{
    return this->scaleFactor;
}

void GameObject::setScaleFactor(float scaleFactor)
{
    this->scaleFactor = scaleFactor;
}

void GameObject::setIsFalling(bool isFalling)
{
    this->isFalling = isFalling;
}

bool GameObject::getIsFalling()
{
    return this->isFalling;
}

void GameObject::reset()
{
    this->scaleFactor = this->startingScaleFactor;
    this->isScaling = false;
    this->isFalling = true;
    this->angle = 0.0f;
    this->color = colors[rand() % colors.size()];
    this->isExploded = true;
}

void GameObject::gameReset()
{
    this->scaleFactor = this->startingScaleFactor;
    this->isScaling = false;
    this->isFalling = false;
    this->angle = 0.0f;
    this->color = colors[rand() % colors.size()];
    this->isExploded = false;
}

void GameObject::setCurrentVerticalPosition(float currentVerticalPosition)
{
    this->currentVerticalPosition = currentVerticalPosition;
}
bool GameObject::getIsExploded()
{
    return this->isExploded;
}

void GameObject::setIsExploded(bool isExploded)
{
    this->isExploded = isExploded;
}

std::vector<glm::vec3> GameObject::colors = {glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(0.8f, 0.8f, 0.8f)};
