#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

struct Content {
    string title;
    string platform;
    long long views = 0;
    string status;
};

const string DATA_FILE = "content_list.txt";

string cleanField(string value) {
    // Keep the pipe delimiter reserved for the file format.
    for (char& c : value) if (c == '|') c = '/';
    return value;
}

vector<Content> loadContent() {
    vector<Content> items;
    ifstream in(DATA_FILE);
    string line;
    while (getline(in, line)) {
        size_t a = line.find('|');
        size_t b = a == string::npos ? a : line.find('|', a + 1);
        size_t c = b == string::npos ? b : line.find('|', b + 1);
        if (a == string::npos || b == string::npos || c == string::npos) continue;
        Content item;
        item.title = line.substr(0, a);
        item.platform = line.substr(a + 1, b - a - 1);
        try { item.views = stoll(line.substr(b + 1, c - b - 1)); }
        catch (...) { item.views = 0; }
        item.status = line.substr(c + 1);
        items.push_back(item);
    }
    return items;
}

bool saveContent(const vector<Content>& items) {
    ofstream out(DATA_FILE); // overwrite with the complete updated list
    if (!out) return false;
    for (const auto& item : items) {
        out << cleanField(item.title) << '|'
            << cleanField(item.platform) << '|'
            << item.views << '|'
            << cleanField(item.status) << '\n';
    }
    return static_cast<bool>(out);
}

void displayContent(const vector<Content>& items) {
    if (items.empty()) { cout << "No content items found.\n"; return; }
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i].title
             << " | Platform: " << items[i].platform
             << " | Views: " << items[i].views
             << " | Status: " << items[i].status << '\n';
    }
}

long long readViews() {
    long long views;
    while (true) {
        if (cin >> views && views >= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return views;
        }
        cout << "Enter a non-negative whole number for views: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    cout << "=== Creator Dashboard Lite ===\n";
    while (true) {
        cout << "\n1. Add content idea\n2. View all content\n3. Update status\n"
             << "4. Delete content\n0. Save and exit\nChoice: ";
        int choice;
        if (!(cin >> choice)) return 0;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        auto items = loadContent();

        if (choice == 1) {
            Content item;
            cout << "Content title: "; getline(cin, item.title);
            cout << "Platform: "; getline(cin, item.platform);
            cout << "Views (0 if not published): "; item.views = readViews();
            cout << "Status (Idea/Planned/Published): "; getline(cin, item.status);
            if (item.title.empty() || item.platform.empty() || item.status.empty()) {
                cout << "Title, platform, and status cannot be empty.\n";
                continue;
            }
            items.push_back(item);
            if (saveContent(items)) cout << "Content saved to " << DATA_FILE << ".\n";
            else cerr << "Error saving file.\n";
        } else if (choice == 2) {
            displayContent(items);
        } else if (choice == 3) {
            displayContent(items);
            if (items.empty()) continue;
            cout << "Item number to update: ";
            size_t index;
            if (!(cin >> index)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (index == 0 || index > items.size()) { cout << "Invalid item number.\n"; continue; }
            cout << "New status: ";
            getline(cin, items[index - 1].status);
            if (items[index - 1].status.empty()) { cout << "Status cannot be empty.\n"; continue; }
            if (saveContent(items)) cout << "Status updated.\n";
            else cerr << "Error saving file.\n";
        } else if (choice == 4) {
            displayContent(items);
            if (items.empty()) continue;
            cout << "Item number to delete: ";
            size_t index;
            if (!(cin >> index)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (index == 0 || index > items.size()) { cout << "Invalid item number.\n"; continue; }
            cout << "Delete '" << items[index - 1].title << "'? (y/n): ";
            char confirm; cin >> confirm;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (confirm == 'y' || confirm == 'Y') {
                items.erase(items.begin() + static_cast<long>(index - 1));
                if (saveContent(items)) cout << "Content deleted.\n";
                else cerr << "Error saving file.\n";
            } else cout << "Deletion cancelled.\n";
        } else if (choice == 0) {
            cout << "All changes are saved in " << DATA_FILE << ". Goodbye!\n";
            return 0;
        } else {
            cout << "Invalid choice.\n";
        }
    }
}
