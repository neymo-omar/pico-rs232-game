

# Pico RS232 Game Interface

A cross-platform C program that communicates with a Raspberry Pi Pico over a serial connection using RS232. The game involves receiving a sequence from the Pico, prompting the user to replicate it, and handling replay requests — all over the COM port.

## 📦 Contents

- `Assignment_2_Extra_Code.c` – Main PC-side game logic
- `pc_side.c` – Alternate or extended version of the game logic
- `rs232.h` – RS232 serial communication header (by Teunis van Beelen)
- `rs232.c` – RS232 serial communication implementation (**placeholder**: replace with actual source)

## 🛠️ Build Instructions

### Linux/macOS

```bash
gcc Assignment_2_Extra_Code.c rs232.c -o pico_game
./pico_game
