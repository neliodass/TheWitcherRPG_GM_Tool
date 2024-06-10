#pragma once
#ifndef CHARACTERWIDGET_H
#define CHARACTERWIDGET_H
#include <QFrame>
#include<QLabel>
#include<QVBoxLayout>
#include"PlayableCharacter.h"

class CharacterListWidget :
	public QFrame
{
	Q_OBJECT
signals:
	void clicked(PlayableCharacter& widgetCharacter);

public:
	explicit CharacterListWidget(PlayableCharacter& widgetCharacter, const QString& characterName, const QString& professionName, QWidget* parent = nullptr);
	PlayableCharacter& widgetCharacter;
	void mousePressEvent(QMouseEvent* event) override
	{
		emit clicked(widgetCharacter);
	}
private:
	QLabel* characterNameLabel;
	QLabel* professionNameLabel;
	QVBoxLayout* layout;
};

#endif