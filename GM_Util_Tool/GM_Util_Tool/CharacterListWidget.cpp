#include "CharacterListWidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include"PlayableCharacter.h"
#include<iostream>
#include "ui_stylization.h"

CharacterListWidget::CharacterListWidget(PlayableCharacter& widgetCharacter, const QString& characterName, const QString& professionName, QWidget* parent)
    : QFrame(parent),
    widgetCharacter(widgetCharacter),
    characterNameLabel(new QLabel(characterName, this)),
    professionNameLabel(new QLabel(professionName, this)),
    layout(new QVBoxLayout(this))
{
    
    layout->addWidget(characterNameLabel);
    layout->addWidget(professionNameLabel);
    setLayout(layout);
    this->setStyleSheet(characterList);
}

