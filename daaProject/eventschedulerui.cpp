# Event Scheduling System - C++ UI Version (Console Based)

/*
 This version simulates a UI using formatted console output.
 It shows step-by-step scheduling with visual timeline.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int start, end;
};

bool compare(Event a, Event b) {
    return a.end < b.end;
}

// Function to draw simple timeline
void drawTimeline(vector<Event> events, vector<Event> selected) {
    cout << "\nTimeline:\n";

    for (auto e : events) {
        cout << "(" << e.start << "," << e.end << ") ";

        bool isSelected = false;
        for (auto s : selected) {
            if (s.start == e.start && s.end == e.end) {
                isSelected = true;
                break;
            }
        }

        if (isSelected)
            cout << "[SELECTED]";
        else
            cout << "[PENDING/REJECTED]";

        cout << "\n";
    }
    cout << "--------------------------\n";
}

int main() {
    int n;
    cout << "===== Event Scheduling Visualizer =====\n";
    cout << "Enter number of events: ";
    cin >> n;

    vector<Event> events(n);

    for (int i = 0; i < n; i++) {
        cout << "\nEvent " << i + 1 << endl;
        cout << "Start: ";
        cin >> events[i].start;
        cout << "End: ";
        cin >> events[i].end;
    }

    sort(events.begin(), events.end(), compare);

    cout << "\nEvents sorted by end time:\n";
    for (auto e : events) {
        cout << "(" << e.start << ", " << e.end << ")\n";
    }

    vector<Event> selected;
    int last_end = -1;

    cout << "\n===== Step-by-Step Execution =====\n";

    for (auto e : events) {
        cout << "\nChecking Event (" << e.start << ", " << e.end << ")";

        if (e.start >= last_end) {
            cout << " --> SELECTED\n";
            selected.push_back(e);
            last_end = e.end;
        } else {
            cout << " --> REJECTED\n";
        }

        drawTimeline(events, selected);
    }

    cout << "\n===== Final Schedule =====\n";
    for (auto e : selected) {
        cout << "(" << e.start << ", " << e.end << ")\n";
    }

    cout << "Total Selected: " << selected.size() << endl;

    return 0;
}
