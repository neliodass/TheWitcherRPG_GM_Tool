#pragma once
#ifndef CHARACTERWIDGET_H
#define CHARACTERWIDGET_H
#include <QFrame>
#include"PlayableCharacter.h"
class QLabel;
class QVBoxLayout;
class CharacterListWidget :
    public QFrame
{
    Q_OBJECT
signals:
    void clicked( PlayableCharacter& widgetCharacter);

public:
    explicit CharacterListWidget(PlayableCharacter& widgetCharacter,const QString& characterName, const QString& professionName, QWidget* parent = nullptr);
    PlayableCharacter& widgetCharacter;
    void onWidgetClicked();
    void mousePressEvent(QMouseEvent* event) override {
        emit clicked(widgetCharacter); // Emituj sygna³, gdy widget zostanie klikniêty
    }
private:
    
    QLabel* characterNameLabel;
    QLabel* professionNameLabel;
    QVBoxLayout* layout;
};

#endif // CHARACTERWIDGET_H