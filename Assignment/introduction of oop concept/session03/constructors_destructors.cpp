#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Playlist {
private:
    string name;

public:
    Playlist() : name("My Favourites") {
        cout << "Welcome! Playlist created: " << name << '\n';
    }
    explicit Playlist(const string& playlistName) : name(playlistName) {}
    Playlist(const Playlist& other) : name(other.name) {}
    ~Playlist() {
        ofstream file("autosave.txt");
        if (file) file << name << '\n';
        cout << "Auto-saved playlist '" << name << "' to autosave.txt\n";
    }
    string getName() const { return name; }
};

class Product {
private:
    string productName;
    double price;
    double rating;
public:
    Product(const string& n, double p, double r)
        : productName(n), price(p), rating(r) {}
    void displayInfo() const {
        cout << productName << " | Rs. " << price << " | Rating: " << rating << "/5\n";
    }
};

class Movie {
private:
    string title;
    int year;
public:
    Movie(string t, int y) : title(t), year(y) {}
    Movie(const Movie& other) : title(other.title), year(other.year) {}
    void display() const { cout << title << " (" << year << ")\n"; }
};

class Ticket {
public:
    Ticket() { cout << "Ticket booked.\n"; }
    ~Ticket() { cout << "Saving your ticket...\n"; }
};

int main() {
    {
        Playlist defaultPlaylist;
        Playlist namedPlaylist("OOP Revision");
        Playlist copiedPlaylist(namedPlaylist);
        cout << "Copied playlist: " << copiedPlaylist.getName() << '\n';

        Product product("Wireless Headphones", 2499.00, 4.5);
        product.displayInfo();

        Movie original("3 Idiots", 2009);
        Movie copy(original);
        cout << "Original: "; original.display();
        cout << "Copy: "; copy.display();

        Ticket ticket;
        cout << "Ticket will be saved when the object leaves scope.\n";
    } // destructors run here
    return 0;
}
