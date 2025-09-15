#include <iostream>
#include <string>
using namespace std;

char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z') return char(c - 'A' + 'a');
    return c;
}
int ciCompare(const string& a, const string& b) {
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        char ca = toLowerChar(a[i]), cb = toLowerChar(b[j]);
        if (ca < cb) return -1;
        if (ca > cb) return 1;
        ++i; ++j;
    }
    if (a.size() < b.size()) return -1;
    if (a.size() > b.size()) return 1;
    return 0;
}

struct PNodeSF {
    string name;
    PNodeSF* next;
    PNodeSF(const string& n) : name(n), next(nullptr) {}
};

struct SingleFlight {
    PNodeSF* head = nullptr;
    bool reserve(const string& name) {
        PNodeSF* n = new PNodeSF(name);
        if (!head || ciCompare(name, head->name) < 0) {
            if (head && ciCompare(name, head->name) == 0) { delete n; return false; }
            n->next = head; head = n; return true;
        }
        PNodeSF* cur = head;
        while (cur->next && ciCompare(cur->next->name, name) < 0) cur = cur->next;
        if (cur->next && ciCompare(cur->next->name, name) == 0) { delete n; return false; }
        n->next = cur->next; cur->next = n; return true;
    }
    bool cancel(const string& name) {
        if (!head) return false;
        if (ciCompare(head->name, name) == 0) { PNodeSF* t = head; head = head->next; delete t; return true; }
        PNodeSF* cur = head;
        while (cur->next && ciCompare(cur->next->name, name) != 0) cur = cur->next;
        if (!cur->next) return false;
        PNodeSF* t = cur->next; cur->next = cur->next->next; delete t; return true;
    }
    bool isReserved(const string& name) const {
        for (PNodeSF* p = head; p; p = p->next)
            if (ciCompare(p->name, name) == 0) return true;
        return false;
    }
    void display() const {
        if (!head) { cout << "No passengers yet.\n"; return; }
        for (PNodeSF* p = head; p; p = p->next)
            cout << p->name << (p->next ? ", " : "\n");
    }
    void clear() {
        while (head) { PNodeSF* t = head; head = head->next; delete t; }
    }
};

struct PNode {
    string name;
    PNode* next;
    PNode(const string& n) : name(n), next(nullptr) {}
};

struct FNode {
    string flightId;
    PNode* pHead;
    FNode* next;
    FNode(const string& id) : flightId(id), pHead(nullptr), next(nullptr) {}
};

struct MultiFlights {
    FNode* fHead = nullptr;
    FNode* ensureFlight(const string& id) {
        FNode* nn = new FNode(id);
        if (!fHead || ciCompare(id, fHead->flightId) < 0) {
            if (fHead && ciCompare(id, fHead->flightId) == 0) { delete nn; return fHead; }
            nn->next = fHead; fHead = nn; return nn;
        }
        FNode* cur = fHead;
        while (cur->next && ciCompare(cur->next->flightId, id) < 0) cur = cur->next;
        if (cur->next && ciCompare(cur->next->flightId, id) == 0) { delete nn; return cur->next; }
        nn->next = cur->next; cur->next = nn; return nn;
    }
    bool reserve(const string& flightId, const string& name) {
        FNode* f = ensureFlight(flightId);
        PNode* n = new PNode(name);
        if (!f->pHead || ciCompare(name, f->pHead->name) < 0) {
            if (f->pHead && ciCompare(name, f->pHead->name) == 0) { delete n; return false; }
            n->next = f->pHead; f->pHead = n; return true;
        }
        PNode* cur = f->pHead;
        while (cur->next && ciCompare(cur->next->name, name) < 0) cur = cur->next;
        if (cur->next && ciCompare(cur->next->name, name) == 0) { delete n; return false; }
        n->next = cur->next; cur->next = n; return true;
    }
    bool cancel(const string& flightId, const string& name) {
        FNode* f = fHead;
        while (f && ciCompare(f->flightId, flightId) != 0) f = f->next;
        if (!f) return false;
        if (!f->pHead) return false;
        if (ciCompare(f->pHead->name, name) == 0) { PNode* t = f->pHead; f->pHead = f->pHead->next; delete t; return true; }
        PNode* cur = f->pHead;
        while (cur->next && ciCompare(cur->next->name, name) != 0) cur = cur->next;
        if (!cur->next) return false;
        PNode* t = cur->next; cur->next = cur->next->next; delete t; return true;
    }
    bool isReserved(const string& flightId, const string& name) const {
        FNode* f = fHead;
        while (f && ciCompare(f->flightId, flightId) != 0) f = f->next;
        if (!f) return false;
        for (PNode* p = f->pHead; p; p = p->next)
            if (ciCompare(p->name, name) == 0) return true;
        return false;
    }
    void display(const string& flightId) const {
        FNode* f = fHead;
        while (f && ciCompare(f->flightId, flightId) != 0) f = f->next;
        if (!f) { cout << "Flight not found.\n"; return; }
        if (!f->pHead) { cout << "No passengers on this flight.\n"; return; }
        cout << "Passengers on flight " << f->flightId << ": ";
        for (PNode* p = f->pHead; p; p = p->next)
            cout << p->name << (p->next ? ", " : "\n");
    }
    void displayAll() const {
        if (!fHead) { cout << "No flights available.\n"; return; }
        for (FNode* f = fHead; f; f = f->next) {
            cout << "Flight " << f->flightId << ": ";
            if (!f->pHead) { cout << "[No passengers]\n"; continue; }
            PNode* p = f->pHead;
            while (p) { cout << p->name << (p->next ? ", " : "\n"); p = p->next; }
        }
    }
    void clear() {
        while (fHead) {
            FNode* f = fHead; fHead = fHead->next;
            while (f->pHead) { PNode* t = f->pHead; f->pHead = f->pHead->next; delete t; }
            delete f;
        }
    }
};

