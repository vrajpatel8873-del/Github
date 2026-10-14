#include <iostream>
#include <string>
using namespace std;

class Song {
private:
    string title;
    string artist;
public:
    Song(string t, string a) : title(t), artist(a) {}
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    void setTitle(const string& t) { if (!t.empty()) title = t; }
    void setArtist(const string& a) { if (!a.empty()) artist = a; }
};

class InstaStory {
protected:
    int storyViews;
public:
    explicit InstaStory(int views) : storyViews(views) {}
};
class SponsoredStory : public InstaStory {
public:
    explicit SponsoredStory(int views) : InstaStory(views) {}
    void displayViews() const { cout << "Story views: " << storyViews << '\n'; }
};

class Product {
public:
    virtual void upload() const = 0;
    virtual ~Product() = default;
};
class Electronics : public Product {
public:
    void upload() const override { cout << "Electronics product uploaded to marketplace.\n"; }
};
class Clothing : public Product {
public:
    void upload() const override { cout << "Clothing product uploaded to marketplace.\n"; }
};

class UserProfile {
private:
    string phoneNumber;
public:
    void setPhoneNumber(const string& phone) {
        if (phone.size() == 10) phoneNumber = phone;
        else cout << "Phone number must contain exactly 10 digits.\n";
    }
    string getPhoneNumber() const { return phoneNumber; }
};

int main() {
    Song song("Kesariya", "Arijit Singh");
    cout << song.getTitle() << " by " << song.getArtist() << '\n';
    song.setTitle("Updated Song Title");
    cout << "Updated title: " << song.getTitle() << '\n';

    SponsoredStory story(12500);
    story.displayViews();

    Electronics electronics;
    Clothing clothing;
    Product* product = &electronics;
    product->upload();
    product = &clothing;
    product->upload();

    UserProfile profile;
    profile.setPhoneNumber("9876543210");
    cout << "Phone: " << profile.getPhoneNumber() << '\n';
    profile.setPhoneNumber("123");
    cout << "\nEncapsulation controls access to private data; abstraction exposes a simple interface "
            "while hiding implementation details.\n";
}
