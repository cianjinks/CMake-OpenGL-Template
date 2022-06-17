# CMake OpenGL Template

This repository is a template CMake project setup for cross platform graphics programming with OpenGL. It includes the following libraries for use:

- [GLAD](https://glad.dav1d.de/) for modern OpenGL bindings
- [ImGui](https://github.com/ocornut/imgui) for GUI
- [GLFW](https://www.glfw.org/) for cross platform window management
- [GLM](https://github.com/g-truc/glm) for math
- [stb_image](https://github.com/nothings/stb/blob/master/stb_image.h) for texture loading


Feel free to copy/fork this repository for your own use. I wrote a [tutorial](https://cianjinks.github.io/posts/cmake-project-graphics-programming/) on how it was setup from scratch if you are interested.

## Usage

### Windows

You will need [CMake](https://cmake.org/) and Visual Studio installed on your computer. CMake needs to be added to the PATH so that it can be run from the commandline. Running `win_setup.bat` will generate a "build" folder with a VS solution (`.sln`) file inside. From there you can code away with all the libraries mentioned above at your disposable. If you need to load any resources from files then you can place them in the "resources" folder and access them from code using relative paths like "./resources/shaders/test.glsl".

### Linux

Same as above, you will need [CMake](https://cmake.org/) and a suitable C++ and C compiler installed. First run `linux_setup.sh` to produce a `./build` folder. Then to compile the program executable in either debug or release mode you can use the commands:

    cmake --build ./build/release OR cmake --build ./build/debug

## Media

![Windows](docs/Windows.png)
![Linux](docs/Linux.png)