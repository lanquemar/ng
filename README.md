# ng

**ng** is my personnal C++ library. It allows me to tinker with a variety of algorithms and concepts (threads, allocators, clocks, etc) and APIs (OpenGL, GLM, GLFW, etc). This library is also compiled against all my projects so I can reuse code when needed.


## Features

* **graphics** module
    * Window, Event, Mouse, Keyboard; abstraction of [GLFW](https://www.glfw.org/), simplifies and hides windows creation and OpenGL contexts.
    * Mesh; a basic OpenGL object renderer.
    * GLShader; manages an OpenGL 3.X shader.
* **io** module
    * File, Buffer; filesystem access.
    * parsing of a few file formats: [Wavefront OBJ](https://en.wikipedia.org/wiki/Wavefront_.obj_file).
* **maths** module
    * AABB, Ray; implements basic collision techniques.
    * [PerlinNoise](https://en.wikipedia.org/wiki/Perlin_noise).
    * Random; based on the standard C library.
* **system** module
    * Clock.
    * Duration.
* **utils** module
    * Logger; print messages to standard outputs and log file at the same time.


## Compilation

Can be done using [cmake](https://cmake.org/):
```bash
cmake -E make_directory build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .. --config Release
```

By default a static library is generated.


## Linter

Google's linter [cpplint](https://github.com/cpplint/cpplint) can be run against this repository. All Google's rules are respected but: identation, forbidden functions and empty loop body rules.

To install and run cpplint:
```bash
pip install cpplint
cpplint --recursive --filter="-whitespace/braces,-whitespace/indent,-whitespace/comments,-runtime/indentation_namespace,-build/c++11,-whitespace/empty_loop_body" include src
```


## Notice

This code is provided "as is", without warranty of any kind. **Not** recommended to be used in a production environment. Can be used to tinker and play around.


## License

See [LICENSE](https://github.com/lanquemar/ng/blob/master/LICENSE) file.
