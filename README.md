# How to use engine

The class Shader is responsible to load, compile and attach fragmente shader and vertex shader of the objects.
The class Render is responsible to draw the buffer os poligon passed by args. It's 

# Installation

This project uses make as a build tool.

## Requirements

* make
* g++

## Compilation

To compile the project, follow the steps below:

Clone the repository:

```bash
git clone https://github.com/your-username/project-name.git
cd project-name
```

Create a build directory at the root of the project:

```bash
mkdir build
```

Navigate to the build directory:

```bash
cd build
```

Run the cmake command in the build directory:
```bash
cmake ..
```
Run the make command to build the project:

```bash
make
```

The executable will be generated in the build directory:

``` bash
./game-opengl
```

## Cleaning

To clean up the generated files, simply remove the build directory:

```bash
rm -rf build
```
