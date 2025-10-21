

# Pico RS232 Game Interface

A cross-platform C program that communicates with a Raspberry Pi Pico over a serial connection using RS232. The game involves receiving a sequence from the Pico, prompting the user to replicate it, and handling replay requests — all over the COM port.

## 📦 Contents

- `GAME_Code.c` – Main PC-side game logic
- `pc_side.c` – Alternate or extended version of the game logic
- `rs232.h` – RS232 serial communication header (by Teunis van Beelen)
- `rs232.c` – RS232 serial communication implementation (**placeholder**: replace with actual source)

## 🛠️ Build Instructions

### Linux/macOS

```bash
gcc Assignment_2_Extra_Code.c rs232.c -o pico_game
./pico_game
# 🎮 Pico RS232 Game Interface

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://www.cprogramming.com/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-green.svg)](https://github.com/neymo-omar/pico-rs232-game)

A cross-platform C program that communicates with a Raspberry Pi Pico over a serial connection using RS232. The game involves receiving a sequence from the Pico, prompting the user to replicate it, and handling replay requests — all over the COM port.

## 📋 Table of Contents

- [Features](#-features)
- [Prerequisites](#-prerequisites)
- [Installation](#-installation)
- [Usage](#-usage)
- [Project Structure](#-project-structure)
- [Building](#-building)
- [Contributing](#-contributing)
- [License](#-license)

## ✨ Features

- **Serial Communication**: Robust RS232 communication with Raspberry Pi Pico
- **Interactive Game**: Sequence-based game with user input validation
- **Cross-Platform**: Works on Linux, macOS, and Windows
- **Replay Functionality**: Handle multiple game sessions and replay requests
- **Error Handling**: Comprehensive error checking and user feedback

## 🔧 Prerequisites

- GCC compiler (or equivalent C compiler)
- Raspberry Pi Pico with compatible firmware
- Serial connection (USB or RS232 adapter)
- Basic understanding of C programming

## 📦 Installation

### Linux/macOS

```bash
# Clone the repository
git clone https://github.com/neymo-omar/pico-rs232-game.git
cd pico-rs232-game

# Compile the program
gcc Assignment_2_Extra_Code.c rs232.c -o pico_game

# Make executable (if needed)
chmod +x pico_game
```

### Windows

```cmd
# Clone the repository
git clone https://github.com/neymo-omar/pico-rs232-game.git
cd pico-rs232-game

# Compile with MinGW or Visual Studio
gcc Assignment_2_Extra_Code.c rs232.c -o pico_game.exe
```

## 🚀 Usage

1. **Connect your Raspberry Pi Pico** to your computer via USB
2. **Run the program**:
   ```bash
   ./pico_game
   ```
3. **Follow the on-screen instructions** to play the game
4. **Enjoy the interactive sequence game!**


