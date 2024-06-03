#include "GM_Util_Tool.h"
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
            CharacterListWidget* widget = new CharacterListWidget(
                current,
                QString(QString::fromStdString(current.getName())),
                QString(QString::fromStdString(current.getClassString())), this);
            QObject::connect(widget,&CharacterListWidget::clicked,this,&GM_Util_Tool::loadCharacterForEdit);
            layout->insertWidget(i-1,widget);
        }
    }
}
void GM_Util_Tool::on_buttonSave_clicked() {
    PlayableCharacter* currentCharacter;
    if (isCharacterLoaded) {
         currentCharacter = currentlyEditing;
    }
    else {
        newTeam.addCharacter();
        currentCharacter = &newTeam.getCharacter(newTeam.getTeamSize());
    }
    
    currentCharacter->setName(ui.inputName->text().toStdString());
    ui.inputName->clear();
    currentCharacter->setMaxHealth(ui.inputHP->text().toInt());
    currentCharacter->setCurrentHealth(ui.inputHP->text().toInt());
    ui.inputHP->clear();
    currentCharacter->setArmor(ui.inputArmor->text().toInt());
    ui.inputArmor->clear();
    currentCharacter->setAttackPotential(ui.inputAttack->text().toInt());
    ui.inputAttack->clear();
    currentCharacter->setEvadePotential(ui.inputEvasion->text().toInt());
    ui.inputEvasion->clear();
    currentCharacter->setMagical(ui.checkBoxIsMagical->isChecked());
    if (ui.checkBoxIsMagical->isChecked()) {
    currentCharacter->setSorceryPotential(ui.inputSorcery->text().toInt());
    }
    ui.checkBoxIsMagical->setChecked(false);
    ui.inputSorcery->clear();
    currentCharacter->getWeapon().setName(ui.inputWeaponName->text().toStdString());
    ui.inputWeaponName->clear();
    currentCharacter->getWeapon().setDamage(ui.inputWeaponDamage->text().toInt());
    ui.inputWeaponDamage->clear();
    currentCharacter->setDescription(ui.inputBackstory->toPlainText().toStdString());
    ui.inputBackstory->clear();
    currentCharacter->setRace((CharacterRace)ui.inputRace->currentIndex());
    ui.inputRace->setCurrentIndex(0);
    currentCharacter->setClass((CharacterClass)ui.inputProfession->currentIndex());
    ui.inputProfession->setCurrentIndex(0);
    isCharacterLoaded = false;
    createCharacterWidgets();
    //currentCharacter.saveToBinaryFile("save");
}

void GM_Util_Tool::loadCharacterForEdit( PlayableCharacter& widgetCharacter)
{
    ui.inputName->setText(QString::fromStdString(widgetCharacter.getName()));
    ui.inputHP->setText(QString::number(widgetCharacter.getMaxHealth()));
    ui.inputArmor->setText(QString::number(widgetCharacter.getArmor()));
    ui.inputAttack->setText(QString::number(widgetCharacter.getAttackPotential()));
    ui.inputEvasion->setText(QString::number(widgetCharacter.getEvadePotential()));
    if(widgetCharacter.isMagical()){
        ui.checkBoxIsMagical->setChecked(true);
        ui.inputSorcery->setText(QString::number(widgetCharacter.getSorceryPotential()));
    }
    else ui.checkBoxIsMagical->setChecked(false);
    ui.inputWeaponName->setText(QString::fromStdString(widgetCharacter.getWeapon().getName()));
    ui.inputWeaponDamage->setText(QString::number(widgetCharacter.getWeapon().getDamage()));
    ui.inputBackstory->setText(QString::fromStdString(widgetCharacter.getDescription()));
    ui.inputRace->setCurrentIndex(widgetCharacter.getRace());
    ui.inputProfession->setCurrentIndex(widgetCharacter.getClass());
    isCharacterLoaded = true;
    currentlyEditing = &widgetCharacter;
    
}
