#include "stdafx.h"
#include "GeneratePassword.h"

GeneratePassword::GeneratePassword(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_Generate, SIGNAL(released()), this, SLOT(clickedButton()));

	ui.lineEdit_baseNumber->setValidator(new QIntValidator());
}

void GeneratePassword::clickedButton()
{
	int baseNumber = ui.lineEdit_baseNumber->text().toInt();
	QString baseWord = ui.lineEdit_baseWord->text();
	QString domain = ui.lineEdit_Domain->text();

	if (baseWord.isEmpty() || domain.isEmpty())
	{
		ui.label_Information->setStyleSheet("color: #FF0000");
		ui.label_Information->setText("***<br>YOU HABE FILLED OUT NOT ALL FIELDS!");
	}
	else
	{
		static const int domainLen = domain.size();

		for (int i = 0; i <= domainLen; i++)
			baseWord.remove(domain[i]);

		for (int i = baseWord.size() - 1; i >= 0; i--)
			baseWord += baseWord[i];

		QString generatedPass =
			QString::number(baseNumber + domainLen) +
			domain.right(1).toUpper() +
			baseWord +
			QString::number(domainLen);

		QClipboard * c = QApplication::clipboard();

		c->clear();
		c->setText(generatedPass);

		ui.label_Information->setStyleSheet("color: #fff");
		ui.label_Information->setText("***<br>YOUR PASSWORD HAS BEEN COPIED TO THE CLIPBOARD");
	}
}