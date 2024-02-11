#include "sudoku.h"
#include "ui_sudoku.h"
#include "endgame.h"
#include "mainwindow.h"

#define address "/home/mohmammad/Desktop/Term 2/MiniProject 2/mini-project-2-sudoku-Mohammadmx/sudoku/LeaderBoard.txt"


sudoku::sudoku(QString n, QWidget *parent) :
	QWidget(parent),
    ui(new Ui::sudoku)
{
	ui->setupUi(this);
	fill_rand();
	name = n;
}

sudoku::~sudoku()
{
	delete ui;
}


void sudoku::add_array(int w, int l)
{
	int i, j;
	i = ((w / 3) * 3) + (l / 3);
	j = ((w % 3) * 3) + (l % 3);
	if (inp.size() == 1 && inp[0] <= 57 && inp[0] >= 49)
		boxs[i][j] = inp.toInt();
	else
		boxs[i][j] = 0;
}


void sudoku::del(int arr[9] , int index)
{
	for (int i = index+1; i < 9; i++)
		arr[i-1] = arr[i];
}


void sudoku::f_rand(int arr[9])
{
	int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int j = 9, random;
	for (int i = 0; i < 9; i++)
	{
		srand(time(0));
		random = rand() % j--;
		arr[i] = numbers[random];
		del(numbers, random);
	}
}


