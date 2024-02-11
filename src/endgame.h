#ifndef ENDGAME_H
#define ENDGAME_H

#include <QWidget>

namespace Ui {
class endgame;
}

class endgame : public QWidget
{
	Q_OBJECT

public:
	explicit endgame(bool win, QWidget *parent = nullptr);
	~endgame();

	void set_text(bool);

private slots:
	void on_btn_firstpage_clicked();

	void on_btn_leaderboard_clicked();

	void on_btn_exit_clicked();

private:
	Ui::endgame *ui;
};

#endif // ENDGAME_H
