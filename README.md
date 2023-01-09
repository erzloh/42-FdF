# 42-FdF
A 3D wireframe model viewer.	

<img width="804" alt="Screen Shot 2023-01-09 at 3 17 13 PM" src="https://user-images.githubusercontent.com/48589114/211329245-32217359-5188-4d07-946c-47b1017ac943.png">

## About the project
FdF stands for "Fil de Fer", which means "wireframe model" in French. A wireframe model is a visual representation of a three-dimensional physical object used in 3D computer graphics.

The purpose of the project is to make a program that renders a 3D wireframe model out of a text file as input. The input text file contains the height value of each point of the map.

The library used to render graphics is the MiniLibX, a library created by the 42 School. It is a very simple library that comes with functions to open a window, draw a pixel and handle user inputs. 
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

## Examples of an input file
`0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0`

## Screenshots
<img width="1483" alt="Screen Shot 2023-01-09 at 3 26 03 PM" src="https://user-images.githubusercontent.com/48589114/211330911-01efce30-04c7-4515-b5ff-9e2c070cb983.png">
<img width="987" alt="Screen Shot 2023-01-09 at 3 21 01 PM" src="https://user-images.githubusercontent.com/48589114/211329819-71c49a1f-c6f0-4950-9784-529abe8b8b88.png">
<img width="967" alt="Screen Shot 2023-01-09 at 3 21 53 PM" src="https://user-images.githubusercontent.com/48589114/211329947-e950c2d3-ca56-4dc4-beca-42ab81d96f5e.png">
<img width="1765" alt="Screen Shot 2023-01-09 at 3 24 45 PM" src="https://user-images.githubusercontent.com/48589114/211330631-5fcd3a3a-c52e-49f5-acf3-2d83617c2922.png">
