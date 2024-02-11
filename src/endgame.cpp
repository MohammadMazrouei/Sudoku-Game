#include "endgame.h"
#include "ui_endgame.h"
#include "leaderboard.h"
#include "mainwindow.h"


endgame::endgame(bool win, QWidget *parent) :
	QWidget(parent),
	ui(new Ui::endgame)
{
	ui->setupUi(this);
	set_text(win);
}

endgame::~endgame()
{
	delete ui;
}


void endgame::set_text(bool w)
{
	if (w)
	{
		this->ui->textedit->setText("You Solve This Sodoku");
	}
	else
        this->ui->textedit->setText("You Can't Solve sudoku");
}


void endgame::on_btn_firstpage_clicked()
{
	MainWindow * mw = new MainWindow();
	mw->show();
	this->close();
}


void endgame::on_btn_leaderboard_clicked()
{
	leaderBoard * lb = new leaderBoard();
	lb->show();
	this->close();
}


void endgame::on_btn_exit_clicked()
{
	this->close();
}

