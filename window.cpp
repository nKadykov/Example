#include "window.h"
#include "button.h"

#include <QLineEdit>
#include <QGridLayout>

Window::Window(QWidget *parent) : QWidget(parent) {
    display = new QLineEdit("0");
    display->setReadOnly(true);
    QGridLayout *layout = new QGridLayout;
    setWindowTitle(tr("Window"));

    firstLabel = new QLabel(tr("First"));
    secondLabel = new QLabel(tr("Second"));
    thirdLabel = new QLabel(tr("Third"));
    fourthLabel = new QLabel(tr("Fourth"));

    layout->addWidget(display, 0, 0, 1, 4);
    layout->addWidget(firstLabel, 1, 0);
    layout->addWidget(secondLabel, 1, 1);
    layout->addWidget(thirdLabel, 1, 2);
    layout->addWidget(fourthLabel, 1, 3);

    Button *firstButton = createButton(tr("First"), &Window::firstButtonClicked);
    Button *secondButton = createButton(tr("Second"), &Window::secondButtonClicked);
    Button *thirdButton = createButton(tr("Third"), &Window::thirdButtonClicked);
    Button *fourthButton = createButton(tr("Fourth"), &Window::fourthButtonClicked);

    layout->addWidget(firstButton, 2, 0);
    layout->addWidget(secondButton, 2, 1);
    layout->addWidget(thirdButton, 2, 2);
    layout->addWidget(fourthButton, 2, 3);

    setLayout(layout);
}

void Window::firstButtonClicked() {
    Button *clickedButton = qobject_cast<Button*>(sender());
    QString text = clickedButton->text();
    display->setText(text);
}

void Window::secondButtonClicked() {
    Button *clickedButton = qobject_cast<Button*>(sender());
    QString text = clickedButton->text();
    display->setText(text);
}

void Window::thirdButtonClicked() {
    Button *clickedButton = qobject_cast<Button*>(sender());
    QString text = clickedButton->text();
    display->setText(text);
}

void Window::fourthButtonClicked() {
    Button *clickedButton = qobject_cast<Button*>(sender());
    QString text = clickedButton->text();
    display->setText(text);
}

template<typename PointerToMemberFunction>
Button *Window::createButton(const QString &text, const PointerToMemberFunction &member) {
    Button *button = new Button(text);
    connect(button, &Button::clicked, this, member);
    return button;
}
