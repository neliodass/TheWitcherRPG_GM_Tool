#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "ui_app.h"

class app : public QMainWindow
{
    Q_OBJECT

public:
    app(QWidget *parent = nullptr);
    ~app();

public slots:
    void on_buttonAvatarChoice_clicked();
    void on_buttonSave_clicked();

private:
    Ui::appClass ui;
    QString avatarPath = "";
};
