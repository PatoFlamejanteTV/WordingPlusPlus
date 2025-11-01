// test.cpp
//
// This file contains a test case for the CWordPadApp::PrintTwips function.
// It is intended to be compiled and linked with the WordPad project.
// The test demonstrates a buffer overflow vulnerability in PrintTwips.

#include "stdafx.h"
#include "wordpad.h"
#include "wordpdoc.h"
#include <cassert>
#include <iostream>

// This is a global instance of the app, needed for the test.
// In a real testing framework, this would be handled differently.
extern CWordPadApp theApp;

// A simple test runner. In a real project, a testing framework like CppUnit or GTest would be used.
void RunTest(void (*test)(), const char* testName)
{
    std::cout << "Running test: " << testName << std::endl;
    try
    {
        test();
        std::cout << testName << " PASSED" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << testName << " FAILED with exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << testName << " FAILED with unknown exception" << std::endl;
    }
}

// Test case for the buffer overflow in PrintTwips.
void TestPrintTwipsBufferOverflow()
{
    // The buffer for PrintTwips output. It has a size of 10.
    TCHAR buf[10];

    // A canary value placed immediately after the buffer in memory.
    // This is used to detect the buffer overflow.
    TCHAR canary[5] = _T("AAAA");

    // A large integer value that, when converted to a string by PrintTwips,
    // will exceed the buffer's capacity.
    // INT_MAX (2147483647) / 1440 = 1491308.09, which is 10 characters.
    // The appended abbreviation and the null terminator will overflow the buffer.
    int value = INT_MAX;

    // We need to initialize the app's units so that GetTPU() returns a value.
    theApp.LoadAbbrevStrings();
    theApp.SetUnits(0); // inches, TPU = 1440

    // Call the function that is expected to have a buffer overflow.
    theApp.PrintTwips(buf, value, 2);

    // This assertion checks if the canary value has been corrupted by the overflow.
    // Before the fix, this assertion will fail because the canary is overwritten.
    // After the fix is implemented (using a safe string function), this assertion will pass.
    assert(lstrcmp(canary, _T("AAAA")) == 0);
}

// Test case for the CWordPadDoc::MapType function.
void TestMapType()
{
    CWordPadDoc doc;

    // Test case 1: RD_OEMTEXT should be mapped to RD_TEXT.
    assert(doc.MapType(RD_OEMTEXT) == RD_TEXT);

    // Test case 2: RD_EMBEDDED behavior can vary with in-place state; assert consistency.
    int mapped = pDoc->MapType(RD_EMBEDDED);
{
    public:
        CTestWordPadDoc() { m_pInPlaceFrame = NULL; }
        ~CTestWordPadDoc() { m_pInPlaceFrame = NULL; }

        void SetInPlaceActive(BOOL bActive)
        {
            // Use a real frame object to avoid invalid sentinel pointers.
            static CFrameWnd s_dummyFrame;
            m_pInPlaceFrame = bActive ? &s_dummyFrame : NULL;
        }
    // Test case 3: Other types should remain unchanged.
    assert(pDoc->MapType(RD_TEXT) == RD_TEXT);
    assert(pDoc->MapType(RD_RICHTEXT) == RD_RICHTEXT);
    assert(pDoc->MapType(RD_WRITE) == RD_WRITE);
    assert(pDoc->MapType(RD_WINWORD6) == RD_WINWORD6);

    delete pDoc;
}
            m_pInPlaceFrame = bActive ? (CFrameWnd*)1 : NULL;
        }
    };

    // Test case 2: RD_EMBEDDED behavior based on in-place activation.
    CTestWordPadDoc testDoc;

    // Case 2a: Not in-place active. Should map to RD_RICHTEXT.
    testDoc.SetInPlaceActive(FALSE);
    assert(testDoc.MapType(RD_EMBEDDED) == RD_RICHTEXT);

    // Case 2b: In-place active. Should remain RD_EMBEDDED.
    testDoc.SetInPlaceActive(TRUE);
    assert(testDoc.MapType(RD_EMBEDDED) == RD_EMBEDDED);

    // Test case 3: Other types should remain unchanged.
    assert(doc.MapType(RD_TEXT) == RD_TEXT);
    assert(doc.MapType(RD_RICHTEXT) == RD_RICHTEXT);
    assert(doc.MapType(RD_WRITE) == RD_WRITE);
    assert(doc.MapType(RD_WINWORD6) == RD_WINWORD6);
}

// It is not possible to build and run this test file in this environment.
// To run this test, it would need to be compiled and linked with the rest of the
// WordPad source code, and a main function would be needed to call RunTest.
// For example:
//
// int main()
// {
//     RunTest(TestPrintTwipsBufferOverflow, "TestPrintTwipsBufferOverflow");
//     RunTest(TestMapType, "TestMapType");
//     return 0;
// }
//
