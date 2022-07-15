#include <random>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main(){
    
    // Ask user for per sec + how many secs + how long each random string is + string format

    // Print
    
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

    output << ctime(&timenow) << ": " << outputString;

}