#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int start;
    int end;
};

// Comparator for sorting by end time
bool compare(Event a, Event b) {
    return a.end < b.end;
}

int main() {
    int n;
    cout << "Enter number of events: ";
    cin >> n;

    vector<Event> events(n);

    // Input events
    for (int i = 0; i < n; i++) {
        cout << "\nEvent " << i + 1 << endl;
        cout << "Start time: ";
        cin >> events[i].start;
        cout << "End time: ";
        cin >> events[i].end;
    }

    // Sort events by end time
    sort(events.begin(), events.end(), compare);

    cout << "\nSorted Events (by end time):\n";
    for (auto e : events) {
        cout << "(" << e.start << ", " << e.end << ")\n";
    }

    vector<Event> selected;
    int last_end = -1;

    cout << "\nStep-by-step scheduling:\n";

    for (auto e : events) {
        cout << "\nChecking event (" << e.start << ", " << e.end << ")";

        if (e.start >= last_end) {
            selected.push_back(e);
            last_end = e.end;
            cout << " --> Selected";
        } else {
            cout << " --> Rejected";
        }
    }

    cout << "\n\nFinal Selected Events:\n";
    for (auto e : selected) {
        cout << "(" << e.start << ", " << e.end << ")\n";
    }

    cout << "Total Events Selected: " << selected.size() << endl;

    return 0;
}