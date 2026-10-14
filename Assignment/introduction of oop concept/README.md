# OOP Module 4 — C++ Solutions

This repository contains solutions for the tasks shown in the TOPS Software Engineering Module 4 screenshots:
- Session 1: Procedural vs object-oriented thinking
- Session 2: Classes and objects
- Session 3: Constructors and destructors
- Session 4: Inheritance
- Session 5: Polymorphism
- Session 6: Encapsulation and abstraction
- Session 7: File handling
- Mini Project 2: Creator Dashboard Lite

Most tasks are implemented in C++ to keep the practice consistent with the module's C++ examples. Session 1 also includes a procedural C version. Java-specific exercises in the screenshot are represented with equivalent C++ examples demonstrating the same OOP concept.

## Requirements
- A C++17 compiler such as `g++`
- A C compiler such as `gcc` for the procedural C example

## Compile and run

From this repository's root folder:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic session01/tasklist_oop.cpp -o tasklist_oop && ./tasklist_oop
g++ -std=c++17 -Wall -Wextra -pedantic session02/classes_objects.cpp -o classes_objects && ./classes_objects
g++ -std=c++17 -Wall -Wextra -pedantic session03/constructors_destructors.cpp -o constructors_destructors && ./constructors_destructors
g++ -std=c++17 -Wall -Wextra -pedantic session04/inheritance.cpp -o inheritance && ./inheritance
g++ -std=c++17 -Wall -Wextra -pedantic session05/polymorphism.cpp -o polymorphism && ./polymorphism
g++ -std=c++17 -Wall -Wextra -pedantic session06/encapsulation_abstraction.cpp -o encapsulation_abstraction && ./encapsulation_abstraction
g++ -std=c++17 -Wall -Wextra -pedantic session07/file_handling.cpp -o file_handling && ./file_handling
g++ -std=c++17 -Wall -Wextra -pedantic mini_project/creator_dashboard_lite.cpp -o creator_dashboard_lite && ./creator_dashboard_lite
gcc -std=c11 -Wall -Wextra -pedantic session01/tasklist_procedural.c -o tasklist_procedural && ./tasklist_procedural
```

A convenience script is included as `build_all.sh`. It compiles all programs into a `build/` folder.

## Session notes
- `session01/tasklist_procedural.c`: global array and `markTaskDone()` in procedural C.
- `session01/tasklist_oop.cpp`: `Task` and `TaskList` classes; demonstrates adding and completing tasks.
- `session02/classes_objects.cpp`: `Playlist`, toggling visibility, song list, and `FoodOrder`.
- `session03/constructors_destructors.cpp`: default/parameterized/copy constructors, destructor output, product details, movie copying, and playlist auto-save to `autosave.txt`.
- `session04/inheritance.cpp`: base class, YouTuber, Podcaster, multilevel `GamingYouTuber`, and `InstagramInfluencer`.
- `session05/polymorphism.cpp`: method overloading and overriding, runtime dispatch, product search overloads, and `MusicPlayer`/`SpotifyPlayer`.
- `session06/encapsulation_abstraction.cpp`: private song fields with getters/setters, protected story views, abstract `Product`, concrete derived classes, and private phone number with validation.
- `session07/file_handling.cpp`: interactive menu for writing/reading/appending songs, creating a three-product wishlist, and counting usernames in `insta_followers.txt`.
- `mini_project/creator_dashboard_lite.cpp`: add, list, update status, and delete content ideas; stores records in `content_list.txt`.

## File handling data
The file-handling program creates `my_fav_songs.txt` and `wishlist.txt` in the current working directory. For task 5, create `insta_followers.txt` with one username per line before selecting option 5.

The Creator Dashboard saves records in `content_list.txt` using this format:

```text
title|platform|views|status
```

Run the mini project from the repository root so the data file is created there. The file is intentionally plain text for this beginner exercise.

## Suggested GitHub upload
1. Extract the ZIP.
2. Create a new GitHub repository.
3. Upload the extracted folders and `README.md`, or run `git init`, `git add .`, `git commit -m "Add OOP Module 4 solutions"`, and push to your GitHub repository.
