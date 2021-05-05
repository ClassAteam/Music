#include "interfacing.h"

QElapsedTimer timing;

interfacing::interfacing(QWidget *parent)
    : QWidget(parent), btnID{0}, slID{0}, lblClueID{0},row{0}, column{0},
       rbGroupID{0}, rbID{0}, rbMappedValue{0}
{
    layout_buttons = new QGridLayout(this);
    this->setLayout(layout_buttons);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    this->setFixedHeight(screenGeometry.height());
    this->setFixedWidth(screenGeometry.width());
    this->setWindowState(Qt::WindowFullScreen);
    //fonts
    btnFont = new QFont("Courier", 12, QFont::Bold);
    lblClueFontAct = new QFont("Time", 12, QFont::Bold);
    lblClueFontInact = new QFont("Time", 8, QFont::Bold);
    //buttons
    signalMapperBtns = new QSignalMapper(this);
    connect(signalMapperBtns, SIGNAL(mapped(int)), this, SIGNAL(digitClicked(int)));
    connect(this, SIGNAL(digitClicked(int)), this, SLOT(m_RedButton2(int)));
    //labels
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setLbl()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateLogic()));
    timer->start(TICK);
    //sliders
    signalMapperSldrs = new QSignalMapper(this);
    connect(signalMapperSldrs, SIGNAL(mapped(int)), this, SIGNAL(changeValue(int)));
    connect(this, SIGNAL(changeValue(int)), this, SLOT(setSlV(int)));
    //rbuttons
    QButtonGroup* firstgroup = new QButtonGroup;
    rbGrPool.append(firstgroup);
    signalMapperRbtns = new QSignalMapper(this);
    connect(signalMapperRbtns, SIGNAL(mapped(const QString)), this, SIGNAL(rbClicked(const QString)));
    connect(this, SIGNAL(rbClicked(const QString)), this, SLOT(setRB(const QString)));
//    this->setStyleSheet("QLabel {color: green}"); //would be very expensive
}

void interfacing::createRedButton(bool* clue, QString name)
{
    QPushButton *button = new QPushButton(name);
//    button->setFixedHeight(40);
//    button->setFixedWidth(150);
    button->setStyleSheet("max-width: 10em");
    layout_buttons->addWidget(button, row, column);
    posOcupied();
    button->setFont(*btnFont);
    signalMapperBtns->setMapping(button, btnID);
    connect(button, SIGNAL(clicked()), signalMapperBtns, SLOT(map()));
    btnClues.append(clue);
    btnID++;
    btnsPool.append(button);
}

void interfacing::createLabelClue(bool* clue, QString name)
{
    QLabel *label = new QLabel(name);
    layout_buttons->addWidget(label, row, column);
    label->setStyleSheet("max-width: 10em;");
    posOcupied();
    lblClues.append(clue);
    lblClueID++;
    lblsPoolClue.append(label);

}

void interfacing::createLabelValue(double* value, QString name)
{
    QLabel *label = new QLabel(name);
    layout_buttons->addWidget(label, row, column);
    label->setFixedWidth(200);
    posOcupied();
    lblValues.append(value);
    lblValueID++;
    lblsPoolValue.append(label);
}

void interfacing::createSlider(double* variable, int low_val, int high_val)
{
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(low_val, high_val);
    slider->setPageStep(1);
    slider->setValue(0);
    slider->setStyleSheet("max-width: 10em;");
    layout_buttons->addWidget(slider, row, column);
    posOcupied();
    signalMapperSldrs->setMapping(slider, slID);
    connect(slider, SIGNAL(valueChanged(int)), signalMapperSldrs, SLOT(map()));
    slValues.append(variable);
    slID++;
    slPool.append(slider);
}
void interfacing::createRadioButton(int* toggler, QString name, bool isLastInGrp)
{
    QRadioButton* rbutton = new QRadioButton(name, this);
    rbGrPool[rbGroupID]->addButton(rbutton);
    layout_buttons->addWidget(rbutton, row, column);
    posOcupied();
    const QString str = QString::number(rbID) + "_" + QString::number(rbMappedValue) ;
    signalMapperRbtns->setMapping(rbutton, str);
    connect(rbutton, SIGNAL(clicked()), signalMapperRbtns, SLOT(map()));
    rbTogglers.append(toggler);
    rbtnPool.append(rbutton);
    rbID++;
    if(rbMappedValue == 0)
    {
        rbutton->setChecked(true);
    }
    rbMappedValue++;
    if(isLastInGrp)
    {
        rbMappedValue = 0;
        rbGroupID++;
        QButtonGroup* newGroup = new QButtonGroup;
        rbGrPool.append(newGroup);
    }
}
void interfacing::setSlV(int value)
{
    QSlider *slider = slPool[value];
    *slValues[value] = slider->value();
}
void interfacing::m_RedButton2(int value)
{
    QPushButton *button = btnsPool[value];;
    bool pressed;
    pressed = *btnClues[value];
    if(pressed == false)
    {
        *btnClues[value] = true;
        button->setStyleSheet("background-color: red;"
                              "border-width: 2px;"
                              "border-color: black;"
                                 "max-width: 10em;");
    }
    if(pressed == true)
    {
        *btnClues[value] = false;
        button->setStyleSheet("max-width: 10em");
   }
}
void interfacing::setLbl()
{
    for(int i = 0; i < lblsPoolClue.count(); i++)
    {
        QLabel *label = lblsPoolClue[i];
        QString str = label->text();
        for(int i = 0; i < str.size(); ++i)
        {
            if(str.at(i) == QChar(' '))
            {
                str.truncate(i + 1);
            }
        }
        bool pressed;
        pressed = *lblClues[i];
        if(pressed)
        {
            QPalette pal = label->palette();
            pal.setColor(QPalette::WindowText, Qt::red);
            label->setPalette(pal);
            label->setFont(*lblClueFontAct);
        }
        else
        {
            QPalette pal = label->palette();
            pal.setColor(QPalette::WindowText, Qt::gray);
            label->setPalette(pal);
            label->setFont(*lblClueFontInact);
        }

    }

    for(int i = 0; i < lblsPoolValue.count(); i++)
    {
        QLabel *label = lblsPoolValue[i];
        QString str = label->text();
        for(int i = 0; i < str.size(); ++i)
        {
            if(str.at(i) == QChar(' '))
            {
                str.truncate(i + 1);
            }
        }

        label->setText(str + " = " + QString::number(*lblValues[i]));

        if(*lblValues[i] != 0)
        {
            QPalette pal = label->palette();
            pal.setColor(QPalette::WindowText, Qt::blue);
            label->setPalette(pal);
            label->setFont(*lblClueFontAct);
        }
        else
        {
            QPalette pal = label->palette();
            pal.setColor(QPalette::WindowText, Qt::gray);
            label->setPalette(pal);
            label->setFont(*lblClueFontInact);

        }
    }
}

void interfacing::setRB(const QString str)
{
    QStringList list;
    QString value_index;
    QString value;

    list = str.split(QRegularExpression("_"));
    value_index = list[0];
    value = list[1];

    *rbTogglers[value_index.toInt()] = value.toInt();
}

void interfacing::posOcupied()
{
    if(row < 45)
        row++;
    else
    {
        row = 0;
        column++;
    }
}
void interfacing::trigerButton()
{
    qDebug() << "timer is up";
}

void interfacing::updateLogic()
{
    qDebug() << "base logic update call";

}
