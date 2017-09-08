#include <assert.h>
#include <iostream>

using namespace std;
#include <QCoreApplication>
#include "TestRunner.h"

//#int main(int argc, char **argv)
//#{
//#   QCoreApplication a(argc, argv);
//#
//#   TestRunner* worker = new TestRunner();
//#
//#   //bool ok = QObject::connect(worker, SIGNAL(finished()), &a, SLOT(quit()));
//#   QObject::connect(worker, SIGNAL(finished()), &a, SLOT(quit()));
//#	
//#   worker->start();
//#   worker->wait();
//#
//#   return a.exec();
//#}


#include <QtTest/QtTest>

class TestQString: public QObject
{
Q_OBJECT
public:
   TestQString(){};
   virtual ~TestQString(){};
private slots:
    void toUpper();
};

void TestQString::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(TestQString)
