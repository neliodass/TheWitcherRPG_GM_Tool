#include "GM_Util_Tool.h"
#include "CharacterListWidget.h"
#include "ui_stylization.h"
#include "exception_handling.h"
#include <string> 
#include <QString>
#include <iostream>

GM_Util_Tool::GM_Util_Tool(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.labelSorcery->setVisible(false);
    ui.inputSorcery->setVisible(false);
    ui.buttonDelete->setDisabled(true);
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
            current.setTempId(i);
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
    int exception = characterSaveExceptions(*this);
    if (exception == -1) {
        return;
    }
    ui.buttonDelete->setDisabled(true);
    PlayableCharacter* currentCharacter;
    if (isCharacterLoaded) {
         currentCharacter = currentlyEditing;
    }
    else {
        newTeam.addCharacter();
        currentCharacter = &newTeam.getCharacter(newTeam.getTeamSize());
    }
    if (!ui.avatar->pixmap().isNull())
    {
        QPixmap pixmap = ui.avatar->pixmap();
        currentCharacter->setCharacterImage(pixmap.toImage());
    }
   
    
    currentCharacter->setName(ui.inputName->text().toStdString());
    currentCharacter->setAge(ui.inputAge->text().toInt());
    currentCharacter->setMaxHealth(ui.inputHP->text().toInt());
    currentCharacter->setCurrentHealth(ui.inputHP->text().toInt());
    currentCharacter->setArmor(ui.inputArmor->text().toInt());
    currentCharacter->setAttackPotential(ui.inputAttack->text().toInt());
    currentCharacter->setEvadePotential(ui.inputEvasion->text().toInt());
    currentCharacter->setMagical(ui.checkBoxIsMagical->isChecked());
    if (ui.checkBoxIsMagical->isChecked()) {
    currentCharacter->setSorceryPotential(ui.inputSorcery->text().toInt());
    }
    currentCharacter->getWeapon().setName(ui.inputWeaponName->text().toStdString());
    currentCharacter->getWeapon().setDamage(ui.inputWeaponDamage->text().toInt());
    currentCharacter->setDescription(ui.inputBackstory->toPlainText().toStdString());
    currentCharacter->setRace((CharacterRace)ui.inputRace->currentIndex());
    currentCharacter->setClass((CharacterClass)ui.inputProfession->currentIndex());
    isCharacterLoaded = false;
    clearUi();
    createCharacterWidgets();
    
}

void GM_Util_Tool::loadCharacterForEdit( PlayableCharacter& widgetCharacter)
{
    if (!widgetCharacter.getCharacterImage().isNull())
    {
        ui.avatar->setPixmap(QPixmap::fromImage(widgetCharacter.getCharacterImage()));
    }
    else
    {
        ui.avatar->clear();
    }
    ui.inputName->setText(QString::fromStdString(widgetCharacter.getName()));
    ui.inputAge->setText(QString::number(widgetCharacter.getAge()));
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
    ui.buttonDelete->setDisabled(false);
    
    
}

void GM_Util_Tool::on_saveTeamFileButton_clicked()
{
    QString filter = "Save Files (*.sav);;All Files (*)";
    QString fileName = QFileDialog::getSaveFileName(this, "Zapisz team", QDir::homePath(), filter);
    std::cout << fileName.toStdString();
    if (!fileName.isEmpty()) {
        qDebug() << "File to save:" << fileName;
        newTeam.saveToBinaryFile(fileName.toStdString());
    }
    else {
        qDebug() << "Save file dialog was canceled.";
    }
    clearUi();
}

void GM_Util_Tool::on_readTeamFileButton_clicked()
{
    QString filter = "Save Files (*.sav);;All Files (*)";
    QString fileName = QFileDialog::getOpenFileName(this, "Wczytaj team", QDir::homePath(), filter);

    if (!fileName.isEmpty()) {
        newTeam.readFromBinaryFile(fileName.toStdString());
        createCharacterWidgets();
        
    }
    else {
        qDebug() << "Open file dialog was canceled.";
    }
    clearUi();
}

