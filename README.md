# Coding Challenge 2018 - Robot Grid

This is a simple C++ console application simulating robot movement on a grid.  

The user must set the upper right quadrant
then input the starting position for example 1 1 E 
before setting instructions to move forward, left or right (F, L R)

The application will output lost if the robots moves off the grid and remember the scent to prevent the next robot from being lost
once a robot is lost the user must input the start location of the next robot, however, this time the quadrant is not changed and the scents are remembered.

The code was originally developed using Visual Studio 2018 on Windows.

## Building and Running

### Windows (Visual Studio 2018 or newer)

1. Open the project folder in Visual Studio.
2. Add `Source.cpp` to your project if not already present.
3. Build the solution (`Ctrl+Shift+B`).
4. Run the application (`F5` or via Debug > Start Debugging).

### Linux / macOS (g++)

> Note: Some libraries or code may require minor changes for non-Windows platforms.

1. Open a terminal in the project directory.
2. Compile the code:
   ```sh
   g++ -std=c++11 Source.cpp -o robot_grid
   ```
3. Run the application:
   ```sh
   ./robot_grid
   ```

## Notes

- The code uses only standard C++ libraries (`iostream`, `csignal`).
- If you encounter compilation errors on Linux/macOS, check for Windows-specific code and adjust as needed.
- Input is expected via standard input (console).

## Example Usage

```
5 3
1 1 E
RFRFRFRF
3 2 N
FRRFLLFFRRFLL
0 3 W
LLFFFLFLFL
```
Expected output:
<img width="1330" height="861" alt="image" src="https://github.com/user-attachments/assets/dae55c48-9584-4b3a-a4b7-df163dd6c3fa" />

## Unit Test

Build unit_test as above or use the unit_tests.exe in the same directory as robot.exe
The results are output to a textfile that outs the test_input.txt and test_output.txt

please see the binarys_x64 folder (Typo!) for the binaries that has a built robot.exe, unit_test.exe as well as input and output results folder
To see the unit test take a look at the tests.cpp file 

Note that the test expects the file to be in the same directory and be called robot.exe!

## License

This project is for educational purposes