void sudoku::fill_rand()
{
	QTextEdit * inputs[9][9] =
	{
		{
			this->ui->inp1_1 ,
			this->ui->inp1_2 ,
			this->ui->inp1_3 ,
			this->ui->inp1_4 ,
			this->ui->inp1_5 ,
			this->ui->inp1_6 ,
			this->ui->inp1_7 ,
			this->ui->inp1_8 ,
			this->ui->inp1_9
		},
		{
			this->ui->inp2_1 ,
			this->ui->inp2_2 ,
			this->ui->inp2_3 ,
			this->ui->inp2_4 ,
			this->ui->inp2_5 ,
			this->ui->inp2_6 ,
			this->ui->inp2_7 ,
			this->ui->inp2_8 ,
			this->ui->inp2_9
		},
		{
			this->ui->inp3_1 ,
			this->ui->inp3_2 ,
			this->ui->inp3_3 ,
			this->ui->inp3_4 ,
			this->ui->inp3_5 ,
			this->ui->inp3_6 ,
			this->ui->inp3_7 ,
			this->ui->inp3_8 ,
			this->ui->inp3_9
		},
		{
			this->ui->inp4_1 ,
			this->ui->inp4_2 ,
			this->ui->inp4_3 ,
			this->ui->inp4_4 ,
			this->ui->inp4_5 ,
			this->ui->inp4_6 ,
			this->ui->inp4_7 ,
			this->ui->inp4_8 ,
			this->ui->inp4_9
		},
		{
			this->ui->inp5_1 ,
			this->ui->inp5_2 ,
			this->ui->inp5_3 ,
			this->ui->inp5_4 ,
			this->ui->inp5_5 ,
			this->ui->inp5_6 ,
			this->ui->inp5_7 ,
			this->ui->inp5_8 ,
			this->ui->inp5_9
		},
		{
			this->ui->inp6_1 ,
			this->ui->inp6_2 ,
			this->ui->inp6_3 ,
			this->ui->inp6_4 ,
			this->ui->inp6_5 ,
			this->ui->inp6_6 ,
			this->ui->inp6_7 ,
			this->ui->inp6_8 ,
			this->ui->inp6_9
		},
		{
			this->ui->inp7_1 ,
			this->ui->inp7_2 ,
			this->ui->inp7_3 ,
			this->ui->inp7_4 ,
			this->ui->inp7_5 ,
			this->ui->inp7_6 ,
			this->ui->inp7_7 ,
			this->ui->inp7_8 ,
			this->ui->inp7_9
		},
		{
			this->ui->inp8_1 ,
			this->ui->inp8_2 ,
			this->ui->inp8_3 ,
			this->ui->inp8_4 ,
			this->ui->inp8_5 ,
			this->ui->inp8_6 ,
			this->ui->inp8_7 ,
			this->ui->inp8_8 ,
			this->ui->inp8_9
		},
		{
			this->ui->inp9_1 ,
			this->ui->inp9_2 ,
			this->ui->inp9_3 ,
			this->ui->inp9_4 ,
			this->ui->inp9_5 ,
			this->ui->inp9_6 ,
			this->ui->inp9_7 ,
			this->ui->inp9_8 ,
			this->ui->inp9_9
		}
	};
	int places[9][9] =
	{
		{0, 6, 3, 2, 8, 5, 1, 7, 4},
		{1, 7, 4, 0, 6, 3, 2, 8, 5},
		{2, 8, 5, 1, 7, 4, 0, 6, 3},
		{3, 0, 6, 5, 2, 8, 4, 1, 7},
		{4, 1, 7, 3, 0, 6, 5, 2, 8},
		{5, 2, 8, 4, 1, 7, 3, 0, 6},
		{6, 3, 0, 8, 5, 2, 7, 4, 1},
		{7, 4, 1, 6, 3, 0, 8, 5, 2},
		{8, 5, 2, 7, 4, 1, 6, 3, 0}
	};

	int random_numbers[9];
	f_rand(random_numbers);

	srand(time(0));
	int rand1 = rand() % 9;

	for (int i = 0; i < 9; i++)
	{
		inputs[i][places[i][rand1]]->setTextColor("green");
		inputs[i][places[i][rand1]]->setPlainText(QString::number(random_numbers[i]));
		boxs[i][places[i][rand1]] = random_numbers[i];
		inputs[i][places[i][rand1]]->setReadOnly(true);
		if (i < 8 && rand1 < 8)
		{
			inputs[i+1][places[i+1][rand1+1]]->setTextColor("green");
			inputs[i+1][places[i+1][rand1+1]]->setPlainText(QString::number(random_numbers[i]));
			boxs[i+1][places[i+1][rand1+1]] = random_numbers[i];
			inputs[i+1][places[i+1][rand1+1]]->setReadOnly(true);
		}
		if (i < 7 && rand1 < 7)
		{
			inputs[i+2][places[i+2][rand1+2]]->setTextColor("green");
			inputs[i+2][places[i+2][rand1+2]]->setPlainText(QString::number(random_numbers[i]));
			boxs[i+2][places[i+2][rand1+2]] = random_numbers[i];
			inputs[i+2][places[i+2][rand1+2]]->setReadOnly(true);
		}
		if (i < 6 && rand1 < 6)
		{
			inputs[i+3][places[i+3][rand1+3]]->setTextColor("green");
			inputs[i+3][places[i+3][rand1+3]]->setPlainText(QString::number(random_numbers[i]));
			boxs[i+3][places[i+3][rand1+3]] = random_numbers[i];
			inputs[i+3][places[i+3][rand1+3]]->setReadOnly(true);
		}
		if (i < 5 && rand1 < 5)
		{
			inputs[i+4][places[i+4][rand1+4]]->setTextColor("green");
			inputs[i+4][places[i+4][rand1+4]]->setPlainText(QString::number(random_numbers[i]));
			boxs[i+4][places[i+4][rand1+4]] = random_numbers[i];
			inputs[i+4][places[i+4][rand1+4]]->setReadOnly(true);
		}
		if (i < 4 && rand1 < 4)
		{
			inputs[i+5][places[i+5][rand1+5]]->setTextColor("green");
			inputs[i+5][places[i+5][rand1+5]]->setPlainText(QString::number(random_numbers[i]));
			boxs[i+5][places[i+5][rand1+5]] = random_numbers[i];
			inputs[i+5][places[i+5][rand1+5]]->setReadOnly(true);
		}
	}
}


// box1
void sudoku::on_inp1_1_textChanged()
{
	inp = this->ui->inp1_1->toPlainText();
	add_array(0, 0);
}

void sudoku::on_inp1_2_textChanged()
{
	inp = this->ui->inp1_2->toPlainText();
	add_array(0, 1);
}

void sudoku::on_inp1_3_textChanged()
{
	inp = this->ui->inp1_3->toPlainText();
	add_array(0, 2);
}

void sudoku::on_inp1_4_textChanged()
{
	inp = this->ui->inp1_4->toPlainText();
	add_array(0, 3);
}

void sudoku::on_inp1_5_textChanged()
{
	inp = this->ui->inp1_5->toPlainText();
	add_array(0, 4);
}

void sudoku::on_inp1_6_textChanged()
{
	inp = this->ui->inp1_6->toPlainText();
	add_array(0, 5);
}

void sudoku::on_inp1_7_textChanged()
{
	inp = this->ui->inp1_7->toPlainText();
	add_array(0, 6);
}

