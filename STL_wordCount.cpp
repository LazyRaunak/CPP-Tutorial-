#include <iostream>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

void display(std::map<std::string, int> &words){
    std::cout<<std::setw(20)<<std::left<<"\nWords"
             <<std::setw(7)<<std::right<<"Count"<<std::endl
             <<"============================="<<std::endl;
    for(auto pair:words)
        std::cout<<std::setw(20)<<std::left<<pair.first
                 <<std::setw(7)<<std::left<<pair.second<<std::endl;
}

void display(std::map<std::string, std::set<int>> &words){
    std::cout<<std::setw(20)<<std::left<<"\nWords"
             <<"Occurences"<<std::endl
             <<"=========================================================="<<std::endl;
    for(auto pair:words){
        std::cout<<std::setw(20)<<std::left<<pair.first
                 <<std::left<<"[ ";
        for(auto occur:pair.second)
            std::cout<<occur<<" ";
        std::cout<<"]"<<std::endl;
    }
}

std::string cleanString(const std::string &str){
    std::string finalStr;
    for(char c:str){
        if(c == '.' || c == ',' || c == '-' || c == ':' || c == '"' || c == '\'' || c == ';' || c == ')' 
                    || c == '(')
            continue;
        else
            finalStr += c;
    }
    return finalStr;
}

void part1(){
    std::map<std::string, int> words;
    std::string word;
    std::string line;

    std::ifstream inFile("SampleReadFile.txt");
    if(inFile){
        while(std::getline(inFile, line)){
            std::stringstream ss(line); //object treated as stream. Treating it as stream, we can do multiple operation.
            while(ss>>word){ //this operator read something from the stringstream object.
                word = cleanString(word);
                words[word]++;
            }
        }
        inFile.close();
        display(words);
    }
    else
        std::cout<<"Error opening file"<<std::endl;
}

void part2(){
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;

    std::ifstream inFile("SampleReadFile.txt");
    if(inFile){
        int lineNum = 0;
        while(std::getline(inFile, line)){
            lineNum++;
            std::stringstream ss(line);
            while(ss>>word){
                word = cleanString(word);
                words[word].insert(lineNum);
            }
        }
        inFile.close();
        display(words);
    }
    else
        std::cerr<<"Error opening file"<<std::endl;
}

int main(){
    part1();
    part2();

    return 0;
}