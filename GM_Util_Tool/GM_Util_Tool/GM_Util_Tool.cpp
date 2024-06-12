#pragma warning(disable : 4703)

#include "CharacterListWidget.h"
#include "DarkStyleSheet.h"
#include "exception_handling.h"
#include "GM_Util_Tool.h"
#include "MedivalStyleSheet.h"
#include <iostream>
#include <QMessageBox>
#include <QString>
#include <string>

GM_Util_Tool::GM_Util_Tool(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowIcon(QIcon("./resources/thewitcher.ico"));
	ui.labelSorcery->setVisible(false);
	ui.inputSorcery->setVisible(false);
	ui.buttonDelete->setDisabled(true);
	setValidation();
}

GM_Util_Tool::~GM_Util_Tool()
{}

void GM_Util_Tool::on_buttonAvatarChoice_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

	if (QString::compare(fileName, QString()) != 0) {
		avatarPath = fileName;
		QImage image;
		bool valid = image.load(fileName);

		if (valid) {
			image = image.scaledToWidth(ui.avatar->width(), Qt::SmoothTransformation);
			ui.avatar->setPixmap(QPixmap::fromImage(image));
		}
		else {
			ExceptionMessageBox error;
			error.setWindowTitle("Corrupted image");
			error.setText("Your image is corrupted");
			error.exec();
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

	if (newTeam.getTeamSize() > 0)
	{
		for (int i = 1; i <= newTeam.getTeamSize(); ++i)
		{
			PlayableCharacter& current = newTeam.getCharacter(i);
			current.setTempId(i);
			CharacterListWidget* widget = new CharacterListWidget(
				current,
				QString(QString::fromStdString(current.getName())),
				QString(QString::fromStdString(current.getClassString())), this);
			QObject::connect(widget, &CharacterListWidget::clicked, this, &GM_Util_Tool::loadCharacterForEdit);
			layout->insertWidget(i - 1, widget);
			widget->adjustSize();
		}
	}
}
void GM_Util_Tool::on_buttonSave_clicked()
{
	int exception = characterSaveExceptions(*this);
	if (exception == -1) {
		return;
	}
	ui.buttonDelete->setDisabled(true);
	PlayableCharacter* currentCharacter = nullptr;
	if (isCharacterLoaded)
	{
		currentCharacter = currentlyEditing;
	}
	else
	{
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
	if (ui.checkBoxIsMagical->isChecked())
	{
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

void GM_Util_Tool::loadCharacterForEdit(PlayableCharacter& widgetCharacter)
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
	if (widgetCharacter.isMagical())
	{
		ui.checkBoxIsMagical->setChecked(true);
		ui.inputSorcery->setText(QString::number(widgetCharacter.getSorceryPotential()));
	}
	else
	{
		ui.checkBoxIsMagical->setChecked(false);
	}
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
	QString filter = "Save Files (*.sav)";
	QString fileName = QFileDialog::getSaveFileName(this, "Save team", QDir::homePath(), filter);
	std::cout << fileName.toStdString();
	if (!fileName.isEmpty())
	{
		qDebug() << "File to save:" << fileName;
		newTeam.saveToBinaryFile(fileName.toStdString());
	}
	else
	{
		qDebug() << "Save file dialog was canceled.";
	}
	clearUi();
}

void GM_Util_Tool::on_readTeamFileButton_clicked()
{
	QString filter = "Save Files (*.sav)";
	QString fileName = QFileDialog::getOpenFileName(this, "Read team", QDir::homePath(), filter);

	if (!fileName.isEmpty())
	{
		if (newTeam.readFromBinaryFile(fileName.toStdString()))
		{
			createCharacterWidgets();
		}
		else
		{
			createCharacterWidgets();
			ExceptionMessageBox error;
			error.setWindowTitle("Corrupted file");
			error.setText("Your file is corrupted");
			error.exec();
		}
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
	if (isCharacterLoaded)
	{
		newTeam.removeCharacter(currentlyEditing->getTempId());
		isCharacterLoaded = false;
		currentlyEditing = nullptr;
		clearUi();
		createCharacterWidgets();
	}
}

void GM_Util_Tool::set_style()
{
	DarkStyleSheet medival;
	//Buttons
	ui.buttonAvatarChoice->setStyleSheet(medival.buttonAvatar);
	ui.buttonDeleteAvatar->setStyleSheet(medival.buttonAvatar);
	ui.buttonDelete->setStyleSheet(medival.buttonCharacter);
	ui.buttonSave->setStyleSheet(medival.buttonCharacter);
	ui.readTeamFileButton->setStyleSheet(medival.buttonTeam);
	ui.saveTeamFileButton->setStyleSheet(medival.buttonTeam);
	//Main backgrounds
	ui.tabWidget->setStyleSheet(medival.tab);
	this->setStyleSheet(medival.mainBackground);
	ui.frameCharacterCreator->setStyleSheet(medival.frameCharacter);
	//Labels
	ui.labelAge->setStyleSheet(medival.normalLabel);
	ui.labelArmor->setStyleSheet(medival.normalLabel);
	ui.labelAttack->setStyleSheet(medival.normalLabel);
	ui.labelBackstory->setStyleSheet(medival.backstoryLabel);
	ui.labelEvasion->setStyleSheet(medival.normalLabel);
	ui.labelHP->setStyleSheet(medival.normalLabel);
	ui.labelK6->setStyleSheet(medival.normalLabel);
	ui.labelName->setStyleSheet(medival.normalLabel);
	ui.labelProfession->setStyleSheet(medival.normalLabel);
	ui.labelRace->setStyleSheet(medival.normalLabel);
	ui.labelSorcery->setStyleSheet(medival.normalLabel);
	ui.labelWeaponDamage->setStyleSheet(medival.normalLabel);
	ui.labelWeaponName->setStyleSheet(medival.normalLabel);
	ui.labelTitle->setStyleSheet(medival.titleLabel);
	//Standard input boxes
	ui.checkBoxIsMagical->setStyleSheet(medival.checkBox);
	ui.inputAge->setStyleSheet(medival.normalInput);
	ui.inputArmor->setStyleSheet(medival.normalInput);
	ui.inputAttack->setStyleSheet(medival.normalInput);
	ui.inputBackstory->setStyleSheet(medival.normalInput);
	ui.inputEvasion->setStyleSheet(medival.normalInput);
	ui.inputHP->setStyleSheet(medival.normalInput);
	ui.inputName->setStyleSheet(medival.normalInput);
	ui.inputSorcery->setStyleSheet(medival.normalInput);
	ui.inputWeaponDamage->setStyleSheet(medival.normalInput);
	ui.inputWeaponName->setStyleSheet(medival.normalInput);
	ui.inputRace->setStyleSheet(medival.comboBoxInput);
	ui.inputProfession->setStyleSheet(medival.comboBoxInput);
	//Avatar related
	ui.avatar->setStyleSheet(medival.avatarBackground);
	ui.frameAvatar->setStyleSheet(medival.frameAvatar);
	//Backstory
	ui.inputBackstory->setStyleSheet(medival.backstory);
	//Team scroll area
	ui.characterListArea->setStyleSheet(medival.scrollArea);
}

void GM_Util_Tool::setValidation()
{
	ui.inputAge->setValidator(ageValidator);
	ui.inputHP->setValidator(statValidator);
	ui.inputArmor->setValidator(statValidator);
	ui.inputAttack->setValidator(statValidator);
	ui.inputEvasion->setValidator(statValidator);
	ui.inputSorcery->setValidator(statValidator);
	ui.inputWeaponDamage->setValidator(statValidator);
}