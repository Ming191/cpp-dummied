/*
 * TEST DRIVER FOR C++
 * @author: VNU-UET
 * Generate automatically by AKAUTAUTO
 */

// include some necessary standard libraries
#include <cstdio>
#include <string>
#include <fstream>
#include <string.h>
#include <vector>

#define ASSERT_ENABLE

// define maximum line of test path
#define AKA_MARK_MAX 4294967290

// function call counter
int AKA_fCall = 0;

// test case name
char* AKA_test_case_name;

typedef void (*AKA_Test)();

void AKA_run_test(std::string name, AKA_Test test, int iterator);

////////////////////////////////////////
//  BEGIN TEST PATH SECTION           //
////////////////////////////////////////

#define AKA_TEST_PATH_FILE "E:\\cpp-projects-collection\\NhatMinh\\aka-working-space\\fwegweg\\test-paths\\RGBtoHCT_unsigned_char_unsigned_char_unsigned_char_unsigned_charmul_unsigned_charmul_unsigned_charmul_manual_0.tp"

void AKA_append_test_path(std::string content);

int AKA_mark(std::string append);

int AKA_mark(char * append)
{
    std::string str(append);
    return AKA_mark(str);
}

////////////////////////////////////////
//  END TEST PATH SECTION             //
////////////////////////////////////////


////////////////////////////////////////
//  BEGIN TEST RESULT SECTION         //
////////////////////////////////////////

#define AKA_EXEC_TRACE_FILE "E:\\cpp-projects-collection\\NhatMinh\\aka-working-space\\fwegweg\\execution-results\\RGBtoHCT_unsigned_char_unsigned_char_unsigned_char_unsigned_charmul_unsigned_charmul_unsigned_charmul_manual_0.trc"

void AKA_append_test_result(std::string content);

void AKA_assert_method
(
    std::string actualName, int actualVal,
    std::string expectedName, int expectedVal,
    std::string method
);

void AKA_assert_string_method
(
    std::string actualName, std::string actualVal,
    std::string expectedName, std::string expectedVal,
    std::string method
);

void AKA_assert_double_method
(
    std::string actualName, double actualVal,
    std::string expectedName, double expectedVal,
    std::string method
);

void AKA_assert_ptr_method
(
    std::string actualName, void* actualVal,
    std::string expectedName, void* expectedVal,
    std::string method
);

#define NULL_STRING ""

void AKA_assert
(
    std::string actualName, int actualVal,
    std::string expectedName, int expectedVal
)
{
    AKA_assert_method
    (
        actualName, actualVal,
        expectedName, expectedVal,
        NULL_STRING
    );
}

int AKA_assert_double
(
    std::string actualName, double actualVal,
    std::string expectedName, double expectedVal
)
{
    AKA_assert_double_method
    (
        actualName, actualVal,
        expectedName, expectedVal,
        NULL_STRING
    );
}


int AKA_assert_string
(
    std::string actualName, std::string actualVal,
    std::string expectedName, std::string expectedVal
)
{
    AKA_assert_string_method
    (
        actualName, actualVal,
        expectedName, expectedVal,
        NULL_STRING
    );
}

int AKA_assert_ptr
(
    std::string actualName, void* actualVal,
    std::string expectedName, void* expectedVal
)
{
    AKA_assert_ptr_method
    (
        actualName, actualVal,
        expectedName, expectedVal,
        NULL_STRING
    );
}

void AKA_assert
(
    char* actualName, int actualVal,
    char* expectedName, int expectedVal
)
{
    std::string strAct(actualName);
    std::string strExp(expectedName);
    AKA_assert(strAct, actualVal, strExp, expectedVal);
}

int AKA_assert_double
(
    char* actualName, double actualVal,
    char* expectedName, double expectedVal
)
{
    std::string strAct(actualName);
    std::string strExp(expectedName);
    AKA_assert_double(strAct, actualVal, strExp, expectedVal);
}

int AKA_assert_ptr
(
    char* actualName, void* actualVal,
    char* expectedName, void* expectedVal
)
{
    std::string strAct(actualName);
    std::string strExp(expectedName);
    AKA_assert_ptr(strAct, actualVal, strExp, expectedVal);
}

////////////////////////////////////////
//  END TEST RESULT SECTION           //
////////////////////////////////////////


////////////////////////////////////////
//  BEGIN SET UP - TEAR DOWN SECTION  //
////////////////////////////////////////

/*
 * This function call before main test driver
 */
void AKA_set_up();

/*
 * This function call after main test driver
 */
void AKA_tear_down();

////////////////////////////////////////
//  END SET UP - TEAR DOWN SECTION    //
////////////////////////////////////////

// Some test cases need to include specific additional headers



// Include akaignore file
#include "E:\\cpp-projects-collection\\NhatMinh\\aka-working-space\\fwegweg\\instruments\src\pngdetail.akaignore.cpp"


using namespace std;

////////////////////////////////////////
//  BEGIN TEST SCRIPTS SECTION        //
////////////////////////////////////////

