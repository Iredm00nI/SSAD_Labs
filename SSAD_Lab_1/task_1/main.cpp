#include <iostream>

using namespace std;

int main() {
    int time;
    cin >> time;

    int hours = time / 3600;
    string hoursString = to_string(hours);
    if (hours < 10) hoursString = "0" + hoursString;
    time = time - hours * 3600;

    int minutes = time / 60;
    string minutesString = to_string(minutes);
    if (minutes < 10) minutesString = "0" + minutesString;
    time = time - minutes * 60;

    int seconds = time;
    string secondsString = to_string(seconds);
    if (seconds < 10) secondsString = "0" + secondsString;

    cout << hoursString << ":" << minutesString << ":" << secondsString << endl;
    return 0;
}