void GM_Util_Tool::on_buttonDeleteAvatar_clicked()
{

    ui.avatar->clear();
    PlayableCharacter* currentCharacter;
    if (isCharacterLoaded) {
        currentCharacter = currentlyEditing;
        currentCharacter->setCharacterImage(QImage());
    }
}

void GM_Util_Tool::clearUi()
{
    ui.avatar->clear();
    ui.inputName->clear();
    ui.inputAge->clear();
    ui.inputHP->clear();
    ui.inputArmor->clear();
    ui.inputAttack->clear();
    ui.inputEvasion->clear();
    ui.checkBoxIsMagical->setChecked(false);
    ui.inputSorcery->clear();
    ui.inputWeaponName->clear();
    ui.inputWeaponDamage->clear();
    ui.inputBackstory->clear();
    ui.inputRace->setCurrentIndex(0);
    ui.inputProfession->setCurrentIndex(0);
}

void GM_Util_Tool::on_buttonDelete_clicked()
{
    if (isCharacterLoaded) {
        newTeam.removeCharacter(currentlyEditing->getTempId());
        isCharacterLoaded = false;
        currentlyEditing = nullptr;
        clearUi();
        createCharacterWidgets();
    }
    


}

void GM_Util_Tool::set_style() {
    //Buttons
    ui.buttonAvatarChoice->setStyleSheet(buttonAvatar);
    ui.buttonDeleteAvatar->setStyleSheet(buttonAvatar);
    ui.buttonDelete->setStyleSheet(buttonCharacter);
    ui.buttonSave->setStyleSheet(buttonCharacter);
    ui.readTeamFileButton->setStyleSheet(buttonTeam);
    ui.saveTeamFileButton->setStyleSheet(buttonTeam);
    //Main backgrounds
    ui.tabWidget->setStyleSheet(tab);
    this->setStyleSheet(mainBackground);
    ui.frameCharacterCreator->setStyleSheet(frameCharacter);
    //Labels
    ui.labelAge->setStyleSheet(normalLabel);
    ui.labelArmor->setStyleSheet(normalLabel);
    ui.labelAttack->setStyleSheet(normalLabel);
    ui.labelBackstory->setStyleSheet(backstoryLabel);
    ui.labelEvasion->setStyleSheet(normalLabel);
    ui.labelHP->setStyleSheet(normalLabel);
    ui.labelK6->setStyleSheet(normalLabel);
    ui.labelName->setStyleSheet(normalLabel);
    ui.labelProfession->setStyleSheet(normalLabel);
    ui.labelRace->setStyleSheet(normalLabel);
    ui.labelSorcery->setStyleSheet(normalLabel);
    ui.labelWeaponDamage->setStyleSheet(normalLabel);
    ui.labelWeaponName->setStyleSheet(normalLabel);
    ui.labelTitle->setStyleSheet(titleLabel);
    //Standard input boxes
    ui.checkBoxIsMagical->setStyleSheet(checkBox);
    ui.inputAge->setStyleSheet(normalInput);
    ui.inputArmor->setStyleSheet(normalInput);
    ui.inputAttack->setStyleSheet(normalInput);
    ui.inputBackstory->setStyleSheet(normalInput);
    ui.inputEvasion->setStyleSheet(normalInput);
    ui.inputHP->setStyleSheet(normalInput);
    ui.inputName->setStyleSheet(normalInput);
    ui.inputSorcery->setStyleSheet(normalInput);
    ui.inputWeaponDamage->setStyleSheet(normalInput);
    ui.inputWeaponName->setStyleSheet(normalInput);
    ui.inputRace->setStyleSheet(comboBoxInput);
    ui.inputProfession->setStyleSheet(comboBoxInput);
    //Avatar related
    ui.avatar->setStyleSheet(avatarBackground);
    ui.frameAvatar->setStyleSheet(frameAvatar);
    //Backstory
    ui.inputBackstory->setStyleSheet(backstory);
    //Team scroll area
    ui.characterListArea->setStyleSheet(scrollArea);
}