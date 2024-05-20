#include "CharacterListWidget.h"
#include <QLabel>
#include <QVBoxLayout>

CharacterListWidget::CharacterListWidget(const QString& characterName, const QString& professionName, QWidget* parent)
    : QWidget(parent),
    characterNameLabel(new QLabel(characterName, this)),
    professionNameLabel(new QLabel(professionName, this)),
    layout(new QVBoxLayout(this))
{
    layout->addWidget(characterNameLabel);
    layout->addWidget(professionNameLabel);
    setLayout(layout);
}