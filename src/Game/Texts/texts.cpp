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

void show_title()
{
    std::cout << R"(
/----------------------------------------------------------------------------------------------------------/
/---------------------------- Welcome dear stranger to Dungeon Adventure ! --------------------------------/
/----------------------------------------------------------------------------------------------------------/

In this dungeon, you will have to fight against many creatures, each one more terrifying than the other ! 
What's the point you'll ask me ? For the beauty of battlefield ? To save a princess ? For the glory ?
Well, that's a mystery ! Yes, you'll have to climb to the top of the dungeon to find out !

Let's just hope that luck is on your side ! Maybe you'll find treasures, maybe you'll find more monsters ! 

So, ready to take your sword and your shield ?                                               
    )" << std::endl;
}

void display_intro()
{
    std::cout << R"(
Excellent ! 
You'll see it's a marvellous adventure you won't regret it !
Ah ! But I'm missing all my duties !
    )" << std::endl;
}

void good_name()
{
    std::cout << R"(
Well, you should sue your parents for this !
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
    while (true) {
        show_commands();
        const auto command = get_character_from_player();
        if (command == 'y') {
            good_name();
            break;
        }
        else if (command == 'n') {
            bad_name(hero);
            show_player_name(hero);
            break;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
    return hero;
}

void did_fight()
{
    std::cout << R"(
Ah ! Here is a proud fighter ! 
And did you even won a fight ?
    )" << std::endl;
    while (true) {
        show_commands();
        const auto command = get_character_from_player();
        if (command == 'y') {
            std::cout << "You know that lying won't help you win, right ?" << std::endl;
            break;
        }
        else if (command == 'n') {
            std::cout << "Ah ... Will have to review the basics from what I see ..." << std::endl;
            break;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
}

void didnt_fight()
{
    std::cout << R"(
What ?! And you accept randoms quests like that from a complete stranger ? 
I wonder if you wouldn't be suicidal on the edge...
Well I can't let you go like that !
    )" << std::endl;
}

void tutorial()
{
    std::cout << R"(
This dungeon is made up of several rooms! I have never gotten very far, but I would say there are at least ten.

There are three types of rooms:
- Small rooms with only one monster guarding the door
- Highly secure rooms with two powerful monsters inside !
- And if you are lucky rooms full of treasures !

Unfortunately for you - but for my personnal pleasure - you will have to fight these monsters with ferocity !
Do not worry, I will not let you go empty-handed! I will leave you my wooden sword !

It may be useless in battle, but it can be a very good toothpick for dragons !
In any case, if during a fight you get the idea of running away, try your luck ! 
But I do not promise that your opponent will let you go out like that. . .

And of course, do not play the big dummy ! 
There are certainly times to hit, but there are also times to heal yourself !
Believe me, I have seen a lot of paladdins with a lot of muscles but nothing in the brain !
The result: they never came out of that dungeon. . . But I believe in you, I like your stupid face !

Anyway, I think with all this you should be ready!

    )" << std::endl;
}

void show_tutorial()
{
    tutorial();
    std::cout << "Did you understand everything ?" << std::endl;
    while (true) {
        show_commands();
        const auto command = get_character_from_player();
        if (command == 'y') {
            std::cout << "You're smarter than I thought ! Good for you ! Now let's go on an adventure !" << std::endl;
            break;
        }
        else if (command == 'n') {
            std::cout << "Mmmm there's no point in skipping the explanations you know ? Well, you're lucky I'm in a good mood today ! I'll explain it again but this time listen carefully !" << std::endl;
            tutorial();
            break;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
}

void no_tutorial()
{
    std::cout << "Oh ? Are you really sure ?" << std::endl;
    while (true) {
        show_commands();
        const auto command = get_character_from_player();
        if (command == 'y') {
            std::cout << "All right then ! But I warned you !" << std::endl;
            break;
        }
        else if (command == 'n') {
            std::cout << "But you should know ! So let's go for explanations !" << std::endl;
            show_tutorial();
            break;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
}

void display_game()
{
    std::cout << R"(
Now we're going to enter the dungeon !
But tell me before you go inside, have you ever fought monsters before ?
    )" << std::endl;
    while (true) {
        show_commands();
        const auto command = get_character_from_player();
        if (command == 'y') {
            did_fight();
            break;
        }
        else if (command == 'n') {
            didnt_fight();
            break;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
    std::cout << "Do you want me to explain a bit how it works here ?" << std::endl;
    while (true) {
        show_commands();
        const auto commands = get_character_from_player();
        if (commands == 'y') {
            show_tutorial();
            break;
        }
        else if (commands == 'n') {
            no_tutorial();
            break;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
}

player display_title_screen()
{
    player hero;
    show_title();
    while (true) {
        show_commands();
        const auto command = get_character_from_player();
        if (command == 'y') {
            display_intro();
            hero = create_player();
            display_game();
            break;
        }
        else if (command == 'n') {
            std::cout << "Really ? Ah ... Too bad adventurer ... You don't have the choice ! MOUAH AHAHAHHH ! Inside you go !" << std::endl;
            break;
        }
        else {
            std::cout << unknow << std::endl;
        }
    }
    return hero;
}