void sudoku::on_inp1_8_textChanged()
{
	inp = this->ui->inp1_8->toPlainText();
	add_array(0, 7);
}

void sudoku::on_inp1_9_textChanged()
{
	inp = this->ui->inp1_9->toPlainText();
	add_array(0, 8);
}

// box2
void sudoku::on_inp2_1_textChanged()
{
	inp = this->ui->inp2_1->toPlainText();
	add_array(1, 0);
}

void sudoku::on_inp2_2_textChanged()
{
	inp = this->ui->inp2_2->toPlainText();
	add_array(1, 1);
}

void sudoku::on_inp2_3_textChanged()
{
	inp = this->ui->inp2_3->toPlainText();
	add_array(1, 2);
}

void sudoku::on_inp2_4_textChanged()
{
	inp = this->ui->inp2_4->toPlainText();
	add_array(1, 3);
}

void sudoku::on_inp2_5_textChanged()
{
	inp = this->ui->inp2_5->toPlainText();
	add_array(1, 4);
}

void sudoku::on_inp2_6_textChanged()
{
	inp = this->ui->inp2_6->toPlainText();
	add_array(1, 5);
}

void sudoku::on_inp2_7_textChanged()
{
	inp = this->ui->inp2_7->toPlainText();
	add_array(1, 6);
}

void sudoku::on_inp2_8_textChanged()
{
	inp = this->ui->inp2_8->toPlainText();
	add_array(1, 7);
}

void sudoku::on_inp2_9_textChanged()
{
	inp = this->ui->inp2_9->toPlainText();
	add_array(1, 8);
}

// box3
void sudoku::on_inp3_1_textChanged()
{
	inp = this->ui->inp3_1->toPlainText();
	add_array(2, 0);
}

void sudoku::on_inp3_2_textChanged()
{
	inp = this->ui->inp3_2->toPlainText();
	add_array(2, 1);
}

void sudoku::on_inp3_3_textChanged()
{
	inp = this->ui->inp3_3->toPlainText();
	add_array(2, 2);
}

void sudoku::on_inp3_4_textChanged()
{
	inp = this->ui->inp3_4->toPlainText();
	add_array(2, 3);
}

void sudoku::on_inp3_5_textChanged()
{
	inp = this->ui->inp3_5->toPlainText();
	add_array(2, 4);
}

void sudoku::on_inp3_6_textChanged()
{
	inp = this->ui->inp3_6->toPlainText();
	add_array(2, 5);
}

void sudoku::on_inp3_7_textChanged()
{
	inp = this->ui->inp3_7->toPlainText();
	add_array(2, 6);
}

void sudoku::on_inp3_8_textChanged()
{
	inp = this->ui->inp3_8->toPlainText();
	add_array(2, 7);
}

void sudoku::on_inp3_9_textChanged()
{
	inp = this->ui->inp3_9->toPlainText();
	add_array(2, 8);
}

// box4
void sudoku::on_inp4_1_textChanged()
{
	inp = this->ui->inp4_1->toPlainText();
	add_array(3, 0);
}

void sudoku::on_inp4_2_textChanged()
{
	inp = this->ui->inp4_2->toPlainText();
	add_array(3, 1);
}

void sudoku::on_inp4_3_textChanged()
{
	inp = this->ui->inp4_3->toPlainText();
	add_array(3, 2);
}

void sudoku::on_inp4_4_textChanged()
{
	inp = this->ui->inp4_4->toPlainText();
	add_array(3, 3);
}

void sudoku::on_inp4_5_textChanged()
{
	inp = this->ui->inp4_5->toPlainText();
	add_array(3, 4);
}

void sudoku::on_inp4_6_textChanged()
{
	inp = this->ui->inp4_6->toPlainText();
	add_array(3, 5);
}

void sudoku::on_inp4_7_textChanged()
{
	inp = this->ui->inp4_7->toPlainText();
	add_array(3, 6);
}

void sudoku::on_inp4_8_textChanged()
{
	inp = this->ui->inp4_8->toPlainText();
	add_array(3, 7);
}

void sudoku::on_inp4_9_textChanged()
{
	inp = this->ui->inp4_9->toPlainText();
	add_array(3, 8);
}

// box5
void sudoku::on_inp5_1_textChanged()
{
	inp = this->ui->inp5_1->toPlainText();
	add_array(4, 0);
}

void sudoku::on_inp5_2_textChanged()
{
	inp = this->ui->inp5_2->toPlainText();
	add_array(4, 1);
}

