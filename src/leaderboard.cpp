#include "leaderboard.h"
#include "ui_leaderboard.h"
#include "sudoku.h"
#include "mainwindow.h"

#define address "/home/mohammad/Documents/University/Projects/sudoku_game/Sudoku-Game/src/leaderboard.txt"


leaderBoard::leaderBoard(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::leaderBoard)
{
	ui->setupUi(this);
	this->ui->lb_names->setReadOnly(true);
	this->ui->lb_wins->setReadOnly(true);
}

leaderBoard::~leaderBoard()
{
	delete ui;
}


void leaderBoard::on_btn_show_clicked()
{
	QFile file(address);

	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, "title", "File Not Open");
		return;
	}

	QTextStream in(&file);
	QVector<QString> users;
	QVector<int> wins;
	QString line;

	while (!in.atEnd())
	{
		line = in.readLine();
		users.push_back(line.split(" ")[0]);
		wins.push_back((line.split(" ")[1]).toInt());
	}


	this->ui->lb_names->clear();
	this->ui->lb_wins->clear();
	for (int i = 0; i < users.size(); i++)
	{
		this->ui->lb_names->appendPlainText(QString::number(i+1));
		if (i < 9)
			this->ui->lb_names->insertPlainText(".    ");
		else
			this->ui->lb_names->insertPlainText(".  ");

		this->ui->lb_names->insertPlainText(users[i]);
		this->ui->lb_wins->appendPlainText(QString::number(wins[i]));
	}
	this->ui->lb_names->setReadOnly(true);
	this->ui->lb_wins->setReadOnly(true);

	file.close();
}


void leaderBoard::on_btn_firstpage_clicked()
{
	MainWindow * mw = new MainWindow();
	mw->show();
	this->close();
}


void leaderBoard::on_btn_exit_clicked()
{
	this->close();
}

