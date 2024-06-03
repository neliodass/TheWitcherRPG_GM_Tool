#include "CharacterListWidget.h"
#include <QLabel>
#include <QVBoxLayout>

CharacterListWidget::CharacterListWidget(const QString& characterName, const QString& professionName, QWidget* parent)
    : QFrame(parent),
    characterNameLabel(new QLabel(characterName, this)),
    professionNameLabel(new QLabel(professionName, this)),
    layout(new QVBoxLayout(this))
{
    this->setFrameShape(QFrame::Box);
    this->setLineWidth(2);
    this->setMinimumSize(QSize(0,65));
    this->setMaximumSize(QSize(250,65));
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    QFont nameFont = characterNameLabel->font();
    nameFont.setBold(true);
    nameFont.setPixelSize(16);
    characterNameLabel->setFont(nameFont);


    layout->addWidget(characterNameLabel);
    layout->addWidget(professionNameLabel);
    setLayout(layout);
}