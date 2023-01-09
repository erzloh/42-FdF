# 42-FdF
A 3D wireframe model viewer.	

![Capture d’écran 2022-12-23 à 23 04 17](https://user-images.githubusercontent.com/48589114/209409414-74a29035-cfce-45ed-9d7b-d32ee2d0f1ec.png)

## About the project
FdF stands for "Fil de Fer", which means "wireframe model" in French. A wireframe model is a visual representation of a three-dimensional physical object used in 3D computer graphics.

The purpose of the project is to make a program that renders a 3D wireframe model out of a text file as input. The input text file contains the height value of each point of the map.

## Build
Run the command `make` inside the repository to build the executable named 'fdf'.

## Run
Run the command `./fdf maps/example_map.fdf`

You can choose a map among the .fdf files inside the 'maps' folder.

## Navigation
- Use `W`, `A`, `S`, and `D` to move the map.
- Use `K` and `L` to zoom in and out.
- Use the `Left` and `Right` arrow keys to increase the width of a 2D tile.
- Use the `Up` and `Down` arrow keys to decrease the height of a 2D tile.
- Use `O` and `P` to increase or decrease the altitude of the elevated points.

## Screenshots
