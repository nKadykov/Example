#ifndef WINDOW_H
#define WINDOW_H

#include "button.h"

#include <QWidget>
#include <QLabel>

class QLineEdit;
class Button;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    void firstButtonClicked();
    void secondButtonClicked();
    void thirdButtonClicked();
    void fourthButtonClicked();

private:
    template<typename PointerToMemberFunction>
    Button *createButton(const QString &text, const PointerToMemberFunction &member);
    QLabel *firstLabel;
    QLabel *secondLabel;
    QLabel *thirdLabel;
    QLabel *fourthLabel;
    QLineEdit *display;
};

#endif // WINDOW_H
