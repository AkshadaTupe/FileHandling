#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileHandler
{
    fstream File;

public: 
    void createFile()
    {
        //Change the path according to your location
        File.open("C://Users//320159441//Documents//GitHub//Projects//FileHandling//TestingFile.txt", ios::out);

        if (!File.is_open())
        {
            cerr << "[Error] Error while creating file";
            exit(EXIT_FAILURE);
        }

        cout << "[Log] File Successfully created\n";

        writeIntoFile();

       
    }

    void writeIntoFile()
    {
        try
        {
            File << "Adding text into TestingFile.txt using fstream";
            File.close();
        }
        catch(exception e)
        {
            cerr << "[Error] Error while writing into file";
            exit(EXIT_FAILURE);
        }
    }

    void readFromFileWithoutSpace()
    {
        //Change the path according to your location
        //Open the file for reading
        File.open("C://Users//320159441//Documents//GitHub//FileHandling//BasicFileHandling//TestingFile.txt", ios::in);

        if (!File.is_open())
        {
            cerr << "Error while creating file";
            exit(EXIT_FAILURE);
        }

        cout << "[Log] File Successfully Opened\n";

        char x;
        while (File >> x)
            cout << x;

        cout << endl;

        File.close();
    }

    void readFromFileWithSpace()
    {
        //Change the path according to your location
        File.open("C://Users//320159441//Documents//GitHub//FileHandling//BasicFileHandling//TestingFile.txt", ios::in);
      
        File.seekp(0, std::ios::beg);
      
        if (!File.is_open())
        {
            cerr << "[Error] Error while creating file\n";
            exit(EXIT_FAILURE);
        }

        cout << "[Log] File Successfully Opened\n";


        char y;
        while (File >> std::noskipws >> y) {
            cout << y;
        }
       
        cout << endl;
        File.close();
    }

    void readFromFile()
    {
        File.open("C://Users//320159441//Documents//GitHub//FileHandling//BasicFileHandling//TestingFile.txt", ios::in);

        if (!File.is_open())
        {
            cerr << "[Error] Error while creating file";
            exit(EXIT_FAILURE);
        }

        string line;
        while (getline(File, line)) {
            cout << line << std::endl;
        }

        File.close();
    }

    void AddnewLines()
    {
        //Change the path according to your location
        File.open("C://Users//320159441//Documents//GitHub//FileHandling//BasicFileHandling//TestingFile.txt", ios::app);

        if (!File.is_open())
        {
            cerr << "[Error] Error while creating file";
            exit(EXIT_FAILURE);
        }

        cout << "[Log] File Successfully Opened\n";

        File << "\nAdding second line to the text";

        cout << "[Log] Written Successfully in File\n";

        File.close();

        readFromFile();
    }
};

int main()
{
    FileHandler obj;

    obj.createFile();

    obj.readFromFileWithoutSpace();

    obj.readFromFileWithSpace();

    obj.readFromFile();

    obj.AddnewLines();


    return 0;
}

