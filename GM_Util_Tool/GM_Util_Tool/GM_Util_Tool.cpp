#include "GM_Util_Tool.h"

GM_Util_Tool::GM_Util_Tool(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.labelSorcery->setVisable(false);
    ui.inputSorcery->setVisable(false);
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
    QString name = ui.inputName->text();
    QString HP = ui.inputHP->text();
    QString race = ui.inputRace->currentText();
    QString profession = ui.inputProfession->currentText();
    QString armor = ui.inputArmor->text();
    QString attack = ui.inputAttack->text();
    QString evasion = ui.inputEvasion->text();
    bool isMagical = ui.checkBoxIsMagical->isChecked();
    QString sorcery = ui.inputSorcery->text();
    QString weaponName = ui.inputWeaponName->text();
    QString weaponDamage = ui.inputWeaponDamage->text();
    QString backstory = ui.inputBackstory->toPlainText();

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

}