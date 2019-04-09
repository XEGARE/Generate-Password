#include "stdafx.h"
#include "GeneratePassword.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GeneratePassword w;

	w.setWindowTitle("Generate Password");
	
	w.setFont(QFont(":/GeneratePassword/Resources/Roboto-Regular.ttf"));
	
	w.setMinimumWidth(400);

	w.show();
	return a.exec();
}
