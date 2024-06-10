#include "CharacterListWidget.h"
#include"PlayableCharacter.h"
#include "ui_stylization.h"
#include<iostream>
#include <QLabel>
#include <QVBoxLayout>

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
	this->setStyleSheet(MedivalStyleSheet().characterList);
}