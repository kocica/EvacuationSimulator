#include "RightClickButton.h"

namespace _GUI
{
    QRightClickButton::QRightClickButton(QWidget *parent) :
        QPushButton(parent)
    {
    }

    void QRightClickButton::mousePressEvent(QMouseEvent *e)
    {
        if(e->button() == Qt::RightButton)
        {
            emit rightClicked();
        }
        else if(e->button() == Qt::LeftButton)
        {
            emit clicked();
        }
    }
}