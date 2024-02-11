#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>
#include <QMessageBox>
#include <stdlib.h>
#include <time.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVector>

namespace Ui {
class sudoku;
}

class sudoku : public QWidget
{
	Q_OBJECT

public:
    explicit sudoku(QString ,QWidget *parent = nullptr);
    ~sudoku();

	void add_array(int, int);
	void del(int[], int);
	void f_rand(int[]);
	void fill_rand();

private slots:
	void on_inp1_1_textChanged();

	void on_inp1_2_textChanged();

	void on_inp1_3_textChanged();

	void on_inp1_4_textChanged();

	void on_inp1_5_textChanged();

	void on_inp1_6_textChanged();

	void on_inp1_7_textChanged();

	void on_inp1_8_textChanged();

	void on_inp1_9_textChanged();

	void on_inp2_1_textChanged();

	void on_inp2_2_textChanged();

	void on_inp2_3_textChanged();

	void on_inp2_4_textChanged();

	void on_inp2_5_textChanged();

	void on_inp2_6_textChanged();

	void on_inp2_7_textChanged();

	void on_inp2_8_textChanged();

	void on_inp2_9_textChanged();

	void on_inp3_1_textChanged();

	void on_inp3_2_textChanged();

	void on_inp3_3_textChanged();

	void on_inp3_4_textChanged();

	void on_inp3_5_textChanged();

	void on_inp3_6_textChanged();

	void on_inp3_7_textChanged();

	void on_inp3_8_textChanged();

	void on_inp3_9_textChanged();

	void on_inp4_1_textChanged();

	void on_inp4_2_textChanged();

	void on_inp4_3_textChanged();

	void on_inp4_4_textChanged();

	void on_inp4_5_textChanged();

	void on_inp4_6_textChanged();

	void on_inp4_7_textChanged();

	void on_inp4_8_textChanged();

	void on_inp4_9_textChanged();

	void on_inp5_1_textChanged();

	void on_inp5_2_textChanged();

	void on_inp5_3_textChanged();

	void on_inp5_4_textChanged();

	void on_inp5_5_textChanged();

	void on_inp5_6_textChanged();

	void on_inp5_7_textChanged();

	void on_inp5_8_textChanged();

	void on_inp5_9_textChanged();

	void on_inp6_1_textChanged();

	void on_inp6_2_textChanged();

	void on_inp6_3_textChanged();

	void on_inp6_4_textChanged();

	void on_inp6_5_textChanged();

	void on_inp6_6_textChanged();

	void on_inp6_7_textChanged();

	void on_inp6_8_textChanged();

	void on_inp6_9_textChanged();

	void on_inp7_1_textChanged();

	void on_inp7_2_textChanged();

	void on_inp7_3_textChanged();

	void on_inp7_4_textChanged();

	void on_inp7_5_textChanged();

	void on_inp7_6_textChanged();

	void on_inp7_7_textChanged();

	void on_inp7_8_textChanged();

	void on_inp7_9_textChanged();

	void on_inp8_1_textChanged();

	void on_inp8_2_textChanged();

	void on_inp8_3_textChanged();

	void on_inp8_4_textChanged();

	void on_inp8_5_textChanged();

	void on_inp8_6_textChanged();

	void on_inp8_7_textChanged();

	void on_inp8_8_textChanged();

	void on_inp8_9_textChanged();

	void on_inp9_1_textChanged();

	void on_inp9_2_textChanged();

	void on_inp9_3_textChanged();

	void on_inp9_4_textChanged();

	void on_inp9_5_textChanged();

	void on_inp9_6_textChanged();

	void on_inp9_7_textChanged();

	void on_inp9_8_textChanged();

	void on_inp9_9_textChanged();

	void on_btn_solve_clicked();

	void on_btn_finish_clicked();

	void on_btn_restart_clicked();

	void on_btn_exit_clicked();

private:
    Ui::sudoku *ui;

	int boxs[9][9] = {};
	QString name;
	QString inp;
};

#endif // sudoku_H
