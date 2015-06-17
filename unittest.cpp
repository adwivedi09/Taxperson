//Author - Ankit Dwivedi
//Date - 06/16/2016

#include<iostream>
#include<string>
#include<list>
#include<cppunit/TestCase.h>
#include<cppunit/TestFixture.h>
#include<cppunit/ui/text/TextTestRunner.h>
#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/extensions/TestFactoryRegistry.h>
#include<cppunit/TestResult.h>
#include<cppunit/TestResultCollector.h>
#include<cppunit/TestRunner.h>
#include<cppunit/BriefTestProgressListener.h>
#include<cppunit/CompilerOutputter.h>
#include<cppunit/XmlOutputter.h>
#include<netinet/in.h>
#include "taxperson.cpp"

using namespace CppUnit;
using namespace std;
class TestTaxCal : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestTaxCal);
    CPPUNIT_TEST(testTax);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void);
    void tearDown(void);
protected:
    void textTax(void);
private:TaxPerson *mTestObj;
};

void TestTaxCal::testTax(void)
{
    CPPUNIT_ASSERT(40.4 == mTestObj->tax_cal(40,0));
}
void TestTaxCal::testTax(void)
{
    CPPUNIT_ASSERT(43.6 == mTestObj->tax_cal(40,1));
}

void TestTaxCal::testTax(void)
{
    CPPUNIT_ASSERT(-1 == mTestObj->tax_cal(-40,0));
}
void TestTaxCal::testTax(void)
{
    CPPUNIT_ASSERT(-1 == mTestObj->tax_cal(-40,1));
}

void TestTaxCal::testTax(void)
{
    CPPUNIT_ASSERT(-1 == mTestObj->tax_cal(0,0));
}
void TestTaxCal::testTax(void)
{
    CPPUNIT_ASSERT(-1 == mTestObj->tax_cal(0,1));
}

void TestTaxCal::testTax(void)
{
    CPPUNIT_ASSERT(-2 == mTestObj->tax_cal(40,2));
}
void TestTaxCal::testTax(void)
{
    CPPUNIT_ASSERT(-2 == mTestObj->tax_cal(40,-1));
}

void TestTaxCal::setUp(void)
{
    mTestObj = new TaxPerson();
}
void TestTaxCal::tearDown(void)
{
    delete mTestObj;
}
CPPUNIT_TEST_SUITE_REGISTRATION( TestTaxCal );

int main(int argc, char* argv[]){
 // informs test-listener about testresults
 CPPUNIT_NS::TestResult testresult;
 
 // register listener for collecting the test-results
 CPPUNIT_NS::TestResultCollector collectedresults;

 testresult.addListener (&collectedresults);
 // register listener for per-test progress output
 CPPUNIT_NS::BriefTestProgressListener progress;
 testresult.addListener (&progress);
 // insert test-suite at test-runner by registry
 CPPUNIT_NS::TestRunner testrunner;
 testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
 testrunner.run(testresult);
 // output results in compiler-format
 CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
 compileroutputter.write ();

 XmlOutputter xmlOut(&collectedresults, xmlFileOut);

 xmlOut.write();
 // return 0 if tests were successful

 return collectedresults.wasSuccessful() ? 0 : 1;

}
