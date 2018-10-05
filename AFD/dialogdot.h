#ifndef DIALOGDOT_H
#define DIALOGDOT_H

#include <QDialog>
#include<QPixmap>

namespace Ui {
class DialogDot;
}

class DialogDot : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDot(QWidget *parent = nullptr);
    ~DialogDot();

private:
    Ui::DialogDot *ui;
};

#endif // DIALOGDOT_H
