#ifndef METADATA_H
#define METADATA_H

#include "SDL.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// this class stores the meta data about the game like the platform it is running on
class MetaData
{
public:
    // constructor fetches the platform and sets the private variable accordingly
    MetaData() : thisPlatform(std::string())
    {
        thisPlatform = fetchPlatform();
    }

    // public data memebers
    const std::string recordDataFile{"../high_score_record.txt"};

    // public method that can be called from other functions
    void displayPlatform();
    int getHighScore();
    void setHighScore(int highScore);


private:
    std::string thisPlatform;

    // private methods
    std::string fetchPlatform();
};

int MetaData::getHighScore()
{
    int highScore{0};
    std::string line;
    std::ifstream filestream(recordDataFile);
    if (filestream.is_open())
    {
        if (std::getline(filestream, line))
        {
            std::istringstream linestream(line);
            if (linestream >> highScore)
            {
            }
        }
        filestream.close();
        std::cout << "reading data from high score record file ..." << std::endl;
    }
    else
    {
        std::cout << "High score record file does not exist. Creating new." << std::endl;
        std::ofstream outfile(recordDataFile);
    }
    return highScore;
}

void MetaData::setHighScore(int highScore)
{
    std::ofstream dataFile;
    dataFile.open(recordDataFile, std::ios::in | std::ios::out | std::ios::app);
    if (!dataFile.is_open())
    {
        std::cout << " unable to open record file" << std::endl;
    }
    else
    {
        dataFile<<highScore;
    }
}

std::string MetaData::fetchPlatform()
{
    const char *platform = SDL_GetPlatform();
    std::string p(platform);
    thisPlatform = p;
    return thisPlatform;
};

void MetaData::displayPlatform()
{
    if (thisPlatform != "")
        std::cout << "The current Platform Detected: " << thisPlatform << std::endl;
    else
        std::cout << "No System Platform Detected." << std::endl;
}

#endif