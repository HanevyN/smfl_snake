# 🐍 Snake Game (SFML + C++)

A grid-based implementation of the classic Snake game using [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/). This project serves as a foundation for experimenting with game development concepts such as:

- Grid-based movement
- Collision detection
- Object spawning and avoidance
- Game loops and input handling
- Potential extensions: Maze generation, pathfinding, and ray tracing

---

## 🚀 Features

- Smooth grid-based movement with arrow keys
- Collision detection with boundaries and self
- Mouse (food) spawning that avoids snake's body
- Score tracking displayed in window title
- Modular design with separation of concerns

---

## 🛠 Requirements

- C++17 or later
- [SFML 3.0](https://www.sfml-dev.org/download.php)
- CMake (for build configuration)

---

## 📁 Project Structure
. ├── include/ │ ├── snake.h │ ├── mouse.h │ ├── update_loop.h │ └── config.h ├── src/ │ ├── snake.cpp │ ├── mouse.cpp │ ├── update_loop.cpp │ └── main.cpp ├── CMakeLists.txt └── README.md

## ⚙️ Configuration

Settings such as cell size, window size, and move steps are managed via `config.h`:

```cpp
constexpr int CELL_SIZE = 25;
constexpr int WINDOW_SIZE = 800;
constexpr int MOVE_STEP = 1;
```
## 🧪 Building & Running

Make sure SFML is installed and available on your system.

```bash
mkdir build
cd build
cmake ..
make
./SnakeGame
```

## 🧠 Future Extensions

* Maze generation
* Pathfinding algorithms (A*, BFS, DFS)
* Smarter food/mouse placement
* Ray casting for vision
* Scoreboard or GUI overlay


## 📝 License
* This project is open-source and available under the MIT License.

