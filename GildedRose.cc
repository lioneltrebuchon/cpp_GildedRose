#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{   
    // TODO: legendary items.
    // // Legendary items are immutable.
    // for (int i = 0; i < legendaryItems.size(); i++)
    // {
    //     legendaryItems[i].quality = 80;
    //     legendaryItems[i].sellIn = -1;
    // }

    // Update all non-legendary items.
    for (int i = 0; i < items.size(); i++)
    {
        // Classic items.
        // Quality decreases by 1 as long as due date is in the future (sellIn>=0),
        // and by 2 when due date is in the past (sellIn<0).
        if (items[i].name != "Aged Brie" && items[i].name != "Backstage passes to a TAFKAL80ETC concert" && items[i].name != "Sulfuras, Hand of Ragnaros")
        {
            if (items[i].quality > 0)
            {
                if (items[i].sellIn < 0)
                {
                    items[i].quality = max(items[i].quality - 2,0);   
                }
                else
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        // Special items.
        // Follow their own rules.
        else
        {
            if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
            {
                if (items[i].sellIn < 11)
                {
                    items[i].quality = min(items[i].quality + 2, 50);
                }
                else if (items[i].sellIn < 6)
                {
                    items[i].quality = min(items[i].quality + 3, 50);
                }
                else if (items[i].sellIn < 0)
                {
                    items[i].quality = 0;   
                }
            }
            else if (items[i].name != "Aged Brie")
            {
                items[i].quality = min(items[i].quality + 1, 50);
            }
            else if (items[i].name != "Sulfuras, Hand of Ragnaros")
            {
                items[i].quality = 80;
                items[i].sellIn = -1;
            }
            else
            {
                cout << items[i].name << "is a special item whose behaviour has not been defined. Abort!"
            }
        }

    // A day passes by.
    items[i].sellIn -= 1;        
    }
}
