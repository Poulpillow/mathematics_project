#include "texts.h"
#include <iostream>
#include "../Entities/player.h"
#include "../PlayerInput.h"

std::string get_commands()
{
    auto command = get_command_from_player();
    return command;
}

void show_commands()
{
    std::cout << "[Y / N]" << std::endl;
}

void display_death_message()
{
    std::cout << "You died" << std::endl;
}

void show_title()
{
    std::cout << R"(
Welcome to Dungeon Adventure !
Here you will have to fight against many creatures, each one more terrifying than the other ! What's the point ? For the beauty of battle ? To save a princess ? For the glory ?
Well, that's a mystery ! Yes, you'll have to climb to the top of the dungeon to find out !

In this dungeon, you will have to fight monsters in each room ! Let's hope that luck is on your side ! There can be several of them !
In each room there will also be rewards !

So, ready to take your sword and shield ?                                               
    )" << std::endl;
}

void display_intro()
{
    std::cout << R"(
Excellent ! 
You'll see it's a fantastic adventure you won't regret it !
Ah ! But I'm missing all my duties !
    )" << std::endl;
}

void good_name()
{
    std::cout << R"(
Well, you should file a complaint against your parents !
Anyway, enough with the jokes and let's go !
    )" << std::endl;
}

void bad_name(player& hero)
{
    std::cout << "Do you suffer from amnesia ? Come on, I'll give you one more chance !" << std::endl;
    hero = set_player();
}

player create_player()
{
    player hero = set_player();
    show_player_name(hero);
    show_commands();
    const auto command = get_character_from_player();
    if (command == 'y') {
        good_name();
    }
    else if (command == 'n') {
        bad_name(hero);
        show_player_name(hero);
    }
    else {
        std::cout << unknow << std::endl;
    }
    return hero;
}

void did_fight()
{
    std::cout << R"(
Ah ! Here is a proud fighter ! 
And did you already win ?
    )" << std::endl;
    show_commands();
    const auto command = get_character_from_player();
    if (command == 'y') {
        std::cout << "You know that lying won't help you win, right ?" << std::endl;
    }
    else if (command == 'n') {
        std::cout << "Ah ... Will have to review the basics from what I see ..." << std::endl;
    }
    else {
        std::cout << unknow << std::endl;
    }
}

void didnt_fight()
{
    std::cout << R"(
What ?! And you accept randoms quests like that from complete strangers ? I wonder if you wouldn't be suicidal on the edge...
Well I can't let you go like that !
    )" << std::endl;
}

void tutorial()
{
    std::cout << "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec aliquam elementum lectus id sollicitudin. Nunc a vestibulum nunc, a tincidunt leo. Pellentesque sagittis erat nisi, eget laoreet felis tempor pellentesque. Aenean vitae erat odio. Integer sed efficitur nunc. Integer rhoncus dolor a ex ultrices, quis varius tellus pharetra. Suspendisse potenti. Donec eget euismod ligula. Donec vitae dui odio. Proin vel lorem vitae orci ullamcorper consequat. Duis laoreet nisl et ultrices ultricies. Pellentesque lacinia diam enim, vulputate consectetur quam semper a. Quisque rutrum consectetur pellentesque. Nunc commodo ex vel turpis facilisis ullamcorper. Pellentesque vitae ornare tellus." << std::endl;
}

void show_tutorial()
{
    tutorial();
    std::cout << "Did you understand everything ?" << std::endl;
    show_commands();
    const auto command = get_character_from_player();
    if (command == 'y') {
        std::cout << "You're smarter than I thought ! Good for you ! Now let's go on an adventure !" << std::endl;
    }
    else if (command == 'n') {
        std::cout << "Mmmm there's no point in skipping the explanations you know ? Well, you're lucky I'm in a good mood today ! I'll explain it again but this time listen carefully !" << std::endl;
        tutorial();
    }
    else {
        std::cout << unknow << std::endl;
    }
}

void no_tutorial()
{
    std::cout << "Oh ? Are you really sure ?" << std::endl;
    show_commands();
    const auto command = get_character_from_player();
    if (command == 'y') {
        std::cout << "All right then ! But I warned you !" << std::endl;
    }
    else if (command == 'n') {
        std::cout << "But you should know ! Do I need to explain the rules of this world to you ?" << std::endl;
        show_tutorial();
    }
    else {
        std::cout << unknow << std::endl;
    }
}

void display_game()
{
    std::cout << R"(
Good ! Now we're going to enter the dungeon !
But tell me before you go in, have you ever fought monsters before ?
    )" << std::endl;
    show_commands();
    const auto command = get_character_from_player();
    if (command == 'y') {
        did_fight();
    }
    else if (command == 'n') {
        didnt_fight();
    }
    else {
        std::cout << unknow << std::endl;
    }
    std::cout << "Do you want me to explain a bit how it works here ?" << std::endl;
    show_commands();
    const auto commands = get_character_from_player();
    if (commands == 'y') {
        show_tutorial();
    }
    else if (commands == 'n') {
        no_tutorial();
    }
    else {
        std::cout << unknow << std::endl;
    }
}

player display_title_screen()
{
    bool   quit = false;
    player hero;
    show_title();
    show_commands();
    while (!quit) {
        const auto command = get_character_from_player();
        if (command == 'y') {
            display_intro();
            hero = create_player();
            display_game();
        }
        else if (command == 'n') {
            std::cout << "Really ? Ah ... Too bad adventurer ..." << std::endl;
            quit = true;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
    return hero;
}