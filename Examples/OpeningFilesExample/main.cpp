#include <iostream>
#include <fstream>
#include <string>

void readAndDisplay(std::ifstream& inputStream)
{

    if (!inputStream.is_open())
    {
        std::cout << "The file is not open" << std::endl;
    } else if (inputStream.eof())
    {
        std::cout << "No data to read from file" << std::endl;
    } else
    {
        while (!inputStream.eof())
        {
            std::string line;
            std::getline(inputStream, line);
            std::cout << line << std::endl;
        }
    }
}

void openFileUsingAbsolutePath()
{
    std::cout << "Open a file using an absolute path" << std::endl;
    std::cout << "Note: typically a bad idea because its specific to a file system's organization" << std::endl;

    std::string filePath = "/Users/swc/Dropbox/UnderGit/cs1440s17-shared/Examples/OpeningFilesExample/Data/TestData.txt";
    std::cout << "File Path = " << filePath << std::endl;
    std::ifstream inputStream(filePath);
    readAndDisplay(inputStream);
    inputStream.close();

    std::cout << std::endl << std::endl;
}

void openFileUsingPathRelativeToWorkingDirectory()
{
    std::cout << "Open a file using an path relative to a working directory" << std::endl;
    std::cout << "Note: better, but requires setting up working directory and may not" << std::endl;
    std::cout << "work as expected for all the different ways to launch a progam." << std::endl;

    std::string filePath = "./Data/TestData.txt";
    std::cout << "File Path = " << filePath << std::endl;
    std::ifstream inputStream(filePath);
    readAndDisplay(inputStream);
    inputStream.close();

    std::cout << std::endl << std::endl;
}

void openFileUsingPathRelativeToExeDirectory(std::string exePath)
{
    std::cout << "Open a file using an path relative to a working directory" << std::endl;
    std::cout << "Note: okay choice for files packaged with the exe, but typically not for data files " << std::endl;

    std::cout << "Exe Path = " << exePath << std::endl;
    int lastSlash = exePath.rfind('/');
    if (lastSlash!=std::string::npos)
        exePath.erase(lastSlash+1);

    std::string filePath = exePath.append("Data/TestData.txt");
    std::cout << "File Path = " << filePath << std::endl;
    std::ifstream inputStream(filePath);

    readAndDisplay(inputStream);
    inputStream.close();

    std::cout << std::endl << std::endl;
}


int main(int argc, char* argv[]) {
    std::cout << "Arguments:" << std::endl;
    for (int i=0; i<argc; i++)
        std::cout << argv[i] << std::endl;

    // Approach 1
    openFileUsingAbsolutePath();

    // Approach 2
    openFileUsingPathRelativeToWorkingDirectory();

    // Aproach 3
    std::string exePath = argv[0];
    openFileUsingPathRelativeToExeDirectory(exePath);

    // Other approaches
    //      - get absolute or relative names from program agruments
    //      - get absolute or relative names from environment variables
    //      - get absolute or relative names from configuration or properties files
    //      - get absolute or relative names from system registry entries
    //      - combinations of the above, e.g. getting root directory from
    //          an environment variable and rest of the file paths from
    //          a configuration file.

}