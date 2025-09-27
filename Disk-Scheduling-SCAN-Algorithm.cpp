#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int scan(vector<int>& requests, int start, int diskEnd) {
    int totalSeekTime = 0;
    int currentPosition = start;
    vector<int> sequence;
    vector<int> right, left; 

    for (int req : requests) {
        if (req >= start) {
            right.push_back(req);
        } else {
            left.push_back(req);
        }
    }

    sort(right.begin(), right.end());
    sort(left.begin(), left.end(), greater<int>());

    for (int req : right) {
        totalSeekTime += abs(currentPosition - req);
        sequence.push_back(req);
        currentPosition = req;
    }

    if (currentPosition != diskEnd) {
        totalSeekTime += abs(currentPosition - diskEnd);
        sequence.push_back(diskEnd);
        currentPosition = diskEnd;
    }

    for (int req : left) {
        totalSeekTime += abs(currentPosition - req);
        sequence.push_back(req);
        currentPosition = req;
    }

    cout << "Sequence of tracks visited: " << start;
    for (int track : sequence) {
        cout << " -> " << track;
    }
    cout << endl;

    return totalSeekTime;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int start = 50; 
    int diskEnd = 199; 

    int totalSeekTime = scan(requests, start, diskEnd);
    cout << "SCAN Total Seek Time: " << totalSeekTime << endl;

    return 0;
}
