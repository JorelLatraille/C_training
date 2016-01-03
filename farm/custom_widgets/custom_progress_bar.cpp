#include <QtGui>
#include <custom_progress_bar.h>

CustomProgressBar::CustomProgressBar (int min, int max, int init_progress, const char * label, QWidget * parent) :
	QProgressBar(parent)
{
    p_label = label;
    setRange(min, max);
    QString format_label = QString("%1 ").arg(init_progress) += QString(p_label);
    setFormat(format_label);
    setValue(init_progress);
}

void CustomProgressBar::setProgress(int prog) {
    QString format_label = QString("%1 ").arg(prog) += QString(p_label);
    setFormat(format_label);
    setValue(prog);
}