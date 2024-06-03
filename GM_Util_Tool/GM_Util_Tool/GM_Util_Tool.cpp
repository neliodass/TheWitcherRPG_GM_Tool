﻿#include "GM_Util_Tool.h"
#include <string> 
#include <QString>
#include <iostream>
#include "CharacterListWidget.h"

GM_Util_Tool::GM_Util_Tool(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.labelSorcery->setVisible(false);
    ui.inputSorcery->setVisible(false);
    
}

GM_Util_Tool::~GM_Util_Tool()
{}
void GM_Util_Tool::on_buttonAvatarChoice_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Wybierz"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

    if (QString::compare(fileName, QString()) != 0) {
        avatarPath = fileName;
        QImage image;
        bool valid = image.load(fileName);

        if (valid) {
            image = image.scaledToWidth(ui.avatar->width(), Qt::SmoothTransformation);
            ui.avatar->setPixmap(QPixmap::fromImage(image));

            QFileInfo fileInfo(fileName);
            QString baseName = fileInfo.fileName();

            QString destinationPath = QCoreApplication::applicationDirPath() + "/" + baseName;

            if (!QFile::copy(fileName, destinationPath)) {
                qDebug() << "Błąd podczas kopiowania pliku!";
            }
            else {
                qDebug() << "Plik został skopiowany do: " << destinationPath;
            }

        }
        else {
            //something i'll add later
        }
    }
}
void GM_Util_Tool::createCharacterWidgets()
{
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui.scrollAreaWidgetContents->layout());
    if (layout) {
        int count = layout->count();
        for (int i = count - 1; i >= 0; --i) {
            QLayoutItem* item = layout->itemAt(i);
            if (item) {
                QWidget* widget = item->widget();
                if (widget && !dynamic_cast<QSpacerItem*>(item->spacerItem())) {
                    widget->deleteLater();
                }
            }
        }
    }

    if (newTeam.getTeamSize() > 0) {
        for (int i = 1; i <= newTeam.getTeamSize(); ++i) {
            PlayableCharacter& current = newTeam.getCharacter(i);
            // Tworzenie nowych widżetów CharacterWidget
            CharacterListWidget* widget = new CharacterListWidget(
                QString(QString::fromStdString(current.getName())),
                QString(QString::fromStdString(current.getClassString())), this);
            
            layout->insertWidget(i-1,widget);
        }
    }
}
void GM_Util_Tool::on_buttonSave_clicked() {
    newTeam.addCharacter();

    PlayableCharacter& currentCharacter = newTeam.getCharacter(newTeam.getTeamSize());

    currentCharacter.setName(ui.inputName->text().toStdString());
    currentCharacter.setMaxHealth(ui.inputHP->text().toInt());
    currentCharacter.setCurrentHealth(ui.inputHP->text().toInt());
    currentCharacter.setArmor(ui.inputArmor->text().toInt());
    currentCharacter.setAttackPotential(ui.inputAttack->text().toInt());
    currentCharacter.setEvadePotential(ui.inputEvasion->text().toInt());
    currentCharacter.setMagical(ui.checkBoxIsMagical->isChecked());
    if (ui.checkBoxIsMagical->isChecked()) {
    currentCharacter.setSorceryPotential(ui.inputSorcery->text().toInt());
    }
    currentCharacter.getWeapon().setName(ui.inputWeaponName->text().toStdString());
    currentCharacter.getWeapon().setDamage(ui.inputWeaponDamage->text().toInt());
    currentCharacter.setDescription(ui.inputBackstory->toPlainText().toStdString());
    currentCharacter.setRace((CharacterRace)ui.inputRace->currentIndex());
    currentCharacter.setClass((CharacterClass)ui.inputProfession->currentIndex());
    createCharacterWidgets();
    //currentCharacter.saveToBinaryFile("save");
}
