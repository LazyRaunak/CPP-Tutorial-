#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


int processResponse(const string &response, const string &answerKey){
    int score{0};
    for(size_t i = 0; i<answerKey.size(); ++i){
        if(response.at(i) == answerKey.at(i))
            score++;
    }
    return score;
}

void printHeader(){
    cout<<setw(15)<<left<<"student"
        <<setw(5)<<"Score"
        <<setw(20)<<setfill('-')<<endl;
    
    cout<<setfill(' ');
}

void printFooter(double avg){
    cout<<setw(20)<<setfill('-')<<""<<endl;
    cout<<setfill(' ');
    cout<<setw(15)<<left<<"Average score"
        <<setw(5)<<right<<avg;
}

void printStudent(const string &student, int score){
    cout<<setprecision(1)<<fixed;
    cout<<setw(15)<<left<<student
        <<setw(5)<<right<<score<<endl;
}


int main(){
    ifstream file;
    string answerKey{}, name{}, response{};
    int rSum{0}, totalStudents{0};
    double avg{0.0};

    file.open("file3.txt");
    if(!file){
        cerr<<"Error opening file"<<endl;
        return 1;
    }

    file>>answerKey;

    while(file>>name>>response){
        ++totalStudents;
        int score = processResponse(response, answerKey);
        rSum += score;
        printStudent(name, score);
    }

    if(totalStudents != 0){
        avg = static_cast<double>(rSum)/totalStudents;
    }

    printFooter(avg);

    file.close();
    cout<<endl<<endl;

    return 0;
}