void sudoku::on_inp5_3_textChanged()
{
	inp = this->ui->inp5_3->toPlainText();
	add_array(4, 2);
}

void sudoku::on_inp5_4_textChanged()
{
	inp = this->ui->inp5_4->toPlainText();
	add_array(4, 3);
}

void sudoku::on_inp5_5_textChanged()
{
	inp = this->ui->inp5_5->toPlainText();
	add_array(4, 4);
}

void sudoku::on_inp5_6_textChanged()
{
	inp = this->ui->inp5_6->toPlainText();
	add_array(4, 5);
}

void sudoku::on_inp5_7_textChanged()
{
	inp = this->ui->inp5_7->toPlainText();
	add_array(4, 6);
}

void sudoku::on_inp5_8_textChanged()
{
	inp = this->ui->inp5_8->toPlainText();
	add_array(4, 7);
}

void sudoku::on_inp5_9_textChanged()
{
	inp = this->ui->inp5_9->toPlainText();
	add_array(4, 8);
}

// box6
void sudoku::on_inp6_1_textChanged()
{
	inp = this->ui->inp6_1->toPlainText();
	add_array(5, 0);
}

void sudoku::on_inp6_2_textChanged()
{
	inp = this->ui->inp6_2->toPlainText();
	add_array(5, 1);
}

void sudoku::on_inp6_3_textChanged()
{
	inp = this->ui->inp6_3->toPlainText();
	add_array(5, 2);
}

void sudoku::on_inp6_4_textChanged()
{
	inp = this->ui->inp6_4->toPlainText();
	add_array(5, 3);
}

void sudoku::on_inp6_5_textChanged()
{
	inp = this->ui->inp6_5->toPlainText();
	add_array(5, 4);
}

void sudoku::on_inp6_6_textChanged()
{
	inp = this->ui->inp6_6->toPlainText();
	add_array(5, 5);
}

void sudoku::on_inp6_7_textChanged()
{
	inp = this->ui->inp6_7->toPlainText();
	add_array(5, 6);
}

void sudoku::on_inp6_8_textChanged()
{
	inp = this->ui->inp6_8->toPlainText();
	add_array(5, 7);
}

void sudoku::on_inp6_9_textChanged()
{
	inp = this->ui->inp6_9->toPlainText();
	add_array(5, 8);
}

// box7
void sudoku::on_inp7_1_textChanged()
{
	inp = this->ui->inp7_1->toPlainText();
	add_array(6, 0);
}

void sudoku::on_inp7_2_textChanged()
{
	inp = this->ui->inp7_2->toPlainText();
	add_array(6, 1);
}

void sudoku::on_inp7_3_textChanged()
{
	inp = this->ui->inp7_3->toPlainText();
	add_array(6, 2);
}

void sudoku::on_inp7_4_textChanged()
{
	inp = this->ui->inp7_4->toPlainText();
	add_array(6, 3);
}

void sudoku::on_inp7_5_textChanged()
{
	inp = this->ui->inp7_5->toPlainText();
	add_array(6, 4);
}

void sudoku::on_inp7_6_textChanged()
{
	inp = this->ui->inp7_6->toPlainText();
	add_array(6, 5);
}

void sudoku::on_inp7_7_textChanged()
{
	inp = this->ui->inp7_7->toPlainText();
	add_array(6, 6);
}

void sudoku::on_inp7_8_textChanged()
{
	inp = this->ui->inp7_8->toPlainText();
	add_array(6, 7);
}

void sudoku::on_inp7_9_textChanged()
{
	inp = this->ui->inp7_9->toPlainText();
	add_array(6, 8);
}

// box8
void sudoku::on_inp8_1_textChanged()
{
	inp = this->ui->inp8_1->toPlainText();
	add_array(7, 0);
}

void sudoku::on_inp8_2_textChanged()
{
	inp = this->ui->inp8_2->toPlainText();
	add_array(7, 1);
}

void sudoku::on_inp8_3_textChanged()
{
	inp = this->ui->inp8_3->toPlainText();
	add_array(7, 2);
}

void sudoku::on_inp8_4_textChanged()
{
	inp = this->ui->inp8_4->toPlainText();
	add_array(7, 3);
}

void sudoku::on_inp8_5_textChanged()
{
	inp = this->ui->inp8_5->toPlainText();
	add_array(7, 4);
}

void sudoku::on_inp8_6_textChanged()
{
	inp = this->ui->inp8_6->toPlainText();
	add_array(7, 5);
}

