#pragma once
#ifndef CHARACTERWIDGET_H
#define CHARACTERWIDGET_H
#include <QWidget>
class QLabel;
class QVBoxLayout;
class CharacterListWidget :
    public QWidget
{
    Q_OBJECT

public:
    explicit CharacterListWidget(const QString& characterName, const QString& professionName, QWidget* parent = nullptr);

private:
    QLabel* characterNameLabel;
    QLabel* professionNameLabel;
    QVBoxLayout* layout;
};

#endif // CHARACTERWIDGET_H