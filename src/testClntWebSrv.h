#include <QtTest/QtTest>
#include <QObject>

class TestQString: public QObject
{
Q_OBJECT
private slots:
    void toUpper();
};
