#include "TestRunner.h"

#include <typeinfo>
#include <iostream>

using namespace std;

TestRunner::TestRunner (QObject *parent): QThread(parent)
{
	cout << "new TestRunner" << endl;
}

TestRunner::~TestRunner()
{
	cout << "delete TestRunner" << endl;
}

void TestRunner::run()
{
	cout << "run TestRunner OK" << endl;
}

