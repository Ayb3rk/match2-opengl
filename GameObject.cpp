#include "GameObject.h"

GameObject::GameObject(int verticalPosition, int horizontalPosition, glm::vec3 color, float scaleFactor, glm::mat4 TranslationMatrix, glm::mat4 RotationMatrix)
{
    this->verticalPosition = verticalPosition;
    this->horizontalPosition = horizontalPosition;
    this->color = color;
    this->scaleFactor = scaleFactor;
    this->TranslationMatrix = TranslationMatrix;
    this->RotationMatrix = RotationMatrix;
    this->isFalling = false;
    this->isScaling = false;
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

void GameObject::setRotationMatrix(glm::mat4 RotationMatrix)
{
    this->RotationMatrix = RotationMatrix;
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

glm::mat4 GameObject::getRotationMatrix()
{
    return this->RotationMatrix;
}

glm::mat4 GameObject::getModelMatrix()
{
    glm::mat4 ScaleMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(this->scaleFactor, this->scaleFactor, this->scaleFactor));
    return this->TranslationMatrix * this->RotationMatrix * ScaleMatrix;
}

void GameObject::rotate()
{
    this->RotationMatrix = glm::rotate(this->RotationMatrix, glm::radians(0.5f), glm::vec3(0.0f, 1.0f, 0.0f));
}

void GameObject::scale()
{
    this->scaleFactor *= 1.01;
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

