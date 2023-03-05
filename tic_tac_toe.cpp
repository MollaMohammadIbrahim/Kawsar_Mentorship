#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QtWidgets>

class TicTacToe : public QWidget {
  Q_OBJECT

public:
  TicTacToe(QWidget *parent = 0);
  QPushButton *createButton(const QString &text, const char *member);
  void reset();

private slots:
  void buttonClicked();
  void showResult();

private:
  QPushButton *buttons[9];
  QLabel *statusLabel;
  int turn;
};

TicTacToe::TicTacToe(QWidget *parent) : QWidget(parent) {
  QGridLayout *grid = new QGridLayout;
  for (int i = 0; i < 9; i++) {
    buttons[i] = createButton("", SLOT(buttonClicked()));
    grid->addWidget(buttons[i], i / 3, i % 3);
  }
  QHBoxLayout *layout = new QHBoxLayout;
  layout->addLayout(grid);
  statusLabel = new QLabel;
  layout->addWidget(statusLabel);
  setLayout(layout);
  setWindowTitle(tr("Tic Tac Toe"));
  reset();
}

QPushButton *TicTacToe::createButton(const QString &text, const char *member) {
  QPushButton *button = new QPushButton(text);
  connect(button, SIGNAL(clicked()), this, member);
  return button;
}

void TicTacToe::reset() {
  turn = 0;
  for (int i = 0; i < 9; i++) {
    buttons[i]->setText("");
  }
  statusLabel->setText("X's turn");
}

void TicTacToe::buttonClicked() {
  QPushButton *button = (QPushButton *)sender();
  int move = -1;
  for (int i = 0; i < 9; i++) {
    if (buttons[i] == button) {
      move = i;
      break;
    }
  }
  if (buttons[move]->text().isEmpty()) {
    buttons[move]->setText(turn % 2 == 0 ? "X" : "O");
    turn++;
    showResult();
  }
}

void TicTacToe::showResult() {
  for (int i = 0; i < 3; i++) {
    if (buttons[i]->text() == buttons[i + 3]->text() &&
        buttons[i + 3]->text() == buttons[i + 6]->text() &&
        !buttons[i]->text().isEmpty()) {
      statusLabel->setText(buttons[i]->text() + " wins!");
      return;
    }
  }
    for (int i = 0; i < 9; i += 3) {
    if (buttons[i]->text() == buttons[i + 1]->text() &&
        buttons[i + 1]->text() == buttons[i + 2]->text() &&
        !buttons[i]->text().isEmpty()) {
      statusLabel->setText(buttons[i]->text() + " wins!");
      return;
    }
  }
  if (buttons[0]->text() == buttons[4]->text() &&
      buttons[4]->text() == buttons[8]->text() &&
      !buttons[0]->text().isEmpty()) {
    statusLabel->setText(buttons[0]->text() + " wins!");
    return;
  }
  if (buttons[2]->text() == buttons[4]->text() &&
      buttons[4]->text() == buttons[6]->text() &&
      !buttons[2]->text().isEmpty()) {
    statusLabel->setText(buttons[2]->text() + " wins!");
    return;
  }
  if (turn == 9) {
    statusLabel->setText("Draw!");
    return;
  }
  statusLabel->setText((turn % 2 == 0 ? "X" : "O") + QString("'s turn"));
}

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  TicTacToe ttt;
  ttt.show();
  return app.exec();
}

