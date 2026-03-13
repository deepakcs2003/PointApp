# Sketch3d - 3D CAD Application

## Overview

Sketch3D is a CAD-style desktop application built using **C++ and Qt Framework**.
The goal of this project is to create an environment where users can draw and manipulate **3D geometric shapes**.

Supported shapes include:

* Cuboid
* Sphere
* Cone
* Torus

---

## Tech Stack

| Technology    | Usage                     |
| ------------- | ------------------------- |
| C++           | Core programming language |
| Qt 6          | UI framework              |
| Visual Studio | Development IDE           |
| qmake         | Build system              |
| Qt3D          | 3D rendering              |

---

## Project Structure

```
PointApp/
│
├── Header Files
│   ├── Canvas.h
│   ├── Cuboid.h
│   ├── Sphere.h
│   ├── ColorBar.h
│   ├── ToolBox.h
│   └── PointApp.h
│
├── Source Files
│   ├── Canvas.cpp
│   ├── Cuboid.cpp
│   ├── Sphere.cpp
│   ├── ColorBar.cpp
│   ├── ToolBox.cpp
│   ├── PointApp.cpp
│   └── main.cpp
│
└── Resources
    └── PointApp.qrc
```

---

## Coding Standards

### Class Naming

Use **PascalCase**

Example:

```
Canvas
Cuboid
Sphere
ToolBox
```

---

### Function Naming

Use **camelCase**

Example:

```
newFile();
openFile();
saveSTL();
exitApp();
```

---

### Variable Naming

Use **camelCase**

Example:

```
currentTool
selectedShape
currentFile
```

---

### Constants

Use **UPPER_CASE**

Example:

```
MAX_OBJECTS
DEFAULT_COLOR
```

---

## UI Guidelines

The application follows a CAD-style UI structure.

Main menu layout:

```
File
Edit
View
Modify
Help
```

---

## Build Instructions

1. Install **Qt 6**
2. Install **Visual Studio 2022**
3. Install **Qt VS Tools extension**
4. Open the project in Visual Studio
5. Run:

```
Qt → Run qmake
```

6. Build the project

---

## Future Features

Planned improvements:

* 3D camera controls
* Grid system
* Object transformation tools
* STL / OBJ export
* Boolean operations
* Undo / Redo system

---