void sudoku::on_inp8_7_textChanged()
{
	inp = this->ui->inp8_7->toPlainText();
	add_array(7, 6);
}

void sudoku::on_inp8_8_textChanged()
{
	inp = this->ui->inp8_8->toPlainText();
	add_array(7, 7);
}

void sudoku::on_inp8_9_textChanged()
{
	inp = this->ui->inp8_9->toPlainText();
	add_array(7, 8);
}

// box9
void sudoku::on_inp9_1_textChanged()
{
	inp = this->ui->inp9_1->toPlainText();
	add_array(8, 0);
}

void sudoku::on_inp9_2_textChanged()
{
	inp = this->ui->inp9_2->toPlainText();
	add_array(8, 1);
}

void sudoku::on_inp9_3_textChanged()
{
	inp = this->ui->inp9_3->toPlainText();
	add_array(8, 2);
}

void sudoku::on_inp9_4_textChanged()
{
	inp = this->ui->inp9_4->toPlainText();
	add_array(8, 3);
}

void sudoku::on_inp9_5_textChanged()
{
	inp = this->ui->inp9_5->toPlainText();
	add_array(8, 4);
}

void sudoku::on_inp9_6_textChanged()
{
	inp = this->ui->inp9_6->toPlainText();
	add_array(8, 5);
}

void sudoku::on_inp9_7_textChanged()
{
	inp = this->ui->inp9_7->toPlainText();
	add_array(8, 6);
}

void sudoku::on_inp9_8_textChanged()
{
	inp = this->ui->inp9_8->toPlainText();
	add_array(8, 7);
}

void sudoku::on_inp9_9_textChanged()
{
	inp = this->ui->inp9_9->toPlainText();
	add_array(8, 8);
}

// buttons
void sudoku::on_btn_solve_clicked()
{
	QMessageBox mb;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			boxs[i][j] ++;
			if (boxs[i][j] == 0)
			{
				mb.setText("Fill All Blank With Numbers 1-9");
				mb.setWindowTitle("Fill All");
				mb.exec();
				return ;
			}
		}
	}

	int ii, jj;
	for (int i = 0; i < 9; i++)
	{
		int checkR[9] = {};
		int checkC[9] = {};
		int checkB[9] = {};

		for (int j = 0; j < 9; j++)
		{
			checkR[boxs[i][j]-1] = 1;
			checkC[boxs[j][i]-1] = 1;
			ii = ((i % 3) * 3) + (j % 3);
			jj = ((i / 3) * 3) + (j / 3);
			checkB[boxs[ii][jj]-1] = 1;
		}

		for (int k = 0; k < 9; k++)
		{
			if (checkR[k] == 0 || checkC[k] == 0 || checkB[k] == 0)
			{
				mb.setText("Your Answer Is Wrong!");
				mb.setWindowTitle("Try Again!");
				mb.exec();
				return ;
			}
		}
	}


	QFile file(address);

	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this,"title","File Not Open");
		return;
	}

	QTextStream in(&file);
	QString line;
	QVector<QString> names;
	QVector<int> wins;

	while (!in.atEnd())
	{
		line = in.readLine();
		names.push_back(line.split(" ")[0]);
		wins.push_back((line.split(" ")[1]).toInt());
	}

	int index = names.indexOf(name);
	if (index != -1) wins[index]++;
	else
	{
		names.push_back(name);
		wins.push_back(1);
	}
	for (int i = index; i > 0; i--)
	{
		if (wins[i] > wins[i-1])
		{
			std::swap(wins[i],wins[i-1]);
			std::swap(names[i],names[i-1]);
		}
	}

	file.remove();


	if (!file.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::warning(this,"title","File Not Open");
	}

	QTextStream out(&file);
	QString txt = "";
	for (int i = 0; i < names.size(); i++)
	{
		out << names[i] << " " << wins[i] << endl;
	}

	file.flush();
	file.close();


    mb.setText("Yor Are Solve This sudoku !!!");
	mb.setWindowTitle("Win");
	mb.exec();

	endgame * endg = new endgame(true);
	endg->show();
	this->close();

}


void sudoku::on_btn_finish_clicked()
{
	endgame * egame = new endgame(false);
	egame->show();
	this->close();
}


void sudoku::on_btn_restart_clicked()
{
    sudoku * sodo = new sudoku(name);
	sodo->show();
	this->close();

}


void sudoku::on_btn_exit_clicked()
{
	this->close();
}
