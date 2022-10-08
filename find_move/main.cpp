#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;

    ifstream myfile;
    string path = argv[1];
    string motive = argv[2];

    try
    {
        myfile.open(path);

        if (!myfile.is_open())
        {
            cerr << "The file " + path + " could not be opened." << '\n';
            return 1;
        }

        string line;
        size_t count = 0;
        while (getline(myfile, line))
        {
            size_t i = 0;
            while (i < line.length())
            {
                int found = line.find(motive, i);
                if (found == string::npos)
                    break;

                i = found + 1;
                count++;
            }
        }

        cout << "The file " + path + " contains " + to_string(count)
                + " words containing the motive " + motive
             << endl;
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
