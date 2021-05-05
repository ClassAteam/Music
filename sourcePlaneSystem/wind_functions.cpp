#include "wind_functions.h"


void m_settext_lbl(QLabel* label, bool variable, QString str)
{
    if(variable != 0)
    {
        label->setText(str);
        label->setStyleSheet("background-color: green");
    }
    else
    {
        label->setText(str);
        label->setStyleSheet("");
    }
}
void m_settext_lbl(QLabel* label, int variable, QString str)
{
    label->setText(str + " = " + QString::number(variable));
    label->setStyleSheet("blue");
}
void m_settext_lbl(QLabel* label, double variable, QString str)
{
    label->setText(str + " = " + QString::number(variable));
    label->setStyleSheet("blue");
}

void m_settext_lbl(QLabel* label, QVector<bool> variable, QString name)
{
    QString stroke;
    for(int i = 0; i < variable.size(); i++)
    {
        if(i > 0)
        {
            stroke += " ";
        }
        stroke += QString::number(variable[i]);
    }
    label->setText(name + "= " + stroke);
}

void m_settext_lbl(QLabel* label, QVector<double> variable, QString name)
{
    QString stroke;
    for(int i = 0; i < variable.size(); i++)
    {
        if(i > 0)
        {
            stroke += " ";
        }
        stroke += QString::number(variable[i]);
    }
    label->setText(name + "= " + stroke);
}

void m_SetSliderGray(QSlider* slider)
{
    slider->setStyleSheet("QSlider::groove:horizontal {"
                             " border: 1px solid #999999;"
                             " height: 8px;"
//                             "  background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);"
                             "  background: orange;"
                             " margin: 2px 0;}"
                             " QSlider::handle:horizontal {"
                             "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);"
                             " border: 1px solid #5c5c5c;"
                             " width: 18px;"
                             " margin: -2px 0;"
                             "  border-radius: 3px;}");
}
void m_SetSliderBlue(QSlider* slider)
{
    slider->setStyleSheet("QSlider::groove:horizontal {"
                             " border: 1px solid #999999;"
                             " height: 8px;"
//                             "  background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);"
                             "  background: blue;"
                             " margin: 2px 0;}"
                             " QSlider::handle:horizontal {"
                             "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);"
                             " border: 1px solid #5c5c5c;"
                             " width: 18px;"
                             " margin: -2px 0;"
                             "  border-radius: 3px;}");
}
void m_switch(bool* toggler, bool* toggling)
{
    if(*toggler == true)
    {
        *toggling = true;
    }
    else
    {
        *toggling = false;
    }
}
void m_DoubleTrue(bool* UpperToggler, bool* UnderToggler, bool* Trigger)
{
    if(*UpperToggler == true || *UnderToggler == true)
    {
        *Trigger = true;
    }
    else
    {
        *Trigger = false;
    }
}
void m_DoubleTrueAnd(bool* UpperToggler, bool* UnderToggler, bool* Trigger)
{
    if(*UpperToggler == true && *UnderToggler == true)
    {
        *Trigger = true;
    }
    else
    {
        *Trigger = false;
    }
}
void m_RedButton2(QPushButton* button, bool* clue)
{
    bool pressed;
    pressed = *clue;
    if(pressed == false)
    {
        *clue = true;
        button->setStyleSheet("background-color: red");
    }
    if(pressed == true)
    {
        *clue = false;
        button->setStyleSheet("");
    }
}
void m_RadioButton2(QRadioButton *rbutton, int* holder, int value)
{
    if(rbutton->isChecked())
    {
        *holder = value;
    }
}
