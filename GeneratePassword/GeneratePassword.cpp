#include "generatepassword.h"
#include "ui_generatepassword.h"

GeneratePassword::GeneratePassword(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GeneratePassword)
{
    ui->setupUi(this);

	QRegExpValidator *numberValidator=new QRegExpValidator(QRegExp("^[0-9]+$"),this);
	ui->secretNumberInput->setValidator(numberValidator);

	QObject::connect(ui->generatePasswordButton,&QPushButton::released,this,&GeneratePassword::ClickedGeneratePassword);
}

GeneratePassword::~GeneratePassword()
{
    delete ui;
}

void GeneratePassword::ClickedGeneratePassword()
{

	if(ui->secretNumberInput->text().isEmpty())
	{
		ui->statusBar->showMessage("Secret number not entered",5000);
		return;
	}

	if(ui->secretWordInput->text().isEmpty())
	{
		ui->statusBar->showMessage("Secret word not entered",5000);
		return;
	}

	if(ui->domainInput->text().isEmpty())
	{
		ui->statusBar->showMessage("Domain not entered",5000);
		return;
	}

	if(!ui->generateType1->isChecked() && !ui->generateType2->isChecked())
	{
		ui->statusBar->showMessage("Generate type not selected",5000);
		return;
	
	}

	QString generatedPassword="";

	int secretNumber=ui->secretNumberInput->text().toInt();
	QString secretWord=ui->secretWordInput->text();
	QString domain=ui->domainInput->text();

	int domainLength=domain.length();

	for(int i=0; i < domainLength; i++)
		secretWord.remove(domain[i]);

	if(ui->generateType1->isChecked())
	{
		int secretWordLength=secretWord.length()-1;

		for(int i=secretWordLength; i >= 0; i--)
			secretWord.append(secretWord[i]);

		generatedPassword=
			QString::number(secretNumber + domainLength) +
			domain.right(1).toUpper() +
			secretWord +
			QString::number(domainLength);
	}
	else if(ui->generateType2->isChecked())
	{
		int sum=secretNumber+domainLength;

		QString newSecretWord="";
		int secretWordLength=secretWord.length();

		for(int i=0; i < secretWordLength; i++)
		{
			newSecretWord.append(secretWord[i]);
			newSecretWord.append(secretWord[secretWordLength-i-1]);
		}

		generatedPassword=
			QString::number(sum) +
			newSecretWord +
			QString::number(int(sum/2)) +
			domain.left(1).toUpper();
	}

	if(!generatedPassword.isEmpty())
	{
		QClipboard *c=QApplication::clipboard();
		c->clear();
		c->setText(generatedPassword);

		generatedPassword.clear();

		ui->statusBar->showMessage("Your password has been copied to the clipboard",5000);
	}
}