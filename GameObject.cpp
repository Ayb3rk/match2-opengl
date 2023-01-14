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
    this->currentVerticalPosition = 0.0f;
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
    glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1.f), glm::vec3(-10.0f, 10.0f, 0.f));
    glm::mat4 ScaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(this->scaleFactor, this->scaleFactor, this->scaleFactor));
    glm::mat4 RotationMatrix = glm::rotate(glm::mat4(1.f), glm::radians(this->angle), glm::vec3(0, 1, 0));

    float verticalPos = -(verticalPosition+0.5f) * (20.f / numberOfRows);
    if(this->isFalling)
    {
        if(verticalPos > this->currentVerticalPosition) { // end of the fall
            this->isFalling = false;
            this->currentVerticalPosition = 0.0f;
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

void GameObject::setIsScaling(bool isScaling)
{
    this->isScaling = isScaling;
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
}

void GameObject::setCurrentVerticalPosition(float currentVerticalPosition)
{
    this->currentVerticalPosition = currentVerticalPosition;
}

std::vector<glm::vec3> GameObject::colors = {glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f)};