void AKA_TEST_RGBtoHCT_unsigned_char_unsigned_char_unsigned_char_unsigned_charmul_unsigned_charmul_unsigned_charmul_manual_0(void) {
{
AKA_test_case_name="RGBtoHCT_unsigned_char_unsigned_char_unsigned_char_unsigned_charmul_unsigned_charmul_unsigned_charmul_manual_0";

// set up
;


unsigned char r=12;

unsigned char g=12;

unsigned char b=12;
unsigned char AKA_ARRAY_INIT_h[2];

unsigned char AKA_ARRAY_INIT_h_0=49;
AKA_ARRAY_INIT_h[0] = AKA_ARRAY_INIT_h_0;

unsigned char AKA_ARRAY_INIT_h_1=50;
AKA_ARRAY_INIT_h[1] = AKA_ARRAY_INIT_h_1;

unsigned char AKA_ARRAY_INIT_h_2=0;
AKA_ARRAY_INIT_h[2] = AKA_ARRAY_INIT_h_2;

unsigned char* h = AKA_ARRAY_INIT_h;
unsigned char AKA_ARRAY_INIT_c[2];

unsigned char AKA_ARRAY_INIT_c_0=49;
AKA_ARRAY_INIT_c[0] = AKA_ARRAY_INIT_c_0;

unsigned char AKA_ARRAY_INIT_c_1=50;
AKA_ARRAY_INIT_c[1] = AKA_ARRAY_INIT_c_1;

unsigned char AKA_ARRAY_INIT_c_2=0;
AKA_ARRAY_INIT_c[2] = AKA_ARRAY_INIT_c_2;

unsigned char* c = AKA_ARRAY_INIT_c;
unsigned char AKA_ARRAY_INIT_t[2];

unsigned char AKA_ARRAY_INIT_t_0=49;
AKA_ARRAY_INIT_t[0] = AKA_ARRAY_INIT_t_0;

unsigned char AKA_ARRAY_INIT_t_1=50;
AKA_ARRAY_INIT_t[1] = AKA_ARRAY_INIT_t_1;

unsigned char AKA_ARRAY_INIT_t_2=0;
AKA_ARRAY_INIT_t[2] = AKA_ARRAY_INIT_t_2;

unsigned char* t = AKA_ARRAY_INIT_t;

/* RootDataNode STATIC */
/* NormalCharacterDataNode r */
/* NormalCharacterDataNode g */
/* NormalCharacterDataNode b */
/* PointerCharacterDataNode h */
/* PointerCharacterDataNode c */
/* PointerCharacterDataNode t */



AKA_mark("<<PRE-CALLING>> Test RGBtoHCT_unsigned_char_unsigned_char_unsigned_char_unsigned_charmul_unsigned_charmul_unsigned_charmul_manual_0");RGBtoHCT(r,g,b,h,c,t);
AKA_fCall++;AKA_mark("Return from: .\\lvandeve_lodepng\\src\\pngdetail.cpp\\RGBtoHCT(unsigned char,unsigned char,unsigned char,unsigned char*,unsigned char*,unsigned char*)");

/* error assertion */


// tear down
;
}
}



////////////////////////////////////////
//  END TEST SCRIPTS SECTION          //
////////////////////////////////////////

/*
 * The main() function for setting up and running the tests.
 */
int main()
{
    AKA_set_up();

    /* Compound test case setup */

    /* add & run the tests */
	AKA_run_test("RGBTOHCT_UNSIGNED_CHAR_UNSIGNED_CHAR_UNSIGNED_CHAR_UNSIGNED_CHARMUL_UNSIGNED_CHARMUL_UNSIGNED_CHARMUL_MANUAL_0", &AKA_TEST_RGBtoHCT_unsigned_char_unsigned_char_unsigned_char_unsigned_charmul_unsigned_charmul_unsigned_charmul_manual_0, 1);


    /* Compound test case teardown */

    AKA_tear_down();

    return 0;
}

////////////////////////////////////////
//  BEGIN DEFINITIONS SECTION         //
////////////////////////////////////////

void AKA_append_test_path(std::string content)
{
    static unsigned int aka_mark_iterator = 0;

    std::ofstream outfile;
    outfile.open(AKA_TEST_PATH_FILE, std::ios_base::app);
    outfile << content;
    aka_mark_iterator++;

    // if the test path is too long, we need to terminate the process
    if (aka_mark_iterator >= AKA_MARK_MAX) {
        outfile << "\nThe test path is too long. Terminate the program automatically!";
        outfile.close();
        exit(0);
    }

    outfile.close();
}

void AKA_append_test_result(std::string content)
{
    std::ofstream outfile;
    outfile.open(AKA_EXEC_TRACE_FILE, std::ios_base::app);
    outfile << content;
    outfile.close();
}

int AKA_mark(std::string append)
{
    AKA_append_test_path(append + "\n");
    return 1;
}

#define AKA_BUFFER_SIZE 1024

