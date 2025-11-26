// tests.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    // ---------- Mocked input (same as console session sent image/displayed on readme) ----------
    const char* testInputFile = "test_input.txt";
    const char* testOutputFile = "test_output.txt";

    ofstream in(testInputFile);
    in <<
        "5 3\n"
        "1 1 E\n"
        "RFRFRFRF\n"
        "1 1 E\n"
        "RR\n"
        "1 1 W\n"
        "L\n"
        "1 1 S\n"
        "fff\n"
        "1 0 S\n"
        "fff\n"
        "1 0 S\n"
        "r\n";
    in.close();

    // ---------- Expected output ----------
    vector<string> expected = {
        "1 1 E",
        "1 1 E",
        "1 1 W",
        "1 1 S",
        "1 0 S LOST",
        "1 0 S",
        "1 0 W"
    };

    // ---------- Run program ----------
    system((string("robot.exe < ") + testInputFile + " > " + testOutputFile).c_str());

    // ---------- Read actual output ----------
    ifstream out(testOutputFile);
    vector<string> actual;
    string line;
    while (getline(out, line))
    {
        // ignore empty noise lines
        if (line.find_first_not_of(" \t\r\n") != string::npos)
            actual.push_back(line);
    }
    out.close();

    // ---------- Compare ----------
    cout << "=== TEST RESULT SUMMARY ===\n\n";

    bool allPass = true;
    size_t maxLines = max(expected.size(), actual.size());

    for (size_t i = 0; i < maxLines; i++)
    {
        string exp = (i < expected.size() ? expected[i] : "<missing>");
        string act = (i < actual.size() ? actual[i] : "<missing>");

        if (exp == act)
        {
            cout << "[PASS]  Line " << i + 1 << ": " << act << "\n";
        }
        else
        {
            allPass = false;
            cout << "[FAIL]  Line " << i + 1 << "\n";
            cout << "        Expected: " << exp << "\n";
            cout << "        Actual:   " << act << "\n";
        }
    }

    cout << "\n----------------------------------\n";
    if (allPass)
        cout << "? ALL TESTS PASSED ?\n";
    else
        cout << "? TESTS FAILED ?\n";
    cout << "----------------------------------\n\n";

    return 0;
}
