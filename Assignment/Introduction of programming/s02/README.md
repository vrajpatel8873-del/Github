# Session 2 – Setup (macOS, MacBook Air M4)
1. Install: `xcode-select --install` (installs Apple's command-line tools).
2. Verify (Task 1): `gcc --version`  (on macOS `gcc` is Apple clang, that's fine).
   For real GNU GCC: `brew install gcc` then `gcc-15 --version` (version number may differ).
3. IDE: VS Code + "C/C++" extension. Create `hello.c`.
4. Compile: `gcc hello.c -o hello`
5. Run: `./hello`  -> `Hello, Instagram World!`
(On Windows the output would be hello.exe.)
