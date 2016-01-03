#include <QtGui>
#include <custom_widgets.h>
#include <animals.h>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    app.setStyle("Plastique");

    QDialog * dialog = new QDialog();

    QVBoxLayout * v_main_layout = new QVBoxLayout(dialog);

    Cow cow;
    int health = cow.getHealth();
    int hunger = cow.getHunger();
    int mood = cow.getMood();
    int weight = cow.getWeight();
    int meat = cow.getMeat();
    CustomProgressBar prog_health(0, 100, health, "HP");
    CustomProgressBar prog_hunger(0, 100, hunger, "Hunger");
    CustomProgressBar prog_mood(0, 100, mood, "Mood");
    CustomProgressBar prog_weight(0, 100, weight, "Weight Kg");
    CustomProgressBar prog_meat(0, 100, meat, "Yield Kg");

    v_main_layout->addWidget(&prog_health);
    v_main_layout->addWidget(&prog_hunger);
    v_main_layout->addWidget(&prog_mood);
    v_main_layout->addWidget(&prog_weight);
    v_main_layout->addWidget(&prog_meat);

    dialog->show();

    return app.exec();
}