void AKA_assert_method
(
    std::string actualName, int actualVal,
    std::string expectedName, int expectedVal,
    std::string userCode
)
{
    std::string buf = "{\n";

    buf.append("\"tag\": \"Aka function calls: ");
    char temp0[AKA_BUFFER_SIZE];
    sprintf(temp0, "%d\",", AKA_fCall);
    buf.append(temp0);
    buf.append("\n");

    if (!userCode.empty())
    {
        buf.append("\"userCode\": \"");
        buf.append(userCode);
        buf.append("\",\n");
    }

    buf.append("\"actualName\": \"");
    buf.append(actualName);
    buf.append("\",\n");
    char temp1[AKA_BUFFER_SIZE];
    sprintf(temp1, "\"actualVal\": \"%d\",", actualVal);
    buf.append(temp1);
    buf.append("\n");

    buf.append("\"expectedName\": \"");
    buf.append(expectedName);
    buf.append("\",\n");
    char temp2[AKA_BUFFER_SIZE];
    sprintf(temp2, "\"expectedVal\": \"%d\"", expectedVal);
    buf.append(temp2);
    buf.append("\n},\n");

    AKA_append_test_result(buf);
}

void AKA_assert_string_method(
    std::string actualName, std::string actualVal,
    std::string expectedName, std::string expectedVal,
    std::string userCode)
{
    std::string buf = "{\n";

    buf.append("\"tag\": \"Aka function calls: ");
    char temp0[AKA_BUFFER_SIZE];
    sprintf(temp0, "%d\",", AKA_fCall);
    buf.append(temp0);
    buf.append("\n");

    if (!userCode.empty())
    {
        buf.append("\"userCode\": \"");
        buf.append(userCode);
        buf.append("\",\n");
    }

    buf.append("\"actualName\": \"");
    buf.append(actualName);
    buf.append("\",\n");

    char temp1[AKA_BUFFER_SIZE];
    sprintf(temp1, "\"actualVal\": \"%s\",", actualVal.c_str());
    buf.append(temp1);
    buf.append("\n");

    buf.append("\"expectedName\": \"");
    buf.append(expectedName);
    buf.append("\",\n");

    char temp2[AKA_BUFFER_SIZE];
    sprintf(temp2, "\"expectedVal\": \"%s\"", expectedVal.c_str());
    buf.append(temp2);
    buf.append("\n},\n");

    AKA_append_test_result(buf);
}

void AKA_assert_double_method
(
    std::string actualName, double actualVal,
    std::string expectedName, double expectedVal,
    std::string userCode
)
{
    std::string buf = "{\n";

    buf.append("\"tag\": \"Aka function calls: ");
    char temp0[AKA_BUFFER_SIZE];
    sprintf(temp0, "%d\",", AKA_fCall);
    buf.append(temp0);
    buf.append("\n");

    if (!userCode.empty())
    {
        buf.append("\"userCode\": \"");
        buf.append(userCode);
        buf.append("\",\n");
    }

    buf.append("\"actualName\": \"");
    buf.append(actualName);
    buf.append("\",\n");

    char temp1[AKA_BUFFER_SIZE];
    sprintf(temp1, "\"actualVal\": \"%lf\",", actualVal);
    buf.append(temp1);
    buf.append("\n");

    buf.append("\"expectedName\": \"");
    buf.append(expectedName);
    buf.append("\",\n");

    char temp2[AKA_BUFFER_SIZE];
    sprintf(temp2, "\"expectedVal\": \"%lf\"", expectedVal);
    buf.append(temp2);
    buf.append("\n},\n");

    AKA_append_test_result(buf);
}

void AKA_assert_ptr_method
(
    std::string actualName, void * actualVal,
    std::string expectedName, void * expectedVal,
    std::string userCode
)
{
    std::string buf = "{\n";

    buf.append("\"tag\": \"Aka function calls: ");
    char temp0[AKA_BUFFER_SIZE];
    sprintf(temp0, "%d\",", AKA_fCall);
    buf.append(temp0);
    buf.append("\n");

    if (!userCode.empty())
    {
        buf.append("\"userCode\": \"");
        buf.append(userCode);
        buf.append("\",\n");
    }

    buf.append("\"actualName\": \"");
    buf.append(actualName);
    buf.append("\",\n");

    char temp1[AKA_BUFFER_SIZE];
    sprintf(temp1, "\"actualVal\": \"%x\",", actualVal);
    buf.append(temp1);
    buf.append("\n");

    buf.append("\"expectedName\": \"");
    buf.append(expectedName);
    buf.append("\",\n");

    char temp2[AKA_BUFFER_SIZE];
    sprintf(temp2, "\"expectedVal\": \"%x\"", expectedVal);
    buf.append(temp2);
    buf.append("\n},\n");

    AKA_append_test_result(buf);
}

void AKA_run_test(std::string name, AKA_Test test, int iterator)
{
    std::string begin = "BEGIN OF " + name;
    AKA_mark(begin);

    int i;
    for (i = 0; i < iterator; i++) {
        test();
    }

    std::string end = "END OF " + name;
    AKA_mark(end);
}

void AKA_set_up()
{
    /*{{INSERT_SET_UP_HERE}}*/
}

void AKA_tear_down()
{
    /*{{INSERT_TEAR_DOWN_HERE}}*/
}

////////////////////////////////////////
//  END DEFINITIONS SECTION           //
////////////////////////////////////////
