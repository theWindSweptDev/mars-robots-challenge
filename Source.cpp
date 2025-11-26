#include <iostream>
#include <csignal>

using namespace std;

static bool hasScent(int x, int y, int scentX[], int scentY[], int scentCount)
{
    for (int i = 0; i < scentCount; i++)
    {
        if (scentX[i] == x && scentY[i] == y)
        {
            return true;
        }
    }
    return false;
}
static bool isValidInputForRobotStart(int x, int y, string direction)
{
    if (x < 0 || x > 50)
        return false;
    if (y < 0 || y > 50)
        return false;
    if (!(direction == "N" || direction == "S" || direction == "E" || direction == "W"))
        return false;
    return true;
}

int main()
{

    // North is Y+1
    // Quad is 0,0 (bottom left to user input top right)

    int positionX = -1;
    int positionY = -1;
    int upperRightXCoordinate = -1;
    int upperRightYCoordinate = -1;

    string direction = "";
    string instructions = "";

    char command[3] = {'L', 'R', 'F'};

    // lost scents
    int scentX[100];
    int scentY[100];
    int scentCount = 0;

    // Set the upper right coordinates of the grid
    cin >> upperRightXCoordinate >> upperRightYCoordinate;

    while (!isValidInputForRobotStart(positionX, positionY, direction))
    {
        cin >> positionX >> positionY >> direction;
    }

    // infinite loop since we are not required to exit
    while (true)
    {
        if (!(cin >> instructions))
        {
            break;
        }

        for (char &c : instructions)
        {
            c = toupper(c);
        }

        bool isLost = false;

        for (char instruction : instructions)
        {
            // else is not used here as a defensive mechanism due to no input filtering(NOT A REQUIREMENT)
            if (instruction == command[0])
            { // L
                if (direction == "N")
                    direction = "W";
                else if (direction == "W")
                    direction = "S";
                else if (direction == "S")
                    direction = "E";
                else if (direction == "E")
                    direction = "N";
            }
            else if (instruction == command[1])
            { // R
                if (direction == "N")
                    direction = "E";
                else if (direction == "E")
                    direction = "S";
                else if (direction == "S")
                    direction = "W";
                else if (direction == "W")
                    direction = "N";
            }
            else if (instruction == command[2])
            { // F
                int nextX = positionX;
                int nextY = positionY;

                if (direction == "N")
                    nextY++;
                else if (direction == "E")
                    nextX++;
                else if (direction == "S")
                    nextY--;
                else if (direction == "W")
                    nextX--;

                // would move off the grid?
                if (nextX > upperRightXCoordinate || nextX < 0 ||
                    nextY > upperRightYCoordinate || nextY < 0)
                {

                    if (hasScent(positionX, positionY, scentX, scentY, scentCount))
                    {
                        // ignore this move
                        continue;
                    }

                    // store scent at last valid position
                    if (scentCount < 100)
                    {
                        scentX[scentCount] = positionX;
                        scentY[scentCount] = positionY;
                        scentCount++;
                    }

                    cout << "\n\n"
                         << positionX << " " << positionY << " " << direction << " LOST\n";
                    isLost = true;
                    break; // stop further instructions for this robot
                }
                else
                {
                    positionX = nextX;
                    positionY = nextY;
                }
            }
        }

        if (!isLost && instructions.length() > 0)
        {
            cout << "\n\n"
                 << positionX << " " << positionY << " " << direction << endl;
        }
        else
        {

            /*
             *  The robot was lost so we enter a new starting location
             *  robots are not being tracked
             *  we reset some of the vars to prevent looping outputs
             */

            positionX = -1;
            positionY = -1;
            string direction = "";
            string instructions = "";

            // The sample appeared to not reset the grid if a robot was lost and requirement not asked for
            while (!isValidInputForRobotStart(positionX, positionY, direction))
            {
                cin >> positionX >> positionY >> direction;
            }
        }
    }

    return 0;
}
