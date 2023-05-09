#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int lruPageFaults(const vector<int>& refString, int numFrames) {
    list<int> frameList;
    unordered_map<int, list<int>::iterator> frameMap;
    int pageFaults = 0;

    for (int page : refString) {
        if (frameMap.find(page) == frameMap.end()) {
            if (frameList.size() < numFrames) {
                frameList.push_front(page);
            } else {
                int lruPage = frameList.back();
                frameList.pop_back();
                frameMap.erase(lruPage);
                frameList.push_front(page);
            }
            frameMap[page] = frameList.begin();
            pageFaults++;
        } else {
            frameList.erase(frameMap[page]);
            frameList.push_front(page);
            frameMap[page] = frameList.begin();
        }
    }

    return pageFaults;
}

int main() {
    int length;
   // cout << "Enter the length of the reference string: ";
    cin >> length;

    vector<int> refString(length);
    //cout << "Enter the reference string page numbers: ";
    for (int i = 0; i < length; i++) {
        cin >> refString[i];
    }

    int numFrames;
    //cout << "Enter the number of frames allotted: ";
    cin >> numFrames;

    int faults = lruPageFaults(refString, numFrames);
    cout << faults << endl;

    return 0;
}
