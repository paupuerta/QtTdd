#ifndef TESTRUNNER_H_
#define TESTRUNNER_H_

#include <QThread>

class TestRunner : public QThread {

   Q_OBJECT

public:
   TestRunner(QObject *parent = 0);
   ~TestRunner();

   void run();

private:

};

#endif /* TESTRUNNER_H_ */
