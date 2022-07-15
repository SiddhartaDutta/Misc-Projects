#include <random>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

void getPrintParams(int& perSec, int& secs, int& length, bool& format, ostream& output, istream& input);
void printText(int length, bool format, ostream& output);

int main(){
    
    // Ask user for per sec + how many secs + how long each random string is + string format
    int perSec, secs, length;
    bool format = true;

    getPrintParams(perSec, secs, length, format, cout, cin);

    int timeout = 60000/perSec;

    // Print
    while(true){

        printText(length, format, cout);
         
        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
    }
    
}

void getPrintParams(int& perSec, int& secs, int& length, bool& format, ostream& output, istream& input){

    output << "Input # of strings per second to be printed: ";
    input >> perSec;

    output << "Input # of secs (duration): ";
    input >> secs;

    output << "Input string length: ";
    input >> length;

    output << "Would you like strings (input 0) or JSON (input 1): ";
    input >> format;

    output << '\n';

}

void printText(int length, bool format, ostream& output){

    string outputString = "";

    for(int i = 0; i < length; i++){
        outputString += 'a' + (rand()%26);
    }

    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

    if(format){
        string temp = '{' + outputString + '}';
        outputString = temp;
    }

    output << ctime(&timenow);
    output << "> " << outputString << "\n\n";

}