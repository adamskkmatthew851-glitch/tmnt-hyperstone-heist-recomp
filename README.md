# TMNT: The Hyperstone Heist - Static Recompilation

A work-in-progress static recompilation of **Teenage Mutant Ninja Turtles: The Hyperstone Heist** (SEGA Genesis / Mega Drive) into native C/C++, powered by the [segagenesisrecomp]*(https://github.com/mstan/segagenesisrecomp)** framework.

> **Status:** Early WIP. Automated CI builds are currently compiling, and active game-specific debugging/fixes are ongoing.

---

## ⚠️ Legal Notice
This repository **does not** contain copyrighted game assets, music, or ROM data. To build or run this project, you must provide your own legally obtained copy of *TMNT: The Hyperstone Heist* (USA) ROM.

---

## 🚀 Quick Start (For Testers & New Devs)

### Option 1: Download a Pre-Built Binary (CI)
If you don't want to compile from source, you can grab the latest automated build:
1. Go to the **[Actions](../../actions)** tab at the top of this repository.
2. Click on the most recent workflow run with a green checkmark (✅).
3. Scroll down to the **Artifacts** section and download the build zip.
4. Extract the folder and place your legally obtained ROM file inside (if required by the runtime).

---

### Option 2: Building from Source

#### Prerequisites
Make sure you have the following installed on your system:
* **CMake** (3.21 or newer)
* **C/C++ Compiler** (MinGW-w64 / GCC, Clang, or MSVC supporting C11 and C++17)
* **Python** (3.10 or newer, for code generation scripts)
* **SDL2** development libraries

#### Build Steps (Windows / MinGW)
1. **Clone the repository:**
   ```bash
   git clone https://github.com
   cd tmnt-hyperstone-heist-recomp
   ```

2. **Configure with CMake:**
   ```bash
   cmake -B build -G "MinGW Makefiles"
   ```

3. **Compile the project:**
   ```bash
   cmake --build build --config Release
   ```

4. **Run:**
   Ensure `SDL2.dll` is present in your `build` output directory alongside the compiled executable, then launch the program.

---

## 📁 Repository Structure
* `cmake/` – CMake configuration modules and toolchain helpers.
* `game/` – Game-specific patches, memory hooks, and custom overrides.
* `generated/` – Static C code generated from the original Motorola 68000 machine code.
* `mingw/` – MinGW-specific build configurations and environment files.
* `segagenesisrecomp-master/` – Core static recompilation runtime and CPU/VDP/Audio translation layer.

---

## 🤝 Contributing
Pull requests, bug reports, and hardware/timing accuracy fixes are welcome! 
1. Fork the repository.
2. Create a new branch (`git checkout -b fix/issue-name`).
3. Commit your changes and open a Pull Request.

---

## 🙏 Credits & Acknowledgments
* * **[segagenesisrecomp](https://github.com/mstan/segagenesisrecomp)** by `mstan` for the core Sega Genesis static recompilation framework.
* **Konami** for the original 1992 SEGA Genesis release.
