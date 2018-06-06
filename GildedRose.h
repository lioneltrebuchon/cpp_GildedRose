#include <string>
#include <vector>

using namespace std;

// TODO
// class ItemParameters
// {
// public:
//     int maxQuality = 50;
//     int minQuality = 0;
// }

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

// TODO: legendary items.
// class LegendaryItem
// {
// public:
//     string name;
//     int quality;
//     LegendaryItem(string name, int quality) : name(name), quality(quality) 
//     {}
// };

class GildedRose
{
public:
    vector<Item> & items;
    // vector<LegendaryItem> & legendaryItems;
    GildedRose(vector<Item> & items);
    
    void updateQuality();
};

