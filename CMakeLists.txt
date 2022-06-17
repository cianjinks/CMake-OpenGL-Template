cmake_minimum_required(VERSION 3.3)
project(CMakeGraphicsProject)

# OpenGL
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
include_directories(src ${OPENGL_INCLUDE_DIRS})

# Address Sanitizer
if (UNIX)
	set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
	set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
endif()

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)

# ImGui
set(imgui-directory dependencies/imgui)
set(imgui-source ${imgui-directory}/imconfig.h
	${imgui-directory}/imgui.h
	${imgui-directory}/imgui.cpp
	${imgui-directory}/imgui_draw.cpp
	${imgui-directory}/imgui_internal.h
	${imgui-directory}/imgui_widgets.cpp
	${imgui-directory}/imstb_rectpack.h
	${imgui-directory}/imstb_textedit.h
	${imgui-directory}/imstb_truetype.h
    ${imgui-directory}/imgui_tables.cpp
	${imgui-directory}/imgui_demo.cpp
	${imgui-directory}/backends/imgui_impl_glfw.cpp
	${imgui-directory}/backends/imgui_impl_opengl3.cpp
)

# Subprojects
add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/stb_image)
add_subdirectory(dependencies/glm)

# Set `source` variable to all .h and .cpp files in `src`
file(GLOB_RECURSE source CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(CMakeGraphicsProject ${source} ${imgui-source})
target_link_libraries(CMakeGraphicsProject ${OPENGL_LIBRARIES} glad glfw stb_image glm)
target_include_directories(CMakeGraphicsProject PRIVATE ${imgui-directory})

# Visual Studio Startup Project
if(WIN32)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT CMakeGraphicsProject)
endif()

# Symlink Resources
add_custom_command(TARGET CMakeGraphicsProject PRE_BUILD COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/resources $<TARGET_FILE_DIR:CMakeGraphicsProject>/resources)