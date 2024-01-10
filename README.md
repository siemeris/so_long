# So_Long Project - 42

This is the So_Long project from the 42 school curriculum. So_Long is a simple 2D game where the player controls a character that must collect items and avoid enemies to win the game. The game is developed in a graphical environment using the MinilibX library.

## Table of Contents

1. [System Requirements](#system-requirements)
2. [Installation](#installation)
3. [Compilation](#compilation)
4. [Usage](#usage)
5. [Game Rules](#game-rules)
6. [Project Structure](#project-structure)
7. [Screenshots](#screenshots)
8. [Project Development Rules](#project-development-rules)


## System Requirements

- MinilibX library installed (provided in the 42 repository)

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/siemeris/so_long.git
    ```

2. Navigate to the project directory:

    ```bash
    cd so_long
    cd mac
    ```

## Compilation

Compile the project by running:

```bash
make
```

For bonus:
```bash
make bonus
```

## Usage

Run the game with:

```bash
./so_long maps/map_valid.ber
```

For bonus:
```bash
./so_long_bonus maps/map_valid.ber
```

## Game Rules
- The player starts at an initial position on the map.
- The goal is to collect all items and reach the exit to win.
- Avoid enemies, as they will deduct lives upon collision. (Bonus)
- The game ends when you collect all items and reach the exit or run out of lives.

## Project Structure
The project structure is organized as follows:

- `src/`: Source code of the project, mandatory part.
- `src_bonus/`: Source code of the project, extra part.
- `maps/`: Example maps for the game.
- `assets/`: Images used in the game.

## Screenshots

![game](https://github.com/siemeris/so_long/blob/main/screenshot.png)
![bonus](https://github.com/siemeris/so_long/blob/main/screenshot_bonus.png)

## Project Development Rules:

### Makefile Rules:
`make` - Compile so_long files.

`make bonus` - Compile so_long_bonus files.

`make all`  - Compile mandatory + bonus files.

`make clean`  - Delete all .o (object files) files.

`make fclean`  - Delete all .o (object files) and .a (executable) files.

`make re` - Use rules `fclean` + `all`.

### Mandatory:
- [x] Must use MiniLibX.
- [x] Makefile must compile source files and should not relink.
- [x] The program has to take as a parameter a map description file ending with the `.ber` extension.

### Game:
- [x] **Goal:** Collect every collectable and escape choosing the shortest route.
- [x] `W`, `A`, `S` and `D` keys must be used to move the main character `up`, `down`, `left` and `right`.
- [x] Can't move into walls.
- [x] Number of movements must be displayed in the shell.
- [x] Must be a 2D view (top-down or profile).
- [x] Doesn't need to be real-time.

### Graphic Management:
- [x] Display the image in a window and must remain smooth (changing windows, minimizing, ...).
- [x] Pressing `ESC` must close the window and quit the program in a clean way.
- [x] Clicking on the window cross must also close and quit the program in a clean way.
- [x] The use of the images of the MiniLibx is mandatory.

### Map Components
- [x] The map should include 3 components to be constructed: walls, collectables and free space.
- [x] Should be composed of only these 5 characters:

| Characters | Description |
| :--: | :--: |
| `0` | Empty space.              |
| `1` | Wall.                     |
| `C` | Collectible.              |
| `E` | Map exit.                 |
| `P` | Player starting position. |

### Map Validation:
- [x] The map must contain 1 exit, at least 1 collectable, and 1 starting position to be valid.
- [x] Map must be rectangular.
- [x] Map must be closed/surrounded by walls. If not, the program should return an error.
- [x] Check if there is a valid path in the map.
- [x] The program must be able to parse any kind of map, as long it respects the rules.
- [x] If an error/misconfiguration is encountered, it should return `Error\n` followed by an explicit message.

Map `.ber` example:
```
111111111111
1001000000C1
100000011101
1P0011E00001
111111111111
```

### Bonus
- [x] Develop original extra features (optional).
- [x] Make the player lose when they touch an enemy patrol.
- [x] Add sprite animation.
- [x] Display the movement count directly on the screen, instead of writing in the shell.

### Norminette Compliance
This project adheres to the coding standards enforced by the Norminette tool at 42 School. Norminette ensures consistency in coding practices, covering aspects such as indentation, formatting, and function naming. By following these standards, we aim to enhance code clarity and maintainability.