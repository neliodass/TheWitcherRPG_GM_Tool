#include "GM_Util_Tool.h"

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

void GM_Util_Tool::on_buttonSave_clicked() {
    newTeam.addCharacter();
    
    PlayableCharacter currentCharacter = newTeam.getCharacter(newTeam.getTeamSize() - 1);
    
    currentCharacter.setName(ui.inputName->text().toStdString());
    currentCharacter.setMaxHealth(ui.inputHP->text().toInt());
    currentCharacter.setCurrentHealth(ui.inputHP->text().toInt());
   // currentCharacter.setRace(ui.inputRace->currentText().)
   // int race = ui.inputRace->currentIndex();
    //QString profession = ui.inputProfession->currentText();
    currentCharacter.setArmor(ui.inputArmor->text().toInt());
    currentCharacter.setAttackPotential(ui.inputAttack->text().toInt());
    currentCharacter.setEvadePotential(ui.inputEvasion->text().toInt());
    currentCharacter.setMagical(ui.checkBoxIsMagical->isChecked());
    currentCharacter.setSorceryPotential(ui.inputSorcery->text().toInt());
    currentCharacter.getWeapon().setName(ui.inputWeaponName->text().toStdString());
    currentCharacter.getWeapon().setDamage(ui.inputWeaponDamage->text().toInt());
    currentCharacter.setDescription(ui.inputBackstory->toPlainText().toStdString());

    /*
    QFile file("character.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    out << name << "\n";
    out << HP << "\n";
    out << race << "\n";
    out << profession << "\n";
    out << armor << "\n";
    out << attack << "\n";
    out << evasion << "\n";
    out << isMagical << "\n";
    out << sorcery << "\n";
    out << weaponName << "\n";
    out << weaponDamage << "\n";
    out << backstory << "\n";

    file.close();
    */
}
