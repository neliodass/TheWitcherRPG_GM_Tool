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
    currentCharacter.setArmor(ui.inputArmor->text().toInt());
    currentCharacter.setAttackPotential(ui.inputAttack->text().toInt());
    currentCharacter.setEvadePotential(ui.inputEvasion->text().toInt());
    currentCharacter.setMagical(ui.checkBoxIsMagical->isChecked());
    currentCharacter.setSorceryPotential(ui.inputSorcery->text().toInt());
    currentCharacter.getWeapon().setName(ui.inputWeaponName->text().toStdString());
    currentCharacter.getWeapon().setDamage(ui.inputWeaponDamage->text().toInt());
    currentCharacter.setDescription(ui.inputBackstory->toPlainText().toStdString());
    int race = ui.inputRace->currentIndex();
    switch (race) {
    case 1:
        currentCharacter.setRace(human);
        break;
    case 2:
        currentCharacter.setRace(werebbubb);
        break;
    case 3:
        currentCharacter.setRace(elf);
        break;
    case 4:
        currentCharacter.setRace(gnome);
        break;
    case 5:
        currentCharacter.setRace(dwarf);
        break;
    case 6:
        currentCharacter.setRace(halfling);
        break;
    case 7:
        currentCharacter.setRace(vran);
        break;
    }
    int profession = ui.inputProfession->currentIndex();
    switch (profession) {
    case 1:
        currentCharacter.setClass(bard);
        break;
    case 2:
        currentCharacter.setClass(mage);
        break;
    case 3:
        currentCharacter.setClass(druid);
        break;
    case 4:
        currentCharacter.setClass(priest);
        break;
    case 5:
        currentCharacter.setClass(merchant);
        break;
    case 6:
        currentCharacter.setClass(doctor);
        break;
    case 7:
        currentCharacter.setClass(criminal);
        break;
    case 8:
        currentCharacter.setClass(merchant);
        break;
    case 9:
        currentCharacter.setClass(noble);
        break;
    case 10:
        currentCharacter.setClass(witcher);
        break;
    case 11:
        currentCharacter.setClass(man_at_arms);
        break;
    }
}
