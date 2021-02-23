#ifndef GENERATEPASSWORD_H
#define GENERATEPASSWORD_H

#include <QMainWindow>
#include <QClipboard>

namespace Ui {
class GeneratePassword;
}

class GeneratePassword : public QMainWindow
{
    Q_OBJECT

public:
    explicit GeneratePassword(QWidget *parent = 0);
    ~GeneratePassword();

private:
    Ui::GeneratePassword *ui;

private slots:
	void ClickedGeneratePassword();
};

#endif // GENERATEPASSWORD_H
