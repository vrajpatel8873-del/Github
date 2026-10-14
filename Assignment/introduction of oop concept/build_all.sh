#!/usr/bin/env bash
set -euo pipefail
mkdir -p build
CXX="${CXX:-g++}"
CC="${CC:-gcc}"
"$CC" -std=c11 -Wall -Wextra -pedantic session01/tasklist_procedural.c -o build/tasklist_procedural
for source in \
  session01/tasklist_oop.cpp \
  session02/classes_objects.cpp \
  session03/constructors_destructors.cpp \
  session04/inheritance.cpp \
  session05/polymorphism.cpp \
  session06/encapsulation_abstraction.cpp \
  session07/file_handling.cpp \
  mini_project/creator_dashboard_lite.cpp
do
  name="$(basename "$source" .cpp)"
  "$CXX" -std=c++17 -Wall -Wextra -pedantic "$source" -o "build/$name"
done
echo "All programs compiled successfully into build/."
