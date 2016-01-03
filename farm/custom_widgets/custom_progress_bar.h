#include <QtGui>

class CustomProgressBar : public QProgressBar {
    protected:
        const char * p_label;
    public:
        CustomProgressBar (int min, int max, int init_progress, const char * label="", QWidget * parent=0);
        void setProgress (int);
};