int main() {
    cout << "Welcome! Choose a mode:\n1) Single Flight\n2) Multiple Flights\n> ";
    int mode; if (!(cin >> mode)) return 0;

    if (mode == 1) {
        SingleFlight sf;
        while (true) {
            cout << "\nSingle Flight Menu\n";
            cout << "1. Reserve a ticket\n";
            cout << "2. Cancel a reservation\n";
            cout << "3. Check a reservation\n";
            cout << "4. Show all passengers\n";
            cout << "5. Exit\n> ";
            int ch; if (!(cin >> ch)) break;
            if (ch == 1) {
                string name; cout << "Passenger name: "; cin >> name;
                cout << (sf.reserve(name) ? "Ticket reserved.\n" : "Already reserved.\n");
            } else if (ch == 2) {
                string name; cout << "Passenger name: "; cin >> name;
                cout << (sf.cancel(name) ? "Reservation cancelled.\n" : "Not found.\n");
            } else if (ch == 3) {
                string name; cout << "Passenger name: "; cin >> name;
                cout << (sf.isReserved(name) ? "Yes, reserved.\n" : "No reservation.\n");
            } else if (ch == 4) {
                sf.display();
            } else if (ch == 5) {
                sf.clear(); break;
            } else {
                cout << "Invalid option.\n";
            }
        }
    } else if (mode == 2) {
        MultiFlights mf;
        while (true) {
            cout << "\nMultiple Flights Menu\n";
            cout << "1. Reserve a ticket\n";
            cout << "2. Cancel a reservation\n";
            cout << "3. Check a reservation\n";
            cout << "4. Show passengers of a flight\n";
            cout << "5. Show all flights\n";
            cout << "6. Exit\n> ";
            int ch; if (!(cin >> ch)) break;
            if (ch == 1) {
                string fid, name; cout << "Flight ID: "; cin >> fid; cout << "Passenger name: "; cin >> name;
                cout << (mf.reserve(fid, name) ? "Ticket reserved.\n" : "Already reserved.\n");
            } else if (ch == 2) {
                string fid, name; cout << "Flight ID: "; cin >> fid; cout << "Passenger name: "; cin >> name;
                cout << (mf.cancel(fid, name) ? "Reservation cancelled.\n" : "Not found.\n");
            } else if (ch == 3) {
                string fid, name; cout << "Flight ID: "; cin >> fid; cout << "Passenger name: "; cin >> name;
                cout << (mf.isReserved(fid, name) ? "Yes, reserved.\n" : "No reservation.\n");
            } else if (ch == 4) {
                string fid; cout << "Flight ID: "; cin >> fid; mf.display(fid);
            } else if (ch == 5) {
                mf.displayAll();
            } else if (ch == 6) {
                mf.clear(); break;
            } else {
                cout << "Invalid option.\n";
            }
        }
    } else {
        cout << "Invalid mode.\n";
    }
    return 0;
}
