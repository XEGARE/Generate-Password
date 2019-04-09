#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GeneratePassword.h"

class GeneratePassword : public QMainWindow
{
	Q_OBJECT

public:
	GeneratePassword(QWidget *parent = Q_NULLPTR);

private slots:
	void clickedButton();

private:
	Ui::GeneratePasswordClass ui;
};
